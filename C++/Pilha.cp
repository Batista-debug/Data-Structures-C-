#include <iostream>
#include <cstdlib>
#include <conio.h>
#define MAX 100

using namespace std;

typedef int Apontador;

typedef struct TipoItem{
	int Codigo;
	char Nome[10];
};

typedef struct TipoPilha{
	TipoItem Item [MAX];
	Apontador Topo;
};

void FazPilhaVazia(TipoPilha &Pilha){
	Pilha.Topo = -1;
}

int PilhaVazia(TipoPilha &Pilha){
	return (Pilha.Topo == -1);
}

void Empilhar (TipoItem X, TipoPilha &Pilha){
	if(Pilha.Topo == MAX){
		cout << "\n Pilha Esta Cheia ";
	}else{
		Pilha.Topo++;
		Pilha.Item [Pilha.Topo] = X;
	}
}

void Desempilhar(TipoPilha &Pilha, TipoItem &Item){
	system("CLS");
	if(PilhaVazia (Pilha))
	{
		cout << "\n Pilha esta vazia ";
		Item.Codigo = -1;
	}else{
		Item = Pilha.Item [Pilha.Topo];
		Pilha.Topo--;
	}
}

int TamanhoPilha(TipoPilha &Pilha){
	return (Pilha.Topo + 1);
}

int Menu(){
	int opc = 5;
	
	do{
		system("CLS");
		cout << "\n Escolha um Opcao " << endl;
		cout << "\n [1] - Empilhar " << endl;
		cout << "\n [2] - Desempilhar " << endl;
		cout << "\n [3] - Verificar Tamanho " << endl;
		cout << "\n [0] - Sair " << endl;
		cout << "\n Digite aqui a opcao: ";
		cin >> opc;
	}while((opc < 0) || (opc > 3));
	
	return (opc);
}

int main()
{
	TipoPilha Pilha;
	TipoItem Aux;
	int Opc;
	
	FazPilhaVazia (Pilha);
	
	Opc = Menu();
	while (Opc != 0){
		switch (Opc){
			case 1:
				system("CLS");
				cout << "\n Inserir Item " << endl;
				cout << "\n Digite um codigo " << endl;
				cin >> Aux.Codigo;
				Empilhar(Aux, Pilha);
				break;
			
			case 2:
				system("CLS");
				cout << "\n Excluir Item " << endl;
				Desempilhar(Pilha, Aux);
				
				if(Aux.Codigo > 0){
					cout << "\n O item a seguir foi removido da Pilha " << endl;
					cout << "\n Codigo " << Aux.Codigo;
					cout << "\n Nome " << Aux.Nome;
				}
				
				fflush(stdin);
				getchar();
				break;
			
			case 3:
				system("CLS");
				cout << "\n Pilha ";
				cout << "\n Quantidade de itens na Pilha " << TamanhoPilha (Pilha);
				fflush(stdin);
				getchar();
		}
		Opc = Menu();
	}
	system("PAUSE");
	
}

