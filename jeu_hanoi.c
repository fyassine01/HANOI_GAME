#include <stdio.h>
#include <string.h>

#define MAX_SIZE 3
#define SIZE_CHAR 50

//structure de pile
typedef struct {
    char items[MAX_SIZE][SIZE_CHAR];
    int top;
} pile;

//initialisation de la pile
void init(pile *p){
    p->top=-1;
}

//verification si la pile est vide
int isEmpty(pile *p){
    return (p->top == -1);
}

//verification si la pile est pleine
int isFull(pile *p){
    return (p->top == MAX_SIZE-1);
}

//fonction pour entrez un element a la pile
void push(pile *p,char valeur[]){
    if(isFull(p)){
        printf("la pile est pleine. impossible d'ajouter l'element\n");

    }else{
        strcpy(p->items[++(p->top)],valeur);
    }
}

//fonction pour retirer un element
char* pop(pile *p){

    if (isEmpty(p)){
        printf("la pile est vide impossible de retirer un element\n");
        return NULL;
    }else{
        return p->items[(p->top)--];
    }
}

//fonction retourne un element sans le retirer
char* peek(pile *p){
    if (isEmpty(p)){
        printf("la pile est vide\n");
        return NULL;
    }else{
        return p->items[p->top];
    }
}

//afficher le jeu
void afficherJeu(pile p[]){

    pile pl1=p[0],pl2=p[1],pl3=p[2],aide;

    printf("\n");
    printf("\033[0;45m             1                     2                     3             \033[0m\n\033[0;45m \033[0m");
    printf("                                                                     \033[0;45m \033[0m\n");
    for(int j=1;j<=3;j++){

    if (pl1.top==MAX_SIZE-j){
            printf("%s",pop(&pl1));
            if (pl2.top==MAX_SIZE-j){
                    printf("%s",pop(&pl2));
                    if(pl3.top==MAX_SIZE-j){
                        printf("%s\n",pop(&pl3));

                    }else{printf("\n");}

            }else{
                    if (pl3.top==MAX_SIZE-j){

                        for (int i=0;i<strlen(peek(&pl3))-21;i++){printf(" ");}
                        printf("%s\n",pop(&pl3));

                    }else{printf("\n");}

            }

    }else{
           aide=(!(isEmpty(&pl2))? pl2:pl3);
           for (int i=0;i<strlen(peek(&aide))-21;i++){printf(" ");}
            if (pl2.top==MAX_SIZE-j){
                    printf("%s",pop(&pl2));
                    if(pl3.top==MAX_SIZE-j){
                        printf("%s\n",pop(&pl3));

                    }else{printf("\n");}

            }else{
                    if (pl3.top==MAX_SIZE-j){

                        for (int i=0;i<strlen(peek(&pl3))-21;i++){printf(" ");}
                        printf("%s\n",pop(&pl3));

                    }else{printf("\n");}

            }

    }
 }

    printf("\033[0;45m \033[0m\033[5m    |---------------|     |---------------|     |---------------|    \033[0m\033[0;45m \033[0m\n");
    printf("\033[0;45m             1                     2                     3             \033[0m\n\n\n");

}

// nombre d'occurence
int occurence(char chaine[],char c){
    int compteur=0;
    for (int i=0;chaine[i] != '\0'; i++){
        if (chaine[i]==c){
            compteur++;
        }
    }
    return compteur;
}

//selection de pyramide source
int selectPyramideS(pile pl[]){
    int pyramide;

    do{
        printf("selectionnez une pyramide dans laquelle existe (au sommet) l'element a deplacer : ");
        scanf("%d",&pyramide);
        if (pyramide<1 || pyramide>3){
            printf("entrez une valeur entre 1 et 3 ...\n");
            pyramide=-1;
        }else{
            if (isEmpty(&pl[pyramide-1])){
                    printf("cette pyramide est vide ...\n");
                    pyramide=-1;

            }

        }

    }while(pyramide==-1);
    return pyramide;
}

//selection la pyramide vers laquelle le disque va deplaser (destination)
int selectPyramideD(pile pl[], int pyramideS){
    int position;

    do{
        printf("vers qu'elle pyramide l'element va-t-il deplecer : ");
        scanf("%d",&position);
        if (position<1 || position>3){
            printf("entrez une valeur entre 1 et 3 ...\n");
            position ==-1;
        }else{
          if (!isEmpty(&pl[position-1])){
            if (occurence(peek(&pl[pyramideS-1]),'/')>occurence(peek(&pl[position-1]),'/')){
                printf("c'est operation impossible reviser les regle de jeu ....\non ne peut pas placer un disque sur un autre de taille inferieur.\n");
                position=-1;

            }
          }
        }

    }while(position==-1);

    return position;

}

//programme principale
int main(){
    //declaration des variables
    pile pl[3];
    int pyramideD,pyramideS;

    //initialisation des pile
    init(&pl[0]);
    init(&pl[1]);
    init(&pl[2]);

    //remplisage de pl[0]
    push(&pl[0]," \033[0;8m///\033[0m   \033[0;43m             \033[0m  ");
    push(&pl[0]," \033[0;8m//\033[0m      \033[0;42m         \033[0m    ");
    push(&pl[0]," \033[0;8m/\033[0m         \033[0;41m     \033[0m      ");
    printf("\t\t\t   ___JEU DE HANOI___\n");

    //corp de programme
    do{

        afficherJeu(pl);

        pyramideS=selectPyramideS(pl);
        pyramideD=selectPyramideD(pl,pyramideS);

        //deplacer le disque vers la tour (pyramide) de destination
        push(&pl[pyramideD-1],pop(&pl[pyramideS-1]));

    }while (isFull(&pl[1])==0 && isFull(&pl[2])==0);

    afficherJeu(pl);
    printf("\t\t ~~~felicitation vous avez reussi~~~\n");

    return 0;
}
