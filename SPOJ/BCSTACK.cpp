#include<iostream>
#define maxn 10000
using namespace std;
long stack[1001];
int top=0;
void init()
{
	top=0;
}
void push(long v)
{
	top++;
	stack[top]=v;
}
int empty()
{
	if(top==0) return 1; else return 0;
}
void pop()
{
	if(empty()==0) top--;
}
long Top()
{
	if(empty()==1) return -1;
	return stack[top];
}
int size()
{
	return top;
}
int main()
{
   while(1)
   {
   	string s;
   	long x;
   	cin>>s;;
   	if(s=="init") init();
   	else if(s=="push") 
   	{
   		cin>>x;
   		push(x);
   	}
   	else if(s=="pop") pop();
   	else if(s=="top") cout<<Top()<<endl;
   	else if(s=="size") cout<<size()<<endl;
   	else if(s=="empty") cout<<empty()<<endl;
   	else if(s=="end") return 0;
   }
   return 0;
}
