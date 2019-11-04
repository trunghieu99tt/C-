#include<iostream>
using namespace std;
struct Sinhvien
{
	char MaSV[20];
	char TenSV[1000];
	char DcSV[100];
	float toan, ly, hoa;
};
void NhapSinhvien(Sinhvien &sinhvien)
{
	cout<<"Moi nhap Ma SV: "; cin>>sinhvien.MaSV; 
	cin.ignore();
	cout<<"Moi nhap Ten SV : "; gets(sinhvien.TenSV);
	cout<<"Moi nhap dia chi SV :"; gets(sinhvien.DcSV);
	cout<<"Moi nhap diem Toan, Ly, Hoa : " ; cin>>sinhvien.toan>>sinhvien.ly>>sinhvien.hoa;
}
void Xuat(Sinhvien sinhvien)
{
	cout<<"Ma SV : "<<sinhvien.MaSV<<endl;
	cout<<"Ten SV : "<<sinhvien.TenSV<<endl;
	cout<<"Dia chi SV : "<<sinhvien.DcSV<<endl;
	cout<<"Diem Toan Ly Hoa lan luot la: "<<sinhvien.toan<<" "<<sinhvien.ly<<" "<<sinhvien.hoa<<endl;
}
int main()
{
	int n;
	cin>>n;
	Sinhvien sinhvien[n];
	for (int i=0;i<n;i++)
	{
		cout<<"Moi nhap thong tin sinh vien thu "<<i+1<<" : "<<endl;
		NhapSinhvien(sinhvien[i]);
		cout<<"--------------------------"<<endl;
		cout<<"Moi ban xac nhan lai thong tin : "<<endl;
		Xuat(sinhvien[i]);
		cout<<"Diem Trung Binh cua sinh vien "<<i+1<<" la: "<<(sinhvien[i].toan+sinhvien[i].ly+sinhvien[i].hoa)/3<<endl;
		cout<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
	}
	return 0;
}
