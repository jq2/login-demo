#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ACCOUNT_EXIST (0x1)
#define USER_NAME "usernam3"
#define PASS_WORD "p4ssworD"

void do_testLogin();
int do_registerAccount(char *name, char *password);
int do_loginAccount(char *name, char *password);
int createAccount(char *name, char *password);
int closeFile(char *name);
int do_checkFile(char *filename);
int do_checkLogin(char *filename);

FILE *fptr;

int main() {

    printf("main...\n");

    // **************************************************
    // createAccount:
    //      @name: string
    //      @password: string
    //      @return: 
    //          1: If the account does not exists
    //          0: If the account is already registered
    //          255: For system error's
    //
    //***************************************************


    // printf("Return: %d\n", createAccount("username.ini", "passw0rd"));

    // test if the file was created.
    // FILE *temp_fptr = fopen("username.ini", "r");
    // printf("\n[DEBUG]: %s\n", temp_fptr ? "Existe" : "Arquivo não encontrado");

    // do_testLogin();

    do_checkLogin("username.ini");


    return 0;
}

void do_testLogin() {
    printf("Seja bem-vindo ao UCP (User-C0ntrol-Panel)\n");

    if ( createAccount(USER_NAME, PASS_WORD) == ACCOUNT_EXIST) {
        do_loginAccount(USER_NAME, PASS_WORD);
    }
    else
    {
        do_registerAccount(USER_NAME, PASS_WORD);
    }
}


int createAccount(char *name, char *password) {

    fptr = fopen(name, "w+");

    char buf[128];
    char tmp_a[10] = {0};
    char tmp_b[10] = {0};

    if (fptr) {
        printf("[DEBUG] Registrando conta...\n");
        // -----------------------------------------------------
        // if ( fscanf(fptr, "%s=%s", tmp_a, tmp_b) ) {
        // printf("1111111111111111111111\n");
        // printf("tmp_a: %s\ntmp_b: %s\n", tmp_a, tmp_b);
        sprintf(buf, "name=%s\n", name);
        fprintf(fptr, buf);
        fclose(fptr);
        // -----------------------------------------------------
        // }
        // else
        // {
        //     printf("000000000000000000000\n");
        // }
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


int do_loginAccount(char *name, char *password) {
    int ret;
    char data[12];

    printf("[DEBUG] do_loginAccount: %d\n", ret);
    if (do_checkFile(name)) {
        // login, enter your password (to make auth)...
        // get the user-input/password and check with the file-content-password...
        // printf("Enter your password: \n");
        printf("Enter your password: \n");
        scanf("%s", data);
        printf("You entered: %s\n", data);
        exit(1);
        return 1;
    }
    else
    {
    }
    return 0;
}



int do_registerAccount(char *name, char *password) {
    printf("[DEBUG] do_registerAccount\n");
    return 0;
}



int do_checkFile(char *filename) {

    printf("[DEBUG] do_checkFile()...\n");

    FILE * file;
    file = fopen(filename, "r");
    if (file)
    {
        // file exists and can be opened 
        // ...
        // close file when you're done
        //         fclose(file);
        fclose(file);
        return 1;
    } 
    else
    {
        //file doesn't exists or cannot be opened (es. you don't have access permission )
        return 0;
    }
    //


    return 0;
}



int do_checkLogin(char *filename) {
    char tmp_password[32];

    printf("Checking login/filename: %s\n", filename);

    printf("[STATUS]\nRegistro não consta no banco de dados\n");
    // if (do_checkFile(filename) == 1) {
    if (do_checkFile(filename) == 1) {
        // account exists
        printf("Logando...\nDigite a sua senha para logar: ");
        printf("\n");
    }
    else {
        // account not found...
        printf("Registrando...\nDigite sua nova senha: ");
        printf("\n");


        scanf("%s", tmp_password);
        printf("Read: %s\n", tmp_password);
        registerNewAccount(password);
    }
    return 0;
}



