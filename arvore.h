#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>

typedef struct ABB* ABBPtr;

class ABB{
    private:
    ABBPtr dir;
    ABBPtr esq;
    int voo;
    int prioridade;

    public:
    ABB(int voo, int prioridade);
    ~ABB();
    bool insere(int voo, int prioridade);
    bool vazia();
    bool remove();
    bool busca(int voo);
    void imprime();
    void MaiorPrioridade(ABBPtr &pai, ABBPtr &elemento);
};

#endif