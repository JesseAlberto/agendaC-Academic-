/*
 * File:  ui.c
 * Author:  Vitor Custódio
 * Description: Biblioteca de funções de user interface
 * Last Change: 09Fev2020
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

/**
 * ########### Funções Internas da Biblioteca ############
 * #######################################################
 **/

/**
 * Imprime no ecrã o contacto com o formato definido
 **/
void imprime_contacto(Contacto *c)
{
    printf("-> %s, %d anos [CC:%s] [Tlf:%s]\n", c->nome, c->idade, c->cc, c->telefone);
}

/*Devolve o contacto com o cc*/
Contacto *get_by_cc(Agenda *a, char *cc)
{
    Contacto *c = a->primeiro;

    while (c)
    {
        if (!strcmp(c->cc, cc))
            return c;
        c = c->prox;
    }
    return NULL; /* Não encontrado*/
}

/**
 * ########### Funções Públicas da Biblioteca ############
 * #######################################################
 **/

Agenda *new_agenda()
{
    Agenda *a = malloc(sizeof(Agenda));
    /*Inicializa valores*/
    a->primeiro = NULL;
    a->ultimo = NULL;
    a->totalContactos = 0;
    return a;
}

void inicia_agenda_txt(Agenda *agenda)
{
    FILE *agenda_txt;
    char *token;
    int contador=0;
    char str[256];
    char nome[MAX_NOME_LENGHT+1],cc[CC_LENGHT+1],tlf[TLF_LENGHT+1];
    int idade;

    agenda_txt=fopen("agenda.txt", "r");

    while (fgets(str, 255, agenda_txt))
    {
        /*devolve o primeiro*/
        token = strtok(str, ":");
        /*enquanto houver tokens*/
        while (*token != '#')
        {
            if(contador==0)
                strncpy(nome,token,MAX_NOME_LENGHT);

            if(contador==1)
                strncpy(tlf,token,TLF_LENGHT);

            if(contador==2)
                strncpy(cc,token,CC_LENGHT);

            if(contador==3)
                idade=atoi(token);     
 

            /*para testes*/
            /*printf("%s\n", token);*/
            token = strtok(NULL, ":");
            contador++;
        }
        inserir_contacto(agenda, nome, cc, idade, tlf);
        memset(nome, '\0', MAX_NOME_LENGHT + 1);
        memset(cc, '\0', CC_LENGHT + 1);
        memset(tlf, '\0', TLF_LENGHT + 1);
        contador = 0;
        memset(str, '\0', 256);
    }
    fclose(agenda_txt);

}

void atualiza_agenda_txt(Agenda *agenda){

    FILE *agenda_txt;
    Contacto *ai = agenda->primeiro;
    agenda_txt=fopen("agenda.txt", "w");
    

    while (ai)
    {
        fprintf(agenda_txt, "%s:%s:%s:%d:#\n", ai->nome, ai->telefone, ai->cc, ai->idade);
        ai = ai->prox;
    }

    fclose(agenda_txt);
}



int inserir_contacto(Agenda *a, char *nome, char *cc, int idade, char *tlf)
{
    Contacto *c;
    /* Caso já existe retorna erro*/
    if (get_by_cc(a, cc))
        return CONTACTO_REPETIDO;
    /*Aloca memória e atribui valores*/
    c = malloc(sizeof(Contacto));
    c->nome = malloc(sizeof(char) * (MAX_NOME_LENGHT + 1));
    c->cc = malloc(sizeof(char) * (CC_LENGHT + 1));
    c->telefone = malloc(sizeof(char) * (TLF_LENGHT + 1));

    c->idade = idade;
    strncpy(c->nome, nome, MAX_NOME_LENGHT);
    strncpy(c->cc, cc, CC_LENGHT);
    strncpy(c->telefone, tlf, TLF_LENGHT);

    /*Acerta apontadores do contacto*/
    c->prox = NULL;
    if (!a->primeiro) /*primeiro contacto a inserir*/
        c->ant = NULL;
    else
    {
        c->ant = a->ultimo;
        a->ultimo->prox = c;
    }

    /*Atualiza apontadores e dados da agenda*/
    if (!a->primeiro) /*primeiro contacto a inserir*/
        a->primeiro = c;
    a->ultimo = c;
    a->totalContactos++;
    return SUCESSO;
}

int apagar_contacto(Agenda *a, char *cc)
{
    Contacto *c = get_by_cc(a, cc);
    /*Não existe o contacto*/
    if (a->totalContactos == 0)
        return CONTACTO_INEXISTENTE;
    /*Não existe o contacto*/
    if (c == NULL)
        return CONTACTO_INEXISTENTE;

    /*Acertar ponteiros da agenda e contactos (anterior e posterior)*/
    if (c->ant == NULL && c->prox == NULL)
    { /*caso seja o único*/
        a->primeiro = NULL;
        a->ultimo = NULL;
    }
    else
    { /*caso não seja o único*/
        if (c->ant == NULL)
        { /*caso seja o primeiro*/
            a->primeiro = c->prox;
            c->prox->ant = NULL;
        }
        if (c->prox == NULL)
        { /*caso seja o último*/
            a->ultimo = c->ant;
            c->ant->prox = NULL;
        }
        if (c->prox != NULL && c->ant != NULL)
        { /*caso não seja o primeiro nem o último*/
            c->ant->prox = c->prox;
            c->prox->ant = c->ant;
        }
    }

    /*Apaga e limpa memória do contacto*/
    free(c->nome);
    free(c->cc);
    free(c->telefone);
    free(c);

    /*Decrementa numero de contactos*/
    a->totalContactos--;

    return SUCESSO;
}

void imprime_agenda(Agenda *a)
{
    Contacto *c = a->primeiro;
    while (c)
    {
        imprime_contacto(c);
        c = c->prox;
    }
}

void apaga_agenda(Agenda *a)
{
    Contacto *tmp, *c = a->primeiro;
    while (c) /*enquanto não for NULL*/
    {
        tmp = c->prox;
        /*Limpa contacto*/
        free(c->nome);
        free(c->cc);
        free(c->telefone);
        free(c);
        c = tmp;
    }
    free(a);
}