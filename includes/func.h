#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


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

void lerArquivo(head list);

void salvarArquivo(head *list);

void adicionar(head* list, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade);

void remover(head * list, int matricula);

void pesquisarMatricula(head * list, int matricula);

void pesquisarDono(head * list, int nomeDono);

//void pesquisar(head * list, int tipoDePesquisa,string nomePet = "", string nomeDono = "");

