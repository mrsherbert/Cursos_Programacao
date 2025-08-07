#include <stdio.h>
#include <stdlib.h>

void resultado(double num1, double num2, char oper){
    double resultado;
    switch (oper) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {printf("Divisão por zero não permitida.\n");
                return;
            }else{resultado = num1 / num2;
            }
            break;
        default:
            printf("Operação não reconhecida \n");
        }
    printf("O resultado de %.3lf %c %.3lf é %.3lf \n", num1, oper, num2, resultado);
}

int main() {
    char operacao[100];
    double num1, num2;
    char operador;
    printf("Digite sua operação \n");
    printf("Só são calculadas operações (+,-,*,/) tal como (15.5 + 6.1, 15.5 - 6.1, 15.5 * 6.1, 15.5 / 6.1:) \n");
    fgets(operacao, 100, stdin);
    int itens = sscanf(operacao, "%lf %c %lf", &num1, &operador, &num2);
    if(itens == 3){resultado(num1, num2, operador);
    }else{
        printf("Erro de sintaxe \n");
    }
    printf("pressione enter para sair");
    getchar();
    return 0;
}