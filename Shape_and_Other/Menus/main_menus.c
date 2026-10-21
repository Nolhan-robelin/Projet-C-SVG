#include <stdio.h>
#include <stdlib.h>
#include "main_menus.h"
#include "../Shape/Shape_modifier/node.h"
#include "../Main_function/creation.h"
#include "../Shape/shape.h"

int mainMenu(void)
{
    //Main menu where user is asked if  he want to create/Load/save or edit a shape/file
    char correctChoice = 'n';
    char correctFile = 'n';
do {
        int file;
        printf("Do you want to edit the file(2) ?\n");
        scanf("%d", &file);
            switch(file)
            {
                case 1: break;
                
                case 2: openFile();
                                int nbForm = 0;
                                int value[] = {nbForm};
                                char* style[] = {"black"};
                                NodeValue* listValue = createNodeValue(value);
                                NodeName* listName = createNodeName("Début du fichier");
                                NodeStyle* listStyle = createNodeStyle(style);

                                correctFile = 'y';  
                                      
                                    do {
                                        formList(listValue, listName, listStyle);
                                        printf("What do you want to do?\n");
                                        printf("1 to create a new form\n");
                                        printf("2 to edit a form\n");
                                        printf("3 to view the file\n");
                                        printf("4 to exit (without saving)\n");

                                        int choice;
                                        scanf("%d", &choice);
                                        switch(choice)
                                        {
                                            case 1: nbForm = formChoice(nbForm, listName, listValue, listStyle); break;

                                            case 2: modifyShape(listValue, listName, listStyle); break;

                                            case 3: viewFile(listName, listValue, listStyle); break;

                                            case 4: printf("Have a good day !\n"); break;

                                        }
                                        
                                    } while(correctChoice == 'n'); break;
            
            default: printf("Invalid number you may try again\n"); break;
        }
} while(correctFile == 'n');
return 0;
}

int formChoice(int nbForm, NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
    char correctForm = 'n';
    char correctChoice = 'n';
    do
    {
        formList(listValue, listName, listStyle);
        
        int form;
        int choice;

        printf("What do you need  ?\n");
        printf("1 for a circle or an elipse\n");
        printf("2 for any polygon \n");
        printf("3 for multiple line, a simple line or a path\n");
        // printf("4 to create a group of several form\n");
        
        scanf("%1d", &form);
        switch(form)
        {
            case 1: correctForm = 'y'; 
                    do {
                    printf("Do you need a circle (1) or an elipse(2) ? \n");    // Ask the user what a need among the possibilities 
                        scanf("%1d", &choice);
                        switch (choice)
                        {
                            case 1: correctChoice = 'y'; nbForm = circle(nbForm, listName, listValue, listStyle); break;
                            case 2: correctChoice = 'y'; nbForm = elipse(nbForm, listName, listValue, listStyle); break;
                            default: printf("Invalid value you may restart\n");
                        }
                    } while  (correctChoice == 'n');break ;

            case 2: correctForm = 'y';  
                    do {
                    printf("Do you need a rectangle(1) or a polygon(2) ? \n");    // Ask the user what he need among the possibilities  
                        scanf("%1d", &choice);
                        switch (choice)
                        {
                            case 1: correctChoice = 'y'; nbForm = rectangle(nbForm, listName, listValue, listStyle); break;
                            // case 2: polygon(); break;
                            default: printf("Invalid value you may restart\n");
                        }
                    } while  (correctChoice == 'n'); break;
            
            
            case 3: correctForm = 'y'; 
                    do {
                    printf("Do you need a single line(1) ? \n");    // Ask the user what a need among the possibilities  
            
                        scanf("%1d", &choice);
                        switch (choice)
                        {
                            case 1: correctChoice = 'y'; nbForm = line(nbForm, listName, listValue, listStyle); break;
                            // case 2: several_line(); break;
                            // case 3: path(); break;
                            default: printf("Invalid value you may restart\n");
                        }
                    } while  (correctChoice == 'n'); break;
            
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
    return nbForm;
}
