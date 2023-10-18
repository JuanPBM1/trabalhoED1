#include "func.h"

//criar funcaopara otimizar a entrada de valores

void adicionar(head* list, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade) {
    pet* novo = new pet;
    novo->matricula = matricula;
    novo->nomePet = nomePet;
    novo->nomeDono = nomeDono;
    novo->tipo = tipo;
    novo->sexo = sexo;
    novo->idade = idade;
    novo->prox = nullptr;

    novo->prox = list->comeco;
    list->comeco = novo;
    list->cont++;
}

void remover(head * list, int matricula){
    pet * primeiro = list->comeco;
    pet * aux = nullptr;

    if(primeiro != nullptr && list->comeco->matricula == matricula){
        aux = list->comeco;
        list->comeco = aux->prox;
    }
    else{
        while(primeiro != nullptr && primeiro->prox != nullptr && primeiro->prox->matricula==matricula){
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

void pesquisarMatricula(head * list, int matricula){
    pet *aux = list->comeco;

    while(aux!=nullptr && aux->matricula!=matricula){
        aux=aux->prox;
    }
    if(aux->matricula==matricula){
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

 void lerArquivo(head list){ // Não coloquei um ponteiro da lista como argumento, pois quando usamos a funcao adicionar ja tera um ponteiro apotando para lista
        string temp, linhaTexto, dado;
        vector<string> vet;
        int teste, aux0, aux5;

        ifstream MyReadFile("filename.csv");
    if (!MyReadFile.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
    }

    while (getline(MyReadFile, linhaTexto)) { //aqui o programa pega a linha até o \n no arquivo e armazena em linha texto
        stringstream s(linhaTexto); //fazemos linhatexto virar uma stream de dados
        while (getline(s, dado, ',')) { //pega os dados até a vírgula, separando-os
            vet.push_back(dado); //coloca os dados dentro de um vetor de string
        }

        if (vet.size() >= 5) { // checa se o vetor tem o tamanho certo
            try { //se n conseguir converter, ocorre a excessão
                aux0 = stoi(vet[0]);
                aux5 = stoi(vet[5]);
            } catch (const std::invalid_argument& e) {
                cerr << "Erro ao converter idade para inteiro: " << e.what() << endl;
                aux0 = 0;
                aux5 = 5;
            }
            adicionar(&list, aux0, vet[1], vet[2], vet[3], vet[4], aux5);
        } else {
            cerr << "Dados insuficientes na linha: " << linhaTexto << endl;
        }
        vet.clear(); 
}
 }

void salvarArquivo(head *list) {
    pet *copia = list->comeco;
    
    ofstream MyFile("filename.csv");
    if (!MyFile.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    while (copia != nullptr) {
        // Escreva os dados da lista copia no arquivo MyFile
        MyFile << copia->matricula << "," << copia->nomePet << "," << copia->nomeDono<< "," << copia->tipo << "," << copia->sexo << "," << copia->idade<<endl;
        copia = copia->prox;
    }

    MyFile.close();
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