
//URI Online Judge | 1024

//Exercicio de criptografia 

//Solicitaram para que voc� construisse um programa simples de criptografia. Este programa deve possibilitar enviar mensagens codificadas sem que algu�m consiga l�-las. O processo � muito simples. S�o feitas tr�s passadas em todo o texto.
//Na primeira passada, somente caracteres que sejam letras min�sculas e mai�sculas devem ser deslocadas 3 posi��es para a direita, segundo a tabela ASCII: letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e assim sucessivamente. Na segunda passada, a linha dever� ser invertida. Na terceira e �ltima passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posi��o para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.
//Por exemplo, se a entrada for �Texto #3�, o primeiro processamento sobre esta entrada dever� produzir �Wh{wr #3�. O resultado do segundo processamento inverte os caracteres e produz �3# rw{hW�. Por �ltimo, com o deslocamento dos caracteres da metade em diante, o resultado final deve ser �3# rvzgV�.

//Entrada

//A entrada cont�m v�rios casos de teste. A primeira linha de cada caso de teste cont�m um inteiro N (1 = N = 1*104), indicando a quantidade de linhas que o problema deve tratar. As N linhas cont�m cada uma delas M (1 = M = 1*103) caracteres.


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void LimpaBuffer()

{ while(getchar()!='\n');
return;
}

int main (void){
	
	char in[1003], cpy[1001];
	int n, p, c, t;
	scanf("%d", &n);
	LimpaBuffer();
	while(n>0){
		fgets(in,1003,stdin);
		for( c=0; in[c] >= ' '; c++ );
		in[c]= '\0';
		t = strlen(in);
	
		for(c=0;c<t;c++)
			if((in[c] >= 97 && in[c] <= 122) || (in[c] >= 65 && in[c] <= 90)){
				p = in[c];
				in[c] = p+3;
			}
				
		for(c=0;c<t;c++)
			cpy[c] = in[t-1-c];				
		cpy[t] = '\0';
			
		for(c=t/2;c<t;c++){
			p = cpy[c];
			cpy[c] = p-1;
		}		
		printf("%s\n", cpy);
			
		n--;
	}
	
	return 0;
}
