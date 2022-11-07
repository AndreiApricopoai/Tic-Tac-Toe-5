#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include "structuri.h"
#include "functii_grafica.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


bool esteVida(stiva S){
		return S.nrMutari == 0;
}
void initializeaza(stiva& S){
		S.ultimaMutare=NULL; S.nrMutari=0;
	}
void pop(stiva &S){
		if (!esteVida(S))
		{
			nod* varf_nou;
			varf_nou=S.ultimaMutare->urm;
			delete S.ultimaMutare;
			S.ultimaMutare=varf_nou;
			S.nrMutari--;
		}
	}
void goleste(stiva &S){
		while (!esteVida(S)) pop(S);
	}
void push(stiva &S, nod* mutare){
		nod * nod_nou;
		if (esteVida(S))
		{
			S.nrMutari = 1;
			S.ultimaMutare = new nod;
			S.ultimaMutare = mutare;
			S.ultimaMutare->urm=NULL;
		}
		else
		{
			S.nrMutari++;
			nod_nou = new nod;
			nod_nou = mutare;
			nod_nou->urm = S.ultimaMutare;
			S.ultimaMutare = nod_nou;
		}
	}
nod* creareMutare(int i, int j, int valoare){
    nod* nou = new nod;
    nou->urm = NULL;
    nou->i = i;
    nou->j = j;
    nou->valoare = valoare;
    return nou;
}
int verificareVictorie(int a[NUMAR_LINII][NUMAR_COLOANE], int i, int j, Game &game){

    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;   // x = coloana , y = linie
    int valoarePiesa = a[i][j];
    int cnt = 0;

    if (valoarePiesa == 0)
        return 0;
    else
    {

        //mergem pe coloane
        x1 = j, x2 = j, y1 = i, y2 = i, cnt = 1;

        for(int k = j+1; k<=j+4; k++)
        {
            if(a[i][k] == valoarePiesa)
            {
                cnt++;
                x2 = k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }



        for(int k = j-1; k>=j-4; k--)
        {
            if(a[i][k] == valoarePiesa)
            {
                cnt++;
                x1 = k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }


        //mergem pe linii
        x1 = j, x2 = j, y1 = i, y2 = i, cnt = 1;

        for(int k = i+1; k<=i+4; k++)
        {
            if(a[k][j] == valoarePiesa)
            {
                cnt++;
                y2 = k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }

        for(int k = i-1; k>=i-4; k--)
        {
            if(a[k][j] == valoarePiesa)
            {
                cnt++;
                y1 = k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }

        // mergem pe diagonala principala


        x1 = j, x2 = j, y1 = i, y2 = i, cnt = 1;

        for(int k = 1; k<=4; k++)
        {
            if(a[i+k][j+k] == valoarePiesa)
            {
                cnt++;
                x2 = j+k;
                y2 = i+k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }

        for(int k = 1; k<=4; k++)
        {
            if(a[i-k][j-k] == valoarePiesa)
            {
                cnt++;
                x1 = j-k;
                y1 = i-k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }


        // mergem pe diagoanala secundara

        x1 = j, x2 = j, y1 = i, y2 = i, cnt = 1;

        for(int k = 1; k<=4; k++)
        {
            if(a[i-k][j+k] == valoarePiesa)
            {
                cnt++;
                y2 = i-k;
                x2 = j+k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }



        for(int k = 1; k<=4; k++)
        {
            if(a[i+k][j-k] == valoarePiesa)
            {
                cnt++;
                y1 = i+k;
                x1 = j-k;
            }
            else
                break;
            if(cnt >= 5)
            {
                game.x1_win = x1;
                game.x2_win = x2;
                game.y1_win = y1;
                game.y2_win = y2;
                game.castigator = valoarePiesa;
                return valoarePiesa;
            }

        }



    }


return 0;
}
int importanta_Mutare(int i, int j, Tabla tabla){


    int cnt = 0, maxim = -1;


        //mergem pe coloane
        cnt = 0;

        for(int k = j+1; k<=j+4; k++)
        {
            if(tabla.matrice[i][k] == 1)
                cnt++;
            else
                break;
        }



        for(int k = j-1; k>=j-4; k--)
        {
            if(tabla.matrice[i][k] == 1)
                cnt++;
            else
                break;
        }

        if(cnt > maxim)
            maxim = cnt;


        //mergem pe linii
        cnt = 0;

        for(int k = i+1; k<=i+4; k++)
        {
            if(tabla.matrice[k][j] == 1)
                cnt++;
            else
                break;
        }

        for(int k = i-1; k>=i-4; k--)
        {
            if(tabla.matrice[k][j] == 1)
                cnt++;
            else
                break;
        }

        if(cnt > maxim)
            maxim = cnt;

        // mergem pe diagonala principala


        cnt = 0;

        for(int k = 1; k<=4; k++)
        {
            if(tabla.matrice[i+k][j+k] == 1)

                cnt++;
            else
                break;
        }

        for(int k = 1; k<=4; k++)
        {
            if(tabla.matrice[i-k][j-k] == 1)
                cnt++;
            else
                break;
        }


        if(cnt > maxim)
            maxim = cnt;


        // mergem pe diagoanala secundara

        cnt = 0;

        for(int k = 1; k<=4; k++)
        {
            if(tabla.matrice[i-k][j+k] == 1)
                cnt++;
            else
                break;
        }



        for(int k = 1; k<=4; k++)
        {
            if(tabla.matrice[i+k][j-k] == 1)
                cnt++;
            else
                break;
        }

        if(cnt > maxim)
            maxim = cnt;

return maxim;
}
void initializareObiectTabla(Tabla &tabla, int lungime, int inaltime, int culoare, int dimensiunePatrat){
    tabla.color = culoare;
    tabla.lungime = lungime;
    tabla.inaltime = inaltime;
    tabla.dimensiunePatrat = dimensiunePatrat;
    tabla.offsetDREAPTA = 0;
    tabla.offsetJOS = 0;
    tabla.offsetSTANGA = 0;
    tabla.offsetSUS = 0;
    for(int i = 0; i <= 500; i++)
        for(int j = 0; j <= 500; j++)
            tabla.matrice[i][j] = 0;
}
void afisareTabla(Tabla tabla){
    initwindow(tabla.lungime,tabla.inaltime,"Cinci in linie!");
    setbkcolor(tabla.color);
    cleardevice();
    setcolor(BLACK);

    for(int i=tabla.dimensiunePatrat; i<=tabla.inaltime; i=i+tabla.dimensiunePatrat) // desenare linii orizonatale
        line(0,i,tabla.lungime-2*tabla.dimensiunePatrat,i);

    for(int i=0; i<=tabla.lungime-2*tabla.dimensiunePatrat; i=i+tabla.dimensiunePatrat)  // desenare linii verticale
        line(i,tabla.dimensiunePatrat,i,tabla.inaltime);

    afisareSageataSus(1200,100,35,BLACK);
    afisareSageataJos(1200,200,35,BLACK);
    afisareSageataStanga(1185,250,35,BLACK);
    afisareSageataDreapta(1215,325,35,BLACK);
    afisareSageataBack(1190,425,35,RED);
    afisareIconitaMeniu(1200,500,35,BLUE);
    afisareIconitaReset(1165,575,70,1,GREEN);
    afisareTextPlayer(50,10,4,1);
    afisareTextPlayer(950,10,4,2);
    afisareSimbol_X(220,13,23); //afisare simbol sus
    afisareSimbol_O(920,25,15); // afisare simbol sus

}
void afisareTablaFaraINIT(Tabla tabla){
    cleardevice();
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,1);

    for(int i=tabla.dimensiunePatrat; i<=tabla.inaltime; i=i+tabla.dimensiunePatrat) // desenare linii in lungime
        line(0,i,tabla.lungime-2*tabla.dimensiunePatrat,i);

    for(int i=0; i<=tabla.lungime-2*tabla.dimensiunePatrat; i=i+tabla.dimensiunePatrat)  // desenare linii in inaltime
        line(i,tabla.dimensiunePatrat,i,tabla.inaltime);

    afisareSageataSus(1200,100,35,BLACK);
    afisareSageataJos(1200,200,35,BLACK);
    afisareSageataStanga(1185,250,35,BLACK);
    afisareSageataDreapta(1215,325,35,BLACK);
    afisareSageataBack(1190,425,35,RED);
    afisareIconitaMeniu(1200,500,35,BLUE);
    afisareIconitaReset(1165,575,70,1,GREEN);
    afisareTextPlayer(50,10,4,1);
    afisareTextPlayer(950,10,4,2);
    afisareSimbol_X(220,13,23);
    afisareSimbol_O(920,25,15);
}
int esteLocLiber(int a[NUMAR_LINII][NUMAR_COLOANE], int i, int j, Tabla tabla){
    if(a[250-8+i+tabla.offsetJOS-tabla.offsetSUS][250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == 0)
        return 1;
    return 0;
}
void plasarePiesaAmbiiPlayeri(Tabla &tabla, Game &game,stiva& S ,int x, int y){

    int i,j;
    int xF,yF;
    double xC,yC;


    if(game.playerTurn == 1 && x <= tabla.lungime-2*tabla.dimensiunePatrat && y >= tabla.dimensiunePatrat)
    {


        xC = (double)x/tabla.dimensiunePatrat;// coordonate matrice in indici
        j = ceil(xC);
        xF = ceil(xC)*tabla.dimensiunePatrat;//coordonate matrice in pixeli

        yC = (double)y/tabla.dimensiunePatrat;// coordonate matrice in indici
        i = ceil(yC);
        yF = ceil(yC)*tabla.dimensiunePatrat; // //coordonate matrice in pixeli

        if(esteLocLiber(tabla.matrice,i,j,tabla))
        {

            tabla.matrice[250-8+i+tabla.offsetJOS-tabla.offsetSUS][250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] = 1;
            push(S,creareMutare(250-8+i+tabla.offsetJOS-tabla.offsetSUS, 250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA, 1));
            cout<<250-8+i+tabla.offsetJOS-tabla.offsetSUS<<" "<<250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA<<endl;
            X(xF,yF);
            game.playerTurn = -1;
            if(verificareVictorie(tabla.matrice,250-8+i+tabla.offsetJOS-tabla.offsetSUS, 250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA,game)){
                trasareLinieVictorie(50*(game.x1_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12), 50*(game.y1_win-tabla.offsetJOS+tabla.offsetSUS-250+8),50*(game.x2_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12),50*(game.y2_win-tabla.offsetJOS+tabla.offsetSUS-250+8));
                afisareWIN_LOSS(game.castigator);
            }
        }
    }

    else if (game.playerTurn == -1 && x <= tabla.lungime-2*tabla.dimensiunePatrat && y >= tabla.dimensiunePatrat)
    {

        xC = (double)x/tabla.dimensiunePatrat;
        j = ceil(xC);
        xF = ceil(xC)*tabla.dimensiunePatrat-tabla.dimensiunePatrat/2;

        yC = (double)y/tabla.dimensiunePatrat;
        i = ceil(yC);
        yF = ceil(yC)*tabla.dimensiunePatrat-tabla.dimensiunePatrat/2;

        if(esteLocLiber(tabla.matrice,i,j,tabla))
        {
            tabla.matrice[250-8+i+tabla.offsetJOS-tabla.offsetSUS][250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] = -1;
            push(S,creareMutare(250-8+i+tabla.offsetJOS-tabla.offsetSUS, 250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA, -1));
            cout<<250-8+i+tabla.offsetJOS-tabla.offsetSUS<<" "<<250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA<<endl;
            O(xF,yF);
            game.playerTurn = 1;

            if(verificareVictorie(tabla.matrice,250-8+i+tabla.offsetJOS-tabla.offsetSUS, 250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA,game)){
                trasareLinieVictorie(50*(game.x1_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12), 50*(game.y1_win-tabla.offsetJOS+tabla.offsetSUS-250+8),50*(game.x2_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12),50*(game.y2_win-tabla.offsetJOS+tabla.offsetSUS-250+8));
                afisareWIN_LOSS(game.castigator);
            }



        }
    }

}
void resetareObiectGame(Game &game){
    game.playerTurn = 1;//X muta primul
    game.ecranMeniu = 0;
    game.ecranReguli = 0;
    game.ecranJoc = 0;
    game.ecranSelectareDificultate = 0;
    game.x1_win = -1;
    game.x2_win = -1;
    game.y1_win = -1;
    game.y2_win = -1;
    game.castigator = 0;
}
void afisareMeniu(){
    // culoare background
    initwindow(600,400,"Cinci in linie!");
    setbkcolor(WHITE);
    cleardevice();


    setcolor(BLACK); // culoare text
    settextstyle(10,0,4); // font, dimensiune
    outtextxy(100,50,"Jocul Cinci in Linie!"); // afisare text

    afisareButonVSPlayer(70,150,200,4,BLACK);
    afisareButonVSBot(320,150,200,4,RED);
    afisareButonReguli(500,340,85,2,GREEN);

}
void afisareMeniuFaraINITWINDOW(){
    cleardevice();
    setcolor(BLACK); // culoare text
    settextstyle(10,0,4); // font, dimensiune
    outtextxy(100,50,"Jocul Cinci in Linie!"); // afisare text

    afisareButonVSPlayer(70,150,200,4,BLACK);
    afisareButonVSBot(320,150,200,4,RED);
    afisareButonReguli(500,340,85,2,GREEN);

}
void afisarePanouReguli(){
    cleardevice();
    afisareSageataStanga(25,25,20,BLACK);
    setcolor(BLUE);
    settextstyle(10,0,1);
    outtextxy(20,70,"- Jocul se poate juca player VS player sau");
    outtextxy(20,90,"player VS computer."); //
    outtextxy(20,130,"- Fiecare player are o piesa de joc asociata");
    outtextxy(20,150,"(X sau O) care va ramane pana la finalul jocului!");
    outtextxy(20,190,"- Jocul se va termina cand unul dintre jucatori va");
    outtextxy(20,210,"reusi sa realizeze o combinatie de 5 piese de");
    outtextxy(20,230," acelasi fel consecutive in una din urmatoarele");
    outtextxy(20,250,"configuratii: orizontal, vertical sau pe diagonala.");
}
void afisareEcranSelectareDificultate(){
    cleardevice();
    afisareSageataStanga(25,25,20,BLACK);
    setcolor(GREEN); // culoare text
    settextstyle(10,0,4); // font, dimensiune
    outtextxy(90,75,"SELECTARE DIFICULTATE:"); // afisare text
    afisareButonEasy(100,170,120,4,BLUE);
    afisareButonHard(350,170,120,4,RED);
}
void functieMutareColoanaDreapta(Tabla &tabla){
    if(tabla.offsetSTANGA == 0)
        tabla.offsetDREAPTA++;
    else if(tabla.offsetSTANGA != 0)
        tabla.offsetSTANGA--;

    setcolor(WHITE);
    for(int i = 1;i <= 14;i++){
        for(int j = 1;j <= 23;j++){
            setfillstyle(SOLID_FILL,WHITE);
            bar((j-1)*50+5,i*50+5,j*50-5,(i+1)*50-5);
        }
    }

    for(int i = 1;i <= 14;i++)
    {
        for(int j = 1;j <= 23;j++)
        {
            if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == 1){
                    X(j*50,(i+1)*50);
            }
            else if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == -1){
                    O(j*50-25,(i+1)*50-25);
            }

        }
    }


}
void functieMutareColoanaStanga(Tabla &tabla){
    if(tabla.offsetDREAPTA == 0)
        tabla.offsetSTANGA++;
    else if(tabla.offsetDREAPTA != 0)
        tabla.offsetDREAPTA--;

    setcolor(WHITE);
    for(int i = 1;i <= 14;i++){
        for(int j = 1;j <= 23;j++){
            setfillstyle(SOLID_FILL,WHITE);
            bar((j-1)*50+5,i*50+5,j*50-5,(i+1)*50-5);
        }
    }

    for(int i = 1;i <= 14;i++)
    {
        for(int j = 1;j <= 23;j++)
        {
            if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == 1){
                    X(j*50,(i+1)*50);
            }
            else if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == -1){
                    O(j*50-25,(i+1)*50-25);
            }

        }
    }

}
void functieMutareLinieSus(Tabla &tabla){
    if(tabla.offsetJOS == 0)
        tabla.offsetSUS++;
    else if(tabla.offsetJOS != 0)
        tabla.offsetJOS--;

    setcolor(WHITE);
    for(int i = 1;i <= 14;i++){
        for(int j = 1;j <= 23;j++){
            setfillstyle(SOLID_FILL,WHITE);
            bar((j-1)*50+5,i*50+5,j*50-5,(i+1)*50-5);
        }
    }

    for(int i = 1;i <= 14;i++)
    {
        for(int j = 1;j <= 23;j++)
        {
            if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == 1){
                    X(j*50,(i+1)*50);
            }
            else if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == -1){
                    O(j*50-25,(i+1)*50-25);
            }

        }
    }

}
void functieMutareLinieJos(Tabla &tabla){
    if(tabla.offsetSUS == 0)
        tabla.offsetJOS++;
    else if(tabla.offsetSUS != 0)
        tabla.offsetSUS--;

    setcolor(WHITE);
    for(int i = 1;i <= 14;i++){
        for(int j = 1;j <= 23;j++){
            setfillstyle(SOLID_FILL,WHITE);
            bar((j-1)*50+5,i*50+5,j*50-5,(i+1)*50-5);
        }
    }

    for(int i = 1;i <= 14;i++)
    {
        for(int j = 1;j <= 23;j++)
        {
            if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == 1){
                    X(j*50,(i+1)*50);
            }
            else if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == -1){
                    O(j*50-25,(i+1)*50-25);
            }

        }
    }

}
void functieMutareInapoi(stiva & S, Tabla &tabla, Game& game){
    if(esteVida(S) == 0){
    setcolor(WHITE);
    for(int i = 1;i <= 14;i++){
        for(int j = 1;j <= 23;j++){
            setfillstyle(SOLID_FILL,WHITE);
            bar((j-1)*50+5,i*50+5,j*50-5,(i+1)*50-5);
        }
    }

    if(S.ultimaMutare->valoare == 1)
        game.playerTurn = 1;
    else if(S.ultimaMutare->valoare == -1)
        game.playerTurn = -1;
    tabla.matrice[S.ultimaMutare->i][S.ultimaMutare->j] = 0;
    pop(S);

        for(int i = 1;i <= 14;i++)
    {
        for(int j = 1;j <= 23;j++)
        {
            if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == 1){
                    X(j*50,(i+1)*50);
            }
            else if(tabla.matrice[243+i+tabla.offsetJOS-tabla.offsetSUS][238+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] == -1){
                    O(j*50-25,(i+1)*50-25);
            }

        }
    }
}
}
int estePozitieDinCadrulTablei(int i, int j, Tabla tabla){

    if(i >= 244+tabla.offsetJOS-tabla.offsetSUS && i <= 257+tabla.offsetJOS-tabla.offsetSUS && j >= 239+tabla.offsetDREAPTA-tabla.offsetSTANGA && j <= 261+tabla.offsetDREAPTA-tabla.offsetSTANGA)
        return 1;
    return 0;

}
void plasarePiesaPlayer(Tabla &tabla, Game &game,stiva& S ,int x, int y){


    int i,j;
    int xF,yF;
    double xC,yC;


    if(game.playerTurn == 1 && game.castigator == 0 && x <= tabla.lungime-2*tabla.dimensiunePatrat && y >= tabla.dimensiunePatrat)
    {
        xC = (double)x/tabla.dimensiunePatrat;// coordonate matrice in indici
        j = ceil(xC);
        xF = ceil(xC)*tabla.dimensiunePatrat;//coordonate matrice in pixeli

        yC = (double)y/tabla.dimensiunePatrat;// coordonate matrice in indici
        i = ceil(yC);
        yF = ceil(yC)*tabla.dimensiunePatrat; // //coordonate matrice in pixeli

        if(esteLocLiber(tabla.matrice,i,j,tabla))
        {
            tabla.matrice[250-8+i+tabla.offsetJOS-tabla.offsetSUS][250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA] = 1;
            push(S,creareMutare(250-8+i+tabla.offsetJOS-tabla.offsetSUS, 250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA, 1));
            X(xF,yF);
            game.playerTurn = -1;
            if(verificareVictorie(tabla.matrice,250-8+i+tabla.offsetJOS-tabla.offsetSUS, 250-12+j+tabla.offsetDREAPTA-tabla.offsetSTANGA,game)){
                trasareLinieVictorie(50*(game.x1_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12), 50*(game.y1_win-tabla.offsetJOS+tabla.offsetSUS-250+8),50*(game.x2_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12),50*(game.y2_win-tabla.offsetJOS+tabla.offsetSUS-250+8));
                afisareWIN_LOSS(game.castigator);
            }
        }
    }
}
void plasarePiesaComputerUsor(Tabla &tabla, Game &game, stiva& S ,int x, int y){
    int i_tabla_player, j_tabla_player, i_matrice_player, j_matrice_player, i_random_bot, j_random_bot, a=0, b=0;
    double xC,yC;
    int x_pixeli_mutare_player,y_pixeli_mutare_player;
    int x_pixeli_mutare_bot,y_pixeli_mutare_bot;

    if (game.playerTurn == -1 && game.castigator == 0)
    {

        xC = (double)x/tabla.dimensiunePatrat;
        j_tabla_player = ceil(xC);
        x_pixeli_mutare_player = ceil(xC)*tabla.dimensiunePatrat;//coordonate matrice in pixeli

        yC = (double)y/tabla.dimensiunePatrat;
        i_tabla_player = ceil(yC);
        y_pixeli_mutare_player = ceil(yC)*tabla.dimensiunePatrat; // //coordonate matrice in pixeli

        i_matrice_player = 250-8+i_tabla_player+tabla.offsetJOS-tabla.offsetSUS; // coordonatele in matrice unde a pus piesa jucatorul
        j_matrice_player = 250-12+j_tabla_player+tabla.offsetDREAPTA-tabla.offsetSTANGA; // coordonatele in matrice unde a pus piesa jucatorul
        cout<<i_matrice_player<<"   "<<j_matrice_player<<endl;

        i_random_bot = -1; // coordonate matrice spate bot
        j_random_bot = -1;

        srand(time(NULL));
        for(int k = 1; k <= 20; k++){
                a = rand()%((i_matrice_player+2)-(i_matrice_player-2)+1)+(i_matrice_player-2);
                b = rand()%((j_matrice_player+2)-(j_matrice_player-2)+1)+(j_matrice_player-2);
                if(tabla.matrice[a][b] == 0 && estePozitieDinCadrulTablei(a,b,tabla) == 1){
                    i_random_bot = a;
                    j_random_bot = b;
                    break;
                }
        }



        if(i_random_bot == -1 && j_random_bot == -1){
            for(int i = i_matrice_player-2; i <= i_matrice_player+2 && i_random_bot == -1; i++)
                for(int j = j_matrice_player-2; j <= j_matrice_player+2; j++)
                    if(tabla.matrice[i][j] == 0 && estePozitieDinCadrulTablei(i,j,tabla) == 1){
                        i_random_bot = i;
                        j_random_bot = j;
                        break;
                    }
        }


        if(i_random_bot == -1 && j_random_bot == -1){

                for(int i = 244+tabla.offsetJOS-tabla.offsetSUS; i <= 257+tabla.offsetJOS-tabla.offsetSUS && i_random_bot == -1; i++){
                    for(int j = 239+tabla.offsetDREAPTA-tabla.offsetSTANGA; j <= 261+tabla.offsetDREAPTA-tabla.offsetSTANGA; j++){
                    if(tabla.matrice[i][j] == 0 && estePozitieDinCadrulTablei(i,j,tabla) == 1){
                        i_random_bot = i;
                        j_random_bot = j;
                        break;
                    }
                    }
                }
        }


        if(i_random_bot != -1 && j_random_bot != -1){
            tabla.matrice[i_random_bot][j_random_bot] = -1;
            push(S,creareMutare(i_random_bot, j_random_bot, -1));
            game.playerTurn = 1;

            x_pixeli_mutare_bot = x_pixeli_mutare_player + 50*(j_random_bot-j_matrice_player);
            y_pixeli_mutare_bot = y_pixeli_mutare_player + 50*(i_random_bot-i_matrice_player);
            O(x_pixeli_mutare_bot-tabla.dimensiunePatrat/2, y_pixeli_mutare_bot-tabla.dimensiunePatrat/2);
            cout<<i_random_bot<<"  "<<j_random_bot<<endl;


        if(verificareVictorie(tabla.matrice,i_random_bot, j_random_bot,game)){
            trasareLinieVictorie(50*(game.x1_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12), 50*(game.y1_win-tabla.offsetJOS+tabla.offsetSUS-250+8),50*(game.x2_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12),50*(game.y2_win-tabla.offsetJOS+tabla.offsetSUS-250+8));
            afisareWIN_LOSS(game.castigator);
            }
        }
    }


}
void plasarePiesaComputerHard(Tabla &tabla, Game &game,stiva& S ,int x, int y){

    int i_tabla_player, j_tabla_player, i_matrice_player, j_matrice_player, i_random_bot, j_random_bot, a=0, b=0;
    double xC,yC;
    int x_pixeli_mutare_player,y_pixeli_mutare_player;
    int x_pixeli_mutare_bot,y_pixeli_mutare_bot;
    int maxim = -1;
    int numarGlisariSus = 0, numarGlisariJos = 0, numarGlisariDreapta = 0, numarGlisariStanga = 0;

    if (game.playerTurn == -1 && game.castigator == 0)
    {

        xC = (double)x/tabla.dimensiunePatrat;
        j_tabla_player = ceil(xC);
        x_pixeli_mutare_player = ceil(xC)*tabla.dimensiunePatrat;//coordonate matrice in pixeli

        yC = (double)y/tabla.dimensiunePatrat;
        i_tabla_player = ceil(yC);
        y_pixeli_mutare_player = ceil(yC)*tabla.dimensiunePatrat; // //coordonate matrice in pixeli

        i_matrice_player = 250-8+i_tabla_player+tabla.offsetJOS-tabla.offsetSUS; // coordonatele in matrice unde a pus piesa jucatorul
        j_matrice_player = 250-12+j_tabla_player+tabla.offsetDREAPTA-tabla.offsetSTANGA; // coordonatele in matrice unde a pus piesa jucatorul
        cout<<i_matrice_player<<"   "<<j_matrice_player<<endl;

        i_random_bot = -1;
        j_random_bot = -1;


        // linie
        for(int k = i_matrice_player-1; k >= i_matrice_player-4; k--){
                if(importanta_Mutare(k,j_matrice_player,tabla) > maxim && tabla.matrice[k][j_matrice_player] == 0){
                    maxim = importanta_Mutare(k,j_matrice_player,tabla);
                    i_random_bot = k;
                    j_random_bot = j_matrice_player;

                }
        }

        // linie
        for(int k = i_matrice_player+1; k <= i_matrice_player+4; k++){
                if(importanta_Mutare(k,j_matrice_player,tabla) > maxim && tabla.matrice[k][j_matrice_player] == 0){
                    maxim = importanta_Mutare(k,j_matrice_player,tabla);
                    i_random_bot = k;
                    j_random_bot = j_matrice_player;

                }
        }

        //coloana
        for(int k = j_matrice_player-1; k >= j_matrice_player-4; k--){
                if(importanta_Mutare(i_matrice_player,k,tabla) > maxim && tabla.matrice[i_matrice_player][k] == 0){
                    maxim = importanta_Mutare(i_matrice_player,k,tabla);
                    i_random_bot = i_matrice_player;
                    j_random_bot = k;

                }
        }

        //coloana
        for(int k = j_matrice_player+1; k <= j_matrice_player+4; k++){
                if(importanta_Mutare(i_matrice_player,k,tabla) > maxim && tabla.matrice[i_matrice_player][k] == 0){
                    maxim = importanta_Mutare(i_matrice_player,k,tabla);
                    i_random_bot = i_matrice_player;
                    j_random_bot = k;

                }
        }


        //diagonala principala
        for(int k = 1; k <= 4; k++){
                if(importanta_Mutare(i_matrice_player+k,j_matrice_player+k,tabla) > maxim && tabla.matrice[i_matrice_player+k][j_matrice_player+k] == 0){
                    maxim = importanta_Mutare(i_matrice_player+k,j_matrice_player+k,tabla);
                    i_random_bot = i_matrice_player+k;
                    j_random_bot = j_matrice_player+k;

                }
        }


        //diagonala principala
        for(int k = 1; k <= 4; k++){
                if(importanta_Mutare(i_matrice_player-k,j_matrice_player-k,tabla) > maxim && tabla.matrice[i_matrice_player-k][j_matrice_player-k] == 0){
                    maxim = importanta_Mutare(i_matrice_player-k,j_matrice_player-k,tabla);
                    i_random_bot = i_matrice_player-k;
                    j_random_bot = j_matrice_player-k;

                }
        }

        // diagonala secundara
        for(int k = 1; k <= 4; k++){
                if(importanta_Mutare(i_matrice_player-k,j_matrice_player+k,tabla) > maxim && tabla.matrice[i_matrice_player-k][j_matrice_player+k] == 0){
                    maxim = importanta_Mutare(i_matrice_player-k,j_matrice_player+k,tabla);
                    i_random_bot = i_matrice_player-k;
                    j_random_bot = j_matrice_player+k;

                }
        }

        //diagonala secundara
        for(int k = 1; k <= 4; k++){
                if(importanta_Mutare(i_matrice_player+k,j_matrice_player-k,tabla) > maxim && tabla.matrice[i_matrice_player+k][j_matrice_player-k] == 0){
                    maxim = importanta_Mutare(i_matrice_player+k,j_matrice_player-k,tabla);
                    i_random_bot = i_matrice_player+k;
                    j_random_bot = j_matrice_player-k;

                }
        }






        if(i_random_bot != -1 && j_random_bot != -1 && estePozitieDinCadrulTablei(i_random_bot,j_random_bot,tabla) == 1){

            tabla.matrice[i_random_bot][j_random_bot] = -1;
            push(S,creareMutare(i_random_bot, j_random_bot, -1));
            game.playerTurn = 1;

            x_pixeli_mutare_bot = x_pixeli_mutare_player + 50*(j_random_bot-j_matrice_player);
            y_pixeli_mutare_bot = y_pixeli_mutare_player + 50*(i_random_bot-i_matrice_player);
            O(x_pixeli_mutare_bot-tabla.dimensiunePatrat/2, y_pixeli_mutare_bot-tabla.dimensiunePatrat/2);
            cout<<i_random_bot<<"  "<<j_random_bot<<endl;


            if(verificareVictorie(tabla.matrice,i_random_bot, j_random_bot,game)){
                trasareLinieVictorie(50*(game.x1_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12), 50*(game.y1_win-tabla.offsetJOS+tabla.offsetSUS-250+8),50*(game.x2_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12),50*(game.y2_win-tabla.offsetJOS+tabla.offsetSUS-250+8));
                afisareWIN_LOSS(game.castigator);
            }
        }

        else if(i_random_bot != -1 && j_random_bot != -1 && estePozitieDinCadrulTablei(i_random_bot,j_random_bot,tabla) == 0){
                numarGlisariDreapta = j_random_bot - 261 + tabla.offsetSTANGA - tabla.offsetDREAPTA;
                numarGlisariStanga =  239 - j_random_bot - tabla.offsetSTANGA + tabla.offsetDREAPTA;
                numarGlisariJos = i_random_bot - 257 + tabla.offsetSUS - tabla.offsetJOS;
                numarGlisariSus = 244 - i_random_bot + tabla.offsetJOS - tabla.offsetSUS;

                tabla.matrice[i_random_bot][j_random_bot] = -1;
                push(S,creareMutare(i_random_bot, j_random_bot, -1));
                game.playerTurn = 1;


                for(int k = 1; k <= numarGlisariStanga; k++){
                    functieMutareColoanaStanga(tabla);
                }

                for(int k = 1; k <= numarGlisariDreapta; k++){
                    functieMutareColoanaDreapta(tabla);
                }

                for(int k = 1; k <= numarGlisariSus; k++){
                    functieMutareLinieSus(tabla);
                }

                for(int k = 1; k <= numarGlisariJos; k++){
                    functieMutareLinieJos(tabla);

                }
                if(verificareVictorie(tabla.matrice,i_random_bot, j_random_bot,game)){
                trasareLinieVictorie(50*(game.x1_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12), 50*(game.y1_win-tabla.offsetJOS+tabla.offsetSUS-250+8),50*(game.x2_win-tabla.offsetDREAPTA+tabla.offsetSTANGA-250+12),50*(game.y2_win-tabla.offsetJOS+tabla.offsetSUS-250+8));
                afisareWIN_LOSS(game.castigator);
            }
    }
}
}


#endif // FUNCTII_H_INCLUDED
