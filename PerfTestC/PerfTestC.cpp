#include <stdio.h>
#include <windows.h>
#include <sysinfoapi.h>

const int WARMUP = 5;
const int SECONDS = 10;

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
    auto tick = GetTickCount64();

    while ((GetTickCount64() - tick) < WARMUP * 1000)
    {
        auto t = GetPrimesUnderN(10000 - (passes % 10000));
        if (t > 1229) printf("Incorrect number of primes");
    }

    tick = GetTickCount64();

    while ((GetTickCount64() - tick) < SECONDS * 1000)
    {
        auto t = GetPrimesUnderN(10000 - (passes % 10000));
        if (t > 1229) printf("Incorrect number of primes");
        passes++;
    }

    printf("Passed %i runs in %u seconds", passes, (int)(GetTickCount64() - tick) / 1000);
}