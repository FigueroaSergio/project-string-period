#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <fstream>
#include "utils.h"
#include "test.h"

using namespace std;
using namespace std::chrono;

#define MIN 1000
#define MAX 500000
#define ITERATIONS 100
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

void testMany(Test tests[], int nTest, Generator generators[], int nGen)
{

    std::ofstream myfile;
    myfile.open("example4.csv");
    myfile << "label,string,result,time,size\n";
    Pair p = spDist(MIN, MAX, ITERATIONS - 1);
    double a = p.x;
    double b = p.y;
    for (int t = 0; t < 8; t++)
    {
        cout << t;
        for (int z = 0; z < ITERATIONS; z++)
        {
            int ln = spDistLength(a, b, z); // (500000/)
            for (int i = 0; i < nGen; i++)
            {

                char *str = createString(ln);
                generators[i].generator(str, ln);
                for (int j = 0; j < nTest; j++)
                {
                    Result r = test(tests[j].func, str);

                    myfile << tests[j].label + ", " + generators[i].label;
                    myfile << ",";
                    myfile << r.result;
                    myfile << ",";
                    myfile << r.time;
                    myfile << ",";
                    myfile << r.size;
                    myfile << "\n";
                }

                free(str);
            }
        }
    }
    myfile.close();
}