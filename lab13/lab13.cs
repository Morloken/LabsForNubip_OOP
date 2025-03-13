
using System;
using System.Collections.Generic;
using System.Text;
abstract class Car
{
    public string Brand { get; set; }
    public string Model { get; set; }
    public double Price { get; set; }

    public Car(string brand, string model, double price)
    {
        Brand = brand;
        Model = model;
        Price = price;
    }

    public abstract void DisplayInfo();

    public override bool Equals(object obj)
    {
        if (obj is Car otherCar)
        {
            return Brand == otherCar.Brand && Model == otherCar.Model && Price == otherCar.Price;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(Brand, Model, Price);
    }
}

class Sedan : Car
{
    public int SeatingCapacity { get; set; }

    public Sedan(string brand, string model, double price, int seatingCapacity)
        : base(brand, model, price)
    {
        SeatingCapacity = seatingCapacity;
    }

    public override void DisplayInfo()
    {
        Console.WriteLine($"Sedan: {Brand} {Model}, Price: {Price} UAH, Seats: {SeatingCapacity}");
    }
}

class SUV : Car
{
    public bool HasFourWheelDrive { get; set; }

    public SUV(string brand, string model, double price, bool hasFourWheelDrive)
        : base(brand, model, price)
    {
        HasFourWheelDrive = hasFourWheelDrive;
    }

    public override void DisplayInfo()
    {
        Console.WriteLine($"SUV: {Brand} {Model}, Price: {Price} UAH, 4WD: {HasFourWheelDrive}");
    }
}

class Truck : Car
{
    public double LoadCapacity { get; set; }

    public Truck(string brand, string model, double price, double loadCapacity)
        : base(brand, model, price)
    {
        LoadCapacity = loadCapacity;
    }

    public override void DisplayInfo()
    {
        Console.WriteLine($"Truck: {Brand} {Model}, Price: {Price} UAH, Load Capacity: {LoadCapacity} tons");
    }
}

class Program
{
    static void Main()
    {
         Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;
        List<Car> autoPark = new List<Car>
        {
            new Sedan("Toyota", "Camry", 800000, 5),
            new SUV("Jeep", "Grand Cherokee", 1200000, true),
            new Truck("Volvo", "FH16", 3000000, 20),
            new Sedan("Honda", "Accord", 850000, 5)
        };

        Console.WriteLine("Автопарк:");
        foreach (var car in autoPark)
        {
            car.DisplayInfo(); // Поліморфізм: виклик перевизначених методів
        }

        double totalCost = 0;
        foreach (var car in autoPark)
        {
            totalCost += car.Price;
        }
        Console.WriteLine($"\nЗагальна вартість автопарку: {totalCost} UAH");

        // Демонстрація Equals
        Console.WriteLine("\nПеревірка рівності автомобілів:");
        Console.WriteLine(autoPark[0].Equals(new Sedan("Toyota", "Camry", 800000, 5))); // True
        Console.WriteLine(autoPark[1].Equals(new SUV("Jeep", "Grand Cherokee", 1200000, false))); // False

        // Різниця між раннім та пізнім зв’язуванням
        Car myCar = new Sedan("Mazda", "6", 900000, 5);
        myCar.DisplayInfo(); // Пізнє зв’язування: викликається перевизначений метод
    }
}
