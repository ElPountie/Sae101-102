#include <SDL.h> 
#include <SDL_ttf.h> 
#include <iostream>
#include "constante_khalis.h"
#include "config_sdl.h"
using namespace std;

SDL_Color blanc = { 255,255,255 };
SDL_Color vert = { 0,255,0 };
SDL_Color bleu = { 0,0,255 };
SDL_Color rouge = { 255,0,0 };
SDL_Color violet = { 255,0,255 };

void carre(SDL_Renderer* rendu) {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            SDL_Rect carre;
            carre.x = 50 + j * 125;
            carre.y = 50 + i * 125;
            carre.w = 125;
            carre.h = 125;
            SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
            SDL_RenderDrawRect(rendu, &carre);
        }
    }
}

void place_img(SDL_Texture* monImage, SDL_Rect posImg, SDL_Renderer* rendu) {

    SDL_RenderCopy(rendu, monImage, NULL, &posImg);

    SDL_RenderPresent(rendu);
}

/*
void ecrit(SDL_Renderer* rendu, TTF_Font* font) {
    SDL_Rect pos_Legende;
    pos_Legende.x = LARGEUR - 200;
    pos_Legende.y = 50;
    SDL_Texture* texture1 = loadText(rendu, "Legende", blanc, font);
    SDL_QueryTexture(texture1, NULL, NULL, &pos_Legende.w, &pos_Legende.h);
    SDL_RenderCopy(rendu, texture1, NULL, &pos_Legende);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture1);

    pos_Legende.x = LARGEUR - 200;
    pos_Legende.y = 100;
    SDL_Texture* texture2 = loadText(rendu, "haut.max", vert, font);
    SDL_QueryTexture(texture2, NULL, NULL, &pos_Legende.w, &pos_Legende.h);
    SDL_RenderCopy(rendu, texture2, NULL, &pos_Legende);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture2);


    pos_Legende.x = LARGEUR - 200;
    pos_Legende.y = 150;
    SDL_Texture* texture3 = loadText(rendu, "haut.moy", violet, font);
    SDL_QueryTexture(texture3, NULL, NULL, &pos_Legende.w, &pos_Legende.h);
    SDL_RenderCopy(rendu, texture3, NULL, &pos_Legende);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture3);


    pos_Legende.x = LARGEUR - 200;
    pos_Legende.y = 200;
    SDL_Texture* texture4 = loadText(rendu, "haut_min", rouge, font);
    SDL_QueryTexture(texture4, NULL, NULL, &pos_Legende.w, &pos_Legende.h);
    SDL_RenderCopy(rendu, texture4, NULL, &pos_Legende);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture4);

    pos_Legende.x = LARGEUR - 200;
    pos_Legende.y = 250;
    SDL_Texture* texture5 = loadText(rendu, "nb coupes", bleu, font);
    SDL_QueryTexture(texture5, NULL, NULL, &pos_Legende.w, &pos_Legende.h);
    SDL_RenderCopy(rendu, texture5, NULL, &pos_Legende);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture5);

}
*/

void affiche_bambou(SDL_Renderer* rendu) {
    SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
    SDL_Rect bambou;
    int N = 3;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            bambou.x = 50 + j * 125+25;
            bambou.y = (50 + (i+1) * 125)-60 ;
            bambou.w = 5;
            bambou.h = 60;//dans la table
            SDL_RenderFillRect(rendu, &bambou);
            for (int k = 0; k < N; k++){
                SDL_RenderDrawLine(rendu, bambou.x - 5, bambou.y +(bambou.h/N)*k, bambou.x + 10, bambou.y  + (bambou.h /N)*k);
            }
        }
    }
}

