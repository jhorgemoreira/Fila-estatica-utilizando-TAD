#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTRUTURA COM AS INFORMAÇÕES DOS ALUNOS
typedef struct {

    char nome[10];
    int matricula;
    int idade;

}ALUNO_FILA;

// VARIÁVEL DO TIPO ALUNO FILA PARA ACESSO AOS DADOS DA ESTRUTURA
typedef ALUNO_FILA aluno_fila;

#include "TAD_Fila_Estatica_01.h"

// VARIÁVEL DO TIPO FILA PARA ACESSO AOS AOS DADOS DA TAD_FILA
FILA fila_aluno;

// MENU DE OPÇÕES
void Menu() {

	printf("\t 1 - INSERIR NA FILA \n ");
    printf("\t 2 - MOSTRAR FILA \n");
    printf("\t 3 - TAMANHO DA FILA \n");
    printf("\t 4 - PRIMEIRO DA FILA \n");
    printf("\t 5 - REMOVER DA FILA \n");
    printf("\t 6 - GRAVAR FILA NO ARQUIVO \n");
    printf("\t 7 - EXCLUIR TODOS DA FILA \n");
   	printf("\t 8 - SAIR \n ");

}

// LIMPAR A TELA DEPOIS DE ESCOLHIDA UMA OPÇÃO
void Limpar_Tela() {

    system("cls");

}

void Inserir() {

    aluno_fila al[3];

    char nome[10];

    int tamanho = Tamanho_Fila(&fila_aluno);

    printf("\n");

    // VERIFICAR SE A FILA ESTÁ CHEIA, CASO CONTRÁRIO A INSERÇÃO É FEITA COM SUCESSO
    if(Lista_Cheia(&fila_aluno)) {

        printf("\t FILA CHEIA \n");

    }

    // DADOS QUE SERÃO INSERIDOS
    else {

        do {

            printf("Informe o nome do aluno: \n");
            scanf("%s", nome);

            strcpy(al[tamanho].nome, nome);

            printf("Informe a matricula do aluno: \n");
            scanf("%d", &al[tamanho].matricula);

            printf("Informe a idade do aluno: \n");
            scanf("%d", &al[tamanho].idade);

            printf("\t ALUNO INSERIDO COM SUCESSO \n");

            Inserir_Fila(&fila_aluno, tamanho, al[tamanho]);

            tamanho++;

        }while(!Lista_Cheia(&fila_aluno));

    }

    printf("\n\n");

}

void Listar() {

    aluno_fila al;

    printf("\n\n");

    int i;

    int tamanho = Tamanho_Fila(&fila_aluno);

    // VERIFICAR SE A FILA CONTÉM ELEMENTOS PARA SEREM EXIBIDOS
    if(tamanho > 0) {

        for(i = 0; i < tamanho; i++) {

            if(Imprime_Fila(&fila_aluno, i, &al)) {

                printf("\t ================================ \n");
                printf(" \t POSICAO: %d \n", i+1);
                printf(" \t NOME: %s \n", al.nome);
                printf(" \t MATRÍCULA: %d \n", al.matricula);
                printf(" \t IDADE: %d \n", al.idade);
                printf("\t ================================ \n");

            }

            printf("\n");

        }

    }

    else {

        printf("\t FILA VAZIA \n ");

    }

    printf("\n\n");

}

// EXIBIR O PRIMEIRO ELEMENTO DA FILA
void Primeiro_da_Fila() {

    aluno_fila al;

    printf("\n\n");

    int tamanho = Tamanho_Fila(&fila_aluno);

    if(tamanho != 0) {

        for(int i = 0; i < tamanho; i++) {

            if(Primeiro_Fila(&fila_aluno, &al)) {

                printf("\t ================================ \n");
                //printf(" POSICAO: %d ", i+1);
                printf(" \t NOME: %s \n", al.nome);
                printf(" \t MATRÍCULA: %d \n", al.matricula);
                printf(" \t IDADE: %d \n", al.idade);
                printf("\t ================================ \n");
                break;

            }

            printf("\n");
            printf("\n");

        }

    }

    else {

        printf("\t FILA VAZIA \n");

    }

    printf("\n\n");

}

// REMOVER SEMPRE O PRIMEIRO ELEMENTO DA FILA
void Remover() {

    aluno_fila al;

    int i = 0;
    int tamanho = Tamanho_Fila(&fila_aluno);

    printf("\n\n");

    if(Remover_Fila(&fila_aluno, i)) {

        printf("\t ALUNO REMOVIDO COM SUCESSO \n");

    }

    else {

        printf("\t FILA VAZIA \n");

    }

    printf("\n\n");

}

void Gravar() {

    // VARIÁVEL DO TIPO FILE
    FILE *arquivo;

    // ABERTURA DO ARQUIVO
    arquivo = fopen("fila_estatica.txt", "w");

    printf("\n\n");

    // VERIFICAR SE O ARQUIVO NÃO ESTÁ NULO
    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSÍVEL ABRIR O ARQUIVO \n");
        exit(0);

    }

    else {

        aluno_fila al;

        Limpar_Tela();
        printf("\n");

        int i;

        int tamanho = Tamanho_Fila(&fila_aluno);

        for(i = 0; i < tamanho; i++) {

            if(Gravar_Arquivo(&fila_aluno, i, &al)) {

                // GRAVAR AS INFORMAÇÕES NO ARQUIVO
                fprintf(arquivo, "%s \n ", al.nome);
                fprintf(arquivo, "%d \n ", al.matricula);
                fprintf(arquivo, "%d \n ", al.idade);

            }

        }

    }

    // FECHAMENTO DO ARQUIVO
    fclose(arquivo);

    printf("\n\n");

}

// CHAMADA DAS FUNÇÕES NO MÉTODO PRINCIPAL
int main(void) {

	int opcao = 0;

	Inicializar_Fila(&fila_aluno);
	Limpar_Tela();

   	do {

		Menu();

		printf("\t Informe uma opção: \n ");
		scanf("%d", &opcao);

		Limpar_Tela();

        switch (opcao) {

            case 1:

                Inserir();
                break;

            case 2:

                Listar();
                break;

            case 3:

                printf("\t TAMANHO DA FILA: %d \n", Tamanho_Fila(&fila_aluno));
                break;

            case 4:

                Primeiro_da_Fila();
                break;

            case 5:

                Remover();
                break;

            case 6:

                Gravar();
                break;

            case 7:

                Excluir_Todos(&fila_aluno);
                break;

            case 8:

                exit(0);
                break;

            default:

                printf("\t OPÇÃO INVÁLIDA \n ");
                break;

        }

    }while(opcao != 0);

}
