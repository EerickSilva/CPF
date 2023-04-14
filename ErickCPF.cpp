#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cpf[11];
    int i, j, soma, digito1, digito2;

    printf("Digite o CPF (somente números): ");
    scanf("%s", cpf);

    if (strlen(cpf) != 11) {
        printf("CPF inválido.\n");
        return 0;
    }

    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF inválido.\n");
            return 0;
        }
    }

    soma = 0;
    for (i = 0, j = 10; i < 9; i++, j--) {
        soma += (cpf[i] - '0') * j;
    }
    digito1 = 11 - (soma % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }

    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        soma += (cpf[i] - '0') * j;
    }
    digito2 = 11 - (soma % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }

    if (cpf[9] - '0' != digito1 || cpf[10] - '0' != digito2) {
        printf("CPF inválido.\n");
        return 0;
    }

    printf("CPF válido.\n");
    return 0;
}
