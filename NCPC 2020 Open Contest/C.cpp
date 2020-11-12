#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    auto b = a;
    sort(begin(a), end(a));
    vector<pair<int, int>> ans;
    while (1)
    {
        int left = 0;
        int right = n - 1;
        while (left < n && a[left].first <= 0)
            left++;
        while (right >= 0 && a[right].first <= 0)
            right--;
        if (left >= n || right < 0 || left >= right)
            break;
        ans.push_back({a[left].second, a[right].second});
        a[left].first--;
        a[right].first--;
        int cnt = 0;
        for (auto i : a)
            cnt += (i.first > 0);
        if (cnt <= 1)
            break;
        sort(begin(a), end(a));
    }
    bool f = 1;
    for (auto i : a)
    {
        if (i.first > 0)
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        cout << "yes\n";
        for (auto i : ans)
            cout << i.first << " " << i.second << endl;
    }
    else
    {
        cout << "no";
    }
}