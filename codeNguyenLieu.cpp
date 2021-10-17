#include<iostream>
using namespace std;

class Ngay{
    protected:
        int Ngay;
        int Thang;
        int Nam;
    public: 
        void NhapNgay();
        void XuatNgay();
        int getNgay();
        int getThang();
        int getNam();
};
int Ngay::getNgay(){
    return Ngay;
}
int Ngay::getThang(){
    return Thang;
}
int Ngay::getNam(){
    return Nam;
}
void Ngay::NhapNgay(){
    cout<<"Nhap Ngay: ";
    cin>>Ngay;
    cout<<"Nhap Thang: ";
    cin>>Thang;
    cout<<"Nhap Nam: ";
    cin>>Nam;
}
void Ngay::XuatNgay(){
    cout<<"Ngay"<<" "<<Ngay<<"Thang"<<" "<<Thang<<"Nam"<<" "<<Nam<<endl;
}
class NguyenLieu:public Ngay{
    private:
        string Ten;
        float GiaTien;
        string NSX;
        string HSD;
    public:
        friend istream &operator >> ( istream &in, NguyenLieu &nl);
        friend ostream &operator << ( out &out, NguyenLieu nl);
        void SuDung();
        string getTen();
};
istream &operator >> ( istream &in, NguyenLieu &nl){
    cout<<"Nhap Ten nguyen lieu: ";
    cin.ignore();
    getline(in,nl.Ten);
    cout<<"Nhap Gia nguyen lieu: ";
    in>>nl.GiaTien;
    cout<<"Nhap NSX: ";
    cin.ignore();
    getline(in,nl.NSX);
    cout<<"Nhap HSD: ";
    cin.ignore();
    getline(in,nl.HSD);
    return is;
}
ostream &operator << (ostream &NguyenLieu, NguyenLieu nl){
    out<<"___________________________________________";
    
    out<<"Ten Nguyen lieu: "<<" "<<nl.Ten<<endl;
    out<<"Gia Nguyen lieu: "<<" "<<nl.GiaTien<<endl;
    out<<"NSX: "<<" "<<nl.NSX<<endl;
    out<<"HSD: "<<" "<<nl.HSD<<endl;
    out<<"___________________________________________";
    return os;
}
void NguyenLieu::SuDung(){
    cout<<"Nhap Han su dung: ";
    cout<<"Ngay"; 
    cin>>Ngay;
    cout<<"Thang"; 
    cin>>Thang;
    cout<<"Nam"; 
    cin>>Nam;
    if(getNam() > Nam){
        cout<<"Nguyen lieu da bi hu!";
    }
    else if(getNam() == Nam && getThang() > Thang ){
        cout<<"Nguyen lieu da bi hu!";
    }
    else if(getNam() == Nam && getThang() == Thang && getNgay() > Ngay ){
        cout<<"Nguyen lieu da bi hu!";
    }
    else{
        cout<<"Nguyen lieu con su dung tot!";
    }
}
string NguyenLieu::getTen(){
    return Ten;
}
struct node{
    NguyenLieu data;
    struct node *pNext;
};
typedef struct node NODE;
struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* KhoiTaoNODE(NguyenLieu x){
    NODE *p= new NODE;
    p->data=x;
    p->pNext=NULL;
    return p;
}
void ThemVaoDau(LIST &l, NODE* p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
void ThemVaoCuoi(LIST &l, NODE* p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void XuatDanhSach(LIST l){
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->data.Xuat();
    }
}
int TimMax(LIST l){
    int max=l.pHead->data;
    for(NODE *k=l.pHead->pNext; k!=NULL; k=k->pNext){
        if(max<k->data){
            max=k->data;
        }
    }
    return max;
}
int main(){
    LIST l;
    KhoiTao(l);
    int n;
    cout<<"Nhap so luong nguyen lieu can them: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        Nhap();
        int x;
        cout<<"Nhap gia tri cua nguyen lieu:";
        cin>>x;
        NODE* p=KhoiTaoNODE(x);
        ThemVaoDau(l,p);
    }
    cout<<"\n\n\tDANH SACH NGUYEN LIEU: \n";
    Xuat();
    cout<<"Gia tien Nguyen lieu: ";
    XuatDanhSach(l);
    cout<<"\nNguyen lieu mac nhat la: "<<TimMax(l);
    return 0;
}
