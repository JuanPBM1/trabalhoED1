#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

 using namespace std;


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

void imprimir(pet *elemento);

void limparConsole();

void printarLista(head *lista); 

void alterar(pet *atual, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade);

void lerArquivo(head *list);

void salvarArquivo(head *list);

void adicionar(head* list, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade);

void remover(head * list, int matricula);

pet* pesquisarMatricula(head* list, int matricula);

pet* pesquisarDono(head * list, string nomeDono);

void limparLista(head *lista);

string cxAlta(string texto);

int matDisponivel(head *lista,int matricula);
