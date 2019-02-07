#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sagakaydir(int mtr[8][8],int satir,int N);
void yazdir(int mtr[8][8],int N);
int kontrol(int mtr[8][8],int satir,int N);
int backtracking(int mtr[8][8],int satir,int N,int sayac);

int main(){
	
	int N,mtr[8][8],i=0,j=0,tmp;
	char colors[8][10]={"Beyaz","Siyah","Mavi","Kirmizi","Sari","Yesil","Mor","Turuncu"};
	char color[10];
	FILE *fs;
	
	do {
	printf("N giriniz:"); // Kullan�c�dan 3 ile 8 aras�nda bir matris boyutu al�yorum
	scanf("%d",&N);
	}while(N<3 || N>8);
	
	fs=fopen("Matris.txt","r");  // Dosyadan Matrisi okuyorum ve her renge bir sayi at�yorum
	 	while(!feof(fs)){ 
		 	fscanf(fs,"%s",color);
		 	if(strcmp(color,"Beyaz")==0){
		 		mtr[i][j]=0;
		    }
			else if(strcmp(color,"Siyah")==0){
		 		mtr[i][j]=1;
		    }
			else if(strcmp(color,"Mavi")==0){
		 		mtr[i][j]=2;
		    }
			else if(strcmp(color,"Kirmizi")==0){
		 		mtr[i][j]=3;
		    }
			else if(strcmp(color,"Sari")==0){
		 		mtr[i][j]=4;
		    }
			else if(strcmp(color,"Yesil")==0){
		 		mtr[i][j]=5;
		    }
			else if(strcmp(color,"Mor")==0){
		 		mtr[i][j]=6;
		    }
			else if(strcmp(color,"Turuncu")==0){
		 		mtr[i][j]=7;
		    } 	
		    j++;
			if(j==N){
				i++;
				j=0;
			}
	  	}  	
   	fclose(fs);
   	
   	printf("Ilk Durum \n"); // Matrisin ilk durumunu yazd�r�yorum
   	yazdir(mtr,N); 
   	backtracking(mtr,0,N,0); // Backtracking ile matrisi istenen �ekile sokmaya �al���yorum

	if(kontrol(mtr,N-1,N)==-1){ // E�er t�m sutunlarda farkl� say�lar yoksa Matris istenen �ekile sokmak i�in uygun olmad���n� bildiriyorum
		printf("Bulunamadi.\n");
	}
		
	return 0;
}

int kontrol(int mtr[8][8],int satir,int N){
	int temp,i,j;
	while(satir!=0){ // Kontrol edilen sat�rdan ba�layarak ilk satira kadar t�m matrisi kontrol ediyorum 
		for(i=0;i<satir;i++){  // Girilen satirdaki t�m elemanlar� di�er sat�rdaki elemanlarla kar��la�t�r�yorum 
			for(j=0;j<N;j++){
				if(mtr[satir][j]==mtr[i][j]){ // E�er farkl� sat�rlar�n ayn� sutununda ayn� say� vasa uygun olmad��� i�in -1 d�nd�r�yorum 
					return -1;	
				}
			}
		}
		satir--; 
	}
	return 0;
}

int backtracking(int mtr[8][8],int satir,int N,int sayac){
	int i,j;
	if(satir<N){ 
		if(kontrol(mtr,satir,N)==0){ // Sat�rdaki elemanlar� matrise uygunlu�u a��s�ndan kontrol ediyorum
			printf("%d. Adim \n",satir+1); // E�er uygunsa o sat�r�n bir alt sat�r�na ge�iyorum
			yazdir(mtr,N);
			backtracking(mtr,satir+1,N,0);
		}
		else{
			sagakaydir(mtr,satir,N); // E�er uygun de�ilse sat�r� bir ad�m sa�a �teliyorum
			sayac++; // sayac artt�r�yorum ��nk� e�er bir sayac koymazsam sonsuza kadar sa�a �teleyip durur
			if(sayac==N){ // sayac N'e ula��rsa anl�yorum ki o satir i�in t�m olas�klar denendi
				return -1; 
			}
			backtracking(mtr,satir,N,sayac); // e�er sayac N'e ula�mad�ysa ayn� sat�r� yeniden backtrackinge sokuyorum
		}
	}
	else{
		printf("-----Matris-----\n"); // Art�k t�m kontroller bitti�inde matristeki say�lara g�re renkleri yazd�r�p bitiriyorum
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(mtr[i][j]==0){
		 			printf("Beyaz ");
			    }
				else if(mtr[i][j]==1){
			 		printf("Siyah ");
			    }
				else if(mtr[i][j]==2){
			 		printf("Mavi ");
			    }
				else if(mtr[i][j]==3){
			 		printf("Kirmizi ");
			    }
				else if(mtr[i][j]==4){
			 		printf("Sari ");
			    }
				else if(mtr[i][j]==5){
			 		printf("Yesil ");
			    }
				else if(mtr[i][j]==6){
			 		printf("Mor ");
			    }
				else if(mtr[i][j]==7){
			 		printf("Turuncu ");;
			    }	
			}
		printf("\n");
		}
	}
	return 0;
}

void sagakaydir(int mtr[8][8],int satir,int N){
	int j=N-1,temp;
	temp=mtr[satir][j]; // En sa�daki eleman� sakl�yorum
	while(j>0){ // Daha sonra sa�daki eleman�n bir solundan ba�layarak elemanlar� �teliyorum
		mtr[satir][j]=mtr[satir][j-1];
		j--;;
	}
	mtr[satir][0]=temp; // Son olarak en soldaki eleman�n yerine saklad���m�z eleman� koyuyoruz
}

void yazdir(int mtr[8][8],int N){ // Matrisi Yazd�r�yorum
	int i=0,j=0;
	printf("-----Matris-----\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",mtr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
