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
    Test tests[2] = {
        {label : "periodo naive", func : periodNaive},
        {label : "periodo smart", func : periodoSmart},
    };
    Generator random[3] = {
        {label : "fill random", generator : fillRandom},
        {label : "fill with period", generator : fillWithPeriod},
        {label : "fill worst case", generator : worstCase}};

    testMany(tests, 2, random, 3);

    return 0;
}