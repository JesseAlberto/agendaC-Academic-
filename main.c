#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "constants.h"
#include "menu.h"
#include "ui.h"
#include "agenda.h"

/*agenda e menu a utilizar na aplicação*/
Agenda *agenda;
Menu *menu;

/*Função para terminar a aplicação pelo CTRL+C*/
void termina_programa(int signal)
{
    printf("\nA terminar por CTRL+C.\nA limpar memória...\n");
    apaga_agenda(agenda);
    free_menu(menu);
    printf("%s",MSG_SAIDA);
    exit(EXIT_SUCCESS);
}

void popular_menu_principal()
{
    insere_item_menu(menu, MENU_PRINCIPAL_1, 1);
    insere_item_menu(menu, MENU_PRINCIPAL_2, 2);
    insere_item_menu(menu, MENU_PRINCIPAL_3, 3);
    insere_item_menu(menu, MENU_PRINCIPAL_9, 9);
}



int main(int argc, char *argv[])
{
    int opt;/* Opçãp escolhido pelo user*/
    char nome[MAX_NOME_LENGHT+1],cc[CC_LENGHT+1],tlf[TLF_LENGHT+1];
    int idade;
    
   

    /*Deteta o CTRL+C do utilizador e chama função termina programa*/
    signal(SIGINT, termina_programa);
    agenda = new_agenda();
    menu = new_menu(MENU_PRINCIPAL_NAME, ANSI_RED);
    popular_menu_principal();
    system("clear");
    inicia_agenda_txt(agenda);

    
    
    while (1)
    {
        opt=imprime_menu(menu);
        switch (opt)
        {
        case 1:
            /*Inserir*/
            system("clear");
            /*Limpar variáveis de suporte*/
            memset(nome, '\0', MAX_NOME_LENGHT + 1);
            memset(cc, '\0', CC_LENGHT + 1);
            memset(tlf, '\0', TLF_LENGHT + 1);

            /*Pede os valores*/
            getString(GET_NOME,MAX_NOME_LENGHT,nome);
            getnString(GET_CC, CC_LENGHT, cc);
            getnString(GET_TLF, TLF_LENGHT, tlf);
            idade = getInt(GET_IDADE);
            inserir_contacto(agenda,nome,cc,idade,tlf);
            break;
        case 2:
            /* Apagar */
            system("clear");

            /*Limpar variáveis de suporte*/
            memset(cc, '\0', CC_LENGHT + 1);

            /*Pede os valores*/
            getnString(GET_CC, CC_LENGHT, cc);

            apagar_contacto(agenda,cc);
            break;
        case 3:
            /* imprimir */
            system("clear");
            imprime_agenda(agenda);
            break;
        case 9:
        case EOF:
            atualiza_agenda_txt(agenda);
            apaga_agenda(agenda);
            free_menu(menu);
            printf("%s",MSG_SAIDA);
            exit(EXIT_SUCCESS);
        }
    }
    return EXIT_SUCCESS;
}