#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <string>

#include "utils.h"
#include "test.h"

using namespace std;
using namespace std::chrono;

#define MIN 1000
#define MAX 5000
#define I 100
double getResolution()
{
    steady_clock::time_point start = steady_clock::now();
    steady_clock::time_point end;
    do
    {
        end = steady_clock::now();
    } while (start == end);
    typedef duration<double, seconds::period> secs;
    return duration_cast<secs>(end - start).count();
}

double getMinTime()
{
    double R = getResolution();
    double E = 0.001;
    double T_min = R * ((1. / E) + 1);
    return T_min;
}

void printResult(Result *r)
{
    cout << "label: " << r->label << " time: " << r->time << " size: " << r->size << endl;
}

Result takeTime(int (*func)(string str), string str, double T_min)
{
    Result r;
    int it = 1;
    double s;

    steady_clock::time_point start = steady_clock::now();
    do
    {
        it++;

        r.result = func(str);
        steady_clock::time_point end = steady_clock::now();

        typedef duration<double, seconds::period> secs;

        s = duration_cast<secs>(end - start).count();

    } while (s < T_min);
    r.time = s / it;
    r.size = str.length();
    return r;
}

Result test(int (*func)(string str), string str)
{
    double T_min = getMinTime();
    return takeTime(func, str, T_min);
}

Result *testMany(Test tests[], int nTest, Generator generators[], int nGen)
{

    int size = (nGen * nTest);
    // Result *results = (Result *)(malloc(size * sizeof(Result)));
    Result *results = new Result[size];
    int p[12];
    if (results == nullptr)
    {
        exit(137);
    }

    int z = 0;
    // Pair *p = spDist(MIN, MAX, I);
    // // double a = (int)p->x;
    // // double b = (int)p->y;

    // for (int l = 0; l < 100; l++)
    // {
    //     int ln = spDistLength(MIN, MAX, l);
    for (int i = 0; i < nGen; i++)
    {
        int ln = 1000 * i;
        char *str = createString(ln);
        generators[i].generator(str, ln);
        for (int j = 0; j < nTest; j++)
        {
            Result r = test(tests[j].func, str);

            r.label = tests[j].label;
            results[z].result = r.result;
            results[z].label = r.label + ", " + generators[i].label;
            results[z].time = r.time;
            results[z].size = r.size;
            z++;
        }

        free(str);
    }
    // }
    for (int i = 0; i < size; i++)
    {
        printResult(&results[i]);
    }

    // free(results);

    return results;
}