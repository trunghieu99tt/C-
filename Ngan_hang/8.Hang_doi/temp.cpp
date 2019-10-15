#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Nhap so n: ";cin>>n;
    int m = log(n)/log(2),i,j,k;
    cout<<"M = "<<m<<endl;
    vector<int> ans;
    for(int i = 0;i<n;i++)
        ans.emplace_back(i);
    vector<vector<int>> dis;
    dis.emplace_back(ans);
    for(i = 0;i<m;i++)
    {
        cout<<"{ ";
        vector<vector<int>> temp;
        for(k = 0; k < dis.size();k++)
        {
            cout<<" (";
            vector<int> odd, even;
            for(int j = 0;j<dis[k].size();j++)
            {
                if(j!=dis[k].size() - 1)
                    cout<<dis[k][j]<<" , ";
                else cout<<dis[k][j];
                if(j%2)
                    odd.emplace_back(dis[k][j]);
                else even.emplace_back(dis[k][j]);
            }
            cout<<") ";
            temp.emplace_back(even);
            temp.emplace_back(odd);
        }
        cout<<"} ";
        cout<<endl;
        dis = temp;
    }
    return 0;
}