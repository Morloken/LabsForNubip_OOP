using System;
using System.Text;
class ex1
{
    // Делегат для математичної функції
    public delegate double Function(double x);

    // Метод трапецій
    public static double TrapezoidalIntegral(Function f, double a, double b, int n)
    {
        double h = (b - a) / n;
        double sum = (f(a) + f(b)) / 2.0;

        for (int i = 1; i < n; i++)
        {
            sum += f(a + i * h);
        }

        return h * sum;
    }
    /*
     Цей метод реалізує метод чисельного інтегрування трапеціями,
    який дозволяє обчислити наближене значення визначеного інтегралу функції на відрізку [a, b].
   
    Метод приймає три параметри: функцію f, яку потрібно проінтегрувати, 
    межі інтегрування a та b, і кількість розбиттів n — тобто, на скільки маленьких відрізків розбити ділянку.
    
    Спочатку обчислюється ширина одного підінтервалу h, як (b - a) / n.
    Потім створюється змінна sum, яка з самого початку містить половинні значення функції на кінцях ((f(a) + f(b)) / 2),
    бо ці значення враховуються лише по половині в методі трапецій. 
    
    Далі в циклі for проходиться по кожній внутрішній точці (без кінців) і до sum додається значення функції в цій точці.
    
    Це відповідає тому, що у формулі методу трапецій усі внутрішні значення беруться повністю.
    
    На завершення отримана сума множиться на ширину підінтервалу h, що дає остаточне наближене значення інтегралу.
     */

    // f(x) = 1 / (x^3 + x^2 + x + 1)
    public static double Func1(double x)
    {
        return 1.0 / (Math.Pow(x, 3) + Math.Pow(x, 2) + x + 1);
    }

    // f(x) = ln(x) / sqrt(x^2)
    public static double Func2(double x)
    {
        if (x == 0) return 0; // щоб уникнути ділення на 0
        return Math.Log(x) / Math.Abs(x);
    }

    // f(x) = cos(x)
    public static double Func3(double x)
    {
        return Math.Cos(x);
    }

    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8; Console.InputEncoding = Encoding.UTF8;

        double a , b;
        Console.Write("Введіть початок відрізка інтегрування (a): ");
        a = Convert.ToDouble(Console.ReadLine());
        Console.Write("Введіть кінець відрізка інтегрування (b): ");
        b = Convert.ToDouble(Console.ReadLine());
        // Кількість підінтервалів
        int n;
        Console.Write("Введіть кількість підінтервалів (n): ");
        n = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Інтеграл для f(x) = 1 / (x^3 + x^2 + x + 1):");
        Console.WriteLine(TrapezoidalIntegral(Func1, a, b, n));

        Console.WriteLine("\nІнтеграл для f(x) = ln(x) / sqrt(x^2):");
        Console.WriteLine(TrapezoidalIntegral(Func2, a, b, n));

        Console.WriteLine("\nІнтеграл для f(x) = cos(x):");
        Console.WriteLine(TrapezoidalIntegral(Func3, a, b, n));
    }
}
