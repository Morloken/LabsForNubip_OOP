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
        public string PlaneType { get; set; }
        public int Passengers { get; set; }
        public double Distance { get; set; }
        public double FuelConsumption { get; set; }
        public double TicketPrice { get; set; }


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
        // Метод для обчислення розходу пального на пасажира на одиницю дальності
        public double FuelPerPassengerPerDistance()
        {
            return FuelConsumption / Passengers / Distance;
        
        }

        // Повертає список літаків
        public List<Airplane> GetAirplanes()
        {
            return airplanes;
        }

    }
}
