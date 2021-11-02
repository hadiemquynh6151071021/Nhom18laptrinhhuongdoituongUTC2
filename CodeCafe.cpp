#include<iostream>
#include<iomanip>		//thu vien de lam tron so
#include<string>
#include<windows.h>		//thu vien de tao am thanh, di chuyen con tro
#include<unistd.h>
void menu1();
void menu2();

//ham di chuyen con tro
void gotoxy(int x, int y) 
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

struct Date{
	int date, month, year;
};

using namespace std;
class Nguoi{
	private:
		string SDT,Diachi;
		Date NgaySinh;
	public:
		Date getns()		//HAM LAY NGAY SINH
		{
			Date t;
			t.date=NgaySinh.date;
			t.month=NgaySinh.month;
			return t;
		}
		void Nhapthongtin()
		{
			
			cout <<"\tNhap ngay sinh: ";
			cout <<"\n\t\t-Ngay:";
			cin >> NgaySinh.date;
			cout <<"\t\t-Thang:";
			cin >> NgaySinh.month;
			cout <<"\t\t-Nam:";
			cin >> NgaySinh.year;
			fflush(stdin);
			cout <<"\tNhap SDT: " ;
			getline(cin,SDT);
			cout <<"\tNhap dia chi: ";
			getline(cin,Diachi);
		}
		void Xuatthongtin()
		{
			cout <<"\t\t\tNgay sinh: " << NgaySinh.date << "/" << NgaySinh.month << "/" << NgaySinh.year <<endl;
			cout << "\t\t\tSo dien thoai: " << SDT << endl ;
			cout << "\t\t\tDia chi: " << Diachi <<endl;
		}
		virtual void GiaTien()=0;
		
};
//TODO: CLASS KHACH HANG
class KhachHang: private Nguoi{
	private:
		int SoLuong;
		string MKH, MatHang[20];
		Date NgayMua;
	public:
		string getMKH();		//HAM LAY MA KHACH HANG
		Date getnm();			//HAM LAY NGAY MUA
		friend istream & operator >> (istream &is, KhachHang & k);	// HAM NHAP 1 KHACH HANG
		friend ostream & operator << (ostream &os, KhachHang &k );	// HAM IN 1 KHACH HANG
		void GiaTien();	//HAM DINH GIA MAT HANG VA TINH TIEN
};
string KhachHang::getMKH()
{
	return MKH;
}
Date KhachHang::getnm()
{
	Date t;
	t.date=NgayMua.date;
	t.month=NgayMua.month;
	return t;
}
istream & operator >> (istream &is, KhachHang & k)
{
		fflush(stdin);
		cout << endl << "\tNhap ma khach hang: " ;
		getline(cin, k.MKH);
		k.Nhapthongtin();
		cout << "\tNhap ngay mua: " ;
		cout <<"\n\t\t-Ngay:";
		is >> k.NgayMua.date;
		cout <<"\t\t-Thang:";
		is >> k.NgayMua.month;
		cout <<"\t\t-Nam:";
		is >> k.NgayMua.year;
		fflush(stdin);
		cout << "\tNhap so luong: " ;
		is >> k.SoLuong ;
		for (int i=1;i<=k.SoLuong;i++)	// mat hang la kieu mang do 1 nguoi co the mua nhieu mon
		{
			fflush(stdin);
			cout << "\t\tNhap mat hang " << i <<":";
			getline(cin,k.MatHang[i]);
		}
		return is;
}
ostream & operator << (ostream &os, KhachHang &k )
{
	os << endl << "\t\t\tMa khach hang: " << k.MKH << endl;
	k.Xuatthongtin();
	os << "\t\t\tNgay mua hang: " << k.NgayMua.date << "/" <<k.NgayMua.month << "/" << k.NgayMua.year << endl ;
	os << "\t\t\tSo luong: " << k.SoLuong << endl ;
	for (int i=1; i <= k.SoLuong; i++)
	{
			os << "\t\t\t\tTen mon " << i << ":" << k.MatHang[i] << endl;
	}
	return os;
}

//So Sanh
int SoSanh(Date a,Date b)
{
	if(a.date==b.date && a.month==b.month)
		return 1;
	return 0;
}

