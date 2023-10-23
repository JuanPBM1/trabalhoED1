#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

 using namespace std;

const char *returnOS();

struct pet{
    int matricula;
    string nomePet;
    string nomeDono;
    string tipo;
    string sexo;
    int idade;
    pet* prox;
};

struct head{
    int cont;
    pet* comeco;
};

void imprimirComPosicao(pet *elemento, int posicao);

void imprimir(pet *elemento);

void limparConsole();

void printarLista(head *lista);

void alterar(pet *atual, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade);

void lerArquivo(head *list);

void salvarArquivo(head *list);

void adicionar(head* list, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade);

int adicionarFinal(head* list, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade);

void remover(head * list, int matricula);

pet* pesquisarMatricula(head* list, int matricula); //busca sequencial (se a pessoa não ordenou a lista)

pet* pesquisarDono(head * list, string nomeDono, int &posicao); //busca sequencial

pet* buscabinariaMatricula(head * lista, int matricula); //busca binária (se a pessoa ordenou a lista)

void limparLista(head *lista);

string cxAlta(string texto);

int matDisponivel(head *lista,int matricula);

void trocarDados(pet *p1, pet *p2);

void trocaNode(pet **cabeca, pet *node1, pet *node2);

void selectionSort(head *cabeca);

void bubbleSort(head *list);

void alterar(pet *atual, int matricula, head lista);

bool estaOrdenado(head *lista);
