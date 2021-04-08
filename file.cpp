using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
class Metod
{
    private int k = 0;
    private int i;
    public static long F(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        else return n * F(n - 1);
    }
    public void L(int n, double[] b
    {
        try
        {
            Console.Write(b[k] + " "); ++k; L(k, b);
        }
        catch (IndexOutOfRangeException) { return; }
    }
    public void L(double[] b)
    {
        for (i = 0; i < b.Length; i++)
            Console.Write(" {0,1}", b[i]);
    }
    public static int Method(double k)
    {
        int res;
        if (k <= 5) res = 10;
        else if (k <= 10) res = 9;
        else if (k <= 15) res = 8;
        else res = 0;
        return res;
    }
}
class Program
{
    static void Main(string[] args)
    {
        Metod M = new Metod();
        int n, i, s = 0, l;
        ConsoleKeyInfo kl;
        Console.BackgroundColor = ConsoleColor.White;
        do
        {
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Black;
            Console.WriteLine(DateTime.Now.ToShortDateString()
            + "; " + DateTime.Now.ToShortTimeString());
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine("Сколько было выстрелов?");
            n = int.Parse(Console.ReadLine());
            double[] b = new double[n];
        First: try
            {
                Console.WriteLine("Напишите расстояние от центра
               до выстрела " + n + " раз");
        for (i = 0; i < n; i++)
                    b[i] = double.Parse(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Напишите еще раз правильно
        используя числа"); goto First; }
        M.L(b);
                Console.WriteLine();
                Console.WriteLine("RECURCIA");
                M.L(b.Length, b);
                for (i = 0; i < n; i++)
                { l = Metod.Method(b[i]); s = s + l; }
                Console.WriteLine(); Console.Beep(500, 1000);
                Console.WriteLine("Ваш результат:" + s);
                long p = Metod.F(n);
                Console.WriteLine("Ну и факториал {0}!={1}", n, p);
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("Напишите Y если хотите презапустить
                программу, в противном случае программа выключится");
                kl = Console.ReadKey(true);
            } while (kl.Key == ConsoleKey.Y
            Console.ReadLine();
        }
}
