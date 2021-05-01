#include <iostream>

#define WARMUP 5
#define SECONDS 10

bool IsPrime(int i)
{
    for (int j = 2; j < i; j++)
        if (i % j == 0)
            return false;

    return true;
}

int GetPrimesUnderN(int n)
{
    int primes = 0;

    for (int i = 2; i < n; i++)
        if (IsPrime(i))
            primes++;

    return primes;
}

int main()
{
    int passes = 0;
    auto tick = clock();

    while (clock() - tick < WARMUP * CLOCKS_PER_SEC)
    {
        auto t = GetPrimesUnderN(10000 - (passes % 10000));
        if (t > 1229) std::cout << "Incorrect number of primes";
    }

    tick = clock();

    while (clock() - tick < SECONDS * CLOCKS_PER_SEC)
    {
        auto t = GetPrimesUnderN(10000 - (passes % 10000));
        if (t > 1229) std::cout << "Incorrect number of primes";
        passes++;
    }

    std::cout << "Passed " << passes << " runs in " << (clock() - tick) / CLOCKS_PER_SEC << " seconds." << std::endl;
}