using System;

class Program
{
    static void Main()
    {
        // Valores 
        Console.WriteLine("Valores");

        // Tamanho do tipo byte
        Console.WriteLine($"byte: Min = {byte.MinValue}, Max = {byte.MaxValue}");

        // Tamanho do tipo char
        Console.WriteLine($"char: Min = {(int)char.MinValue}, Max = {(int)char.MaxValue}");

        // Tamanho do tipo int
        Console.WriteLine($"int: Min = {int.MinValue}, Max = {int.MaxValue}");

        // Tamanho do tipo long
        Console.WriteLine($"long: Min = {long.MinValue}, Max = {long.MaxValue}");

        // Tamanho do tipo double
        Console.WriteLine($"double: Min = {double.MinValue}, Max = {double.MaxValue}");

        // Tamanho do tipo bool
        Console.WriteLine($"bool: Min = {false}, Max = {true}");

        // Tamanho do tipo string
        Console.WriteLine($"string: Tamanho máximo = {int.MaxValue} caracteres");
        
    }
}