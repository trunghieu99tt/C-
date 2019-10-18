#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

void toLower(string &s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    forn(k,t)
    {
    	cin.ignore();
    	string s1, s2;
    	getline(cin,s1);
    	cin>>s2;
    	vector<string> words;
    	stringstream ss(s1);
    	string token;
    	while(ss>>token)
    		words.push_back(token);
    	int i;
    	toLower(s2);
    	cout<<"Test "<<k+1<<": ";
    	for(i = 0;i<words.size();i++)
    	{
    		string t1 = words[i];
    		toLower(t1);
    		if(s2!=t1)
    			cout<<words[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}