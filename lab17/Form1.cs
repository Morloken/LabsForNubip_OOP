using System;
using System.Drawing;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace lab17
{
    public partial class Form1 : Form
    {
        private Pentagon pentagon;

        public Form1()
        {
            InitializeComponent();
        }

        [Serializable]
        public class Pentagon
        {
            public double Radius { get; set; }

            public Pentagon()
            {
                Radius = 0;
            }

            public Pentagon(double radius)
            {
                if (radius < 1.0)
                    throw new ArgumentException("Радіус має бути не менше 1.0");
                Radius = radius;
            }

            public void Draw(Graphics g, Pen pen, Point center)
            {
                if (Radius < 1.0) return;

                PointF[] points = new PointF[5];
                for (int i = 0; i < 5; i++)
                {
                    double angle = 2 * Math.PI * i / 5 - Math.PI / 2;
                    points[i] = new PointF(
                        center.X + (float)(Radius * Math.Cos(angle)),
                        center.Y + (float)(Radius * Math.Sin(angle))
                    );
                }
                g.DrawPolygon(pen, points);
            }
        }

        private void buttonDraw_Click(object sender, EventArgs e)
        {
            double radius = (double)numericUpDown1.Value;
            if (radius < 1.0)
            {
                MessageBox.Show("Радіус має бути не менше 1.0");
                return;
            }

            pentagon = new Pentagon(radius);
            panel1.Invalidate();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            if (pentagon != null)
            {
                Point center = new Point(panel1.Width / 2, panel1.Height / 2);
                pentagon.Draw(e.Graphics, Pens.Blue, center);
            }
        }

        private void buttonSaveBinary_Click(object sender, EventArgs e)
        {
            if (pentagon == null) return;

#pragma warning disable SYSLIB0011
            using (FileStream fs = new FileStream("pentagon.dat", FileMode.Create))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                formatter.Serialize(fs, pentagon);
            }
#pragma warning restore SYSLIB0011

            MessageBox.Show("Збережено у Binary (pentagon.dat)");
        }

        private void buttonSaveXml_Click(object sender, EventArgs e)
        {
            if (pentagon == null) return;

            using (FileStream fs = new FileStream("pentagon.xml", FileMode.Create))
            {
                XmlSerializer serializer = new XmlSerializer(typeof(Pentagon));
                serializer.Serialize(fs, pentagon);
            }

            MessageBox.Show("Збережено у XML (pentagon.xml)");
        }

        private void buttonLoadBinary_Click(object sender, EventArgs e)
        {
            if (!File.Exists("pentagon.dat"))
            {
                MessageBox.Show("Файл pentagon.dat не знайдено.");
                return;
            }

#pragma warning disable SYSLIB0011
            using (FileStream fs = new FileStream("pentagon.dat", FileMode.Open))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                pentagon = (Pentagon)formatter.Deserialize(fs);
            }
#pragma warning restore SYSLIB0011

            numericUpDown1.Value = (decimal)pentagon.Radius;
            panel1.Invalidate();

            MessageBox.Show("Завантажено з Binary");
        }

        private void buttonLoadXml_Click(object sender, EventArgs e)
        {
            if (!File.Exists("pentagon.xml"))
            {
                MessageBox.Show("Файл pentagon.xml не знайдено.");
                return;
            }

            using (FileStream fs = new FileStream("pentagon.xml", FileMode.Open))
            {
                XmlSerializer serializer = new XmlSerializer(typeof(Pentagon));
                pentagon = (Pentagon)serializer.Deserialize(fs);
            }

            numericUpDown1.Value = (decimal)pentagon.Radius;
            panel1.Invalidate();

            MessageBox.Show("Завантажено з XML");
        }
    }
}
