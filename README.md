# ED1\_Prova2

Este repositório contém a implementação em C++ e a análise de desempenho de três algoritmos clássicos de ordenação:

* Selection Sort
* Insertion Sort
* Bubble Sort

## Visão Geral

O objetivo deste trabalho é comparar a eficiência dos algoritmos de ordenação por meio de testes de tempo de execução em diferentes tamanhos de entrada e cenários (caso médio, melhor caso e pior caso). Para isso, foi desenvolvido um gerador de dados que cria vetores de números inteiros em ordens variadas.

## Estrutura de Diretórios

```plain
├── CMakeLists.txt        # Script de build CMake
├── codigo                # Código-fonte de implementação
│   ├── busca.cpp         # Funções de busca
│   ├── gerador_dados.cpp # Geração de vetores de teste
│   └── ordenacao.cpp     # Implementação dos algoritmos de ordenação
├── dados                 # Dados usados para cálculos
│   ├── pequeno.bin       # Grupo de dados pequenos
│   ├── medio.bin         # Grupo de dados médios
│   └── grande.bin        # Grupo de dados grandes
└── README.md             # Documentação do projeto
```

## Requisitos

* CMake versão **>= 3.30**
* Compilador C++ com suporte a **C++23** (ex.: GCC 11+, Clang 13+)
* Sistema operacional: Windows, Linux ou macOS

## Compilação

1. Crie o diretório de build e acesse-o:

   ```bash
   mkdir build && cd build
   ```

2. Execute o CMake para gerar os arquivos de projeto:

   ```bash
   cmake ..
   ```

3. Compile o projeto:

   ```bash
   cmake --build .
   ```

Após a compilação, o executável será gerado em `build/bin/` com o nome `ed1_prova2`.
