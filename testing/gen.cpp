
// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

long long rand(long long a, long long b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[])
{
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(1, 10);
    int m = rand(1, 10);
    cout << n << " " << m << endl;
    while (n--)
    {
        int x = rand(0, 10);
        cout << x << " ";
    }
    cout << endl;
    while (m--)
    {
        int x = rand(0, 10);
        cout << x << " ";
    }

    puts("");
}