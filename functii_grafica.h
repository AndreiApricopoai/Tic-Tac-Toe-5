#ifndef FUNCTII_GRAFICA_H_INCLUDED
#define FUNCTII_GRAFICA_H_INCLUDED
#include "functii.h"
#include "structuri.h"


void trasareLinieVictorie(int x1, int y1, int x2, int y2){
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,2);
    if(y1 == y2){
        line(x1-50,y1-25,x2,y1-25);
    }

    else if (x1 == x2){
        line(x1-25,y1-50,x2-25,y2);
    }

    else if (x1 < x2 && y2 < y1){
        line(x1-50,y1,x2,y2-50);
    }

    else if (x1 < x2 && y1 < y2){
        line(x1-50,y1-50,x2,y2);
    }
}
void afisareSageataStanga(int x, int y, int dim,int culoare){

    setcolor(culoare);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x+dim,y);
    line(x,y,x+dim/2,y-dim/2);
    line(x,y,x+dim/2,y+dim/2);
}
void afisareSageataDreapta(int x, int y, int dim,int culoare){

    setcolor(culoare);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x-dim,y);
    line(x,y,x-dim/2,y-dim/2);
    line(x,y,x-dim/2,y+dim/2);
}
void afisareSageataSus(int x, int y, int dim,int culoare){
    setcolor(culoare);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x,y+dim);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x-dim/2,y+dim/2);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x+dim/2,y+dim/2);
}
void afisareSageataJos(int x, int y, int dim,int culoare){

    setcolor(culoare);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x,y-dim);
    line(x,y,x-dim/2,y-dim/2);
    line(x,y,x+dim/2,y-dim/2);
}
void afisareSageataBack(int x, int y, int dim,int culoare){
    setcolor(culoare);
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x,y-dim);
    line(x,y,x-dim/2,y-dim/2);
    line(x,y,x+dim/2,y-dim/2);
    line(x,y-dim,x+dim-10,y-dim);
    line(x+dim-10,y-dim,x+dim-10,y);
}
void afisareIconitaMeniu(int x, int y, int dim,int culoare){
    setcolor(culoare);
    setlinestyle(SOLID_LINE,0,3);
    line(x-dim/2,y-dim/2,x-dim/2,y+dim/2);
    line(x,y-dim/2,x,y+dim/2);
    line(x+dim/2,y-dim/2,x+dim/2,y+dim/2);
}
void afisareIconitaReset(int x, int y, int dim, int fontSize, int culoare){

    setcolor(culoare); // culoare text
    setlinestyle(SOLID_LINE,0,3);
    line(x,y,x,y+dim/2);
    line(x,y,x+dim,y);
    line(x+dim,y,x+dim,y+dim/2);
    line(x,y+dim/2,x+dim,y+dim/2);
    settextstyle(10,0,fontSize); // font, dimensiune
    outtextxy(x+dim/6,y+dim/5-3,"RESET"); // afisare text setcolor(culoare)

}
void afisareTextPlayer(int x, int y, int dim, int player){

    if(player == 1)
    {
        setcolor(BLACK);
        settextstyle(10,0,dim);
        outtextxy(x,y,"PLAYER 1");
    }
    else
    {
        setcolor(BLACK);
        settextstyle(10,0,dim);
        outtextxy(x,y,"PLAYER 2");
    }

}
void afisareButonVSPlayer(int x, int y, int dim, int fontSize, int culoare){

    setcolor(culoare); // culoare text
    setlinestyle(SOLID_LINE,0,6);
    line(x,y,x,y+dim/2);
    line(x,y,x+dim,y);
    line(x+dim,y,x+dim,y+dim/2);
    line(x,y+dim/2,x+dim,y+dim/2);
    settextstyle(10,0,fontSize); // font, dimensiune
    outtextxy(x+dim/6-17,y+dim/5-3,"VS PlAYER"); // afisare text setcolor(culoare)


}
void afisareButonVSBot(int x, int y, int dim, int fontSize, int culoare){
    setcolor(culoare); // culoare text
    setlinestyle(SOLID_LINE,0,6);
    line(x,y,x,y+dim/2);
    line(x,y,x+dim,y);
    line(x+dim,y,x+dim,y+dim/2);
    line(x,y+dim/2,x+dim,y+dim/2);
    settextstyle(10,0,fontSize); // font, dimensiune
    outtextxy(x+dim/6+5,y+dim/5-3,"VS BOT"); // afisare text setcolor(culoare)
}
void afisareButonReguli(int x, int y, int dim, int fontSize, int culoare){
    setcolor(culoare); // culoare text
    setlinestyle(SOLID_LINE,0,4);
    line(x,y,x,y+dim/2);
    line(x,y,x+dim,y);
    line(x+dim,y,x+dim,y+dim/2);
    line(x,y+dim/2,x+dim,y+dim/2);
    settextstyle(10,0,fontSize); // font, dimensiune
    outtextxy(x+dim/6-5,y+dim/5-7,"reguli"); // afisare text setcolor(culoare)
}
void afisareButonEasy(int x, int y, int dim, int fontSize, int culoare){
    setcolor(culoare); // culoare text
    setlinestyle(SOLID_LINE,0,6);
    line(x,y,x,y+dim/2);
    line(x,y,x+dim,y);
    line(x+dim,y,x+dim,y+dim/2);
    line(x,y+dim/2,x+dim,y+dim/2);
    settextstyle(10,0,fontSize); // font, dimensiune
    outtextxy(x+dim/6,y+dim/5-7,"USOR"); // afisare text setcolor(culoare)
}
void afisareButonHard(int x, int y, int dim, int fontSize, int culoare){
    setcolor(culoare); // culoare text
    setlinestyle(SOLID_LINE,0,6);
    line(x,y,x,y+dim/2);
    line(x,y,x+dim,y);
    line(x+dim,y,x+dim,y+dim/2);
    line(x,y+dim/2,x+dim,y+dim/2);
    settextstyle(10,0,fontSize); // font, dimensiune
    outtextxy(x+dim/6,y+dim/5-7,"GREU"); // afisare text setcolor(culoare)
}
void afisareWIN_LOSS(int castigator){
    if(castigator == 1){
        setcolor(GREEN);
        settextstyle(10,0,4);
        outtextxy(300,12,"WIN");

        setcolor(RED);
        settextstyle(10,0,4);
        outtextxy(790,12,"LOSS");

    }
    else if (castigator == -1){
        setcolor(GREEN);
        settextstyle(10,0,4);
        outtextxy(790,12,"WIN");

        setcolor(RED);
        settextstyle(10,0,4);
        outtextxy(300,12,"LOSS");

    }
}
void afisareSimbol_X(int x, int y, int dim){ // pentru panou de langa player1 player2
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,2);
    line(x,y,x+dim,y+dim);
    line(x+dim,y,x,y+dim);
}
void afisareSimbol_O(int x, int y, int dim){ // pentru panou de langa player1 player2
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,2);
    circle(x,y,dim);
}
void X(int x, int y){ // pentru tabla
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,12,2);
    line(x-12,y-12,x-40,y-40);
    line(x-40,y-12,x-12,y-40);
}
void O(int x, int y){ // pentru tabla
    setcolor(RED);
    circle(x,y,16);
}
int clickedSageataStanga(int x, int y){
    if(x >= 1185 && x <= 1220 && y >= 230 && y <= 265)
        return 1;
    return 0;
}
int clickedSageataDreapta(int x, int y){
    if(x >= 1180 && x <= 1215 && y >= 305 && y <= 340)
        return 1;
    return 0;
}
int clickedSageataSus(int x, int y){
        if(x >= 1183 && x <= 1218 && y >= 100 && y <= 135)
        return 1;
    return 0;
}
int clickedSageataJos(int x, int y){
    if(x >= 1183 && x <= 1218 && y >= 165 && y <= 200)
        return 1;
    return 0;
}
int clickedSageataMutareBack(int x, int y){
    if(x >= 1170 && x <= 1220 && y >= 390 && y <= 425)
        return 1;
    return 0;
}
int clickedSageataBackReguli(int x, int y){
    if(x >= 25 && x <= 45 && y >= 15 && y <= 35)
        return 1;
    return 0;
}
int clickedIconMeniu(int x, int y){
    if(x >= 1183 && x <= 1217 && y >= 483 && y <= 517)
        return 1;
    return 0;
}
int clickedButonVSPlayer(int x, int y){
    if(x >= 80 && x <= 270 && y >= 150 && y <= 250)
        return 1;
    return 0;
}
int clickedButonVSBot(int x, int y){
    if(x >= 320 && x <= 520 && y >= 150 && y <= 250)
        return 1;
    return 0;
}
int clickedButonReguli(int x, int y){
    if(x >= 500 && x <= 585 && y >= 300 && y <= 380)
        return 1;
    return 0;
}
int clickedButonReset(int x, int y){
    if(x >= 1165 && x <= 1235 && y >= 575 && y <= 610)
        return 1;
    return 0;
}
int clickedButonUsor(int x, int y){
    if(x >= 100 && x <= 220 && y >= 170 && y <= 230)
        return 1;
    return 0;
}
int clickedButonGreu(int x, int y){
    if(x >= 350 && x <= 470 && y >= 170 && y <= 230)
        return 1;
    return 0;
}
int clickedButonBackSelectareDificultate(int x, int y){
    if(x >= 25 && x <= 45 && y >= 15 && y <= 35)
        return 1;
    return 0;
}


#endif // FUNCTII_GRAFICA_H_INCLUDED
