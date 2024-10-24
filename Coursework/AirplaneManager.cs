using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace Coursework
{
    internal class AirplaneManager
    {
        private List<Airplane> airplanes = new List<Airplane>();
        private double fuelPrice;

        // Додавання літака
        public void AddAirplane(Airplane airplane)
        {
            airplanes.Add(airplane);
        }

        // Встановлення ціни на паливо
        public void SetFuelPrice(double price)
        {
            fuelPrice = price;
        }

        // Збереження даних у файл
        public void SaveToFile(string filename)
        {
            using (StreamWriter sw = new StreamWriter(filename))
            {
                foreach (var airplane in airplanes.OrderBy(a => a.FuelPerPassengerPerDistance()))
                {
                    sw.WriteLine($"{airplane.PlaneType}: {airplane.TicketPrice} грн, Собівартість перевезення пасажира: {airplane.FuelPerPassengerPerDistance() * fuelPrice} грн.");
                }
            }
        }

        // Виведення даних у консоль
        public void DisplayAirplanes()
        {
            foreach (var airplane in airplanes.OrderBy(a => a.FuelPerPassengerPerDistance()))
            {
                Console.WriteLine($"{airplane.PlaneType}: {airplane.TicketPrice} грн, Собівартість перевезення пасажира: {airplane.FuelPerPassengerPerDistance() * fuelPrice} грн.");
            }
        }
    }
}
