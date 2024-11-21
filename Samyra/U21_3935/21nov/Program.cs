using System;

class Program
{
   static void Main()
   {
       /*
        // tamanho dos dados
        Console.WriteLine($"byte: Min = {byte.MinValue}, Max = {byte.MaxValue}  ");
        Console.WriteLine($"char: Min = {(int)char.MinValue}, Max = {(int)char.MaxValue}");
        Console.WriteLine($"int: Min = {int.MinValue}, Max = {int.MaxValue}");
        Console.WriteLine($"long: Min = {long.MinValue}, Max = {long.MaxValue}");
        Console.WriteLine($"double: Min = {double.MinValue}, Max = {double.MaxValue}");
        Console.WriteLine($"bool: Min= {false}, Max= {true}");
        Console.WriteLine($"string: Max= {int.MaxValue} caracteres");
        */

       
        /*
        Console.WriteLine("Enter you age: ");
        string ageString = Console.ReadLine();
        if (int.TryParse(ageString, out int age))
        {
            Console.WriteLine("Your age is " + age);
        }
        else
        {
            Console.WriteLine("Invalid input. Please enter a valid number.");
        }
        Console.WriteLine("Enter you name: ");
        string input = Console.ReadLine()!;
        string name = string.IsNullOrEmpty(input) ? "Unknown" : input;
        Console.WriteLine("hello, " + name + "!");
        */
       
       
        /*
        // numeros separados por espaço
        Console.Write("introduza dois numeros separados por espaço: ");
        string umExemplo = Console.ReadLine()!;
        string[] num_ = umExemplo.Split(' ');
        int num1, num2, soma;
        if (int.TryParse(num_[0], out num1) && int.TryParse(num_[1], out num2))
        {
            soma = num1 + num2;
            Console.WriteLine("Soma: " + soma);
        }
        else
        {
            Console.WriteLine("Invalid input.");
        }
        */
       
       
        /*
        //Desafio 1
        Console.Write("Digite um número: ");
        string input = Console.ReadLine()!;

        if (!int.TryParse(input, out int originalNumber))
        {
            Console.WriteLine("Por favor, insira um numero válido");
            return;
        }
       
        int tempNumber = originalNumber;
       
        int reversedNumber = 0;
        while (tempNumber > 0)
        {
            int remainder = tempNumber % 10;
            reversedNumber = reversedNumber * 10 + remainder;
            tempNumber /= 10;
        }

        if (originalNumber == reversedNumber)
        {
            Console.WriteLine($"O numero {originalNumber} é um palindromo");
        }
        else
        {
            Console.WriteLine($"O numero {originalNumber} não é um palindromo.");
        }
        */
       
       
        /*
        //Desafio 2
        Console.Write("Digite um número de dois dígitos ou mais: ");
        string input = Console.ReadLine();

        if (int.TryParse(input, out int numero))
        {
            int soma = 0;

            while (numero > 0)
            {
                int resto = numero % 10; // Obter o último dígito
                soma += resto;          // Somar o dígito
                numero /= 10;           // Remover o último dígito
            }

            Console.WriteLine($"A soma dos dígitos é: {soma}");
        }
        else
        {
            Console.WriteLine("Entrada inválida! Por favor, insira um número inteiro.");
        }
        */
       
       
       
   }
}