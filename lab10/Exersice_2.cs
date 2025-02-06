
//10. Обчислити добуток елементів масиву, для яких справедлива нерівність 1 < Zi. 

using System;

using System.Text;

internal class Program2
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;

        Random rand = new Random();
        int size ; // Розмір масиву
        Console.WriteLine("Введіть розмір масиву:");
        size = Convert.ToInt32(Console.ReadLine());

        int[] Z = new int[size];

        //---------------------------------------- Заповнення масиву випадковими числами 
        for (int i = 0; i < size; i++)
        {
            Z[i] = rand.Next(-50, 51);// Заповнюємо масив випадковими числами 
            /*
             .Next(...   ,   ...) – викликає метод Next(min, max), що повертає випадкове ціле число в діапазоні [min, max-1].
             
             */
        }

        //---------------------------------------- Виведення початкового масиву
        Console.WriteLine("Початковий масив:");
        Array.ForEach(Z, x => Console.Write(x + " ")); //Виводить початковий масив на екран, виконуэться поки не закінчиться розмір, а не визначену кількість разів
        Console.WriteLine();

        //---------------------------------------- Фільтруємо елементи, які > 1
        int[] filteredZ = Array.FindAll(Z, x => x > 1);// синтаксис означає: (Z) це масив, (x => x > 1) це фільтр, який вибирає елементи, які > 1 
        /*
            x => x > 1 – лямбда-вираз (анонімна функція), що описує умову відбору:
            x – кожен елемент масиву Z.
            x > 1 – перевірка, чи значення x більше за 1. Якщо так, елемент додається до filteredZ.
        */

        //---------------------------------------- Обчислення добутку знайдених елементів
        long product = 1;// змінна для зберігання добутку елементів

        if (filteredZ.Length > 0)
        {
            foreach (int num in filteredZ)
            {
                product *= num;
            }
        }
        else product = 0;
        
            
        

        //Результати
        Console.WriteLine("Елементи масиву, які > 1:");
        Array.ForEach(filteredZ, x => Console.Write(x + " "));// виконуэться поки не закінчиться розмір, а не визначену кількість разів
        Console.WriteLine();


        Console.WriteLine(  $"Добуток елементів, які > 1: {product}"  );
    }
}
