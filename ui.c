/*
 * File:  ui.c
 * Author:  Vitor Custódio
 * Description: Biblioteca de funções de user interface
 * Last Change: 09Fev2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

/**
 * Pede um inteiro ao utilizador
 * @param pedido - String a apresentar ao utilizador
 * @return inteiro introduzido ou EOF(-1) no caso da leitura a partir de ficheiro
 **/
int getInt(char* pedido){
    char buf[MAX_STRING_LENGHT];
    int val,r=-1;
    do
    {
        if(r!=-1){
            printf("Tem que inserir um inteiro!");
        }
        printf("%s",pedido);
        if(!fgets(buf,MAX_STRING_LENGHT,stdin))
            return EOF;
        r=sscanf(buf,"%d",&val);
    } while (r!=1);
    return val;
}

/**
 * Solicita e lê uma string
 * @param pedido - texto a apresentar ao user
 * @param str - string lida
 * @param max_char - máximo número de char a ler
 * @return número carateres da string, -1 (STR_ERROR) em caso de erro
 **/
int getString(char* pedido, int max_char,char* str){
    char* pos;
    char buf[MAX_STRING_LENGHT];

    /*escreve mensagem e lê*/
    printf("%s",pedido);

    memset(buf,'\0',MAX_STRING_LENGHT);
    /*Ler. Sair em caso de erro de leitura*/
    if(NULL==fgets(buf,MAX_STRING_LENGHT,stdin))
        return STR_ERROR;

    /* Caso o utilizador tenha inserido mais que o máximo esperado, alertar*/
    if(strlen(buf)>(max_char+1))
        printf("Atenção! Inseriu mais carateres que o esperado (%d). Só serão considerados os primeiros %d carateres!",max_char,max_char);

    /*copia no máximo, max_char carateres*/
    strncpy(str,buf,max_char);

    /*retira \n caso tenha sido copiado e insere \0*/
    if((pos=strchr(str,'\n'))!=NULL)
        *pos='\0';

    return strlen(str);
}


/**
 * Solicita e lê uma string
 * @param pedido - texto a apresentar ao user
 * @param str - string lida
 * @param n - Número exato de carateres a ler
 * @return número carateres da string, -1 (STR_ERROR) em caso de erro
 **/
int getnString(char* pedido, int n,char* str){
    
    char *lido;
    char buf[MAX_STRING_LENGHT];

    do
    {
        /*escreve mensagem e lê*/
        printf("%s",pedido);
        memset(buf,'\0',MAX_STRING_LENGHT);
        lido=fgets(buf,MAX_STRING_LENGHT,stdin);
        if(lido==NULL)
            return STR_ERROR;
        if(strlen(buf)!=(n+1))
            printf("Tem que inserir uma string com exatamente -%d- carateres!",n);
    } while (strlen(buf)!=(n+1));

    /*copia no máximo, max_char carateres*/
    strncpy(str,buf,n);
    
    return strlen(str);
}