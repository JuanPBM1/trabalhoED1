#include "func.h"

const char *returnOS() { 
    #ifdef _WIN32 
         return "cls";  
     #else 
         return "clear"; 
     #endif 
 } 

void adicionar(head* list, int matricula, string nomePet, string nomeDono, string tipo, string sexo, int idade) {
    pet* novo = new pet;
    novo->matricula = matricula;
    novo->nomePet = nomePet;
    novo->nomeDono = nomeDono;
    novo->tipo = tipo;
    novo->sexo = sexo;
    novo->idade = idade;
    novo->prox = nullptr;

    novo->prox = list->comeco; //Por adicionarmos no início da lista, o 1° pet virará o próximo nó da lista, pois o novo será o primeiro nó da lista (o próximo do novo vira o começo da lista)
    list->comeco = novo; //o começo da lista vira o novo pet
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
    pet * primeiro = list->comeco; //cópia de segurança para não perder onde a lista começa após remover o elemento
    pet * aux = nullptr;

    if(primeiro != nullptr && list->comeco->matricula == matricula){ //Excluir o primeiro pet da lista
        aux = list->comeco; //Guarda o elemento que será deletado
        list->comeco = aux->prox; //Excluir o primeiro pet e torna o segundo o primeiro
    }
    else if (list->cont == 0){
        cout<< "Não há Pets para excluir!";
    }
    else{
        while(primeiro != nullptr && primeiro->prox != nullptr && primeiro->prox->matricula==matricula){ // Excluir pets ao longo da lista
            primeiro = primeiro -> prox; // busca sequencial
        }
        if(primeiro != nullptr && primeiro->prox != nullptr){ // Testa se tem mais de 1 pet na lista
            aux = primeiro -> prox; // Guarda o elemento que será deletado
            primeiro -> prox = aux->prox; //Faz a costura da lista, ex: se vamos excluir 2º pet em uma lista com 3 pets, o 3º Pet passara a ser o segundo
        }
    }
    
    if(aux){ //Se aux não é nulo
        delete aux;
        list->cont--;
        cout<<"Pet com ID "<<matricula<<" foi removido!";
    }
}

void imprimir(pet *elemento){ //padronização das saídas
    cout<<"----------Pet "<<elemento->matricula<<"----------"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"ID: "<< elemento->matricula << endl;
    cout<<"Nome do Pet: "<< elemento->nomePet << endl;
    cout<<"Dono: "<< elemento->nomeDono << endl;
    cout<<"Tipo: "<< elemento->tipo << endl;
    cout<<"Sexo do Pet: "<< elemento->sexo << endl;
    cout<<"Idade (em meses): "<< elemento->idade << endl;
    cout<<"------------------------------"<< endl;
}

void limparConsole(){
    const char *OS = returnOS();
    string confirm;
    cout<<endl<<"Digite \"OK\" para continuar...";
    cin>>confirm;
    system(OS);
}

void printarLista(head *lista){ //printa a lista inteira
    pet *aux = lista->comeco;

    cout << "Pets cadastrados: " << lista->cont <<endl<<endl;
    while(aux != nullptr){
        imprimir(aux);
        aux = aux->prox;
    }
    limparConsole();
}

