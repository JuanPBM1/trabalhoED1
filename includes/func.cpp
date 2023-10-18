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

void alterar(pet *atual, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade){
    atual->matricula =  matricula;
    atual->nomePet = nomePet;
    atual->nomeDono = nomeDono;
    atual->tipo = tipo;
    atual->sexo = sexo;
    atual->idade = idade;
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

void printarLista(head *lista){ //deixar a saida mais estetica
    pet *aux = lista->comeco;

    cout << "Pets cadastrados: " << lista->cont <<endl<<endl;
    while(aux != nullptr){
        cout << aux->matricula << ", " << aux->nomePet << ", " << aux->nomeDono << ", " << aux->tipo << ", " << aux->sexo << ", " << aux->idade <<endl;
        aux = aux->prox;
    }

}

pet* pesquisarMatricula(head* list, int matricula) {
    pet* aux = list->comeco;

    while (aux != nullptr && aux->matricula != matricula) {
        aux = aux->prox;
    }
    
    if (aux != nullptr && aux->matricula == matricula) {
        return aux; // Matrícula encontrada, retorna o ponteiro para o pet
    } else {
        return nullptr; // Matrícula não encontrada, retorna nullptr
    }
}

pet* pesquisarDono(head * list, string nomeDono){
    pet *aux = list->comeco;

    while (aux != nullptr && aux->nomeDono != nomeDono) {
        aux = aux->prox;
    }
    
    if (aux != nullptr && aux->nomeDono == nomeDono) {
        return aux; // Matrícula encontrada, retorna o ponteiro para o pet
    } else {
        return nullptr; // Matrícula não encontrada, retorna nullptr
    }
}

 void lerArquivo(head *list){ // Não coloquei um ponteiro da lista como argumento, pois quando usamos a funcao adicionar ja tera um ponteiro apotando para lista
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
            adicionar(list, aux0, vet[1], vet[2], vet[3], vet[4], aux5);
        } else {
            cerr << "Dados insuficientes na linha: " << linhaTexto << endl;
        }
        vet.clear(); 
}
 }

void salvarArquivo(head *list){
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

void limparLista(head *lista){
    pet *primeiro = lista->comeco, *aux;

    while(primeiro != nullptr){
        aux = primeiro;
        primeiro = primeiro->prox;
        delete(aux);
    }
    lista->comeco = nullptr; 
}



