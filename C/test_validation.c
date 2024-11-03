#include <stdio.h>
#include <assert.h>
#include "validation.h"

void test_validateName() {
    assert(validateName("Pedro", 5) == 1);
    printf("Validate name tests passed\n");
}

int main() {
    printf("Running tests...\n");
    test_validateName();
    printf("All tests passed\n");
    return 0;
}