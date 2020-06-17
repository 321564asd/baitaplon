#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
 
 
typedef struct city_st{
	char city_nm[30];
    char country[30];
	int  year;
}CT;
 
 
void nhap(CT &ct){
	fflush(stdin); 
	printf("\nNhap ten thanh pho: ");
	gets(ct.city_nm);
    printf("\nNhap ten quoc gia: "); 
	gets(ct.country);
    printf("\nNhap nam: "); 
	scanf("%d", &ct.year);
}
 
void nhapN(CT a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap TP thu %d:", i+1);
        nhap(a[i]);
    	printf("\n____________________________________\n");    
    }
}
 
void xuat(CT ct){
    printf("\nTen: %s", ct.city_nm);
    printf("\nQuoc Gia: %s", ct.country);
    printf("\nNam: %d", ct.year);
}
 
void xuatN(CT a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nThong tin Thanh Pho thu %d:\n", i+1);
        xuat(a[i]);
        printf("\n____________________________________\n");
    }
}

void sapxepZtoA(CT a[], int n){
	CT t;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(strcmp(a[i].city_nm,a[j].city_nm)<0){
            	t = a[i];
            	a[i] = a[j];
            	a[j] = t;
            }
        }
    }
}
void sapxepAtoZ(CT a[], int n){
	CT t;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(strcmp(a[i].city_nm,a[j].city_nm)>0){
            	t = a[i];
            	a[i] = a[j];
            	a[j] = t;
            }
        }
    }
}

void timkiem(CT ct){	
    printf("\nTen: %s", ct.city_nm);
    printf("\nQuoc Gia: %s", ct.country);
    printf("\nNam: %d", ct.year);
    printf("\n____________________________________\n");
}
 
void timkiemN(CT a[], int n){
	int dem=0;
	char ten[30];
	fflush(stdin);
	printf("\n____________________________________\n");
	printf("\nNhap ten quoc gia cua thanh pho ban muon tim: \n");
	gets(ten);

    for(int i = 0;i < n;++i){
    	if(strcmp(a[i].country, ten)==0){
    		dem = ++dem;
		}    	
    }
    if(dem==0){
    	printf("\nKhong co quoc gia nay trong du lieu!!!");
    	printf("\n____________________________________\n");
	}
	else {
		printf("Co %d ket qua duoc tim thay", dem);
		printf("\n____________________________________\n");
		for(int i = 0; i<n; i++){	
			if(strcmp(a[i].country, ten)==0){
			printf("TP thu %d:\n", i);	
			timkiem(a[i]);
			}
		}
	}
}

void xuatFile(CT a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"wb");
    for(int i = 0;i < n;i++){
		fwrite(&a[i], sizeof(struct city_st), 2, fp);
	}
    fclose (fp);
}
 
int main(){
    int key;
    int n;
    char fileName[] = "city.dat";
    bool daNhap = false;
    do{
        printf("\nNhap so luong TP: "); scanf("%d", &n);
    }while(n <= 0);
    CT a[n];
    while(true){
        system("cls");
        printf("****************************************************\n");
        printf("**           CHUONG TRINH SAP XEP TP              **\n");
        printf("**       1. Nhap du lieu TP                       **\n");
        printf("**       2. Hien thi danh sach TP (A to Z)        **\n");
        printf("**       3. Hien thi danh sach TP (Z to A)        **\n");
        printf("**       4. Tim TP theo ten quoc gia              **\n");
        printf("**       5. Ghi vao tap tin nhi phan city.dat     **\n");
        printf("**       0. Thoat                                 **\n");
        printf("****************************************************\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS TP!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon hien thi DS TP!");
                    sapxepAtoZ(a,  n);
                    xuatN(a, n);
                }
				else{
                    printf("\nNhap DS TP truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon hien thi DS TP!");
                    sapxepZtoA(a,  n);
                    xuatN(a, n);
                }
				else{
                    printf("\nNhap DS TP truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;    
			case 4:
				if(daNhap){
                    printf("\nBan da chon tim kiem TP theo quoc gia!");
                    timkiemN(a, n);
                }
				else{
                    printf("\nNhap DS TP truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;	 
			 case 5:
                if(daNhap){
                    printf("\nBan da chon xuat DS TP!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS TP truoc!!!!");
                }
                printf("\nXuat DSTP thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;	 
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}

