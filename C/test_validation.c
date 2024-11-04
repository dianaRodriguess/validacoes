#include <stdio.h>
#include <assert.h>
#include "validation.h"

void test_validateName() {
    assert(validateName("Pedro", 6) == 1);
    assert(validateName("diana rodrigues da silva", 54) == 1);
    assert(validateName("Pedro de Alcântara Francisco Antônio João Carl", 54) == 1);
    assert(validateName("áàâãéêíóôõúçÁÀÂÃÉÊÍÓÔÕÚÇ", 54) == 1);
    assert(validateName("diana rodria1234567890", 54) == 0);
    assert(validateName("¹²³£¢¬{[]}§/?°®ŧ←↓→øþ´ªæßðđŋħˀĸł´~º«»©„“”µ•·d ̣°", 54) == 0);
    assert(validateName("!@#$%¨&*()_+=-´`^~[]{};:.,<>d?/|/'\"", 54) == 0);
    assert(validateName("", 54) == 0);
    printf("\nValidate name tests passed\n");
}

void test_validateEmail() {
    assert(validateEmail("ab@cd.ef") == 1);
    assert(validateEmail("aa@aa.aa.aa") == 1);
    assert(validateEmail("user.name@domain.co") == 1);
    assert(validateEmail("name_123@web.info") == 1);
    assert(validateEmail("test-user@site.org") == 1);
    assert(validateEmail("a_b@abc.co.uk") == 1);

    assert(validateEmail("username.domain.com") == 0);
    assert(validateEmail("username@domaincom") == 0);
    assert(validateEmail("a@domain.com") == 0);
    assert(validateEmail("user@d.c") == 0);
    assert(validateEmail("user!name@domain.com") == 0);
    assert(validateEmail("test*user@domain.com") == 0);
    assert(validateEmail("user#name@domain.co.uk") == 0);
    assert(validateEmail(".username@domain.com") == 0);
    assert(validateEmail("username@dom ain.com") == 0);
    assert(validateEmail("user..name@domain.com") == 0);
    assert(validateEmail("a3@a2.com") == 0);
    assert(validateEmail("a3@a2.1a") == 0);
    assert(validateEmail("diana.rodrigues@.co@m.br") == 0);
    assert(validateEmail("diana.@com.br.") == 0);
    assert(validateEmail("rodrigues@co#m") == 0);

    printf("\nValidate email tests passed\n");

}

int main() {
    printf("\n-----------------------\nRunning tests...\n");
    if (test_validateName){
        printf("\nValidate name tests passed\n");
    } else {
        printf("\nValidate name tests failed\n");
    }
    if (test_validateEmail){
        printf("\nValidate email tests passed\n");
    } else {
        printf("\nValidate email tests failed\n");
    }
    printf("\nAll tests passed\n");
    return 0;
}