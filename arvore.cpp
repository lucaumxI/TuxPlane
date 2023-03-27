#include "arvore.h"

using std::cout, std::endl;

ABB::ABB(int voo, int prioridade):dir(NULL),esq(NULL),voo(voo),prioridade(prioridade){
}

ABB::~ABB(){
}

bool ABB::vazia(){
    return (this==NULL);
}

bool ABB::insere(int voo, int prioridade){
    ABBPtr atual;
    atual = this;
    while(1){
        if(atual->busca(voo)&&!atual->vazia()){
            return false;
        }
        else{
            if(this->voo==-1){
                this->voo=voo;
                this->prioridade=prioridade;
            }
            else if(atual->esq->vazia()&&atual->prioridade>=prioridade){
                ABBPtr aux;
                aux = new ABB(voo, prioridade);
                atual->esq=aux;
                return true;
            }
            else if(atual->dir->vazia()&&atual->prioridade<prioridade){
                ABBPtr aux;
                aux = new ABB(voo, prioridade);
                atual->dir=aux;
                return true;
            }
            else if(atual->prioridade>=prioridade){
                atual = atual->esq;
            }
            else {
                atual = atual->dir;
            }
        }
    }
    return true;
}


void ABB::MaiorPrioridade(ABBPtr &pai,ABBPtr &elemento){
    pai = NULL;
    elemento = this;
    while (elemento->dir!=NULL){
        pai = elemento;
        elemento = elemento->dir;
    }
}

bool ABB::remove(){
    ABBPtr pai;
    ABBPtr eliminado;
    this->MaiorPrioridade(pai,eliminado);
    if(eliminado == this && ((this->esq!=NULL)||(this->dir!=NULL))){
        ABBPtr aux=eliminado->esq;
        while(aux->dir!=NULL){
            pai = aux;
            aux=aux->dir;
        }
        ABBPtr aux2=new ABB(eliminado->voo,eliminado->prioridade);
        eliminado->voo=aux->voo;
        eliminado->prioridade=aux->prioridade;
        aux->voo=aux2->voo;
        aux->prioridade=aux2->prioridade;
        pai = eliminado;
        eliminado = eliminado->esq;
        
    }
    else if(eliminado == this && eliminado->dir==NULL && eliminado->esq==NULL){
        this->voo=-1;
        this->prioridade=-1;
        return true;
    }
    if((eliminado->dir == eliminado->esq)&& (eliminado->esq== NULL)){//0 filho;
        if(pai->dir==eliminado){
            delete eliminado;
            pai->dir=NULL;
            return true;
        }else{
            delete eliminado;
            pai->esq=NULL;
            return true;
        }
    }
    else{
        ABBPtr aux = eliminado->esq;
        if(pai->dir==eliminado){
            delete eliminado;
            pai->dir=aux;
            return true;
        }else{
            pai->esq=eliminado->esq;
            delete eliminado;
            
            return true;
        }
    }
    return false;
}
    
bool ABB::busca(int voo){
    if(this->vazia()){
        return false;
    }
    else{
        if(voo > this->voo){
            return this->dir->busca(voo);
        }
        else if(voo < this->voo){
            return this->esq->busca(voo);
        }
        else{
            return true;
        }
    }
}


void ABB::imprime(){
    if(this->dir != NULL){
        this->dir->imprime();
    }
    if(this->voo!=-1){
        cout<<"VOO: "<<this->voo;
        switch (this->prioridade){
            case 1:
                cout<<"     Ordem de cadastro"<<endl;
                break;
            case 2:
                cout<<"     PAN-PAN"<<endl;
                break;
            case 3:
                cout<<"     MAYDAY"<<endl;
                break;
            default:
                cout<<"     Prioridade militar level:"<<this->prioridade;
                break;}
    }else{
        cout << "                SEM VÔOS CADASTRADOS                  " << endl;
    }
    if (this->esq != NULL) {
        this->esq->imprime();
    }
}