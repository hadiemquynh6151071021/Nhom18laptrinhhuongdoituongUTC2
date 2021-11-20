#include<iostream>
using namespace std;
//TODO: Class Nguyen lieu( to chuc theo kieu danh sach lien ket don gom n ngay)
//TODO: struct ngay thang nam
struct Date {						
	int date, month, year;
};
//TODO: class nguyen lieu
class NguyenLieu {
    private: 
        Date HSD;
        float Coffee;
        float Tra;
        float Sua;
        int Da;
        int LyDung;
    public:
        NguyenLieu();
        friend istream &operator >> ( istream &in, NguyenLieu &nl);
        friend ostream &operator << ( ostream &out, NguyenLieu nl);
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
int main(){
    LIST *list;
    NguyenLieu nl;
    cout<<"Nhap thong tin Nguyen lieu 1 ngay: "<<endl;
    cin>>nl;
    cout<<"Thong tin Nguyen lieu da nhap: "<<endl;
    cout<<nl;


}


/*class NguyenLieu {
    private: 
        float Coffee;
        float Tra;
        float Sua;
        int Da;
        int LyDung;
    public:
        friend istream &operator >> ( istream &in, NguyenLieu &nl);
        friend ostream &operator << ( ostream &out, NguyenLieu nl);
        float GiaMotNgay();
       
};

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



int main(){
    NguyenLieu nl;
    LIST l;
    cout<<"Moi ban nhap thong tin nguyen lieu: "<<endl;
    cin>>nl;
    cout<<"Thong tin nguyen lieu: "<<endl;
    cout<<nl;
    cout<<"Gia nguyen lieu: "<<endl;
    cout<<nl.GiaMotNgay();
    cout<<endl<<"Gia nguyen lieu mot tuan:"<<endl;
    
    
    return 0;
    //con ham tinh tong tien 1 tuan
}*/





