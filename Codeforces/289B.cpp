#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

bool CheckInt(float a)

{

    if (int(a) == a)
        return true;

    return false;
}

int main()

{

    int n, m, d;

    cin >> n >> m >> d;

    int a[n][m], min;

    vector<int> v;

    int i, j;

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < m; j++)

        {

            cin >> a[i][j];

            v.push_back(a[i][j]);
        }
    }

    sort(v.begin(), v.end());

    if (v.size() % 2 == 0)
        min = v[v.size() / 2 - 1];

    else
        min = v[v.size() / 2];

    bool flag1 = true, flag = true;

    int result = 0;

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < m; j++)

        {

            if (CheckInt(float(abs(a[i][j] - min)) / d) == 1)
                result += (abs(a[i][j] - min)) / d;

            else

            {

                flag = false;

                break;
            }
        }

        if (flag == false)

        {

            flag1 = false;

            break;
        }
    }

    if (flag1 == false)
        cout << -1;

    else
        cout << result;
}