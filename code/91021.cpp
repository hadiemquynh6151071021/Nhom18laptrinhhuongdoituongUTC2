//Ha Diem Quynh 6151071021
#include<iostream>
#include<math.h>
using namespace std;
class Hocsinh{
	private:
		string hoten;
		float diemtoan;
		float diemvan;
	public:
		float gettoan();
		float getvan();
		float diemTB();
		static int dem;
		Hocsinh();
		Hocsinh(string hoten);
		Hocsinh(string hoten,float diemtoan,float diemvan);
		Hocsinh(const Hocsinh &hs);
		~Hocsinh();
		bool operator > (Hocsinh hs);
		bool operator < (Hocsinh hs);
		bool operator == (Hocsinh hs);
		bool operator >= (Hocsinh hs);
		bool operator <= (Hocsinh hs);
		bool operator != (Hocsinh hs);
		friend istream& operator >> (istream &is, Hocsinh &hs);
		friend ostream& operator << (ostream &os, Hocsinh &hs);
		Hocsinh operator=(const Hocsinh &hs);	
};
float Hocsinh::gettoan()
{
		return diemtoan;
}
float Hocsinh::getvan()
{
		return diemvan;
}
float Hocsinh::diemTB()
{
	return (gettoan()+getvan())/2;
}
int Hocsinh::dem=0;
Hocsinh::Hocsinh()
{
	hoten="Ha Diem Quynh";
	diemtoan=8.0;
	diemvan=6.5;
}
Hocsinh::Hocsinh(string hoten)
{
	this->hoten=hoten;
	this->diemtoan=0;
	this->diemvan=0;
}
Hocsinh::Hocsinh(string hoten,float diemtoan,float diemvan)
{
	this->hoten=hoten;
	this->diemtoan=diemtoan;
	this->diemvan=diemvan;
}
Hocsinh::Hocsinh(const Hocsinh &hs)
{
	this->hoten=hs.hoten;
	this->diemtoan=hs.diemtoan;
	this->diemvan=hs.diemvan;
}
Hocsinh::~Hocsinh()
{
	
};
bool Hocsinh::operator >(Hocsinh hs)
{
	if(diemTB()>hs.diemTB())
	{
		return true;
	}
	return false;
}
bool Hocsinh::operator <(Hocsinh hs)
{
	if(diemTB()<hs.diemTB())
	{
		return true;
	}
	return false;
}
bool Hocsinh::operator >=(Hocsinh hs)
{
	if(diemTB()>=hs.diemTB())
	{
		return true;
	}
	return false;
}
bool Hocsinh::operator <=(Hocsinh hs)
{
	if(diemTB()<=hs.diemTB())
	{
		return true;
	}
	return false;
}
bool Hocsinh::operator ==(Hocsinh hs)
{
	if(diemTB()==hs.diemTB())
	{
		return true;
	}
	return false;
}
bool Hocsinh::operator !=(Hocsinh hs)
{
	if(diemTB()!=hs.diemTB())
	{
		return true;
	}
	return false;
}
istream & operator >> (istream & is, Hocsinh &hs)
{
	cout <<"\nNhap ho va ten: ";
	fflush(stdin);
	getline(is,hs.hoten);
	cout<<endl<<"Nhap diem toan: ";
	is>>hs.diemtoan;
	cout<<endl<<"Nhap diem van: ";
	is>>hs.diemvan;
	return is;
}
ostream& operator << (ostream &os, Hocsinh &hs)
{
	cout<<"\nHoc sinh thu: "<<++hs.dem;
	cout<<"\nHO VA TEN: "<<hs.hoten<<endl;
	cout<<"DIEM TOAN: "<<hs.diemtoan<<endl;
	cout<<"DIEM VAN: "<<hs.diemvan<<endl;
	cout<<"DIEM TRUNG BINH: "<<hs.diemTB()<<endl;
	return os;
}
Hocsinh Hocsinh::operator=(const Hocsinh &hs)
{
	this->hoten=hs.hoten;
	this->diemvan=hs.diemvan;
	this->diemtoan=hs.diemtoan;
}

int main()
{
	Hocsinh hs1,hs2("Nguyen Van A"),hs3("Le Van B",10,10),hs4(hs3),hs5,hs6,hs7;
	cout<<"-----------------------------------------------------------------------";
	cout<<hs1;
	cout<<"-----------------------------------------------------------------------";
	cout<<hs2;
	cout<<"-----------------------------------------------------------------------";
	cout<<hs3;
	cout<<"-----------------------------------------------------------------------";
	cout<<hs4;
	cout<<"-----------------------------------------------------------------------";
	cin>>hs5;
	cout<<hs5;
	cout<<"-----------------------------------------------------------------------";
	cin>>hs6;
	cout<<hs6;
	cout<<"-----------------------------------------------------------------------";
	hs7=hs6;
	cout<<hs7;
}

