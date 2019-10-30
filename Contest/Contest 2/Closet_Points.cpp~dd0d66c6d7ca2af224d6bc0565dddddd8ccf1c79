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
typedef pair<int,int> pii;
struct Point{
	int x, y;
};

bool cmpX(Point& a, Point& b)
{
	return a.x < b.x;
}

bool cmpY(Point& a, Point& b)
{
	return a.y < b.y;
}

double dist(Point a, Point b)
{
	return sqrt(round(pow(b.x - a.x,2)) + round(pow(b.y - a.y,2)));
}

const int maxn = 1e5;

struct point {
    double x, y;
};

bool cmp_x(const point &a, const point &b) {
    return a.x < b.x;
}

bool cmp_y(const point &a, const point &b) {
    return a.y < b.y;
}

#define MAXN 100000
point a[MAXN];
double mindist;

void upd_ans(const point &a, const point &b) {
    double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if (dist < mindist) mindist = dist;
}

void find(int l, int r) {
    if (r <= l) return;
    if (r == l + 1) {
        upd_ans(a[l], a[r]);
        if (!cmp_y(a[l], a[r])) swap(a[l], a[r]);
        return;
    }

    int m = (l + r) / 2;
    int midx = a[m].x;
    find(l, m);
    find(m+1, r);

    static point t[MAXN];
    merge(a+l, a+m+1, a+m+1, a+r+1, t, cmp_y);
    copy(t, t+r-l+1, a+l);
    int tm = 0;
    for (int i=l; i<=r; i++) if (abs(a[i].x-midx) < mindist) {
        for (int j=tm-1; j>=0 && t[j].y > a[i].y-mindist; j--)
            upd_ans(a[i], t[j]);
        t[tm++] = a[i];
    }
}




int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,j;
        forn(i,n)
        	cin>>a[i].x>>a[i].y;
        sort(a,a+n,cmp_x);
        find(0,n-1);
        cout<<setprecision(6)<<fixed<<mindist<<endl;
    }
    return 0;
}
