#include <iostream>
#include <fstream>

using namespace std;

class student{
protected:
    int no,kayitY,tempS;    string tel;
    string ad,soyad,bolum,eposta;

public:

    void setstudent(int nu,int kyt,string tlf,string ism,string syad,string blum,string posta){
        no=nu;  kayitY=kyt; tel=tlf;  ad=ism; soyad=syad; bolum=blum; eposta=posta;
    }
    void print(){
        cout<<tel<<endl;
    }

};

class acedemician{
protected:
    int sicilno,tempA;  string tel;
    string ad,soyad,dal,eposta,unvan;
public:
    void setacedemician(int nu,string tlf,string ism,string syad,string blum,string posta,string unvn){
        sicilno=nu;  tel=tlf;  ad=ism; soyad=syad; dal=blum; eposta=posta;  unvan=unvn;
    }

    void print(){
        cout<<tel<<endl;
    }


};


class date:public student , acedemician {
private:
    int ogrno,akdmsynno,baslngc,sure;
    string tarih;
public:
    void setdate(int ogr,int akdmsyn,string trh,int saat,int sire){
        ogrno=ogr;  akdmsynno=akdmsyn;  tarih=trh;  baslngc=saat;   sure=sire;

    }

    int getogrno(){
        return ogrno;
    }
    int getakdmsynno(){
        return akdmsynno;
    }
    int getbaslangic(){
        return baslngc;
    }
    int getsure(){
        return sure;
    }
    string gettarih(){
        return tarih;
    }



    void print(){
        cout<<ogrno<<"   "<<akdmsynno<<"    "
        <<tarih<<"   "<<baslngc<<"    "<<sure<<endl;
    }

};


