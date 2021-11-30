#include<iostream>
#include<iomanip>				//thu vien de co the in ra tien trieu
#include<string>				//thu vien de so sanh hai chuoi
#include<windows.h>				//thu vien de tao am thanh, di chuyen con tro
#include<unistd.h>				// chay sleep
#include <stdio.h>
using namespace std;

void menu1();
void menu2();
void menu3();
struct SList1;
struct SList2;
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
	cout << d.date << "/" << d.month << "/" << d.year <<endl;
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
			
			cout << "\n\tNhap ngay sinh: ";
			NhapDate(NgaySinh);
			fflush(stdin);
			cout <<"\tNhap SDT: " ;
			getline(cin,SDT);
			cout <<"\tNhap dia chi: ";
			getline(cin,Diachi);
		}
		void Xuatthongtin() {					//ham xuat 1 nguoi
			cout << "\n\t\t\tNgay Sinh: ";
			XuatDate(NgaySinh);
			cout << "\t\t\tSo dien thoai: " << SDT << endl ;
			cout << "\t\t\tDia chi: " << Diachi <<endl;
		}
		friend void GhiFileKhachHang(SList1 l);
		friend void GhiFileNhanVien(SList2 sl);
		friend void GhiFileNguyenLieu(SList3 l);
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
		friend istream & operator >> (istream &is, KhachHang &k );
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

istream & operator >> (istream &is, KhachHang &k ) {			//nhap 1 khach hang ghi vao file
	fflush(stdin);
	k.Nhapthongtin();
	cout << "\tNhap ngay mua: " ;
	NhapDate(k.NgayMua);
	fflush(stdin);
	cout << "\tNhap so luong: " ;
	is >> k.SoLuong ;
	for (int i=1;i<=k.SoLuong;i++) {				// mat hang la kieu mang do 1 nguoi co the mua nhieu mon
		fflush(stdin);
		cout << "\t\tNhap mat hang " << i <<":";
		getline(is,k.MatHang[i]);
	}
	return is;
}

ostream & operator << (ostream &os, KhachHang &k ) {	//nap chong toan tu xuat 1 kh
	k.Xuatthongtin();
	cout << "\t\t\tNgay mua: ";
	XuatDate(k.NgayMua);
	os << "\t\t\tSo luong: " << k.SoLuong << endl ;
	for (int i=1; i <= k.SoLuong; i++) {
			os << "\t\t\tTen mon " << i << ":" << k.MatHang[i] << endl;
	}
	return os;
}

int SoSanh(Date a,Date b) {							//so sanh ngay sinh va ngay mua
	if(a.date==b.date && a.month==b.month)
		return 1;
	return 0;
}

int SS(Date d1,Date d2){
	if(d1.date==d2.date && d1.month==d2.month && d1.year==d2.year){
		return 1;
	}
	else return 0;
}

