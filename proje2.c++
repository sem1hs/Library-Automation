#include <iostream> // Girdi-Çıktı İşlemleri İçin
#include <fstream> // Dosya İşlemleri İçin
#include <iomanip> // setw() (Görüntü) İçin
#include <string> // String Değerler İçin
using namespace std;

struct ogrenciler
{
    string ogrenci1; // Ad
    string ogrenci2; // SoyAd
    string ogrenci3; // Öğrenci Ad Test 
    string ogrenci4; // Öğrenci SoyAd Test 
    string ogrenci5; // Göstermek İçin
    string ogrenci6; // Göstermek İçin
    int numara; // Numara
    int numara1; // Numara Test
} ogrenci[5];

struct giris
{
    string g1; // Kullanıcı Adı
    int g2; // Şifre 
    string g3; // Test Kullanıcı Adı
    int g4; // Test Şifre 
} kullanici[5];

struct kitaplar
{
    string k1; // Kitap Adı
    string k2; // Yazar Adı
    string k3; // Kitap Göster
    int id; // Kitap ID
    int id1; // Test ID
    int durum; // Kitap Durumu (0 İse Başvurulabilir Veya Atanabilir, 1 İse Atanmış , 2 İse Başvurulmuş)
} kitap[5];

void kitap_basvuru()
{
    cout << "Kitaplar" <<endl;
    cout << endl;
    fstream file; // File Dosyası Oluşturuldu 
    file.open("Kitaplar_Yazarlar_ID.txt",ios::in); // File Dosyasını Açtı , Ona İsim Verdi (txt Olarak) Ve Okuma Biçimini Girdi(ios::in)
    cout << "Numara" << setw(15) << "Kitap Adı" << setw(12) << "Yazar" << setw(15) << "Durum" <<endl;
    while(getline(file,kitap[1].k3)) // File Dosyasındaki Her Satırı Sağdaki Değere Atıyor
    {
        cout << "" <<kitap[1].k3<<endl;
    }
    file.close(); // File Dosyasını Kapattı
    cout << endl;
    cout << "Lütfen Başvurmak İstediğiniz Kitabın Numarasını Yazınız = ";   
    cin >> kitap[1].id;

    fstream file1; // File Dosyası Oluşturuldu 
    file1.open("Kitaplar_Yazarlar_ID.txt",ios::in); // File Dosyasını Açtı , Ona İsim Verdi (txt Olarak) Ve Okuma Biçimini Girdi(ios::in)
    while(!(file1.eof())) // File Dosyasının Sonuna Kadar Gidiyor (eof() = End Of File) 
    {
        file1 >> kitap[1].id1 >> kitap[1].k1 >> kitap[1].k2 >> kitap[1].durum;
        if(kitap[1].id == kitap[1].id1)
        {
            if(kitap[1].durum == 1 || kitap[1].durum == 2)
            {
                cout << "Bu Kitaba Başvuru Yapılamaz..."<<endl;
                cout <<endl;
            }
            else
            {
                cout << "Başvuru Başarıyla Gerçekleşti..." <<endl;
                cout <<endl;

                fstream file3; // File Dosyası Oluşturuldu 
                fstream file4; // File Dosyası Oluşturuldu 
                file3.open("Kitaplar_Yazarlar_ID.txt",ios::in); // File Dosyasını Açtı , Ona İsim Verdi (txt Olarak) Ve Okuma Biçimini Girdi(ios::in)
                file4.open("Gecici.txt",ios::app|ios::out); // File Dosyasını Açtı , Ona İsim Verdi (txt Olarak) Ve Yazma Biçimini Girdi(ios::out) (ios::app = Cümlenin Sonuna Kelime Ekliyor)
                while(!file3.eof()) // File Dosyasının Sonuna Kadar Gidiyor (eof() = End Of File) 
                {
                    file3 >> kitap[1].id1 >> kitap[1].k1 >> kitap[1].k2 >> kitap[1].durum;
                    // File Dosyasındaki Her Değişkeni Yukardaki Değişkene Atıyor 
                    if(kitap[1].id == kitap[1].id1)
                    {
                        continue;
                        // Eğer ID Tutarsa Hiçbir İşlem Gerçekleşmiyor 
                    }
                    else 
                    {
                        file4 << kitap[1].id1 << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) << kitap[1].durum;
                        file4 <<endl;
                        // ID Tutmazsa Değişkenler Geçici Dosyasına Yazılıyor 
                    }
                }
                file3.close(); // File Dosyasını Kapattı
                file4.close(); // File Dosyasını Kapattı
                remove("Kitaplar_Yazarlar_ID.txt"); // Eski Dosyayı Kaldırdı
                rename("Gecici.txt","Kitaplar_Yazarlar_ID.txt"); // Girdiğiniz ID Dışındaki Tüm Değişkenleri İlk Önce Geçici Dosyasına Yazdı Daha Sonra O Dosyanın İsmini Eski Dosya İsmi Yaptı Böylece Girdiğiniz ID Silinmiş Oldu
                
                kitap[1].durum = 2;
                fstream file2; // File Dosyası Oluşturuldu 
                file2.open("Kitaplar_Yazarlar_ID.txt",ios::app|ios::out); // File Dosyasını Açtı , Ona İsim Verdi (txt Olarak) Ve Yazma Biçimini Girdi(ios::out) (ios::app = Cümlenin Sonuna Kelime Ekliyor)
                file2 << kitap[1].id1 << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) << kitap[1].durum;
                file2 <<endl; 
                file2.close(); // File Dosyasını Kapattı
                // İlk Önce Silme İşlemini Gerçekleştirdik Daha Sonra Girdiğiniz ID'deki Bilgileri Tekrar Dosyaya Yazdırıp ID sini Güncelledik
                break;
            }
        }
        else 
        {
            cout << "Lütfen Tekrar Deneyiniz..." <<endl;
            cout <<endl;
        }
    }
    file1.close();
}
void kitap_iade()
{
    cout << "Kitaplar" <<endl;
    cout << endl;
    fstream file;
    file.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    cout << "Numara" << setw(15) << "Kitap Adı" << setw(12) << "Yazar" << setw(15) << "Durum" <<endl;
    while(getline(file,kitap[1].k3))
    {
        cout << "" <<kitap[1].k3<<endl;
    }
    file.close();
    cout << endl;

    cout << "Lütfen İade Etmek İstediğiniz Kitabın Numarasını Yazınız = ";
    cin >> kitap[1].id;

    fstream file1;
    file1.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    while(!(file1.eof()))
    {
        file1 >> kitap[1].id1 >> kitap[1].k1 >> kitap[1].k2 >> kitap[1].durum;
        if(kitap[1].id == kitap[1].id1)
        {
            if(kitap[1].durum!= 2)
            {   
                cout << "İade İşlemi Başarısız..." <<endl;
                cout <<endl;
            }
            else 
            {   
                cout << "İade İşlemi Başarılı..."<<endl;
                cout << endl;
                fstream file3;
                fstream file4;
                file3.open("Kitaplar_Yazarlar_ID.txt",ios::in);
                file4.open("Gecici.txt",ios::app|ios::out);
                while(!file3.eof())
                {
                    file3 >> kitap[1].id1 >> kitap[1].k1 >> kitap[1].k2 >> kitap[1].durum;
                    if(kitap[1].id == kitap[1].id1)
                    {
                        continue;
                    }
                    else 
                    {
                        file4 << kitap[1].id1 << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) << kitap[1].durum;
                        file4 <<endl;
                    }
                }
                file3.close();
                file4.close();
                remove("Kitaplar_Yazarlar_ID.txt");
                rename("Gecici.txt","Kitaplar_Yazarlar_ID.txt");

                kitap[1].durum = 0;
                fstream file2;
                file2.open("Kitaplar_Yazarlar_ID.txt",ios::app|ios::out);
                file2 << kitap[1].id1 << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) << kitap[1].durum;
                file2 <<endl;
                file2.close();
                break;
            }
        }
        else
        {
            cout << "Lütfen Tekrar Deneyiniz..."<<endl;
            cout << endl;
        }
    }
    file1.close();
}

