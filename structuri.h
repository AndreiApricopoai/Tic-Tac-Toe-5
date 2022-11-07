#ifndef STRUCTURI_H_INCLUDED
#define STRUCTURI_H_INCLUDED

#define NUMAR_LINII 501
#define NUMAR_COLOANE 501



struct Tabla{

    int lungime;
    int inaltime; // dimensiunea de joc e de 23x14 casute
    int color;
    int dimensiunePatrat;
    int matrice[NUMAR_LINII][NUMAR_COLOANE]={0}; // linii: 1-500   coloane:0-499 cu centrul jocului:
    int offsetSUS = 0;
    int offsetJOS = 0;
    int offsetDREAPTA = 0;
    int offsetSTANGA = 0;
};
struct Game{

    int vsComputer;
    int vsPlayer;
    int playerTurn;
    int computerDificulty;
    int ecranMeniu;
    int ecranReguli;
    int ecranJoc;
    int ecranSelectareDificultate;
    int x1_win,y1_win,x2_win,y2_win;
    int castigator;

};
struct nod {
		int i,j;
		int valoare;
		nod * urm;
	};
struct stiva {
		nod* ultimaMutare;
		int nrMutari;
	};



#endif // STRUCTURI_H_INCLUDED
