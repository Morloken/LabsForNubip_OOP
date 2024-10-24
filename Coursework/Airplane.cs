using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Coursework
{
    internal class Airplane
    {
        // Приватні поля
        private string planeType;
        private int passengers;
        private double distance;
        private double fuelConsumption;
        private double ticketPrice;

        // Конструктор
        public Airplane(string planeType, int passengers, double distance, double fuelConsumption, double ticketPrice)
        {
            this.planeType = planeType;
            this.passengers = passengers;
            this.distance = distance;
            this.fuelConsumption = fuelConsumption;
            this.ticketPrice = ticketPrice;
        }

        // Властивості
        public string PlaneType => planeType;
        public int Passengers => passengers;
        public double Distance => distance;
        public double FuelConsumption => fuelConsumption;
        public double TicketPrice => ticketPrice;

        // Метод для розрахунку витрат пального на пасажира на одиницю відстані
        public double FuelPerPassengerPerDistance()
        {
            return fuelConsumption / (passengers * distance);
        }
    }
}
