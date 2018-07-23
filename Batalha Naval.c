#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define NM_TABU 10

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu(){
	setlocale(LC_ALL, "Portuguese");
	printf("\n										|       MENU");
	printf("\n										|    TENTATIVAS: ");
	printf("\n										|     Jogador 1");
	printf("\n										| BARCOS DESTRUIDOS");
	printf("\n										| - PORTA AVIÕES: [   ]");
	printf("\n										| - NAVIO DE GUERRA: [   ]");
	printf("\n										| - CRUZADOR: [   ]");
	printf("\n										| - SUBMARINO: [   ]");
	printf("\n										| - NAVIO O DESTRUIDOR: [   ]");
	printf("\n										|    ACERTOS: [   ]");
}

int sorteia_valor(int *valor){
	srand(time(NULL));
	*valor = 1+(rand()%1000);
}

main(){
	char porta_avioes[5] = {'@','@','@','@','@'};
	char navio_guerra[4] = {'#','#','#','#'};
	char cruzador[3] = {'$','$','$'};
	char submarino[3] = {'!','!','!'};
	char o_destruidor[2] = {'<','<'};
	char tabuleiro_jogador[10][10];
	char tabuleiro_computador[10][10];
	char opcao, posicao = 0;
	do{
	int linha, coluna, cont, aux, tentativa_jogador, tentativa_computer, computadorl, computadorc, acertos_jogador, acertos_computador = 0;
	linha = coluna = cont =  aux = tentativa_jogador = tentativa_computer = computadorl = computadorc = acertos_jogador = acertos_computador = 0;
	int porta, navio, cruzador1, submarino1, destruidor, randon = 0;
	porta = navio = cruzador1 = submarino1 = destruidor = randon = 0;
	for (linha = 0; linha < NM_TABU; linha++){
		for (coluna = 0; coluna < NM_TABU; coluna++){
			tabuleiro_jogador[linha][coluna] = '\0';
			tabuleiro_computador[linha][coluna] = '\0';
		}
	}
	computadorl = computadorc = 0;
	computadorl = 1+(rand()%7);
	computadorc = 1+(rand()%7);
	randon = 0;
	randon += computadorl;
	for (cont = 0; cont < 5; cont++){
		if (tabuleiro_computador[randon][computadorc] != '\0'){
			computadorl = 2;
			computadorc = 8;
		}
		randon++;
	}
	for (aux = 0; aux < 5; aux++){
		if (computadorl == 9){
			computadorl = 4;
			tabuleiro_computador[computadorl][computadorc] = porta_avioes[aux];
			computadorl++;
		}
		else{
			tabuleiro_computador[computadorl][computadorc] = porta_avioes[aux];
			computadorl++;
		}
	}
	computadorl = computadorc = 0;
	computadorl = 1+(rand()%7);
	computadorc = 1+(rand()%7);
	randon = 0;
	randon += computadorc;
	for (cont = 0; cont < 4; cont++){
		if (tabuleiro_computador[computadorl][randon] != '\0'){
			computadorl = 0;
			computadorc = 2;
		}
		randon++;
	}
	for (aux = 0; aux < 4; aux++){
		if (computadorc == 9){
			computadorc = 5;
			tabuleiro_computador[computadorl][computadorc] = navio_guerra[aux];
			computadorc++;
		}
		else{
			tabuleiro_computador[computadorl][computadorc] = navio_guerra[aux];
			computadorc++;
		}
	}
	computadorl = computadorc = 0;
	computadorl = 1+(rand()%5);
	computadorc = 1+(rand()%5);
	randon = 0;
	randon += computadorc;
	for (cont = 0; cont < 3; cont++){
		if (tabuleiro_computador[computadorl][randon] != '\0'){
			computadorl = 1;
			computadorc = 1;
		}
		randon++;
	}
	for (aux = 0; aux < 3; aux++){
		if (computadorc > 9){
			computadorc = 9;
			tabuleiro_computador[computadorl][computadorc] = cruzador[aux];
			computadorc++;
		}
		else{
			tabuleiro_computador[computadorl][computadorc] = cruzador[aux];
			computadorc++;
		}
	}
	computadorl = computadorc = 0;
	computadorl = 1+(rand()%7);
	computadorc = 1+(rand()%7);
	randon = 0;
	randon += computadorl;
	for (cont = 0; cont < 2; cont++){
		if (tabuleiro_computador[randon][computadorc] != '\0'){
			computadorl = 7;
			computadorc = 4;
		}
		randon++;
	}
	for (aux = 0; aux < 2; aux++){
		if (computadorl > 9){
			computadorl = 7;
			tabuleiro_computador[computadorl][computadorc] = o_destruidor[aux];
			computadorl++;
		}
		else{
			tabuleiro_computador[computadorl][computadorc] = o_destruidor[aux];
			computadorl++;
		}
	}
	computadorl = computadorc = 0;
	computadorl = 1+(rand()%7);
	computadorc = 1+(rand()%7);
	randon = 0;
	randon += computadorc;
	for (cont = 0; cont < 3; cont++){
		if (tabuleiro_computador[computadorl][randon] != '\0'){
			computadorl = computadorc = 0;
			computadorl = 9;
			computadorc = 7;
		}
		randon++;
	}
	for (aux = 0; aux < 3; aux++){
		if (computadorc > 9){
			computadorc = 3;
			tabuleiro_computador[computadorl][computadorc] = submarino[aux];
			computadorc++;
		}
		else{
			tabuleiro_computador[computadorl][computadorc] = submarino[aux];
			computadorc++;
		}
	}
	setlocale(LC_ALL, "Portuguese");
	printf("	       BATALHA NAVAL");
	printf("\n	  APERTA '1' PARA INICIAR");
	opcao = getch();
	switch(opcao){
		case '1':
			printf("\nJogador 1 É A SUA VEZ!");
			printf("\nPosicione os BARCOS AONDE VOCÊ QUEIRA");
			printf("\nO primeiro barco é: Porta Avioes - 5 QUADRADOS\n\n");
			setlocale(LC_ALL, "C");
			printf("       C0    C1   C2    C3    C4    C5    C6    C7    C8     C9");
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
			printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[0][0], 179, tabuleiro_jogador[0][1], 179, tabuleiro_jogador[0][2], 179, tabuleiro_jogador[0][3], 179, tabuleiro_jogador[0][4], 179, tabuleiro_jogador[0][5], 179, tabuleiro_jogador[0][6], 179, tabuleiro_jogador[0][7], 179, tabuleiro_jogador[0][8], 179, tabuleiro_jogador[0][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[1][0], 179, tabuleiro_jogador[1][1], 179, tabuleiro_jogador[1][2], 179, tabuleiro_jogador[1][3], 179, tabuleiro_jogador[1][4], 179, tabuleiro_jogador[1][5], 179, tabuleiro_jogador[1][6], 179, tabuleiro_jogador[1][7], 179, tabuleiro_jogador[1][8], 179, tabuleiro_jogador[1][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[2][0], 179, tabuleiro_jogador[2][1], 179, tabuleiro_jogador[2][2], 179, tabuleiro_jogador[2][3], 179, tabuleiro_jogador[2][4], 179, tabuleiro_jogador[2][5], 179, tabuleiro_jogador[2][6], 179, tabuleiro_jogador[2][7], 179, tabuleiro_jogador[2][8], 179, tabuleiro_jogador[2][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[3][0], 179, tabuleiro_jogador[3][1], 179, tabuleiro_jogador[3][2], 179, tabuleiro_jogador[3][3], 179, tabuleiro_jogador[3][4], 179, tabuleiro_jogador[3][5], 179, tabuleiro_jogador[3][6], 179, tabuleiro_jogador[3][7], 179, tabuleiro_jogador[3][8], 179, tabuleiro_jogador[3][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[4][0], 179, tabuleiro_jogador[4][1], 179, tabuleiro_jogador[4][2], 179, tabuleiro_jogador[4][3], 179, tabuleiro_jogador[4][4], 179, tabuleiro_jogador[4][5], 179, tabuleiro_jogador[4][6], 179, tabuleiro_jogador[4][7], 179, tabuleiro_jogador[4][8], 179, tabuleiro_jogador[4][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[5][0], 179, tabuleiro_jogador[5][1], 179, tabuleiro_jogador[5][2], 179, tabuleiro_jogador[5][3], 179, tabuleiro_jogador[5][4], 179, tabuleiro_jogador[5][5], 179, tabuleiro_jogador[5][6], 179, tabuleiro_jogador[5][7], 179, tabuleiro_jogador[5][8], 179, tabuleiro_jogador[5][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[6][0], 179, tabuleiro_jogador[6][1], 179, tabuleiro_jogador[6][2], 179, tabuleiro_jogador[6][3], 179, tabuleiro_jogador[6][4], 179, tabuleiro_jogador[6][5], 179, tabuleiro_jogador[6][6], 179, tabuleiro_jogador[6][7], 179, tabuleiro_jogador[6][8], 179, tabuleiro_jogador[6][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[7][0], 179, tabuleiro_jogador[7][1], 179, tabuleiro_jogador[7][2], 179, tabuleiro_jogador[7][3], 179, tabuleiro_jogador[7][4], 179, tabuleiro_jogador[7][5], 179, tabuleiro_jogador[7][6], 179, tabuleiro_jogador[7][7], 179, tabuleiro_jogador[7][8], 179, tabuleiro_jogador[7][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[8][0], 179, tabuleiro_jogador[8][1], 179, tabuleiro_jogador[8][2], 179, tabuleiro_jogador[8][3], 179, tabuleiro_jogador[8][4], 179, tabuleiro_jogador[8][5], 179, tabuleiro_jogador[8][6], 179, tabuleiro_jogador[8][7], 179, tabuleiro_jogador[8][8], 179, tabuleiro_jogador[8][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[9][0], 179, tabuleiro_jogador[9][1], 179, tabuleiro_jogador[9][2], 179, tabuleiro_jogador[9][3], 179, tabuleiro_jogador[9][4], 179, tabuleiro_jogador[9][5], 179, tabuleiro_jogador[9][6], 179, tabuleiro_jogador[9][7], 179, tabuleiro_jogador[9][8], 179, tabuleiro_jogador[9][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
			setlocale(LC_ALL, "Portuguese");
			printf("\nDigite A LINHA: ");
			scanf("%d", &linha);
			printf("Digite A COLUNA: ");
			scanf("%d", &coluna);
			printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
			scanf("%s", &posicao);
			if ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
				while ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
					printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
					scanf("%s", &posicao);
				}
			}
			else if (tabuleiro_jogador[linha][coluna] != '\0'){
				while (tabuleiro_jogador[linha][coluna] != '\0'){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
					printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
					scanf("%s", &posicao);
				}
			}
			else if (posicao == 'H' || posicao == 'h'){
				for (aux = 0; aux < 5; aux++){
					if (coluna == 9){
						coluna = 4;
						tabuleiro_jogador[linha][coluna] = porta_avioes[aux];
						coluna++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = porta_avioes[aux];
						coluna++;
					}
				}
			}
			else if (posicao == 'V' || posicao == 'v'){
				for (aux = 0; aux < 5; aux++){
					if (linha == 9){
						linha = 4;
						tabuleiro_jogador[linha][coluna] = porta_avioes[aux];
						linha++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = porta_avioes[aux];
						linha++;
					}
				}
			}
			getch();
			system("cls");
			printf("\nO segundo barco é: Navio de Guerra - 4 QUADRADOS\n\n");
			setlocale(LC_ALL, "C");
			printf("       C0    C1   C2    C3    C4    C5    C6    C7    C8     C9");
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
			printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[0][0], 179, tabuleiro_jogador[0][1], 179, tabuleiro_jogador[0][2], 179, tabuleiro_jogador[0][3], 179, tabuleiro_jogador[0][4], 179, tabuleiro_jogador[0][5], 179, tabuleiro_jogador[0][6], 179, tabuleiro_jogador[0][7], 179, tabuleiro_jogador[0][8], 179, tabuleiro_jogador[0][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[1][0], 179, tabuleiro_jogador[1][1], 179, tabuleiro_jogador[1][2], 179, tabuleiro_jogador[1][3], 179, tabuleiro_jogador[1][4], 179, tabuleiro_jogador[1][5], 179, tabuleiro_jogador[1][6], 179, tabuleiro_jogador[1][7], 179, tabuleiro_jogador[1][8], 179, tabuleiro_jogador[1][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[2][0], 179, tabuleiro_jogador[2][1], 179, tabuleiro_jogador[2][2], 179, tabuleiro_jogador[2][3], 179, tabuleiro_jogador[2][4], 179, tabuleiro_jogador[2][5], 179, tabuleiro_jogador[2][6], 179, tabuleiro_jogador[2][7], 179, tabuleiro_jogador[2][8], 179, tabuleiro_jogador[2][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[3][0], 179, tabuleiro_jogador[3][1], 179, tabuleiro_jogador[3][2], 179, tabuleiro_jogador[3][3], 179, tabuleiro_jogador[3][4], 179, tabuleiro_jogador[3][5], 179, tabuleiro_jogador[3][6], 179, tabuleiro_jogador[3][7], 179, tabuleiro_jogador[3][8], 179, tabuleiro_jogador[3][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[4][0], 179, tabuleiro_jogador[4][1], 179, tabuleiro_jogador[4][2], 179, tabuleiro_jogador[4][3], 179, tabuleiro_jogador[4][4], 179, tabuleiro_jogador[4][5], 179, tabuleiro_jogador[4][6], 179, tabuleiro_jogador[4][7], 179, tabuleiro_jogador[4][8], 179, tabuleiro_jogador[4][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[5][0], 179, tabuleiro_jogador[5][1], 179, tabuleiro_jogador[5][2], 179, tabuleiro_jogador[5][3], 179, tabuleiro_jogador[5][4], 179, tabuleiro_jogador[5][5], 179, tabuleiro_jogador[5][6], 179, tabuleiro_jogador[5][7], 179, tabuleiro_jogador[5][8], 179, tabuleiro_jogador[5][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[6][0], 179, tabuleiro_jogador[6][1], 179, tabuleiro_jogador[6][2], 179, tabuleiro_jogador[6][3], 179, tabuleiro_jogador[6][4], 179, tabuleiro_jogador[6][5], 179, tabuleiro_jogador[6][6], 179, tabuleiro_jogador[6][7], 179, tabuleiro_jogador[6][8], 179, tabuleiro_jogador[6][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[7][0], 179, tabuleiro_jogador[7][1], 179, tabuleiro_jogador[7][2], 179, tabuleiro_jogador[7][3], 179, tabuleiro_jogador[7][4], 179, tabuleiro_jogador[7][5], 179, tabuleiro_jogador[7][6], 179, tabuleiro_jogador[7][7], 179, tabuleiro_jogador[7][8], 179, tabuleiro_jogador[7][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[8][0], 179, tabuleiro_jogador[8][1], 179, tabuleiro_jogador[8][2], 179, tabuleiro_jogador[8][3], 179, tabuleiro_jogador[8][4], 179, tabuleiro_jogador[8][5], 179, tabuleiro_jogador[8][6], 179, tabuleiro_jogador[8][7], 179, tabuleiro_jogador[8][8], 179, tabuleiro_jogador[8][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[9][0], 179, tabuleiro_jogador[9][1], 179, tabuleiro_jogador[9][2], 179, tabuleiro_jogador[9][3], 179, tabuleiro_jogador[9][4], 179, tabuleiro_jogador[9][5], 179, tabuleiro_jogador[9][6], 179, tabuleiro_jogador[9][7], 179, tabuleiro_jogador[9][8], 179, tabuleiro_jogador[9][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
			setlocale(LC_ALL, "Portuguese");
			printf("\nDigite A LINHA: ");
			scanf("%d", &linha);
			printf("Digite A COLUNA: ");
			scanf("%d", &coluna);
			printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
			scanf("%s", &posicao);
			if ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
				while ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
					printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
					scanf("%s", &posicao);
				}
			}
			else if (tabuleiro_jogador[linha][coluna] != '\0'){
				while (tabuleiro_jogador[linha][coluna] != '\0'){
					linha = coluna = 0;
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			if (posicao == 'H' || posicao == 'h'){
				for (aux = 0; aux < 4; aux++){
					if (coluna == 9){
						coluna = 5;
						tabuleiro_jogador[linha][coluna] = navio_guerra[aux];
						coluna++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = navio_guerra[aux];
						coluna++;
					}
				}
			}
			else if (posicao == 'V' || posicao == 'v'){
				for (aux = 0; aux < 4; aux++){
					if(linha == 9){
						linha = 5;
						tabuleiro_jogador[linha][coluna] = navio_guerra[aux];
						linha++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = navio_guerra[aux];
						linha++;
					}
				}
			}
			getch();
			system("cls");
			printf("\nO terceiro barco é: Cruzador - 3 QUADRADOS\n\n");
			setlocale(LC_ALL, "C");
			printf("       C0    C1   C2    C3    C4    C5    C6    C7    C8     C9");
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
			printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[0][0], 179, tabuleiro_jogador[0][1], 179, tabuleiro_jogador[0][2], 179, tabuleiro_jogador[0][3], 179, tabuleiro_jogador[0][4], 179, tabuleiro_jogador[0][5], 179, tabuleiro_jogador[0][6], 179, tabuleiro_jogador[0][7], 179, tabuleiro_jogador[0][8], 179, tabuleiro_jogador[0][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[1][0], 179, tabuleiro_jogador[1][1], 179, tabuleiro_jogador[1][2], 179, tabuleiro_jogador[1][3], 179, tabuleiro_jogador[1][4], 179, tabuleiro_jogador[1][5], 179, tabuleiro_jogador[1][6], 179, tabuleiro_jogador[1][7], 179, tabuleiro_jogador[1][8], 179, tabuleiro_jogador[1][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[2][0], 179, tabuleiro_jogador[2][1], 179, tabuleiro_jogador[2][2], 179, tabuleiro_jogador[2][3], 179, tabuleiro_jogador[2][4], 179, tabuleiro_jogador[2][5], 179, tabuleiro_jogador[2][6], 179, tabuleiro_jogador[2][7], 179, tabuleiro_jogador[2][8], 179, tabuleiro_jogador[2][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[3][0], 179, tabuleiro_jogador[3][1], 179, tabuleiro_jogador[3][2], 179, tabuleiro_jogador[3][3], 179, tabuleiro_jogador[3][4], 179, tabuleiro_jogador[3][5], 179, tabuleiro_jogador[3][6], 179, tabuleiro_jogador[3][7], 179, tabuleiro_jogador[3][8], 179, tabuleiro_jogador[3][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[4][0], 179, tabuleiro_jogador[4][1], 179, tabuleiro_jogador[4][2], 179, tabuleiro_jogador[4][3], 179, tabuleiro_jogador[4][4], 179, tabuleiro_jogador[4][5], 179, tabuleiro_jogador[4][6], 179, tabuleiro_jogador[4][7], 179, tabuleiro_jogador[4][8], 179, tabuleiro_jogador[4][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[5][0], 179, tabuleiro_jogador[5][1], 179, tabuleiro_jogador[5][2], 179, tabuleiro_jogador[5][3], 179, tabuleiro_jogador[5][4], 179, tabuleiro_jogador[5][5], 179, tabuleiro_jogador[5][6], 179, tabuleiro_jogador[5][7], 179, tabuleiro_jogador[5][8], 179, tabuleiro_jogador[5][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[6][0], 179, tabuleiro_jogador[6][1], 179, tabuleiro_jogador[6][2], 179, tabuleiro_jogador[6][3], 179, tabuleiro_jogador[6][4], 179, tabuleiro_jogador[6][5], 179, tabuleiro_jogador[6][6], 179, tabuleiro_jogador[6][7], 179, tabuleiro_jogador[6][8], 179, tabuleiro_jogador[6][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[7][0], 179, tabuleiro_jogador[7][1], 179, tabuleiro_jogador[7][2], 179, tabuleiro_jogador[7][3], 179, tabuleiro_jogador[7][4], 179, tabuleiro_jogador[7][5], 179, tabuleiro_jogador[7][6], 179, tabuleiro_jogador[7][7], 179, tabuleiro_jogador[7][8], 179, tabuleiro_jogador[7][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[8][0], 179, tabuleiro_jogador[8][1], 179, tabuleiro_jogador[8][2], 179, tabuleiro_jogador[8][3], 179, tabuleiro_jogador[8][4], 179, tabuleiro_jogador[8][5], 179, tabuleiro_jogador[8][6], 179, tabuleiro_jogador[8][7], 179, tabuleiro_jogador[8][8], 179, tabuleiro_jogador[8][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[9][0], 179, tabuleiro_jogador[9][1], 179, tabuleiro_jogador[9][2], 179, tabuleiro_jogador[9][3], 179, tabuleiro_jogador[9][4], 179, tabuleiro_jogador[9][5], 179, tabuleiro_jogador[9][6], 179, tabuleiro_jogador[9][7], 179, tabuleiro_jogador[9][8], 179, tabuleiro_jogador[9][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
			setlocale(LC_ALL, "Portuguese");
			printf("\nDigite A LINHA: ");
			scanf("%d", &linha);
			printf("Digite A COLUNA: ");
			scanf("%d", &coluna);
			printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
			scanf("%s", &posicao);
			if ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
				while ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			else if (tabuleiro_jogador[linha][coluna] != '\0'){
				while (tabuleiro_jogador[linha][coluna] != '\0'){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			if (posicao == 'H' || posicao == 'h'){
				for (aux = 0; aux < 3; aux++){
					if (coluna == 9){
						coluna = 6;
						tabuleiro_jogador[linha][coluna] = cruzador[aux];
						coluna++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = cruzador[aux];
						coluna++;
					}
				}
			}
			else if (posicao == 'V' || posicao == 'v'){
				for (aux = 0; aux < 3; aux++){
					if (linha == 9){
						linha = 6;
						tabuleiro_jogador[linha][coluna] = cruzador[aux];
						linha++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = cruzador[aux];
						linha++;
					}
				}
			}
			getch();
			system("cls");
			printf("\nO terceiro barco é: Submarino - 3 QUADRADOS\n\n");
			setlocale(LC_ALL, "C");
			printf("       C0    C1   C2    C3    C4    C5    C6    C7    C8     C9");
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
			printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[0][0], 179, tabuleiro_jogador[0][1], 179, tabuleiro_jogador[0][2], 179, tabuleiro_jogador[0][3], 179, tabuleiro_jogador[0][4], 179, tabuleiro_jogador[0][5], 179, tabuleiro_jogador[0][6], 179, tabuleiro_jogador[0][7], 179, tabuleiro_jogador[0][8], 179, tabuleiro_jogador[0][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[1][0], 179, tabuleiro_jogador[1][1], 179, tabuleiro_jogador[1][2], 179, tabuleiro_jogador[1][3], 179, tabuleiro_jogador[1][4], 179, tabuleiro_jogador[1][5], 179, tabuleiro_jogador[1][6], 179, tabuleiro_jogador[1][7], 179, tabuleiro_jogador[1][8], 179, tabuleiro_jogador[1][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[2][0], 179, tabuleiro_jogador[2][1], 179, tabuleiro_jogador[2][2], 179, tabuleiro_jogador[2][3], 179, tabuleiro_jogador[2][4], 179, tabuleiro_jogador[2][5], 179, tabuleiro_jogador[2][6], 179, tabuleiro_jogador[2][7], 179, tabuleiro_jogador[2][8], 179, tabuleiro_jogador[2][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[3][0], 179, tabuleiro_jogador[3][1], 179, tabuleiro_jogador[3][2], 179, tabuleiro_jogador[3][3], 179, tabuleiro_jogador[3][4], 179, tabuleiro_jogador[3][5], 179, tabuleiro_jogador[3][6], 179, tabuleiro_jogador[3][7], 179, tabuleiro_jogador[3][8], 179, tabuleiro_jogador[3][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[4][0], 179, tabuleiro_jogador[4][1], 179, tabuleiro_jogador[4][2], 179, tabuleiro_jogador[4][3], 179, tabuleiro_jogador[4][4], 179, tabuleiro_jogador[4][5], 179, tabuleiro_jogador[4][6], 179, tabuleiro_jogador[4][7], 179, tabuleiro_jogador[4][8], 179, tabuleiro_jogador[4][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[5][0], 179, tabuleiro_jogador[5][1], 179, tabuleiro_jogador[5][2], 179, tabuleiro_jogador[5][3], 179, tabuleiro_jogador[5][4], 179, tabuleiro_jogador[5][5], 179, tabuleiro_jogador[5][6], 179, tabuleiro_jogador[5][7], 179, tabuleiro_jogador[5][8], 179, tabuleiro_jogador[5][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[6][0], 179, tabuleiro_jogador[6][1], 179, tabuleiro_jogador[6][2], 179, tabuleiro_jogador[6][3], 179, tabuleiro_jogador[6][4], 179, tabuleiro_jogador[6][5], 179, tabuleiro_jogador[6][6], 179, tabuleiro_jogador[6][7], 179, tabuleiro_jogador[6][8], 179, tabuleiro_jogador[6][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[7][0], 179, tabuleiro_jogador[7][1], 179, tabuleiro_jogador[7][2], 179, tabuleiro_jogador[7][3], 179, tabuleiro_jogador[7][4], 179, tabuleiro_jogador[7][5], 179, tabuleiro_jogador[7][6], 179, tabuleiro_jogador[7][7], 179, tabuleiro_jogador[7][8], 179, tabuleiro_jogador[7][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[8][0], 179, tabuleiro_jogador[8][1], 179, tabuleiro_jogador[8][2], 179, tabuleiro_jogador[8][3], 179, tabuleiro_jogador[8][4], 179, tabuleiro_jogador[8][5], 179, tabuleiro_jogador[8][6], 179, tabuleiro_jogador[8][7], 179, tabuleiro_jogador[8][8], 179, tabuleiro_jogador[8][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[9][0], 179, tabuleiro_jogador[9][1], 179, tabuleiro_jogador[9][2], 179, tabuleiro_jogador[9][3], 179, tabuleiro_jogador[9][4], 179, tabuleiro_jogador[9][5], 179, tabuleiro_jogador[9][6], 179, tabuleiro_jogador[9][7], 179, tabuleiro_jogador[9][8], 179, tabuleiro_jogador[9][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
			setlocale(LC_ALL, "Portuguese");
			printf("\nDigite A LINHA: ");
			scanf("%d", &linha);
			printf("Digite A COLUNA: ");
			scanf("%d", &coluna);
			printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
			scanf("%s", &posicao);
			if ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
				while ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			else if (tabuleiro_jogador[linha][coluna] != '\0'){
				while (tabuleiro_jogador[linha][coluna] != '\0'){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			if (posicao == 'H' || posicao == 'h'){
				for (aux = 0; aux < 3; aux++){
					if (coluna == 9){
						coluna = 6;
						tabuleiro_jogador[linha][coluna] = submarino[aux];
						coluna++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = submarino[aux];
						coluna++;
					}
				}
			}
			else if (posicao == 'V' || posicao == 'v'){
				for (aux = 0; aux < 3; aux++){
					if (linha == 9){
						linha = 6;
						tabuleiro_jogador[linha][coluna] = submarino[aux];
						linha++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = submarino[aux];
						linha++;
					}
				}
			}
			getch();
			system("cls");
			printf("\nO quarto barco é: O Destruidor - 2 QUADRADOS\n\n");
			setlocale(LC_ALL, "C");
			printf("       C0    C1   C2    C3    C4    C5    C6    C7    C8     C9");
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
			printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[0][0], 179, tabuleiro_jogador[0][1], 179, tabuleiro_jogador[0][2], 179, tabuleiro_jogador[0][3], 179, tabuleiro_jogador[0][4], 179, tabuleiro_jogador[0][5], 179, tabuleiro_jogador[0][6], 179, tabuleiro_jogador[0][7], 179, tabuleiro_jogador[0][8], 179, tabuleiro_jogador[0][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[1][0], 179, tabuleiro_jogador[1][1], 179, tabuleiro_jogador[1][2], 179, tabuleiro_jogador[1][3], 179, tabuleiro_jogador[1][4], 179, tabuleiro_jogador[1][5], 179, tabuleiro_jogador[1][6], 179, tabuleiro_jogador[1][7], 179, tabuleiro_jogador[1][8], 179, tabuleiro_jogador[1][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[2][0], 179, tabuleiro_jogador[2][1], 179, tabuleiro_jogador[2][2], 179, tabuleiro_jogador[2][3], 179, tabuleiro_jogador[2][4], 179, tabuleiro_jogador[2][5], 179, tabuleiro_jogador[2][6], 179, tabuleiro_jogador[2][7], 179, tabuleiro_jogador[2][8], 179, tabuleiro_jogador[2][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[3][0], 179, tabuleiro_jogador[3][1], 179, tabuleiro_jogador[3][2], 179, tabuleiro_jogador[3][3], 179, tabuleiro_jogador[3][4], 179, tabuleiro_jogador[3][5], 179, tabuleiro_jogador[3][6], 179, tabuleiro_jogador[3][7], 179, tabuleiro_jogador[3][8], 179, tabuleiro_jogador[3][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[4][0], 179, tabuleiro_jogador[4][1], 179, tabuleiro_jogador[4][2], 179, tabuleiro_jogador[4][3], 179, tabuleiro_jogador[4][4], 179, tabuleiro_jogador[4][5], 179, tabuleiro_jogador[4][6], 179, tabuleiro_jogador[4][7], 179, tabuleiro_jogador[4][8], 179, tabuleiro_jogador[4][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[5][0], 179, tabuleiro_jogador[5][1], 179, tabuleiro_jogador[5][2], 179, tabuleiro_jogador[5][3], 179, tabuleiro_jogador[5][4], 179, tabuleiro_jogador[5][5], 179, tabuleiro_jogador[5][6], 179, tabuleiro_jogador[5][7], 179, tabuleiro_jogador[5][8], 179, tabuleiro_jogador[5][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[6][0], 179, tabuleiro_jogador[6][1], 179, tabuleiro_jogador[6][2], 179, tabuleiro_jogador[6][3], 179, tabuleiro_jogador[6][4], 179, tabuleiro_jogador[6][5], 179, tabuleiro_jogador[6][6], 179, tabuleiro_jogador[6][7], 179, tabuleiro_jogador[6][8], 179, tabuleiro_jogador[6][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[7][0], 179, tabuleiro_jogador[7][1], 179, tabuleiro_jogador[7][2], 179, tabuleiro_jogador[7][3], 179, tabuleiro_jogador[7][4], 179, tabuleiro_jogador[7][5], 179, tabuleiro_jogador[7][6], 179, tabuleiro_jogador[7][7], 179, tabuleiro_jogador[7][8], 179, tabuleiro_jogador[7][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[8][0], 179, tabuleiro_jogador[8][1], 179, tabuleiro_jogador[8][2], 179, tabuleiro_jogador[8][3], 179, tabuleiro_jogador[8][4], 179, tabuleiro_jogador[8][5], 179, tabuleiro_jogador[8][6], 179, tabuleiro_jogador[8][7], 179, tabuleiro_jogador[8][8], 179, tabuleiro_jogador[8][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
			printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[9][0], 179, tabuleiro_jogador[9][1], 179, tabuleiro_jogador[9][2], 179, tabuleiro_jogador[9][3], 179, tabuleiro_jogador[9][4], 179, tabuleiro_jogador[9][5], 179, tabuleiro_jogador[9][6], 179, tabuleiro_jogador[9][7], 179, tabuleiro_jogador[9][8], 179, tabuleiro_jogador[9][9], 179);
			printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
			setlocale(LC_ALL, "Portuguese");
			printf("\nDigite A LINHA: ");
			scanf("%d", &linha);
			printf("Digite A COLUNA: ");
			scanf("%d", &coluna);
			printf("Digite A POSICAO DO NAVIO: (USE 'V' PARA VERTICAL E 'H' PARA HORIZONTAL) - ");
			scanf("%s", &posicao);
			if ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
				while ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			else if (tabuleiro_jogador[linha][coluna] != '\0'){
				while (tabuleiro_jogador[linha][coluna] != '\0'){
					printf("\nEscolha outro quadrante para jogada!");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
				}
			}
			if (posicao == 'H' || posicao == 'h'){
				for (aux = 0; aux < 2; aux++){
					if (coluna == 9){
						coluna = 7;
						tabuleiro_jogador[linha][coluna] = o_destruidor[aux];
						coluna++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = o_destruidor[aux];
						coluna++;
					}
				}
			}
			else if (posicao == 'V' || posicao == 'v'){
				for (aux = 0; aux < 2; aux++){
					if (coluna == 9){
						coluna = 7;
						tabuleiro_jogador[linha][coluna] = o_destruidor[aux];
						linha++;
					}
					else{
						tabuleiro_jogador[linha][coluna] = o_destruidor[aux];
						linha++;
					}
				}
			}		
			while(cont >= 0){
				if (cont % 2 == 0){
					system("cls");
					tentativa_jogador++;
					menu();
					gotoxy(97,2);
					printf("%d", tentativa_jogador);
					gotoxy(100,5);
					printf("%d", porta);
					gotoxy(103,6);
					printf("%d", navio);
					gotoxy(96,7);
					printf("%d", cruzador1);
					gotoxy(97,8);
					printf("%d", submarino1);
					gotoxy(106,9);
					printf("%d", destruidor);
					gotoxy(96,10);
					printf("%d", acertos_jogador);
					setlocale(LC_ALL, "Portuguese");
					printf("\nJogador 1 - DE UM TIRO, ESCOLHA UM QUADRANTE PARA ISSO: ");
					printf("\nDigite a LINHA: ");
					scanf("%d", &linha);
					printf("Digite a COLUNA: ");
					scanf("%d", &coluna);
					if (tabuleiro_computador[linha][coluna] == 'X'){
						while (tabuleiro_computador[linha][coluna] == 'X'){
							printf("\nEscolha outro quadrante para jogada!");
							printf("\nDigite a LINHA: ");
							scanf("%d", &linha);
							printf("Digite a COLUNA: ");
							scanf("%d", &coluna);
						}
					}
					else if ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
						while ((linha > 9 || coluna > 9 || linha < 0 || coluna < 0)){
							printf("\nEscolha outro quadrante para jogada!");
							printf("\nDigite a LINHA: ");
							scanf("%d", &linha);
							printf("Digite a COLUNA: ");
							scanf("%d", &coluna);
						}
					}
					else if (tabuleiro_computador[linha][coluna] == '@'){
						porta++;
					}
					else if (tabuleiro_computador[linha][coluna] == '#'){
						navio++;
					}
					else if (tabuleiro_computador[linha][coluna] == '$'){
						cruzador1++;
					}
					else if (tabuleiro_computador[linha][coluna] == '!'){
						submarino1++;
					}
					else if (tabuleiro_computador[linha][coluna] == '<'){
						destruidor++;
					}
					if (tabuleiro_computador[linha][coluna] != '\0'){
						acertos_jogador++;
					}
					tabuleiro_computador[linha][coluna] = ("%c", 178);
					//OPCAO VER TABULEIRO DO COMPUTADOR
					/*for (linha = 0; linha < NM_TABU; linha++){
						for (coluna = 0; coluna < NM_TABU; coluna++){
							printf("%c", tabuleiro_computador[linha][coluna]);
						}
					printf("\n");
					}*/
					if (acertos_jogador == 17){
						system("cls");
						setlocale(LC_ALL, "Portuguese");
						printf("\nJogador 1 VENCEU O GAME!");
						setlocale(LC_ALL, "C");
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
						printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[0][0], 179, tabuleiro_computador[0][1], 179, tabuleiro_computador[0][2], 179, tabuleiro_computador[0][3], 179, tabuleiro_computador[0][4], 179, tabuleiro_computador[0][5], 179, tabuleiro_computador[0][6], 179, tabuleiro_computador[0][7], 179, tabuleiro_computador[0][8], 179, tabuleiro_computador[0][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[1][0], 179, tabuleiro_computador[1][1], 179, tabuleiro_computador[1][2], 179, tabuleiro_computador[1][3], 179, tabuleiro_computador[1][4], 179, tabuleiro_computador[1][5], 179, tabuleiro_computador[1][6], 179, tabuleiro_computador[1][7], 179, tabuleiro_computador[1][8], 179, tabuleiro_computador[1][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[2][0], 179, tabuleiro_computador[2][1], 179, tabuleiro_computador[2][2], 179, tabuleiro_computador[2][3], 179, tabuleiro_computador[2][4], 179, tabuleiro_computador[2][5], 179, tabuleiro_computador[2][6], 179, tabuleiro_computador[2][7], 179, tabuleiro_computador[2][8], 179, tabuleiro_computador[2][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[3][0], 179, tabuleiro_computador[3][1], 179, tabuleiro_computador[3][2], 179, tabuleiro_computador[3][3], 179, tabuleiro_computador[3][4], 179, tabuleiro_computador[3][5], 179, tabuleiro_computador[3][6], 179, tabuleiro_computador[3][7], 179, tabuleiro_computador[3][8], 179, tabuleiro_computador[3][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[4][0], 179, tabuleiro_computador[4][1], 179, tabuleiro_computador[4][2], 179, tabuleiro_computador[4][3], 179, tabuleiro_computador[4][4], 179, tabuleiro_computador[4][5], 179, tabuleiro_computador[4][6], 179, tabuleiro_computador[4][7], 179, tabuleiro_computador[4][8], 179, tabuleiro_computador[4][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[5][0], 179, tabuleiro_computador[5][1], 179, tabuleiro_computador[5][2], 179, tabuleiro_computador[5][3], 179, tabuleiro_computador[5][4], 179, tabuleiro_computador[5][5], 179, tabuleiro_computador[5][6], 179, tabuleiro_computador[5][7], 179, tabuleiro_computador[5][8], 179, tabuleiro_computador[5][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[6][0], 179, tabuleiro_computador[6][1], 179, tabuleiro_computador[6][2], 179, tabuleiro_computador[6][3], 179, tabuleiro_computador[6][4], 179, tabuleiro_computador[6][5], 179, tabuleiro_computador[6][6], 179, tabuleiro_computador[6][7], 179, tabuleiro_computador[6][8], 179, tabuleiro_computador[6][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[7][0], 179, tabuleiro_computador[7][1], 179, tabuleiro_computador[7][2], 179, tabuleiro_computador[7][3], 179, tabuleiro_computador[7][4], 179, tabuleiro_computador[7][5], 179, tabuleiro_computador[7][6], 179, tabuleiro_computador[7][7], 179, tabuleiro_computador[7][8], 179, tabuleiro_computador[7][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[8][0], 179, tabuleiro_computador[8][1], 179, tabuleiro_computador[8][2], 179, tabuleiro_computador[8][3], 179, tabuleiro_computador[8][4], 179, tabuleiro_computador[8][5], 179, tabuleiro_computador[8][6], 179, tabuleiro_computador[8][7], 179, tabuleiro_computador[8][8], 179, tabuleiro_computador[8][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[9][0], 179, tabuleiro_computador[9][1], 179, tabuleiro_computador[9][2], 179, tabuleiro_computador[9][3], 179, tabuleiro_computador[9][4], 179, tabuleiro_computador[9][5], 179, tabuleiro_computador[9][6], 179, tabuleiro_computador[9][7], 179, tabuleiro_computador[9][8], 179, tabuleiro_computador[9][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
						getch();
						break;
					}
				}
				else{
					tentativa_computer++;
					linha = coluna = 0;
					linha = 1+(rand()%9);
					coluna = 1+(rand()%9);
					if (tabuleiro_jogador[linha][coluna] == 'X'){
						while (tabuleiro_jogador[linha][coluna] == 'X'){
							linha = coluna = 0;
							linha = 1+(rand()%9);
							coluna = 1+(rand()%9);
						}
					}
					setlocale(LC_ALL, "Portuguese");
					printf("\nComputador SUA VEZ!");
					printf("\nLINHA: %d", linha);
					printf("\nCOLUNA: %d\n", coluna);
					Sleep(1000);
					if (tabuleiro_jogador[linha][coluna] != '\0'){
						acertos_computador++;
					}
					tabuleiro_jogador[linha][coluna] = ("%c", 178);
					setlocale(LC_ALL, "C");
					printf("       C0    C1   C2    C3    C4    C5    C6    C7    C8     C9");
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
					printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[0][0], 179, tabuleiro_jogador[0][1], 179, tabuleiro_jogador[0][2], 179, tabuleiro_jogador[0][3], 179, tabuleiro_jogador[0][4], 179, tabuleiro_jogador[0][5], 179, tabuleiro_jogador[0][6], 179, tabuleiro_jogador[0][7], 179, tabuleiro_jogador[0][8], 179, tabuleiro_jogador[0][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[1][0], 179, tabuleiro_jogador[1][1], 179, tabuleiro_jogador[1][2], 179, tabuleiro_jogador[1][3], 179, tabuleiro_jogador[1][4], 179, tabuleiro_jogador[1][5], 179, tabuleiro_jogador[1][6], 179, tabuleiro_jogador[1][7], 179, tabuleiro_jogador[1][8], 179, tabuleiro_jogador[1][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[2][0], 179, tabuleiro_jogador[2][1], 179, tabuleiro_jogador[2][2], 179, tabuleiro_jogador[2][3], 179, tabuleiro_jogador[2][4], 179, tabuleiro_jogador[2][5], 179, tabuleiro_jogador[2][6], 179, tabuleiro_jogador[2][7], 179, tabuleiro_jogador[2][8], 179, tabuleiro_jogador[2][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[3][0], 179, tabuleiro_jogador[3][1], 179, tabuleiro_jogador[3][2], 179, tabuleiro_jogador[3][3], 179, tabuleiro_jogador[3][4], 179, tabuleiro_jogador[3][5], 179, tabuleiro_jogador[3][6], 179, tabuleiro_jogador[3][7], 179, tabuleiro_jogador[3][8], 179, tabuleiro_jogador[3][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[4][0], 179, tabuleiro_jogador[4][1], 179, tabuleiro_jogador[4][2], 179, tabuleiro_jogador[4][3], 179, tabuleiro_jogador[4][4], 179, tabuleiro_jogador[4][5], 179, tabuleiro_jogador[4][6], 179, tabuleiro_jogador[4][7], 179, tabuleiro_jogador[4][8], 179, tabuleiro_jogador[4][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[5][0], 179, tabuleiro_jogador[5][1], 179, tabuleiro_jogador[5][2], 179, tabuleiro_jogador[5][3], 179, tabuleiro_jogador[5][4], 179, tabuleiro_jogador[5][5], 179, tabuleiro_jogador[5][6], 179, tabuleiro_jogador[5][7], 179, tabuleiro_jogador[5][8], 179, tabuleiro_jogador[5][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[6][0], 179, tabuleiro_jogador[6][1], 179, tabuleiro_jogador[6][2], 179, tabuleiro_jogador[6][3], 179, tabuleiro_jogador[6][4], 179, tabuleiro_jogador[6][5], 179, tabuleiro_jogador[6][6], 179, tabuleiro_jogador[6][7], 179, tabuleiro_jogador[6][8], 179, tabuleiro_jogador[6][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[7][0], 179, tabuleiro_jogador[7][1], 179, tabuleiro_jogador[7][2], 179, tabuleiro_jogador[7][3], 179, tabuleiro_jogador[7][4], 179, tabuleiro_jogador[7][5], 179, tabuleiro_jogador[7][6], 179, tabuleiro_jogador[7][7], 179, tabuleiro_jogador[7][8], 179, tabuleiro_jogador[7][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[8][0], 179, tabuleiro_jogador[8][1], 179, tabuleiro_jogador[8][2], 179, tabuleiro_jogador[8][3], 179, tabuleiro_jogador[8][4], 179, tabuleiro_jogador[8][5], 179, tabuleiro_jogador[8][6], 179, tabuleiro_jogador[8][7], 179, tabuleiro_jogador[8][8], 179, tabuleiro_jogador[8][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
					printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_jogador[9][0], 179, tabuleiro_jogador[9][1], 179, tabuleiro_jogador[9][2], 179, tabuleiro_jogador[9][3], 179, tabuleiro_jogador[9][4], 179, tabuleiro_jogador[9][5], 179, tabuleiro_jogador[9][6], 179, tabuleiro_jogador[9][7], 179, tabuleiro_jogador[9][8], 179, tabuleiro_jogador[9][9], 179);
					printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
					getch();
					if (acertos_computador == 17){
						system("cls");
						setlocale(LC_ALL, "Portuguese");
						printf("\nCPU VENCEU O GAME!");
						setlocale(LC_ALL, "C");
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
						printf("\nL0 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[0][0], 179, tabuleiro_computador[0][1], 179, tabuleiro_computador[0][2], 179, tabuleiro_computador[0][3], 179, tabuleiro_computador[0][4], 179, tabuleiro_computador[0][5], 179, tabuleiro_computador[0][6], 179, tabuleiro_computador[0][7], 179, tabuleiro_computador[0][8], 179, tabuleiro_computador[0][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL1 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[1][0], 179, tabuleiro_computador[1][1], 179, tabuleiro_computador[1][2], 179, tabuleiro_computador[1][3], 179, tabuleiro_computador[1][4], 179, tabuleiro_computador[1][5], 179, tabuleiro_computador[1][6], 179, tabuleiro_computador[1][7], 179, tabuleiro_computador[1][8], 179, tabuleiro_computador[1][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL2 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[2][0], 179, tabuleiro_computador[2][1], 179, tabuleiro_computador[2][2], 179, tabuleiro_computador[2][3], 179, tabuleiro_computador[2][4], 179, tabuleiro_computador[2][5], 179, tabuleiro_computador[2][6], 179, tabuleiro_computador[2][7], 179, tabuleiro_computador[2][8], 179, tabuleiro_computador[2][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL3 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[3][0], 179, tabuleiro_computador[3][1], 179, tabuleiro_computador[3][2], 179, tabuleiro_computador[3][3], 179, tabuleiro_computador[3][4], 179, tabuleiro_computador[3][5], 179, tabuleiro_computador[3][6], 179, tabuleiro_computador[3][7], 179, tabuleiro_computador[3][8], 179, tabuleiro_computador[3][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL4 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[4][0], 179, tabuleiro_computador[4][1], 179, tabuleiro_computador[4][2], 179, tabuleiro_computador[4][3], 179, tabuleiro_computador[4][4], 179, tabuleiro_computador[4][5], 179, tabuleiro_computador[4][6], 179, tabuleiro_computador[4][7], 179, tabuleiro_computador[4][8], 179, tabuleiro_computador[4][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL5 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[5][0], 179, tabuleiro_computador[5][1], 179, tabuleiro_computador[5][2], 179, tabuleiro_computador[5][3], 179, tabuleiro_computador[5][4], 179, tabuleiro_computador[5][5], 179, tabuleiro_computador[5][6], 179, tabuleiro_computador[5][7], 179, tabuleiro_computador[5][8], 179, tabuleiro_computador[5][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL6 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[6][0], 179, tabuleiro_computador[6][1], 179, tabuleiro_computador[6][2], 179, tabuleiro_computador[6][3], 179, tabuleiro_computador[6][4], 179, tabuleiro_computador[6][5], 179, tabuleiro_computador[6][6], 179, tabuleiro_computador[6][7], 179, tabuleiro_computador[6][8], 179, tabuleiro_computador[6][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL7 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[7][0], 179, tabuleiro_computador[7][1], 179, tabuleiro_computador[7][2], 179, tabuleiro_computador[7][3], 179, tabuleiro_computador[7][4], 179, tabuleiro_computador[7][5], 179, tabuleiro_computador[7][6], 179, tabuleiro_computador[7][7], 179, tabuleiro_computador[7][8], 179, tabuleiro_computador[7][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL8 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[8][0], 179, tabuleiro_computador[8][1], 179, tabuleiro_computador[8][2], 179, tabuleiro_computador[8][3], 179, tabuleiro_computador[8][4], 179, tabuleiro_computador[8][5], 179, tabuleiro_computador[8][6], 179, tabuleiro_computador[8][7], 179, tabuleiro_computador[8][8], 179, tabuleiro_computador[8][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
						printf("\nL9 %c  %c   %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c   %c", 179, tabuleiro_computador[9][0], 179, tabuleiro_computador[9][1], 179, tabuleiro_computador[9][2], 179, tabuleiro_computador[9][3], 179, tabuleiro_computador[9][4], 179, tabuleiro_computador[9][5], 179, tabuleiro_computador[9][6], 179, tabuleiro_computador[9][7], 179, tabuleiro_computador[9][8], 179, tabuleiro_computador[9][9], 179);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
						getch();
						break;
					}
				}
			cont++;
			}
		}
	printf("\nDeseja jogar novamente? (S/N): ");
	scanf("%s", &opcao);
	}
	while(opcao=='S');
	return 0;
}
/* DESENHAR TABULEIRO
NÃO ESQUECER DE DESENHAR OS BARCOS
*/
