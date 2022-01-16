#include<SDL.h> 
#include<SDL_ttf.h> 
#include<iostream>
#include "config_sdl.h"
using namespace std;
const int LARGEUR = 800; 
const int HAUTEUR = 480; 

void legende(SDL_Renderer* rendu) {
    SDL_Rect rect; 
   
    rect.x = LARGEUR-150;   
    rect.y = 0;  
    rect.w = 150;                
    rect.h = HAUTEUR;

    SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
    SDL_RenderFillRect(rendu, &rect);
}

void place_img(SDL_Texture* monImage, SDL_Rect posImg,SDL_Renderer* rendu) {
    SDL_RenderClear(rendu);

    SDL_RenderCopy(rendu, monImage, NULL, &posImg);

    SDL_RenderPresent(rendu);
}

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

    SDL_Surface* image = IMG_Load("panda.png");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        return -1;
    }

    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
    SDL_FreeSurface(image);

    SDL_Rect posImg;
    posImg.x = 0;
    posImg.y = 300;

    SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
    SDL_RenderCopy(rendu, monImage, NULL, &posImg);
    legende(rendu);
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
                if (posImg.x != 300) {
                    posImg.x += 100;
                    place_img(monImage, posImg, rendu);
                }

                break;
            case SDLK_LEFT:
                if (posImg.x != 0) {
                    posImg.x -= 100;
                    place_img(monImage, posImg, rendu);
                }
                break;
            }
        }

    }

    //DESTRUCTION FINAL 
    SDL_DestroyRenderer(rendu);

    SDL_DestroyWindow(win);


    SDL_Quit();
    return 0;
}