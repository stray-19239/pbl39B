#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
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
void KH::nhap(){
    cin.ignore(1);
    cout<<"\n nhap ho va ten:";cin.getline(hoten,20);fflush(stdin);
    cout<<"\n nhap so dien thoai: ";cin.getline(sdt,20);fflush(stdin);
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
    char San[31][5][5]; 
    int hang = 50;
    int hcau,hsl,hsluong,hvot;
    void nhap();
    void hienthi();
    void themtt();
    void xoatt();
    void suatt();
    void dichvu();
    void ttsan();
    void capnhatsan(int, int, int, int);
    void hienthisan(int);
    quanli();
    KH* timkhach(const char* sdt); 
    void thongke();
    void xuatfile();
    void kiemtrakho();
    void xcns(int, int, int, int);
    void xs(int, int, int, int);
};
void quanli::xs(int ngay, int san, int tgbd, int tgt){
     for(int i=tgbd-16;i<(tgbd-16+tgt+1);++i){
        San[ngay-1][san-1][i]= ' ';
    };
}
void quanli::xuatfile() {
    ofstream outfile("khachhang.txt");
    if (outfile.is_open()) {
        outfile << "\n Ho ten" << setw(20) << "so dien thoai" << setw(10)
                << "ma san" << setw(5) << "san" << setw(15) << "thoi gian thue" << setw(15)
                << "gio nhan" << setw(15) << "gio tra" << setw(15) << "ngay dat san" << endl;
        for (int i = 0; i < n; i++) {
            outfile << endl << "" << setw(10) << kh[i].hoten;
            outfile << "" << setw(11) << kh[i].sdt << setw(11) << kh[i].msan;
            outfile << "" << setw(10) << kh[i].san << setw(15) << kh[i].tgian << setw(15) << kh[i].nsan;
            int tsan = kh[i].tgian + kh[i].nsan;
            outfile << "" << setw(15) << tsan << setw(15) << kh[i].nds;
        }
        outfile.close();
        cout << "Da xuat thong tin khach hang ra file khachhang.txt." << endl;
    } else {
        cout << "Khong the mo file de ghi." << endl;
    }
}
void quanli::thongke(){
    int X,V;
    int U=0;
    int H=0;
    for (int i=0;i<n;i++){
        cout<<"Tien san "<<kh[i].san<<": "<<kh[i].tgian*700<<" nghin dong"<<endl;
        V=kh[i].tgian*700;
        H=H+V;
        }; 
        if (di == "co"){
        for(int i=0;i<n;i++){
        cout<<"Tien dich vu san "<<kh[i].san<<endl;
        cout<<"Tien cau: "<<cau*10<<" nghin dong"<<endl;
        cout<<"Tien vot: "<<vot*50<<" nghin dong"<<endl;
        cout<<"Tien nuoc ngot: "<<sl*15<<" nghin dong"<<endl;
        cout<<"Tien nuoc khoang: "<<sluong*7<<" nghin dong"<<endl;
       X=cau*10+vot*50+sl*15+sluong*7;
       U=U+X+H;
    } }else{
        X=0;
        U=U+X+H;
    };
    cout<<"Tong doanh thu thang nay la: "<<U<<" nghin dong"<<endl;
}

KH* quanli::timkhach(const char* sdt) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(kh[i].sdt, sdt) == 0) {
            return &kh[i]; 
        }
    }
    return nullptr; 
}

quanli::quanli() {
    memset(San, ' ', sizeof(San));
    hcau = hvot = hsl = hsluong = hang; 
}

void quanli::capnhatsan(int ngay, int san, int tgbd, int tgt) {
    for (int i = tgbd - 16; i < (tgbd - 16 + tgt + 1); ++i) {
        San[ngay - 1][san - 1][i] = 'X';
    }}
