using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Coursework
{
    public partial class Form1 : Form
    {
        private AirplaneManager airplaneManager = new AirplaneManager(); // Оголошення airplaneManager на рівні класу

        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Add_planeButton_Click(object sender, EventArgs e)
        {
            try
            {
                string planeType = Type_of_planeTextBox.Text;
                int passengers = int.Parse(Number_of_passengersTextBox.Text);
                double distance = double.Parse(Length_of_flightTextBox.Text);
                double fuelConsumption = double.Parse(Fuel_consumptionTextBox.Text);
                double ticketPrice = double.Parse(Price_of_ticketTextBox.Text);

                // Створення об'єкта Airplane
                Airplane airplane = new Airplane(planeType, passengers, distance, fuelConsumption, ticketPrice);

                // Додавання літака до менеджера
                airplaneManager.AddAirplane(airplane);

                MessageBox.Show("Літак додано!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: {ex.Message}");
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void Display_airplanesButton_Click(object sender, EventArgs e)
        {
            try
            {
                // Виклик методу для відображення інформації про літаки
                airplaneManager.DisplayAirplanes();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: {ex.Message}");
            }
        }
    }
}
