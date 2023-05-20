#include <iostream>
#include <string>
#include <iostream>

#include "utils.h"
#include "periodoNaive.h"
#include "periodoSmart.h"
#include "test.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    Test tests[2] = {{label : "periodo naive", func : periodNaive},
                     {label : "periodo smart", func : periodoSmart}};
    Generator random[2] = {
        {label : "fill random", generator : fillRandom},
        {label : "fill with period", generator : fillWithPeriod}};

    testMany(tests, 2, random, 2);

    return 0;
}