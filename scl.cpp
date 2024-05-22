hoan
#include<iostream>
#include<iomanip>
#include<cstring>
//#include<fstream>
using namespace std;
class KH{
    public:
    char hoten[20];
    char sdt[20];
    int san,tgian,nsan,tsan,nds,msan;
    void nhap();
    void hienthi();
void soluong();
};
void KH::nhap() {
    cin.ignore(1);

    cout << "\nNhap ho va ten: ";
    cin.getline(hoten, 20);

    cout << "\nNhap so dien thoai: ";
    cin.getline(sdt, 20);

    cout << "\nNhap ma san: ";
    cin >> msan;

    while (true) {
        cout << "\nNhap so san (co tong cong 5 san lan luot tu 1->5): ";
        cin >> san;
        if ((san >= 1) && (san <= 5)) break;
        cout << "Khong co san nay. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "\nNhap ngay dat san : ";
        cin >> nds;
        if (nds >= 1 && nds <= 31) break;
        cout << "Khong hop le. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "\nNhap thoi gian thue (tieng): ";
        cin >> tgian;
        if (tgian > 0 && tgian <= 4) break;
        cout << (tgian <= 0 ? "Khong hop le. Vui long nhap lai.\n" : "Ban thue qua lau. Vui long giam thoi gian thue.\n");
    }

    while (true) {
        cout << "\nThoi gian bat dau nhan san (mo tu 16h - dong cua luc 20h): ";
        cin >> nsan;
        tsan = nsan + tgian;
        if (nsan >= 16 && nsan <= 20 && tsan <= 20) break;
        cout << ((nsan < 16 || nsan > 20) ? "Hien dang dong cua vui long dat vao gio khac.\n" : "Vuot qua muc thoi gian cho phep. Vui long dien lai.\n");
    }
}
void KH::hienthi(){
    cout<<endl<<""<<setw(10)<<hoten;
    cout<<""<<setw(11)<<sdt<<setw(11)<<msan;
    cout<<""<<setw(10)<<san<<setw(15)<<tgian<<setw(15)<<nsan;
    tsan= tgian + nsan;
    cout<<""<<setw(15)<<tsan<<setw(15)<<nds;
}
class quanli: public KH{
    public:
    KH kh[100];
    int n,m;
    int cau,sl,sluong,vot;
    string di;
    char san_status[31][5][5]; 
    void nhap();
    void hienthi();
    void themtt();
    void xoatt();
    void suatt();
    void dichvu();
    void ttsan();
 void capNhatTrangThaiSan(int, int, int, int);
    void hienThiTrangThaiSan(int);
    quanli();
 KH* timkiemKhachHang(const char* sdt); 
 void thongke();
};
void quanli::thongke(){
    int X,V;
    int U=0;
    for (int i=0;i<n;i++){
        cout<<"Tien san "<<kh[i].san<<": "<<kh[i].tgian*700<<" nghin dong"<<endl;
        V=kh[i].tgian*700;
        }; 
        if (di == "co"){
        for(int i=0;i<n;i++){
        cout<<"Tien dich vu san "<<kh[i].san<<endl;
        cout<<"Tien cau: "<<cau*10<<" nghin dong"<<endl;
        cout<<"Tien vot: "<<vot*50<<" nghin dong"<<endl;
        cout<<"Tien nuoc ngot: "<<sl*15<<" nghin dong"<<endl;
        cout<<"Tien nuoc khoang: "<<sluong*7<<" nghin dong"<<endl;
       X=cau*10+vot*50+sl*15+sluong*7;
       U=U+X+V;
    } 
}
    else{
        X=0;
        U=U+X+V;
    };
    cout<<"Tong doanh thu thang nay la: "<<U<<" nghin dong"<<endl;
}

KH* quanli::timkiemKhachHang(const char* sdt) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(kh[i].sdt, sdt) == 0) { //so sanh hai ki tu
            return &kh[i]; 
        }
    }
    return nullptr; 
}

quanli::quanli() {
    memset(san_status, ' ', sizeof(san_status)); 
}

