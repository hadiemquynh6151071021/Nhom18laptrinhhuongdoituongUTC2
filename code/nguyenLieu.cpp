#include<iostream>
using namespace std;
class NguyenLieu {
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
ostream &operator << ( ostream &out, NguyenLieu nl){
    out<<"So luong nguyen lieu da dung: "<<endl;
    out<<"Coffee: "<<nl.Coffee<<endl;
    out<<"Tra: "<<nl.Tra<<endl;
    out<<"Sua: "<<nl.Sua<<endl;
    out<<"Da: "<<nl.Da<<endl;
    out<<"Ly Dung: "<<nl.LyDung<<endl;
    return out;
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
}





