using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab15_NET
{
    public partial class Form2: Form
    {
        public static Form2 form2Instance;
        public Form2()
        {
            InitializeComponent();
            form2Instance = this;
            
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)//Прізвище і ім'я навпаки
        {
            string input = textBox1.Text.Trim();

            // Вивід у зворотному порядку
            string[] words = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            Array.Reverse(words);
            string reversed = string.Join(" ", words);
            label7.Text = "Зворотній порядок: " + reversed;

            // Кількість символів
            label5.Text = "Кількість символів: " + input.Length;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            //string fileName = textBox2.Text.Trim();
            //string textToSave = txtInput.Text;

            //try
            //{
            //    File.WriteAllText(fileName, textToSave);
            //    MessageBox.Show("Текст успішно збережено у файл.", "Збережено", MessageBoxButtons.OK, MessageBoxIcon.Information);
            //}
            //catch (Exception ex)
            //{
            //    MessageBox.Show("Помилка збереження файла: " + ex.Message, "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            //}
        }
    }
}
