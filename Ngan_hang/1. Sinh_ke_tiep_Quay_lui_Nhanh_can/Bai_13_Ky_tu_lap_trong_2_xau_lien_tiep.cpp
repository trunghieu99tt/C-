#include<bits/stdc++.h>

using namespace std;

int count(string a, string b)
{
    map<int,int> cnt, visited;
    int ans = 0;
    for(auto i:a)
        cnt[i]++;
    for(auto i:b)
        if(!visited[i] && cnt[i])
        {
            ans++;
            visited[i] = 1;
        }
    return ans;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;
    vector<string> words;
    words.resize(n);
    int i,j, ans = INT_MAX;
    for(auto &i:words)
        cin>>i;
    sort(begin(words),end(words));
    do{
        int temp = 0;
        for(i = 0;i<n-1;i++)
            temp+= count(words[i], words[i+1]);
        ans = min(ans, temp);
    }
    while(next_permutation(words.begin(),words.end()));
    cout<<ans;
    return 0;
}