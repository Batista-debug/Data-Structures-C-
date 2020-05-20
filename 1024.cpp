
//URI Online Judge | 1024

//Exercicio de criptografia 

//Solicitaram para que você construisse um programa simples de criptografia. Este programa deve possibilitar enviar mensagens codificadas sem que alguém consiga lê-las. O processo é muito simples. São feitas três passadas em todo o texto.
//Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita, segundo a tabela ASCII: letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e assim sucessivamente. Na segunda passada, a linha deverá ser invertida. Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.
//Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá produzir “Wh{wr #3”. O resultado do segundo processamento inverte os caracteres e produz “3# rw{hW”. Por último, com o deslocamento dos caracteres da metade em diante, o resultado final deve ser “3# rvzgV”.

//Entrada

//A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 = N = 1*104), indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada uma delas M (1 = M = 1*103) caracteres.


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
