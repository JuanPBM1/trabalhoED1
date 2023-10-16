#include <iostream>
#include <cstring>
 using namespace std;


struct pet{
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

void adicionar(head * list,string nomePet,string nomeDono,string tipo, string sexo, int idade);

void remover(head * list, string nome);

//void pesquisar(head * list, int tipoDePesquisa,string nomePet = "", string nomeDono = "");

