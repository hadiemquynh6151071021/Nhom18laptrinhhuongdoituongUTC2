//HA DIEM QUYNH 6151071021
#include<iostream>
using namespace std;
class vector{
	private:
		int n;
		float *v;
	public:
		vector(int size);
		vector(vector &x);
		~vector();
		void nhap();
		void xuat();
		void operator=(vector &x);
		friend vector operator +(vector &x, vector &y);
};
vector::vector(int size){
	n=size;
	v=new float[n];
}
void vector::nhap(){
	for (int i=0;i<n;i++){
		cout<<"\nNhap v["<<i<<"]= ";
		cin>>v[i];
	}
}
vector::vector(vector &x){
	n=x.n;
	v=new float [n];
	for(int i=0;i<n;i++){
		v[i]=x.v[i];
	}
}
vector::~vector(){
	delete v;
}
void vector::xuat(){
	for(int i=0;i<n;i++){
		cout<<v[i]<<"	";
	}
}
void vector::operator=(vector &x){
	n=x.n;
	v=new float[n];
	for(int i;i<n;i++){
		v[i]=x.v[i];
	}
}
vector operator +(vector &x,vector &y){
	vector c=x;
	for(int i;i<x.n;i++){
		c.v[i]=x.v[i]+y.v[i];
	}
		return c;	
}
int main(){
	int n;
	cout<<"Nhap so phan tu cua vector a: ";
	cin>>n;
	vector a(n);
	cout<<endl<<"Nhap vecto a:";
	a.nhap();
	cout<<"----------------------------------------------------------------\n";
	a.xuat();
	cout<<"\nNhap so phan tu cua vector b: ";
	cin>>n;
	vector b(n);
	cout<<endl<<"Nhap vecto b:";
	b.nhap();
	cout<<"----------------------------------------------------------------\n";
	b.xuat();
	cout<<"----------------------------------------------------------------\n";
	cout<<"Ket qua: ";
	(a+b).xuat();
}


