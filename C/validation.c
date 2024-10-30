#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int validateName(char *name) {
    regex_t regex;
    char pattern[] = "[A-Za-zÀ-ÿ ]{1,50}";
    int reti;
    regmatch_t matches[1];

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf(" :Could not compile regex:\n");
        return 0;
    }
    reti = regexec(&regex, name, 1, matches, 0);
    if (!reti){
        printf(" :VALID NAME:\n");
        printf("Matched string: %.*s\n", matches[0].rm_eo - matches[0].rm_so, name + matches[0].rm_so);
        return 1;
    } else if (reti == REG_NOMATCH) {
        printf(" :INVALID NAME:\n");
        // printf("Matched string: %.*s\n", matches[0].rm_eo - matches[0].rm_so, name + matches[0].rm_so);
        return 0;
    } else {
        printf(" :Regex match error:\n");
        return 0;
    }
    regfree(&regex);
}

