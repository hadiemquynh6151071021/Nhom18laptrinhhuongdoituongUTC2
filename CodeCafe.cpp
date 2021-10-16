#include <iostream>
#include <string.h>
using namespace std;
class Thongtin{
	private:
		string Ngaysinh,SDT,Diachi;
	public:
		string getns()		//HAM LAY NGAY SINH
		{
			return Ngaysinh;
		}
		void Nhapthongtin()
		{
			fflush(stdin);
			cout << endl <<"Nhap ngay sinh: ";
			getline(cin,Ngaysinh);
			cout << endl << "Nhap SDT: " ;
			getline(cin,SDT);
			cout << endl <<"Nhap dia chi: ";
			getline(cin,Diachi);
		}
		void Xuatthongtin()
		{
			cout <<"Ngay sinh: " << Ngaysinh << endl ;
			cout << "So dien thoai: " << SDT << endl ;
			cout << "Dia chi: " << Diachi <<endl;
		}
		
};
//TODO: CLASS KHACH HANG
class KhachHang: private Thongtin{
	private:
		int SoLuong;
		string MKH,NgayMua, MatHang[20];
	public:
		string getMKH();		//HAM LAY MA KHACH HANG
		string getnm();			//HAM LAY NGAY MUA
		void NhapKhachHang();	// HAM NHAP 1 KHACH HANG
		void XuatKhachHang();	// HAM IN 1 KHACH HANG
		void GiaThanhToan();	//HAM DINH GIA MAT HANG
};
string KhachHang::getMKH()
{
	return MKH;
}
string KhachHang::getnm()
{
	return NgayMua;
}
void KhachHang::NhapKhachHang()
{
		fflush(stdin);
		cout << "Nhap ma khach hang: ";
		getline(cin,MKH);
		Nhapthongtin();
		fflush(stdin);
		cout << endl << "Nhap ngay mua: " ;
		getline(cin,NgayMua);
		cout << endl << "Nhap so luong " ;
		cin >> SoLuong ;
		for (int i=1;i<=SoLuong;i++)	// mat hang la kieu mang do 1 nguoi co the mua nhieu mon
		{
			fflush(stdin);
			cout << endl << "Nhap mat hang " << i <<":";
			getline(cin,MatHang[i]);
		}
}
void KhachHang::XuatKhachHang() {
	cout << endl <<"Ma khach hang: "<<MKH<<endl;
	Xuatthongtin();
	cout << "Ngay mua hang: " << NgayMua << endl ;
	cout << "So luong: " << SoLuong << endl ;
	for (int i=1; i<=SoLuong; i++)
	{
			cout << "Ten mon " << i << ":" << MatHang[i] << endl;
	}
	GiaThanhToan();
}
void KhachHang::GiaThanhToan()
{
	string x1="Cafe den",x2="Cold brew",x3="Bac siu",x4="Cafe sua",x5="Cappuccino",x6="Americano",x7="Tra matcha";
	string x8="Tra vai",x9="Tra hat sen",x10="Hong tra latte",x11="Tra dao cam sa",x12="Tra sua mac ca",x13="Tra viet quoc dau thom",x14="Tra sua oolong";
	float *Gia=new float[SoLuong];		// cap phat bo nho dong cho mang gia
	float Tong=0;
	for (int i=1;i<=SoLuong;i++)
	{
		if(MatHang[i].compare(x1)==0||MatHang[i].compare(x2)==0)		//trong c++ de so sanh hai chuoi ta dung compare
		{
			Gia[i]=35000;
		}
		else if(MatHang[i].compare(x3)==0||MatHang[i].compare(x4)==0)
		{
			Gia[i]=38000;
		}
		else if(MatHang[i].compare(x5)==0||MatHang[i].compare(x6)==0)
		{
			Gia[i]=40000;
		}
		else if(MatHang[i].compare(x7)==0||MatHang[i].compare(x8)==0)
		{
			Gia[i]=55000;
		}
		else if(MatHang[i].compare(x9)==0||MatHang[i].compare(x10)==0)
		{
			Gia[i]=50000;
		}
		else if(MatHang[i].compare(x11)==0||MatHang[i].compare(x12)==0)
		{
			Gia[i]=59000;
		}
		else
		{
			Gia[i]=60000;
		}
	}
	for (int i=0;i<=SoLuong;i++)		//cau lenh tinh tong trong truong hop 1 nguoi mua 2 mat hang khac nhau
		{
			Tong += Gia[i];
			
		}
	if(getns().compare(getnm())==0)
	{
		cout<<"Uu dai 15% nhan dip sinh nhat";
		cout<<endl<<"Gia thanh toan: "<<Tong-((Tong*15)/100);
	}
	else
	{
		cout<<endl<<"Gia thanh toan: "<<Tong <<"d";
	}
	delete [] Gia;
}
//STRUCT NODE
struct Node{
	KhachHang data;
	Node *next;
};
//STRUCT DANH SACH
struct SList1{
	Node *head;
	Node *tail;
	long size;
};
//HAM DANH SACH RONG
void SList1rong(SList1 &l){
	l.head = NULL;
	l.tail = NULL;
	l.size = 0;
}
//HAM XUAT 1 DANH SACH
void Xuatds(SList1 l) {
	Node* p = l.head;
	while (p != NULL) {
		(p->data).XuatKhachHang();
		p = p->next;
	}
	cout << endl;
	delete p;
}
//HAM TAO 1 NODE
Node* Taonode1()
{
	KhachHang v;
	Node* p = new Node;
	v.NhapKhachHang();
	p->data = v ;	
	p->next = NULL;	
	return p;
}
//HAM THEM 1 NODE KHACH HANG VAO CUOI DANH SACH
void Themcuoi1(SList1 &l,Node *p)
{
		if (l.size == 0) {
			l.head = p;
			l.tail = p;
		}
		else {
			l.tail->next = p;
			l.tail = p;	  
		}
		l.size = l.size + 1;
}
//HAM IN HOA DON 1 KHACH DUA VAO MKH
void Hoadon(SList1 &l)
{
	string x;
	fflush(stdin);
	cout<<"Ma khach hang can tim:";
	getline(cin,x);
	Node* p = l.head;
	while (p != NULL) 
	{
		if(x.compare(p->data.getMKH())==0)
		{
			p->data.XuatKhachHang();
		}
		p=p->next;
	}
}
//HAM MENU
void menu(SList1 &l)
{
	int luachon;
	cout<<"\t========================================================="<<endl;
	cout<<"\t=\t\tNhap 1: Nhap khach hang.\t\t="<<endl;
	cout<<"\t=\t\tNhap 2: Hoa don cua mot khach.\t\t="<<endl;
	cout<<"\t========================================================="<<endl;
	cout<<"\t\t\tNhap lua chon: ";
	while (1)
	{
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1)
		{
			Node *p=Taonode1();
			Themcuoi1(l,p);
		}
		if(luachon==2)
		{
			Hoadon(l);
		}
	}
}
//TODO: CLASS NGUYEN LIEU
int main(){
	SList1 l;
	SList1rong(l);
	menu(l);
}

