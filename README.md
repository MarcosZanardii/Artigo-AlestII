# Sistema de Caminhamento de Árvore em Matriz

Este projeto implementa um sistema para percorrer uma árvore representada em forma de matriz, utilizando um algoritmo de caminhamento pós-ordem. O código é desenvolvido em C++ e é capaz de calcular a maior soma dos valores encontrados durante o percurso na árvore.

## Descrição

O programa lê uma matriz que representa a árvore, onde cada posição pode conter um valor numérico ou indicar uma bifurcação (`V` ou `W`) e termina com um símbolo `#`. O objetivo é calcular a soma máxima dos valores percorridos em um caminho, de acordo com as regras de movimentação especificadas.

## Estrutura do Código

O código é composto por várias funções principais:

- **postOrder**: Realiza o caminhamento pós-ordem na árvore, somando os valores encontrados durante o percurso e atualizando o valor máximo se necessário.
  
- **TreeMatriz**: Preenche a matriz a partir da entrada do usuário, armazenando os valores na estrutura de dados apropriada.

- **encontraRaiz**: Localiza a posição da raiz da árvore, que é o primeiro elemento diferente de vazio na última linha da matriz.

- **deleteTreeMatriz**: Libera a memória alocada para a matriz.

- **main**: Função principal que gerencia a execução do programa, realizando a leitura da matriz e chamando as funções necessárias para calcular e exibir a maior soma encontrada.

## Como Usar

1. **Compilação**: Utilize um compilador de C++ para compilar o código. Por exemplo:
   ```bash
   g++ -o arvore arvore.cpp
