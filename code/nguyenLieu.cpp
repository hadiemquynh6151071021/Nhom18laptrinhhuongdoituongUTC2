#include<iostream>
#include<windows.h>	
#include<fstream>
using namespace std;
//TODO: Class Nguyen lieu( to chuc theo kieu danh sach lien ket don gom n ngay)
//TODO: struct ngay thang nam
struct Date {						
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
//TODO: class nguyen lieu
class NguyenLieu {
    private: 
        Date date;
        float Coffee;
        float Tra;
        float Sua;
        int Da;
        int LyDung;
    public:
        NguyenLieu();
        friend istream &operator >> ( istream &in, NguyenLieu &nl);
        friend ostream &operator << ( ostream &out, NguyenLieu nl);
        float GiaMotNgay();
        friend void GhiFileNguyenLieu(LIST l);
        Date getDate(){
            return date;
        }
        
};
//Todo: Ham tao nguyen lieu khong doi so
NguyenLieu::NguyenLieu(){           
    Date d;
    d.date=d.month=d.year=0;
    Coffee=Tra=Sua=Da=LyDung=0;
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
//TODO: ham list rong
void KhoiTaoListRong( LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
    l.size = 0;
}

// TODO: ham nhap so luong nguyen lieu 1 ngay( 1 node la 1 ngay)  
istream &operator >> ( istream &in, NguyenLieu &nl){
    cout<<"Nhap Date: "<<endl;
    NhapDate(nl.date);
    cout<<"Nhap so luong nguyen lieu: "<<endl;
    cout<<"Coffee: ";
    in>>nl.Coffee;
    cout<<"Tra: ";
    in>>nl.Tra;
    cout<<"Sua: ";
    in>>nl.Sua;
    cout<<"Da: ";
    in>>nl.Da;
    cout<<"Ly dung: ";
    in>>nl.LyDung;
    return in;
}
//TODO: ham xuat so luong nguyen lieu 1 ngay
ostream &operator << ( ostream &out, NguyenLieu nl){
    cout << "Date: ";
	XuatDate(nl.date);
    out<<"So luong nguyen lieu da dung: "<<endl;
    out<<"Coffee: "<<nl.Coffee<<endl;
    out<<"Tra: "<<nl.Tra<<endl;
    out<<"Sua: "<<nl.Sua<<endl;
    out<<"Da: "<<nl.Da<<endl;
    out<<"Ly Dung: "<<nl.LyDung<<endl;
    return out;
}
//TODO: ham tao node 
NODE* KhoiTaoNodeRong ( NguyenLieu x) {
    NODE *p= new NODE; // cap phat vung nho cho node p
    if(p == NULL){
        cout<<"Khong du bo nho de cap phat";
        return NULL;
    }
    else {
        p->data = x; // truyen gia tri x vao cho data
        p->pNext = NULL; //p chua tro toi node khac
        return p;
    }
}
//TODO: ham them Node vao cuoi
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
float NguyenLieu::GiaMotNgay() {
    string x1="Coffee", x2="Tra", x3="Sua", x4="Da", x5="Ly Dung";
    float GiaCoffeeMotNgay=0;
    for(int i=0; i< Coffee; i++){
        GiaCoffeeMotNgay+=80000;
    }
    float GiaTraMotNgay=0;
    for(int i=0; i< Tra; i++){
        GiaTraMotNgay+=30000;
    }
    float GiaSuaMotNgay=0;
    for(int i=0; i< Sua; i++){
        GiaSuaMotNgay+=20000;
    }
    float GiaDaMotNgay=0;
    for(int i=0; i< Da; i++){
        GiaDaMotNgay+=10000;
    }
    float GiaLyDungMotNgay=0;
    for(int i=0; i< LyDung; i++){
        GiaLyDungMotNgay+=10000;
    }
    float GiaNguyenLieu =GiaCoffeeMotNgay + GiaTraMotNgay + GiaSuaMotNgay + GiaDaMotNgay + GiaLyDungMotNgay;
    return GiaNguyenLieu;
}
//TODO: ham nhap danh sach nguyen lieu
void NhapDS(LIST &l)
{
    NODE *p;
    NguyenLieu x;
    int n;
    l.pHead=l.pTail=NULL;//khoi dong ds rong
    cout<<"Nhap vao so luong ngay: ";           //1 NODE la 1 ngay
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cout<<"Nhap thong tin nguyen lieu ngay "<<i+1<<" :"<<endl;
            cin>>x;
            p=KhoiTaoNodeRong(x);
            ThemVaoCuoi(l,p); //addhead(l,p);
       }

}
//TODO: ham hien thi danh sach nguyen lieu
void XuatDSNL(LIST l) {				
	NODE* p = l.pHead;
	if(p==NULL) {
		cout<<"\n\t\t\tDanh sach rong.";
		cout<<"\n\t\t\tNHAN PHIM 1 DE NHAP DANH SACH.";
		cout<<"\7";
	}
	if(p != NULL) {
		int i=0;
		cout<<endl<<"\t\t\t\tDANH SACH NGUYEN LIEU:";
		while (p != NULL) {
			cout<<endl<<"\t\t\t----------------------------------\n";
			cout<<"\n\t\t\t\tNGUYEN LIEU NGAY "<<i+1<<endl;
			cout<<(p->data);
			i++;
			p = p->pNext;
		}
		Beep(523,500);
	    cin.get(); 
		cout << endl;
	}
	delete p;
}
//TODO: ham ghi file nguyen lieu
/*void GhiFileNhanVien(LIST l) {			//ghi file nhan vien
	FILE *file = fopen("NhanVien.txt","w");
	NODE *p=l.pHead; 
	while(p != NULL) {
		fprintf(file,"\n------------------------------------------------------------------");
		fprintf(file,"\n||                     THONG TIN NGUYEN LIEU                    ||");
        

		p = p->pNext;
	}
	fclose(file);
	cout << "\n\t\t\tGHI FILE NGUYEN LIEU THANH CONG!!!";
}*/
/*
void GhiFileNguyenLieu(ofstream &fileout, NguyenLieu nl){
    int dem=0;
    ofstream file;
    fileout<<"------------------------------------------------------------------"<<endl;
    fileout<<"||                     THONG TIN NGUYEN LIEU                    ||"<<endl;
    fileout<<"||   --------------------------------------------------------   ||"<<endl;
    fileout<<"||      STT"<<"    |"<<"|        Ten nguyen lieu      |"<<"|    So luong"<<"    ||"<<endl;
    fileout<<"|| \t\t"<<dem++<<"\t   |"<<"|      \tCoffee:               "<<"|"<<"|"<<"       "<<nl.Coffee<< "        ||"<<endl; dem=dem++;
    fileout<<"|| \t\t"<<dem++<<"\t   |"<<"|      \tTra:                  "<<"|"<<"|"<<"       "<<nl.Tra<< "        ||"<<endl; dem=dem++;
    fileout<<"|| \t\t"<<dem++<<"\t   |"<<"|      \tSua:                  "<<"|"<<"|"<<"       "<<nl.Sua<< "        ||"<<endl; dem=dem++;
    fileout<<"|| \t\t"<<dem++<<"\t   |"<<"|      \tDa:                   "<<"|"<<"|"<<"       "<<nl.Da<< "        ||"<<endl; dem=dem++;
    fileout<<"|| \t\t"<<dem++<<"\t   |"<<"|      \tLy dung:              "<<"|"<<"|"<<"       "<<nl.LyDung<< "        ||"<<endl; 
    fileout<<"------------------------------------------------------------------"<<endl;
    fileout.close();
}
void LuuFile(LIST l, NguyenLieu nl){
    ofstream file;
	NODE *p=l.pHead; 
	while(p != NULL) {
        file.open("NguyenLieu.txt", ios::out);
        GhiFileNguyenLieu(file,nl);
        p = p->pNext;
    }
}*/
void ChinhSua(LIST l)				//ham chinh sua 1 ngay trong danh sach
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
}
int main(){
    LIST l;
    NODE *p;
    NguyenLieu nl;
    NhapDS(l);
    XuatDSNL(l);
    //ofstream file;
    //GhiFileNguyenLieu(l);
    //LuuFile(l,nl);
    cout<<nl.GiaMotNgay();
    KhoiTaoListRong(l);
    return 0;
}

    





