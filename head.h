#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

class Magazzino{
	private:
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
