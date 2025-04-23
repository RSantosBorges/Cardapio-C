#ifndef CARDAPIO_H
#define CARDAPIO_H

typedef struct Cardapio Cardapio;

Cardapio* criarCardapio();
char menu();
char retornarMenu();
int adicionarItem(Cardapio *cardapio, float valorItem, const char nomeItem[], int idItem);
void removerItem(Cardapio *cardapio, int idItem);
void listarCardapio(Cardapio *cardapio);
void liberarCardapio(Cardapio *cardapio);
void buscarItem(Cardapio *cardapio, int idItem);
void limpar_buffer();

#endif