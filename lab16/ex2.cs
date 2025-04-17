using System;
using System.Text;
class Program
{

    // Делегат для події
    public delegate void KeyPressedEventHandler();

    // Подія
    public static event KeyPressedEventHandler NameKeyPressed;

    static void Main2()
    {
        Console.OutputEncoding = Encoding.UTF8; Console.InputEncoding = Encoding.UTF8;

        // Підписка на подію
        NameKeyPressed += ShowName;

        Console.WriteLine("Натисни будь-яку клавішу. Якщо це 'М', буде показано ім'я:");

        while (true)
        {
            ConsoleKeyInfo keyInfo = Console.ReadKey(true); // Читаємо клавішу без відображення

            // Якщо натиснута клавіша — 'М' або 'м'
            if (keyInfo.KeyChar == 'М' || keyInfo.KeyChar == 'м')
            {
                // Викликаємо подію
                NameKeyPressed?.Invoke();
            }
            else if (keyInfo.Key == ConsoleKey.Escape)
            {
                Console.WriteLine("Вихід з програми.");
                break;
            }
        }
    }

    // Метод-обробник події
    static void ShowName()
    {
        Console.WriteLine("ім'я: Микита");
    }
}
