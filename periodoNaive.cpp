#include <string>
using namespace std;

bool periodoFrazionario(string A, int p)
{
    int n = A.length() - 1;
    for (int i = 0; i <= n - p; i++)
    {
        if (A[i] != A[i + p])
        {
            return false;
        }
    }
    return true;
}

int periodNaive(string A)
{
    bool r;
    int p;
    for (p = 1; p <= A.length() - 1; p++)
    {
        r = periodoFrazionario(A, p);
        if (r)
        {
            return p;
        }
    }
    return p;
}