using System;
using System.Text;

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

        // Шифрування імені
        string encryptedText = CaesarCipher(firstName, 3);
        Console.WriteLine($"\nЗашифроване ім'я: {encryptedText}");

        // Дешифрування імені
        string decryptedText = CaesarCipher(encryptedText, -3);
        Console.WriteLine($"Розшифроване ім'я: {decryptedText}");

        // Виведення імені у стовпець
        Console.WriteLine("\nІм'я у стовпець:");
        foreach (char c in firstName)
        {
            Console.WriteLine(c);
        }
    }

    // Шифр Цезаря (зсув символів)
    static string CaesarCipher(string text, int shift)
    {
        char[] buffer = text.ToCharArray();
        for (int i = 0; i < buffer.Length; i++)
        {
            char letter = buffer[i];

            if (char.IsLetter(letter))
            {
                char offset = char.IsUpper(letter) ? 'А' : 'а'; // Підтримка кирилиці
                letter = (char)((letter + shift - offset + 32) % 32 + offset);
            }

            buffer[i] = letter;
        }
        return new string(buffer);
    }
}
