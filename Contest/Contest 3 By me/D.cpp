#include<bits/stdc++.h>
using namespace std;
priority_queue <long long , vector<long> , greater<long> >pq;
const int mod = 1e9 + 7;
long long n;
void Init(){
    cin>> n;
    for(int i=1;i<=n;i++){
        long long tmp;
        cin>> tmp;
        pq.push(tmp);
    }
}
long long OPT(){
    long long opt=0;
    while(pq.size()>1){
        long long first=pq.top();pq.pop();
        long long second=pq.top();pq.pop();
        opt+=(first+second)%mod;
        opt%=mod;
        pq.push((first+second)%mod);
    }
    return opt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    Init();
    cout<< OPT();
}