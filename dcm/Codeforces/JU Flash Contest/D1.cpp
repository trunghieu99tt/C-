#include<iostream>
using namespace std;

bool check(int n, int a, int b, int s){
	return s>= a*(n-1)+b && s<=a + (n-1)*b;
}
int main(){
	int n, a, b, s;
	cin>>n>>a>>b>>s;
	if(check(n,a, b, s)){
		cout<<"YES";
	}else cout<<"NO";
}