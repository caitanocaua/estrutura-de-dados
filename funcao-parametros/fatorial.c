//Faça uma programa usando função, que receba um valor inteiro n e retorne o fatorial de n.

#include <stdio.h>

int fatorial(int n){
    int fatorial = 1;

    for(int i = 2; i<=n;i++)
        fatorial *= i;
    return fatorial;
}
/*
int main(){
    int n;
    char respos;

    do
    {
    printf("Digite um numero que deseja calcular o fatorial: ");
    scanf("%d", &n);
    if(n < 0){
        printf("Não existe fatorial para numeros negativos.\n");
        printf("Favor digite um numero inteiro positivo. \n");
    }
    else if(n == 0 || n == 1)
        printf("O fatorial de %d eh: 1\n", n);
    else
        printf("O fatorial de %d eh: %d\n", n, fatorial(n));

    printf("Deseja continuar?\n");
    scanf(" %c", &respos);
    } while (respos =='s' || respos =='S');

    return 0;
}*/

/*
    Faça um programa usando função, que receba um
    valor inteiro n e retorne a soma dos n primeiros termos da série:
    1+ 1/1! + 1/2! + 1/3! + ... + 1/n!
*/

int main(){
    int n;
    char respos;

    do{
        printf("Digite um numero inteiro positivo para calcular a soma da serie: ");
        scanf("%d", &n);
        if(n<0){
            printf("Não existe fatorial para numeros negativos.\n");
            printf("Favor digitar um numero inteiro positivo ");

        }else{
            float soma = 0;
            for(int i = 0; i<=n; i++)
                soma += 1.0/fatorial(i);
            printf("A soma da serie ate %d eh: %.2f\n", n, soma);
        }
        printf("Deseja continuar?\n");
        scanf(" %c", &respos);

    }while(respos=='s'||respos=='S');
    return 0;
}