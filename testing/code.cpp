#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        vector<double> la(n);
        vector<double> lb(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 1)
            {
                la[i] = a[i] * 1.0 / log(a[i]);
            }
            else
            {
                if (a[i] == 1)
                    la[i] = 0;
                else
                    la[i] = -1;
            }
        }
        int cnt1 = 0;
        int cnt0 = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] > 1)
            {
                lb[i] = b[i] * 1.0 / log(b[i]);
            }
            else
            {
                lb[i] = -1;
                if (b[i] == 1)
                    cnt1++;
                else
                    cnt0++;
            }
        }
        sort(begin(lb), end(lb));
        auto out = [](vector<double> a) {
            for (auto i : a)
            {
                cout << i << " ";
            }
            cout << endl;
        };

        // out(la);
        // out(lb);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (la[i] > 0)
            {
                int idx = upper_bound(begin(lb), end(lb), la[i]) - begin(lb);
                ans += max(0, m - idx);
                ans += cnt1 + cnt0;
                // cout << a[i] << " " << m - idx << " " << cnt << endl;
            }
            else
            {
                if (la[i] == 0)
                    ans += cnt0;
            }
        }
        cout << ans << endl;
    }
}