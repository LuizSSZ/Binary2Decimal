#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>


int bin2dec(const char *binario);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    char binario[9]; // Para 8 dígitos + 1 para o caractere nulo

    printf("Digite um número binário (até 8 dígitos): ");    
    scanf("%8s", binario); // Limita a entrada a 8 caracteres

    // Verifica se a entrada é válida
    for (int i = 0; i < strlen(binario); i++)
    {
        if (binario[i] != '0' && binario[i] != '1')
        {
            printf("Entrada inválida! Use apenas 0s e 1s.\n");
            return 1; // Sai do programa se a entrada for inválida
        }
    }

    int resultado = bin2dec(binario);
    printf("O equivalente decimal é: %d\n", resultado);

    return 0;
}

int bin2dec(const char *binario)
{
    int decimal = 0;
    int comprimento = strlen(binario);

    for (int i = 0; i < comprimento; i++)
    {
        // Converte caractere binário para inteiro (0 ou 1)
        if (binario[comprimento - 1 - i] == '1')
        {
            decimal += pow(2, i); // Calcula a potência de 2
        }   // decimal = decimal + pow(2, i)
    }

    return decimal;
}