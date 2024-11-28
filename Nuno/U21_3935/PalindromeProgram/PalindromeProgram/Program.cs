using System;

namespace PalindromeProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Verificador de Número Palíndromo");
        
            // Solicita o número ao utilizador
            Console.Write("Digite um número: ");
            string input = Console.ReadLine();

            // Verifica se a entrada é válida
            if (!int.TryParse(input, out int originalNumber))
            {
                Console.WriteLine("Por favor, insira um número válido.");
                return;
            }

            // Armazena o número original em uma variável temporária
            int tempNumber = originalNumber;

            // Reverte o número
            int reversedNumber = 0;
            while (tempNumber > 0)
            {
                int remainder = tempNumber % 10;
                reversedNumber = reversedNumber * 10 + remainder;
                tempNumber /= 10;
            }

            // Compara o número original com o número revertido
            if (originalNumber == reversedNumber)
            {
                Console.WriteLine($"O número {originalNumber} é um palíndromo!");
            }
            else
            {
                Console.WriteLine($"O número {originalNumber} não é um palíndromo.");
            }
        }
    }
}