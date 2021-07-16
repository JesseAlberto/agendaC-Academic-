# Exercício

## Pequena agenda (memória dinâmica)

- Pretende-se construir uma aplicação que seja uma agenda onde se podem guardar e consultar contactos;
- Cada contacto é constituído pelos seguintes campos (outros de controle podem ser adicionados à estrutura):
  - Nome (max 100 char);
  - Nº cartão cidadão (não pode ser repetido);
  - Idade (int);
  - Telefone (9 char);
- Para a construção do menu é obrigatório a utilização da biblioteca menu;
- Para solicitar dados ao utilizador é obrigatório a utilização da biblioteca ui e as frases definidas em constants.h.
- Só está autorizado a editar os ficheiros main-c e agenda.c
- O ficheiro agenda.h possui a definição da estrutura de dados a utilizar e não pode ser alterado.
- Até selecionar a opção de saída o utilizador pode efetuar o número de operações que entender;
- O conjunto de funcionalidade a implementar são:
  1. Inserir Contacto;
  2. Apagar contacto (sempre pelo número do CC);
  3. Imprimir toda a agenda.
  4. Sair (e limpa toda a memória)
- Cada contacto deve ser impresso com a função que se apresenta abaixo, a ser por vós implementada no ficheiro agenda.c (é uma função interna da biblioteca):
  
```c
void imprime_contacto(Contacto *c)
{
    printf("-> %s, %d anos [CC:%s] [Tlf:%s]\n", c->nome, c->idade, c->cc, c->telefone);
}
```
