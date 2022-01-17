#include <SDL.h> //ne pas oublier

#include <SDL_ttf.h> //ne pas oublier

#include <iostream>

#include "config_sdl.h"

#include "constante_khalis.h"

using namespace std;

/*
int main(int argn, char* argv[]) {//entête imposée

    //ouverture de la SDL

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {

        cout << "Echec à l’ouverture";

        return 1;

    }

    //on ouvre la police de caractères

    TTF_Init();

    TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\calibri.ttf", 18);


    //on crée la fenêtre

    SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",

        SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED

        SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 

        LARGEUR,                         //largeur en pixels                        

        HAUTEUR,                         //hauteur en pixels

        SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)

    );

    if (win == NULL)

        cout << "erreur ouverture fenetre";

    //Création d’un dessin associé à la fenêtre (1 seul renderer par fenetre)

    SDL_Renderer* rendu = SDL_CreateRenderer(

        win,  //nom de la fenêtre

        -1, //par défaut

        SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

    SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);

    SDL_Rect rect; //on définit le rectangle à tracer

                                //SDL_Rect est un type struct        

    rect.x = LARGEUR - 100;  //coin en haut à gauche

    rect.y = HAUTEUR - 75 ;  //coin en haut à gauche

    rect.w = 80;                //largeur

    rect.h = 20;                //hauteur

    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc

    SDL_RenderDrawRect(rendu, &rect); //on trace un rectangle vide

    SDL_Color blanc = { 255, 255, 255 };

    SDL_Rect positionTexte;

    positionTexte.x = LARGEUR - 98;

    positionTexte.y = HAUTEUR - 75;

    SDL_Texture* texture = loadText(rendu, "Start/Stop", blanc, font);

    SDL_QueryTexture(texture, NULL, NULL, &positionTexte.w, &positionTexte.h);

    SDL_RenderCopy(rendu, texture, NULL, &positionTexte);

    SDL_DestroyTexture(texture);

    SDL_RenderPresent(rendu);

    bool continuer = true;   //booléen fin de programme

    SDL_Event event;//gestion des évènements souris/clavier, 

    while (continuer)

    {

        SDL_WaitEvent(&event);//attente d’un évènement

        switch (event.type) //test du type d’évènement

        {

        case SDL_QUIT: //clic sur la croix de fermeture

            continuer = false;

            break;

        case SDL_MOUSEBUTTONUP://appui souris

            if (event.button.button == SDL_BUTTON_LEFT) {//si on clique bouton gauche

                if (event.button.x > rect.x && event.button.x<rect.x + rect.w && event.button.y>rect.y && event.button.y < rect.y + rect.h) {                                                                                                                                                                                                                                    //on retrace le rectangle avec une couleur aléatoire

                    SDL_SetRenderDrawColor(rendu, rand() % 256, rand() % 256, rand() % 256, 255); //on définit une clouleur aleatoire

                    SDL_RenderDrawRect(rendu, &rect); //on trace un rectangle video

                    
                }

                SDL_RenderPresent(rendu);//on rafraichit
            }

            break;
        }
       
    }

    //destruction du renderer à la fin

    SDL_DestroyRenderer(rendu);

    //destruction à la fin

    SDL_DestroyWindow(win);   //equivalent du delete

    //fermeture

    TTF_CloseFont(font); //on ferme la font

    TTF_Quit(); //on quitte la TTF

    SDL_Quit();

    return 0;

}*/