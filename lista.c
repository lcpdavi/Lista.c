#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Pessoa{
    int id;
    char nome[30];
    int idade;
    struct Pessoa *prox;

}Pessoa;
//funcao que cria a lista vazia
 Pessoa* criarListaVazia(){

    return NULL;
    }
 //criar uma nova pessoa
 //retorna o endereco da nova pessoa
 Pessoa* criarPessoa(){
    Pessoa *novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if(novaPessoa == NULL){
        //memoria insuficiente
        printf("Erro de alocacao.\n");
        exit(EXIT_FAILURE);
    }
    novaPessoa->prox = NULL;
    return novaPessoa;//endereco de memoria alocado para nova pessoa
 }

 Pessoa* cadastrar(Pessoa *lista){
    Pessoa *novaPessoa = criarPessoa();
    //inserir as informacoes
    srand(time(NULL));
    novaPessoa->id = rand() % 100;
    printf("Digite o nome:\n");
    fflush(stdin);
    fgets(novaPessoa->nome, sizeof(novaPessoa), stdin);
    printf("Digite a idade:\n");
    fflush(stdin);
    scanf("%d", &novaPessoa->idade);

    //duas situacoes 1 - lista vazia, 2 - Ja tem alguem na lista
    if(lista == NULL){
        return novaPessoa;
    }else{
        //percorrer a lista ate encontrar a pessoa que apornta para NULL
        Pessoa *atual = lista;
        while(atual != NULL){
            atual = atual->prox;
        }
        atual->prox = novaPessoa;
        return lista;
    }
 }
int main(){

    int opcao;
    Pessoa *lista = criarListaVazia();

    do{
        printf("1- Cadastrar.\n");
        fflush(stdin);
        printf("2- Mostrar.\n");
        fflush(stdin);
        printf("3- Buscar.\n");
        fflush(stdin);
        printf("4- Alterar.\n");
        fflush(stdin);
        printf("5- Excluir.\n");
        fflush(stdin);
        printf("0- Sair.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            cadastrar(lista);
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    }while(opcao != 0);
}