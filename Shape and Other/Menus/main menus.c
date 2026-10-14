#include <stdio.h>
#include <stdlib.h>


int mainMenu(void)
{
    //Main menu where user is asked if  he want to create/Load/save or edit a shape/file
}

int formChoice(void)
{
    char correctForm = 'n';
    char correctChoice = 'n';
    do
    {
        int form;
        int choice;

        printf("What do you need  ?\n ");
        printf("1 for a circle or an elipse\n");
        printf("2 for any polygon \n");
        printf("3 for multiple line, a simple line or a path\n");
        printf("4 to create a group of several form\n");
        
        scanf("%1d", &form);
        switch(form)
        {
            case 1:  do {
                    printf("Do you need a circle (1) or an elipse(2) ? \n");    // Ask the user what a need among the possibilities 
                        scanf("%1d", &choice);
                        switch (choice)
                        {
                            case 1: circle(); break;
                            case 2: elipse(); break;
                            default: printf("Invalid value you may restart\n");
                        }
                    } while  (correctChoice == 'n');
            case 2:  do {
                    printf("Do you need a triangle (1) a rectangle(2) or a polygon(3) ? \n");    // Ask the user what a need among the possibilities  
                        scanf("%1d", &choice);
                        switch (choice)
                        {
                            case 1: triangle(); break;
                            case 2: rectangle(); break;
                            case 3: polygon(); break;
                            default: printf("Invalid value you may restart\n");
                        }
                    } while  (correctChoice == 'n');
            
            case 3: do {
                    printf("Do you need a single line(1) ,several line(2) or path-like line(3) ? \n");    // Ask the user what a need among the possibilities  
            
                        scanf("%1d", &choice);
                        switch (choice)
                        {
                            case 1: single_line(); break;
                            case 2: several_line(); break;
                            case 3: path(); break;
                            default: printf("Invalid value you may restart\n");
                        }
                    } while  (correctChoice == 'n'); 
            
            case 4:
                        int formNb;
                        printf("How many form do you want ? \n");    // Ask the number of form wanted ; relancer la fonction pour avoir les formes voulus et jsp 
                        scanf("%d", &formNb);
                        for(int i = 0; i = formNb; i++)
                        {
                            formChoice();  // A terminer ; besoin de liste chainée pour augmenter la taille du tableau pour ajouter un nouveau groupe de forme
                        }
            default: printf("Invalid value you may restart\n"); break;
        }
    } while (correctForm == 'n');
}
