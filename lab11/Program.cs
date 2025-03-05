using System;
using System.Text;
//10. Вивести ім'я в стовпець
class Program
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;

        // Введення ПІБ
        Console.Write("Введіть прізвище: ");
        string lastName = Console.ReadLine();
        Console.Write("Введіть ім'я: ");
        string firstName = Console.ReadLine();
        Console.Write("Введіть по батькові: ");
        string middleName = Console.ReadLine();

        // Визначення довжини
        Console.WriteLine($"\nДовжина прізвища: {lastName.Length}");
        Console.WriteLine($"Довжина імені: {firstName.Length}");
        Console.WriteLine($"Довжина по батькові: {middleName.Length}");

        // Генерація випадкового зсуву для шифрування
        Random rand = new Random(DateTime.Now.Millisecond);
        int randomShiftSeed = rand.Next(1, 10); // випадковий зсув від 1 до 9, залежить від часу(тому завжди випадковий по різному)
         Console.WriteLine($"\nЗміщуємо випадковим зсувом на: {randomShiftSeed} символів");
        // Шифрування імені
        string encryptedText = CaesarCipher(firstName, randomShiftSeed);//виклик функції шифрування
        Console.WriteLine($"\nЗашифроване ім'я: {encryptedText}");

        // Дешифрування імені
        string decryptedText = CaesarCipher(encryptedText, -randomShiftSeed);
        Console.WriteLine($"Розшифроване ім'я: {decryptedText}");

        // Виведення імені у стовпець
        Console.WriteLine("\nІм'я у стовпець:");
        foreach (char c in firstName)
        {
            Console.WriteLine(c);
        }
    }

    // Шифр Цезаря (зсув символів)
    static string CaesarCipher(string text, int shift)//приймає параметри text — рядок, який потрібно зашифрувати або розшифрувати.shift — число, яке визначає зсув букв у алфавіті.
    {
        char[] buffer = text.ToCharArray();//Перетворення рядка у масив символів, Кожен символ обробляється окремо
        for (int i = 0; i < buffer.Length; i++)//перебирання всього масиву
        {
            char letter = buffer[i];//Взяття по літері по черзі

            if (char.IsLetter(letter))//Перевірка, чи є символ буквою. 
            //Якщо це буква, застосовується шифрування.
            //Якщо це не буква (цифра, пробіл, знак пунктуації), вона залишається без змін.
            {
                if (letter >= 'А' && letter <= 'Я' || letter >= 'а' && letter <= 'я')//чи буква належить кириличному алфавіту.
                    //offset = 'А' або offset = 'а' встановлює початкову точку для обчислення нового символу.
                {
                    // Кирилиця
                    char offset = char.IsUpper(letter) ? 'А' : 'а';
                    letter = (char)((letter - offset + shift + 32) % 32 + offset);//Змінюємо символ за формулою, гарантує, що після виходу за межі кириличного алфавіту буква повертається на його початок.
                }
                else if (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z')//Обробка латиниці (англійські літери)
                {
                    // Латиниця
                    char offset = char.IsUpper(letter) ? 'A' : 'a';
                    letter = (char)((letter - offset + shift + 26) % 26 + offset);//працює так само, як у кирилиці, але для латинського алфавіту (26 літер).
                }
            }

            buffer[i] = letter;//Заміна символа у вихідному масиві. Після зміни символу він записується назад у масив.
        }
        return new string(buffer);//Масив символів перетворюється назад у рядок і повертається як результат.
    }
}
