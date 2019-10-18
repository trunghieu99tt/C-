#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,x;
	int m;cin>>m;
	for(int i=0;i<m;i++)
	{
		queue<int> q;
		cin>>n;
		for(int j=0;j<n;j++)
		{ 
			cin>>x;
			switch(x)
			{
				case 1: cout<<q.size()<<endl;break;
				case 2:
					if(q.empty()) 
					     cout<<"YES"<<endl;
				    else
					     cout<<"NO"<<endl;
				break;
				case 3:{
					int y;cin>>y;
					q.push(y);
				}
					break;
				case 4:{
					if(!q.empty()) q.pop();
				}
				break;
				case 5:{
					if(!q.empty()) cout<<q.front()<<endl;
				    else cout<<"-1"<<endl;
				}
				break;
				case 6:{
					if(!q.empty()) cout<<q.back()<<endl;
				    else cout<<"-1"<<endl;
				}
				break;
			}
	}
}
	return 0;
}