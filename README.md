# Projeto Algoritmos em C

Este repositório contém implementações de projetos práticos de algoritmos em linguagem C, com foco em análise de complexidade e testes de desempenho.

## Projeto 01: Auditoria Experimental da Busca Sequencial

**Objetivo:** Comprovar experimentalmente as três métricas clássicas de complexidade da busca sequencial em vetores não ordenados.

### Conceitos e Metodologia (Por que fizemos assim?)
**Por que uma "Auditoria Experimental"?** 
Normalmente, a análise de complexidade de algoritmos (Notação Big-O) é ensinada de forma puramente teórica e matemática. O objetivo de estruturar o código em formato de "auditoria" com testes de estresse é fazer a ponte entre a teoria e o hardware. Em vez de apenas aceitar que o caso médio é $\Theta(n)$, nós instruímos o computador a rodar milhares de simulações e contar as comparações reais para provar que elas convergem para a fórmula matemática $\frac{n + 1}{2}$.

**Conceitos de Complexidade Aplicados:**
- **Melhor Caso ($\Omega(1)$):** O elemento procurado é o primeiro do vetor. Custo constante de 1 comparação independente do tamanho de $n$.
- **Pior Caso ($O(n)$):** O elemento não existe no vetor (ou é o último). O algoritmo é obrigado a varrer toda a estrutura, exigindo $n$ comparações.
- **Caso Médio ($\Theta(n)$):** Assumindo distribuição uniforme onde o elemento tem a mesma chance de estar em qualquer posição, a busca precisará varrer, em média, metade do vetor.

### O que foi implementado:
- Função de busca sequencial com contador de comparações injetado via ponteiro.
- **Testes Unitários:** Validação automatizada de cenários lógicos usando `<assert.h>` para garantir a integridade da lógica antes dos testes de carga.
- **Teste de Carga e Estresse:** Execução de 10.000 buscas em um vetor de 10 milhões de elementos, medindo o *throughput* (tempo de CPU e total de comparações no nível do bilhão).
- **Experimentos Base:** Avaliação automatizada e impressão lado a lado das comparações reais versus a complexidade teórica para vetores de diferentes tamanhos (100, 1.000 e 10.000).

### Como compilar e executar

```bash
gcc busca_sequencial.c -o busca_sequencial
./busca_sequencial
