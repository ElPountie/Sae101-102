#include<SDL.h> 
#include<SDL_ttf.h> 
#include "config_sdl.h"
#include "constante_khalis.h"
#include <iostream>
#include "func_khalis.h"

using namespace std;

int main(int argn, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Echec à l’ouverture";
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",
        SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
        SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
        LARGEUR,                         //largeur en pixels                        
        HAUTEUR,                         //hauteur en pixels
        SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
    );
    if (win == NULL)
        cout << "erreur ouverture fenetre";

    //IMPORTATION IMG PANDA 

    SDL_Renderer* rendu = SDL_CreateRenderer(
        win,  //nom de la fenêtre
        -1, //par défaut
        SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("calibri.ttf", 25);

    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);


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
    posImg.y =100;

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
                carre(rendu);
                ecrit(rendu, font);
                affiche_bambou(rendu);
                coupe(rendu);
                place_img(monImage, posImg, rendu);
            }
        }
    }

    //DESTRUCTION FINAL 
    SDL_DestroyRenderer(rendu);

    SDL_DestroyWindow(win);


    SDL_Quit();
    return 0;
}