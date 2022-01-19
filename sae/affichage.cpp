#include<SDL.h> 
#include<SDL_ttf.h> 
#include <iostream>
#include <fstream>;
#include "constante_khalis.h"
#include "config_sdl.h"
#include "Constante_Thibault.h"
#include "Panda.h"
#include "Bambou.h"
#include "savefile.h"
#include"fonct_thibault.h"
#include "func_khalis.h"
#include "auto.h";
#include "Stats_struct.h"
#include "fonct_stats.h"


using namespace std;

SDL_Color blanc = { 255,255,255 };
SDL_Color vert = { 0,255,0 };
SDL_Color bleu = { 0,0,255 };
SDL_Color rouge = { 255,0,0 };
SDL_Color violet = { 255,0,255 };
SDL_Color noir = { 0,0,0 };
SDL_Color dark_grey = { 60,60,60 };

void ecrire_render(TTF_Font* font, SDL_Renderer* rendu, SDL_Color color, const char texte[100], int posx, int posy) {
    SDL_Rect pos_Legende;
    pos_Legende.x = posx;
    pos_Legende.y = posy;
    SDL_Texture* texture = loadText(rendu, texte, color, font);
    SDL_QueryTexture(texture, NULL, NULL, &pos_Legende.w, &pos_Legende.h);
    SDL_RenderCopy(rendu, texture, NULL, &pos_Legende);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture);
}

void recharge(SDL_Renderer* rendu) {
    SDL_Rect batterie;
    batterie.x = 150;
    batterie.y = 50;
    batterie.w = 25;
    batterie.h = 25;
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderDrawRect(rendu, &batterie);
}

void nb_coupes(SDL_Renderer* rendu,TTF_Font* font,int nb_coupe) {
    ecrire_render(font, rendu, bleu, "nombres coupes : ", 50, 675);
    char txt[1000];
    sprintf_s(txt, "%d", nb_coupe);
    ecrire_render(font, rendu, bleu, txt, 400, 675);
}

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
    ecrire_render(font, rendu, blanc, "haut.min", LARGEUR - 670, HAUTEUR-475);
    ecrire_render(font, rendu, vert, "haut.max", LARGEUR - 670, HAUTEUR - 375);
    ecrire_render(font, rendu, violet, "haut.moy", LARGEUR - 670, HAUTEUR - 275);
}

void affiche_bambou(SDL_Renderer* rendu ,Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_cote) {
    SDL_SetRenderDrawColor(rendu, 50, 255, 0, 255);
    SDL_Rect bambou;
    int N = nb_cote;
    int k = 0;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            k = 0;
            bambou.x = 50 + j * 125 + 25;
            bambou.y = 50 + i * 125 + 125;
            bambou.w = 5;
            bambou.h = -tab[i][j].taille * 1.5;
            SDL_RenderFillRect(rendu, &bambou);
            tmp = tab[i][j].taille / tab[i][j].vitesse;
            do
            {
                SDL_RenderDrawLine(rendu, bambou.x - 5, bambou.y - (k* tab[i][j].vitesse) *1.5 , bambou.x + 10, bambou.y - (k * tab[i][j].vitesse)*1.5);
                k++;
            } while (k < tmp);
        }
    }
    SDL_RenderPresent(rendu);
}

void coupe(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int posx, int posy) {
    tab[posy][posx].taille = tab[posy][posx].vitesse;
}

void statistique(SDL_Renderer* rendu, Bambou tab[][sqrt_nb_bambou]){
    Stats T[100];
    int i;
    for (i = 0; i < 100; i++){
        T[i].min = 0;
    }
    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
    SDL_Rect stat;
    stat.x = LARGEUR - 550;
    stat.y = HAUTEUR - 500;
    stat.h = 200;
    stat.w = 500;
    SDL_RenderDrawRect(rendu, &stat);

    stat.x = LARGEUR - 550;
    stat.y = HAUTEUR - 400;
    stat.h = 200;
    stat.w = 500;
    SDL_RenderDrawRect(rendu, &stat);
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    init_tab(T, tab);
    i = 0;
    while (i<100){
        if (i == 0){
            SDL_RenderDrawLine(rendu, LARGEUR - 550, 2*((T[i].min) * (HAUTEUR - 500)), LARGEUR - 540, 2*((T[i].min) * (HAUTEUR - 500)));
        }
        else {
            SDL_RenderDrawLine(rendu, LARGEUR - 550, (T[i-1].min) * (HAUTEUR - 500), LARGEUR - 540, (T[i].min) * (HAUTEUR - 500));
        }
        i++;
    }
    SDL_RenderPresent(rendu);
}

