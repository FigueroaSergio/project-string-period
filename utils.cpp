#include <iostream>
#include <new>
#include <math.h> /* pow */
#include <cstdlib>
#include "utils.h"

using namespace std;

Pair spDist(int min, int max, int iterazioni)
{
    return {x : (double)min,
            y : pow(((double)max / (double)min), (1. / iterazioni))};
}

int spDistLength(double a, double b, int i)
{
    return (int)(a * pow(b, i));
}

int randomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

char *createString(int size)
{
    char *str = (char *)malloc((size + 1) * sizeof(char));
    if (str == nullptr)
    {
        exit(137);
    }
    str[size] = '\0';
    return str;
}

void fillRandom(char str[], int size)
{
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        int min = (int)'a';
        str[i] = (char)randomNumber(min, min + 25);
    }
};

void fillWithPeriod(char str[], int size)
{
    int period = randomNumber(1, 25);
    int min = (int)'a';
    int start = randomNumber(min, min + 25 - period);
    char *p;
    p = (char *)malloc((period + 2) * sizeof(char));
    ;
    if (p == nullptr)
    {
        exit(137);
    }
    p[period] = '\0';

    for (int i = 0; i < period; i++)
    {
        char c = (char)randomNumber(start, start + period);
        p[i] = c;
    }
    for (int i = 0; i < size; i++)
    {
        str[i] = p[((i) % period)];
    }
    free(p);
};