int main()
{
    student mevcutS[50];
    acedemician mevcutA[30];
    date mevcutD[50];

        fstream dosyaS,dosyaA,dosyaD;
        dosyaS.open("ogrenci.txt",ios::in);
        dosyaA.open("akademisyen.txt",ios::in);
        dosyaD.open("randevu.txt",ios::in);
        int numra,aknumra,trhsi,sursi,tempS=0,tempA=0,tempD=0;
        string tlfsi;
        string ismisi,syismisi,mslk,psta,unvn;
        for(;!dosyaS.eof();tempS++){
            dosyaS>>numra;  dosyaS>>ismisi;  dosyaS>>syismisi;
            dosyaS>>mslk;  dosyaS>>trhsi;  dosyaS>>psta;  dosyaS>>tlfsi;
            mevcutS[tempS].setstudent(numra,trhsi,tlfsi,ismisi,syismisi,mslk,psta);
        }
        for(;!dosyaA.eof();tempA++){
            dosyaA>>numra;  dosyaA>>ismisi;  dosyaA>>syismisi;
            dosyaA>>mslk;   dosyaA>>psta;  dosyaA>>tlfsi;   dosyaA>>unvn;
            mevcutA[tempA].setacedemician(numra,tlfsi,ismisi,syismisi,mslk,psta,unvn);
        }
        for(;!dosyaD.eof();tempD++){
            dosyaD>>numra;  dosyaD>>aknumra;  dosyaD>>syismisi;
            dosyaD>>trhsi;  dosyaD>>sursi;
            mevcutD[tempD].setdate(numra,aknumra,syismisi,trhsi,sursi);
            //mevcutD[tempD].print();
        }

    int islem=0;
    do{
        cout<< "1.Ogrenci ekle"<<endl
            << "2.Akademisyen ekle" <<endl
            << "3.Randevu al" <<endl
            << "4.Randevulari goster"<<endl
            << "0.Programi sonlandir" <<endl<<endl;
        cout<<"Isleminiz: ";  cin>>islem; cout<<endl;


   switch (islem){
        case 1:{
            int no,kayitY;  string tel;
            string ad,soyad,bolum,eposta;
            cout<<"Ogrencinin nosu: ";   cin>>no;
            cout<<"Ogrencinin adi: ";   cin>>ad;
            cout<<"Ogrencinin soyadi: ";   cin>>soyad;
            cout<<"Ogrencinin bolumu: ";   cin>>bolum;
            cout<<"Ogrencinin kayit yili: ";   cin>>kayitY;
            cout<<"Ogrencinin telnosu: ";   cin>>tel;
            cout<<"Ogrencinin epostasi: ";   cin>>eposta;
            mevcutS[tempS].setstudent(no,kayitY,tel,ad,soyad,bolum,eposta); tempS++;
            ofstream dosya;
            dosya.open("ogrenci.txt",ios::out|ios::app);
            dosya<<no<<"    "<<ad<<"    "<<soyad<<"    "<<bolum<<"    "<<kayitY<<"    "<<eposta<<"    "<<tel<<endl;
            dosya.close();
        break;
        }

        case 2:{
            int sicilno;  string tel;
            string ad,soyad,dal,eposta,unvan;
            cout<<"Akademisyenin sicilnosu: ";   cin>>sicilno;
            cout<<"Akademisyenin adi: ";   cin>>ad;
            cout<<"Akademisyenin soyadi: ";   cin>>soyad;
            cout<<"Akademisyenin dali: ";   cin>>dal;
            cout<<"Akademisyenin unvani: ";   cin>>unvan;
            cout<<"Akademisyenin telnosu: ";   cin>>tel;
            cout<<"Akademisyenin epostasi: ";   cin>>eposta;
            mevcutA[tempA].setacedemician(sicilno,tel,ad,soyad,dal,eposta,unvan);    tempA++;
            ofstream dosya;
            dosya.open("akademisyen.txt",ios::out|ios::app);
            dosya<<sicilno<<"    "<<ad<<"    "<<soyad<<"    "<<dal<<eposta<<"    "<<"    "<<tel<<"    "<<unvan<<endl;
            dosya.close();
        break;
        }

        case 3:{
            int ogrno,akdmsynno,baslngc,sure;
            string tarih;
            do{
                cout<<endl;
                cout<<"Ogrenci no: ";   cin>>ogrno;
                cout<<"Akademisyenin sicilnosu: ";   cin>>akdmsynno;
                cout<<"Randevu tarihi: ";   cin>>tarih;
                cout<<"Baslangic saati: ";   cin>>baslngc;
                cout<<"Randevu susresi(dk): ";   cin>>sure;
                mevcutD[tempD].setdate(ogrno,akdmsynno,tarih,baslngc,sure);
                bool sonuc=true;
                for(int i=0;i<tempD;i++){
                    if((mevcutD[tempD].getakdmsynno()==mevcutD[i].getakdmsynno())&&(mevcutD[tempD].gettarih()==mevcutD[i].gettarih())&&
                       (((mevcutD[tempD].getbaslangic()<mevcutD[i].getbaslangic()+mevcutD[i].getsure())&&
                         (mevcutD[tempD].getbaslangic()+mevcutD[tempD].getsure()>mevcutD[i].getbaslangic()))||
                       ((mevcutD[tempD].getbaslangic()>mevcutD[i].getbaslangic()+mevcutD[i].getsure())&&
                        (mevcutD[tempD].getbaslangic()+mevcutD[tempD].getsure()<mevcutD[i].getbaslangic()))))
                    {
                        cout<<"Belirtilen akademisyen istenilen tarih ve saatte müsait degildir."<<endl
                        <<"Lutfen baska tarih ve/veya saat belirtiniz.";
                        sonuc=false;    break;
                    }
                    if((mevcutD[tempD].getogrno()==mevcutD[i].getogrno())&&(mevcutD[tempD].gettarih()==mevcutD[i].gettarih())&&
                       (((mevcutD[tempD].getbaslangic()<mevcutD[i].getbaslangic()+mevcutD[i].getsure())&&
                         (mevcutD[tempD].getbaslangic()+mevcutD[tempD].getsure()>mevcutD[i].getbaslangic()))||
                       ((mevcutD[tempD].getbaslangic()>mevcutD[i].getbaslangic()+mevcutD[i].getsure())&&
                        (mevcutD[tempD].getbaslangic()+mevcutD[tempD].getsure()<mevcutD[i].getbaslangic()))))
                    {
                        cout<<"Belirtilen ogrenci istenilen saatte müsait degildir."<<endl
                        <<"Lutfen baska tarih ve/veya saat belirtiniz.";
                        sonuc=false;    break;
                    }
                }
                if(sonuc){
                    tempD++;
                    ofstream dosya;
                    dosya.open("randevu.txt",ios::out|ios::app);
                    dosya<<ogrno<<"    "<<akdmsynno<<"    "<<tarih<<"    "<<baslngc<<"    "<<sure<<endl;
                    dosya.close();
                    break;
                }
            }while(true);
        break;
        }

        case 4:{
            for(int i=0;i<tempD;i++){
                mevcutD[i].print();
            }
        break;
        }

        default:{
            if(islem!=0)
            cout<<"Hatali islem tekrar deneyiniz.";
        }

   }
}while(islem!=0);
    return 0;
}
