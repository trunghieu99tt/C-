#include<bits/stdc++.h>

using namespace std;

int strToNum(string s)
{
	int ans;
	istringstream is(s);
	is >> ans;
	return ans;
}

const int maxn = 2000;

int matrix[maxn][maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int i, j;
	cin.ignore();
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
			matrix[i][j] = 0;
		string s;
		getline(cin, s);
		vector<int> number;
		string token;
		stringstream ss(s);
		while (ss >> token)
			number.push_back(strToNum(token));
		for (j = 0;j < number.size();j++)
			matrix[i][number[j] - 1] = 1;
	}
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}