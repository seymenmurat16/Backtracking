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
	printf("N giriniz:"); // Kullanýcýdan 3 ile 8 arasýnda bir matris boyutu alýyorum
	scanf("%d",&N);
	}while(N<3 || N>8);
	
	fs=fopen("Matris.txt","r");  // Dosyadan Matrisi okuyorum ve her renge bir sayi atýyorum
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
   	
   	printf("Ilk Durum \n"); // Matrisin ilk durumunu yazdýrýyorum
   	yazdir(mtr,N); 
   	backtracking(mtr,0,N,0); // Backtracking ile matrisi istenen þekile sokmaya çalýþýyorum

	if(kontrol(mtr,N-1,N)==-1){ // Eðer tüm sutunlarda farklý sayýlar yoksa Matris istenen þekile sokmak için uygun olmadýðýný bildiriyorum
		printf("Bulunamadi.\n");
	}
		
	return 0;
}

int kontrol(int mtr[8][8],int satir,int N){
	int temp,i,j;
	while(satir!=0){ // Kontrol edilen satýrdan baþlayarak ilk satira kadar tüm matrisi kontrol ediyorum 
		for(i=0;i<satir;i++){  // Girilen satirdaki tüm elemanlarý diðer satýrdaki elemanlarla karþýlaþtýrýyorum 
			for(j=0;j<N;j++){
				if(mtr[satir][j]==mtr[i][j]){ // Eðer farklý satýrlarýn ayný sutununda ayný sayý vasa uygun olmadýðý için -1 döndürüyorum 
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
		if(kontrol(mtr,satir,N)==0){ // Satýrdaki elemanlarý matrise uygunluðu açýsýndan kontrol ediyorum
			printf("%d. Adim \n",satir+1); // Eðer uygunsa o satýrýn bir alt satýrýna geçiyorum
			yazdir(mtr,N);
			backtracking(mtr,satir+1,N,0);
		}
		else{
			sagakaydir(mtr,satir,N); // Eðer uygun deðilse satýrý bir adým saða öteliyorum
			sayac++; // sayac arttýrýyorum çünkü eðer bir sayac koymazsam sonsuza kadar saða öteleyip durur
			if(sayac==N){ // sayac N'e ulaþýrsa anlýyorum ki o satir için tüm olasýklar denendi
				return -1; 
			}
			backtracking(mtr,satir,N,sayac); // eðer sayac N'e ulaþmadýysa ayný satýrý yeniden backtrackinge sokuyorum
		}
	}
	else{
		printf("-----Matris-----\n"); // Artýk tüm kontroller bittiðinde matristeki sayýlara göre renkleri yazdýrýp bitiriyorum
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
	temp=mtr[satir][j]; // En saðdaki elemaný saklýyorum
	while(j>0){ // Daha sonra saðdaki elemanýn bir solundan baþlayarak elemanlarý öteliyorum
		mtr[satir][j]=mtr[satir][j-1];
		j--;;
	}
	mtr[satir][0]=temp; // Son olarak en soldaki elemanýn yerine sakladýðýmýz elemaný koyuyoruz
}

void yazdir(int mtr[8][8],int N){ // Matrisi Yazdýrýyorum
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
