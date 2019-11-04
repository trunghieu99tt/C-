#include<iostream>
using namespace std;
struct Nhanvien
{
    char ms[100];
	char  hoten[100];
	char dc[100];
	int i;
};
void Nhap(Nhanvien &nv)
{
	cout<<"Moi nhap ma so nhan vien : "; cin>>nv.ms; 
	cin.ignore();
	cout<<"Moi nhap ho ten nhan vien : "; gets(nv.hoten); 
	cout<<"Moi nhap dia chi nhan vien : "; gets(nv.dc); 
	cout<<"Moi nhap so chi chuc vu : "; cin>>nv.i;
}
void Xuat (Nhanvien nv)
{
	cout<<"ma so nhan vien : "<<nv.ms<<endl;
	cout<<"ho ten nhan vien : "<<nv.hoten<<endl;
	cout<<"dia chi nhan vien : "<<nv.dc<<endl;
	if(nv.i==1) cout<<"Quan Ly"<<endl; else cout<<"Nhan vien "<<endl;
}
int main()
{
	int n;
	cin>>n;
	Nhanvien nv[n];
	for (int i=1;i<=n;i++)
	{
		 cout<<"Moi nhap thong tin cua nhan vien "<<i<<": "<<endl;
		 Nhap(nv[i]);
		 cout<<"----------------------------"<<endl;
		 cout<<"Moi ban kiem tra lai : "<<endl;
		 Xuat(nv[i]);
         cout<<"-------------------------------------------------------------------------"<<endl;
	}
}
