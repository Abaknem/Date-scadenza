#include "head.h"

void Magazzino::Inserisci(){
}

void Magazzino::VisualizzaT(){
    char tempDate[10]="";
	char tempProd[20]="";
	
	if ((fp=fopen("product.txt", "r"))==NULL){
		fprintf(stderr, "Errore\n");
	}
	
	while(fscanf(fp, "%s %s", &tempProd, &tempDate) != EOF){
    	printf("%s %s\n", prod, date);
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
			if (*tempDate[i]=='/')
				*tempDate[i]=' ';
		}
	}
	
	fclose(fp);
}
