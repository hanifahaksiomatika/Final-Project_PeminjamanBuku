#include<iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

string user_akun[10] = {"asahi", "marklee"};

int jumlah_akun = 2;

int pilih_menu(), cariakun(string nama),peminjaman();
void tambah_akun(), lihat_akun(), sortakun(), masuk();

struct tanggal {
	int hari, bln, thn;
};

struct dataPerpus{
	char judul[3][30],pengarang[3][30], penerbit[3][30];
};

struct tanggal pjm, bck, jt;
struct dataPerpus dt;


int main(){
	
	int lanjut =1;
	do {
		int daftar=pilih_menu();
		
		if (daftar== 1){
			tambah_akun();
			masuk();
		}else{
			masuk();
		}
	} while (lanjut== 1);
	
}

int pilih_menu(){
	int menu;
	
	cout << "Buat akun baru atau masuk : " << endl;
	cout << "1. Buat Akun " << endl;
	cout << "2. Masuk" << endl;
	cout << "Pilih [1/2] : ";
	cin >> menu;
	
	return menu;
	system("cls");
}

void masuk(){
	int urutan_akun = -1;
	string nama;
	
	lihat_akun();
	
	do{
		cout << "Silahkan Login Terlebih Dahulu" << endl;
		cout << "Masukkan Username : ";
		cin >> nama;
		
		
		urutan_akun == cariakun(nama);
	
		if (urutan_akun == cariakun(nama)){
			cout<< "username tidak ditemukan, coba lagi!!" << endl;
			
		}else{
			peminjaman();
		}
	}while(urutan_akun == -1);
	
}

void lihat_akun(){
	for(int i=0; i< jumlah_akun; i++){
		cout << (i+1) << ". "<< user_akun[i] << " telah terdaftar"<<endl;
	}
}

void tambah_akun(){
	int akun = jumlah_akun;
	cout<<"Masukan username baru : ";
	cin>>user_akun[akun];
	cout<<"Membuat akun sukses "<<endl;
	
	jumlah_akun++;
	
	sortakun();
	system("cls");
}



void sortakun(){
	int i,j,lokasi_min;
	string temp;
	
	for(i=0;i<jumlah_akun;i++){
		lokasi_min = i;
		for(j = i+1; j<jumlah_akun;j++){
			if (user_akun[j] < user_akun[lokasi_min] ){
				lokasi_min=j;
			}
		}
		
		temp=user_akun[i];
		user_akun[i]=user_akun[lokasi_min];
		user_akun[lokasi_min] = temp;
	}
}

int cariakun(string nama){
	int lo=0, hi = jumlah_akun-1;
	int mid;
	
	
	while (hi-lo > 1){
		mid = (hi + lo)/2;
		if(user_akun[mid]<nama){
			lo= mid+1;
		}else {
			hi=mid;
		}
		
		if (user_akun[lo]==nama){
			return lo;
		}else if (user_akun[hi]==nama){
			return hi;
		}else{
			return -1;
		}
	}
}

int peminjaman(){
	int byk;
	
	while(1){
		cout<<"\nBanyak peminjaman buku : ";
		cin>>byk;
		if(byk>3) {
			cout<<"\n--- MAXIMAL PEMINJAMAN 2 BUKU ---";
		} else {
			break;
		}
	}
	
	system("cls");
	
	cout<<"	=============================="<<endl;
	cout<<"	  INPUT DATA PEMINJAMAN BUKU	"<<endl;
	cout<<"	=============================="<<endl;
	
	for(int a=1; a <= byk; a++){
		
		cout<<"\n Data buku ke " << a;
		cout<<"\n Judul buku\t: "; cin>>(dt.judul[a]);
		cout<<"\n Pengarang\t: "; cin>>(dt.pengarang[a]);
		cout<<"\n Penerbit\t: "; cin>>dt.penerbit[a];
		
		cout<<"\n=======================================";
	}

	system("cls");
	
	cout<<"\n Tanggal pinjam: \n";
	while(1){
		cout<<" Tanggal [1 - 30]\t: "; cin>>pjm.hari;
		if(pjm.hari<=0||pjm.hari>30){
			cout<<" ERROR ...!\n";
		}else{break;}
	}
	
	cout<<"\n Bulan pinjam: \n";
	while(1){
		cout<<" Bulan [1 - 12]\t\t: "; cin>>pjm.bln;
		if(pjm.bln<=0||pjm.bln>12){
			cout<<" ERROR ...!\n";
		}else{break;}
	}
	
	cout<<"\n Tahun pinjam: \n";
	while(1){
		cout<<" Tahun [yyyy]\t\t: "; cin>>pjm.thn;
		if(pjm.hari<=0){
			cout<<" ERROR ...!\n";
		}else{break;}
	}
	system("cls");
	cout<<"\n Tanggal kembali : \n";
	while(1){
		cout<<" Tanggal [1 - 30]\t: "; cin>>bck.hari;
		if(bck.hari<=0||bck.hari>30){
			cout<<" ERROR ..!\n";
		}else{break;}
	}
	
	
	cout<<"\n Bulan kembali: \n";
	while(1){
		cout<<" Bulan [1 - 12]\t\t: "; cin>>bck.bln;
		if(bck.bln<=0||bck.bln>12){
			cout<<" ERROR ..!\n";
		}else{break;}
	}
	
	
	cout<<"\n Tahun kembali: \n";
	while(1){
		cout<<" Tahun [yyyy]\t\t: "; cin>>bck.thn;
		if(bck.thn<=0){
			cout<<" ERROR ..!\n";
		}else{break;}
	}
	
	
	int lamapinjam = (bck.hari - pjm.hari)+((bck.bln-pjm.bln)*30)+((bck.thn-pjm.thn)*360);
	int terlambat = lamapinjam - 7;
	int denda=0;
	if(lamapinjam>7){
		denda = terlambat *500*byk;
	}
	
	
	jt.hari = pjm.hari+7;
	jt.bln = pjm.bln+(jt.hari/31);
	jt.thn = pjm.thn+(jt.bln/13);
	if(jt.hari>30){
		jt.hari-=30;
	}
	if(jt.bln>12){
		jt.bln-=12;
	}
	
	system("cls");
	
	cout<<"\n =========================================";
	cout<< "\n             OUTPUT PEMINJAMAN";
	cout<<"\n =========================================";
	cout<<"\n\n Data buku yang dipinjam:"<<endl<<endl;
	
	for(int a=1; a<=byk; a++){
		cout<<"\n Data buku ke "<<a;
		cout<<"\n Judul buku\t: "<<dt.judul[a];
		cout<<"\n Pengarang\t: "<<dt.pengarang[a];
		cout<<"\n Penerbit\t: "<<dt.penerbit[a];
		cout<<"\n ========================================="<<endl;
	}
	
	
	cout<<"\n Tanggal pinjam		: "<<pjm.hari<<" - "<<pjm.bln<<" - "<<pjm.thn;
	cout<<"\n Tanggal kembali	: "<<bck.hari<<" - "<<bck.bln<<" - "<<bck.thn;
	cout<<"\n Tanggal jatuh tempo	: "<<jt.hari<<" - "<<jt.bln<<" - "<<jt.thn;
	cout<<"\n Lama peminjaman	: "<<lamapinjam<<" hari";
	cout<<"\n Lama keterlambatan	: "<<terlambat<<" hari";
	cout<<"\n Denda			: Rp. "<<denda;
	cout<<"\n ========================================="<<endl;
	getch();
}