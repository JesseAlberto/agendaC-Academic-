/*
 * File:  ui.h
 * Author:  Vitor Custódio
 * Description: Biblioteca de funções de user interface
 * Last Change: 09Fev2020
 */
#ifndef UI_H
#define UI_H

#define MAX_STRING_LENGHT 1024
#define STR_ERROR -1

/**
 * Solicita e lê uma string
 * @param pedido - texto a apresentar ao user
 * @param str - string lida
 * @param max_char - máximo número de char a ler
 * @return número carateres da string, -1 (STR_ERROR) em caso de erro
 **/
int getString(char* pedido,int max_char,char* str);


/**
 * Solicita e lê uma string
 * @param pedido - texto a apresentar ao user
 * @param str - string lida
 * @param n - Número exato de carateres a ler
 * @return número carateres da string, -1 (STR_ERROR) em caso de erro
 **/
int getnString(char* pedido, int n,char* str);

/**
 * Pede um inteiro ao utilizador
 * @param pedido - String a apresentar ao utilizador
 * @return inteiro introduzido
 **/
int getInt(char* pedido);

#endif