pet* pesquisarMatricula(head* list, int matricula) {
    pet* aux = list->comeco;

    while (aux != nullptr && aux->matricula != matricula) {
        aux = aux->prox;
    }
    
    if (aux != nullptr && aux->matricula == matricula) {
        return aux; // Matrícula encontrada, retorna o ponteiro para o pet
    } else {
        return aux; // Matrícula não encontrada, retorna nullptr
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

    ifstream MyReadFile("pet_data.csv");
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
    
    ofstream MyFile("pet_data.csv");
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
    lista->cont = 0;
}

string cxAlta(string texto){
    transform(texto.begin(),texto.end(),texto.begin(), ::toupper); //aplica uma operação a cada elemento de um intervalo e armazena em outro intervalo
    return texto;
}

int matDisponivel(head *lista,int matricula){
    int i;
    pet* aux;
    aux = pesquisarMatricula(lista,matricula);
    if(aux==nullptr)
        return 0; //Quando não acha uma matrícula igual
    else
        return 1; //Quando acha uma matrícula igual
    
}

void trocarDados(pet *p1, pet *p2){
    if(p1 != nullptr && p2 != nullptr){
    
    int matricula=p1->matricula;
    string nomePet=p1->nomePet;
    string nomeDono=p1->nomeDono;
    string tipo=p1->tipo;
    string sexo=p1->sexo;
    int idade=p1->idade;

    p1->matricula=p2->matricula;
    p1->nomePet=p2->nomePet;
    p1->nomeDono=p2->nomeDono;
    p1->tipo=p2->tipo;
    p1->sexo=p2->sexo;
    p1->idade=p2->idade;

    p2->matricula=matricula;
    p2->nomePet=nomePet;
    p2->nomeDono=nomeDono;
    p2->tipo=tipo;
    p2->sexo=sexo;
    p2->idade=idade;
    }
    else{
        cout<<"ERRO! PONTEIROS NULOS!";
    }
}

void bubbleSort(head *list) {
    int tamanho = list->cont;
    bool ordenado = false;
    pet *primeiro = list->comeco;

    if (list != nullptr) {
        while (!ordenado) {
            ordenado = true;
            primeiro = list->comeco;
            while (primeiro->prox != nullptr) {
                if ((primeiro->matricula) > (primeiro->prox->matricula)) {
                    ordenado = false;
                    trocarDados(primeiro, primeiro->prox);
                }
                primeiro = primeiro->prox;
            }
        }
        cout<<endl<<"A lista foi organizada em ordem crescente de ID com sucesso.";
    } else {
        cout << endl << "A lista está vazia!" << endl;
    }
}

void alterar(pet *atual, int matricula, head lista)
{

    int matricula2, idade2, opcao;
    string nomePet2, nomeDono2, tipo2, sexo2;

    if(atual==nullptr)
        cout << "Pet não encontrado" <<endl;
    else if (atual->matricula == matricula)
    {
        cout<< "Deseja alterar qual campo abaixo: "<<endl;
        cout<< "[1] - ID" <<endl;
        cout<< "[2] - Nome do Pet" <<endl;
        cout<< "[3] - Nome do Dono" <<endl;
        cout<< "[4] - Tipo" <<endl;
        cout<< "[5] - Sexo" <<endl;
        cout<< "[6] - Idade" <<endl;
        cin>> opcao;

        switch (opcao)
        {
        case 1:
            do
            {
                cout<<"Digite o novo ID do Pet: ";
                cin >> matricula2;
                if(matDisponivel(&lista,matricula2)==1)
                {
                    cout<<"Essa matrícula já está em uso, digite outra!"<<endl<<endl;
                    limparConsole();
                }
                
            }
            while(matDisponivel(&lista,matricula2)==1);
            atual->matricula =  matricula2;
            "O cadastro do Pet foi alterado com sucesso!";
            break;

        case 2:
            cout << endl<<"Digite o novo nome do Pet: ";
            getline(cin,nomePet2);
            getline(cin,nomePet2);
            atual->nomePet = cxAlta(nomePet2);
            "O cadastro do Pet foi alterado com sucesso!";
            break;

        case 3:
            cout << endl<< "Digite o nome do dono do Pet: ";
            getline(cin,nomeDono2);
            getline(cin,nomeDono2);
            atual->nomeDono = cxAlta(nomeDono2);
            "O cadastro do Pet foi alterado com sucesso!";
            break;

        case 4:
            cout << "Digite o novo tipo do Pet: " <<endl;
            getline(cin,tipo2);
            getline(cin,tipo2);
            atual->tipo = cxAlta(tipo2);
            "O cadastro do Pet foi alterado com sucesso!";
            break;

        case 5:
            cout << endl<< "Digite o sexo do Pet: ";
            getline(cin,sexo2);
            getline(cin,sexo2);
            atual->sexo = cxAlta(sexo2);
            "O cadastro do Pet foi alterado com sucesso!";
            break;

        case 6:
            cout << endl<< "Digite a idade do Pet (em meses): ";
            cin >> idade2;
            atual->idade = idade2;
            cout<<"O cadastro do Pet foi alterado com sucesso!";
            break;

        default:
            cout << "Dígito Inválido!" <<endl;
            break;
        }
    }
}
