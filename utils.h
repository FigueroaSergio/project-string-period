#ifndef UTILS_H
#define UTILS_H

typedef struct Pair
{
    double x, y;
} Pair;

Pair spDist(int a, int b, int i);

int spDistLength(double a, double b, int i);

int randomNumber(int min, int max);

char *createString(int size);

void fillRandom(char str[], int size);

void fillWithPeriod(char str[], int size);

#endif