#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

bool valid(int r, int c)
{
    return r >= 0 && r < 8 && c > 0 && c <= 8;
}

vector<int> dr = {-1, -1, 1, 1};
vector<int> dc = {1, -1, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        char x, y;
        int a, b;
        cin >> x >> a >> y >> b;
        int xx = x - 'A';
        int yy = y - 'A';
        queue<pii> q;
        q.push({xx, a});
        map<pii, int> cnt;
        map<pii, pii> par;

        int f = 0;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            int r, c;
            tie(r, c) = u;

            if (r == yy && c == b)
            {
                f = 1;
                cout << cnt[{r, c}] << " ";
                vector<pii> ans;
                ans.emplace_back(r, c);
                while (r != xx && c != a)
                {
                    int tR = par[{r, c}].first;
                    int tC = par[{r, c}].second;
                    r = tR;
                    c = tC;
                    ans.emplace_back(r, c);
                }
                reverse(begin(ans), end(ans));
                for (auto i : ans)
                {
                    cout << char(i.first + 'A') << " " << i.second << " ";
                }
                cout << endl;
                break;
            }

            if (cnt[u] >= 3)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int tempR = r;
                int tempC = c;
                while (valid(tempR, tempC))
                {
                    tempR += dr[i];
                    tempC += dc[i];
                    if (valid(tempR, tempC))
                    {
                        if ((cnt[{tempR, tempC}] == 0) || cnt[u] + 1 < cnt[{tempR, tempC}])
                        {
                            cnt[{tempR, tempC}] = cnt[u] + 1;
                            par[{tempR, tempC}] = u;
                            q.push({tempR, tempC});
                        }
                    }
                }
            }
        }
        if (!f)
            cout << "Impossible" << endl;
    }
    return 0;
}
