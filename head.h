#include <stdio.h>
#include <string.h>
#include <time.h>

class Magazzino{
	private:
		char date[20];
		char prod[20];
		FILE *fp;
		FILE *fs;
	public:
		void Menu();
		void Inserisci();
		void VisualizzaT();       //vis lista completa
		void Modifica();          //modifica prodotto-data
		void Cancella();          //cancella prodotto
		void CtrData();		      //controllo scadenze
};
