#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
struct sehir {
	int kactane;
  	struct plaka *p;
}sehirler[82];
struct plaka {
    char harfkodu[4];
    int sayikodu;
};
void plaka(int x,char *harf,int sayi){
	int kactane = sehirler[x].kactane;
				if (plakaSorgu(x,harf,sayi)== 1) {
					struct plaka *ptr;
					if(sehirler[x].kactane == 0){
						ptr =(struct plaka *)(malloc(sizeof(struct plaka)));
						strcpy(ptr[kactane].harfkodu,harf);
						ptr[kactane].sayikodu = sayi;
						sehirler[x].kactane++;
						sehirler[x].p = ptr;

                    }
                    else if (sehirler[x].kactane > 0){
                    	ptr =sehirler[x].p;
                  		strcpy(ptr[kactane].harfkodu,harf);
						ptr[kactane].sayikodu = sayi;
						sehirler[x].kactane++;
					}
					// printf("\t%s %d\n ",ptr[].harfkodu,ptr[0].sayikodu);
				}
				else if(plakaSorgu(x,harf,sayi)== 2){
					printf("\tAyni Formatta plaka kodu girdiniz.\n");
				}
				else {
					printf("\tYanlis formatta plaka kodu girdiniz.\n");
				}
}
void sehirList(){
	int i,j;
		for(i=0;i < 82;i++){
			for(j=0;j < sehirler[i].kactane; j++){
		    	if(sehirler[i].kactane > 0){
	            printf("\t\t%d %s %d\n",i,sehirler[i].p[j].harfkodu,sehirler[i].p[j].sayikodu);
            }
        }
	}

}


int plakaSorgu(int x,char *harf,int sayi){
	if (x > 0 && x <= 81) {
		if (strlen(harf) > 1 && strlen(harf) <= 3) {
			if (sayi > 9 && sayi <= 9999) {
			   int i;
		 	   int kacTane = sehirler[x].kactane;
		 	   	   for(i=0;i < kacTane;i++){

		 	   		  if(strcmp(sehirler[x].p[i].harfkodu,harf)==0){

		 	   		  	if(sehirler[x].p[i].sayikodu=sayi){
		 	   		  		return 2;

							  }
					   }

				}

		 return 1;
			}
		}
	}
	else return 0;

}

int main (){

    int tercih;
	int i;
		for(i=0;i <= 82; i++)
			sehirler[i].kactane = 0;

	while(TRUE) {
		int x;
		char harf[4];
		int sayi;
		printf("     <|||||||||||||||| Hosgeldiniz||||||||||||||||>\n");
	    printf("\t              ___ MENU ___\n");
		printf("\n");
	    printf("\t[1] < Plaka ekle\n");
	    printf("\t[2] < Tum plakalari yazdir.\n");
	    printf("\t[3] < Secilen palakalari yazdir\n");
		printf("\t[4] < Programdan cikis yap.\n");
		printf("\tTercih Ettiginiz Islem Numarasi: ");
		scanf("%d",&tercih);
			if(tercih == 4){
				printf("\tCikis yaptiniz.");
				break;
		}
	    switch (tercih)
	    {
	    	case 1: {
				printf("\tLutfen bir plaka giriniz! :");
				scanf("%d",&x);
				scanf("%s",harf);
				scanf("%d",&sayi);

				int i,kacHarf = strlen(harf);
				for(i=0;i < kacHarf;i++){
					if(islower(harf[i])){
						harf[i] = toupper(harf[i]);
					}
				}

				plaka(x,harf,sayi);

				break;
			}
			case 2: {

				sehirList();

				break;
			}
			case 3: {
				printf("\tSecilen plakalari yazdir.");
				scanf("%d",&x);
				int i,j;
				 	for(j=0;j < sehirler[x].kactane; j++){
						if(sehirler[x].kactane > 0){
						printf("\t\t%d %s %d\n",x,sehirler[x].p[j].harfkodu,sehirler[x].p[j].sayikodu);
					}
				}
				break;
			}
			case 4:{
				// TODO sehir liste bak!
				break;

			}
		    default: {
				printf("\tGecerli bir sey girmediniz.\n");
				break;
			}
	    }

	}
    return 0;
}
