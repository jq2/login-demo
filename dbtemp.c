#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

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
int callback__registerFile(char *name, char *tmp_password);


FILE *fptr;

int main() {
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
        sprintf(buf, "name=%s\n", name);
        fprintf(fptr, buf);
        fclose(fptr);
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

    struct termios term, term_tmp;
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
        tcgetattr(STDIN_FILENO, &term);
        term_tmp = term;
        term.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &term);



        scanf("%s", tmp_password);
        printf("Read: %s\n", tmp_password);

        tcsetattr(STDIN_FILENO, TCSANOW, &term_tmp);


        // registerNewAccount(tmp_password);
        callback__registerFile(filename, tmp_password);
        printf("[DEBUG] FINAL STEP\n");
    }
    return 0;
}

int callback__registerFile(char *name, char *tmp_password) {
    printf("[DEBUG::CALLBACK::callback__registerFile(%s, %s)\n", name, tmp_password);

    do_registerAccount(name, tmp_password);
    return 0;
}



