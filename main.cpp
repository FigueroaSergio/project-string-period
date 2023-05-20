#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

#include "utils.h"
#include "periodoNaive.h"
#include "periodoSmart.h"
#include "test.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    // int n = 200;
    // Pair res = spDist(1000, 500000, 99);
    // char str[n];
    // char str2[n];
    // str[n - 1] = '\0';
    // str2[n - 1] = '\0';
    // fillRandom(str, n - 1);
    // fillRandomWithPeriod(str2, n - 1, 4);
    // cout << res.x << ',' << res.y << endl;
    // cout << str << endl;
    // cout << str2 << endl;
    // cout << periodNaive(str);
    // cout << periodoSmart(str) << endl;

    // cout << periodNaive(str2);
    // cout << periodoSmart(str2) << endl;

    // Test single
    // int size = 2000;
    // char *str = createString(size);
    // fillRandom(str, size);
    // Result r = test(&periodoSmart, str);
    // Result r2 = test(&periodNaive, str);
    // cout << str << endl;
    // cout << "r1: " << r.time << endl;
    // cout << "r2: " << r2.time << endl;
    // free(str);

    Test tests[2] = {{label : "periodo naive", func : periodNaive},
                     {label : "periodo smart", func : periodoSmart}};
    Generator random[2] = {
        {label : "fill random", generator : fillRandom},
        {label : "fill with period", generator : fillWithPeriod}};

    Result *results = testMany(tests, 2, random, 2);

    std::ofstream myfile;
    myfile.open("example.csv");
    myfile << "label,result,time,size\n";
    for (int i = 0; i < 4; i++)
    {

        myfile << results[i].label;
        myfile << ",";
        myfile << results[i].result;
        myfile << ",";
        myfile << results[i].time;
        myfile << ",";
        myfile << results[i].size;
        myfile << "\n";
    }

    myfile.close();
    return 0;
}