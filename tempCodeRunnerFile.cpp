
        x = 1;
        y = 0;
        return;
    }
    extendEuclid(b, a % b);
    ll x1 = y, y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------- USER'S SOLVE FUNC -------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
}

/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
#endif
    solve();
    return 0;
}