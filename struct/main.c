#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void listarAluno(Aluno *aluno, int quantAluno){	
	for(int i = 0; i < quantAluno; i++){
        printf("\nDados do aluno %d:\n", i + 1);
        printf("RA: %d\n", aluno[i].ra);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Curso: %s\n", aluno[i].curso);                
		for(int b=0;b<4;b++){
			printf("Nota %d: %.2f\n", b + 1, aluno[i].notas[b]);
		}
		printf("Media: %.2f\n", media(aluno[i]));                                           
		printf("Ano de inicio: %d \n", aluno[i].anoInicio);
		printf("Idade: %d\n", aluno[i].idade);
	}
}*/

/*
Uma função que cria um novo aluno, leia os seus dados e
retorne o novo aluno;
*/

typedef struct{
		int ra;
		char nome[50];
		char curso[50];
		float notas[4];
		int anoInicio;
		int idade;
	} Aluno;	

float media(Aluno aluno){
	float soma=0;
	for(int b=0;b<4;b++){
		soma+=aluno.notas[b];
	}
	return soma/4;
}

float mediaTurma(Aluno *aluno,int quantAluno){
	if(quantAluno == 0)
		return 0;
	float mediaturma=0;
	for(int i=0;i<quantAluno;i++){
		mediaturma += media(aluno[i]);
	}
	return mediaturma / quantAluno;
}

void vizualizacaoDeAluno(Aluno aluno){
	printf("\nDados do aluno: \n");
    printf("RA: %d\n", aluno.ra);
    printf("Nome: %s\n", aluno.nome);
    printf("Curso: %s\n", aluno.curso);                
	for(int b=0;b<4;b++){
		printf("Nota %d: %.2f\n", b + 1, aluno.notas[b]);
	}
	printf("Media: %.2f\n", media(aluno));                                           
	printf("Ano de inicio: %d \n", aluno.anoInicio);
	printf("Idade: %d\n", aluno.idade);
}

Aluno maiorMedia(Aluno *aluno, int quantAluno){
    float maior;
    Aluno alunoMaior;

    maior = media(aluno[0]);
    alunoMaior = aluno[0];

    for(int i = 1; i < quantAluno; i++){
        float mediaAtual = media(aluno[i]);

        if(mediaAtual > maior){
            maior = mediaAtual;
            alunoMaior = aluno[i];
        }
    }

    return alunoMaior;
}

void cadastroAluno(Aluno *aluno, int quantAluno){

    printf("Digite o RA do aluno: ");
    scanf("%d", &aluno->ra);
    while (getchar() != '\n');

    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, 50, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    printf("Digite o curso do aluno: ");
    fgets(aluno->curso, 50, stdin);
    aluno->curso[strcspn(aluno->curso, "\n")] = '\0';

    printf("Digite as 4 notas do aluno:\n");

    for(int i = 0; i < 4; i++){
        printf("Nota %d: ", i + 1);
        scanf("%f", &aluno->notas[i]);
    }

    printf("Digite o ano de inicio do aluno: ");
    scanf("%d", &aluno->anoInicio);

    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno->idade);
    
    vizualizacaoDeAluno(*aluno);
}

void listarAluno(Aluno *aluno, int quantAluno){	
	for(int i = 0; i < quantAluno; i++){
        vizualizacaoDeAluno(aluno[i]);
	}
}

void buscaRA(Aluno *aluno,int quantAluno){
	int RA, encontrado=0;
	printf("Digite o RA do aluno para sua busca: ");
	scanf("%d", &RA);
	for(int i=0;i<quantAluno;i++){
		if(RA == aluno[i].ra){
			vizualizacaoDeAluno(aluno[i]);
			encontrado=1;
		}	
	}
	if(encontrado == 0)
		printf("\nNao foi encontrado\n");
}

int menu(void){
	int op, quantAluno=0;
	Aluno aluno[40];
	do {
    	printf("\n1 - Cadastrar novo aluno\n");
    	printf("2 - Listar todos os alunos\n");
    	printf("3 - Buscar aluno pelo RA\n");
    	printf("4 - Exibir o aluno com a maior média\n");
    	printf("5 - Exibir a média das médias\n");
    	printf("6 - Excluir um aluno pelo RA\n");
    	printf("7 - Sair\n");

    	printf("Selecione uma das opções acima: ");
    	scanf("%d", &op);

    	switch (op) {
        	case 1:
        		system("cls");
        		if(quantAluno < 40){
        		cadastroAluno(&aluno[quantAluno], quantAluno);
        		quantAluno++;
    		} else {
        		printf("Limite de alunos atingido!\n");
    		}
    		break;
    		
        	case 2:
        		system("cls");
            	listarAluno(aluno,quantAluno);
            	break;

        	case 3:
            	system("cls");
            	buscaRA(&aluno,quantAluno);
            	break;

        	case 4:
            	system("cls");
            	Aluno maior = maiorMedia(aluno, quantAluno);
            	vizualizacaoDeAluno(maior);
            	break;

        	case 5:
            	system("cls");
            	printf("Media da turma: %.2f",mediaTurma(&aluno,quantAluno));
            	break;

        	case 6:
            	system("cls");
            	break;

        	case 7:
            	printf("Saindo...\n");
            	break;

        	default:
            	printf("\nSelecione uma opção válida!!!\n");
    	}

	} while (op != 7);
	return 0;
}

int main(int argc, char *argv[]) {
	
	menu();
	
	return 0;
}