#include <iostream>

using namespace std;

void menuInicial();


void limpaTela(){
	system("CLS");
}


void inciarTabuleiro(char tabuleiro[10][10], char mascara[10][10]){
	
	int lin, col;
	
	for(lin = 0; lin < 10; lin++){
		for(col = 0; col < 10; col++){
			tabuleiro[lin][lin] = 'A';
			mascara = [lin][col] = '*';
		}
	}
}

void exibirMapa(){
	int cont;
	for(cont = 0; cont < 10; cont++){
		if(cont == 0){
			cout << "   ";
		}
		cout << "| ";
	}
	
	cout << "\n ";
}

void exibirTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraGabarito){
	char blue[] = { }
}