void batterire(SDL_Renderer* rendu, int charge) {

    SDL_Rect batterie;    
    batterie.x = 700;
    batterie.y = 175;   
    batterie.h = -120;
    batterie.w = 40;
    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
    SDL_RenderFillRect(rendu, &batterie);

    SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
    batterie.h = -charge;
    batterie.w = 30;
    batterie.x = 705;
    batterie.y = 175;

    SDL_RenderFillRect(rendu, &batterie);
    SDL_Surface* image = IMG_Load("eclair.png");
    if (!image)
    {
        cout << "erreur";
        return;
    }

    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
    SDL_FreeSurface(image);



    SDL_Rect posImg;
    posImg.x = 705;
    posImg.y = 100;

    SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
    SDL_RenderCopy(rendu, monImage, NULL, &posImg);
    SDL_DestroyTexture(monImage);

    SDL_RenderPresent(rendu);

}

void background(SDL_Renderer* rendu) {
    SDL_Surface* image = IMG_Load("background.png");
    if (!image)
    {
        cout << "erreur";
        return;
    }

    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
    SDL_FreeSurface(image);



    SDL_Rect posImg;
    posImg.x = 0;
    posImg.y = 0;

    SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
    SDL_RenderCopy(rendu, monImage, NULL, &posImg);
    SDL_DestroyTexture(monImage);

    SDL_RenderPresent(rendu);
}

void message_batterie(SDL_Renderer* rendu, TTF_Font* font) {
    SDL_Rect mess_batterie;
    mess_batterie.x = 50;
    mess_batterie.y = HAUTEUR/2;
    SDL_Texture* texture = loadText(rendu, "VOUS N'AVEZ PLUS DE BATTERIE", rouge, font);
    SDL_QueryTexture(texture, NULL, NULL, &mess_batterie.w, &mess_batterie.h);
    SDL_RenderCopy(rendu, texture, NULL, &mess_batterie);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture);
}

void controle(SDL_Renderer* rendu, TTF_Font* font) {
    SDL_Rect direction;
    direction.x = 800;
    direction.y = 675;
    SDL_Texture* texture = loadText(rendu, " DIRECTION ", dark_grey, font);
    SDL_QueryTexture(texture, NULL, NULL, &direction.w, &direction.h);
    SDL_RenderCopy(rendu, texture, NULL, &direction);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture);

    SDL_Surface* image = IMG_Load("arrow.png");
    if (!image)
    {
        cout << "erreur";
        return;
    }

    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
    SDL_FreeSurface(image);



    SDL_Rect posImg;
    posImg.x = 700;
    posImg.y = 650;

    SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
    SDL_RenderCopy(rendu, monImage, NULL, &posImg);
    SDL_DestroyTexture(monImage);

    SDL_RenderPresent(rendu);

    SDL_Rect entree;
    entree.x = 1100;
    entree.y = 675;
    SDL_Texture* texture2 = loadText(rendu, " COUPER ", dark_grey, font);
    SDL_QueryTexture(texture2, NULL, NULL, &entree.w, &entree.h);
    SDL_RenderCopy(rendu, texture2, NULL, &entree);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture2);

    SDL_Surface* image2 = IMG_Load("return.png");
    if (!image2)
    {
        cout << "erreur";
        return;
    }

    SDL_Texture* monImage2 = SDL_CreateTextureFromSurface(rendu, image2);
    SDL_FreeSurface(image2);



    SDL_Rect posImg2;
    posImg2.x = 1025;
    posImg2.y = 640;

    SDL_QueryTexture(monImage2, NULL, NULL, &posImg2.w, &posImg2.h);
    SDL_RenderCopy(rendu, monImage2, NULL, &posImg2);
    SDL_DestroyTexture(monImage2);


    SDL_RenderPresent(rendu);
}

void bouton(SDL_Renderer* rendu, TTF_Font* font) {
    SDL_Rect bouton;
    bouton.x = 450;
    bouton.y = 675;
    SDL_Texture* texture = loadText(rendu, "START/STOP", noir, font);
    SDL_QueryTexture(texture, NULL, NULL, &bouton.w, &bouton.h);
    SDL_RenderCopy(rendu, texture, NULL, &bouton);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture);
}


