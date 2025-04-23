#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "cardapio.c"

int main()
{
    bool select = true;
    int quantidadeItens, idTemp, error;
    char nomeTemp[50], menuSelect, retornoMenu;
    float valorTemp;
    Cardapio *cardapio = NULL;
    do
    {
        menuSelect = menu();
        switch(menuSelect)
        {
            case '1':
                system("cls");
                cardapio = criarCardapio();
                printf("\nCardápio criado com sucesso!\n");
                break;
            case '2':
                system("cls");
                if(cardapio == NULL)
                {
                    printf("O cardápio não foi criado...\n");
                    printf("Retornando ao menu.");
                    sleep(2);
                    break;
                }
                else
                {
                    printf("Quantos itens irá adicionar?[apenas números positivos]\n");
                    scanf("%d", &quantidadeItens);
                    limpar_buffer();
                    for(int i = 0; i < quantidadeItens; i++)
                    {
                        system("cls");
                        printf("\n---- Item [%d] ----", i+1);

                        printf("\nNome: ");
                        fgets(nomeTemp, sizeof(nomeTemp), stdin);
                        nomeTemp[strcspn(nomeTemp, "\n")] = '\0';
                        printf("\nValor: ");
                        scanf("%f", &valorTemp);
                        limpar_buffer();
                        printf("\nId: ");
                        scanf("%d", &idTemp);
                        limpar_buffer();
                        error = adicionarItem(cardapio, valorTemp, nomeTemp, idTemp);
                        if(error != 0)
                        {
                            printf("\nNão foi possivel adicionar o item.");
                            printf("\nTente novamente.");
                        }
                        else
                        {
                            printf("\nItem cadastrado com sucesso!");
                            sleep(2);
                        }
                    }
                    retornoMenu = retornarMenu();
                    if(retornoMenu == '1')
                    {
                        printf("\nRetornando ao menu...");
                        sleep(2);
                    }
                    else
                    {
                        printf("\nSaindo...");
                        sleep(2);
                        select = false;
                    }
                }
                system("cls");
                break;
            case '3':
                system("cls");
                if(cardapio == NULL)
                {
                    printf("O cardápio não foi criado...\n");
                    printf("Retornando ao menu.");
                    sleep(2);
                }
                else
                {
                    printf("Insira o ID do item para ser removido: ");
                    scanf("%d", &idTemp);
                    limpar_buffer();
                    removerItem(cardapio, idTemp);
                    retornoMenu = retornarMenu();
                    if(retornoMenu == '1')
                    {
                        printf("\nRetornando ao menu...");
                        sleep(2);
                    }
                    else
                    {
                        printf("\nSaindo...");
                        sleep(2);
                        select = false;
                    }
                }
                system("cls");
                break;
            case '4':
                system("cls");
                if(cardapio == NULL)
                {
                    printf("O cardápio não foi criado...\n");
                    printf("Retornando ao menu.");
                    sleep(2);
                }
                else
                {
                    printf("\nInsira o ID do item para ser buscado: ");
                    scanf("%d", &idTemp);
                    limpar_buffer();
                    buscarItem(cardapio, idTemp);
                    retornoMenu = retornarMenu();
                    if(retornoMenu == '1')
                    {
                        printf("\nRetornando ao menu...");
                        sleep(2);
                    }
                    else
                    {
                        printf("\nSaindo...");
                        sleep(2);
                        select = false;
                    }
                }       
                system("cls");        
                break;
            case '5':
                system("cls");
                if(cardapio == NULL)
                {
                    printf("O cardápio não foi criado...\n");
                    printf("Retornando ao menu.");
                    sleep(2);
                }
                else listarCardapio(cardapio);
                retornoMenu = retornarMenu();
                if(retornoMenu == '1')
                {
                    printf("\nRetornando ao menu...");
                    sleep(2);
                }
                else
                {
                    printf("\nSaindo...");
                    sleep(2);
                    select = false;
                }
                system("cls");
                break;
            case '0':
                printf("\nSaindo...");
                sleep(2);
                select = false;
                break;
            default:
                printf("\nEntrada inválida.\nTente novamente.");
                break;
        }
    }while(select);
    if(cardapio != NULL) liberarCardapio(cardapio);
    return 0;
}