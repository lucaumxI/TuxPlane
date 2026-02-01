# TuxPlane - Gerenciador de Pousos Prioritários ✈️

Um sistema de gerenciamento de tráfego aéreo desenvolvido em C++ que utiliza uma **Árvore Binária de Busca (ABB)** para organizar filas de pouso baseadas em níveis de prioridade e emergência.

## 📋 Sobre o Projeto

O **TuxPlane** simula uma torre de controle. Diferente de uma fila comum (FIFO), onde o primeiro que chega é o primeiro que sai, este sistema utiliza uma estrutura de dados hierárquica para garantir que aviões em situação de emergência pousem antes de aviões em situação normal.

### Níveis de Prioridade
O sistema trabalha com 3 níveis de hierarquia:
1.  **Ordem de Cadastro:** Vôos comerciais/privados normais.
2.  **PAN-PAN:** Urgência sem risco de vida imediato (ex: falha mecânica leve).
3.  **MAYDAY:** Emergência grave com risco de vida (prioridade máxima).

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++
* **Estrutura de Dados:** Árvore Binária de Busca (BST) adaptada para Fila de Prioridade.
* **Bibliotecas:** `iostream`, `cstdlib`, `unistd.h`.

## ⚙️ Como Funciona a Lógica (Backend)

O projeto implementa uma classe `ABB` (Árvore Binária de Busca).
* **Inserção:** Ao cadastrar um vôo, a árvore o posiciona comparando a prioridade. Prioridades maiores vão para a direita da árvore.
* **Remoção (Pouso):** O algoritmo de remoção busca sempre o nó mais à direita da árvore (maior valor de prioridade), garantindo que emergências *Mayday* sejam atendidas antes de qualquer outro vôo.
* **Visualização:** A listagem percorre a árvore em ordem decrescente (Reverse In-Order Traversal) para exibir os casos críticos no topo da lista.

## 🚀 Como Compilar e Rodar

Como o arquivo `main.cpp` faz a inclusão direta da implementação (`#include "arvore.cpp"`), a compilação é simples.

### Pré-requisitos
* Compilador G++ (GCC) instalado.

### Passo a passo

1.  Clone este repositório ou baixe os arquivos (`main.cpp`, `arvore.cpp`, `arvore.h`).
2.  Abra o terminal na pasta dos arquivos.
3.  Compile o código:
    ```bash
    g++ main.cpp -o tuxplane
    ```
4.  Execute o programa:
    * **Linux/Mac:** `./tuxplane`
    * **Windows:** `tuxplane.exe`

## ⚠️ Observação sobre Compatibilidade

O código utiliza:
* `system("CLS")`: Comando específico do Windows para limpar a tela.
* `<unistd.h>` e `sleep()`: Comandos comuns em sistemas Unix/Linux.

*Se você estiver rodando no Linux e a tela não limpar, ou no Windows e tiver erro no sleep, pequenas adaptações no código fonte podem ser necessárias (ex: trocar "CLS" por "clear").*

---
*Projeto desenvolvido para a disciplina de Estrutura de Dados.*
