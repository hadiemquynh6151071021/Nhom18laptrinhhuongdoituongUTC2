#include<iostream>
#include<iomanip>				//thu vien de co the in ra tien trieu
#include<string>				//thu vien de so sanh hai chuoi
#include<windows.h>				//thu vien de tao am thanh, di chuyen con tro
#include<unistd.h>				// chay sleep
#include <stdio.h>
using namespace std;

void menu1();
void menu2();
struct SList1;
struct SList3;

void gotoxy(int x, int y)  {		//ham di chuyen con tro
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

struct Date {						//struct ngay thang nam
	int date, month, year;
};

void NhapDate(Date &d) {			//ham nhap ngay
	cout << "\n\t\t-Ngay:";
	cin >> d.date;
	cout <<"\t\t-Thang:";
	cin >> d.month;
	cout <<"\t\t-Nam:";
	cin >> d.year;
}
void XuatDate(Date d) {
	cout << "\t\t\t" << d.date << "/" << d.month << "/" << d.year <<endl;
}
//TODO: CLASS NGUOI
class Nguoi {
	private:
		string SDT,Diachi;
		Date NgaySinh;
	public:
		Date getns() {							//ham lay ngay sinh
			Date t;
			t.date=NgaySinh.date;
			t.month=NgaySinh.month;
			return t;
		}
		void Nhapthongtin() {					//ham nhap 1 nguoi
			
			cout << "\tNhap ngay sinh: ";
			NhapDate(NgaySinh);
			fflush(stdin);
			cout <<"\tNhap SDT: " ;
			getline(cin,SDT);
			cout <<"\tNhap dia chi: ";
			getline(cin,Diachi);
		}
		void Xuatthongtin() {					//ham xuat 1 nguoi
			XuatDate(NgaySinh);
			cout << "\t\t\tSo dien thoai: " << SDT << endl ;
			cout << "\t\t\tDia chi: " << Diachi <<endl;
		}
		friend void GhiFileKhachHang(SList1 l);
		friend void GhiFileNhanVien(SList3 sl);
		virtual float GiaTien()=0;				//ham thuan ao tinh tien	
};

//TODO: CLASS KHACH HANG
class KhachHang: private Nguoi {
	private:
		int SoLuong;
		string MKH, MatHang[20];
		Date NgayMua;
	public:		
		string getMKH();
		Date getnm();
		void NhapKhachHang(KhachHang &k);
		friend ostream & operator << (ostream &os, KhachHang &k );
		friend void GhiFileKhachHang(SList1 l);
		float GiaTien();
};

string KhachHang::getMKH() {					//ham lay mkh
	return MKH;
}

Date KhachHang::getnm() {						//ham lay ngay mua
	Date t;
	t.date=NgayMua.date;
	t.month=NgayMua.month;
	return t;
}

void KhachHang::NhapKhachHang(KhachHang &k) {			//nhap 1 khach hang ghi vao file
		fflush(stdin);
		cout << endl << "\tNhap ma khach hang: " ;
		getline(cin,k.MKH);
		k.Nhapthongtin();
		cout << "\tNhap ngay mua: " ;
		NhapDate(NgayMua);
		fflush(stdin);
		cout << "\tNhap so luong: " ;
		cin >> k.SoLuong ;
		for (int i=1;i<=k.SoLuong;i++) {				// mat hang la kieu mang do 1 nguoi co the mua nhieu mon
			fflush(stdin);
			cout << "\t\tNhap mat hang " << i <<":";
			getline(cin,k.MatHang[i]);
		}
}

ostream & operator << (ostream &os, KhachHang &k ) {		//nap chong toan tu xuat 1 kh
	os << endl << "\t\t\tMa khach hang: " << k.MKH << endl;
	k.Xuatthongtin();
	XuatDate(k.NgayMua);
	os << "\t\t\tSo luong: " << k.SoLuong << endl ;
	for (int i=1; i <= k.SoLuong; i++) {
			os << "\t\t\t\tTen mon " << i << ":" << k.MatHang[i] << endl;
	}
	return os;
}

int SoSanh(Date a,Date b) {								//so sanh ngay sinh va ngay mua
	if(a.date==b.date && a.month==b.month)
		return 1;
	return 0;
}

float KhachHang::GiaTien() {							//ham tinh tien 1 kh
	string x1 = "Cafe den", x2 = "Cold brew", x3 = "Bac siu",x4 = "Cafe sua", x5 = "Cappuccino",x6 = "Americano", x7 = "Tra matcha";
	string x8 = "Tra vai", x9 = "Tra hat sen", x10 = "Hong tra latte", x11 = "Tra dao cam sa", x12 = "Tra sua mac ca", x13 = "Tra viet quoc", x14 = "Tra sua oolong";
	float *Gia = new float[SoLuong];				// cap phat bo nho dong cho mang gia
	float Tong = 0;
	for ( int i=1; i <= SoLuong; i++) {
		if (MatHang[i].compare(x1) == 0 || MatHang[i].compare(x2) == 0)	{		//trong c++ de so sanh hai chuoi ta dung compare
			Gia[i] = 35000;
		}
		else if (MatHang[i].compare(x3) == 0 || MatHang[i].compare(x4) == 0) {
			Gia[i] = 38000;
		}
		else if (MatHang[i].compare(x5) == 0 || MatHang[i].compare(x6) == 0) {
			Gia[i] = 40000;
		}
		else if (MatHang[i].compare(x7) == 0 || MatHang[i].compare(x8) == 0) {
			Gia[i] = 55000;
		}
		else if (MatHang[i].compare(x9) == 0 || MatHang[i].compare(x10) == 0) {
			Gia[i] = 50000;
		}
		else if (MatHang[i].compare(x11) == 0 || MatHang[i].compare(x12) == 0) {
			Gia[i] = 59000;
		}
		else {
			Gia[i] = 60000;
		}
	}
	for (int i=0; i <= SoLuong; i++) {				//cau lenh tinh tong trong truong hop 1 nguoi mua 2 mat hang khac nhau
			Tong += Gia[i];	
	}
	if (SoSanh(getns(),getnm())) {
		cout << "\t\t\tUu dai 15% nhan dip sinh nhat";
		return Tong-((Tong*15)/100);
	}
	else {
		return Tong;
	}
	delete [] Gia;
}

struct Node  {							//struct node khach hang
	KhachHang data;
	Node *next;
};

struct SList1 {							//struct danh sach khach hang
	Node *head;
	Node *tail;
	long size;
};

void SList1rong (SList1 &l)  {			//ham tao danh sach rong
	l.head = NULL;
	l.tail = NULL;
	l.size = 0;
}

Node* Taonode1() {						//ham tao mot node
	KhachHang v;
	Node* p = new Node;
	v.NhapKhachHang(v);
	p->data = v ;	
	p->next = NULL;	
	return p;
}

void Themcuoi1 (SList1 &l, Node *p) {		//ham them mot node vao cuoi danh sach
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

void SuaDoi1(SList1 l)						//ham chinh sua 1 khach hang trong danh sach
{	
	Node *p=l.head;
	if(p == NULL)
	{
		cout << "\n\t\t\t\t\7Danh sach rong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
	}
	if(p != NULL)
	{
		string m;
		cout<<"Nhap ma khach hang can sua doi: ";
		fflush(stdin);
		getline(cin,m);
		int dem = 0;
		while(p != NULL)
		{
			if(p->data.getMKH() == m)
			{
				Beep(523,500); 			 //lenh tao am thanh
	    		cin.get(); 
				p->data.NhapKhachHang(p->data);
				dem++;
			}
			p=p->next;
		}
		if(dem == 0)
		{
			cout << "\n\t\t\t\7Khong co khach hang trong danh sach";
			cout << "\n\t\t\tNHAN PHIM 2 DE TIM LAI.";
		}
	}
}

void XuatDSKH (SList1 l)  {				//ham xuat mot danh sach
	Node* p = l.head;
	if(p == NULL) {
		cout << "\n\t\t\t\t\7Danh sach rong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";	
	}
	if(p != NULL) {
		int i=0;
		cout << endl << "\t\t\t\tDANH SACH KHACH HANG:";
		while (p != NULL) {
			cout << endl << "\t\t\t--------------------------------\n";
			cout << "\n\t\t\t\tKHACH HANG THU " << i+1 << endl;
			cout << (p->data);
			i++;
			p = p->next;
		}
		cout << endl;
		Beep(523,500);  
	    cin.get();
	} 
	delete p;
}

void Hoadon (SList1 &l) {				//ham in hoa don 1 kh dua vao tim kiem mkh
	string x;
	fflush(stdin);
	cout << "Ma khach hang can tim:";
	getline(cin,x);
	Node* p = l.head;
	if(p==NULL) {
		cout << "\n\t\t\t\7Danh sach dang trong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		int dem=0;
		while (p != NULL) {	
			if(x.compare(p->data.getMKH())==0) {
				Beep(523,500);  
	    		cin.get(); 
				cout << p->data;
				cout << "\n\t\t\tGia Tien thanh toan: " << p->data.GiaTien();
				dem++;
			}
			p = p->next;
		}
		if(dem==0) {
			cout << "\n\t\t\t\7Khong co khach hang trong danh sach";
			cout << "\n\t\t\tNHAN PHIM 3 DE TIM LAI.";
		}
	}
}

void GhiFileKhachHang(SList1 l) {					//ghi danh sach vao tep
	FILE *file = fopen("KhachHang.txt","w");
	Node *p=l.head; 
	while(p != NULL) {
		fprintf(file,"\n%5s %2d/%2d/%4d",p->data.MKH.c_str(),p->data.NgaySinh.date,p->data.NgaySinh.month,p->data.NgaySinh.year);
		fprintf(file,"%10s %15s %2d/%2d/%4d\n%2d: ",p->data.SDT.c_str(),p->data.Diachi.c_str(),p->data.NgayMua.date,p->data.NgayMua.month,p->data.NgayMua.year,p->data.SoLuong);
		for(int i=1;i<=p->data.SoLuong;i++) {
			fprintf(file,"%15s",p->data.MatHang[i].c_str());
		}
		p = p->next;
	}
	fclose(file);
}
//TODO: CLASS NGUYEN LIEU

//TODO: NHANVIEN
class NhanVien:private Nguoi {
	private:
		string name,loainhanvien;
        int soluonggio;
    public:
     	void NhapNhanVien(NhanVien &n);
		friend ostream & operator << (ostream &os, NhanVien & n);
		friend void GhiFileNhanVien(SList3 sl);
        float GiaTien();
        string getname();

};

string NhanVien::getname() {			//ham lay ten nhan vien
    return name;
}

float NhanVien::GiaTien() {				//ham tinh luong 1 nhan vien
    float ftienluong = 1;
    string a = "Full time";
    string b = "Part time";
    if(loainhanvien.compare(a) == 0) {
        ftienluong = ( 27000*soluonggio*7);
       
    }
    else if(loainhanvien.compare(b) == 0) {
        ftienluong = (17000*soluonggio*7);
    }
    return ftienluong;    
}

void NhanVien::NhapNhanVien( NhanVien &n) {			//nhap 1 nhan vien ghi vao file
    fflush(stdin);
    cout << "\tNhap no va ten :";
    getline(cin,n.name);
    n.Nhapthongtin();
    cout << "\tNhap loai nhan vien:";
    getline(cin,n.loainhanvien);
    cout << "\tNhap so luong gio:";
    cin >> n.soluonggio;
}

ostream& operator << (ostream &os, NhanVien & n) {		//nap chong toan tu xuat 1 nhan vien
    cout<<"\t\t\tHo va ten :"<<n.name<<endl;
    n.Xuatthongtin();
    cout<<"\t\t\tLoai nhan vien :"<<n.loainhanvien<<endl;
    cout<<"\t\t\tSo luong gio:"<<n.soluonggio<<endl;
    return os;
}

struct Node3 {				//struct node nhan vien
    NhanVien data3;
    Node3* next3;
};

struct SList3 {				//struct danh sach nhan vien
    Node3* head3;
    Node3* tail3;
    long size3;
};

void SList3rong(SList3 &sl) {		//ham tao danh sach nhan vien rong
    sl.head3 = NULL;
    sl.tail3 = NULL;
    sl.size3 = 0;
}

Node3* TaoNode3() {					//tao node nhan vien
	NhanVien v;
    Node3 *p3 = new Node3 ;
	v.NhapNhanVien(v);
    p3->data3 = v;
    p3->next3= NULL;
    return p3;
}

void addLast(SList3 &sl , Node3 *p3) {   		//ham them nhan vien vao danh sach
    if(sl.size3 == 0) {
       sl. head3 = p3 ;
       sl. tail3 = p3;
    }
    else {
        sl.tail3 ->next3 = p3;
        sl.tail3 = p3 ;
    }
    sl.size3 =sl.size3+1;
}

void searchbyName(SList3 sl) {					//ham tim kiem nhan vien theo ten
    string fname;
	fflush(stdin);
    cout<<"Ten nhan vien muon tim :";
    getline(cin,fname);
    Node3*p3 = sl.head3;
    if(p3 == NULL) {
    	cout << "\n\t\t\t\7Danh sach dang trong.";
    	cout << "\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		int dem=0;
	    while ( p3!= NULL) {
		    if(fname == p3->data3.getname()) {
				Beep(523,500);  
	    		cin.get();	
		        cout<<(p3->data3);
		        dem++;
		  	}
		    p3 = p3-> next3;    
	    }
	    if (dem==0) {
	    	cout<<"\n\t\t\t\7Khong tim thay nhan vien.";
	    	cout<<"\n\t\t\tNHAN PHIM 3 DE TIM LAI.";
	    }
	}
}

void MaxLuong(SList3 sl) {				//ham tim nhan vien luong cao nhat
	
	Node3* p3 = sl.head3;
	NhanVien max = p3->data3;
	Node3* q3 = p3->next3;
	if(p3==NULL) {
    	cout<<"\n\t\t\t\7Danh sach dang trong.";
    	cout<<"\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		int dem=0;
		while(q3 != NULL) {
			if(max.GiaTien() < q3->data3.GiaTien()) {
				max = q3->data3;
				dem++;
				Beep(523,500);
	    		cin.get();
				cout<< "\nNhan vien co luong cao nhat la: "<<endl;
				cout << max;
			}
			q3 = q3->next3;
		}
		if(dem == 0) {
			cout<<"\n\t\t\t\7Khong tim thay nhan vien.";
			cout<<"\n\t\t\tNHAN PHIM 5 DE TIM LAI.";
		}	
	}	
}

void SuaDoi2(SList3 sl)				//ham chinh sua 1 nhan vien trong danh sach
{	
	Node3 *p3=sl.head3;
	if(p3 == NULL)
	{
		cout << "\n\t\t\t\t\7Danh sach rong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
	}
	if(p3 != NULL)
	{
		string m;
		cout<<"Nhap ten nhan vien can sua doi: ";
		fflush(stdin);
		getline(cin,m);
		int dem = 0;
		while(p3 != NULL)
		{
			if(p3->data3.getname() == m)
			{
				Beep(523,500);
	    		cin.get(); 
				p3->data3.NhapNhanVien(p3->data3);
				dem++;
			}
			p3 = p3->next3;
		}
		if(dem == 0)
		{
			cout << "\n\t\t\t\7Khong nhan vien trong danh sach";
			cout << "\n\t\t\tNHAN PHIM 2 DE TIM LAI.";
		}
	}
}

void XuatDSNV(SList3 sl) {				//ham xuat danh sach nhan vien
	Node3* p3 = sl.head3;
	if(p3==NULL) {
		cout<<"\n\t\t\tDanh sach rong.";
		cout<<"\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
		cout<<"\7";
	}
	if(p3 != NULL) {
		int i=0;
		cout<<endl<<"\t\t\t\tDANH SACH NHAN VIEN:";
		while (p3 != NULL) {
			cout<<endl<<"\t\t\t--------------------------------\n";
			cout<<"\n\t\t\t\tNHAN VIEN THU "<<i+1<<endl;
			cout<<(p3->data3);
			i++;
			p3 = p3->next3;
		}
		Beep(523,500);
	    cin.get(); 
		cout << endl;
	}
	delete p3;
}

void GhiFileNhanVien(SList3 sl) {			//ghi file nhan vien
	FILE *file = fopen("NhanVien.txt","w");
	Node3 *p3=sl.head3; 
	while(p3 != NULL) {
		fprintf(file,"\n%30s %2d/%2d/%4d",p3->data3.name.c_str(),p3->data3.NgaySinh.date,p3->data3.NgaySinh.month,p3->data3.NgaySinh.year);
		fprintf(file,"%10s %15s %15s%!d",p3->data3.SDT.c_str(),p3->data3.Diachi.c_str(),p3->data3.loainhanvien.c_str(),p3->data3.soluonggio);
		p3 = p3->next3;
	}
	fclose(file);
}

void wpay (SList3 sl) {					//ham dua ra luong nhan vien trong danh sach dua theo ten
    string x;
    int dem=0;
    fflush (stdin);
    cout<<"\t\t\tNhap ten nhan vien :";
    getline(cin,x);
    Node3*p3 = sl.head3;
    while (p3 != NULL) {
        if(x.compare(p3->data3.getname())==0) {    
            cout<< std::setprecision(20);
            cout<<p3->data3;
            p3->data3.GiaTien();
            dem++;
        }
		p3=p3->next3;
    }
    if(dem==0) {
			cout<<"\n\t\t\tKhong tim thay nhan vien.";
			cout<<"\n\t\t\tNHAN PHIM 4 DE TIM LAI.";
	}
    Beep(523,500);
    cin.get(); 
}

//ham tao tieu de
void TieuDe() {
	gotoxy(10,5);
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"; gotoxy(10,6);
	cout<<"@                                                          @"; gotoxy(10,7);
	cout<<"@                                                          @"; gotoxy(10,8);
	cout<<"@          **     **  *****  **   **  **  **               @"; gotoxy(10,9);
	cout<<"@          ** * * **  **     ** * **  **  **               @"; gotoxy(10,10);
	cout<<"@          **  *  **  *****  **  ***  **  **               @"; gotoxy(10,11);
	cout<<"@          **     **  **     **   **  **  **               @"; gotoxy(10,12);
	cout<<"@          **     **  *****  **   **   ****                @"; gotoxy(10,13);
	cout<<"@                                                          @"; gotoxy(10,14);
	cout<<"@                                                          @"; gotoxy(10,15);
	cout<<"@   Cafe den      :  35K           Cold brew     :   35K   @"; gotoxy(10,16);
	cout<<"@   Bac siu       :  38K           Cafe sua      :   38K   @"; gotoxy(10,17);
	cout<<"@   Cappuccino    :  40K           Americano     :   40K   @"; gotoxy(10,18);
	cout<<"@   Tra matcha    :  55K           Tra vai       :   55K   @"; gotoxy(10,19);
	cout<<"@   Tra hat sen   :  50K           Hong tra latte:   50K   @"; gotoxy(10,20);
	cout<<"@   Tra dao cam sa:  59K           Tra sua mac ca:   59K   @"; gotoxy(10,21);
	cout<<"@   Tra viet quoc :  60K           Tra sua oolong:   60K   @"; gotoxy(10,22);
	cout<<"@                                                          @"; gotoxy(10,23);
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl<<endl;
}

void menuChung() {
	system("cls");
	int n;
	gotoxy(1,5);
	cout<<"..............................................................................";	gotoxy(1,6);
	cout<<".%%%%%..%%%%%..%%%%%..%%%%..%%...%%......%%%%...%%%%..%%%%%.%%%%%.%%%%%.%%%%%.";	gotoxy(1,7);
	cout<<".%%..%%.%%..%%.%%....%%..%%.%%%.%%%.....%%..%%.%%..%%.%%....%%....%%....%%....";	gotoxy(1,8);
	cout<<".%%..%%.%%%%%..%%%%..%%%%%%.%%.%.%%.....%%.....%%..%%.%%%%..%%%%..%%%%..%%%%..";	gotoxy(1,9);
	cout<<".%%..%%.%%..%%.%%....%%..%%.%%...%%.....%%..%%.%%..%%.%%....%%....%%....%%....";	gotoxy(1,10);
	cout<<".%%%%%..%%..%%.%%%%%.%%..%%.%%...%%......%%%%...%%%%..%%....%%....%%%%%.%%%%%.";	gotoxy(1,11);
	cout<<"..............................................................................";	gotoxy(1,12);
	gotoxy(35.5,15);
	cout<<"NHAN PHIM";
	gotoxy(35.5,16);
	cout<<"1.Khach hang.";
	gotoxy(35.5,17);
	cout<<"2.Nhan vien.";
	cout<<"\nNhap doi tuong muon xu ly:";
	cin>>n;
	if(n==1) {
		system("cls");
		menu1();
	}
	else if(n==2) {
		system("cls");
		menu2();
	}
	else {
		cout<<"\n\t\t\tMOI BAN NHAN LAI:";
		sleep(5); 			//keo dai time hien thi dong chu
		menuChung();
	}
}

void menu1() {
	system("cls");
	int luachon;
	SList1 l;
	SList1rong(l);
	TieuDe();
    gotoxy(11,29);
	cout<<"=========================================================="; gotoxy(11,30);
	cout<<"=               Nhap 1: Nhap DS khach hang.              ="; gotoxy(11,31);
	cout<<"=               Nhap 2: Chinh sua khach hang.            ="; gotoxy(11,32);
	cout<<"=               Nhap 3: Xuat DS khach hang.              ="; gotoxy(11,33);
	cout<<"=               Nhap 4: Ghi file khach hang.             ="; gotoxy(11,34);
	cout<<"=               Nhap 5: Hoa don cua 1 khach.             ="; gotoxy(11,34);
	cout<<"=               Nhap 6: Tro ve menu chinh.               ="; gotoxy(11,35);
	cout<<"=               Nhap 7: Thoat chuong trinh.              ="; gotoxy(11,36);
	cout<<"=========================================================="; gotoxy(11,37);
	fflush(stdin);
	cout<<"Nhap lua chon: ";
	while (1) {
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1) {
			int n,i=0;
			cout<<"Nhap so luong khach hang:";
			cin>>n;
			for(int j=0;j<n;j++) {
				cout<<"\t\tKHACH HANG THU "<<++i<<":"<<endl;
				Node *p=Taonode1();
				Themcuoi1(l,p);
			}
		}
		else if(luachon==2) {
			SuaDoi1(l);
		}
		else if(luachon==3) {
			XuatDSKH(l);
		}
		else if(luachon==4) {
			Hoadon(l);
		}
		else if(luachon==5) {
			system("cls");
			menuChung();
		}
		else if(luachon==6) {
			exit(0);
		}
		else {
			cout<<"\n\t\tLua chon khong hop le.Vui long chon lai!";
		}
	}
}

void menu2() {
	system("cls");
	int luachon;
	SList3 sl;
	SList3rong(sl);
	TieuDe();
    gotoxy(11,29);
	cout<<"=========================================================="; gotoxy(11,30);
	cout<<"=               Nhap 1: Nhap DS nhan vien.               ="; gotoxy(11,31);
	cout<<"=               Nhap 2: Chinh sua nhan vien.             ="; gotoxy(11,32);
	cout<<"=               Nhap 3: Xuat DS nhan vien.               ="; gotoxy(11,33);
	cout<<"=               Nhap 4: Ghi file nhan vien.              ="; gotoxy(11,33);
	cout<<"=               Nhap 5: Tim kiem nhan vien.              ="; gotoxy(11,34);
	cout<<"=               Nhap 6: Xuat luong nhan vien.            ="; gotoxy(11,35);
	cout<<"=               Nhap 7: Luong nhan vien cao nhat.        ="; gotoxy(11,36);
	cout<<"=               Nhap 8: Tro ve menu chinh.               ="; gotoxy(11,37);
	cout<<"=               Nhap 9: Thoat chuong trinh.              ="; gotoxy(11,38);
	cout<<"=========================================================="; gotoxy(11,39);
	cout<<"Nhap lua chon: ";
	while (1) {
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1) {
			int n,i=0;
			cout<<"Nhap so luong nhan vien:";
			cin>>n;
			for(int j=0;j<n;j++) {
				cout<<"NHAN VIEN THU "<<++i<<":"<<endl;
				Node3*p3=TaoNode3();
				addLast(sl,p3);
			}
		}
		else if(luachon==2) {
			SuaDoi2(sl);
		}
		else if(luachon==3) {
			XuatDSNV(sl);
		}
		else if(luachon==4) {
			GhiFileNhanVien(sl);
		}
		else if(luachon==5) {
			searchbyName(sl);
		}
		else if(luachon==6) {
			wpay(sl);
		}
		else if(luachon==7) {
			MaxLuong(sl);
		}
		else if(luachon==8) {
			system("cls");
			menuChung();
		}
		else if(luachon==9) {
			exit(0);
		}
		else {
			cout<<"\n\t\tLua chon khong hop le. Vui long chon lai!";
		}
	}
}

int main() {
	system("color f0"); //thiet lap mau nen va mau chu
	menuChung();   
}
