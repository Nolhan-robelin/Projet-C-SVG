#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    return 0;
}

int choixForme(void)
{
    char formeCorrect = 'n';
    char choixCorrect = 'n';
    do
    {
        int forme;
        int choix;

        printf("De quoi avez vous besoin ?\n ");
        printf("1 pour un cercle ou une elipse\n");
        printf("2 pour n'importe quel polygone \n");
        printf("3 pour un enchainement de ligne, chemin ou ligne simple\n");
        printf("4 pour un rassemblement de plusieurs formes\n");
        
        scanf("%1d", &forme);
        switch(forme)
        {
            case 1:  do {
                    printf("Avez-vous besoin d'un cercle (1) ou d'une elipse(2) ? \n");    // Demander a l'utilisateur ce qu'il a besoin parmis la selection disponible ; puis demander la taille, angles
                        scanf("%1d", &choix);
                        switch (choix)
                        {
                            case 1: circle(); break;
                            case 2: elipse(); break;
                            default: printf("Valeur invalide veuillez recommencer\n");
                        }
                    } while  (choixCorrect == 'n');
            case 2:  do {
                    printf("Avez-vous besoin d'un triangle (1) ou d'un rectangle(2) ou autre chose(3) ? \n");    // Demander le nombre de points voulu ; cas particulier pour carre et rectangle 
                        scanf("%1d", &choix);
                        switch (choix)
                        {
                            case 1: triangle(); break;
                            case 2: rectangle(); break;
                            case 3: polygone(); break;
                            default: printf("Valeur invalide veuillez recommencer\n");
                        }
                    } while  (choixCorrect == 'n');
            
            case 3: do {
                    printf("Avez-vous besoin d'une seule ligne(1) ou de plusieurs ligne(2) ou de ligne type chemin(3) ? \n");    // Demander a l'utilisateur ce qu'il a besoin parmis la selection disponible ; puis demander la longeur des lignes et/ou le nombre de lignes 
            
                        scanf("%1d", &choix);
                        switch (choix)
                        {
                            case 1: triangle(); break;
                            case 2: rectangle(); break;
                            case 3: polygone(); break;
                            default: printf("Valeur invalide veuillez recommencer\n");
                        }
                    } while  (choixCorrect == 'n'); 
            
            case 4:
                        int nbFormes;
                        printf("Combien de forme avez vous besoin ? \n");    // Demander le nombre de forme voulu ; relancer la fonction pour avoir les formes voulus et jsp 
                        scanf("%d", &nbFormes);
                        for(int i = 0; i = nbFormes; i++)
                        {
                            choixForme();  // A terminer ; besoin de liste chainée pour augmenter la taille du tableau pour ajouter un nouveau groupe de forme
                        }
            default: printf("Valeur invalide veuillez recommencer\n"); break;
        }
    } while (formeCorrect == 'n');
}