// Creation Menue


int menue() {

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
    TTF_Font* font_Title = TTF_OpenFont("04B_30__.ttf", 70);

    TTF_Font* font_txt = TTF_OpenFont("8-bit-pusab.ttf", 25);


    background(rendu);

    SDL_Rect titleTxt; // Titre

    titleTxt.x = 350 ;

    titleTxt.y = 50;

    titleTxt.w = 100;
    titleTxt.h = 100;

    SDL_Texture* title = loadText(rendu, "Panda Robot",noir, font_Title);

    SDL_QueryTexture(title, NULL, NULL, &titleTxt.w, &titleTxt.h);

    SDL_RenderCopy(rendu, title, NULL, &titleTxt);

    SDL_DestroyTexture(title);

    SDL_Rect positionTexteBienvenue; // Texte de bienvenue

    positionTexteBienvenue.x = 400;

    positionTexteBienvenue.y = 300;

    SDL_Texture* texture_Bienvenue = loadText(rendu, "Selectionnez un mode : ", noir, font_txt);

    SDL_QueryTexture(texture_Bienvenue, NULL, NULL, &positionTexteBienvenue.w, &positionTexteBienvenue.h);

    SDL_RenderCopy(rendu, texture_Bienvenue, NULL, &positionTexteBienvenue);

    SDL_DestroyTexture(texture_Bienvenue);


    //SDL_RenderPresent(rendu);

    SDL_Rect Oui; //Bouton oui ou tout va etre mal dispos� mais j'ai confiance en toi khalis :)
    Oui.x = 350;
    Oui.y = 400;
    Oui.w = 300;
    Oui.h = 50;
    SDL_SetRenderDrawColor(rendu, 233, 170, 240, 255); //pinceau bleu

    SDL_RenderFillRect(rendu, &Oui);

    SDL_Rect positionTexteOui; // OUI !

    positionTexteOui.x = 360;

    positionTexteOui.y = 400;

    SDL_Texture* texture_Oui = loadText(rendu, " Automatique", noir, font_txt);

    SDL_QueryTexture(texture_Oui, NULL, NULL, &positionTexteOui.w, &positionTexteOui.h);

    SDL_RenderCopy(rendu, texture_Oui, NULL, &positionTexteOui);

    SDL_DestroyTexture(texture_Oui);

    //SDL_RenderPresent(rendu);

    SDL_Rect Non; //Bouton Non ou tout va etre mal dispos� mais j'ai confiance en toi khalis :)
    Non.x = 725;
    Non.y = 400;
    Non.w = 300;
    Non.h = 50;
    SDL_SetRenderDrawColor(rendu, 127, 231, 240, 255); //pinceau rouge

    SDL_RenderFillRect(rendu, &Non);

    SDL_Rect positionTexteNon; // Non ...

    positionTexteNon.x = 780 ;

    positionTexteNon.y = 400;

    SDL_Texture* texture_Non = loadText(rendu, " Manuel", noir, font_txt);

    SDL_QueryTexture(texture_Non, NULL, NULL, &positionTexteNon.w, &positionTexteNon.h);

    SDL_RenderCopy(rendu, texture_Non, NULL, &positionTexteNon);
    SDL_RenderPresent(rendu);
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
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    cout << event.button.x << endl << event.button.y << endl;
                    if ((event.button.x > 300 && event.button.x < 600 && (event.button.y > 400 && event.button.y < 450))) {
                        SDL_DestroyRenderer(rendu);

                        SDL_DestroyWindow(win);

                        SDL_Quit();
                        return 0;
                    }
                    else if ((event.button.x > 650 && event.button.x < 950 && (event.button.y > 400 && event.button.y < 450))) {
                        SDL_DestroyRenderer(rendu);

                        SDL_DestroyWindow(win);

                        SDL_Quit();
                        return 1;
                    }
                }
        }

    }

    SDL_DestroyRenderer(rendu);

    SDL_DestroyWindow(win);

    SDL_Quit();
    return 3;
}

