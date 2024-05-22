#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<conio.h>
#include<vector>
//#include<fstream>
using namespace std;
class KH{
    public:
    char hoten[20],  nsinh[20];
    char sdt[20];
    float san,tgian,nsan,tsan,nds,msan;
    float gia;
    void nhap();
    void hienthi();
void soluong();
};
void KH::nhap(){
    cin.ignore(1);
    cout<<"\n nhap ho va ten:";cin.getline(hoten,20);fflush(stdin);
    cout<<"\n nhap nam sinh:";cin.getline(nsinh,20);fflush(stdin);
    cout<<"\n nhap so dien thoai: ";cin.getline(sdt,20);fflush(stdin);
    cout<<"\n nhap ma san: ";cin>>msan;
    cout<<"\n nhap so san: ";cin>>san;
    cout<<"\n nhap ngay dat san: ";cin>>nds;
    cout<<"\n nhap thoi gian thue (tieng): ";cin>>tgian;
    cout<<"\n thoi gian bat dau nhan san (mo tu 16h-20h) :";cin>>nsan;
}
void KH::hienthi(){
    cout<<""<<setw(10)<<hoten<<setw(8)<<nsinh;
    cout<<""<<setw(11)<<sdt<<setw(11)<<msan;
    cout<<""<<setw(10)<<san<<setw(10)<<tgian<<setw(10)<<nsan;
    tsan= tgian + nsan;
    cout<<""<<setw(10)<<tsan<<setw(10)<<nds;
    gia=tgian*70000;
    cout<<""<<setw(10)<<gia;
}
class quanli: public KH{
    public:
    KH kh[100];
    int n;
    void nhap();
    void hienthi();
    void themtt();
    void xoatt();
    void suatt();
    void hienthongtin();
    friend class Dichvu;
};  vector<quanli> listquanli;
void quanli::themtt(){
   quanli Newkh;
   Newkh.nhap();
   listquanli.push_back(Newkh);
   
}
void quanli::hienthongtin(){
   cout<<""<<setw(10)<<hoten<<setw(8)<<nsinh;
    cout<<""<<setw(11)<<sdt<<setw(11)<<msan;
    cout<<""<<setw(10)<<san<<setw(10)<<tgian<<setw(10)<<nsan;
    tsan= tgian + nsan;
    cout<<""<<setw(10)<<tsan<<setw(10)<<nds;
    gia=tgian*70000;
    cout<<""<<setw(10)<<gia;
    for (int i=0;i<listquanli.size();i++) {
listquanli[i].hienthi();
}}

void quanli::xoatt(){
    for (int i=0;i<listquanli.size();i++) {
        if (listquanli[i].msan==msan) {
listquanli.erase(listquanli.begin()+i);
        }
    }
}
void quanli::nhap(){
   
    cout<<"nhap so luong khach hang muon dat san:";cin>>n;
    for (int i=0;i<n;i++){
        cout<<"\n nhap khach hang thu:"<<i+1<<"";
        kh[i].nhap();
    }
}
void quanli::hienthi(){
    cout<<"\n Ho ten"<<setw(20)<<"Nam sinh"<<setw(20)<<"so dien thoai"<<setw(10);
    cout<<"ma san"<<setw(5)<<"san"<<setw(15)<<"thoi gian thue"<<setw(20);
    cout<<"thoi gian nhan"<<setw(20)<<"thoi gian tra"<<setw(15)<<"ngay dat san"<<setw(15);
    cout<<"Gia tien "<<setw(15);
    for (int i=0;i<n;i++){
        kh[i].hienthi();
    }
    }
class Dichvu{
    public:
    float vot,cau,douong,Msan;
    void nhapp();
    void hienthi();
};
void Dichvu::nhapp() {
    cout << "nhap ma san: "; cin >> Msan;
    for (int i = 0; i < listquanli.size(); i++) {
        if (listquanli[i].msan == Msan) {

            cout << endl << "nhap so luong vot ban muon thue: "; cin >> vot;
            cout << endl << "nhap so luong cau ban muon thue: "; cin >> cau;
            cout << endl << "nhap so luong do uong ban muon mua: "; cin >> douong;
            break; 
        }else { 
        cout << endl << "Ma san nhap khong hop le. Vui long nhap lai hoac thoat." << endl;
       break;
    }
 
}}
void Dichvu::hienthi(){
    cout<<endl<<"Vot: "<<vot;
    cout<<endl<<"Cau: "<<cau;
    cout<<endl<<"Do uong: "<<douong;
}
void menu(){
    cout<<endl<<"==========================================================="<<"\n";
    cout<<"chao mung ban den voi dich vu cua chung toi. Vui long chon"<<endl;
    cout<<"==========================================================="<<"\n";
    cout<<"1. Dat san"<<endl;
    cout<<"2. Dich vu"<<endl;
    cout<<"3. Them thong tin"<<endl;
    cout<<"4. Sua thong tin"<<endl;
    cout<<"5. Xoa thong tin"<<endl;
    cout<<"0. Thoat"<<endl;
    
}
void Menu(){
    cout<<"Xin chao quan ly. Ban muon"<<endl;
    cout<<"1. Xem tinh trang san"<<endl;
    cout<<"2. Quan li khach hang"<<endl;
    cout<<"3. Thong ke doanh thu"<<endl;
    cout<<"0. Thoat"<<endl;
}
int main(){
int a,b,g,msan;
Dichvu s2;
string h;
quanli s1;
//freopen("in.doc","r",stdin);
//freopen("out.txt","w",stdout);
khoahoc:
    cout<<" Hoan nghenh ban den voi Vu tru badminton. Ban la"<<endl;
    cout<<"1. Khach hang"<<endl;
    cout<<"2. Quan li"<<endl;
    cin>>a;
    if (a==1) {
        while(true){
        menu();
        cin>>g;
        switch(g)
        {
            case 1:
            s1.themtt();
            cout<<"ban co muon xem hoa don khong? ";cin>>h;
            if (h=="co") {
            s1.hienthongtin();}
            break;
            case 0:
            goto khoahoc;
            case 2:
        
            s2.nhapp();
            break;
            case 3:
            s1.themtt();
            break;
            case 4:
            s1.hienthongtin();
            break;
            case 5:
            cout<<"nhap msan: ";cin>>msan;
            s1.xoatt();
break;
        }}

    }
    else if (a==2) { cout<<"vui long nhap mat khau: ";
    cin>>b;
    if (b==1234) {
        Menu();
    }else cout<<"mat khau sai vui long roi khoi day";
    };
return 0;
}