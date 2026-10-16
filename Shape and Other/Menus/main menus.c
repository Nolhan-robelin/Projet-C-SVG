#include <stdio.h>
#include <stdlib.h>
#include "main menus.h"
#include "../Shape/Shape modifier/node.h"

int mainMenu(void)
{
    //Main menu where user is asked if  he want to create/Load/save or edit a shape/file
    char correctChoice = 'n';
    char correctFile = 'n';
do {
        int file;
        printf("Do you want to create a new file(1) or use an existing one(2) ?\n");
        scanf("%d", file);
            switch(file)
            {
                case 1: if (createFile() == 1); break;
                
                case 2: if (openFile() == 1){
                                int nbForm = 0;
                                int value[] = {nbForm};
                                NodeValue* listValue = createNodeValue(value);
                                NodeName* listName = createNodeName("Début du fichier");

                                correctFile = 'y';  
                                      
                                    do {
                                        printf("What do you want to do?\n");
                                        printf("1 to create a new form\n");
                                        printf("2 to edit a form\n");
                                        printf("3 to save the file\n");
                                        printf("4 to exit (without saving)\n");

                                        int choice;
                                        scanf("%d", &choice);
                                        switch(choice)
                                        {
                                            case 1: formChoice(); break;

                                            case 2: edit(); break;

                                            case 3: save(); break;

                                            case 4: printf("Have a good day !\n"); break;

                                        }
                                        
                                    } while(correctChoice == 'n'); break;
                            }
            default: printf("Invalid number you may try again\n"); break;
        }
} while(correctFile == 'n');
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
        // printf("4 to create a group of several form\n");
        
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
                    printf("Do you need a rectangle(1) or a polygon(2) ? \n");    // Ask the user what a need among the possibilities  
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
            
            /*
            case 4:
                        int formNb;
                        printf("How many form do you want ? \n");    // Ask the number of form wanted ; relancer la fonction pour avoir les formes voulus et jsp 
                        scanf("%d", &formNb);
                        for(int i = 0; i = formNb; i++)
                        {
                            formChoice();  // A terminer ; besoin de liste chainée pour augmenter la taille du tableau pour ajouter un nouveau groupe de forme
                        }
            */
            default: printf("Invalid value you may restart\n"); break;
        }
    } while (correctForm == 'n');
}
