#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include <iostream>
#include <string.h>
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
			cout <<"\tNhap ngay sinh: ";
			getline(cin,Ngaysinh);
			cout <<"\tNhap SDT: " ;
			getline(cin,SDT);
			cout <<"\tNhap dia chi: ";
			getline(cin,Diachi);
		}
		void Xuatthongtin()
		{
			cout <<"\t\t\tNgay sinh: " << Ngaysinh << endl ;
			cout << "\t\t\tSo dien thoai: " << SDT << endl ;
			cout << "\t\t\tDia chi: " << Diachi <<endl;
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
		friend istream & operator >> (istream &is, KhachHang & k);	// HAM NHAP 1 KHACH HANG
		friend ostream & operator << (ostream &os, KhachHang &k );	// HAM IN 1 KHACH HANG
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
istream & operator >> (istream &is, KhachHang & k)
{
		fflush(stdin);
		cout <<endl<<"\tNhap ma khach hang: ";
		getline(cin,k.MKH);
		k.Nhapthongtin();
		fflush(stdin);
		cout <<"\tNhap ngay mua: " ;
		getline(cin,k.NgayMua);
		cout <<"\tNhap so luong: " ;
		cin >> k.SoLuong ;
		for (int i=1;i<=k.SoLuong;i++)	// mat hang la kieu mang do 1 nguoi co the mua nhieu mon
		{
			fflush(stdin);
			cout <<"\t\tNhap mat hang " << i <<":";
			getline(cin,k.MatHang[i]);
		}
}
ostream & operator << (ostream &os, KhachHang &k )
{
	cout << endl <<"\t\t\tMa khach hang: "<<k.MKH<<endl;
	k.Xuatthongtin();
	cout << "\t\t\tNgay mua hang: " << k.NgayMua << endl ;
	cout << "\t\t\tSo luong: " << k.SoLuong << endl ;
	for (int i=1; i<=k.SoLuong; i++)
	{
			cout << "\t\t\t\tTen mon " << i << ":" << k.MatHang[i] << endl;
	}
}
void KhachHang::GiaThanhToan()
{
	string x1="Cafe den",x2="Cold brew",x3="Bac siu",x4="Cafe sua",x5="Cappuccino",x6="Americano",x7="Tra matcha";
	string x8="Tra vai",x9="Tra hat sen",x10="Hong tra latte",x11="Tra dao cam sa",x12="Tra sua mac ca",x13="Tra viet quoc",x14="Tra sua oolong";
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
		cout<<"\t\t\tUu dai 15% nhan dip sinh nhat";
		cout<<endl<<"\t\t\tGia thanh toan: "<<Tong-((Tong*15)/100)<<"d";
	}
	else
	{
		cout<<"\t\t\tGia thanh toan: "<<Tong <<"d";
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
	int i=0;
	cout<<endl<<"\t\t\t\tDANH SACH KHACH HANG:";
	while (p != NULL) {
		cout<<endl<<"\t\t\t--------------------------------\n";
		cout<<"\t\t\t\tKHACH HANG THU "<<i+1<<endl;
		cout<<(p->data);
		i++;
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
	cin>>v;
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
			cout<<p->data;
			p->data.GiaThanhToan();
		}
		p=p->next;
		
	}
}
//TODO: CLASS NGUYEN LIEU
//NHANVIEN
class NhanVien:private Thongtin{
    private:
        string name,loainhanvien;
        int soluonggio;
    public:
    
        friend istream & operator >> (istream &is, NhanVien & n);	// HAM NHAP 1 NHAN VIEN
		friend ostream & operator << (ostream &os, NhanVien & n);	// HAM IN 1 NHAN VIEN
        void tienluong1tuan();
        string getname();

};
string NhanVien::getname(){
    return name;
}
void NhanVien::tienluong1tuan(){
    float ftienluong=1;
    string a="full time";
    string b="part time";
    if(loainhanvien.compare(a)==0){
        ftienluong=( 27000*soluonggio*7);
       
    }
    else if(loainhanvien.compare(b)==0){
        ftienluong=(17000*soluonggio*7);
    }
    cout<<endl<<"Tien luong:"<<ftienluong<<"d";
 
    
}