void quanli::xcns(int ngay, int san, int tgbd, int tgt){
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
    if(kh[i].nsan == kh[j].nsan){
        if(kh[i].tsan < kh[j].tsan){
        for (int i= tgbd-16+2;i<(tgbd-16+tgt+1);++i){
        San[ngay-1][san-1][i] = ' ';
        };
    }else{
        break;
    };
    break;
    };
    if (kh[i].tsan == kh[j].nsan){
    for (int i = tgbd - 16; i < (tgbd - 16 + tgt + 1); ++i){
        San[ngay - 1][san - 1][i+1]= ' ';
    };
    break;
    };
    if (kh[i].nsan == kh[j].tsan){
        for (int i = tgbd - 16; i < (tgbd-16+tgt);++i){
            San[ngay - 1][san - 1][i] = ' ';
        };
        break;
    };
     if(kh[i].nsan + 1 == kh[j].nsan){
        if(kh[i].tsan<kh[j].tsan){
            for (int i= tgbd-16+2;i<(tgbd-16+tgt+1);++i){
                San[ngay-1][san-1][i]= ' ';
            };
        }else {
            break;
        };
        break;
};
 if(kh[i].tsan == kh[j].tsan){
    for(int i=tgbd-16;i<(kh[i].nsan-kh[j].nsan);++i){
        San[ngay-1][san-1][i] = ' ';
    };
    break;
 };
 if(kh[i].nsan-1==kh[j].nsan){
    for(int i=tgbd-16;i<(tgbd-16+tgt+1);++i){
        San[ngay-1][san-1][i]= ' ';
    };
    for (int i=(kh[i].nsan-16);i<(kh[i].tsan-16+1);++i){
        San[ngay-1][san-1][i]= 'X';
    };
    break;
 };
 if(kh[j].tsan - 1 == kh[i].nsan){
    for(int i=tgbd-16;i<(tgbd-16+tgt+1);++i){
        San[ngay-1][san-1][i]= ' ';
    };
    for (int i=(kh[i].nsan-16);i<(kh[i].tsan-16+1);++i){
        San[ngay-1][san-1][i]= 'X';
    };
    break;
 };
if(kh[i].tsan - 1 == kh[j].nsan){
    for(int i=tgbd-16;i<(tgbd-16+tgt+1);++i){
        San[ngay-1][san-1][i]= ' ';
    };
    for (int i=(kh[i].nsan-16);i<(kh[i].tsan-16+1);++i){
        San[ngay-1][san-1][i]= 'X';
    };
    break;
};
 }
    }};
