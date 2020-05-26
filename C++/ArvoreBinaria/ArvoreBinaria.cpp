#include <iostream>
#include <stdlib.h>


using namespace std;


struct NO {
    int item;
    NO *esq;
    NO *dir;
};

class Tree {
  private: NO *root; 

  public: Tree() { root = NULL; } 

  public: void inserir(int v) {
    NO *novo = new NO(); 
    novo->item = v;
    novo->dir = NULL;
    novo->esq = NULL;
    if (root == NULL) root = novo;
    else  { 
      NO *atual = root;
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
    if (root == NULL) return NULL; 
    NO *atual = root;  
    while (atual->item != chave) { 
      if(chave < atual->item ) atual = atual->esq; 
      else atual = atual->dir; 
      if (atual == NULL) return NULL; 
    } 
    return atual; 
  }


  public: bool remover(int v) {
    if (root == NULL) return false; 
    NO *atual = root;
    NO *pai = root;
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
      if (atual == root ) root = NULL; 
      else if (filho_esq) pai->esq = NULL; 
           else pai->dir = NULL; 
    }

    else if (atual->dir == NULL) {
       if (atual == root) root = atual->esq; 
       else if (filho_esq) pai->esq = atual->esq; 
            else pai->dir = atual->esq; 
    }
    
    else if (atual->esq == NULL) {
       if (atual == root) root = atual->dir; 
       else if (filho_esq) pai->esq = atual->dir; 
            else pai->dir = atual->dir;
    }

    else {
      NO *sucessor = no_sucessor(atual);
      if (atual == root) root = sucessor; 
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
    inOrder(root);
    cout << "\n Exibindo em pos-ordem: ";
    posOrder(root);
    cout << "\n Exibindo em pre-ordem: ";
    preOrder(root);
    cout << "\n Altura da arvore: " << altura(root);
    cout << "\n Quantidade de folhas: " << folhas(root);
    cout << "\n Quantidade de Nos: " << contarNos(root);
    if (root != NULL ) {  // se arvore nao esta vazia
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
    if(atual == NULL) return 0;
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
    NO *atual = root;
    NO *anterior = NULL;
    while (atual != NULL) {
      anterior = atual;
      atual = atual->esq;
    }
    return anterior->item;
  }

  public: int max() {
    NO *atual = root;
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
    do {
        cout << "\n Entre com a opcao:";
		cout << "\n [1]: Inserir";
		cout << "\n [2]: Excluir";
		cout << "\n [3]: Pesquisar";
		cout << "\n [4]: Exibir";
		cout << "\n [5]: Sair do programa";
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
        } // fim switch
    } while(opcao != 5);
}
