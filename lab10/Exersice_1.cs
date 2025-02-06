//10. Максимальний елемент поміняти місцями з мінімальним елементом. 

using System;
using System.Text;
internal class Program
{
    
    internal static void Main2()
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;


        Random rand = new Random();
        int size; // Розмір масиву
        Console.WriteLine("Введіть розмір масиву:");
        size = Convert.ToInt32(Console.ReadLine());

        int[] array = new int[size];
        Console.WriteLine();
        //---------------------------------------- Заповнення масиву випадковими числами(не додав введення меж випадковості, можливо треба)
        Console.WriteLine("Початковий масив:");
        for (int i = 0; i < size; i++)
        {
            array[i] = rand.Next(-50, 51);
            Console.Write(array[i] + " ");
        }
        Console.WriteLine();

        //---------------------------------------- Пошук індексів мінімального та максимального елементів
        int minIndex = 0, maxIndex = 0;
        for (int i = 1; i < size; i++)
        {
            if (array[i] < array[minIndex]) minIndex = i;
            if (array[i] > array[maxIndex]) maxIndex = i;
        }

        Console.WriteLine("Мінімальний елемент: " + array[minIndex]);
        Console.WriteLine("Максимальний елемент: " + array[maxIndex]);




        //---------------------------------------- Обмін місцями максимального і мінімального елементів
        int temp = array[minIndex];
        array[minIndex] = array[maxIndex];
        array[maxIndex] = temp;

        //показ зміненого варіанту масиву
        Console.WriteLine("Масив після заміни мінімального і максимального елементів:");
        foreach (int num in array)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }
}
