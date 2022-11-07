#include <iostream>
#include <winbgim.h>
#include <graphics.h>
#include <cmath>
#include <conio.h>
#include "functii.h"
#include "structuri.h"
#include "functii_grafica.h"


Tabla tabla;
Game game;
stiva S;
int x,y;


int main()
{
    //incepere joc

    afisareMeniu();

    game.ecranMeniu = 1;
    game.ecranJoc = 0;
    game.ecranReguli = 0;
    game.ecranSelectareDificultate = 0;
    game.computerDificulty = 0;
    game.vsComputer = 0;
    game.vsPlayer = 0;

    goleste(S);
    initializeaza(S);



    while(1)
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();


            if(game.ecranJoc == 1)
            {
                if(clickedSageataSus(x,y) == 1 && game.castigator == 0)
                    functieMutareLinieSus(tabla);


                else if(clickedSageataJos(x,y) == 1 && game.castigator == 0)
                    functieMutareLinieJos(tabla);

                else if(clickedSageataStanga(x,y) == 1 && game.castigator == 0)
                    functieMutareColoanaStanga(tabla);


                else if(clickedSageataDreapta(x,y) == 1 && game.castigator == 0)
                    functieMutareColoanaDreapta(tabla);


                else if(clickedSageataMutareBack(x,y) == 1 && game.castigator == 0){
                    if(game.vsPlayer == 1)
                        functieMutareInapoi(S,tabla,game);
                    else if(game.vsComputer == 1){
                        functieMutareInapoi(S,tabla,game);
                        functieMutareInapoi(S,tabla,game);
                    }
                }


                else if (clickedButonReset(x,y) == 1)
                {
                    initializareObiectTabla(tabla,1250,750, WHITE,50);
                    resetareObiectGame(game);
                    goleste(S);
                    initializeaza(S);
                    game.ecranJoc = 1;
                    game.ecranMeniu = 0;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    closegraph();
                    afisareTabla(tabla);


                }
                else if(clickedIconMeniu(x,y) == 1)
                {
                    game.ecranJoc = 0;
                    game.ecranMeniu = 1;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    closegraph();
                    afisareMeniu();
                }


                else if(game.castigator == 0)
                {
                    if(game.vsComputer == 1){

                            if(game.computerDificulty == 1){
                                    plasarePiesaPlayer(tabla,game,S,x,y);
                                    plasarePiesaComputerUsor(tabla,game,S,x,y);

                            }
                            else if(game.computerDificulty == 2){
                                    plasarePiesaPlayer(tabla,game,S,x,y);
                                    plasarePiesaComputerHard(tabla,game,S,x,y);
                            }
                    }

                    else if(game.vsPlayer == 1)
                        plasarePiesaAmbiiPlayeri(tabla,game,S,x,y);
                }

            }





            else if(game.ecranMeniu == 1)
            {
                if(clickedButonVSPlayer(x,y) == 1)
                {
                    goleste(S);
                    initializeaza(S);
                    resetareObiectGame(game);
                    game.ecranJoc = 1;
                    game.ecranMeniu = 0;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    game.vsComputer = 0;
                    game.vsPlayer = 1;
                    closegraph();
                    initializareObiectTabla(tabla,1250,750, WHITE,50);
                    afisareTabla(tabla);
                }
                else if(clickedButonVSBot(x,y) == 1)
                {
                    goleste(S);
                    initializeaza(S);
                    resetareObiectGame(game);
                    game.ecranJoc = 0;
                    game.ecranMeniu = 0;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 1;
                    game.vsComputer = 1;
                    game.vsPlayer = 0;
                    afisareEcranSelectareDificultate();

                }
                else if(clickedButonReguli(x,y) == 1)
                {
                    game.ecranJoc = 0;
                    game.ecranSelectareDificultate = 0;
                    game.ecranMeniu = 0;
                    game.ecranReguli = 1;
                    afisarePanouReguli();

                }
            }



            else if(game.ecranReguli == 1)
            {
                if(clickedSageataBackReguli(x,y) == 1)
                {
                    game.ecranJoc = 0;
                    game.ecranMeniu = 1;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    afisareMeniuFaraINITWINDOW();

                }
            }






            else if (game.ecranSelectareDificultate == 1)
            {

                if(clickedButonBackSelectareDificultate(x,y) == 1)
                {
                    game.ecranJoc = 0;
                    game.ecranMeniu = 1;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    afisareMeniuFaraINITWINDOW();

                }
                else if(clickedButonUsor(x,y) == 1)
                {
                    goleste(S);
                    initializeaza(S);
                    resetareObiectGame(game);
                    game.computerDificulty = 1;
                    game.ecranJoc = 1;
                    game.ecranMeniu = 0;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    closegraph();
                    initializareObiectTabla(tabla,1250,750, WHITE,50);
                    afisareTabla(tabla);

                }
                else if(clickedButonGreu(x,y) == 1)
                {
                    goleste(S);
                    initializeaza(S);
                    resetareObiectGame(game);
                    game.computerDificulty = 2;
                    game.ecranJoc = 1;
                    game.ecranMeniu = 0;
                    game.ecranReguli = 0;
                    game.ecranSelectareDificultate = 0;
                    closegraph();
                    initializareObiectTabla(tabla,1250,750, WHITE,50);
                    afisareTabla(tabla);

                }

            }
        }
    }

    return 0;
}
