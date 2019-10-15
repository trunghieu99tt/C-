int group[1005][1005];
bool visited[1005][1005];
int maxZeroCells(vector<string> a)
{
    int ans = 0;
    int gr = 1;
    int i, j, n = a.size(), m = a[0].size();
    memset(group, 0, sizeof(group[0][0]) * 1000 * 1000);
    memset(visited, 0, sizeof(visited[0][0]) * 1000 * 1000);
    map<int, int> groupNum;
    int dr[] = {-1, 0, 0, 1},
        dc[] = {0, -1, 1, 0};
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == '0' && !visited[i][j])
            {
                queue<pair<int, int>> q;
                int cnt = 0;
                q.push({i, j});
                visited[i][j] = 1;
                while (!q.empty())
                {
                    auto u = q.front();
                    q.pop();
                    group[u.first][u.second] = gr;
                    cnt++;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = u.first + dr[k],
                            y = u.second + dc[k];
                        if (x > 0 && y > 0 && x < n && y < m && a[x][y] == '0' && !visited[x][y])
                        {
                            visited[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
                groupNum[gr] = cnt;
                ans = max(ans, cnt);
                gr++;
            }
        }
    }
    for (i = 1; i < n - 1; i++)
    {
        for (j = 1; j < m - 1; j++)
        {
            if (a[i][j] == '1')
            {
                int sum = 0;
                set<int> connect;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dr[k],
                        y = j + dc[k];
                    if (x > 0 && y > 0 && x < n && y < m && a[x][y] == '0')
                        connect.insert(group[x][y]);
                }
                for (auto i : connect)
                    sum += groupNum[i];
                ans = max(ans, sum + 1);
            }
        }
    }
    return ans;
}
