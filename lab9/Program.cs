using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;


namespace lab9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // ...............Локалізація на укр
            CultureInfo culture = new CultureInfo("uk-UA");
            CultureInfo.CurrentCulture = culture;
            CultureInfo.CurrentUICulture = culture;
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            //.................................. 

            bool exitProgram = false; // Змінна для виходу з програми

            while (!exitProgram) // Цикл, поки користувач не вирішить вийти
            {
                // Меню вибору завдання
                Console.Write("\n\nВведiть яке завдання хочете обрати: \n1 - знаходження значення a; \n2 - знаходження відстані, яку проходить світло за годину та добу;" +
                    " \nЯкщо введення неправильне(не 1,2) - вихід з консолі: \n");
                int n = Convert.ToInt32(Console.ReadLine());

                if (n == 1) Task1();
                
                    
                    
                
                else if (n == 2) Task2();
                
                    
                   
                
                else
                {
                    // Вихід, якщо введено щось інше, крім 1 або 2
                    Console.WriteLine("Неправильний вибір. Програма завершується...");
                    break;
                }

                // Після виконання завдання запитуємо, чи продовжити
                Console.WriteLine("\nБажаєте виконати інше завдання чи вийти з програми?");
                Console.WriteLine("1 - Виконати інше завдання");
                Console.WriteLine("2 - Вийти з програми");
                int choice = Convert.ToInt32(Console.ReadLine());

                if (choice == 2)
                {
                    exitProgram = true; // Вихід з програми
                }
            }

            Console.WriteLine("\nПрограма завершена. Натисніть будь-яку клавішу для виходу...");
            Console.ReadKey();
        }

        static void Task1()//========================================           TASK 1
        {
            Console.WriteLine("\n------------Завдання 1-------------");

            double x, y, z, a;
            string rangeX = "", rangeA = "";

            do
            {
                // Введення значень
                Console.Write("\nВведiть значення x: ");
                x = Convert.ToDouble(Console.ReadLine());

                if (x == 0) break; //  x = 0 -> вихід з циклу

                Console.Write("Введiть значення y: ");
                y = Convert.ToDouble(Console.ReadLine());

                Console.Write("Введiть значення z: ");
                z = Convert.ToDouble(Console.ReadLine());

                // Обчислення виразу
                a = Math.Sin(z - y) * Math.Cos((y + z) * Math.Abs(x));

                // Визначення діапазону для x
                if (x < -10)
                    rangeX = "менш за -10";
                else if (x < -1)
                    rangeX = "менш за -1";
                else if (x > 10)
                    rangeX = "більш за 10";
                else if (x > 1)
                    rangeX = "більш за 1";
                else
                    rangeX = "від -1 до 1";

                // Визначення діапазону для a
                if (a < 0)
                    rangeA = "негативне";
                else
                    rangeA = "позитивне";

                
                Console.WriteLine($"Результат обчислення: a = {a}");//$ - для виведеня значення змінної при звичайному рядку
                                                                    //(як в Js, але на початку рядку)
                Console.WriteLine($"X знаходиться в діапазоні: {rangeX}");
                Console.WriteLine($"Результат обчислення a є: {rangeA}");

            } while (x != 0);

            Console.WriteLine("\nПрограма 1 завершена.");
        }

        static void Task2()//========================================           TASK 2 
        {
            Console.WriteLine("\n------------Завдання 2-------------");

            // Швидкість світла в км/с
            const double lightSpeed = 299792; // км/с

            // Час в секундах
            const int secondsInHour = 60 * 60;   // Кількість секунд у годині
            const int secondsInDay = 24 * 60 * 60;   // Кількість секунд у добі

            // Обчислення відстані, яку проходить світло за годину та за добу
            double distancePerHour = lightSpeed * secondsInHour; // Відстань за годину
            double distancePerDay = lightSpeed * secondsInDay;   // Відстань за добу

            // Виведення результатів
            Console.WriteLine($"Швидкість світла: {lightSpeed} км/с");
            Console.WriteLine($"Відстань, яку проходить світло за годину: {distancePerHour} км");
            Console.WriteLine($"Відстань, яку проходить світло за добу: {distancePerDay} км");

            Console.WriteLine("\nПрограма 2 завершена.");
        }
    }
}


/* ----------------------- КОНТРОЛЬНІ ПИТАННЯ
 * 1. Яким чином можна оголосити змінну строковим типом?
Змінну строкового типу в C# можна оголосити так:

string variable;




2. Що описується в методах?
Методи — це блоки коду, які виконують певну задачу. Вони описують:

Вхідні параметри (аргументи, які передаються методу).
Логіку (послідовність операцій, яку виконує метод).
Результат (значення, яке метод може повернути після виконання, 
або ж метод може не повертати нічого).





3. Що буде виведено на екран після виконання програми?

Виведення на екран:

Премію отримає: Ivan Ivanov
Метод ViewPerson виводить на екран рядок із переданими аргументами "Ivan" та "Ivanov".






4. Яке перетворення типів здійснюється при виконанні наступного кода?

Операція a + 70 здійснює арифметичне додавання, але оскільки результат цього додавання є типу int,
здійснюється явне перетворення з int до byte через операцію кастингу (byte).







5. Вкажіть, як правильно визначити неявно типизовану змінну?
Неявно типизовану змінну в C# можна оголосити за допомогою ключового слова var,
яке дозволяє компілятору самостійно визначити тип змінної на основі присвоєного значення.

var myVariable = 100; // Тип буде визначено як int






6. Чим відрізняються параметри методів з ключовим словом ref і out?

ref: параметр передається в метод за посиланням, і він повинен бути ініціалізований до виклику методу. 
Метод може змінити значення цього параметра, і зміни будуть збережені після завершення методу.

out: параметр також передається за посиланням, але він не повинен бути ініціалізований до виклику методу.
Метод обов'язково повинен присвоїти значення цьому параметру.

Основна різниця полягає в тому, що з ref параметр повинен мати початкове значення, 
тоді як з out він буде обов'язково ініціалізований всередині методу.
 * 
 * 
 * 
 */