#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i = 0;i<n;i++)

int a[20][20], n, ans = 0;

vector<int> indexRow;
map<int,int> visitedRow;

bool checker(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) != abs(c1 - c2);
}
void solve(int c)
{
	for(int r = 0;r<n;r++)
	{
		if(visitedRow[r] == 0)
		{
			int flag = 1;
			for(int j = 0;j<indexRow.size();j++)
			{
				if(!checker(r,c,indexRow[j], j))
				{
					flag=  0;
					break;
				}
			}
			if(flag)
			{
				visitedRow[r] = 1;
				indexRow.push_back(r);
				if(c == n-1)
				{
					ans++;
				}
				else solve(c+1);
				visitedRow[r] = 0;
				indexRow.pop_back();
			}
		}
	}
}


int main(){
	for(int n = 1;n<=10;n++)
	{
		indexRow.clear();
		visitedRow.clear();
		ans = 0;
		solve(0);
		cout<<ans<<" ";
	}
	return 0;
}