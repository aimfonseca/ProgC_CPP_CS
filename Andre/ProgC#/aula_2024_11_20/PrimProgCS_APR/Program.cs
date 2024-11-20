using System;

class Program{
    public static int Main(){
        DateTime dataAtual = DateTime.Now;
        Console.WriteLine($"Data e hora atual: {dataAtual}" );
        string nome = "André Proença";
        Console.WriteLine($"Autor: {nome}");
        int primVar = 1;
        Console.WriteLine($"Valor da variável primVar: {primVar}");

        return 0;
    }
}