/*
   Tên bài:  Khung tranh của Daniel.
   Thuật toán: 
   Khởi tạo một mảng đánh dấu các thanh có độ dài từ 1 đếm 100 ( ban đầu cho tất cả các giá trị bằng 0)
   
 */
 
#include<iostream>
using namespace std;
int a1[101],i;
void khoitao()
{
	for (i=1;i<=100;i++) a1[i]=0;
}
int main()
{
    int t,k;
    cin>>t;
    for (k=0;k<t;k++)
    {
    	khoitao();
    	int n;
    	cin>>n;
    	int a[n],dem2=0,dem4=0,tong=0;
    	for (i=0;i<n;i++)
    	{
    		cin>>a[i];
    		a1[a[i]]++;
		}
		for (i=1;i<=100;i++) 
		 {
		 	if(a1[i]>=4) 
		 	{
		 		dem4+=(a1[i]/4);
		 		a1[i]%=4;
			 }
			if(a1[i]>=2)
			{
				dem2+=(a1[i]/2);
				a[i]%=2;
			}
		 }
	    cout<<dem2/2+dem4<<endl;
	}
	return 0;
}
