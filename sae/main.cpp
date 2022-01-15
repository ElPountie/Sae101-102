#include<SDL.h> //ne pas oublier
#include<SDL_ttf.h> //ne pas oublier
#include<iostream>
#include <fstream>
#include "config_sdl.h"

using namespace std;

const int TAILLEX = 900, TAILLEY = 700;


int main(int argn, char* argv[]) {//entête imposée
   //ouverture de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Echec à l’ouverture";
        return 1;
    }

    //on crée la fenêtre
    SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",
        SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
        SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
        TAILLEX,                         //largeur en pixels                        
        TAILLEY,                         //hauteur en pixels
        SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
    );

    if (win == NULL)
        cout << "erreur ouverture fenetre";

    SDL_Renderer* rendu = SDL_CreateRenderer(
        win,  //nom de la fenêtre
        -1, //par défaut
        SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

    bool continuer = true;   //booléen fin de programme
    SDL_Event event;//gestion des évènements souris/clavier, 
                                    //SDL_Event est de type struct

    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);

    //Clear the entire screen to our selected color.
    SDL_RenderClear(rendu);

    //Up until now everything was drawn behind the scenes.
    //This will show the new, red contents of the window.

    SDL_Surface* image = IMG_Load("panda.png");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        return 1001; //erreur chargement image 
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image);

    SDL_Rect position;
    position.x = 0;
    position.y = 300;
    SDL_QueryTexture(monImage, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(rendu, monImage, NULL, &position);

    SDL_RenderPresent(rendu);


    while (continuer)
    {

        SDL_RenderCopy(rendu, monImage, NULL, &position); // copie de surface grâce au SDL_Renderer

        SDL_RenderPresent(rendu); //Affichage
        SDL_RenderClear(rendu);
        SDL_WaitEvent(&event);//attente d’un évènement
        switch (event.type) //test du type d’évènement
        {
        case SDL_QUIT: //clic sur la croix de fermeture
                                        //on peut enlever SDL_Delay
            continuer = false;
            break;

        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                if (position.x != 300) {
                    position.x += 100;

                    SDL_RenderPresent(rendu);
                }

                break;
            case SDLK_LEFT:
                if (position.x != 0) {
                    position.x-=100;

                    SDL_RenderPresent(rendu);
                }

                break;
            }
        }
    }
}