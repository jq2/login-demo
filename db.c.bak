#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int createFile(char *name, char *password);

FILE *fptr;

int main() {
    printf("main...\n");

    // **************************************************
    // createFile:
    //      @name: string
    //      @password: string
    //      return: 
    //          1 if success, 
    //          0 if the username is already registred, 
    //          255 for system error's
    //
    //***************************************************


    printf("Return: %d\n", createFile("username.ini", "passw0rd"));

    // test if the file was created.
    // FILE *temp_fptr = fopen("username.ini", "r");
    // printf("\n[DEBUG]: %s\n", temp_fptr ? "Existe" : "Arquivo não encontrado");


    return 0;
}


int createFile(char *name, char *password) {
    fptr = fopen(name, "w+");
    char tmp_a[10] = {0};
    char tmp_b[10] = {0};

    if (fptr) {
        printf("[DEBUG] Registrando conta...\n");
        if ( fscanf(fptr, "%s=%s", tmp_a, tmp_b) ) {
            printf("1111111111111111111111\n");
            printf("tmp_a: %s\ntmp_b: %s\n", tmp_a, tmp_b);
            fclose(fptr);
        }
        else
        {
            printf("000000000000000000000\n");
        }
        // return 1;
    }
    else {
        printf("[DEBUG] ERROR !!!!!\n");
        // fclose(fptr);
        exit(EXIT_FAILURE);
    }

    fclose(fptr);
    printf("Account created!\n");
    return 0;
}