void quanli::capNhatTrangThaiSan(int day, int san, int start, int duration) {
    for (int i = start - 16; i < (start - 16 + duration + 1); ++i) {
        san_status[day - 1][san - 1][i] = 'X';
    }
}
void quanli::hienThiTrangThaiSan(int day) {
    cout << "\nTrang thai cac san ngay " << day << " (16h-20h):" << endl;
    cout << "       16h 17h 18h 19h 20h" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "San " << i + 1 << "  ";
        for (int j = 0; j < 5; ++j) {
            cout << san_status[day - 1][i][j] << "   ";
        }
        cout << endl;
    }
}
void quanli::nhap(){
    cout<<"nhap so luong khach hang muon dat san:";cin>>n;
   haha: for (int i=0;i<n;i++){
        cout<<"\n nhap khach hang thu:"<<i+1<<"";
        kh[i].nhap();
        capNhatTrangThaiSan(kh[i].nds ,kh[i].san, kh[i].nsan, kh[i].tgian);
    };
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].msan == kh[j].msan) {
                cout<<"Ma san bi trung. Vui long nhap lai"<<endl;
                goto haha;
            } else {
                break;
            }
        }
    };
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].nds == kh[j].nds){
                if (kh[i].san == kh[j].san){
                    if((kh[i].nsan == kh[j].nsan)|| (kh[i].tsan == kh[j].nsan)||(kh[i].nsan == kh[j].tsan) ||(kh[i].tsan - 1 == kh[j].nsan)|| (kh[i].nsan + 1 == kh[j].nsan)){
                        cout<<"San da duoc dat vui long nhap lai"<<endl;
                        goto haha;
                    }else{
                        break;
                    }
                } else{
                    break;
                }
            } else {
                break;
            }
        }
    }
    }
  
