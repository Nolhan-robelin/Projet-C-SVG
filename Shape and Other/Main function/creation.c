#include <stdio.h>
#include <stdlib.h>

int createFile(void)
{
    // Function which will create a file 
    char* fileP = malloc(sizeof(char) * 30);
    char fileName[30];
                            
    printf("Enter the name of your file with the extension\n");
    scanf("%s", fileName);
                                
    FILE* fptr;
    fptr = fopen(fileName, 'w');
    free(fileP);
                                
    if (fptr = NULL) {
        printf("The file did not opened.\n");
        printf("You may retry\n");
        return 0;
    }

    else    
        printf("The file got created successfully\n");
        char* dateP = malloc(sizeof(char) * 250);
        char data[250] = "<html>"
                            "<head>"
                                "<meta charset='UTF-8' />"
                                "<title>Exemple mêlant HTML & SVG</title>"
                            "</head>"
                            "<body>"
                                "<svg width='150' height='100' viewBox='0 0 3 2'>";
        fputs(data, fptr);
        
        return 1;


}

int openFile(void)
{
    char* fileP = malloc(sizeof(char) * 30);
    char fileName[30];
                            
    printf("Enter the name of your file with the extension\n");
    scanf("%s", fileName);
                                
    FILE* fptr;
    fptr = fopen(fileName, 'w');
    free(fileP);
                            
    if (fptr = NULL) {
        printf("The file did not opened.\n");
        printf("You may retry");
        return 0;
    }
    else
        printf("File successfully opened\n");
        return 1;         
}

int edit(void)
{
    // Function which allow the user to edit an existing shape he made
    return 0;
}

int save(void)
{
    // Function which save what the user made
    return 0;
}

/*
int visualize(void)
{
    char* fileP = malloc(sizeof(char) * 30);
    
    
    char fileName[30];
    printf("Enter the name of your file (without the extension)\n");
    scanf("%s", fileName);
    
    char systemF[30] = {"xdg-open %s.html", fileName};
    system("xdg-open" fileName".html");
}
*/