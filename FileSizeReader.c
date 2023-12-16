#include <stdio.h>
#include <dirent.h> 

long int findSize(char file_name[]){
    FILE* fp = fopen(file_name, "r");

    if(fp == NULL){
        printf("File not found!\n");
        printf("\nPress ENTER to exit program.");
        getchar();
        return 1;
    }

    fseek(fp, 0L, SEEK_END);

    long int res = ftell(fp);

    fclose(fp);

    return res;
}

char path[100];
char file_name[100];

int main(){
    struct dirent *de;

    printf("Enter the file directory path: ");
    fgets(path, sizeof(path), stdin);

    path[strcspn(path, "\n")] = '\0'; //Remove \n character so path is correct

    DIR *dr = opendir(path);

    if(dr == NULL){
        printf("\nCould not open directory: %s\n", path);
        printf("\nPress ENTER to exit program.");
        getchar();
        return 1;
    }

    while ((de = readdir(dr)) != NULL) 
            printf("\n%s", de->d_name); 
  
    closedir(dr);

    printf("\n\nEnter name of the file: ");
    fgets(file_name, sizeof(file_name), stdin);

    file_name[strcspn(file_name, "\n")] = '\0'; //Remove \n character so path is correct

    long int res = findSize(file_name);
    
    if(res != 1)
        printf("Size of the file is %ld bytes \n", res);

    printf("\nPress ENTER to exit program.");
    getchar();

    return 0;
}