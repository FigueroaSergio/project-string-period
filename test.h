#include <string>
using namespace std;

#ifndef TESTING_H
#define TESTING_H

// your code goes here
typedef struct Generator
{
    string label;
    void (*generator)(char s[], int size);
} Generator;

typedef struct Test
{
    string label;
    int (*func)(string str);

} Test;

typedef struct Result
{
    string label;
    int result;
    double time;
    int size;

} Result;

double getResolution();

double getMinTime();

void printResult(Result *t);

Result takeTime(int (*func)(string str), string str);

Result test(int (*func)(string str), string str);

Result *testMany(Test tests[], int nTest, Generator generators[], int nGen);

#endif