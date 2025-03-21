using System;
using System.Text;

// Інтерфейс для фігури
interface IShape
{
    double GetArea(); // Метод для обчислення площі
    void Print();     // Метод для виведення інформації
}

class FourPointStar : IShape, IComparable<FourPointStar>
{
    private double a;
    private double b;

    // Конструктор без параметрів
    public FourPointStar()
    {
        a = 0;
        b = 0;
    }

    // Конструктор з параметрами
    public FourPointStar(double a, double b)
    {
        this.a = a;
        this.b = b;
    }

    // Властивості a і b
    public double A
    {
        get { return a; }
        set { a = value; }
    }

    public double B
    {
        get { return b; }
        set { b = value; }
    }

    // За формулою S = 4ab
    public double GetArea()
    {
        return (4 *
        (  (  (a/2) - b  )  /2) * b) + Math.Pow(b, 2);
    }

    public int CompareTo(FourPointStar other)    // Порівняння за площею
    {
        return this.GetArea().CompareTo(other.GetArea());
    }

    public void Print()
    {
        Console.WriteLine($"Зірка: a = {a}, b = {b}, площа = {GetArea()}");
    }
}

class Program
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;

        Console.Write("Введіть кількість зірок (N): ");
        int N = int.Parse(Console.ReadLine());
        FourPointStar[] stars = new FourPointStar[N];

        // Введення екземплярів
        for (int i = 0; i < N; i++)
        {
            Console.WriteLine($"\nЗірка #{i + 1}:");
            Console.Write("Введіть a: ");
            double a = double.Parse(Console.ReadLine());
            Console.Write("Введіть b: ");
            double b = double.Parse(Console.ReadLine());
            stars[i] = new FourPointStar(a, b);
        }

        // Вивід до сортування
        Console.WriteLine("\nОб'єкти до сортування:");
        foreach (IShape star in stars)
        {
            star.Print();
        }

        // Сортування за площею
        Array.Sort(stars);

        // Вивід після сортування
        Console.WriteLine("\nОб'єкти після сортування за площею:");
        foreach (IShape star in stars)
        {
            star.Print();
        }
    }
}
