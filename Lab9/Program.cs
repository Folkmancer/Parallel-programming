using System;
using System.Threading;
using System.Threading.Tasks;

namespace Lab9
{
    class Program
    {
        private static DateTime Start, End;
        static void Main(string[] args)
        {
            ////Последовательное выполнение////
            Console.WriteLine("Последовательное выполнение");
            Start = DateTime.Now;
            Test('A');
            Test('B');
            Test('С');
            End = DateTime.Now;
            Console.WriteLine(End - Start);

            ////Потоки инициализированные лямбда выражениями////
            Console.WriteLine("Потоки, инициализированные лямбда выражениями");
            Start = DateTime.Now;
            Thread firstLambda = new Thread(() => Test('A'));
            Thread secondLambda = new Thread(() => Test('B'));
            Thread thirdLambda = new Thread(() => Test('C'));
            firstLambda.Start();
            secondLambda.Start();
            thirdLambda.Start();
            firstLambda.Join();
            secondLambda.Join();
            thirdLambda.Join();
            End = DateTime.Now;
            Console.WriteLine(End - Start);

            ////Потоки, инициализированные статическими методами////
            Console.WriteLine("Потоки, инициализированные статическими методами");
            Start = DateTime.Now;
            Thread firstStatic = new Thread(Test);
            Thread secondStatic = new Thread(Test);
            Thread thirdStatic = new Thread(Test);
            firstStatic.Start('A');
            secondStatic.Start('B');
            thirdStatic.Start('C');
            firstStatic.Join();
            secondStatic.Join();
            thirdStatic.Join();
            End = DateTime.Now;
            Console.WriteLine(End - Start);

            ////Пул потоков////
            Console.WriteLine("Пул потоков");
            Start = DateTime.Now;
            Task firstTask = Task.Run(() => Test('A'));
            Task secondTask = Task.Run(() => Test('B'));
            Task thirdTask = Task.Run(() => Test('C'));
            //firstTask.Wait();
            Task.WaitAll(firstTask, secondTask, thirdTask);
            End = DateTime.Now;
            Console.WriteLine(End - Start);

            Console.WriteLine("Конец всего");
        }

        public static void Test(object symbol)
        {
            double x = 12345.6789;
            for (int i = 0; i < 10000; i++)
                for (int j = 0; j < 10000; j++)
                {
                    x = Math.Sqrt(x);
                    x = x + 0.000000001;
                    x = Math.Pow(x, 2);
                }
            Console.WriteLine($"{symbol}: {x}");
        }
    }
}
