public class Perf
{
    private static final int WARMUP = 5;
    private static final int SECONDS = 10;

    public static void main(String[] args)
    {
        int passes = 0;
        long tick = System.currentTimeMillis();

        while (System.currentTimeMillis() - tick < WARMUP * 1000)
        {
            var t = GetPrimesUnderN(10000 - (passes % 10000));
            if (t > 1229) System.out.println("Incorrect number of primes");
        }

        tick = System.currentTimeMillis();

        while (System.currentTimeMillis() - tick < SECONDS * 1000)
        {
            var t = GetPrimesUnderN(10000 - (passes % 10000));
            if (t > 1229) System.out.println("Incorrect number of primes");
            passes++;
        }

        System.out.println("Passed " + passes + " runs in " + (System.currentTimeMillis() - tick) / 1000 + " seconds.");
    }

    private static int GetPrimesUnderN(int n)
    {
        int primes = 0;

        for (int i = 2; i < n; i++)
            if (IsPrime(i))
                primes++;

        return primes;
    }

    private static boolean IsPrime(int i)
    {
        for (int j = 2; j < i; j++)
            if (i % j == 0) 
                return false;

        return true;
    }
}