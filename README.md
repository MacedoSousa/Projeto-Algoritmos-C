# Projeto Algoritmos em C

Este repositório contém implementações de projetos práticos de algoritmos em linguagem C, com foco em análise de complexidade e testes de desempenho.

## Projeto 01: Auditoria Experimental da Busca Sequencial

**Objetivo:** Comprovar experimentalmente as três métricas clássicas de complexidade da busca sequencial em vetores não ordenados.

### O que foi implementado:
- Função de busca sequencial com contador de comparações.
- **Testes Unitários:** Validação automatizada de cenários lógicos usando `<assert.h>`.
- **Teste de Carga e Estresse:** Execução de 10.000 buscas em um vetor de 10 milhões de elementos, medindo o *throughput* (tempo de CPU e total de comparações).
- **Experimentos Base:** 
  - **Melhor caso ($\Omega(1)$):** Busca na primeira posição (1 comparação).
  - **Pior caso ($O(n)$):** Busca de elemento inexistente ($n$ comparações).
  - **Caso médio ($\Theta(n)$):** Média de 1.000 buscas convergindo para a fórmula teórica $\frac{n + 1}{2}$.

### Como compilar e executar

```bash
gcc busca_sequencial.c -o busca_sequencial
./busca_sequencial
