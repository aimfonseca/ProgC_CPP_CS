using System;

namespace _2024_11_21
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Valores máximos e mínimos de tipos de dados em C#:");
            Console.WriteLine();

            // Tipos inteiros
            Console.WriteLine("Tipos inteiros:");
            Console.WriteLine($"sbyte (com sinal): Mínimo = {sbyte.MinValue}, Máximo = {sbyte.MaxValue}");
            Console.WriteLine($"byte (sem sinal): Mínimo = {byte.MinValue}, Máximo = {byte.MaxValue}");
            Console.WriteLine($"short (com sinal): Mínimo = {short.MinValue}, Máximo = {short.MaxValue}");
            Console.WriteLine($"ushort (sem sinal): Mínimo = {ushort.MinValue}, Máximo = {ushort.MaxValue}");
            Console.WriteLine($"int (com sinal): Mínimo = {int.MinValue}, Máximo = {int.MaxValue}");
            Console.WriteLine($"uint (sem sinal): Mínimo = {uint.MinValue}, Máximo = {uint.MaxValue}");
            Console.WriteLine($"long (com sinal): Mínimo = {long.MinValue}, Máximo = {long.MaxValue}");
            Console.WriteLine($"ulong (sem sinal): Mínimo = {ulong.MinValue}, Máximo = {ulong.MaxValue}");
            Console.WriteLine();

            // Tipos de ponto flutuante
            Console.WriteLine("Tipos de ponto flutuante:");
            Console.WriteLine($"float: Mínimo = {float.MinValue}, Máximo = {float.MaxValue}");
            Console.WriteLine($"double: Mínimo = {double.MinValue}, Máximo = {double.MaxValue}");
            Console.WriteLine($"decimal: Mínimo = {decimal.MinValue}, Máximo = {decimal.MaxValue}");
            Console.WriteLine();

            // Tipo de caractere
            Console.WriteLine("Tipo de caractere:");
            Console.WriteLine($"char: Mínimo = {(int)char.MinValue}, Máximo = {(int)char.MaxValue} (representa valores Unicode)");
            Console.WriteLine();

            // Tipo booleano
            Console.WriteLine("Tipo booleano:");
            Console.WriteLine($"bool: Valores possíveis = {true} e {false}");
            Console.WriteLine();

            Console.WriteLine("Pressione qualquer tecla para sair...");
            Console.ReadKey();
        }
    }
}