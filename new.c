/* @filename: new.c
 * @desc: simple login application
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>


#define ACCOUNT_EXIST       (0x1)
#define ACCOUNT_NOT_FOUND   (0x2)
#define USER_NAME           "usernam3"
#define PASS_WORD           "p4ssworD"


void do_testLogin();
int do_registerAccount(char *name, char *password);
int do_loginAccount(char *name, char *password);
int do_createAccount(char *name, char *password);
int closeFile(char *name);
int do_checkFile(char *filename);
int do_checkLogin(char *filename);
int callback__registerFile(char *name, char *tmp_password);
int callback__loadFile(char *name, char *tmp_password);


FILE *fptr;
bool debugIsOn = false;


int main() {
    do_checkLogin("username.ini");
    return 0;
}


void do_testLogin() {
    printf("Seja bem-vindo ao UCP (User-Control-Panel)\n");
    if ( do_createAccount(USER_NAME, PASS_WORD) == ACCOUNT_EXIST) {
        do_loginAccount(USER_NAME, PASS_WORD);
    } else {
        do_registerAccount(USER_NAME, PASS_WORD);
    }
}


int do_createAccount(char *name, char *password) {
    fptr = fopen(name, "w+");
    char buf[128];

    if (fptr) {
        if (debugIsOn)
            printf("[DEBUG] Registrando conta...\n");
        sprintf(buf, "name=%s\n", name);
        fprintf(fptr, buf);
        fclose(fptr);
    }
    else {
        if (debugIsOn)
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
    
    // não está sendo usado...
    if (debugIsOn)
        printf("[DEBUG] do_loginAccount: %d\n", ret);

    printf("file:pass: %s\n", getUserPassword(name, "password"));
    printf("user:pass: %s\n", password);

    /*
    if (do_checkFile(name)) {
        printf("Enter your password: \n");
        scanf("%s", data);
        printf("You entered: %s\n", data);
        exit(1);
        return 1;
    }
    else {
        // ...
    }
    */


    return 0;
}

int do_registerAccount(char *name, char *password) {
    if (debugIsOn)
        printf("[DEBUG] do_registerAccount\n");

    do_createAccount(name, password); 
    return 0;
}

int do_checkFile(char *filename) {
    FILE * file;

    if (debugIsOn)
        printf("[DEBUG] do_checkFile()...\n");

    file = fopen(filename, "r");

    if (file) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
    return 0;
}



int do_checkLogin(char *filename) {
    char tmp_password[32] = {0};
    struct termios term, term_tmp;

    if (do_checkFile(filename) == 1) {
        printf("[LOGIN] Usuário %s é cadastrado, fazendo login,...\nDigite sua senha para logar: ", filename);
        printf("\n");

        tcgetattr(STDIN_FILENO, &term);
        term_tmp = term;
        term.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
        scanf("%s", tmp_password);
        tcsetattr(STDIN_FILENO, TCSANOW, &term_tmp);
        callback__loadFile(filename, tmp_password);
    }
    else {
        printf("[REGISTRO] Registrando conta...\nDigite sua nova senha: ");
        printf("\n");

        tcgetattr(STDIN_FILENO, &term);
        term_tmp = term;
        term.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
        scanf("%s", tmp_password);
        tcsetattr(STDIN_FILENO, TCSANOW, &term_tmp);
        callback__registerFile(filename, tmp_password);
    }
    return 0;
}

int callback__registerFile(char *name, char *tmp_password) {
    if (debugIsOn)
        printf("[DEBUG] callback__registerFile(%s, %s)\n", name, tmp_password);

    do_registerAccount(name, tmp_password);
    return 0;
}

int callback__loadFile(char *name, char *tmp_password) {
    if (debugIsOn)
        printf("[DEBUG] callback__loadFile(%s, %s\n", name, tmp_password);
    do_loginAccount(name, tmp_password);
    return 0;
}
