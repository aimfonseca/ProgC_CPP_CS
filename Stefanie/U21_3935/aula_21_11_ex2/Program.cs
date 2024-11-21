
DateTime agora = DateTime.Now;
Console.WriteLine($"Data e hora atual: {agora}");
Console.WriteLine("Stéfanie Abreu");


Console.WriteLine("enter your age: ");
string ageString = Console.ReadLine()!;
if (int.TryParse(ageString, out int age))
{
    Console.WriteLine("your age is: " + age);
}
else
{
    Console.WriteLine("invalid age. Enter valid number.");
    
}
Console.WriteLine("enter your name: ");
string input = Console.ReadLine()!;
string name = string.IsNullOrWhiteSpace(input) ? "Unknown" : input;
Console.WriteLine("hello, " + name + "!");

Console.WriteLine("enter 2 number separated by space: ");
string umExemplo = Console.ReadLine();
string[] num_ = umExemplo.Split(' ');
int num1, num2, soma;
if (int.TryParse(num_[0], out num1) && int.TryParse(num_[1], out num2))
{
    soma = num1 + num2;
    Console.WriteLine($"The sum is: {soma}");
    
}

else
{
    Console.WriteLine("invalid number. Enter valid number.");
}

using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Digite um número: ");
        string input = Console.ReadLine();

        // Armazena o número temporariamente
        string numeroTemporario = input;

        // Inverte o número
        char[] arrayNumeros = input.ToCharArray();
        Array.Reverse(arrayNumeros);
        string numeroInvertido = new string(arrayNumeros);

        // Compara os números
        if (numeroTemporario == numeroInvertido)
        {
            Console.WriteLine("Palindrome number");
        }
        else
        {
            Console.WriteLine("Not palindrome number");
        }

        // Pausa para o utilizador ver o resultado
        Console.WriteLine("Pressione qualquer tecla para sair...");
        Console.ReadKey();
    }
}