void quanli::hienthi(){
    cout<<"\n Ho ten"<<setw(20)<<"so dien thoai"<<setw(10);
    cout<<"ma san"<<setw(5)<<"san"<<setw(15)<<"thoi gian thue"<<setw(15);
    cout<<"gio nhan"<<setw(15)<<"gio tra"<<setw(15)<<"ngay dat san";
    for (int i=0;i<n;i++){
        kh[i].hienthi();
    };
    if (di == "co"){
        for (int i=0;i<n;i++){
        cout<<endl<<"Ma san:"<<kh[i].msan<<endl;
cout<<"Cau: "<<cau<<endl;
cout<<"Vot: "<<vot<<endl;
cout<<"Nuoc ngot: "<<sl<<endl;
cout<<"Nuoc khoang: "<<sluong;
        }
    }
    }
    void quanli::themtt(){
        cout<<" ban da chon them thong tin. Vui long nhap:"<<endl;
        kh[n].nhap();
        capNhatTrangThaiSan(kh[n].nds, kh[n].san, kh[n].nsan, kh[n].tgian);
        n++;
        for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].msan == kh[j].msan) {
                cout<<"Ma san bi trung. Vui long nhap lai"<<endl;
                kh[n-1].nhap();
                capNhatTrangThaiSan(kh[n-1].nds, kh[n - 1].san, kh[n - 1].nsan, kh[n - 1].tgian);
            }
            else {
                break;
            }
    }}
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].nds == kh[j].nds){
                if (kh[i].san == kh[j].san){
                    if((kh[i].nsan == kh[j].nsan)or (kh[i].tsan == kh[j].nsan)or(kh[i].nsan == kh[j].tsan) or (kh[i].tsan - 1 == kh[j].nsan)or (kh[i].nsan + 1 == kh[j].nsan)){
                        cout<<"San da duoc dat vui long nhap lai"<<endl;
                        kh[n-1].nhap();
                capNhatTrangThaiSan(kh[n-1].nds, kh[n - 1].san, kh[n - 1].nsan, kh[n - 1].tgian);
                    }else{
                        break;
                    }
                } else{
                    break;
                }
            } else {
                break;
            }
        }
    }
    }
    void quanli::xoatt() {
    int msan;
    cout << "Nhap ma san cua khach hang can xoa: ";
    cin >> msan;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (kh[i].msan == msan) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < n - 1; ++i) {
            kh[i] = kh[i + 1];
        }
        n--;
        cout << "Khach hang voi ma san " << msan << " da duoc xoa." << endl;
    } else {
        cout << "Khong tim thay khach hang voi ma san " << msan << "." << endl;
    }
}
void quanli::suatt() {
    int msan;
    cout << "Nhap ma san cua khach hang can sua: ";
    cin >> msan;
    int index = -1;
    huhu: for (int i = 0; i < n; ++i) {
        if (kh[i].msan == msan) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cout << "Nhap thong tin moi cho khach hang:" << endl;
        kh[index].nhap();
        capNhatTrangThaiSan(kh[index].nds, kh[index].san, kh[index].nsan, kh[index].tgian);
        cout << "Thong tin khach hang voi ma san " << msan << " da duoc cap nhat." << endl;
    } else {
        cout << "Khong tim thay khach hang voi ma san " << msan << "." << endl;
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].msan == kh[j].msan) {
                cout<<"Ma san bi trung. Vui long nhap lai"<<endl;
                goto huhu;
            } else {
                break;
            }
        }
    };
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].nds == kh[j].nds){
                if (kh[i].san == kh[j].san){
                    if((kh[i].nsan == kh[j].nsan)or (kh[i].tsan == kh[j].nsan)or(kh[i].nsan == kh[j].tsan) or (kh[i].tsan - 1 == kh[j].nsan)or (kh[i].nsan + 1 == kh[j].nsan)){
                        cout<<"San da duoc dat vui long nhap lai"<<endl;
                        goto huhu;
                    }else{
                        break;
                    }
                } else{
                    break;
                }
            } else {
                break;
            }
        }
    }
}
void quanli::dichvu(){
int msan,douong; 
sluong=0;
sl=0;
cout<<"Ban co muon them dich vu khong: ";cin>>di;
if (di== "co"){
for (int i=0;i<n;i++) {
    cout<<"\n nhap khach hang thu:"<<i+1<<""<<endl;
    cout<<"nhap ma san cua khach hang: ";
    hehe:cin>>msan;
    if (kh[i].msan == msan) {
        cout<<"Nhap so luong cau khach hang muon thue: ";
        cin>>cau;cout<<endl;
        cout<<"Nhap so luong vot khach hang muon thue: ";
        cin>>vot;cout<<endl;
        cout<<"Khach hang muon chon do uong: "<<endl;
        cout<<"1. Nuoc khoang"<<endl;
        cout<<"2. Nuoc ngot"<<endl;
        cout<<"3. Ca hai"<<endl;
        cout<<"0. Khong chon"<<endl;
        cin>>douong;
        switch(douong){
        case 1:
            cout<<"Nhap so luong: ";
            cin>>sluong;
            break;
        case 2:
            cout<<"Nhap so luong: ";
            cin>>sl;
            break;
        case 3:
        cout<<"Nhap so luong nuoc khoang: ";
        cin>>sluong;
        cout<<"Nhap so luong nuoc ngot: ";
        cin>>sl;
        break;
        case 0:
        break;
        };
    }
 else {
    cout<<"Nhap sai ma san vui long nhap lai:";
    goto hehe;
}}
}}
void menu(){
    cout<<endl<<"==========================================================="<<"\n";
    cout<<"chao mung ban den voi Vu tru badminton. Ban muon"<<endl;
    cout<<"==========================================================="<<"\n";
    cout<<"1. Nhap thong tin khach hang"<<endl;
    cout<<"2. Hien thong tin khach hang"<<endl;
    cout<<"3. Them thong tin khach hang"<<endl;
    cout<<"4. Sua thong tin khach hang"<<endl;
    cout<<"5. Xoa thong tin khach hang"<<endl;
    cout<<"6. Xem tinh trang san"<<endl;
    cout<<"7. Thong ke doanh thu"<<endl;
    cout<<"8. Them dich vu cho khach hang"<<endl;
    cout<<"9. Tim kiem khach hang"<<endl;
    cout<<"0. Thoat"<<endl;  
}
int main(){
int day,g,msan;
string h;
quanli s1;
        while(true){
        menu();
        cin>>g;
        switch(g)
        {
            case 1:
            s1.nhap();
            break;
            case 2:
              s1.hienthi();
              cout<<endl;
              system("pause");
            break;
            case 3:
            s1.themtt();
            break;
            case 4:
            s1.suatt();
            break;
            case 5:
            s1.xoatt();
break;
case 6:
cout<<"Nhap ngay de xem tinh trang san: ";
cin>>day;
cout<<endl;
s1.hienThiTrangThaiSan(day);
system("pause");
break;
case 7:
s1.thongke();
system("pause");
break;
        case 8:
        s1.dichvu();
        break;
        case 9:
        {
                char sdt[20];
                cout << "Nhap so dien thoai khach hang muon tim: ";
                cin.ignore();
                cin.getline(sdt, 20);
                KH* khachhang = s1.timkiemKhachHang(sdt);
                if (khachhang) {
                    cout << "Khach hang tim thay:\n";
                    cout<<"\n Ho ten"<<setw(20)<<"so dien thoai"<<setw(10);
    cout<<"ma san"<<setw(5)<<"san"<<setw(15)<<"thoi gian thue"<<setw(15);
    cout<<"gio nhan"<<setw(15)<<"gio tra"<<setw(15)<<"ngay dat san";
                    khachhang->hienthi();
                    cout << endl;
                } else {
                    cout << "Khong tim thay khach hang voi so dien thoai " << sdt << endl;
                }
                system("pause");
                break;
            }
        case 0:
            return 0;
            }};
    }
