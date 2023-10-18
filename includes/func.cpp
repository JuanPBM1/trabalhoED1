#include "func.h"

void gArquivo(){
    //Lê o arquivo e coloca na memória;se não tiver nada, cria arquivo
    ifstream MyReadFile("dados.csv");
    
    //Cria arquivo
    //Salva o arquivo
    
}

void adicionar(head * list,string nomePet,string nomeDono,string tipo, string sexo, int idade){
    pet* novo = new pet; //Aloca a memória
    novo -> nomePet = nomePet; //Inicializa cada valor da struct
    novo -> nomeDono = nomeDono;
    novo -> tipo = tipo;
    novo -> sexo = sexo;
    novo -> idade = idade;
    novo -> prox = nullptr;

    novo -> prox = list -> comeco; //Faz o inserido apontar para o elemento que era o head
    list -> comeco = novo; //faz a struct head apontar para o que realmente é o head agora
    list -> cont++;
}

void remover(head * list, string nomePet){
    pet * primeiro = list->comeco;
    pet * aux = nullptr;

    if(primeiro != nullptr && list->comeco->nomePet == nomePet){
        aux = list->comeco;
        list->comeco = aux->prox;
    }
    else{
        while(primeiro != nullptr && primeiro->prox != nullptr && primeiro->prox->nomePet==nomePet){
            primeiro = primeiro -> prox;
        }
        if(primeiro != nullptr && primeiro->prox != nullptr){
            aux = primeiro -> prox;
            primeiro -> prox = aux->prox;
        }
    }
    if(aux){ //Se aux não é nulo
        delete aux;
        list->cont--;
    }
}

void pesquisarPet(head * list,string nomePet){
    pet *aux = list->comeco;

    while(aux!=nullptr && aux->nomePet!=nomePet){
        aux=aux->prox;
    }
    if(aux->nomePet==nomePet){
        //print do nome do pet
    }
    else{
        //print que não foi encontrado
    }
}
void pesquisarDono(head * list, string nomeDono){
    pet *aux = list->comeco;

    while(aux != nullptr && aux->nomeDono != nomeDono){
        aux = aux->prox;
    }
    if(aux->nomeDono==nomeDono){
        //print nome do dono
    }
    else{
        //print que não foi encontrado
    }
}

/**void pesquisar(head * list, int tipoDePesquisa,string nomePet, string nomeDono){

    pet *aux = list->comeco;

    if(tipoDePesquisa == 1){ // 1 é o nome do pet
        while(aux != nullptr && aux->nomePet != nomePet){
            aux = aux->prox;
        }
        if(aux->nomePet==nomePet){
            //print do nome do pet
        }
        else{
            //print que não foi encontrado
        }
    }
    else if(tipoDePesquisa == 2){ // 2 é o nome do dono
        while(aux != nullptr && aux->nomeDono != nomeDono){
            aux = aux->prox;
        }
        if(aux->nomeDono==nomeDono){
            //print do nome do dono
        }
        else{
            //print que não foi encontrado
        }
    }
}
*/