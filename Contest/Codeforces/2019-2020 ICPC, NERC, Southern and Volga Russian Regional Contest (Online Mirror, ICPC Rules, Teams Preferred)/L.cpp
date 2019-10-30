#include <bits/stdc++.h>
using namespace std;

int l, r, mid, ans, A, B, C, T;

bool check(int lim)
{
    int a = A, b = B, c = C;
    if (a <= lim)
    {
        if (2 * lim >= c)
            return 1;
        else
            return 0;
    }
    a -= lim;
    if (a <= lim)
    {
        if (lim >= c)
            return 1;
        else
            return 0;
    }
    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &A, &B, &C);
        l = (A + B + C + 2) / 3, r = 3000, ans = 0;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}