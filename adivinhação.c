#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}



void inserir_no_inicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(No *no){
    printf("\n\tJOGADAS ANTERIORES: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}



int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"portuguese");

    //Declarando variaveis
    int menu = 0;
    int var_contr;
    int usuario;
    int pc;
    int opcao, valor, anterior;
    int tentativa = 1;

    No *removido;
    Lista *lista = NULL;

    criar_lista(&lista);

    for(;;)
    {
        label:

            var_contr = 0;
            printf("\n\t\t\t     JOGO DA ADIVINHACAO\n");

            printf("\n\t\t\t\t    MENU\n");

            printf("\n\t\t\t         [1] JOGAR\n");
            printf("\t\t\t         [2] AJUDA\n");
            printf("\t\t\t         [3] JOGADAS ANTERIORES\n");
            printf("\t\t\t         [4] RECORDE DO DIA\n");
            printf("\t\t\t         [5] SAIR\n");

            printf("\n\t\t\tEscolha uma das opcoes do MENU: ");
            scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            pc = rand() % 100; //Faz o computador escolher um n�mero entre 0 e 100 e atribui a variavel PC

                //La�o de repeti��o da op��o 1 = JOGAR
                while(1)
                {
                    printf("\n");
                    printf("\t        ----------------------------------------------- %d\n", pc);
                    printf("\n\t\t\t     Digite um numero: ");
                    scanf("%d", &usuario);

                    if(usuario < pc) //Se o n�mero do Computador for maior, imprimi printf
                    {
                        printf("\n\t\tO numero que o COMPUTADOR pensou e maior que %d.\n", usuario);
                        inserir_no_inicio(&lista, usuario);
                    }
                    else if(usuario > pc) //Se o numero do Computador for menor, imprimi printf
                    {
                        printf("\n\t\tO numero que o COMPUTADOR pensou e menor que %d.\n", usuario);
                        inserir_no_inicio(&lista, usuario);
                    }
                    else if(usuario == pc) //Se o numero do usuario for igual ao do Computador, imprimi printf
                    {
                        printf("\t        -----------------------------------------------\n");
                        printf("\n\t\t\t\tCARREGANDO...\n");
                        Sleep(2000); //Adiciona um delay de 2 segundos
                        printf("\n\t\t\t    Parabens voce acertou!!");
                        Sleep(1000);
                        printf("\n\t\t     O numero que o COMPUTADOR pensou foi %d.\n", pc);
                        Sleep(1000);
                        printf("\t\t           Voce usou %d tentativa(s)\n", tentativa); //Numero de tentativas at� o acerto

                        printf("\n\t        Pressione qualquer tecla para voltar ao MENU."); //Volta ao menu
                        getch();

                        system("cls"); //Limpa tela
                        var_contr = 1;
                    }

                    printf("\t\t           Voce usou %d tentativa(s) \n", tentativa); //N�mero de tentativas at� o acerto
                    tentativa++;

                    if(var_contr == 1)
                        goto label;
                }
            break;

        case 2: //Op��o 2 do MENU, explica ao usuario como o jogo funciona
            printf("\n              O JOGO DA ADIVINHACAO funciona da seguinte forma:\n");
            printf("\n   ---------------------------------------------------------------------------");
            printf("\n   O computador ira pensar em um numero entre 1 e 100 e voce tera que adivinhar.");
            Sleep(3000); //Adiciona um delay de 3 segundos
            printf("\n      Voce conseguira visualizar quantas tentivas foi preciso para acertar.");
            Sleep(3000);
            printf("\n  Sera informado se o numero que o COMPUTADOR pensou e maior ou menor que o seu.\n");
            Sleep(3000);
            printf("\n                             Boa sorte!!\n");
            printf("   ---------------------------------------------------------------------------\n");

            printf("\n\t        Pressione qualquer tecla para voltar ao MENU."); //Voltar ao MENU
            getch(); //Faz a a��o apertando qualquer tecla

            system("cls"); //Limpa tela
        break;

        case 3:
            imprimir(lista);
        break;

        case 4:
            system("start recordes.exe");
        break;

        case 5:
            exit(1);
        break;

        default:                                                                              //Caso o usuario n�o escolha nenhuma das op��es
            printf("\n\t         ERRO: Voce nao digitou nenhuma das opcoes disponiveis.\n");  //disponiveis no menu que s�o 1,2 ou 0
            printf("\n\t              Pressione qualquer tecla para voltar ao MENU."); //Volta ao MENU
            getch(); //Faz a a��o apertando qualquer tecla

            system("cls"); //Limpa a tela
        break;
        }

    };

    return 0;
}

