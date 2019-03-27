#include "head.h"

void Magazzino::Menu(){
	int ch;
	int ch2;
	char c;
	
	printf("1.Inserimento prod.\n");
	printf("2.Modifica prod.\n");
	printf("3.Visualizza lista prod.\n");
	printf("4.Cancella prod.\n");
	printf("5.Esci\n");
	scanf("%d", &ch);
	
	switch(ch) {
      case 1 :
      	system ("cls");
      	printf("1.Inserimento multiplo\n");
        printf("2.Inserimento singolo\n");
        scanf("%d", &ch2);
         
        if(ch2==1)
            do {
               Magazzino::Inserisci();
               printf("Procedere? Y/N");
               scanf("%c", &c);
            } while(c=='y');
        else
          	Magazzino::Inserisci();
        break;
        
      //
      	
      case 3 :
      	system ("cls");
        Magazzino::VisualizzaT();
        break;
        
      case 4 :
      	system ("cls");
      	Magazzino::Cancella(); 	
      
      case 5 :
      	return;
    }
}

void Magazzino::Inserisci(){
	char tempDate[10]="";
	char tempProd[20]="";	
	time_t sec;
	int f,b,c;
	struct tm *a;
	
	printf("Inserire nome prodotto e data di scadenza.\n");
		printf("prod.:\n");
		scanf("%s", tempProd);
		
		printf("data dd/mm/yyyy:\n");
	    scanf("%d %d %d", &f, &b, &c);
	    
	    a->tm_mday=f;
		a->tm_mon=b;
		a->tm_year=c;
	    
	    sec=mktime(a);
	    
	    printf("%d %d %d", a->tm_mday, a->tm_mon, a->tm_year);
	    printf("%d", sec);
	    
	if ((fp=fopen("product.txt", "a"))==NULL){
		fprintf(stderr, "Errore\n");
	}
	
	fprintf(fp, "%s %s \n", tempProd, tempDate);
	
	fclose(fp);
}

void Magazzino::VisualizzaT(){
    char tempDate[10]="";
	char tempProd[20]="";
	
	if ((fp=fopen("product.txt", "r"))==NULL){
		fprintf(stderr, "Errore\n");
	}
	
	while(fscanf(fp, "%s %s", tempProd, tempDate) != EOF){
    	printf("%s %s\n", tempProd, tempDate);
	}
	
	fclose(fp);
}

void Magazzino::Cancella(){
	char tempProd [20]="";
	char tempDate [10]="";
	char ric[20];
	
	if ((fp=fopen("product.txt", "r"))==NULL) {
		fprintf(stderr, "Errore\n");
	}
	
	if ((fs=fopen("supp", "w"))==NULL) {
		fprintf(stderr, "Errore\n");
	}
	
	printf("Prodotto da cancellare:\n");
	scanf("%s", &ric);	
	
	while (fscanf(fp, "%s %s", &tempProd, &tempDate) != EOF)  {
			if(strcmp(ric,tempProd)!=0)
              fprintf(fs, "%s %s \n", &tempProd, &tempDate);
              //da aggiungere: prodotto non trovato
	}
	
	fclose(fp);
	fclose(fs);
	
	if ((fp=fopen("product.txt", "w"))==NULL) {
		fprintf(stderr, "Errore\n");
	}
	
	if ((fs=fopen("supp", "r"))==NULL) {
		fprintf(stderr, "Errore\n");
	}
	
	while (fscanf(fs, "%s %s", &tempProd, &tempDate) != EOF)  {
            fprintf(fp, "%s %s \n", &tempProd, &tempDate);
	}
	
	fclose(fs);
	fclose(fp);
}

void Magazzino::CtrData(){
	char tempDate[10]="";
	char tempProd[20]="";
	int i;
	struct tm date;
	
	if ((fp=fopen("product.txt", "r"))==NULL) {
		fprintf(stderr, "Errore\n");
	}
	
	while(fscanf(fp, "%s %s", tempProd, tempDate) != EOF){
		for(i=0;i<10;i++){

		}
	}
	
	fclose(fp);
}
