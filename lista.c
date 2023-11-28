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
    fgets(novaPessoa->nome, sizeof(novaPessoa->nome), stdin);
    printf("Digite a idade:\n");
    fflush(stdin);
    scanf("%d", &novaPessoa->idade);

    //duas situacoes 1 - lista vazia, 2 - Ja tem alguem na lista
    if(lista == NULL){
        return novaPessoa;
    }else{
        //percorrer a lista ate encontrar a pessoa que aponta para NULL()

        // quando a lista for nula, ela vai inserir uma nova pessoa onde ira pegar o endereco de memoria da 
        // nova pessoa, dai vai deixar de ser NULL e vai pra outra lista

        //o atual vai receber o endereço de memoria da proxima pessoa ate ficar NULL, e o ulimo aponta para NULL

        Pessoa *atual = lista;
        while(atual -> prox!= NULL){
            atual = atual->prox;
        }
        atual->prox = novaPessoa;
        return lista;
    }
}
 
void mostrar(Pessoa *lista){
    if(lista == NULL){
        printf("Lista nula.");
    }else{

        Pessoa *atual = lista;
        while(atual != NULL){
            printf("Nome: %s", atual->nome);
            printf("Idade: %d",atual->idade);
            printf("id: %d", atual->id);
            atual = atual->prox;

        }
    }
}

Pessoa* buscarPessoa(Pessoa *lista, int idBusca){
    if(lista == NULL){
        printf("Lista nula.");
        return lista;
    }else{
        Pessoa *atual = lista;
        while(atual != NULL){
            if(atual-> id == idBusca){
                printf("Nome: %s", atual->nome);
                printf("Idade: %d",atual->idade);
                printf("id: %d", atual->id);
                return atual;
            }
            atual = atual->prox;
        }
        printf("Pessoa nao encontrada.");
        return NULL;
    }
}
void alterar(Pessoa *encontrada){
    printf("Digite o nome:\n");
    fflush(stdin);
    fgets(encontrada->nome, sizeof(encontrada->nome), stdin);
    fflush(stdin);
    printf("Digite a idade:\n");
    fflush(stdin);
    scanf("%d", &encontrada->idade);
    
}
Pessoa* excluir(Pessoa *lista, int idBusca){
    Pessoa *anterior = NULL;
    Pessoa *atual = lista;

    while(atual != NULL && atual-> id != idBusca){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual != NULL){
        //logica de exclusao
        if(anterior !=NULL){
            //excluir alguem que nao esta no inicio da lista
            anterior->prox = atual->prox;
        }else{
            //excluir que o primeiro da lista
            lista = atual->prox;
        }
        free(atual);
        printf("Excluido com sucesso.");

    }else{
        printf("Pessoa nao encontrada.");
    }
    return lista;
}
int main(){

    int opcao, idBusca;
    Pessoa *lista = criarListaVazia();
    Pessoa *encontrada;

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
        printf("0- Sair.\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastrar(lista);
            case 2:
                mostrar(lista);
                break;
            case 3:
                printf("Digite o id para busca:\n");
                scanf("%d", &idBusca);
                encontrada = buscarPessoa(lista, idBusca);
                break;
            case 4:
                printf("Digite o id para busca:\n");
                scanf("%d", &idBusca);
                encontrada = buscarPessoa(lista, idBusca);
                if(encontrada != NULL){
                    alterar(encontrada);
                }
                break;
            case 5:
                printf("Digite o id para busca:\n");
                scanf("%d", &idBusca);
                lista = excluir(lista, idBusca); 
                break;
            default:
                break;
        }
    }while(opcao != 0);
}