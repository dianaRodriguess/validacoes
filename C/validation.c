#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include "validation.h"

int validateName(char *name, int nchar) {
    regex_t regex;
    char pattern[100];
    int reti;
    regmatch_t matches[1];
    
    // formata o padrão com limite de caracteres
    sprintf(pattern, "^[A-Za-zÀ-ÿ ]{1,%d}$", nchar);
    // compile regex
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf(" :Could not compile regex:\n");
        return 0;
    }
    // execute regex
    reti = regexec(&regex, name, 1, matches, 0);
    if (!reti){
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return 0;
    } else {
        regfree(&regex);
        return 0;
    }
    // regfree(&regex);
}

int validateEmail(char *email) {
    regex_t regex;
    char pattern[100];
    int reti;
    regmatch_t matches[1];

    sprintf(pattern,"([a-zA-Z0-9\.\-\_]{2,})@([a-zA-Z0-9]{2,})(\.[a-zA-Z]{2,})(\.[a-zA-Z]{2,})?(\.[a-z]{2,})?");

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf(" :Could not compile regex:\n");
        return 0;
    }

    reti = regexec(&regex, email, 1, matches, 0);
    if (!reti){
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return 0;
    } else {
        regfree(&regex);
        return 0;
    }
}

int checkPrice(char *price) {
    float price_f;
    price_f = atof(price);
    if (price_f < 0){
        return 0;
    }
    return 1;
}

int validatePrice(char *price){
    regex_t regex;
    char pattern[] = "([0-9]{1,}(\\.[0-9]{3})*)[,\\.]([0-9]{2})";
    int reti;
    regmatch_t matches[1];

    for (int i = 0; price[i] != '\0'; i++) {
        if (price[i] == ',') {
            price[i] = '.';
        }
    }

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf(" :Could not compile regex:\n");
        return 0;
    }
    if (!checkPrice(price)) {
        return 0;
    }
    reti = regexec(&regex, price, 1, matches, 0);
    if (!reti){
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return 0;
    } else {
        regfree(&regex);
        return 0;
    }
}

// *******************
// ******* MAIN ******
// *******************

int main() {

//     // Pedro de Alcântara Francisco Antônio João Carlos Xavier de Paula Miguel Rafael Joaquim José Gonzaga Pascoal Cipriano Serafim de Bragança e Bourbon
//     char name[50];
//     // sprintf(name, "Diana Rodrigues da silva");
//     printf("Name: ");
//     fgets(name, sizeof(name), stdin);
//     name[strcspn(name, "\n")] = '\0';
    
//     printf("%s\n", name);
    
//     int result = validateName(name, sizeof(name) - 1);
//     if (result == 1) {
//         printf("Valid name\n");
//     } else if (result == 0) {
//         printf("Invalid name\n");
//     }
    // char email[55];
    // printf("Email: ");
    // fgets(email, sizeof(email), stdin);
    // email[strcspn(email, "\n")] = '\0';
    
    // printf("%s\n", email);
    
    // int result = validateEmail(email);
    // if (result == 1) {
    //     printf("Valid email\n");
    // } else if (result == 0) {
    //     printf("Invalid email\n");
    // }

    char price[10];
    printf("Price: ");
    fgets(price, sizeof(price), stdin);
    price[strcspn(price, "\n")] = '\0';
    int result = validatePrice(price);
    if (result == 1) {
        printf("Valid price\n");
    } else if (result == 0) {
        printf("Invalid price\n");
    }
    
    return 0;
}
