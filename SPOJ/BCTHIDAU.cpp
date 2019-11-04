#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string Winner;
	int mintime=1000000,maxsub=0;
	for (int k=0;k<n;k++)
	{
		string name;
		int p1sub,p1time,p2sub,p2time,p3sub,p3time,p4sub,p4time;
		cin>>name>>p1sub>>p1time>>p2sub>>p2time>>p3sub>>p3time>>p4sub>>p4time;
		int FineTime=0,sum=0;
		if(p1time!=0)
		{
			sum++;
			FineTime+=(p1sub-1)*20+p1time;
		}
		if(p2time!=0)
		{
			sum++;
			FineTime+=(p2sub-1)*20+p2time;
		}
		if(p3time!=0)
		{
			sum++;
			FineTime+=(p3sub-1)*20+p3time;
		}
		if(p4time!=0)
		{
			sum++;
			FineTime+=(p4sub-1)*20+p4time;
		}
		if(sum>maxsub)
		{
			maxsub=sum;
			Winner=name;
		}
		else if(sum==maxsub && FineTime<mintime)
		{
			mintime=FineTime;
			Winner=name;
		}
	}
	cout<<Winner<<" "<<maxsub<<" "<<mintime;
	return 0;
}