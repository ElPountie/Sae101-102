#include<SDL.h> 
#include<SDL_ttf.h> 
#include <iostream>
#include "constante_khalis.h"
#include "config_sdl.h"
#include "Constante_Thibault.h"
using namespace std;

SDL_Color blanc = { 255,255,255 };
SDL_Color vert = { 0,255,0 };
SDL_Color bleu = { 0,0,255 };
SDL_Color rouge = { 255,0,0 };
SDL_Color violet = { 255,0,255 };



void carre(SDL_Renderer* rendu) {
    int N = sqrt(nb_bambou);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
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

void affiche_bambou(SDL_Renderer* rendu) {
    SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
    SDL_Rect bambou;
    int N = sqrt(nb_bambou);
    int L = h_start_bambou;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            bambou.x = 50 + j * 125+25;
            bambou.y = 50+(i+1)*125-40 ;
            bambou.w = 5;
            bambou.h = N*10;//dans la table
            SDL_RenderFillRect(rendu, &bambou);
            /*for (int k = 0; k < L; k++) {
                SDL_RenderDrawLine(rendu, bambou.x - 5, bambou.y +(bambou.h/L)*k, bambou.x + 10, bambou.y  + (bambou.h /L)*k);
            }*/
        }
    }
}

void coupe(SDL_Renderer* rendu,SDL_Rect pos_panda) {
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_Rect cache;
    cache.x = pos_panda.x - 30;
    cache.y = pos_panda.y- 2;
    cache.h = 60-3;
    cache.w = 20;
    SDL_RenderFillRect(rendu, &cache);
    SDL_RenderPresent(rendu);
}

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Echec � l�ouverture";
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",
        SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
        SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
        LARGEUR,                         //largeur en pixels                        
        HAUTEUR,                         //hauteur en pixels
        SDL_WINDOW_SHOWN //d�autres options (plein ecran, resizable, sans bordure...)
    );
    if (win == NULL)
        cout << "erreur ouverture fenetre";
    SDL_Renderer* rendu = SDL_CreateRenderer(
        win,  //nom de la fen�tre
        -1, //par d�faut
        SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommand�e

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("calibri.ttf", 25);

 



    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);

    //IMPORTATION IMG PANDA

    SDL_Surface* image = IMG_Load("panda.png");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        return -1;
    }

    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
    SDL_FreeSurface(image);

    SDL_Rect posImg;
    posImg.x = 100;
    posImg.y = 100;

    SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
    SDL_RenderCopy(rendu, monImage, NULL, &posImg);

    carre(rendu);
    ecrit(rendu, font);
    affiche_bambou(rendu);
    SDL_RenderPresent(rendu);

    //CREATION BOUCLE EVENT 
    bool continuer = true;
    SDL_Event event;

    while (continuer)
    {


        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = false;
            break;
        case SDL_KEYDOWN:

            switch (event.key.keysym.sym) {

            case SDLK_RIGHT:
                if (posImg.x != 600) {
                    posImg.x += 125;
                    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                    SDL_RenderClear(rendu);
                    carre(rendu);
                    ecrit(rendu, font);
                    affiche_bambou(rendu);
                    place_img(monImage, posImg, rendu);
                }

                break;
            case SDLK_LEFT:
                if (posImg.x != 100) {
                    posImg.x -= 125;
                    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                    SDL_RenderClear(rendu);
                    carre(rendu);
                    ecrit(rendu, font);
                    affiche_bambou(rendu);
                    place_img(monImage, posImg, rendu);
                }
                break;
            case SDLK_UP:
                if (posImg.y != 100) {
                    posImg.y -= 125;
                    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                    SDL_RenderClear(rendu);
                    carre(rendu);
                    ecrit(rendu, font);
                    affiche_bambou(rendu);
                    place_img(monImage, posImg, rendu);
                }
                break;
            case SDLK_DOWN:
                if (posImg.y != 600) {
                    posImg.y += 125;
                    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                    SDL_RenderClear(rendu);
                    carre(rendu);
                    ecrit(rendu, font);
                    affiche_bambou(rendu);
                    place_img(monImage, posImg, rendu);
                }
                break;
            case SDLK_RETURN:
                SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                SDL_RenderClear(rendu);
                place_img(monImage, posImg, rendu);
                carre(rendu);
                ecrit(rendu, font);
                affiche_bambou(rendu);
                coupe(rendu,posImg);
 
            }
        }
    }

    //DESTRUCTION FINAL 
    SDL_DestroyRenderer(rendu);

    SDL_DestroyWindow(win);


    SDL_Quit();
    return 0;
}
