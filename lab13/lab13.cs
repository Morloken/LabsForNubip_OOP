//10. Автомобілі. Визначити ієрархію легкових автомобілів. Створити автопарк організації. Порахувати вартість автопарку. 

using System;
using System.Collections.Generic;
using System.Text;

abstract class Car // батьківський елемент
{
    public string Brand { get; }
    public string Model { get; }
    public int Year { get; }
    public double Price { get; }

    protected Car(string brand, string model, int year, double price)
    {
        Brand = brand;
        Model = model;
        Year = year;
        Price = price;
    }

    public abstract void DisplayInfo(); // спочатку задається метод для майбутнього перезаписування

    public override bool Equals(object obj)//перевизн. за умовою, в батьківському класі
    {
        if (obj is Car otherCar)
        {
            return Brand == otherCar.Brand &&
                   Model == otherCar.Model &&
                   Year == otherCar.Year &&
                   Price == otherCar.Price;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(Brand, Model, Year, Price);
    }
}

class Sedan : Car // ієрархічний елемент від Car класу; Поліморфізм
{
    public bool HasSunroof { get; }

    public Sedan(string brand, string model, int year, double price, bool hasSunroof)
        : base(brand, model, year, price)
    {
        HasSunroof = hasSunroof;
    }

    // конструктор за замовчуванням (щоб можна було створювати екземпляри без параметрів).
    public Sedan() : base("Unknown", "Unknown", 2000, 0)
    {
        HasSunroof = false;
    }

    public override void DisplayInfo() // перезапис методу; Поліморфізм
    {
        Console.WriteLine($"Sedan: {Brand} {Model} ({Year}) - ${Price} | Sunroof: {HasSunroof}");
    }

    public override bool Equals(object obj)//перевизначення й у похідних класах для точності порівняння; Поліморфізм
    {
        if (obj is Sedan otherSedan && base.Equals(obj))
        {
            return HasSunroof == otherSedan.HasSunroof;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(base.GetHashCode(), HasSunroof);
    }
}

class SUV : Car // ієрархічний елемент від Car класу; Поліморфізм
{
    public bool HasFourWheelDrive { get; }

    public SUV(string brand, string model, int year, double price, bool hasFourWheelDrive)
        : base(brand, model, year, price)
    {
        HasFourWheelDrive = hasFourWheelDrive;
    }

    // конструктор за замовчуванням (щоб можна було створювати екземпляри без параметрів).
    public SUV() : base("Unknown", "Unknown", 2000, 0)
    {
        HasFourWheelDrive = false;
    }

    public override void DisplayInfo() // перезапис методу; Поліморфізм
    {
        Console.WriteLine($"SUV: {Brand} {Model} ({Year}) - ${Price} | 4WD: {HasFourWheelDrive}");
    }

    public override bool Equals(object obj)//перевизначення й у похідних класах для точності порівняння; Поліморфізм
    {
        if (obj is SUV otherSUV && base.Equals(obj))
        {
            return HasFourWheelDrive == otherSUV.HasFourWheelDrive;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(base.GetHashCode(), HasFourWheelDrive);
    }
}

class Program
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;

        Random rand = new Random(DateTime.Now.Millisecond);

        List<Car> autoPark = new List<Car>
        {
            new Sedan("Toyota", "Camry", rand.Next(2020, 2025), rand.Next(20000, 40000), true),
            new Sedan("Honda", "Accord", rand.Next(2020, 2025), rand.Next(20000, 40000), false),
            new SUV("Jeep", "Grand Cherokee", rand.Next(2020, 2025), rand.Next(20000, 40000), true),
            new SUV("Ford", "Explorer", rand.Next(2020, 2025), rand.Next(20000, 40000), false)
        };


        double totalCost = 0;
        foreach (Car car in autoPark)
        {
            totalCost += car.Price; // Раннє зв’язування (компілятор знає про Price)
        }

        Console.WriteLine("Автопарк компанії/організації:");
        foreach (Car car in autoPark)
        {
            car.DisplayInfo(); // Пізнє зв’язування (динамічний виклик DisplayInfo)
        }
        
        Console.WriteLine($"\nЗагальна вартість автопарку: ${totalCost}");

        // Демонстрація Equals
        Console.WriteLine("\nПорівняння автомобілів, 1 з 2, а потім - 3 і 4:");
        Console.WriteLine(autoPark[0].Equals(autoPark[1]) ? "Однакові" : "Різні");
        Console.WriteLine(autoPark[2].Equals(autoPark[3]) ? "Однакові" : "Різні");
    }
}
