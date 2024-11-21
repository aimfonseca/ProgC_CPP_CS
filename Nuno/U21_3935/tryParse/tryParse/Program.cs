using System;

namespace tryParse
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter your age: ");
            string ageString = Console.ReadLine();
            if (int.TryParse(ageString, out int age))
            {
                Console.WriteLine("your age is: " + age);
            }
            else
            {
                Console.WriteLine("invalid input");
            }
            
            Console.Write("Enter your name: ");
            string input = Console.ReadLine();
            string name = string.IsNullOrWhiteSpace(input) ? "Unknown" : input;
            Console.WriteLine("Your name is: " + name + "!");
        }
    }
}