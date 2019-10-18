#include <bits/stdc++.h>

using namespace std;

void generateGrayarr(int n)
{
    if (n <= 0)
        return;
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    int i, j;
    for (i = 2; i < (1 << n); i <<= 1)
    {
        for (j = i - 1; j >= 0; j--)
            ans.push_back(ans[j]);
        for (j = 0; j < i; j++)
            ans[j] = "0" + ans[j];
        for (j = i; j < 2 * i; j++)
            ans[j] = "1" + ans[j];
    }
    cout << ans.size() << " ";
}

int main()
{
    for (int n = 1; n <= 10; n++)
        generateGrayarr(n);
    return 0;
}
