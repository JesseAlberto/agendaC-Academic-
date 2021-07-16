/*
 * File:  menu.h
 * Author:  Vitor Custódio
 * Description: Biblioteca para construção de menus.
 * Last Change: 09Fev2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "ui.h"

/**
 * Função interna para validar se escolha do user existe no menu
 * @param m Menu onde procurar;
 * @param escolha do utilizador
 * @return int - ESCOLHA_CORRETA(1) // ESCOLHA_INCORRETA(0) // EOF(-1)
 **/
int valida_escolha(Menu *m, int escolha)
{
    MenuItem *mi = m->primeiro;
    if(escolha==EOF)
        return EOF;
    
    while (mi)
    {
        if (mi->id == escolha)
        {
            return ESCOLHA_CORRETA;
        }
        mi = mi->proximo;
    }
    printf("Opção (%d) não consta do menu!", escolha);
    return ESCOLHA_INCORRETA;
}

/**
 * Liberta a memória alocada a um item de menu
 * @param mi Item de Menu a libertar memória;
 **/
void free_menu_item(MenuItem *mi){
    free(mi->item_name);
    free(mi);
}

/**
 * ###############################################
 * #####   FUNÇÔES PÚBLICAS ######################
 * ###############################################
 **/

Menu *new_menu(char *nome, char *cor)
{
    /*cria menu e aloca memória*/
    Menu *m = malloc(sizeof(Menu));
    m->cor = malloc(sizeof(char) * 7);
    m->name = malloc(sizeof(char) * (MAX_MENU_LENGHT + 1));

    /*Faz a configuração inicial dos ponteiros de controlo*/
    m->primeiro = NULL;
    m->ultimo = NULL;

    /*copia informação*/
    strncpy(m->cor, cor, 6);
    strncpy(m->name, nome, MAX_MENU_LENGHT);

    return m;
}

void insere_item_menu(Menu *m, char *nome, int id)
{
    /* Cria o Item de menu*/
    MenuItem *mi = malloc(sizeof(MenuItem));
    mi->item_name = malloc(sizeof(char) * (MAX_MENU_LENGHT + 1));

    /*Configura ponteiros e copia valores*/
    mi->proximo = NULL;
    mi->id = id;
    strncpy(mi->item_name, nome, MAX_MENU_LENGHT);

    /*Caso seja o primeiro item a ser inserido*/
    if (!m->primeiro)
        m->primeiro = mi;
    else  /* caso contrário*/
        m->ultimo->proximo = mi; 
    /*Por fim aponta para o último*/
    m->ultimo = mi;
}

int imprime_menu(Menu *m)
{
    int opt; /*Opção selecionada*/
    MenuItem *mi = m->primeiro;
    printf("%s\t-----------------------------------------\n", m->cor);
    printf("\t\t\t%s\t\t\n", m->name);
    printf("\t-----------------------------------------\n");
    while (mi != NULL)
    {
        printf("\t %d- %s\n", mi->id, mi->item_name);
        mi = mi->proximo;
    }
    printf("\t-----------------------------------------%s\n", ANSI_COLOR_RESET);
    do
    {
        opt = getInt("Insira a sua escolha->");

    } while (valida_escolha(m, opt)==ESCOLHA_INCORRETA);
    return opt;
}

void free_menu(Menu *m){
    MenuItem *tmp, *mi=m->primeiro;
    /* Liberta itens do menu*/
    while (mi)
    {
        tmp=mi->proximo;
        free_menu_item(mi);
        mi=tmp;
    }
    
    /*Liberta variáveis de Menu e menu*/
    free(m->cor);
    free(m->name);
    free(m);
}
