#include <bits/stdc++.h>
using namespace std;
 
string s;
long long k;
 
long long test(long long n){
	if(k<=s.size())	return k-1;
	if(k > n/2)
		k=k-n/2-1;
	if(k==0) k=n/2;
	return test(n/2);
}
 
int main(){
	cin>>s>>k;
	long long n= s.size(), n1 = n;
	while(n < k)
		n*=2;
	long long index= test(n);
	cout<<s[index];
	return 0;
}