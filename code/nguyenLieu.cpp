#include<iostream>
#include<iomanip>
#include<windows.h>	
#include<stdio.h>
#include<fstream>
using namespace std;

struct Date {						//struct ngay thang nam
	int date, month, year;
};
struct List;
typedef struct List LIST;
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
int SS(Date d1,Date d2){
	if(d1.date==d2.date && d1.month==d2.month && d1.year==d2.year){
		return 1;
	}
	else return 0;
}
class NguyenLieu {
    private: 
    	Date d;
        int Coffee;
        int Tra;
        int Sua;
        int Da;
        int LyDung;
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
		friend void GhiFileNguyenLieu(LIST l);  
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
struct Node { 
    NguyenLieu data;
    struct Node *pNext;
};
typedef struct Node NODE;
//ham tao mot struct list
struct List {
    NODE *pHead;
    NODE *pTail;
    long size;
};
typedef struct List LIST;
// ham list rong
void KhoiTaoListRong( LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
    l.size = 0;
}
// ham tao node 
NODE* KhoiTaoNodeRong () {
	NguyenLieu x;
    NODE *p= new NODE; // cap phat vung nho cho node p
    if(p == NULL){
        cout<<"Khong du bo nho de cap phat";
        return NULL;
    }
    else {
    	cin >>x;
        p->data = x; // truyen gia tri x vao cho data
        p->pNext = NULL; //p chua tro toi node khac
        return p;
    }
}
void ThemVaoCuoi(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p; // cho con tro pTail lien ket với node p
        l.pTail=p; // cap nhat lai la node cuoi
    }
    l.size= l.size +1;
}
//TODO: ham xuat danh sach nguyen lieu
void XuatDSNL(LIST l) {				
	NODE* p =l.pHead;
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
			cout<<(p->data);
			i++;
			p = p->pNext;
		}
		cout << endl;
		Beep(523,500);
	    cin.get(); 
		}
	delete p;
}
//TODO: ham ghi file nguyen lieu
void GhiFileNguyenLieu(LIST l) {			//ghi file nguyen lieu
	FILE *file = fopen("NguyenLieu.txt","w");
	NODE *p=l.pHead; 
	while(p != NULL) {
		fprintf(file,"\n------------------------------------------------------------------");
		fprintf(file,"\n||                     THONG TIN NGUYEN LIEU                    ||");
        fprintf(file,"\n    Date: %1d/%1d/%4d                                           ",p->data.d);
        fprintf(file,"\n      ------------------------------------------------------    ");
        fprintf(file,"\n   STT:  |          Ten nguyen lieu:       |         So luong:  ");
        fprintf(file,"\n     1   |           Coffee                |        %0d         ",p->data.Coffee);
        fprintf(file,"\n     2   |           Tra                   |        %0d         ",p->data.Tra);
        fprintf(file,"\n     3   |           Sua                   |        %0d         ",p->data.Sua);
        fprintf(file,"\n     4   |           Da                    |        %0d         ",p->data.Da);
        fprintf(file,"\n     5   |           Ly dung               |        %0d         ",p->data.LyDung);
        fprintf(file,"\n||                                                              ||");
        fprintf(file,"\n||                     ---------------------                    ||");
        fprintf(file,"\n------------------------------------------------------------------");
        fprintf(file,"\n__________________________________________________________________\n");
       

		p = p->pNext;
	}
	fclose(file);
	cout << "\n\t\t\tGHI FILE NGUYEN LIEU THANH CONG!!!";
}
void TongTien(LIST l){
	float Tong=0;
	NODE *p=l.pHead;
	if(p==NULL){
		cout << "\n\t\t\t\7Danh sach dang rong.";
		cout << "\n\n\t\t\tNHAN PHIM 1 DE THEM DANH SACH.";
	}
	else {
		while(p!=NULL){
			Tong = Tong + p->data.GiaMotNgay();
			p=p->pNext;
		}
		Beep(523,500);  
		cin.get();
		cout<< std::setprecision(20);
		cout << "\n\t\t\tTong tien nguyen lieu la: " <<Tong<<"d";
	}	
}
/*void ChinhSua(LIST l)				//ham chinh sua 1 ngay trong danh sach
{	
	NODE *p=l.pHead;
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
			if(p->data.getDate() == m)
			{
				Beep(523,500);
	    		cin.get(); 
				cin >> p->data;
				dem++;
			}
			p = p->pNext;
		}
		if(dem == 0)
		{
			cout << "\n\t\t\t\7Khong co Date trong danh sach";
			cout << "\n\t\t\tNHAN PHIM 2 DE TIM LAI.";
		}
	}
}*/
  int main(){
    LIST l;
    NguyenLieu nl;
    KhoiTaoListRong(l);
    int n;
	cout<<"Nhap so luong ngay:";
	cin >> n;
	for(int i=0;i<n;i++) {
		cout<<"\n\t\tNGAY THU "<<i+1<<":"<<endl;
		NODE *p=KhoiTaoNodeRong();
		ThemVaoCuoi(l,p);
	}
    XuatDSNL(l);
    GhiFileNguyenLieu(l);
    TongTien(l);
}
 
