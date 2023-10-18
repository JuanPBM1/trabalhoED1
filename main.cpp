#include <iostream>
#include "includes/func.h"

int main(){
    head lista;
    lista.comeco=nullptr;
    lista.cont=0;

    lerArquivo(&lista);
    int opcao;
    pet *aux;

    int matricula, idade;
    string nomePet, nomeDono, tipo, sexo;
 // colocar if e else para diferenciar SO limpar console 
 // ou so colocar a funcao de ler arquivo
 // criar algo para quando o usurio fechar o aplicativo e voltar, precisamos aproveitar as informações salvas no arquivo
 // inicializar lista com base no arquivo /  Criar uma funcao para inicializar a lista com base na lista
    do {
        cout << "       Sistema Cadastral        " <<endl;
        cout << "--------------------------------" <<endl;
        cout << "[1] - Cadastrar Pet" <<endl;
        cout << "[2] - Alterar Cadastro" <<endl;
        cout << "[3] - Excluir Cadastro" <<endl;
        cout << "[4] - Imprimir Listagem" <<endl;
        cout << "[5] - Buscar P/ Matricula" <<endl;
        cout << "[6] - Buscar P/ Nome do Dono" <<endl;
        cout << "[7] - Ordernar 1" <<endl;
        cout << "[8] - Ordernar 2" <<endl;
        cout << "[9] - Sair e Salvar" <<endl;
        cout << "[10] - Formatar Sistema Cadastral" <<endl;
        
        cout << "Digite uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1: // Inserir lista
            cout << endl<< "Digite o ID do Pet: ";
            cin >> matricula;
            cout << endl<< "Digite o nome do Pet: ";
            cin >> nomePet;
            cout << endl<< "Digite o nome do dono do Pet: ";
            cin >> nomeDono;
            cout << endl<< "Digite o tipo do Pet: ";
            cin >> tipo;
            cout << endl<< "Digite o sexo do Pet: ";
            cin >> sexo;
            cout << endl<< "Digite a idade do Pet: ";
            cin >> idade;
            adicionar(&lista, matricula, nomePet, nomeDono, tipo, sexo, idade);
            break;
       
        case 2: // Alterar Cadastro com base na matricula
        //dar uma melhorada depois (colocar pro user identificar oq quer mudar)
            cout << endl<< "Digite o ID do Pet em que deseja Alterar Cadastro: " <<endl;
            cin >> matricula;
            cout <<endl;
            aux = pesquisarMatricula(&lista, matricula); //Pesquisa a matricula e armazena o ponteiro para a struct da matricula
            if (aux->matricula == matricula) {
                cout << "Digite o novo ID do Pet: " <<endl;
                cin >> aux->matricula;
                cout << "Digite o novo nome do Pet: " <<endl;
                cin >> aux->nomePet;
                cout << "Digite o novo nome do dono do Pet " <<endl;
                cin >> aux->nomeDono;
                cout << "Digite o novo tipo do Pet: " <<endl;
                cin >> aux->tipo;
                cout << "Digite o novo sexo do Pet: " <<endl;
                cin >> aux->sexo;
                cout << "Digite a nova idade do Pet: " <<endl;
                cin >> aux->idade;
                alterar(aux, matricula, nomePet, nomeDono, tipo, sexo, idade);
            }
            else {
                cout << "Pet não encontrado" <<endl;
            }
            break;
       
        case 3: // Excluir com base na matricula
            cout << endl<< "Digite o ID do Pet em que deseja Excluir Cadastro: " <<endl;
            cin >> matricula;
            remover(&lista, matricula);
            break;
        
        case 4: // Imprimir Listagem 
            cout << endl;
            printarLista(&lista);
            break;
        
        case 5: //Buscar por matricula- //deixar saida estetica //fazer funcao print saida
            cout << endl;
            aux = pesquisarMatricula(&lista, matricula);
            if (aux){
                 cout << aux->matricula << ", " << aux->nomePet << ", " << aux->nomeDono << ", " << aux->tipo << ", " << aux->sexo << ", " << aux->idade <<endl; 
            }
             else {
                cout << "Pet não encontrado" <<endl;
            }
            break;

        case 6: //Buscar por nome do dono
            cout << endl;
            aux = pesquisarDono(&lista, nomeDono);
            if (aux){
                 cout << aux->matricula << ", " << aux->nomePet << ", " << aux->nomeDono << ", " << aux->tipo << ", " << aux->sexo << ", " << aux->idade <<endl; 
            }
             else {
                cout << "Pet não encontrado" <<endl;
            }
            break;
       
        case 7: 
            // ordernar1
            break;
        
        case 8:
            // ordernar2
            break;
        
        case 9: // salvar no arquivo
            salvarArquivo(&lista);
            break;
        
        case 10: //limpar lista e arquivo
            limparLista(&lista);
            break;
        
        default:
            cout << "Dígito Inválido!" <<endl;
            break;
        }

    } while(opcao != 9);
}