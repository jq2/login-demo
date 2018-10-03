#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int createFile(char *name, char *password);

FILE *fptr;

int main() {
    printf("main...\n");
    printf("Return: %d\n", createFile("username.ini", "passw0rd"));
    return 0;
}


int createFile(char *name, char *password) {
    fptr = fopen(name, "w+");
    if (fptr) {
        printf("[DEBUG] Registrando conta...\n");
        fscanf("%s=%s", name, password);
        // return 1;
    }
    else {
        printf("[DEBUG] ERROR !!!!!\n");
        // fclose(fptr);
        exit(EXIT_FAILURE);
    }

    printf("Account created!\n");
    return 0;
}