void KhachHang::GiaTien()
{
	string x1 = "Cafe den", x2 = "Cold brew", x3 = "Bac siu",x4 = "Cafe sua", x5 = "Cappuccino",x6 = "Americano", x7 = "Tra matcha";
	string x8 = "Tra vai", x9 = "Tra hat sen", x10 = "Hong tra latte", x11 = "Tra dao cam sa", x12 = "Tra sua mac ca", x13 = "Tra viet quoc", x14 = "Tra sua oolong";
	float *Gia = new float[SoLuong];		// cap phat bo nho dong cho mang gia
	float Tong = 0;
	for ( int i=1; i <= SoLuong; i++)
	{
		if (MatHang[i].compare(x1) == 0 || MatHang[i].compare(x2) == 0)		//trong c++ de so sanh hai chuoi ta dung compare
		{
			Gia[i] = 35000;
		}
		else if (MatHang[i].compare(x3) == 0 || MatHang[i].compare(x4) == 0)
		{
			Gia[i] = 38000;
		}
		else if (MatHang[i].compare(x5) == 0 || MatHang[i].compare(x6) == 0)
		{
			Gia[i] = 40000;
		}
		else if (MatHang[i].compare(x7) == 0 || MatHang[i].compare(x8) == 0)
		{
			Gia[i] = 55000;
		}
		else if (MatHang[i].compare(x9) == 0 || MatHang[i].compare(x10) == 0)
		{
			Gia[i] = 50000;
		}
		else if (MatHang[i].compare(x11) == 0 || MatHang[i].compare(x12) == 0)
		{
			Gia[i] = 59000;
		}
		else
		{
			Gia[i] = 60000;
		}
	}
	for (int i=0; i <= SoLuong; i++)		//cau lenh tinh tong trong truong hop 1 nguoi mua 2 mat hang khac nhau
	{
			Tong += Gia[i];	
	}
	if (SoSanh(getns(),getnm()))
	{
		cout << "\t\t\tUu dai 15% nhan dip sinh nhat";
		cout << endl << "\t\t\tGia thanh toan: " << Tong-((Tong*15)/100)<<"d";
	}
	else
	{
		cout << "\t\t\tGia thanh toan: " << Tong <<"d";
	}
	delete [] Gia;
}
//STRUCT NODE
struct Node 
{
	KhachHang data;
	Node *next;
};
//STRUCT DANH SACH
struct SList1 
{
	Node *head;
	Node *tail;
	long size;
};
//HAM DANH SACH RONG
void SList1rong (SList1 &l) 
{
	l.head = NULL;
	l.tail = NULL;
	l.size = 0;
}
//HAM TAO 1 NODE
Node* Taonode1()
{
	KhachHang v;
	Node* p = new Node;
	cin >> v;
	p->data = v ;	
	p->next = NULL;	
	return p;
}
//HAM THEM 1 NODE KHACH HANG VAO CUOI DANH SACH
void Themcuoi1 (SList1 &l, Node *p)
{
		if (l.size == 0) 
		{
			l.head = p;
			l.tail = p;
		}
		else 
		{
			l.tail->next = p;
			l.tail = p;	  
		}
		l.size = l.size + 1;
}
//HAM XUAT 1 DANH SACH
void XuatDSKH (SList1 l) 
{
	Node* p = l.head;
	if(p == NULL)
	{
		cout << "\n\t\t\t\tDanh sach rong.";
		cout << "\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
		cout << "\7";	
	}
	if(p != NULL)
	{
		int i=0;
		cout << endl << "\t\t\t\tDANH SACH KHACH HANG:";
		while (p != NULL) {
			cout << endl << "\t\t\t--------------------------------\n";
			cout << "\t\t\t\tKHACH HANG THU " << i+1 << endl;
			cout << (p->data);
			i++;
			p = p->next;
		}
		cout << endl;
		Beep(523,500);  //lenh tao am thanh
	    cin.get();
	} 
	delete p;
}
//HAM IN HOA DON 1 KHACH DUA VAO MKH
void Hoadon (SList1 &l)
{
	string x;
	fflush(stdin);
	cout << "Ma khach hang can tim:";
	getline(cin,x);
	Node* p = l.head;
	while (p != NULL) 
	{
		if(x.compare(p->data.getMKH())==0)
		{
			cout << p->data;
			p->data.GiaTien();
		}
		p = p->next;
	}
	if(p = NULL)
	{
		cout << "\t\t\tKhong co khach hang trong danh sach";
		cout << "\t\t\tNHAN PHIM 3 DE TIM LAI.";
	}
	Beep(523,500);  //lenh tao am thanh
    cin.get(); 
}
//TODO: CLASS NGUYEN LIEU
//NHANVIEN
class NhanVien:private Nguoi
{
    private:
        string name,loainhanvien;
        int soluonggio;
    public:
        friend istream & operator >> (istream &is, NhanVien & n);	// HAM NHAP 1 NHAN VIEN
		friend ostream & operator << (ostream &os, NhanVien & n);	// HAM IN 1 NHAN VIEN
        void GiaTien();
        string getname();

};
string NhanVien::getname()
{
    return name;
}
void NhanVien::GiaTien()
{
    float ftienluong = 1;
    string a = "Full time";
    string b = "Part time";
    if(loainhanvien.compare(a) == 0)
	{
        ftienluong = ( 27000*soluonggio*7);
       
    }
    else if(loainhanvien.compare(b) == 0)
	{
        ftienluong = (17000*soluonggio*7);
    }
    cout << endl << "\t\t\tTien luong:" << ftienluong << "d";    
}
istream& operator >> (istream &is, NhanVien & n)
{
    fflush(stdin);
    cout << "\tNhap Ho va ten :";
    getline(cin,n.name);
    n.Nhapthongtin();
    cout << "\tNhap loai nhan vien:";
    getline(cin,n.loainhanvien);
    cout << "\tNhap so luong gio:";
    is >> n.soluonggio;
    return is;
}
ostream& operator << (ostream &os, NhanVien & n)
{
    cout<<"\t\t\tHo va ten :"<<n.name<<endl;
    n.Xuatthongtin();
    cout<<"\t\t\tLoai nhan vien :"<<n.loainhanvien<<endl;
    cout<<"\t\t\tSo luong gio:"<<n.soluonggio<<endl;
    return os;
}
//Struct Node
struct Node3
{
    NhanVien data3;
    Node3* next3;
};
struct SList3
{
    Node3* head3;
    Node3* tail3;
    long size3;
};
//TAO DANH SACH RONG
void SList3rong(SList3 &sl)
{
    sl.head3 = NULL;
    sl.tail3 = NULL;
    sl.size3 = 0;
}
//TAO NOT MOI 
Node3* TaoNode3()
{
	NhanVien v;
    Node3 *p3 = new Node3 ;
    cin>>v;
    p3->data3 = v;
    p3->next3= NULL;
    return p3;
}
void addLast(SList3 &sl , Node3 *p3)
{   
    if(sl.size3 == 0)
	{
       sl. head3 = p3 ;
       sl. tail3 = p3;
    }
    else 
	{
        sl.tail3 ->next3 = p3;
        sl.tail3 = p3 ;
    }
    sl.size3 =sl.size3+1;
}
void searchbyName(SList3 sl)
{
    string fname;
    int dem=0;
	fflush(stdin);
    cout<<"Ten nhan vien muon tim :";
    getline(cin,fname);
    Node3*p3 = sl.head3;
    while ( p3!= NULL)
    {
	    if(fname == p3->data3.getname())
		{
	        cout<<(p3->data3);
	        dem++;
	  	}
	    p3 = p3-> next3;
	    
    }
    if (dem==0)
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
		cout<<"\7";
	}
	if(p != NULL)
	{
		int i=0;
		cout<<endl<<"\t\t\t\tDANH SACH NHAN VIEN:";
		while (p3 != NULL) 
		{
			cout<<endl<<"\t\t\t--------------------------------\n";
			cout<<"\t\t\t\tNHAN VIEN THU "<<i+1<<endl;
			cout<<(p3->data3);
			i++;
			p3 = p3->next3;
		}
		Beep(523,500);  //lenh tao am thanh
	    cin.get(); 
		cout << endl;
	}
	delete p3;
}
void wpay (SList3 sl)
{
    string x;
    int dem=0;
    fflush (stdin);
    cout<<"\t\t\tNhap ten nhan vien :";
    getline(cin,x);
    Node3*p3 = sl.head3;
    while (p3 != NULL)
	{
           if(x.compare(p3->data3.getname())==0)
        {    
            cout<< std::setprecision(20);
            cout<<p3->data3;
            p3->data3.GiaTien();
            dem++;
        }
		p3=p3->next3;
    }
    if(dem==0)
	{
			cout<<"\n\t\t\tKhong tim thay nhan vien.";
			cout<<"\n\t\t\tNHAN PHIM 4 DE TIM LAI.";
	}
    Beep(523,500);  //lenh tao am thanh
    cin.get(); 
}
//tieu de
void TieuDe()
{
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
}
//HAM MENU CHUNG
void menuChung()
{
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
	if(n==1)
	{
		system("cls");
		menu1();
	}
	else if(n==2)
	{
		system("cls");
		menu2();
	}
	else 
	{
		cout<<"\n\t\t\tMOI BAN NHAN LAI:";
		sleep(5); //keo dai time hien thi dong chu
		menuChung();
	}
}
//MENU1
void menu1()
{
	system("cls");
	int luachon;
	SList1 l;
	SList1rong(l);
	TieuDe();
    gotoxy(11,29);
	cout<<"=========================================================="<<endl; gotoxy(11,30);
	cout<<"=               Nhap 1: Nhap khach hang.                 ="<<endl; gotoxy(11,31);
	cout<<"=               Nhap 2: Xuat DS khach hang.              ="<<endl; gotoxy(11,32);
	cout<<"=               Nhap 3: Hoa don cua mot khach.           ="<<endl; gotoxy(11,33);
	cout<<"=               Nhap 4: Tro ve menu chinh.               ="<<endl; gotoxy(11,34);
	cout<<"=               Nhap 5: Thoat chuong trinh.              ="<<endl; gotoxy(11,35);
	cout<<"=========================================================="<<endl; gotoxy(11,36);
	fflush(stdin);
	cout<<"Nhap lua chon: ";
	while (1)
	{
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1)
		{
			int n,i=0;
			cout<<"Nhap so luong khach hang:";
			cin>>n;
			for(int j=0;j<n;j++)
			{
				cout<<"\t\tKHACH HANG THU "<<++i<<":"<<endl;
				Node *p=Taonode1();
				Themcuoi1(l,p);
			}
		}
		else if(luachon==2)
		{
			XuatDSKH(l);
		}
		else if(luachon==3)
		{
			Hoadon(l);
		}
		else if(luachon==4)
		{
			system("cls");
			menuChung();
		}
		else if(luachon==5)
		{
			exit(0);
		}
	}
}
void menu2()
{
	system("cls");
	int luachon;
	SList3 sl;
	SList3rong(sl);
	TieuDe();
    gotoxy(11,29);
	cout<<"=========================================================="<<endl; gotoxy(11,30);
	cout<<"=               Nhap 1: Nhap nhan vien.                  ="<<endl; gotoxy(11,31);
	cout<<"=               Nhap 2: Xuat DS nhan vien.               ="<<endl; gotoxy(11,32);
	cout<<"=               Nhap 3: Tim kiem nhan vien.              ="<<endl; gotoxy(11,33);
	cout<<"=               Nhap 4: Xuat luong nhan vien.            ="<<endl; gotoxy(11,34);
	cout<<"=               Nhap 5: Tro ve menu chinh.               ="<<endl; gotoxy(11,35);
	cout<<"=               Nhap 6: Thoat chuong trinh.              ="<<endl; gotoxy(11,36);
	cout<<"=========================================================="<<endl; gotoxy(11,37);
	cout<<"Nhap lua chon: ";
	while (1)
	{
		cout<<endl<<"Nhap chuc nang: ";
		cin>>luachon;
		if(luachon==1)
		{
			int n,i=0;
			cout<<"Nhap so luong nhan vien:";
			cin>>n;
			for(int j=0;j<n;j++)
			{
				cout<<"NHAN VIEN THU "<<++i<<":"<<endl;
				Node3*p3=TaoNode3();
				addLast(sl,p3);
			}
		}
		else if(luachon==2)
		{
			XuatDSNV(sl);
		}
		else if(luachon==3)
		{
			searchbyName(sl);
		}
		else if(luachon==4)
		{
			wpay(sl);
		}
		else if(luachon==5)
		{
			system("cls");
			menuChung();
		}
		else if(luachon==6)
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
