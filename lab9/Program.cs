using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab9
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Console.Write("Введiть своє iм'я:"); 
            string name = Console.ReadLine(); // вводимо ім'я
            Console.WriteLine($"Привiт,{name}"); // виводимо ім'я на консоль
            Console.ReadKey(); 
        }
    }
}
