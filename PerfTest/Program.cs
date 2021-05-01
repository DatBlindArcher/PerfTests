using System;
using System.Diagnostics;

namespace PerfTest
{
    class Program
    {
        private const int WARMUP = 5;
        private const int SECONDS = 10;

        static void Main()
        {
            int passes = 0;
            long tick = Stopwatch.GetTimestamp();

            while (Stopwatch.GetTimestamp() - tick < WARMUP * Stopwatch.Frequency)
            {
                var t = GetPrimesUnderN(10000 - (passes % 10000));
                if (t > 1229) Console.WriteLine("Incorrect number of primes");
            }

            tick = Stopwatch.GetTimestamp();

            while (Stopwatch.GetTimestamp() - tick < SECONDS * Stopwatch.Frequency)
            {
                var t = GetPrimesUnderN(10000 - (passes % 10000));
                if (t > 1229) Console.WriteLine("Incorrect number of primes");
                passes++;
            }

            Console.WriteLine($"Passed {passes} runs in {(Stopwatch.GetTimestamp() - tick) / Stopwatch.Frequency} seconds.");
        }

        private static int GetPrimesUnderN(int n)
        {
            int primes = 0;

            for (int i = 2; i < n; i++)
                if (IsPrime(i))
                    primes++;

            return primes;
        }

        private static bool IsPrime(int i)
        {
            for (int j = 2; j < i; j++)
                if (i % j == 0) 
                    return false;

            return true;
        }
    }
}