istream& operator >> (istream &is, NhanVien & n){
        fflush(stdin);
        cout<<"\tNhap Ho va ten :";
        getline(cin,n.name);
        n.Nhapthongtin();
        fflush(stdin);
        cout<<"\tNhap loai nhan vien:";
        getline(cin,n.loainhanvien);
        cout<<"\tNhap so luong gio:";
        cin>>n.soluonggio;
        return is;
}
ostream& operator << (ostream &os, NhanVien & n){
        cout<<"\t\t\tHo va ten :"<<n.name<<endl;
        n.Xuatthongtin();
        cout<<"\t\t\tLoai nhan vien:"<<n.loainhanvien<<endl;
        cout<<"\t\t\tSo luong gio:"<<n.soluonggio<<endl;
        return os;
}
//Struct Node
struct Node3{
    NhanVien data;
    Node3* next;
};
struct SList3{
        Node3* head;
        Node3* tail;
        long size;
};
//TAO DANH SACH RONG
void SList3rong(SList3 &sl){
    sl.head = NULL;
    sl.tail = NULL;
    sl.size = 0;

}
//TAO NOT MOI 
Node3* TaoNode3(){
    Node3 *p3 = new Node3 ;
    NhanVien v;
    cin>>v;
    p3-> data = v;
    p3-> next= NULL;
    return p3;
}
void addLast(SList3 &sl , Node3*p3){
    
    if(sl.size == 0){
       sl. head = p3 ;
       sl. tail = p3;
    }
    else {
        sl.tail ->next = p3;
        sl.tail = p3 ;
    }
        sl.size ++;


}
void searchbyName(SList3 sl){
    string fname;
	fflush(stdin);
    cout<<"Ten nhan vien muon tim :";
    getline(cin,fname);
    Node3*p3 = sl.head;
    while ( p3!= NULL)
        if(fname == p3-> data.getname()){
              cout<<(p3->data);
          cout<< std::setprecision(20);
              system ("pause");
    }
    else{
    cout <<"Khong tim thay nhan vien !!" <<endl;
      p3 = p3-> next;
    }
	
}
void xuat (SList3 sl) {
	Node3* p3 = sl.head;
	int i=0;
	cout<<endl<<"\t\t\t\tDANH SACH NHAN VIEN:";
	while (p3 != NULL) {
		cout<<endl<<"\t\t\t--------------------------------\n";
		cout<<"\t\t\t\tNHAN VIEN "<<i+1<<endl;
		cout<<(p3->data);
		i++;
		p3 = p3->next;
	}
	cout << endl;
	delete p3;
}
   void wpay (SList3 sl){
    string x;
    fflush (stdin);
    cout<<"\t\t\tNhap ten nhan vien :";
    getline(cin,x);
    Node3*p3 = sl.head;
     while (p3 != NULL){
           if(x.compare(p3->data.getname())==0)
        {    
            cout<< std::setprecision(20);
            cout<<p3->data;
            p3->data.tienluong1tuan();
	 
        
        }
		p3=p3->next;
     }
}
//HAM MENU
void menu()
{
	int luachon;
	SList1 l;
	SList1rong(l);
    SList3 sl;
    SList3rong(sl);
	cout<<"\t========================================================="<<endl;
	cout<<"\t=\t\tNhap 1: Nhap khach hang.\t\t="<<endl;
	cout<<"\t=\t\tNhap 2: Xuat DS khach hang.\t\t="<<endl;
	cout<<"\t=\t\tNhap 3: Hoa don cua mot khach.\t\t="<<endl;
	cout<<"\t=\t\tNhap 4: Nhap ten nhan vien .\t\t="<<endl;
	cout<<"\t=\t\tNhap 5: Xuat danh sach nhan vien .\t="<<endl;
	cout<<"\t=\t\tNhap 6: Tien luong cua nhan vien.\t="<<endl;
	cout<<"\t=\t\tNhap 7: Thoat chuong trinh.\t\t="<<endl;
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
				Xuatds(l);
		}
		if(luachon==3)
		{
			Hoadon(l);
		}
		if(luachon==4)
		{
			Node3*p3=TaoNode3();
			addLast(sl,p3);
		}
		if(luachon==5);
			xuat(sl);
		if(luachon==6)
		{
			wpay(sl);
		}
		if(luachon==7)
		{
			exit(0);
		}
	}
}
int main(){
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	cout<<"\t@                                                         @"<<endl;
	cout<<"\t@                                                         @"<<endl;
	cout<<"\t@          **     **  *****  **   **  **  **              @"<<endl;
	cout<<"\t@          ** * * **  **     ** * **  **  **              @"<<endl;
	cout<<"\t@          **  *  **  *****  **  ***  **  **              @"<<endl;
	cout<<"\t@          **     **  **     **   **  **  **              @"<<endl;
	cout<<"\t@          **     **  *****  **   **   ****               @"<<endl;
	cout<<"\t@                                                         @"<<endl;
	cout<<"\t@                                                         @"<<endl;
	cout<<"\t@   Cafe den      :  35K           Cold brew     :   35K  @"<<endl;
	cout<<"\t@   Bac siu       :  38K           Cafe sua      :   38K  @"<<endl;
	cout<<"\t@   Cappuccino    :  40K           Americano     :   40K  @"<<endl;
	cout<<"\t@   Tra matcha    :  55K           Tra vai       :   55K  @"<<endl;
	cout<<"\t@   Tra hat sen   :  50K           Hong tra latte:   50K  @"<<endl;
	cout<<"\t@   Tra dao cam sa:  59K           Tra sua mac ca:   59K  @"<<endl;
	cout<<"\t@   Tra viet quoc :  60K           Tra sua oolong:   60K  @"<<endl;
	cout<<"\t@                                                         @"<<endl;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl<<endl;

	menu();

    
}
