//TODO: CODE CLASS NGUYEN LIEU
class NguyenLieu {
    private:
        string Ten;
        float GiaTien;
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