void kitap_ekle()
{
    cout << "Lütfen Eklemek İstediğiniz Kitabın Adını Giriniz = ";
    cin >> kitap[1].k1;
    cout << "Lütfen Yazar Adını Giriniz = ";
    cin >> kitap[1].k2;
    cout << "Lütfen Kitabın Numarasını Giriniz = ";
    cin >> kitap[1].id;

    kitap[1].durum = 0;

    fstream file;
    fstream file1;
    file.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    file1.open("Kitaplar_Yazarlar_ID.txt",ios::app|ios::out);
    while(!(file.eof()))
    {
        file >> kitap[1].id1;

        if(kitap[1].id == kitap[1].id1)
        {
            cout << "Lütfen Başka ID Kullanın..."<<endl;
            cout << endl;
        }
        else
        {   
            cout << "Kitap Başarıyla Eklenmiştir..."<<endl;
            cout << endl;
            file1 << kitap[1].id << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) <<kitap[1].durum;
            file1 <<endl;
            break;
        }
    }
    file.close();
    file1.close();

}
void kitap_goster()
{   
    cout << "Kitaplar" <<endl;
    cout << endl;
    fstream file;
    file.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    cout << "Numara" << setw(15) << "Kitap Adı" << setw(12) << "Yazar" << setw(15) << "Durum" <<endl;
    while(getline(file,kitap[1].k3))
    {
        cout << "" <<kitap[1].k3<<endl;
    }
    file.close();
    cout << endl;
}
void kitap_sil()
{
    int a,b;
    fstream file;
    file.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    cout << "Numara" << setw(15) << "Kitap Adı" << setw(12) << "Yazar" << setw(15) << "Durum"<<endl;

    while(getline(file,kitap[1].k3))
    {
        cout << "" <<kitap[1].k3<<endl;
    }
    file.close();
    cout << endl<<"Lütfen Silmek İstediğiniz Kitabın ID'sini Yazınız = ";
    cin >> a;
    fstream file1;
    fstream file2;
    file1.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    file2.open("Gecici.txt",ios::app|ios::out);
    while(!file1.eof())
    {
        file1 >> kitap[2].id >> kitap[2].k1 >> kitap[2].k2 >> kitap[2].durum;
        if(kitap[2].id==a)
        {
            cout << "Kitap Silme İşlemi Başarılı...";
            cout <<endl;
        }
        else 
        {
            file2 << kitap[2].id << setw(15) << kitap[2].k1 << setw(15) << kitap[2].k2 << setw(15) << kitap[2].durum;
            file2 <<endl;
        }
    }
    file1.close();
    file2.close();
    remove("Kitaplar_Yazarlar_ID.txt");
    rename("Gecici.txt","Kitaplar_Yazarlar_ID.txt");

}
void kitap_ata()
{
    int a,b;
    fstream file2;
    file2.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    cout << "Numara" << setw(15) << "Kitap Adı" << setw(12) << "Yazar" << "Durum"<<endl;
    cout <<endl;
    while(getline(file2,kitap[1].k3))
    {
        cout << "" <<kitap[1].k3<<endl;
    }
    file2.close();
    cout << endl<<"Lütfen Atamak İstediğiniz Kitabın ID'sini Yazınız = ";
    cin >>a;
    
    fstream file;
    file.open("Ogrenciler.txt",ios::in);
    cout << "Ad" << setw(10) << "SoyAd" << setw(10) << "Numara";
    cout <<endl;
    while(getline(file,ogrenci[1].ogrenci5))
    {
        cout << "" << ogrenci[1].ogrenci5 << endl;
    }
    file.close();
    cout <<endl<< "Lütfen Atamak İstediğiniz Öğrencinin Numarasını Yazınız = ";
    cin >> b;
    
    fstream file1;
    fstream file3;
    file1.open("Kitaplar_Yazarlar_ID.txt",ios::in);
    file3.open("Ogrenciler.txt",ios::in);
    while(!(file1.eof()) && !(file3.eof()))
    {
        file1 >> kitap[1].id1 >> kitap[1].k1 >> kitap[1].k2 >> kitap[1].durum;
        file3 >> ogrenci[1].ogrenci1 >> ogrenci[1].ogrenci2 >> ogrenci[1].numara1;

        if(a==kitap[1].id1 && b == ogrenci[1].numara1)
        {
            if(kitap[1].durum==1 || kitap[1].durum==2)
            {
                cout << "Bu Başkasına Atanmıştır..."<<endl;
                cout <<endl;
            }
            else
            {
                cout << "Kitap Atama İşlemi Başarılı..." << endl;
                fstream file3;
                fstream file4;
                file3.open("Kitaplar_Yazarlar_ID.txt",ios::in);
                file4.open("Gecici.txt",ios::app|ios::out);
                while(!file3.eof())
                {
                    file3 >> kitap[1].id1 >> kitap[1].k1 >> kitap[1].k2 >> kitap[1].durum;
                    if(kitap[1].id == kitap[1].id1)
                    {
                        continue;
                    }
                    else 
                    {
                        file4 << kitap[1].id1 << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) << kitap[1].durum;
                        file4 <<endl;
                    }
                }
                file3.close();
                file4.close();
                remove("Kitaplar_Yazarlar_ID.txt");
                rename("Gecici.txt","Kitaplar_Yazarlar_ID.txt");

                kitap[1].durum = 1;
                fstream file5;
                file5.open("Kitaplar_Yazarlar_ID.txt",ios::app|ios::out);
                file5 << kitap[1].id1 << setw(15) << kitap[1].k1 << setw(15) << kitap[1].k2 << setw(15) << kitap[1].durum;
                file5 <<endl;
                file5.close();
                break;
            }
        }
        else 
        {
            cout << "Lütfen Tekrar Deneyiniz..."<<endl;
            cout <<endl;
        }
    }
    file1.close();
    file3.close();
}
void ogrenci_goster()
{
    cout << "Öğrenciler" <<endl;
    cout << endl;
    cout << "Ad" << setw(15) << "SoyAd" << setw(15) << "Numara"<<endl;
    fstream file;
    fstream file1;
    file1.open("Öğrenci_Kayıtları.txt",ios::in);
    file.open("Ogrenciler.txt",ios::in);
    while(getline(file,ogrenci[1].ogrenci5) && getline(file1,ogrenci[1].ogrenci6))
    {
        cout << "" << ogrenci[1].ogrenci5<<endl;
        cout << "" << ogrenci[1].ogrenci6;
    }
    file.close();
    file1.close();
    cout <<endl;
}
void ogrenci_ekle()
{
    cout << "Lütfen Eklemek İstediğiniz Öğrencinin Adını Giriniz = ";
    cin >> ogrenci[1].ogrenci1;
    cout << "Lütfen Eklemek İstediğiniz Öğrencinin SoyAdını Giriniz = ";
    cin >> ogrenci[1].ogrenci2;
    cout << "Lütfen Eklemek İstediğiniz Öğrencinin Numarasını Giriniz = ";
    cin >> ogrenci[1].numara;

    fstream file;
    fstream file1;
    file.open("Ogrenciler.txt",ios::in);
    file1.open("Ogrenciler.txt",ios::app|ios::out);

    while(!(file.eof()))
    {
        file >> ogrenci[1].ogrenci3 >> ogrenci[1].ogrenci4 >> ogrenci[1].numara1;
        if(ogrenci[1].ogrenci3 != ogrenci[1].ogrenci1 && ogrenci[1].ogrenci4 != ogrenci[1].ogrenci2 && ogrenci[1].numara1 != ogrenci[1].numara)
        {   
            cout << "Öğrenci Ekleme İşlemi Başarılı..."<<endl;
            cout <<endl;
            file1 << ogrenci[1].ogrenci1 << setw(10) << ogrenci[1].ogrenci2 << setw(10) << ogrenci[1].numara;
            file1 <<endl;
            break;
        }
        else 
        {
            cout << "Böyle Bir Öğrenci Bulunmaktadır,Lütfen Bilgileri Tekrar Giriniz " <<endl;
        }
    }
    file.close();
    file1.close();
    cout<< endl;
}