float KhachHang::GiaTien() {						//ham tinh tien 1 kh
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
	cin >> v;
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
				cin >> p->data;
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
				cout << "\t\t\tGia Tien thanh toan: " << p->data.GiaTien() << "d";
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
	int i=1;
	FILE *file = fopen("KhachHang.txt","w");
	Node *p=l.head; 
	fprintf(file,"\t\t\t\t\t=====================================\n");
	fprintf(file,"\t\t\t\t\t=        DANH SACH KHACH HANG       =\n");
	fprintf(file,"\t\t\t\t\t=====================================\n\n\n");
	while(p != NULL) {
		fprintf(file,"\n\n");
		fprintf(file,"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fprintf(file,"\t\t\t\t~                 KHACH HANG THU: %2d                 ~\n",i);
		fprintf(file,"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fprintf(file,"\t\t\t\t             Ma khach hang: %2d\n",i);
		fprintf(file,"\t\t\t\t             Ngay sinh: %2d/%2d/%4d\n",p->data.NgaySinh.date,p->data.NgaySinh.month,p->data.NgaySinh.year);
		fprintf(file,"\t\t\t\t             SDT: %s\n",p->data.SDT.c_str());
		fprintf(file,"\t\t\t\t             Ngay mua: %2d/%2d/%4d\n",p->data.NgayMua.date,p->data.NgayMua.month,p->data.NgayMua.year);
		fprintf(file,"\t\t\t\t             So luong: %d\n",p->data.SoLuong);
		for(int j=1;j<=p->data.SoLuong;j++) {
			fprintf(file,"\t\t\t\t\t\t%15s\n",p->data.MatHang[j].c_str());
		}
		i++;
		p = p->next;
	}
	fclose(file);
	cout << "\n\t\t\tGHI FILE KHACH HANG THANH CONG!!!";
}
//TODO: NHANVIEN
class NhanVien:private Nguoi {
	private:
		string name,loainhanvien;
        int soluonggio;
    public:
     	friend istream & operator >> (istream &is, NhanVien & n);
		friend ostream & operator << (ostream &os, NhanVien & n);
		friend void GhiFileNhanVien(SList2 sl);
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

istream & operator >> (istream &is, NhanVien & n){			//nhap 1 nhan vien ghi vao file
    fflush(stdin);
    cout << "\tNhap ho va ten :";
    getline(is,n.name);
    n.Nhapthongtin();
    cout << "\tNhap loai nhan vien:";
    getline(is,n.loainhanvien);
    cout << "\tNhap so luong gio:";
    is >> n.soluonggio;
    return is;
}

ostream& operator << (ostream &os, NhanVien & n) {		//nap chong toan tu xuat 1 nhan vien
    os<<"\t\t\tHo va ten :"<<n.name;
    n.Xuatthongtin();
    os<<"\t\t\tLoai nhan vien :"<<n.loainhanvien<<endl;
    os<<"\t\t\tSo luong gio:"<<n.soluonggio<<endl;
    return os;
}

struct Node2 {				//struct node nhan vien
    NhanVien data2;
    Node2* next2;
};

struct SList2 {				//struct danh sach nhan vien
    Node2* head2;
    Node2* tail2;
    long size2;
};

void SList2rong(SList2 &sl) {		//ham tao danh sach nhan vien rong
    sl.head2 = NULL;
    sl.tail2 = NULL;
    sl.size2 = 0;
}

Node2* TaoNode2() {					//tao node nhan vien
	NhanVien v;
    Node2 *p2 = new Node2 ;
	cin >> v;
    p2->data2 = v;
    p2->next2= NULL;
    return p2;
}

void addLast(SList2 &sl , Node2 *p2) {   		//ham them nhan vien vao danh sach
    if(sl.size2 == 0) {
       sl. head2 = p2 ;
       sl. tail2 = p2;
    }
    else {
        sl.tail2 ->next2 = p2;
        sl.tail2 = p2 ;
    }
    sl.size2 =sl.size2+1;
}

void searchbyName(SList2 sl) {					//ham tim kiem nhan vien theo ten
    string fname;
	fflush(stdin);
    cout<<"Ten nhan vien muon tim :";
    getline(cin,fname);
    Node2*p2 = sl.head2;
    if(p2 == NULL) {
    	cout << "\n\t\t\t\7Danh sach dang trong.";
    	cout << "\n\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		int dem=0;
	    while ( p2!= NULL) {
		    if(fname == p2->data2.getname()) {
				Beep(523,500);  
	    		cin.get();	
		        cout<<(p2->data2);
		        dem++;
		  	}
		    p2 = p2-> next2;    
	    }
	    if (dem==0) {
	    	cout<<"\n\t\t\t\7Khong tim thay nhan vien.";
	    	cout<<"\n\t\t\tNHAN PHIM 5 DE TIM LAI.";
	    }
	}
}

void MaxLuong(SList2 sl) {				//ham tim nhan vien luong cao nhat
	
	Node2* p2 = sl.head2;
	if(p2==NULL)
    {
    	cout<<"\n\t\t\t\7Danh sach dang trong.";
    	cout<<"\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		NhanVien max = p2->data2;
		Node2* q2 = p2->next2;
		while(q2 != NULL) {
			if(max.GiaTien() < q2->data2.GiaTien()) {
				max = q2->data2;
			}
			q2 = q2->next2;
		}
		Beep(523,500);
	    cin.get();
		cout << "\nNhan vien co luong cao nhat la: "<<endl;
		cout << max;
		cout<< std::setprecision(20);
		cout<<"\t\t\tLuong: "<<max.GiaTien() <<"d";		
	}	
}

void SuaDoi2(SList2 sl)				//ham chinh sua 1 nhan vien trong danh sach
{	
	Node2 *p2=sl.head2;
	if(p2 == NULL)
	{
		cout << "\n\t\t\t\t\7Danh sach rong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
	}
	if(p2 != NULL)
	{
		string m;
		cout<<"Nhap ten nhan vien can sua doi: ";
		fflush(stdin);
		getline(cin,m);
		int dem = 0;
		while(p2 != NULL)
		{
			if(p2->data2.getname() == m)
			{
				Beep(523,500);
	    		cin.get(); 
				cin >> p2->data2;
				dem++;
			}
			p2 = p2->next2;
		}
		if(dem == 0)
		{
			cout << "\n\t\t\t\7Khong nhan vien trong danh sach";
			cout << "\n\t\t\tNHAN PHIM 2 DE TIM LAI.";
		}
	}
}

void XuatDSNV(SList2 sl) {				//ham xuat danh sach nhan vien
	Node2* p2 = sl.head2;
	if(p2==NULL) {
		cout<<"\n\t\t\tDanh sach rong.";
		cout<<"\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
		cout<<"\7";
	}
	if(p2 != NULL) {
		int i=0;
		cout<<endl<<"\t\t\t\tDANH SACH NHAN VIEN:";
		while (p2 != NULL) {
			cout<<endl<<"\t\t\t--------------------------------\n";
			cout<<"\n\t\t\t\tNHAN VIEN THU "<<i+1<<endl;
			cout<<(p2->data2);
			i++;
			p2 = p2->next2;
		}
		Beep(523,500);
	    cin.get(); 
		cout << endl;
	}
	delete p2;
}

void GhiFileNhanVien(SList2 sl) {			//ghi file nhan vien
	int i=1;
	FILE *file = fopen("NhanVien.txt","w");
	Node2 *p2=sl.head2; 
	fprintf(file,"\t\t\t\t\t=====================================\n");
	fprintf(file,"\t\t\t\t\t=        DANH SACH NHAN VIEN        =\n");
	fprintf(file,"\t\t\t\t\t=====================================\n\n\n");
	while(p2 != NULL) {
		fprintf(file,"\n\n");
		fprintf(file,"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fprintf(file,"\t\t\t\t~               NHAN VIEN THU: %2d                    ~\n",i);
		fprintf(file,"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fprintf(file,"\t\t\t\t          Ho va ten: %s\n",p2->data2.name.c_str());
		fprintf(file,"\t\t\t\t          Ngay sinh: %2d/%2d/%4d\n",p2->data2.NgaySinh.date,p2->data2.NgaySinh.month,p2->data2.NgaySinh.year);
		fprintf(file,"\t\t\t\t          SDT: %s\n",p2->data2.SDT.c_str());
		fprintf(file,"\t\t\t\t          Dia chi: %15s\n",p2->data2.Diachi.c_str());
		fprintf(file,"\t\t\t\t          Loai nhan vien: %15s\n",p2->data2.loainhanvien.c_str());
		fprintf(file,"\t\t\t\t          Gio lam: %1d\n",p2->data2.soluonggio);
		p2 = p2->next2;
		i++;
	}
	fclose(file);
	cout << "\n\t\t\tGHI FILE NHAN VIEN THANH CONG!!!";
}

void wpay (SList2 sl) {					//ham dua ra luong nhan vien trong danh sach dua theo ten
    string x;
    int dem=0;
    fflush (stdin);
    cout<<"Nhap ten nhan vien can tim :";
    getline(cin,x);
    Node2 *p2 = sl.head2;
    while (p2 != NULL) {
        if(x.compare(p2->data2.getname())==0) {    
            cout<< std::setprecision(20);
            cout<<p2->data2;
            cout<<"\t\t\tLuong: "<<p2->data2.GiaTien() <<"d";
            dem++;
        }
		p2=p2->next2;
    }
    if(dem==0) {
			cout<<"\n\t\t\tKhong tim thay nhan vien.";
			cout<<"\n\t\t\tNHAN PHIM 4 DE TIM LAI.";
	}
    Beep(523,500);
    cin.get(); 
}
//TODO:CLASS NGUYEN LIEU
class NguyenLieu {
    private: 
    	Date d;
        float Coffee,Tra,Sua,Da,LyDung;
    public:
    	NguyenLieu()
    	{
    		d.date=d.month=d.year=0;
    		Coffee=Tra=Sua=Da=LyDung=0;
    	}
    	Date getdate(){
    		return d;
		}
        friend istream &operator >> ( istream &in, NguyenLieu &nl);
        friend ostream &operator << ( ostream &fileout, NguyenLieu nl);
        float GiaMotNgay();    
		friend void GhiFileNguyenLieu(SList3 l);  
};
istream &operator >> ( istream &in, NguyenLieu &nl){
    NhapDate(nl.d);
    cout<<"\t\tNhap so luong nguyen lieu: "<<endl;
    cout<<"\tCoffee: ";
    in>>nl.Coffee;
    cout<<"\tTra: ";
    in>>nl.Tra;
    cout<<"\tSua: ";
    in>>nl.Sua;
    cout<<"\tDa: ";
    in>>nl.Da;
    cout<<"\tLy dung: ";
    in>>nl.LyDung;
    return in;
}
ostream &operator << ( ostream &out, NguyenLieu nl){
    out<<"\t\t\tDate:";
    XuatDate(nl.d);
    out<<"\t\t\tSo luong nguyen lieu da dung: "<<endl;
    out<<"\t\t\tCoffee: "<<nl.Coffee<<endl;
    out<<"\t\t\tTra: "<<nl.Tra<<endl;
    out<<"\t\t\tSua: "<<nl.Sua<<endl;
    out<<"\t\t\tDa: "<<nl.Da<<endl;
    out<<"\t\t\tLy dung: "<<nl.LyDung<<endl;
    return out;
}
float NguyenLieu::GiaMotNgay() {
    float GiaNguyenLieu;
    GiaNguyenLieu=80000*Coffee + 30000*Tra + 20000*Sua + 10000*Da + 10000*LyDung;
    return GiaNguyenLieu;
}
//ham tao mot struct node
struct Node3 { 
    NguyenLieu data3;
    struct Node3 *next3;
};
//ham tao mot struct list
struct SList3 {
    Node3 *head3;
    Node3 *tail3;
    long size3;
};
// ham list rong
void KhoiTaoListRong( SList3 &l) {
    l.head3 = NULL;
    l.tail3 = NULL;
    l.size3 = 0;
}
// ham tao node 
Node3* KhoiTaoNodeRong () {
	NguyenLieu x;
    Node3 *p= new Node3; // cap phat vung nho cho node p
    if(p == NULL){
        cout<<"Khong du bo nho de cap phat";
        return NULL;
    }
    else {
    	cin >>x;
        p->data3 = x; // truyen gia tri x vao cho data
        p->next3 = NULL; //p chua tro toi node khac
        return p;
    }
}
void ThemVaoCuoi(SList3 &l, Node3 *p){
    if(l.head3 == NULL){
        l.head3=l.tail3=p;
    }
    else{
        l.tail3->next3=p; // cho con tro pTail lien ket vá»›i node p
        l.tail3=p; // cap nhat lai la node cuoi
    }
    l.size3= l.size3 +1;
}
//ham xuat danh sach nguyen lieu
void XuatDSNL(SList3 l) {				
	Node3* p =l.head3;
	if(p==NULL) {
		cout<<"\n\t\t\tDanh sach rong.";
		cout<<"\n\t\t\t\7NHAN PHIM 1 DE NHAP DANH SACH.";
	}
	if(p != NULL) {
		int i=0;
		cout<<endl<<"\t\t\t\tDANH SACH NGUYEN LIEU:";
		while (p != NULL) {
			cout<<endl<<"\t\t\t--------------------------------\n";
			cout<<"\n\t\t\t\tNGAY THU "<<i+1<<endl;
			cout<<(p->data3);
			i++;
			p = p->next3;
		}
		cout << endl;
		Beep(523,500);
	    cin.get(); 
		}
	delete p;
}
//ham ghi file nguyen lieu
void GhiFileNguyenLieu(SList3 l) {			//ghi file nguyen lieu
	FILE *file = fopen("NguyenLieu.txt","w");
	Node3 *p=l.head3; 
		fprintf(file,"\t\t\t\t\t=====================================\n");
		fprintf(file,"\t\t\t\t\t=        DANH SACH NGUYEN LIEU      =\n");
		fprintf(file,"\t\t\t\t\t=====================================\n\n\n");
	while(p != NULL) {
		fprintf(file,"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fprintf(file,"\t\t\t\t~                     Ngay: %2d/%2d/%4d               ~\n",p->data3.d.date,p->data3.d.month,p->data3.d.year);
		fprintf(file,"\t\t\t\t~   STT    |   Ten nguyen lieu    |      So luong    ~\n");
		fprintf(file,"\t\t\t\t~    1     |         Cafe         |        %.2f      ~\n",p->data3.Coffee);
		fprintf(file,"\t\t\t\t~    2     |         Tra          |        %.2f      ~\n",p->data3.Tra);
		fprintf(file,"\t\t\t\t~    3     |         Sua          |        %.2f      ~\n",p->data3.Sua);
		fprintf(file,"\t\t\t\t~    4     |         Da           |        %.2f      ~\n",p->data3.Da);
		fprintf(file,"\t\t\t\t~    5     |         Ly dung      |        %.2f      ~\n",p->data3.LyDung);
		fprintf(file,"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		p = p->next3;
	}
	fclose(file);
	cout << "\n\t\t\tGHI FILE NGUYEN LIEU THANH CONG!!!";
}
void TongTien(SList3 l){
	float Tong=0;
	Node3 *p=l.head3;
	if(p==NULL){
		cout << "\n\t\t\t\7Danh sach dang rong.";
		cout << "\n\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		while(p!=NULL){
			Tong = Tong + p->data3.GiaMotNgay();
			p=p->next3;
		}
		Beep(523,500);  
		cin.get();
		cout<< std::setprecision(20);
		cout << "\n\t\t\tTong tien nguyen lieu la: " <<Tong<<"d";
	}	
}
void SuaDoi3(SList3 l)				//ham chinh sua 1 ngay trong danh sach
{	
	Node3 *p=l.head3;
	if(p == NULL)
	{
		cout << "\n\t\t\t\t\7Danh sach rong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
	}
	if(p != NULL)
	{
		Date m;
		cout<<"Nhap Date can chinh sua: ";
		NhapDate(m);
		int dem = 0;
		while(p != NULL)
		{
			if(SS(p->data3.getdate(),m)==1)
			{
				Beep(523,500);
	    		cin.get(); 
				cin >> p->data3;
				dem++;
			}
			p = p->next3;
		}
		if(dem == 0)
		{
			cout << "\n\t\t\t\7Khong co ngay trong danh sach";
			cout << "\n\t\t\tNHAN PHIM 2 DE TIM LAI.";
		}
	}
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
	gotoxy(34,16);
	cout<<"1.Khach hang.";
	gotoxy(34,17);
	cout<<"2.Nhan vien.";
	gotoxy(34,18);
	cout<<"3.Nguyen lieu.";
	gotoxy(26.5,19);
	cout<<"Nhap doi tuong muon xu ly: ";
	cin>>n;
	if(n==1) {
		system("cls");
		menu1();
	}
	else if(n==2) {
		system("cls");
		menu2();
	}
	else if(n==3) {
		system("cls");
		menu3();
	}
	else {
		cout<<"\n\n\t\t\t\t\7MOI BAN NHAN LAI:";
		sleep(1); 			//keo dai time hien thi dong chu
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
	cout<<"=               Nhap 5: Hoa don cua 1 khach.             ="; gotoxy(11,35);
	cout<<"=               Nhap 6: Tro ve menu chinh.               ="; gotoxy(11,36);
	cout<<"=               Nhap 7: Thoat chuong trinh.              ="; gotoxy(11,37);
	cout<<"=========================================================="; gotoxy(11,38);
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
				cout<<"\n\t\tKHACH HANG THU "<<++i<<":"<<endl;
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
			GhiFileKhachHang(l);
		}
		else if(luachon==5) {
			Hoadon(l);
		}
		else if(luachon==6) {
			system("cls");
			menuChung();
		}
		else if(luachon==7) {
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
	SList2 sl;
	SList2rong(sl);
    gotoxy(11,6);
	cout<<"=========================================================="; gotoxy(11,7);
	cout<<"=               Nhap 1: Nhap DS nhan vien.               ="; gotoxy(11,8);
	cout<<"=               Nhap 2: Chinh sua nhan vien.             ="; gotoxy(11,9);
	cout<<"=               Nhap 3: Xuat DS nhan vien.               ="; gotoxy(11,10);
	cout<<"=               Nhap 4: Ghi file nhan vien.              ="; gotoxy(11,11);
	cout<<"=               Nhap 5: Tim kiem nhan vien.              ="; gotoxy(11,12);
	cout<<"=               Nhap 6: Xuat luong nhan vien.            ="; gotoxy(11,13);
	cout<<"=               Nhap 7: Luong nhan vien cao nhat.        ="; gotoxy(11,14);
	cout<<"=               Nhap 8: Tro ve menu chinh.               ="; gotoxy(11,15);
	cout<<"=               Nhap 9: Thoat chuong trinh.              ="; gotoxy(11,16);
	cout<<"=========================================================="; gotoxy(11,17);
	cout<<"Nhap lua chon: ";
	while (1) {
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1) {
			int n,i=0;
			cout<<"Nhap so luong nhan vien:";
			cin>>n;
			for(int j=0;j<n;j++) {
				cout<<"\n\t\tNHAN VIEN THU "<<++i<<":"<<endl;
				Node2 *p3=TaoNode2();
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

void menu3() {
	system("cls");
	int luachon;
	SList3 l;
	KhoiTaoListRong(l);
    gotoxy(11,1);
	cout<<"=========================================================="; gotoxy(11,2);
	cout<<"=               Nhap 1: Nhap DS nguyen lieu.             ="; gotoxy(11,3);
	cout<<"=               Nhap 2: Chinh sua nguyen lieu.           ="; gotoxy(11,4);
	cout<<"=               Nhap 3: Xuat DS nguyen lieu.             ="; gotoxy(11,5);
	cout<<"=               Nhap 4: Ghi file nguyen lieu.            ="; gotoxy(11,6);
	cout<<"=               Nhap 5: Tong tien nguyen lieu.           ="; gotoxy(11,7);
	cout<<"=               Nhap 6: Tro ve menu chinh.       	    ="; gotoxy(11,8);
	cout<<"=               Nhap 7: Thoat chuong trinh.       	    ="; gotoxy(11,9);
	cout<<"=========================================================="; gotoxy(11,10);

	cout<<"Nhap lua chon: ";
	while (1) {
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1) {
			int n,i=0;
			cout<<"Nhap so ngay su dung nguyen lieu:";
			cin>>n;
			for(int j=0;j<n;j++) {
				cout<<"\n\t\tNGUYEN LIEU NGAY THU "<<++i<<":"<<endl;
				Node3 *p=KhoiTaoNodeRong();
				ThemVaoCuoi(l,p);
			}
		}
		else if(luachon==2) {
			SuaDoi3(l);
		}
		else if(luachon==3) {
			XuatDSNL(l);
		}
		else if(luachon==4) {
			GhiFileNguyenLieu(l);
		}
		else if(luachon==5) {
			TongTien(l);
		}
		else if(luachon==6) {
			system("cls");
			menuChung();
		}
		else if(luachon==7) {
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