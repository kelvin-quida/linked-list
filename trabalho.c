#include <stdio.h>
#include <stdlib.h>

struct Banco
{
    int numero_conta;
    char nome_cliente[30];
    float saldo;
    struct Banco *anterior;
    struct Banco *proximo;
};
typedef struct Banco node;

void insereFinal(struct Banco *CABECA)
{
    struct Banco *p = CABECA;
    struct Banco *novo = (struct Banco *)malloc(sizeof(struct Banco));

    if (!novo)
    {
        printf("Sem espaco na memoria!");
        exit(1);
    }

    printf("Informe o numero da conta: ");
    scanf("%d", &novo->numero_conta);

    // Verifica se o número da conta já existe na lista
    struct Banco *aux = CABECA->proximo;
    while (aux != NULL)
    {
        if (aux->numero_conta == novo->numero_conta)
        {
            printf("Numero ja contido na lista, operacao cancelada\n");
            free(novo);
        }
        aux = aux->proximo;
    }

    printf("Informe o nome do cliente: ");
    scanf("%s", novo->nome_cliente);

    printf("Informe o saldo do cliente: ");
    scanf("%f", &novo->saldo);

    while (p->proximo != NULL)
    {
        p = p->proximo;
    }

    novo->proximo = NULL;
    novo->anterior = p;
    p->proximo = novo;
}

void imprime(struct Banco *CABECA)
{
    if (CABECA->proximo == NULL)
    {
        printf("Lista vazia!!\n");
    }
    else
    {
        struct Banco *aux = CABECA->proximo;
        printf("\n Imprimindo a lista \n");
        while (aux != NULL)
        {
            printf("\n------------------------------\n");
            printf("Conta do Cliente: %d\n", aux->numero_conta);
            printf("Nome do Cliente: %s\n", aux->nome_cliente);
            printf("Saldo do Cliente: %f\n", aux->saldo);
            printf("Endereco do node: %x\n", aux);
            printf("Endereco do node next: %x\n", aux->proximo);
            printf("\n------------------------------\n");
            aux = aux->proximo;
        }
    }
    printf("\n\n");
}

void removerNode(struct Banco *CABECA)
{
    int numero_conta;
    printf("Informe o node a ser removido: ");
    scanf("%d", &numero_conta);

    struct Banco *p = CABECA->proximo;

    while (p != NULL)
    {
        if (p->numero_conta == numero_conta)
        {
            printf("\n------------------------------\n");
            printf("Node a ser removido: ");
            printf("Conta do Cliente: %d\n", p->numero_conta);
            printf("Nome do Cliente: %s\n", p->nome_cliente);
            printf("Saldo do Cliente: %f\n", p->saldo);
            printf("Endereco do node: %x\n", p);
            printf("Endereco do node next: %x\n", p->proximo);
            printf("\n------------------------------\n");
            if (p->anterior != NULL)
            {
                p->anterior->proximo = p->proximo;
            }
            if (p->proximo != NULL)
            {
                p->proximo->anterior = p->anterior;
            }
            free(p);
            printf("\n\nNode removido com sucesso!\n\n");
            return;
        }
        p = p->proximo;
    }
    printf("\n\nNode nao esta na lista\n\n");
}

int main()
{
    int opt = 0;

    struct Banco *CABECA = (struct Banco *)malloc(sizeof(struct Banco));
    if (!CABECA)
    {
        printf("Sem espaco em memoria");
        exit(1);
    }

    CABECA->proximo = NULL;

    do
    {
        printf("Escolha a opcao\n");
        printf("0. Sair\n");
        printf("1. Exibir lista\n");
        printf("2. Adicionar node\n");
        printf("3. Remove node da lista\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("\n\nOpcao 1 selecionada \n\n");
            imprime(CABECA);
            break;
        case 2:
            printf("\n\nOpcao 2 selecionada \n\n");
            insereFinal(CABECA);
            break;
        case 3:
            printf("\n\nOpcao 3 selecionada \n\n");
            removerNode(CABECA);
            break;
        case 0:
            printf("\n\nEncerrando..\n\n");
            break;
        default:
            printf("\n\nOpcao invalida..\n\n");
        }

    } while (opt != 0);

    return 0;
}
