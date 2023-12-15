#include <stdio.h>
#include <stdlib.h>

void cabecalho () {
    printf("1. Adicionar venda\n");
    printf("2. Exibir vendas\n");
    printf("3. Calcular total de vendas\n");
    printf("4. Consultar carrinho\n");
    printf("5. Sair\n");
}

// Estrutura para armazenar informações da venda
struct Venda {
    int numero;
    float valor;
};

// Função para adicionar uma nova venda
void adicionarVenda(struct Venda vendas[], int *numVendas) {
    printf("Digite o número da venda: ");
    scanf("%d", &vendas[*numVendas].numero);

    printf("Digite o valor da venda: ");
    scanf("%f", &vendas[*numVendas].valor);

    (*numVendas)++;
}

// Função para exibir todas as vendas
void exibirVendas(struct Venda vendas[], int numVendas) {
    printf("\nVendas realizadas:\n");
    for (int i = 0; i < numVendas; i++) {
        printf("Venda %d: R$ %.2f\n", vendas[i].numero, vendas[i].valor);
    }
    printf("\n");
}

// Função para calcular o total de vendas
float calcularTotalVendas(struct Venda vendas[], int numVendas) {
    float total = 0;
    for (int i = 0; i < numVendas; i++) {
        total += vendas[i].valor;
    }
    return total;
}

// Função para consultar o carrinho (vendas não finalizadas)
void consultarCarrinho(struct Venda vendas[], int numVendas) {
    if (numVendas == 0) {
        printf("\nCarrinho vazio.\n");
    } else {
        printf("\nVendas no carrinho:\n");
        for (int i = 0; i < numVendas; i++) {
            printf("Venda %d: R$ %.2f\n", vendas[i].numero, vendas[i].valor);
        }
        printf("\n");
    }
}

int main() {
    struct Venda vendas[100]; // Supomos que haverá no máximo 100 vendas
    int numVendas = 0;
    int opcao;

    do {
        // Menu de opções
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarVenda(vendas, &numVendas);
                break;
            case 2:
                exibirVendas(vendas, numVendas);
                break;
            case 3:
                printf("Total de vendas: R$ %.2f\n", calcularTotalVendas(vendas, numVendas));
                break;
            case 4:
                consultarCarrinho(vendas, numVendas);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
