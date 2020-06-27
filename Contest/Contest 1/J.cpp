#include <iostream>
#include<string.h>
 
using namespace std;
 
int n, m,matrix[30][30],ans = -1;
 
void dfs(int u, int tmp)
{
    ans = max(ans,tmp);
    for (int v = 0; v < n; v++)
    {
        if (matrix[u][v] == 1)
        {
            matrix[u][v] = 0;
            matrix[v][u] = 0;
            dfs(v, tmp + 1);
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }
}
 
void solve()
{
    memset(matrix, 0, sizeof(matrix[0][0]) * 30 * 30);
    ans = -1;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    for (int i = 0; i < n; i++)
    	dfs(i,0);
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 0;k<t;k++){
        solve();
    }
}