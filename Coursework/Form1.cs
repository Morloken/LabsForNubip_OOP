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
                int passengers = (int)Passengers_numericUpDown.Value;
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

        private void Form1_Load(object sender, EventArgs e)
        {
            // Заповнення ComboBox типами літаків
            comboBox1.Items.AddRange(new string[] { "Boeing 737",
                "Airbus A320",
                "Embraer E190",
                "Boeing 747",
                "Boeing 777",
                "Airbus A380",
                "Boeing 787",
                "Airbus A330",
                "Bombardier CRJ200",
                "ATR 42"
            });




            listView1.Visible = false;
            listView1.View = View.Details;

            // Додавання колонок до ListView
            listView1.Columns.Add("Тип літака", 100);
            listView1.Columns.Add("Пасажири", 80);
            listView1.Columns.Add("Дальність", 80);
            listView1.Columns.Add("Розхід пального", 100);
            listView1.Columns.Add("Вартість квитка", 80);
            listView1.Columns.Add("Розхід на пасажира", 150);
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedType = comboBox1.SelectedItem.ToString();

            // Значення для кожного типу літака
            switch (selectedType)
            {
                case "Boeing 737":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "3000";
                    Fuel_consumptionTextBox.Text = "2600";
                    Price_of_ticketTextBox.Text = "500";
                    break;

                case "Airbus A320":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "3500";
                    Fuel_consumptionTextBox.Text = "2400";
                    Price_of_ticketTextBox.Text = "550";
                    break;

                case "Embraer E190":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "2800";
                    Fuel_consumptionTextBox.Text = "1800";
                    Price_of_ticketTextBox.Text = "400";
                    break;

                case "Boeing 747":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "8000";
                    Fuel_consumptionTextBox.Text = "10100";
                    Price_of_ticketTextBox.Text = "1200";
                    break;

                case "Boeing 777":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "9000";
                    Fuel_consumptionTextBox.Text = "7500";
                    Price_of_ticketTextBox.Text = "1100";
                    break;

                case "Airbus A380":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "15000";
                    Fuel_consumptionTextBox.Text = "12700";
                    Price_of_ticketTextBox.Text = "1500";
                    break;

                case "Boeing 787":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "14000";
                    Fuel_consumptionTextBox.Text = "5200";
                    Price_of_ticketTextBox.Text = "900";
                    break;

                case "Airbus A330":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "13450";
                    Fuel_consumptionTextBox.Text = "5700";
                    Price_of_ticketTextBox.Text = "950";
                    break;

                case "Bombardier CRJ200":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "2000";
                    Fuel_consumptionTextBox.Text = "1000";
                    Price_of_ticketTextBox.Text = "300";
                    break;

                case "ATR 42":
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Text = "1500";
                    Fuel_consumptionTextBox.Text = "900";
                    Price_of_ticketTextBox.Text = "250";
                    break;

                default:
                    // Значення за замовчуванням або очищення полів
                    Passengers_numericUpDown.Value = 0;
                    Length_of_flightTextBox.Clear();
                    Fuel_consumptionTextBox.Clear();
                    Price_of_ticketTextBox.Clear();
                    break;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear(); // Очистити список перед додаванням нових даних

            if (airplaneManager.GetAirplanes().Count == 0)
            {
                MessageBox.Show("Список літаків порожній!");
                return;
            }

            listView1.Visible = true;

            foreach (var airplane in airplaneManager.GetAirplanes())
            {
                // Обчислення кількості пального на пасажира на одиницю дальності
                double fuelPerPassengerPerDistance = airplane.FuelConsumption / airplane.Passengers / airplane.Distance;

                // Додавання даних до ListView
                var item = new ListViewItem(new string[]
                {
            airplane.Type,
            airplane.Passengers.ToString(),
            airplane.Distance.ToString(),
            airplane.FuelConsumption.ToString(),
            airplane.TicketPrice.ToString(),
            fuelPerPassengerPerDistance.ToString("0.00")
                });

                listView1.Items.Add(item);
            }
        }

        private void textBox1_TextChanged_2(object sender, EventArgs e)
        {

        }
    }
}
