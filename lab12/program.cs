using System;

public class Sphere
{
    // Приховане поле для збереження значення радіусу кулі
    private double radius;

    // Конструктор без параметрів, створює кулю з радіусом 0
    public Sphere()
    {
        radius = 0;
    }

    // Конструктор з параметрами, приймає радіус і ініціалізує поле radius
    public Sphere(double radius)
    {
        this.radius = radius; // Використовуємо this для звернення до поля класу
    }

    // Властивість для отримання та встановлення значення радіусу
    public double Radius
    {
        get { return radius; } // Повертає значення радіусу
        set { radius = value; } // Встановлює нове значення радіусу
    }

    // Властивість для обчислення об'єму кулі (4/3 * π * r^3)
    public double Volume
    {
        get { return (4.0 / 3.0) * Math.PI * Math.Pow(radius, 3); } // Обчислює та повертає об'єм
    }//користувач може отримати значення об'єму, але не може його змінити напряму.Бо нема Set

    // Перевантаження оператора "+", який об'єднує дві кулі за об'ємом
    public static Sphere operator +(Sphere s1, Sphere s2)
    {
        double totalVolume = s1.Volume + s2.Volume; // Обчислюємо сумарний об'єм
        double newRadius = Math.Pow((3 * totalVolume) / (4 * Math.PI), 1.0 / 3.0); // Обчислюємо радіус нової кулі
        return new Sphere(newRadius); // Повертаємо новий об'єкт кулі з новим радіусом
    }

    // Перевизначений метод ToString(), який повертає рядок з інформацією про кулю
    public override string ToString()
    {
        return $"Sphere with radius: {radius}, Volume: {Volume:F2}"; // Форматований рядок з радіусом і об'ємом
    }

    // Перевизначений метод Equals() для порівняння двох куль за радіусом
    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType()) // Перевірка чи obj є об'єктом класу Sphere
        {
            return false;
        }

        Sphere other = (Sphere)obj; // Перетворюємо obj до типу Sphere
        return radius == other.radius; // Повертаємо true, якщо радіуси рівні
    }

    // Перевизначений метод GetHashCode(), щоб відповідати перевизначеному Equals()
    public override int GetHashCode()
    {
        return radius.GetHashCode(); // Використовуємо хеш-код радіусу
    }
}

class Program
{
    static void Main(string[] args)
    {
         Random rand = new Random(DateTime.Now.Millisecond);
        // Створення двох об'єктыв Sphere з різними радіусами
        Sphere sphere1 = new Sphere(rand.Next(2, 10)); 
        Sphere sphere2 = new Sphere(rand.Next(2, 10)); 
        // Sphere sphere1 = new Sphere(3); 
        // Sphere sphere2 = new Sphere(3); 
        
        // інформація про кожну кулю за допомогою перевизначеного ToString()
        Console.WriteLine(sphere1);
        Console.WriteLine(sphere2);

        // Використовуємо перевантажений оператор "+" для об'єднання двох куль
        Sphere combinedSphere = sphere1 + sphere2;
        Console.WriteLine($"Combined sphere: {combinedSphere}"); // Виводимо нову об'єднану кулю

        // Перевіряємо рівність двох куль
        Sphere sphere3 = new Sphere(3);
        Console.WriteLine($"sphere1 equals sphere3: {sphere1.Equals(sphere3)}"); // Очікувано: True, бо радіуси однакові
    }
}
