#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// Função de Busca Sequencial normal (rápida para milhões de dados)
int busca_sequencial(int *vet, int n, int chave, long long *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (vet[i] == chave) {
            return i; // Encontrou
        }
    }
    return -1; // Não encontrou
}

// Função de Busca Sequencial Verbosa (Demonstração visual)
int busca_sequencial_verbosa(int *vet, int n, int chave, long long *comparacoes) {
    printf("\n--- Iniciando Busca Passo a Passo (Procurando: %d) ---\n", chave);
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        printf(" [Passo %lld] Analisando indice [%d] -> Valor atual: %d", *comparacoes, i, vet[i]);
        if (vet[i] == chave) {
            printf(" (ENCONTRADO!)\n");
            return i;
        } else {
            printf(" (Diferente)\n");
        }
    }
    printf(" -> Fim da busca: Elemento %d NAO ENCONTRADO.\n", chave);
    return -1;
}

// ==========================================
// DEMONSTRAÇÃO VISUAL PASSO A PASSO
// ==========================================
void demonstrar_passo_a_passo() {
    printf("======================================\n");
    printf(" DEMONSTRACAO PASSO A PASSO\n");
    printf("======================================\n");
    int vet[] = {15, 22, 8, 40, 57, 91, 12};
    int n = 7;
    long long comp = 0;

    printf("Vetor: [");
    for(int i = 0; i < n; i++) {
        printf("%d%s", vet[i], i < n - 1 ? ", " : "]\n");
    }

    // Busca de um elemento que existe
    busca_sequencial_verbosa(vet, n, 40, &comp);

    comp = 0;
    // Busca de um elemento inexistente (Pior caso)
    busca_sequencial_verbosa(vet, n, 99, &comp);
    printf("\n");
}

// ==========================================
// TESTES UNITÁRIOS
// ==========================================
void testar_busca_sequencial() {
    printf("======================================\n");
    printf("[...] Iniciando Testes Unitarios silenciados...\n");
    int vet[] = {10, 20, 30, 40, 50};
    int n = 5;
    long long comp;
    int resultado;

    // Teste 1: Elemento no início (Melhor caso)
    comp = 0;
    resultado = busca_sequencial(vet, n, 10, &comp);
    assert(resultado == 0);
    assert(comp == 1);

    // Teste 2: Elemento no meio
    comp = 0;
    resultado = busca_sequencial(vet, n, 30, &comp);
    assert(resultado == 2);
    assert(comp == 3);

    // Teste 3: Elemento no final
    comp = 0;
    resultado = busca_sequencial(vet, n, 50, &comp);
    assert(resultado == 4);
    assert(comp == 5);

    // Teste 4: Elemento inexistente (Pior caso)
    comp = 0;
    resultado = busca_sequencial(vet, n, 99, &comp);
    assert(resultado == -1);
    assert(comp == 5);

    printf("[+] Todos os testes unitarios passaram com sucesso!\n\n");
}

// ==========================================
// TESTES DE CARGA E ESTRESSE
// ==========================================
void testar_estresse_carga() {
    int n = 10000000; // 10 Milhões de elementos
    printf("======================================\n");
    printf(" TESTE DE CARGA E ESTRESSE (n = %d)\n", n);
    printf("======================================\n");

    int *vet = (int*) malloc(n * sizeof(int));
    if (vet == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    // Preenche vetor
    for (int i = 0; i < n; i++) {
        vet[i] = i;
    }

    int num_buscas = 10000; // 10 mil buscas em um vetor de 10 milhoes
    long long comp_totais = 0;
    long long comp = 0;

    printf("Executando %d buscas aleatorias silenciosas...\n", num_buscas);

    clock_t inicio = clock();

    for(int k = 0; k < num_buscas; k++) {
        comp = 0;
        int chave = (rand() % 2 == 0) ? (rand() % n) : -1;
        busca_sequencial(vet, n, chave, &comp);
        comp_totais += comp;
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("[!] Teste concluido.\n");
    printf(" - Total de comparacoes feitas: %lld\n", comp_totais);
    printf(" - Tempo de CPU gasto: %.4f segundos\n\n", tempo_gasto);

    free(vet);
}

// ==========================================
// EXPERIMENTOS BASE (Projeto 01)
// ==========================================
void executar_experimento(int n) {
    int *vet = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        vet[i] = i;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }

    printf("======================================\n");
    printf(" Experimentos para n = %d\n", n);
    printf("======================================\n");

    long long comp;

    comp = 0;
    busca_sequencial(vet, n, vet[0], &comp);
    printf("Melhor Caso:\n - Comparacoes: %lld\n - Complexidade Teorica: 1\n\n", comp);

    comp = 0;
    busca_sequencial(vet, n, -1, &comp);
    printf("Pior Caso:\n - Comparacoes: %lld\n - Complexidade Teorica: %d\n\n", comp, n);

    long long total_comp_medio = 0;
    int num_buscas = 1000;

    for(int k = 0; k < num_buscas; k++) {
        comp = 0;
        int indice_sorteado = rand() % n;
        busca_sequencial(vet, n, vet[indice_sorteado], &comp);
        total_comp_medio += comp;
    }

    double media = (double)total_comp_medio / num_buscas;
    double teoria = (n + 1) / 2.0;

    printf("Caso Medio (Media de %d buscas):\n - Comparacoes reais (media): %.1f\n - Convergencia Teorica: %.1f\n\n", num_buscas, media, teoria);

    free(vet);
}

int main() {
    srand(time(NULL));

    // 0. Demonstração Visual Passo a Passo
    demonstrar_passo_a_passo();

    // 1. Testes Unitários
    testar_busca_sequencial();

    // 2. Teste de Carga e Estresse
    testar_estresse_carga();

    // 3. Experimentos Base (Melhor, Pior, Medio)
    int tamanhos[] = {100, 1000, 10000};
    for (int i = 0; i < 3; i++) {
        executar_experimento(tamanhos[i]);
    }

    return 0;
}
