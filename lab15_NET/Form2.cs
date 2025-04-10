
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab15_NET
{
    public partial class Form2 : Form
    {
        public static Form2 form2Instance;
        private string currentFilePath = null; // Поточний шлях до активного файлу

        public Form2()
        {
            InitializeComponent();
            form2Instance = this;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
        }

        private void label4_Click(object sender, EventArgs e)
        {
        }

        private void label2_Click(object sender, EventArgs e)
        {
        }

        private void label5_Click(object sender, EventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e) // Прізвище і ім’я навпаки
        {
            string input = textBox1.Text;

            // Зворотній порядок символів
            char[] chars = input.ToCharArray();
            Array.Reverse(chars);
            string reversed = new string(chars);

            label7.Text = "Зворотній порядок: " + reversed;

            // Кількість символів (включно з пробілами)
            label5.Text = "Кількість символів: " + input.Length;

            // Очистити поле
            textBox1.Clear();
        }

        private void button3_Click(object sender, EventArgs e) // Зберегти текст у файл
        {
            string newFileName = textBox2.Text.Trim();
            string textToSave = textBox4.Text;

            // Додати .txt, якщо користувач не ввів розширення
            if (!newFileName.EndsWith(".txt", StringComparison.OrdinalIgnoreCase))
            {
                newFileName += ".txt";
            }

            try
            {
                if (string.IsNullOrEmpty(currentFilePath))
                {
                    // Якщо це перше збереження
                    currentFilePath = newFileName;
                }
                else if (Path.GetFileName(currentFilePath) != Path.GetFileName(newFileName))
                {
                    // Якщо назва файлу змінена
                    string newPath = Path.Combine(Path.GetDirectoryName(currentFilePath), newFileName);
                    File.Move(currentFilePath, newPath);
                    currentFilePath = newPath;
                }

                // Дописування в кінець файлу
                File.AppendAllText(currentFilePath, textToSave + Environment.NewLine);

                MessageBox.Show("Текст успішно збережено у файл.", "Збережено", MessageBoxButtons.OK, MessageBoxIcon.Information);

                // Очищення полів
                textBox2.Clear();
                textBox4.Clear();

                //  ОНОВЛЕННЯ richTextBox1 ПІСЛЯ ЗАПИСУ
                string updatedContent = File.ReadAllText(currentFilePath);
                richTextBox1.Text = updatedContent;

            }
            catch (Exception ex)
            {
                MessageBox.Show("Помилка збереження файла: " + ex.Message, "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button4_Click(object sender, EventArgs e) // Зчитати з файлу
        {
            try
            {
                if (!string.IsNullOrEmpty(currentFilePath) && File.Exists(currentFilePath))
                {
                    string fileContent = File.ReadAllText(currentFilePath);
                    textBox3.Text = fileContent;
                }
                else
                {
                    MessageBox.Show("Файл не знайдено. Створіть або вкажіть файл перед читанням.", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Помилка читання файла: " + ex.Message, "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button1_Click(object sender, EventArgs e) // Назад до Form1
        {
            this.Hide();
            Form1.form1Instance.Show();
        }

        private void buttonClose_Click_Click(object sender, EventArgs e) // Закрити додаток
        {
            DialogResult result = MessageBox.Show("Ви впевнені, що хочете закрити програму?", "Закриття програми", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
            {
                Application.Exit();
            }
        }
    }
}