void quanli::hienthisan(int ngay) {
    cout << "\nTinh trang cac san ngay " << ngay << " (16h-20h):" << endl;
    cout << "       16h 17h 18h 19h 20h" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "San " << i + 1 << "  ";
        for (int j = 0; j < 5; ++j) {
            cout << San[ngay - 1][i][j] << "   ";
        }
        cout << endl;
    }
}
void quanli::nhap(){
    cout<<"nhap so luong khach hang muon dat san:";cin>>n;
   haha: for (int i=0;i<n;i++){
        cout<<"\n nhap khach hang thu:"<<i+1<<"";
        kh[i].nhap();
        capnhatsan(kh[i].nds ,kh[i].san, kh[i].nsan, kh[i].tgian);
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
                 if((kh[i].nsan == kh[j].nsan)or (kh[i].tsan == kh[j].nsan)or(kh[i].nsan == kh[j].tsan)or (kh[j].tsan - 1 == kh[i].nsan)or (kh[j].nsan + 1 == kh[i].nsan) or (kh[i].tsan - 1 == kh[j].nsan)or (kh[i].nsan + 1 == kh[j].nsan)){
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
        capnhatsan(kh[n].nds, kh[n].san, kh[n].nsan, kh[n].tgian);
        n++;
        for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].msan == kh[j].msan) {
                cout<<"Ma san bi trung. Vui long nhap lai"<<endl;
                kh[n-1].nhap();
                capnhatsan(kh[n-1].nds, kh[n - 1].san, kh[n - 1].nsan, kh[n - 1].tgian);
            }
            else {
                break;
            }
    }}
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (kh[i].nds == kh[j].nds){
                if (kh[i].san == kh[j].san){
                    if((kh[i].nsan == kh[j].nsan)or (kh[i].tsan == kh[j].nsan)or(kh[i].nsan == kh[j].tsan)or (kh[j].tsan - 1 == kh[i].nsan)or (kh[j].nsan + 1 == kh[i].nsan) or (kh[i].tsan - 1 == kh[j].nsan)or (kh[i].nsan + 1 == kh[j].nsan)){
                        cout<<"San da duoc dat vui long nhap lai"<<endl;
                         xcns(kh[n-1].nds, kh[n-1].san, kh[n-1].nsan, kh[n-1].tgian);
                         kh[n-1].nhap();
                         capnhatsan(kh[n-1].nds, kh[n-1].san, kh[n-1].nsan, kh[n-1].tgian);
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
         xs(kh[index].nds, kh[index].san, kh[index].nsan, kh[index].tgian);
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
        capnhatsan(kh[index].nds, kh[index].san, kh[index].nsan, kh[index].tgian);
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
                    if((kh[i].nsan == kh[j].nsan)or (kh[i].tsan == kh[j].nsan)or(kh[i].nsan == kh[j].tsan)or (kh[j].tsan - 1 == kh[i].nsan)or (kh[j].nsan + 1 == kh[i].nsan) or (kh[i].tsan - 1 == kh[j].nsan)or (kh[i].nsan + 1 == kh[j].nsan)){
                        cout<<"San da duoc dat vui long nhap lai"<<endl;
                        xcns(kh[index].nds, kh[index].san, kh[index].nsan, kh[index].tgian);
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
       h: cout<<"Nhap so luong cau khach hang muon thue: ";
        cin>>cau;
        if (cau > hcau){
            cout<<"Khong con du cau cho khach thue."<<"Chi con lai "<<hcau<<"qua cau"<<" Hay lay so luong it hon";
            goto h;
        } else  {
            hcau= hcau - cau;
        };
        cout<<endl;
       k: cout<<"Nhap so luong vot khach hang muon thue: ";
        cin>>vot;
         if (vot > hvot){
            cout<<"Khong con du vot cho khach thue."<<"Chi con lai "<<hvot<<"vot"<<" Hay lay so luong it hon";
            goto k;
        } else  {
            hvot= hvot - vot;
        };
        cout<<endl;
        cout<<"Khach hang muon chon do uong: "<<endl;
        cout<<"1. Nuoc khoang"<<endl;
        cout<<"2. Nuoc ngot"<<endl;
        cout<<"3. Ca hai"<<endl;
        cout<<"0. Khong chon"<<endl;
        cin>>douong;
        switch(douong){
        case 1:
          j:  cout<<"Nhap so luong: ";
            cin>>sluong;
             if (sluong > hsluong){
            cout<<"Khong con du nuoc khoang."<<"Chi con lai "<<hsluong<<"chai nuoc khoang "<<" Hay lay so luong it hon";
            goto j;
        } else  {
            hsluong= hsluong - sluong;
        };
            break;
        case 2:
           p: cout<<"Nhap so luong: ";
            cin>>sl;
                if (sl > hsl){
            cout<<"Khong con du nuoc ngot."<<"Chi con lai "<<hsl<<"chai nuoc ngot "<<" Hay lay so luong it hon";
            goto p;
        } else  {
            hsl= hsl - sl;
        };
            break;
        case 3:
       t: cout<<"Nhap so luong nuoc khoang: ";
        cin>>sluong;
             if (sluong > hsluong){
            cout<<"Khong con du nuoc khoang."<<"Chi con lai "<<hsluong<<"chai nuoc khoang "<<" Hay lay so luong it hon";
            goto t;
        } else  {
            hsluong= hsluong - sluong;
        };
       w: cout<<"Nhap so luong nuoc ngot: ";
        cin>>sl;
              if (sl > hsl){
            cout<<"Khong con du nuoc ngot."<<"Chi con lai "<<hsl<<"chai nuoc ngot "<<" Hay lay so luong it hon";
            goto w;
        } else  {
            hsl= hsl - sl;
        };
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
void quanli::kiemtrakho(){
    string m;
    int j,k,l,s;
    cout<<"Kho luu tru cua Vu tru badminton"<<endl;
    cout<<"So luong cau trong kho: "<<hcau<<endl;
    cout<<"So luong vot trong kho: "<<hvot<<endl;
    cout<<"So luong nuoc ngot trong kho: "<<hsl<<endl;
    cout<<"So luong nuoc khoang trong kho: "<<hsluong<<endl;
    cout<<"Ban co muon nhap them hang vao kho khong"<<endl;
    cin>>m;
    if (m == "co"){
        cout<<"Nhap so luong cau muon them: ";cin>>j;cout<<endl;
        hcau=hcau+j;
        cout<<"Nhap so luong vot muon them: ";cin>>k;cout<<endl;
        hvot=hvot+k;
        cout<<"Nhap so luong nuoc ngot muon them: ";cin>>l;cout<<endl;
        hsl=hsl+l;
        cout<<"Nhap so luong nuoc khoang muon them: ";cin>>s;cout<<endl;
        hsluong=hsluong+s;
        cout<<"Kho luu tru cua vu tru badminton sau khi nhap them hang"<<endl;
        cout<<"So luong cau trong kho: "<<hcau<<endl;
        cout<<"So luong vot trong kho: "<<hvot<<endl;
        cout<<"So luong nuoc ngot trong kho: "<<hsl<<endl;
        cout<<"So luong nuoc khoang trong kho: "<<hsluong<<endl;
    }
}
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
    cout<<"10. Xuat file thong tin khach hang"<<endl;
    cout<<"11. Kiem tra kho luu tru"<<endl;
    cout<<"0. Thoat"<<endl;  
}
int main(){
int ngay,g,msan;
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
             system("pause");
            break;
            case 4:
            s1.suatt();
             system("pause");
            break;
            case 5:
            s1.xoatt();
             system("pause");
            break;
            case 6:
            cout<<"Nhap ngay de xem tinh trang san: ";
            cin>>ngay;
            cout<<endl;
            s1.hienthisan(ngay);
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
                KH* khachhang = s1.timkhach(sdt);
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
            case 10:
            s1.xuatfile();
            system("pause");
            break;
            case 11:
            s1.kiemtrakho();
            system("pause");
            break;
            case 0:
            return 0;
            }};
    }