int menu1()
{
    int secim;
    cout << "1 - Kitap Ekle " << endl << "2 - Kitapları Göster " << endl << "3 - Kitap Kaldır " << endl << "4 - Kitap Ata " << endl << "5 - Öğrencileri Göster " << endl <<  "6 - Öğrenci Ekle " << endl<< "0 - Ana Menüye Dön"<<endl; 
    cin >> secim;
    return secim;
}

int menu2()
{
    int secim;
    cout << "1 - Kitapları Göster " << endl << "2 - Kitap Başvuru " << endl << "3 - Kitap İade " << endl << "0 - Ana Menüye Dön"<<endl; 
    cin >> secim;
    return secim;
}

void giris()
{
    int secim;
    cout << "Giriş Ekranına Hoş Geldiniz..."<<endl;
    cout << "1 - Yönetici Giriş " << endl << "2 - Öğrenci Giriş " <<endl<< "0 - Ana Menüye Dön " <<endl;
    cin >> secim;
    int secim1;
    int secim2;
    while(secim!=0)
    {
        switch(secim)
        {
            case 1: 
            {
                cout << "Kullanıcı Adı = ";
                cin >> kullanici[3].g1;
                cout << "Şifre = ";
                cin >> kullanici[3].g2;

                fstream file;
                file.open("Yönetici_Kayıtları.txt",ios::in);
                while(!(file.eof()))
                {
                    file >> kullanici[3].g3 >> kullanici[3].g4;

                    if(kullanici[3].g3==kullanici[3].g1 && kullanici[3].g4 == kullanici[3].g2)
                    {
                        cout << "Başarıyla Giriş Yaptınız..."<<endl<<endl;
                        int secim1 = menu1();
                        while(secim1!=0)
                        {
                            switch(secim1)
                            {
                                case 1:
                                {
                                    kitap_ekle();
                                    break;
                                }
                                case 2:
                                {
                                    kitap_goster();
                                    break;
                                }
                                case 3:
                                {
                                    kitap_sil();
                                    break;
                                }
                                case 4:
                                {
                                    kitap_ata();
                                    break;
                                }
                                case 0:
                                {
                                    break;
                                }
                                case 5:
                                {
                                    ogrenci_goster();
                                    break;
                                }
                                case 6:
                                {
                                    ogrenci_ekle();
                                    break;
                                }
                                default:
                                {
                                    cout << "Lütfen Geçerli Bir Sayı Giriniz... "<<endl;
                                    cout <<endl;
                                    break;
                                }
                            }
                            secim1=menu1();
                        }
                        break;
                    }
                    else 
                    {
                        cout << "Bilgileriniz Kontrol Ediliyor..."<<endl;
                        cout <<endl;
                    }
                }
                file.close();
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "Kullanıcı Adı = ";
                cin >> kullanici[4].g1;
                cout << "Şifre = ";
                cin >> kullanici[4].g2;
                fstream file;
                file.open("Öğrenci_Kayıtları.txt",ios::in);
                while(!(file.eof()))
                {
                    file >> kullanici[4].g3 >> kullanici[4].g4;
                    if(kullanici[4].g3==kullanici[4].g1 && kullanici[4].g4 == kullanici[4].g2)
                    {
                        cout << "Başarıyla Giriş Yaptınız..."<<endl<<endl;
                        int secim2 =menu2();
                        while(secim2!=0)
                        {
                            switch(secim2)
                            {
                                case 1:
                                {
                                    kitap_goster();
                                    break;
                                }
                                case 2:
                                {
                                    kitap_basvuru();
                                    break;
                                }
                                case 3:
                                {
                                    kitap_iade();
                                    break;
                                }
                                case 0:
                                {
                                    break;
                                }
                                default:
                                {
                                    cout << "Lütfen Geçerli Bir Sayı Giriniz... "<<endl;
                                    cout <<endl;
                                    break;
                                }
                            }
                            secim2=menu2();
                        }
                        break;
                    }   
                    else 
                    {
                        cout << "Bilgileriniz Kontrol Ediliyor..."<<endl;
                        cout <<endl;
                    }
                }
                file.close();
                cout << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                cout << "Lütfen Geçerli Bir Seçim Yapınız..."<<endl;
                cout <<endl;
                break;
            }
        }
        secim = 0;
    }
}
void kayit()
{
    int secim;
    cout << "Kayıt Ekranına Hoş Geldiniz..."<<endl;
    cout << "1 - Yönetici Kayıt " << endl << "2 - Öğrenci Kayıt " <<endl<< "0 - Ana Menüye Dön " <<endl;
    cin >> secim;
    while(secim!=0)
    {
        switch(secim)
        {
            case 1: 
            {
                cout << "Kullanıcı Adı = ";
                cin >> kullanici[1].g1;
                cout << "Şifre = ";
                cin >> kullanici[1].g2;
                fstream file;
                file.open("Yönetici_Kayıtları.txt",ios::in); 
                while(!(file.eof()))
                {
                    file >> kullanici[1].g3;   
                    if(kullanici[1].g3!=kullanici[1].g1)
                    {
                        cout << "Başarıyla Kayıt Oldunuz..."<<endl;
                        fstream file1;
                        file1.open("Yönetici_Kayıtları.txt",ios::app | ios::out);
                        file1 << kullanici[1].g1  << setw(15) << kullanici[1].g2;
                        file1 <<endl;
                        file1.close();
                        break;
                    }
                    else 
                    {
                        cout << "Böyle Bir Kullanıcı Daha Önce Kayıt Oldu Lütfen Tekrar Deneyin..."<<endl;
                        cout << endl;
                        break;
                    }
                }
                file.close();
                break;
            }
            case 2:
            {
                cout << "Kullanıcı Adı = ";
                cin >> kullanici[2].g1;
                cout << "Şifre = ";
                cin >> kullanici[2].g2;
                fstream file;
                file.open("Öğrenci_Kayıtları.txt",ios::in);
                while(!(file.eof()))
                {
                    file >> kullanici[2].g3;
                    if(kullanici[2].g3!=kullanici[2].g1)
                    {
                        cout << "Başarıyla Kayıt Oldunuz..."<<endl;
                        fstream file1;
                        file1.open("Öğrenci_Kayıtları.txt",ios::app | ios::out);
                        file1 << kullanici[2].g1 <<setw(10) << kullanici[2].g2;
                        file1 <<endl;
                        file1.close();
                        break;
                    }
                    else 
                    {
                        cout << "Böyle Bir Kullanıcı Daha Önce Kayıt Oldu Lütfen Tekrar Deneyin..."<<endl;
                        cout << endl;
                        break;
                    }
                }
                file.close();
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                cout << "Lütfen Geçerli Bir Seçim Yapınız..."<<endl;
                break;
            }
        }
        secim = 0;
    }
}
int menu()
{   
    int secim1;
    cout <<"Lütfen Giriş Yapınız, Kayıt Olmadıysanız Lütfen Kayıt Olunuz ! " << endl << endl;
    cout << "1 - Giriş Yap " << endl << "2 - Kayıt Ol " << endl << "0 - Programı Kapat " << endl;
    cin >> secim1;
    return secim1;
}

int main()
{
    int secim = menu();
    
    while(secim!=0)
    {
        switch(secim)
        {
            case 1:
            {
                giris();
                break;
            }
            case 2:
            {
                kayit();
                break;
            }
            case 0:
            {
                break;
            } 
            default:
            {
                cout << "Lütfen Geçerli Bir Rakam Giriniz ! ";
            }
        }
        secim = menu(); 
    }
}