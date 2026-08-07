#include <stdio.h>

//Faça uma função que receba um número inteiro e determine se ele é primo ou não.
/*
int is_prime(int n){
    if(n <= 1)
        return 0;
    int i;
    for(i = 2; i <= n / 2; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Digite o numero para verificar se e primo: ");
    scanf("%d", &n);

    if(is_prime(n))
        printf("%d e primo.\n", n);
    else
        printf("%d nao e primo.\n", n);
    return 0;
}
*/

//Faça uma função que receba um número N qualquer do usuário e imprima os N primeiros números de Fibonacci.

int main(){

    int n;
    printf("Digite o numero de termos da sequencia de Fibonacci que deseja exibir: ");
    scanf("%d", &n);

    int t1 = 0, t2 = 1, proximoTermo;
    int i;

    printf("Os %d primeiros termos da sequencia de Fibonacci sao:\n", n);
    for(i = 0; i < n; i++){
        if(i == 0)
            printf("%d ", t1);
        else if(i == 1)
            printf("%d ", t2);
        else{
            proximoTermo = t1 + t2;
            printf("%d ", proximoTermo);
            t1 = t2;
            t2 = proximoTermo;
        }
    }

    return 0;
}

