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

string intToStr(int n)
{
	string ans;
	ostringstream s;
	s<<n;
	ans = s.str();
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    map<string,int> counterWords;
    cin.ignore();
    forn(k,t)
    {
    	string s;
    	getline(cin,s);
    	vector<string> words;
    	stringstream ss(s);
    	string token;
    	while(ss>>token)
    		words.push_back(token);
    	string ans = "";
    	int i,n = words.size();
    	token = "";
    	forn(i,n)
    	{
    		toLower(words[i]);
    		if(i!=n-1)
    			token+=words[i][0];
    		else ans+=words[i];
    	}
    	ans+=token;
    	token = ans;
    	//cout<<token<<" "<<counterWords[token]<<endl;
    	if(counterWords[token])
    	{
    		int n = counterWords[ans] + 1;
    		ans+=intToStr(n);
    	}
    	counterWords[token]++;
    	if(ans!=token)
    		counterWords[ans]++;
    	ans+="@ptit.edu.vn";
    	cout<<ans<<endl;
    }
    return 0;
}