int init(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_cote) {

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
    TTF_Font* font = TTF_OpenFont("04B_30__.ttf", 15);
    TTF_Font* font2 = TTF_OpenFont("04B_30__.ttf", 25);
    TTF_Font* font3 = TTF_OpenFont("04B_30__.ttf", 50);



    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);
   SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);

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
    int Taille = sqrt_nb_bambou;
    SDL_RenderPresent(rendu);
    Panda panda;
    panda.posx = 0;
    panda.posy = 0;
    panda.batterie = 100;
    panda.distance = 0;

    int cpt_return = 0;
    //CREATION BOUCLE EVENT 
    bool continuer = true;
    bool pause = false;
    SDL_Event event;
    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3,cpt_return);

    while (continuer)
    {
        nb_coupes(rendu, font2, cpt_return);
        controle(rendu, font2);
        SDL_WaitEvent(&event);//update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 5);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_RIGHT:
                if (panda.batterie > 0) {
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 1,cpt_return);
                    panda.batterie-= 1;
                    nb_coupes(rendu, font2, cpt_return);
                    controle(rendu, font2);
                }
                else {
                    panda.batterie = 100;
                    panda.posx = 0;
                    panda.posy = 0;
                    posImg.x = 100;
                    posImg.y = 100;
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3, cpt_return);
                    message_batterie(rendu, font3);
                }
                break;

            case SDLK_LEFT:
                if (panda.batterie > 0) {
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3,cpt_return);
                    panda.batterie -= 1;
                    nb_coupes(rendu, font2, cpt_return);
                    controle(rendu, font2);
                }
                else {
                    panda.batterie = 100;
                    panda.posx = 0;
                    panda.posy = 0;
                    posImg.x = 100;
                    posImg.y = 100;
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3, cpt_return);
                    nb_coupes(rendu, font2, cpt_return);                 
                    controle(rendu, font2);
                    message_batterie(rendu, font3);
                }
                break;

            case SDLK_UP:
                if (panda.batterie > 0) {
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4,cpt_return);
                    panda.batterie -= 1;
                    controle(rendu, font2);
                    nb_coupes(rendu, font2, cpt_return);


                }
                else {
                    panda.batterie = 100;
                    panda.posx = 0;
                    panda.posy = 0;
                    posImg.x = 100;
                    posImg.y = 100;
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3, cpt_return);
                    nb_coupes(rendu, font2, cpt_return);
                    controle(rendu, font2);
                    message_batterie(rendu, font3);

                }
                break;

            case SDLK_DOWN:
                if (panda.batterie > 0) {
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 2,cpt_return);
                    panda.batterie -= 1;
                    controle(rendu, font2);
                    nb_coupes(rendu, font2, cpt_return);


                }
                else {
                    panda.batterie = 100;
                    panda.posx = 0;
                    panda.posy = 0;
                    posImg.x = 100;
                    posImg.y = 100;
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3, cpt_return);
                    nb_coupes(rendu, font2, cpt_return);
                    controle(rendu, font2);
                    message_batterie(rendu, font3);

                }
                break;

            case SDLK_RETURN:
                if (panda.batterie >= 0) {
                    cpt_return++;
                    panda.batterie -= 1;
                    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                    SDL_RenderClear(rendu);
                    background(rendu);
                    croissance_bambouseraie(tab, nb_cote);
                    coupe(tab, panda.posx, panda.posy);
                    place_img(monImage, posImg, rendu);
                    statistique(rendu, tab);

                    //courbe(rendu, tabs[], tabb, tabx, taby, taille);
                    recharge(rendu);
                    carre(rendu,nb_cote);
                    ecrit(rendu, font);
                    affiche_bambou(rendu,tab,nb_cote);
                    batterire(rendu, panda.batterie);
                    nb_coupes(rendu, font2, cpt_return);
                    controle(rendu, font2);
                }
                else {
                    panda.batterie = 100;
                    panda.posx = 0;
                    panda.posy = 0;
                    posImg.x = 100;
                    posImg.y = 100;
                    update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3, cpt_return);
                    nb_coupes(rendu, font2, cpt_return);
                    controle(rendu, font2);
                    message_batterie(rendu, font3);
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


void update_movment(SDL_Rect &posImg, Panda &panda, SDL_Renderer* rendu, TTF_Font* font, Bambou tab[][sqrt_nb_bambou], SDL_Texture* monImage, int& nb_cote, int direction,int cpt_return) {
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
    background(rendu);
    statistique(rendu, tab);
    place_img(monImage, posImg, rendu);
    carre(rendu, nb_cote);
    ecrit(rendu, font);
    affiche_bambou(rendu, tab, nb_cote);
    batterire(rendu, panda.batterie);
    statistique(rendu, tab);
    recharge(rendu);

}