#include<SDL.h> 
#include<SDL_ttf.h> 
#include <iostream>
#include "constante_khalis.h"
#include "config_sdl.h"
#include "Constante_Thibault.h"
#include "Panda.h"
#include "Bambou.h"
#include "savefile.h"
#include"fonct_thibault.h"
#include "func_khalis.h"

using namespace std;

SDL_Color blanc = { 255,255,255 };
SDL_Color vert = { 0,255,0 };
SDL_Color bleu = { 0,0,255 };
SDL_Color rouge = { 255,0,0 };
SDL_Color violet = { 255,0,255 };



void carre(SDL_Renderer* rendu,int nb_cote) {
    int N = nb_cote;
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

void affiche_bambou(SDL_Renderer* rendu ,Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_cote) {
    SDL_SetRenderDrawColor(rendu, 50, 255, 0, 255);
    SDL_Rect bambou;
    int N = nb_cote;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            bambou.x = 50 + j * 125+25;
            bambou.y = 50+ i * 125 +125 ;
            bambou.w = 5;
            bambou.h = -tab[i][j].taille * 1.5;
            SDL_RenderFillRect(rendu, &bambou);
            for (int k = 0; k < tab[i][j].taille/tab[i][j].vitesse; k++){
                SDL_RenderDrawLine(rendu, bambou.x - 5, bambou.y, bambou.x + 10, bambou.y);
            }
        }
    }
    SDL_RenderPresent(rendu);
}

void coupe(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int posx, int posy) {
    tab[posy][posx].taille = tab[posy][posx].vitesse;
}

int init(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_cote) {

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
    SDL_Renderer* rendu = SDL_CreateRenderer(
        win,  //nom de la fenêtre
        -1, //par défaut
        SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

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

    SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);

    SDL_Rect rect; //on définit le rectangle à tracer

                                //SDL_Rect est un type struct        

    rect.x = LARGEUR - 100;  //coin en haut à gauche

    rect.y = HAUTEUR - 75;  //coin en haut à gauche

    rect.w = 80;                //largeur

    rect.h = 20;                //hauteur

    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc

    SDL_RenderDrawRect(rendu, &rect); //on trace un rectangle vide


    SDL_Rect positionTexte;

    positionTexte.x = LARGEUR - 98;

    positionTexte.y = HAUTEUR - 75;

    SDL_Texture* texture = loadText(rendu, "Start/Stop", blanc, font);

    SDL_QueryTexture(texture, NULL, NULL, &positionTexte.w, &positionTexte.h);

    SDL_RenderCopy(rendu, texture, NULL, &positionTexte);

    SDL_DestroyTexture(texture);

    SDL_RenderPresent(rendu);

    SDL_Rect posImg;
    posImg.x = 100;
    posImg.y = 100;

    SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
    SDL_RenderCopy(rendu, monImage, NULL, &posImg);

    carre(rendu,nb_cote);
    ecrit(rendu, font);
    affiche_bambou(rendu,tab,nb_cote);
    int Taille = sqrt_nb_bambou;
    SDL_RenderPresent(rendu);
    Panda panda;
    panda.posx = 0;
    panda.posy = 0;
    panda.batterie = 100;
    panda.distance = 0;
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
                update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 1);
                break;

            case SDLK_LEFT:
                update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3);
                break;

            case SDLK_UP:
                update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4);
                break;

            case SDLK_DOWN:
                update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 2);
                break;

            case SDLK_RETURN:
                SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                SDL_RenderClear(rendu);
                croissance_bambouseraie(tab, nb_cote);
                coupe(tab, panda.posx, panda.posy);
                place_img(monImage, posImg, rendu);
                carre(rendu,nb_cote);
                ecrit(rendu, font);
                affiche_bambou(rendu,tab,nb_cote);
                break;

            /*case SDL_MOUSEBUTTONUP://appui souris

                if (event.button.button == SDL_BUTTON_LEFT) {//si on clique bouton gauche

                    if (event.button.x > rect.x && event.button.x<rect.x + rect.w && event.button.y>rect.y && event.button.y < rect.y + rect.h) {                                                                                                                                                                                                                                    //on retrace le rectangle avec une couleur aléatoire

                        SDL_SetRenderDrawColor(rendu, rand() % 256, rand() % 256, rand() % 256, 255); //on définit une clouleur aleatoire

                        SDL_RenderDrawRect(rendu, &rect); //on trace un rectangle video


                    }

                    SDL_RenderPresent(rendu);//on rafraichit
                }

                break;*/
            }
        }
    }

    //DESTRUCTION FINAL 
    SDL_DestroyRenderer(rendu);

    SDL_DestroyWindow(win);


    SDL_Quit();
    return 0;
}


void update_movment(SDL_Rect &posImg, Panda &panda, SDL_Renderer* rendu, TTF_Font* font, Bambou tab[][sqrt_nb_bambou], SDL_Texture* monImage, int& nb_cote, int direction) {
    if (direction == 1) {
        if (posImg.x != 100 + 125 * (nb_cote - 1)) {
            posImg.x += 125;
            panda.posx++;
        }
    }
    else if (direction == 2) {
        if (posImg.y != 100 + 125 * (nb_cote - 1)) {
            posImg.y += 125;
            panda.posy++;
        }
    }
    else if (direction == 3) {
        if (posImg.x != 100) {
            posImg.x -= 125;
            panda.posx--;
        }
    }
    else if (direction == 4) {
        if (posImg.y != 100) {
            posImg.y -= 125;
            panda.posy--;
        }
    }
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);
    place_img(monImage, posImg, rendu);
    carre(rendu, nb_cote);
    ecrit(rendu, font);
    affiche_bambou(rendu, tab, nb_cote);
}