#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cardapio.h"

typedef struct Item
{
    int idItem;
    char nome[50];
    float valor;
    struct Item *proximoItem;
} Item;
struct Cardapio
{
    Item *inicio;
};

char menu()
{
    char menuSelect;
    printf("========= BEM VINDO =========\n");
    printf("Por favor, selecione um.\n");
    printf("1 ----- Criar cardápio\n");
    printf("2 ----- Inserir item\n");
    printf("3 ----- Remover item\n");
    printf("4 ----- Buscar item\n");
    printf("5 ----- Imprimir cardápio\n");
    printf("0 ----- Sair\n");
    scanf(" %c", &menuSelect);
    return menuSelect;
}
char retornarMenu()
{
    char retorno;
    do{
        printf("\nDeseja retornar ao menu original?");
        printf("\n[1 ---- Sim || 0 ---- Não]");
        scanf(" %c", &retorno);
        limpar_buffer();
        switch(retorno)
        {
            case '1':
            case '0':
                return retorno;
            default:
                printf("\nInsira algo válido...");
                break;
        }        
    }while(1);
}

Cardapio *criarCardapio()
{
    Cardapio *novo = (Cardapio*)malloc(sizeof(Cardapio));
    novo->inicio = NULL;
    return novo;
}
int adicionarItem(Cardapio *cardapio, float valorItem, const char nome[], int idItem)
{
    //Cabeçalho para variaveis
    Item *atual = cardapio->inicio;
    Item *novo = (Item*)malloc(sizeof(Item));
    //Atribuindo valores
    novo->idItem = idItem;
    novo->valor = valorItem;
    strcpy(novo->nome, nome);
    novo->proximoItem = NULL;
    //Movendo para os ponteiros
    if(cardapio->inicio == NULL)
    {
        cardapio->inicio = novo;
        return 0;
    }
    else
    {
        while(atual->proximoItem != NULL)
        {
            atual = atual->proximoItem;
        }
        atual->proximoItem = novo;
        return 0;
    }
    //Um caso onde não foi possivel criar o cardápio.
    return 1;
}
void removerItem(Cardapio *cardapio, int idItem)
{
    //Adicionar primeiro o anterior
    Item *anterior = cardapio->inicio;
    //Verificando se o cardapio tá vazio
    if(cardapio->inicio == NULL){
        printf("Cardapio vazio! \n");
        return;
    }
    //Só define o atual sendo o proximo, se a lista não estiver vazia!
    Item *atual = anterior->proximoItem;
    //Caso o item esteja no inicio:
    if(cardapio->inicio->idItem == idItem)
    {
        Item *temp = cardapio->inicio;
        //Isso é bem estranho, mas a gente tá simplesmente fatiando a lista...
        cardapio->inicio = cardapio->inicio->proximoItem;
        free(temp);
        return;
    }
    //Caso o item esteja no meio:
    while(atual != NULL)
    {
        if(atual->idItem == idItem)
        {
            //Nessa parte, a gente pega e liga o item anterior com o proximo do atual, e daí remove o item atual!
            anterior->proximoItem = atual->proximoItem;
            printf("\nItem %s removido com sucesso!\n", atual->nome);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximoItem;
    }
    printf("Item de id: %d não encontrado.", idItem);
    return; 
}
void listarCardapio(Cardapio *cardapio)
{
    //Cabeçalho para variaveis
    Item *atual = cardapio->inicio;
    //Fazemos a checagem se está vazio
    if(cardapio->inicio == NULL)
    {
        printf("\nNão há cardapio para listar.");
        return;
    }

    printf("============ CARDÁPIO ============\n");
    //Enquanto o atual não for nulo, ele vai imprimir
    while(atual != NULL)
    {
        printf("\nItem: %s\nId: %d\nValor: %.2f\n", atual->nome, atual->idItem, atual->valor);
        atual = atual->proximoItem;
    }
    printf("===================================\n");
    return;
}
void liberarCardapio(Cardapio *cardapio)
{
    //Cabeçalho para variaveis e verificação
    Item *atual = cardapio->inicio;
    if(atual == NULL) return;
    //Enquanto o cardapio não estiver vazio, vai percorrer ele
    while(atual != NULL)
    {
        //Libera utilizando um ponteiro
        Item *temp = atual;
        atual = atual->proximoItem;
        free(temp);
    }
    //Libera o cardapio inteiro
    free(cardapio);
    printf("\nCardapio liberado!");
    return;
}
void buscarItem(Cardapio *cardapio, int idItem)
{
    //Cabeçalho para variavel
    Item *atual = cardapio->inicio;
    //Faz a verificação se o inicio estiver vazio.
    if(cardapio->inicio == NULL)
    {
        printf("\nNão há itens registrados ainda...\n");
        return;
    }
    //Utiliza-se de um loop while para buscar o item desejado
    while(atual != NULL)
    {
        //Quando encontra o item, imprime o mesmo na tela.
        if(atual->idItem == idItem)
        {
            printf("\n --------- Item encontrado --------- \n");
            printf("\nNome: %s\nValor: %.2f\n", atual->nome, atual->valor);
            return;
        }
        //Caso não encontre, parte para o próximo item.
        atual = atual->proximoItem;
    }
    //Caso a lista seja percorrida, e ainda assim não encontre nada.
    printf("\nItem não encontrado.");
    return;
}
void limpar_buffer() {
    // Limpa tudo até encontrar '\n' ou EOF
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}