using System;

namespace EstruturaDeControlo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter two numbers separated by space: ");
            string umExemplo = Console.ReadLine()!;
            string[] num = umExemplo.Split(" ");
            int num1, num2, soma;
            if (int.TryParse(num[0], out num1) && int.TryParse(num[1], out num2))
            {
                soma = num1 + num2;
                Console.WriteLine("Soma = " + soma);
            }
            else
            {
                Console.WriteLine("Invalid input");
            }
        }
    }
}