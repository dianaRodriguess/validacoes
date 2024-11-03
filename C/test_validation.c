#include <stdio.h>
#include <assert.h>
#include "validation.h"

void test_validateName() {
    assert(validateName("Pedro", 6) == 1);
    assert(validateName("diana rodrigues da silva", 49) == 1);
    assert(validateName("Pedro de Alcântara Francisco Antônio João Carl", 49) == 1);
    assert(validateName("áàâãéêíóôõúçÁÀÂÃÉÊÍÓÔÕÚÇ", 49) == 1);
    assert(validateName("diana rodria1234567890", 49) == 0);
    assert(validateName("¹²³£¢¬{[]}§/?°®ŧ←↓→øþ´ªæßðđŋħˀĸł´~º«»©„“”µ•·d ̣°", 49) == 0);
    assert(validateName("!@#$%¨&*()_+=-´`^~[]{};:.,<>d?/|/'\"", 49) == 0);
    assert(validateName("", 49) == 0);
    printf("\nValidate name tests passed\n");
}

int main() {
    printf("\n-----------------------\nRunning tests...\n");
    test_validateName();
    printf("\nAll tests passed\n");
    return 0;
}