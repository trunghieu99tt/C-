#include<iostream>
using namespace std;
int main()
{
   while(1)
   {
   	   int n,i,a[300],k=0,dem=0,j;
   	   cin>>n;
   	   if(n==0) return 0;
   	   for (i=0;i<n;i++)
   	   {
   	   	   int m;
   	   	   cin>>m;                                      // nhap so lua chon cua BGK
   	   	   int b[m];
   	   	   for (j=0;j<m;j++) 
   	   	   {                    
   	   	   	cin>>b[j];
   	   	   	a[k++]=b[j];                             // nhap so bao danh cua thi sinh (mang b) va tao mang chua so bao danh cua cac thi sinh(mang a)
   	   	   	dem++;                                    // dem so phan tu cua mang a
			}
		}
	   int c[dem],l=0,dem1=1;
	   c[0]=a[0];
	   for (i=1;i<dem;i++)
	   {
	   	bool flag=true;
	   	  for (j=i-1;j>=0;j--) 
	   	   if(a[i]==a[j])                              
	   	   {
	   	   	flag=false;
	   	   	break;
			}
		if(flag==true) 
		{
			c[++l]=a[i];                        // tao mang c gom cac so bao danh phan biet
			dem1++;                             // dem so phan tu cua mang c
		}
	   } 
	   int so1[dem1],so2[dem1],so3[dem1],d[dem1];
	   for (i=0;i<dem1;i++) 
	   {
	   	    for (j=0;j<dem;j++)
	   	      if(a[j]==c[i])
	   	      {
	   	      	if(j%3==0) 
	   	      	{
	   	      		so1[c[i]]++;                                          // tinh diem cua cac thi sinh va dem so lan #1,#2,#3 cua thi sinh do 	   	      		
	   	      		d[i]+=3;                                           // trong do mang so la so lan #1,2,3 , mang d la mang diem
				}
	   	      	else if(j%3==1) 
	   	      	{
	   	      		so2[c[i]]++;
	   	      		d[i]+=2;
				}
	   	      	else so3[i]++;
	   	      	{
	   	      		so3[c[i]]++;
	   	      		d[i]++;
				}
			}
	   }
	   int dmax=d[0];
	   for (i=1;i<dem1;i++)
	     if(d[i]>dmax) dmax=d[i];                           // tim so diem max cua cac thi sinh
	    int e[dem1],f=0,dem2=0;                                        // tao mang e chua cac thi sinh co diem=max de so sanh
	    for (i=0;i<dem1;i++)
	    {
	    	if(d[i]==dmax) 
	    	{
	    		e[f++]=c[i];
	    		dem2++;
			}
		}
		if(dem2==1) cout<<e[0]<<endl;
		else
		{
			int kq[dem2],p=0,max;
			max=e[0];
			for (i=1;i<dem2;i++) 
			{
				 if(so[e[i]]>)
			}
		}
   }
}
