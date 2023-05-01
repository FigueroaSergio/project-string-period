#include <string>
#include <cstdlib>

using namespace std;

int periodoSmart(string s)
{
    int l = s.length();
    int *b = (int *)malloc(sizeof(int) * l);
    b[0] = 0;

    for (int i = 1; i < l; i++)
    {
        int x = b[i - 1];

        while (s[x] != s[i] && x > 0)
            x = b[x - 1];

        if (s[x] == s[i])
            b[i] = x + 1;
        else
            b[i] = 0;
    }

    int result = l - b[l - 1];
    free(b);
    return result;
}