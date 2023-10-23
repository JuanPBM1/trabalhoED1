#include <iostream>
#include "func.h"

int main(){
    setlocale(LC_ALL, "portuguese");

    head lista;
    lista.comeco=nullptr;
    lista.cont=0;

    lerArquivo(&lista);
    int opcao, selec, posicao;
    pet *aux;
    const char *OS = returnOS();

    int matricula, idade;
    string nomePet, nomeDono, tipo, sexo;


    do {
        cout << "--------------------------------" <<endl;
        cout << "  Sistema Cadastral para Pets!  " <<endl;
        cout << "--------------------------------" <<endl;
        cout << "[1] - Cadastrar Pet" <<endl;
        cout << "[2] - Alterar Cadastro" <<endl;
        cout << "[3] - Excluir Cadastro" <<endl;
        cout << "[4] - Listar Todos os Pets" <<endl;
        cout << "[5] - Buscar P/ Matricula" <<endl;
        cout << "[6] - Buscar P/ Nome do Dono" <<endl;
        cout << "[7] - Ordernar" <<endl;
        cout << "[8] - Salvar e sair" <<endl;
        cout << "[9] - Formatar Sistema Cadastral" <<endl;

        cout << "Digite uma opção: ";
        cin >> opcao;
        system(OS);
        switch (opcao)
        {
        case 1: // Inserir lista
            cout << endl<< "Digite o ID do Pet: ";
            do{ //Tratamento de erro, se o usuário coloca uma matrícula já cadastrada
                cin >> matricula;
                if(matDisponivel(&lista,matricula)==1){
                    cout<<"Essa matrícula já está em uso, digite outra!"<<endl<<endl;
                    limparConsole();
                    cout<<"Digite o novo ID do Pet: ";}
            }while(matDisponivel(&lista,matricula)==1);

            getline(cin,nomePet); //getline para evitar estouro de buffer
            cout << endl<< "Digite o nome do Pet: ";
            getline(cin,nomePet);
            cout << endl<< "Digite o nome do dono do Pet: ";
            getline(cin,nomeDono);
            cout << endl<< "Digite o tipo do Pet: ";
            getline(cin,tipo);
            cout << endl<< "Digite o sexo do Pet: ";
            getline(cin,sexo);
            cout << endl<< "Digite a idade do Pet (em meses): ";
            cin >> idade;
            adicionar(&lista, matricula, cxAlta(nomePet), cxAlta(nomeDono), cxAlta(tipo), cxAlta(sexo), idade);
            salvarArquivo(&lista);
            cout<<endl<<endl<<"O Pet foi cadastrado com sucesso!";
            limparConsole();
            break;

        case 2: // Alterar Cadastro com base na matricula
            cout << endl<< "Digite o ID do Pet que terá o cadastro alterado: " <<endl;
            cin >> matricula;
            cout <<endl;
            system("clear");

            aux = pesquisarMatricula(&lista, matricula); //Pesquisa a matricula e armazena o ponteiro para a struct da matricula
            alterar(aux, matricula, lista);
            salvarArquivo(&lista);

        limparConsole();
        break;

        case 3: // Excluir com base na matricula
            cout << endl<< "Digite o ID do Pet em que deseja Excluir Cadastro: " <<endl;
            cin >> matricula;
            if(pesquisarMatricula(&lista,matricula)!=nullptr){
                remover(&lista, matricula);
                salvarArquivo(&lista);
            }else{
                cout<<"A matrícula informada não consta na lista!";
            }
            limparConsole();
            break;

        case 4: // Imprimir Listagem
            cout << endl;
            printarLista(&lista);
            break;

        case 5: //Buscar por matricula, podendo ser sequencial ou binária
            cout << endl;
            cout<<"Digite o ID do Pet que deseja procurar: ";
            cin>>matricula;
            if(estaOrdenado(&lista)==true){
                aux = buscabinariaMatricula(&lista, matricula);
                if(aux){ //Se aux tiver algo
                    imprimir(aux);
                }
                else{
                    cout << "Pet não encontrado" <<endl;
                }
            }
            else{
                aux = pesquisarMatricula(&lista, matricula);
                if (aux){ //Se aux tiver algo
                    imprimir(aux);
                }
                else {
                    cout << "Pet não encontrado" <<endl;
                }
            }
            limparConsole();
            break;

        case 6: //Buscar por nome do dono
            cout << endl;
            cout<<"Digite o nome do dono do pet que deseja procurar: ";
            getline(cin,nomeDono); //getline para evitar o estouro de buffer (entrada do tipo int indo para tipo string)
            getline(cin,nomeDono);
            aux = pesquisarDono(&lista, cxAlta(nomeDono), posicao);
            if (aux){
                imprimirComPosicao(aux, posicao);

            }
             else {
                cout << "Pet não encontrado!" <<endl;
            }
            limparConsole();
            break;

        case 7: //ordenação por BubbleSort
            system(OS);
            cout<<endl<<"Selecione qual algoritmo de ordenação será utilizado:"<<endl<<endl;
            cout<<"[1] Bubble Sort"<<endl<<"[2] Selection Sort"<<endl<<endl;
            cin>>selec;
            if(selec==1){
                 if(lista.comeco!=nullptr)
                    bubbleSort(&lista);
                else
                    cout<<"A lista está vazia!";
                limparConsole();
            }
            else if(selec==2){
                if(lista.comeco!=nullptr)
                    selectionSort(&lista);
                else
                    cout<<"A lista está vazia!";
                limparConsole();
                break;
            }
            else{
                cout<<"O número fornecido não é válido!";
                limparConsole();
            }
            break;

        case 8: // salvar no arquivo
            salvarArquivo(&lista);
            break;

        case 9: //limpar lista e arquivo
            char c;
            cout<<"Tem certeza que deseja limpar toda a base de dados (ação irreversível!)? (S/N): ";
            cin>>c;
            c=toupper(c);
            if (c=='S'&&lista.comeco!=nullptr)
                limparLista(&lista);
                salvarArquivo(&lista);
            limparConsole();
            break;

        default:
            cout << "Dígito Inválido!" <<endl;
            limparConsole();
            break;
        }

    } while(opcao != 8);
}
