#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef vector<int> vi;
typedef vector<char> vc;
#define vi vector<int>
int checkPerfect(int n)
{
    int k=sqrt(n);
    return k*k==n;
}
int constructSquare(string s) {
    vi c(26,0);
    for (auto i:s)
        c[i-'a']++;
    sort(all(c));
    int n=s.length(),i;
    for (i=pow(10,n)-1;i>=pow(10,n-1);i--)
    {
        if(checkPerfect(i))
        {
            string k=to_string(i);
            vi c1;
            for (auto j:k)
                c1[j-'a']++;
            sort(all(c1));
            if(c1==c) return i;
        }

    }
    return -1;
}
