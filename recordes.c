#include <stddef.h>
#include <stdio.h>
#include <conio.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista2;

void criar_lista2(Lista2 *lista2){
    lista2->inicio = NULL;
    lista2->tam = 0;
}

// inserir no início
void inserir_no_inicio2(Lista2 *lista2, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista2->inicio;
        lista2->inicio = novo;
        lista2->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//  inserir no fim
void inserir_no_fim2(Lista2 *lista2, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;


        if(lista2->inicio == NULL)
            lista2->inicio = novo;
        else{
            aux = lista2->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista2->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//  inserir no meio
void inserir_no_meio2(Lista2 *lista2, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(lista2->inicio == NULL){
            novo->proximo = NULL;
            lista2->inicio = novo;
        }
        else{
            aux = lista2->inicio;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista2->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(No *no){
    printf("\n\tRECORDES DO DIA: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

/*
      função remover da lista
*/
No* remover(No **lista2, int num){
    No *aux, *remover = NULL;

    if(*lista2){
        if((*lista2)->valor == num){
            remover = *lista2;
            *lista2 = remover->proximo;
        }
        else{
            aux = *lista2;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}

int main(){

    int opcao, valor, anterior;

    No *removido;
    Lista2 *lista2 = NULL;

    criar_lista2(&lista2);

    do{
        printf("\n\n----------------------------------------------------------\n\n");
        printf("\n\t0 - Sair\n\t1 - INSERIR RECORDE (inicio)\n\t2 - INSERIR RECORDE (meio)\n\t3 - INSERIR RECORDE (fim)\n\t4 - MOSTRAR RECORDE\n\t5 - REMOVER RECORDE\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\tDIGITE O RECORDE: ");
            scanf("%d", &valor);
            inserir_no_inicio2(&lista2, valor);
            break;
        case 2:
            printf("\tDIGITE O RECORDE E O VALOR DE REFERENCIA: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio2(&lista2, valor, anterior);
            break;
        case 3:
            printf("\tDIGITE O RECORDE: ");
            scanf("%d", &valor);
            inserir_no_fim2(&lista2, valor);
            break;
        case 4:
            imprimir(lista2);
            break;
        case 5:
             printf("\tDIGITE O RECORDE A SER REMOVIDO: ");
            scanf("%d", &valor);
            removido = remover(&lista2, valor);
            if(removido){
                printf("\tRECORDE REMOVIDO COM SUCESSO\n");
                free(removido);
            }
            else
                printf("\tRECORDE INEXISTENTE!\n");
            break;
        default:
            if(opcao != 0)
                printf("\tOPCAO INVALIDA!\n");
        }

    }while(opcao != 0);

    return 0;
}
