/*
 * File:  menu.h
 * Author:  Vitor Custódio
 * Description: Biblioteca para construção de menus.
 * É proibida a alteração deste ficheiro no projeto final
 * Last Change: 15Fev2020
 */
#ifndef MENU_H
#define MENU_H

#define MAX_MENU_LENGHT 100

/**
 *Definição das cores que podem ser usadas no menu
 *Mais info em: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
 **/
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ESCOLHA_CORRETA 1
#define ESCOLHA_INCORRETA 0

/*Definição dos itens que compõem um menu*/
typedef struct menu_item
{
    struct menu_item *proximo; /*proximo item do menu*/
    char *item_name;           /* nome a apresentar ao user*/
    int id;                    /* opção que o user deve escolher*/
} MenuItem;

typedef struct menu
{
    char *name; /* Nome do menu*/
    char *cor;  /* cor a imprimir o menu*/
    struct menu_item *primeiro;
    struct menu_item *ultimo;
} Menu;

/**
 * Cria um novo menu
 * @param nome do menu
 * @param cor do menu
 * @return ponteiro para menu
 **/
Menu *new_menu(char *nome, char *cor);

/**
 * Insere um item no menu
 * @param m Menu onde será inserido o item
 * @param nome do item
 * @param id do item do menu
 **/
void insere_item_menu(Menu *m, char *nome, int id);

/**
 * Imprime o menu principal no ecrã;
 * @param m Menu a imprimir
 * @return int - Opção selecionada pelo user
 **/
int imprime_menu(Menu *m);

/**
 * Liberta a memória utilizada no menu
 * @param m Menu a libertar memória
 **/
void free_menu(Menu *m);

#endif