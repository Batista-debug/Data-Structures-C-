#include <iostream>
#include <stdlib.h>

//Sr Vinicius Batista Braz
//Email: viniciusbbf2020@gmail.com
using namespace std;

struct NO {
    int item;
    NO *esq;
    NO *dir;
};

class Tree {
  private: NO *raiz; 

  public: Arvore() { raiz = NULL; } 

  public: void inserir(int v) {
    NO *novo = new NO(); 
    novo->item = v; 
    novo->dir = NULL;
    novo->esq = NULL;
    if (raiz == NULL) raiz = novo;
    else  { 
      NO *atual = raiz;
      NO *anterior;
      while(true) {
        anterior = atual;
        if (v <= atual->item) {
          atual = atual->esq;
          if (atual == NULL) {
            anterior->esq = novo;
            return;
          } 
        }  
        else { 
           atual = atual->dir;
           if (atual == NULL) {
             anterior->dir = novo;
             return;
           }
        } 
      } 
    } 

  }

  public: NO *buscar(int chave) {
    if (raiz == NULL) return NULL;
    NO *atual = raiz;  
    while (atual->item != chave) { 
      if(chave < atual->item ) atual = atual->esq; 
      else atual = atual->dir; 
      if (atual == NULL) return NULL; 
    } 
    return atual; 
  }


  public: bool remover(int v) {
    if (raiz == NULL) return false; 
    NO *atual = raiz;
    NO *pai = raiz;
    bool filho_esq = true;
    while (atual->item != v) { 
      pai = atual;
      if(v < atual->item ) { 
        atual = atual->esq;
        filho_esq = true;
      }
      else { 
        atual = atual->dir; 
        filho_esq = false; 
      }
      if (atual == NULL) return false;
    } 

    

    if (atual->esq == NULL && atual->dir == NULL) {
      if (atual == raiz ) raiz = NULL; 
      else if (filho_esq) pai->esq = NULL; 
           else pai->dir = NULL; 
    }

    else if (atual->dir == NULL) {
       if (atual == raiz) raiz = atual->esq; 
       else if (filho_esq) pai->esq = atual->esq; 
            else pai->dir = atual->esq;
    }
    
    else if (atual->esq == NULL) {
       if (atual == raiz) raiz = atual->dir; 
       else if (filho_esq) pai->esq = atual->dir; 
            else pai->dir = atual->dir; 
    }

    else {
      NO *sucessor = no_sucessor(atual);
      if (atual == raiz) raiz = sucessor; 
      else if(filho_esq) pai->esq = sucessor; 
           else pai->dir = sucessor; 
      sucessor->esq = atual->esq; 
    }

    return true;
  }
  
  private: NO *no_sucessor(NO *apaga) { 
     NO *paidosucessor = apaga;
     NO *sucessor = apaga;
     NO *atual = apaga->dir; 

     while (atual != NULL) { 
       paidosucessor = sucessor;
       sucessor = atual;
       atual = atual->esq; 
     } 
     
     if (sucessor != apaga->dir) { 
       paidosucessor->esq = sucessor->dir;
       

       sucessor->dir = apaga->dir;
                                
     }
     return sucessor;
  }
  
  public: void caminhar() {
    cout << "\n\n Exibindo em ordem: ";
    inOrder(raiz);
    cout << "\n Exibindo em pos-ordem: ";
    posOrder(raiz);
    cout << "\n Exibindo em pre-ordem: ";
    preOrder(raiz);
    cout << "\n Altura da arvore: " << altura(raiz);
    cout << "\n Quantidade de folhas: " << folhas(raiz);
    cout << "\n Quantidade de Nos: " << contarNos(raiz);
    if (raiz != NULL) { 
       cout << "\n Valor minimo: " << min();
       cout << "\n Valor maximo: " << max() << endl;
    }
  }

  private: void inOrder(NO *atual) {
    if (atual != NULL) {
      inOrder(atual->esq);
      cout << atual->item << " ";
      inOrder(atual->dir);
    }
  }

  private: int altura(NO *atual) {
     if(atual == NULL || (atual->esq == NULL && atual->dir == NULL))
       return 0;
     else {
   	if (altura(atual->esq) > altura(atual->dir))
   	   return ( 1 + altura(atual->esq) );
   	else
	   return ( 1 + altura(atual->dir) );
     }
  }
  
  private: int folhas(NO *atual) {
    if(atual ==NULL) return 0;
    if(atual->esq == NULL && atual->dir == NULL) return 1;
    return folhas(atual->esq) + folhas(atual->dir);
  }
  
  private: int contarNos(NO *atual) {
   if(atual == NULL)  return 0;
   else return ( 1 + contarNos(atual->esq) + contarNos(atual->dir));
  }
  
  private: void posOrder(NO *atual) {
    if (atual != NULL) {
      posOrder(atual->esq);
      posOrder(atual->dir);
      cout << atual->item << " ";
    }
  }
  
  private: void preOrder(NO *atual) {
    if (atual != NULL) {
      cout << atual->item << " ";
      preOrder(atual->esq);
      preOrder(atual->dir);
    }
  }

  public: int min() {
    NO *atual = raiz;
    NO *anterior = NULL;
    while (atual != NULL) {
      anterior = atual;
      atual = atual->esq;
    }
    return anterior->item;
  }

  public: int max() {
    NO *atual = raiz;
    NO *anterior = NULL;
    while (atual != NULL) {
      anterior = atual;
      atual = atual->dir;
    }
    return anterior->item;
  }

};

int main() {
    Tree arv;
    int opcao, x;
    cout << ("\n Arvore Binaria de Busca");
    do {
        cout << "\n |*********************************|";
		cout << "\n |1: Inserir                       |";
		cout << "\n |2: Excluir                       |";
		cout << "\n |3: Pesquisar                     |";
		cout << "\n |4: Exibir                        |";
		cout << "\n |5: Sair do programa              |";
		cout << "\n |*********************************|";
		cout << "\n-> ";
		cin >> opcao;
		switch(opcao) {
	 		case 1: {
		       cout << "\n Informe o valor (int) -> ";
		       cin >> x;
		       arv.inserir(x);
		       break;
			}
			case 2: {
		       cout << "\n Informe o valor (int) -> ";
		       cin >> x;
		       if ( !arv.remover(x) )
                          cout << "\n Valor nao encontrado!"; 
		       break;
			}
			case 3: {
		       cout << "\n Informe o valor (int) -> ";
               cin >> x;
	      	   if( arv.buscar(x) != NULL )
		          cout << "\n Valor Encontrado";
		       else 
		          cout << "\n Valor nao encontrado!";
		       break;
			}	 
			case 4: {
		      arv.caminhar();
		      break; 
			}
        } 
    } while(opcao != 5);
}
