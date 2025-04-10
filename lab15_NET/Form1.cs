using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace lab15_NET
{
    public partial class Form1: Form
    {

        public static Form1 form1Instance;
        public Form1()
        {
          
        InitializeComponent();
            form1Instance = this;

            // Центрування
            int screenWidth = Screen.PrimaryScreen.WorkingArea.Width;
            int screenHeight = Screen.PrimaryScreen.WorkingArea.Height;
            int formWidth = 400;
            int formHeight = 300;

            this.Width = formWidth;
            this.Height = formHeight;
            this.StartPosition = FormStartPosition.Manual;
            this.Left = (screenWidth - formWidth) / 2;
            this.Top = (screenHeight - formHeight) / 2;

            this.FormBorderStyle = FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Text = "Конус – Обчислення S та V";
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            //this.FormBorderStyle = FormBorderStyle.None;
            this.FormBorderStyle = FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.ControlBox = false;


        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
            
        private void button1_Click(object sender, EventArgs e)//обчислити кнопка
        {
         
            try
            {
                double h = double.Parse(textBoxH.Text);
                double l = double.Parse(textBoxL.Text);
                double r = double.Parse(textBoxR.Text);

                double S = Math.PI * r * l;
                double V = Math.PI * Math.Pow(r, 2) * h / 3;

                labelResult.Text = $"Площа бічної поверхні:\n S = {S:F2}\nОб’єм V = {V:F2}";
            }
            catch
            {
                MessageBox.Show("Будь ласка, введіть правильні числові значення.", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        

        }

        private void button2_Click  (object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            this.Hide();
            //Form2 form2 = new Form2();
            Form2.form2Instance.Show();
        }
    }
}
