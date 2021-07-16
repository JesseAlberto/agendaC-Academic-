/*
 * File:  ui.h
 * Author:  Vitor Custódio
 * Description: Biblioteca gestão de agendas
 * Last Change: 09Fev2020
 */
#ifndef AGENDA_H
#define AGENDA_H

#define MAX_NOME_LENGHT 100
#define TLF_LENGHT 9
#define CC_LENGHT 8

/* definição de estado e erros da agenda*/
#define SUCESSO 0;
#define CONTACTO_INEXISTENTE -1
#define CONTACTO_REPETIDO -2

typedef struct contacto
{
    struct contacto *prox;
    struct contacto *ant;
    char *nome;
    char *cc;
    int idade;
    char *telefone;
}Contacto;

typedef struct agenda{
    struct contacto *primeiro;
    struct contacto *ultimo;
    int totalContactos;
}Agenda; 

/**
 * Inicia a agenda
 * @return Agenda
 **/
Agenda *new_agenda();

void inicia_agenda_txt(Agenda *agenda);

void atualiza_agenda_txt(Agenda *agenda);

/**
 * Insere um contacto na agenda
 * @param a - Agenda onde inserir
 * @param nome - Nome do novo contacto
 * @param cc - Cartão de cidadão
 * @param idade - Idade do contacto
 * @param tlf - telefone do contacto
 * @return 0 se sucesso, CONTACTO_REPETIDO (-2) se já existir CC
 **/
int inserir_contacto(Agenda *a,char* nome,char* cc, int idade,char* tlf);

/**
 * Apaga contacto na agenda
 * @param a - Agenda onde apagar
 * @param cc - Cartão de cidadão
 * @return >=0 se foi apagado, caso contrario -1 ou -2
 **/
int apagar_contacto(Agenda *a,char* cc);

/**
 * Imprime toda a agenda
 * @param a - Agenda onde procurar
 **/
void imprime_agenda(Agenda *a);

/**
 * Apaga a agenda (e contactos) e limpa a memória
 * @param a - Agenda a apagar
 **/
void apaga_agenda(Agenda *a);
#endif