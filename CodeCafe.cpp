#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>

void menu1();
void menu2();
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

using namespace std;
class Nguoi{
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
		virtual void GiaTien()=0;
		
};
//TODO: CLASS KHACH HANG
class KhachHang: private Nguoi{
	private:
		int SoLuong;
		string MKH,NgayMua, MatHang[20];
	public:
		string getMKH();		//HAM LAY MA KHACH HANG
		string getnm();			//HAM LAY NGAY MUA
		friend istream & operator >> (istream &is, KhachHang & k);	// HAM NHAP 1 KHACH HANG
		friend ostream & operator << (ostream &os, KhachHang &k );	// HAM IN 1 KHACH HANG
		void GiaTien();	//HAM DINH GIA MAT HANG VA TINH TIEN
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
void KhachHang::GiaTien()
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
//HAM XUAT 1 DANH SACH
void XuatDSKH(SList1 l) {
	Node* p = l.head;
	if(p==NULL)
	{
			cout<<"\n\t\t\tDanh sach rong.";
			cout<<"\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
	}
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
	Beep(523,500);  //lenh tao am thanh
    cin.get(); 
	delete p;
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
			p->data.GiaTien();
		}
		p=p->next;
	}
	if(p=NULL)
	{
		cout<<"\t\t\tKhong co khach hang trong danh sach";
		cout<<"\t\t\tNHAN PHIM 3 DE TIM LAI.";
	}
	Beep(523,500);  //lenh tao am thanh
    cin.get(); 
}
//TODO: CLASS NGUYEN LIEU
//NHANVIEN
class NhanVien:private Nguoi{
    private:
        string name,loainhanvien;
        int soluonggio;
    public:
        friend istream & operator >> (istream &is, NhanVien & n);	// HAM NHAP 1 NHAN VIEN
		friend ostream & operator << (ostream &os, NhanVien & n);	// HAM IN 1 NHAN VIEN
        void GiaTien();
        string getname();

};
string NhanVien::getname(){
    return name;
}
void NhanVien::GiaTien(){
    float ftienluong=1;
    string a="Full time";
    string b="Part time";
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
        cout<<"\tNhap loai nhan vien:";
        getline(cin,n.loainhanvien);
        cout<<"\tNhap so luong gio:";
        is>>n.soluonggio;
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
    NhanVien data3;
    Node3* next3;
};
struct SList3{
        Node3* head3;
        Node3* tail3;
        long size3;
};
//TAO DANH SACH RONG
void SList3rong(SList3 &sl){
    sl.head3 = NULL;
    sl.tail3 = NULL;
    sl.size3 = 0;

}
//TAO NOT MOI 
Node3* TaoNode3(){
	NhanVien v;
    Node3 *p3 = new Node3 ;
    cin>>v;
    p3->data3 = v;
    p3->next3= NULL;
    return p3;
}
void addLast(SList3 &sl , Node3 *p3){
    
    if(sl.size3 == 0){
       sl. head3 = p3 ;
       sl. tail3 = p3;
    }
    else {
        sl.tail3 ->next3 = p3;
        sl.tail3 = p3 ;
    }
        sl.size3 =sl.size3+1;


}
void searchbyName(SList3 sl){
    string fname;
	fflush(stdin);
    cout<<"Ten nhan vien muon tim :";
    getline(cin,fname);
    Node3*p3 = sl.head3;
    while ( p3!= NULL)
    {
	    if(fname == p3->data3.getname())
		{
	        cout<<(p3->data3);
	  	}
	    p3 = p3-> next3;
    }
    if (p3==NULL)
    {
    	cout<<"\n\t\t\tKhong tim thay nhan vien.";
    	cout<<"\n\t\t\tNHAN PHIM 3 DE TIM LAI.";
    }
    Beep(523,500);  //lenh tao am thanh
    cin.get(); 
	
}
void XuatDSNV(SList3 sl) {
	Node3* p3 = sl.head3;
	if(p3==NULL)
	{
			cout<<"\n\t\t\tDanh sach rong.";
			cout<<"\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
	}
	int i=0;
	cout<<endl<<"\t\t\t\tDANH SACH NHAN VIEN:";
	while (p3 != NULL) {
		cout<<endl<<"\t\t\t--------------------------------\n";
		cout<<"\t\t\t\tNHAN VIEN THU "<<i+1<<endl;
		cout<<(p3->data3);
		i++;
		p3 = p3->next3;
	}
	Beep(523,500);  //lenh tao am thanh
    cin.get(); 
	cout << endl;
	delete p3;
}
void wpay (SList3 sl){
    string x;
    fflush (stdin);
    cout<<"\t\t\tNhap ten nhan vien :";
    getline(cin,x);
    Node3*p3 = sl.head3;
    while (p3 != NULL){
           if(x.compare(p3->data3.getname())==0)
        {    
            cout<< std::setprecision(20);
            cout<<p3->data3;
            p3->data3.GiaTien();
        }
		p3=p3->next3;
    }
    if(p3==NULL)
	{
			cout<<"\n\t\t\tKhong tim thay nhan vien.";
			cout<<"\n\t\t\tNHAN PHIM 4 DE TIM LAI.";
	}
    Beep(523,500);  //lenh tao am thanh
    cin.get(); 
}
//HAM MENU CHUNG
void menuChung()
{
	int n;
	gotoxy(10,5);
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;	gotoxy(10,6);
	cout<<"@                                                          @"<<endl; gotoxy(10,7);
	cout<<"@                                                          @"<<endl; gotoxy(10,8);
	cout<<"@          **     **  *****  **   **  **  **               @"<<endl; gotoxy(10,9);
	cout<<"@          ** * * **  **     ** * **  **  **               @"<<endl; gotoxy(10,10);
	cout<<"@          **  *  **  *****  **  ***  **  **               @"<<endl; gotoxy(10,11);
	cout<<"@          **     **  **     **   **  **  **               @"<<endl; gotoxy(10,12);
	cout<<"@          **     **  *****  **   **   ****                @"<<endl; gotoxy(10,13);
	cout<<"@                                                          @"<<endl; gotoxy(10,14);
	cout<<"@                                                          @"<<endl; gotoxy(10,15);
	cout<<"@   Cafe den      :  35K           Cold brew     :   35K   @"<<endl; gotoxy(10,16);
	cout<<"@   Bac siu       :  38K           Cafe sua      :   38K   @"<<endl; gotoxy(10,17);
	cout<<"@   Cappuccino    :  40K           Americano     :   40K   @"<<endl; gotoxy(10,18);
	cout<<"@   Tra matcha    :  55K           Tra vai       :   55K   @"<<endl; gotoxy(10,19);
	cout<<"@   Tra hat sen   :  50K           Hong tra latte:   50K   @"<<endl; gotoxy(10,20);
	cout<<"@   Tra dao cam sa:  59K           Tra sua mac ca:   59K   @"<<endl; gotoxy(10,21);
	cout<<"@   Tra viet quoc :  60K           Tra sua oolong:   60K   @"<<endl; gotoxy(10,22);
	cout<<"@                                                          @"<<endl; gotoxy(10,23);
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl<<endl;
	gotoxy(35.5,27);
	cout<<"NHAN PHIM";
	gotoxy(35.5,28);
	cout<<"1.Khach hang.";
	gotoxy(35.5,29);
	cout<<"2.Nhan vien.";
	cout<<"\nNhap doi tuong muon xu ly:";
	cin>>n;
	if(n==1)
	{
		system("cls");
		menu1();
	}
	if(n==2)
	{
		system("cls");
		menu2();
	}
}
//MENU1
void menu1()
{
	int luachon;
	SList1 l;
	SList1rong(l);
	system("cls");
    gotoxy(11,5);
	cout<<"=========================================================="<<endl; gotoxy(11,6);
	cout<<"=               Nhap 1: Nhap khach hang.                 ="<<endl; gotoxy(11,7);
	cout<<"=               Nhap 2: Xuat DS khach hang.              ="<<endl; gotoxy(11,8);
	cout<<"=               Nhap 3: Hoa don cua mot khach.           ="<<endl; gotoxy(11,9);
	cout<<"=               Nhap 4: Tro ve menu chinh.               ="<<endl; gotoxy(11,10);
	cout<<"=               Nhap 5: Thoat chuong trinh.              ="<<endl; gotoxy(11,11);
	cout<<"=========================================================="<<endl; gotoxy(11,12);
	fflush(stdin);
	cout<<"Nhap lua chon: ";
	while (1)

	{
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1)
		{
			int n,i=0;
			cout<<"\nNhap so luong khach hang:";
			cin>>n;
			for(int j=0;j<n;j++)
			{
				cout<<"Khach hang thu "<<++i<<":"<<endl;
				Node *p=Taonode1();
				Themcuoi1(l,p);
			}
		}
		if(luachon==2)
		{
			XuatDSKH(l);
		}
		if(luachon==3)
		{
			Hoadon(l);
		}
		if(luachon==4)
		{
			system("cls");
			menuChung();
		}
		if(luachon==5)
		{
			exit(0);
		}
	}
}
void menu2()
{
	int luachon;
	SList3 sl;
	SList3rong(sl);
	system("cls");
    gotoxy(11,5);
	cout<<"=========================================================="<<endl; gotoxy(11,6);
	cout<<"=               Nhap 1: Nhap nhan vien.                  ="<<endl; gotoxy(11,7);
	cout<<"=               Nhap 2: Xuat DS nhan vien.               ="<<endl; gotoxy(11,8);
	cout<<"=               Nhap 3: Tim kiem nhan vien.              ="<<endl; gotoxy(11,9);
	cout<<"=               Nhap 4: Xuat luong nhan vien.            ="<<endl; gotoxy(11,10);
	cout<<"=               Nhap 5: Tro ve menu chinh.               ="<<endl; gotoxy(11,11);
	cout<<"=               Nhap 6: Thoat chuong trinh.              ="<<endl; gotoxy(11,12);
	cout<<"=========================================================="<<endl; gotoxy(11,13);
	cout<<"Nhap lua chon: ";
	while (1)
	{
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1)
		{
			int n,i=0;
			cout<<"\nNhap so luong nhan vien:";
			cin>>n;
			for(int j=0;j<n;j++)
			{
				cout<<"Nhan vien thu "<<++i<<":"<<endl;
				Node3*p3=TaoNode3();
				addLast(sl,p3);
			}
		}
		if(luachon==2)
		{
			XuatDSNV(sl);
		}
		if(luachon==3)
		{
			searchbyName(sl);
		}
		if(luachon==4)
		{
			wpay(sl);
		}
		if(luachon==5)
		{
			system("cls");
			menuChung();
		}
		if(luachon==6)
		{
			exit(0);
		}
	}
}
int main()
{
	system("color f0");
	menuChung();   
}
