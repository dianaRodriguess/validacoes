#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
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
        // printf(" :VALID NAME:\n");
        // printf("Matched string: %.*s\n", matches[0].rm_eo - matches[0].rm_so, name + matches[0].rm_so);
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        // printf(" :INVALID NAME:\n");
        // printf("Matched string: %.*s\n", matches[0].rm_eo - matches[0].rm_so, name + matches[0].rm_so);
        regfree(&regex);
        return 0;
    } else {
        // printf(" :Regex match error:\n");
        regfree(&regex);
        return 0;
    }
    // regfree(&regex);
}


// *******************
// ******* MAIN ******
// *******************

// int main() {

//     // Pedro de Alcântara Francisco Antônio João Carlos Xavier de Paula Miguel Rafael Joaquim José Gonzaga Pascoal Cipriano Serafim de Bragança e Bourbon
//     char name[50];
//     // sprintf(name, "Diana Rodrigues da silva");
//     printf("Name: ");
//     fgets(name, sizeof(name), stdin);
//     name[strcspn(name, "\n")] = '\0';
    
//     // printf("%s", name);
    
//     int result = validateName(name, sizeof(name) - 1);
//     if (result == 1) {
//         printf("Valid name\n");
//     } else if (result == 0) {
//         printf("Invalid name\n");
//     }
    
//     return 0;
// }
