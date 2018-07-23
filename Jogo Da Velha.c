#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define TAM_MAX 3
#define JOG_PESSOA 2
#define JOGADAS_MAX 9

main(){
	setlocale(LC_ALL, "Portuguese");
	char x, resultado = 0;
	do{
		char velha[3][3] = {{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
		int i, j, aux, cont = 0;
		i = j = aux = 0;
		cont = 0;
		printf("		JOGO DA VELHA");
		printf("\n	  APERTA '1' PARA INICIAR");
		resultado = getch();
		switch(resultado){	
			case '1':
				printf("\nPlayer 1 - OS ÍCONES SÃO: 1- 'X' OU 2- 'O': ");
				printf("\nVocê escolheu 'X'");
				printf("\nPlayer 2 - VOCÊ É 'O'");
				printf("\nINSTRUÇÕES: Jogue conforme o pedido, linhas e colunas. Se tentar colocar uma letra \nsobre a outra o jogo vai ser restardado, então cuidado.");
				printf("\nAS LINHAS E COLUNAS SÃO DE 0 A 2, BOM JOGO!");
				printf("\nN/J: NÚMERO DE JOGADAS | C0/1/2: NÚMERO DA COLUNA | L0/1/2: NÚMERO DA LINHA");
				printf("\n   C0    C1    C2");
				setlocale(LC_ALL, "C");
				printf("\nL0   %c %c %c %c %c", velha[0][0], 179, velha[0][1], 179, velha[0][2]);
				printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
				printf("\nL1   %c %c %c %c %c", velha[1][0], 179, velha[1][1], 179, velha[1][2]);
				printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
				printf("\nL2   %c %c %c %c %c", velha[2][0], 179, velha[2][1], 179, velha[2][2]);
				setlocale(LC_ALL, "Portuguese");
				printf("\n\n");			
				while (cont < JOGADAS_MAX){
					if (cont % 2 == 0){
						printf("\nPlayer 1 - SUA VEZ!");
						if (cont > TAM_MAX-2){
							i = 0;
							j = 0;
							aux = 0;
							while(i < 3){
								if ((velha[i][0] == 'X') && (velha[i][1] == 'X') && (velha[i][2] == '\0')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,2);
								}
								else if ((velha[i][0] == 'X') && (velha[i][1] == '\0') && (velha[i][2] == 'X')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,1);
								}
								else if ((velha[i][0] == '\0') && (velha[i][1] == 'X') && (velha[i][2] == 'X')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,0);
								}
								else if ((velha[i][0] == 'O') && (velha[i][1] == 'O') && (velha[i][2] == '\0')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,2);
								}
								else if ((velha[i][0] == 'O') && (velha[i][1] == '\0') && (velha[i][2] == 'O')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,1);
								}
								else if ((velha[i][0] == '\0') && (velha[i][1] == 'O') && (velha[i][2] == 'O')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,0);
								}
							i++;
							}
							while(j < 3){
								if ((velha[0][j] == 'X') && (velha[1][j] == 'X') && (velha[2][j] == '\0')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,j);
								}
								else if ((velha[0][j] == 'X') && (velha[1][j] == '\0') && (velha[2][j] == 'X')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,j);
								}
								else if ((velha[0][j] == '\0') && (velha[1][j] == 'X') && (velha[2][j] == 'X')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,j);
								}
								else if ((velha[0][j] == 'O') && (velha[1][j] == 'O') && (velha[2][j] == '\0')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,j);
								}
								else if ((velha[0][j] == 'O') && (velha[1][j] == '\0') && (velha[2][j] == 'O')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,j);
								}
								else if ((velha[0][j] == '\0') && (velha[1][j] == 'O') && (velha[2][j] == 'O')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,j);
								}
							j++;
							}
							if ((velha[0][0] == 'X') && (velha[1][1] == 'X') && (velha[2][2] == '\0')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,2);
							}
							else if ((velha[0][0] == 'X') && (velha[1][1] == '\0') && (velha[2][2] == 'X')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][0] == '\0') && (velha[1][1] == 'X') && (velha[2][2] == 'X')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,0);
							}
							else if ((velha[0][2] == 'X') && (velha[1][1] == 'X') && (velha[2][0] == '\0')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,0);
							}
							else if ((velha[0][2] == 'X') && (velha[1][1] == '\0') && (velha[2][0] == 'X')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][2] == '\0') && (velha[1][1] == 'X') && (velha[2][0] == 'X')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,2);
							}
							else if ((velha[0][0] == 'O') && (velha[1][1] == 'O') && (velha[2][2] == '\0')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,2);
							}
							else if ((velha[0][0] == 'O') && (velha[1][1] == '\0') && (velha[2][2] == 'O')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][0] == '\0') && (velha[1][1] == 'O') && (velha[2][2] == 'O')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,0);
							}
							else if ((velha[0][2] == 'O') && (velha[1][1] == 'O') && (velha[2][0] == '\0')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,0);
							}
							else if ((velha[0][2] == 'O') && (velha[1][1] == '\0') && (velha[2][0] == 'O')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][2] == '\0') && (velha[1][1] == 'O') && (velha[2][0] == 'O')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,2);
							}
						}
						printf("\nN/J: [ %i ] - Digite a LINHA da JOGADA: ", cont+1);
						scanf("%d", &i);
						printf("N/J: [ %i ] - Digite a COLUNA da JOGADA: ", cont+1);
						scanf("%d", &j);
						if (velha[i][j] == 'X'|| velha[i][j] == 'O'){
							printf("\nNão é possível completar sua jogada!\n");
							printf("\nPlayer 2 Venceu a PARTIDA!");
							break;
						}
						else if ((i >= TAM_MAX || j >= TAM_MAX)){
							printf("Linha/Coluna INVÁLIDA!");
							while((i >= TAM_MAX || j >= TAM_MAX)){
								printf("\nN/J: [ %i ] - Digite a LINHA da JOGADA: ", cont+1);
								scanf("%d", &i);
								printf("N/J: [ %i ] - Digite a COLUNA da JOGADA: ", cont+1);
								scanf("%d", &j);
							}
						}
						velha[i][j] = 'X';
						printf("\n   C0    C1    C2");
						setlocale(LC_ALL, "C");
						printf("\nL0   %c %c %c %c %c", velha[0][0], 179, velha[0][1], 179, velha[0][2]);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
						printf("\nL1   %c %c %c %c %c", velha[1][0], 179, velha[1][1], 179, velha[1][2]);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
						printf("\nL2   %c %c %c %c %c", velha[2][0], 179, velha[2][1], 179, velha[2][2]);
						setlocale(LC_ALL, "Portuguese");
						printf("\n\n");											
						if (cont > TAM_MAX-1){
							if (((velha[0][0]=='X') && (velha[0][1]=='X') && (velha[0][2]=='X')) || ((velha[1][0]=='X') && (velha[1][1]=='X') && (velha[1][2]=='X')) || ((velha[2][0]=='X') && (velha[2][1]=='X') && (velha[2][2]=='X')) || ((velha[0][0]=='X') && (velha[1][0]=='X') && (velha[2][0]=='X')) || ((velha[0][1]=='X') && (velha[1][1]=='X') && (velha[2][1]=='X')) || ((velha[0][2]=='X') && (velha[1][2]=='X') && (velha[2][2]=='X')) || ((velha[0][0]=='X') && (velha[1][1]=='X') && (velha[2][2]=='X')) || ((velha[0][2]=='X') && (velha[1][1]=='X') && (velha[2][0]=='X'))){
								system("cls");
								printf("Player 1 Venceu o JOGO!");
								getch();
								break;
							}
							else if (((velha[0][0]=='O') && (velha[0][1]=='O') && (velha[0][2]=='O')) || ((velha[1][0]=='O') && (velha[1][1]=='O') && (velha[1][2]=='O')) || ((velha[2][0]=='O') && (velha[2][1]=='O') && (velha[2][2]=='O')) || ((velha[0][0]=='O') && (velha[1][0]=='O') && (velha[2][0]=='O')) || ((velha[0][1]=='O') && (velha[1][1]=='O') && (velha[2][1]=='O')) || ((velha[0][2]=='O') && (velha[1][2]=='O') && (velha[2][2]=='O')) || ((velha[0][0]=='O') && (velha[1][1]=='O') && (velha[2][2]=='O')) || ((velha[0][2]=='O') && (velha[1][1]=='O') && (velha[2][0]=='O'))){
								system("cls");
								printf("Player 2 Venceu o JOGO!");
								getch();
								break;
							}
						}
					}
					else{
						printf("\nPlayer 2 - SUA VEZ!");
						if (cont > TAM_MAX-2){
							i = 0;
							j = 0;
							while(i < 3){
								if ((velha[i][0] == 'O') && (velha[i][1] == 'O') && (velha[i][2] == '\0')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,2);
								}
								else if ((velha[i][0] == 'O') && (velha[i][1] == '\0') && (velha[i][2] == 'O')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,1);
								}
								else if ((velha[i][0] == '\0') && (velha[i][1] == 'O') && (velha[i][2] == 'O')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,0);
								}
								else if ((velha[i][0] == 'X') && (velha[i][1] == 'X') && (velha[i][2] == '\0')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,2);
								}
								else if ((velha[i][0] == 'X') && (velha[i][1] == '\0') && (velha[i][2] == 'X')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,1);
								}
								else if ((velha[i][0] == '\0') && (velha[i][1] == 'X') && (velha[i][2] == 'X')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", i,0);
								}
							i++;
							}
							while(j < 3){
								if ((velha[0][j] == 'O') && (velha[1][j] == 'O') && (velha[2][j] == '\0')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,j);
								}
								else if ((velha[0][j] == 'O') && (velha[1][j] == '\0') && (velha[2][j] == 'O')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,j);
								}
								else if ((velha[0][j] == '\0') && (velha[1][j] == 'O') && (velha[2][j] == 'O')){
									printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,j);
								}
								else if ((velha[0][j] == 'X') && (velha[1][j] == 'X') && (velha[2][j] == '\0')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,j);
								}
								else if ((velha[0][j] == 'X') && (velha[1][j] == '\0') && (velha[2][j] == 'X')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,j);
								}
								else if ((velha[0][j] == '\0') && (velha[1][j] == 'X') && (velha[2][j] == 'X')){
									printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,j);
								}
							j++;
							}
							if ((velha[0][0] == 'O') && (velha[1][1] == 'O') && (velha[2][2] == '\0')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,2);
							}
							else if ((velha[0][0] == 'O') && (velha[1][1] == '\0') && (velha[2][2] == 'O')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][0] == '\0') && (velha[1][1] == 'O') && (velha[2][2] == 'O')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,0);
							}
							else if ((velha[0][2] == 'O') && (velha[1][1] == 'O') && (velha[2][0] == '\0')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,0);
							}
							else if ((velha[0][2] == 'O') && (velha[1][1] == '\0') && (velha[2][0] == 'O')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][2] == '\0') && (velha[1][1] == 'O') && (velha[2][0] == 'O')){
								printf("\nOFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,2);
							}
							else if ((velha[0][0] == 'X') && (velha[1][1] == 'X') && (velha[2][2] == '\0')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,2);
							}
							else if ((velha[0][0] == 'X') && (velha[1][1] == '\0') && (velha[2][2] == 'X')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][0] == '\0') && (velha[1][1] == 'X') && (velha[2][2] == 'X')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,0);
							}
							else if ((velha[0][2] == 'X') && (velha[1][1] == 'X') && (velha[2][0] == '\0')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 2,0);
							}
							else if ((velha[0][2] == 'X') && (velha[1][1] == '\0') && (velha[2][0] == 'X')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 1,1);
							}
							else if ((velha[0][2] == '\0') && (velha[1][1] == 'X') && (velha[2][0] == 'X')){
								printf("\nDEFENSIVA: FAÇA A JOGADA NA LINHA: %i E NA COLUNA: %i", 0,2);
							}
						}
						printf("\nN/J: [ %i ] - Digite a LINHA da JOGADA: ", cont+1);
						scanf("%d", &i);
						printf("N/J: [ %i ] - Digite a COLUNA da JOGADA: ", cont+1);
						scanf("%d", &j);
						if (velha[i][j] == 'X' || velha[i][j] == 'O'){
							printf("\nNão é possível completar sua jogada!\n");
							printf("\nPlayer 1 Venceu a PARTIDA!");
							break;
						}
						else if ((i >= TAM_MAX || j >= TAM_MAX)){
							printf("Linha/Coluna INVÁLIDA!");
							while((i >= TAM_MAX || j >= TAM_MAX)){
								printf("\nN/J: [ %i ] - Digite a LINHA da JOGADA: ", cont+1);
								scanf("%d", &i);
								printf("N/J: [ %i ] - Digite a COLUNA da JOGADA: ", cont+1);
								scanf("%d", &j);
							}
						}
						velha[i][j] = 'O';
						printf("\n   C0    C1    C2");
						setlocale(LC_ALL, "C");
						printf("\nL0   %c %c %c %c %c", velha[0][0], 179, velha[0][1], 179, velha[0][2]);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
						printf("\nL1   %c %c %c %c %c", velha[1][0], 179, velha[1][1], 179, velha[1][2]);
						printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
						printf("\nL2   %c %c %c %c %c", velha[2][0], 179, velha[2][1], 179, velha[2][2]);
						setlocale(LC_ALL, "Portuguese");
						printf("\n\n");				
						if (cont > TAM_MAX-1){
							if (((velha[0][0]=='X') && (velha[0][1]=='X') && (velha[0][2]=='X')) || ((velha[1][0]=='X') && (velha[1][1]=='X') && (velha[1][2]=='X')) || ((velha[2][0]=='X') && (velha[2][1]=='X') && (velha[2][2]=='X')) || ((velha[0][0]=='X') && (velha[1][0]=='X') && (velha[2][0]=='X')) || ((velha[0][1]=='X') && (velha[1][1]=='X') && (velha[2][1]=='X')) || ((velha[0][2]=='X') && (velha[1][2]=='X') && (velha[2][2]=='X')) || ((velha[0][0]=='X') && (velha[1][1]=='X') && (velha[2][2]=='X')) || ((velha[0][2]=='X') && (velha[1][1]=='X') && (velha[2][0]=='X'))){
								system("cls");
								printf("Player 1 Venceu o JOGO!");
								getch();
								break;
							}
							else if (((velha[0][0]=='O') && (velha[0][1]=='O') && (velha[0][2]=='O')) || ((velha[1][0]=='O') && (velha[1][1]=='O') && (velha[1][2]=='O')) || ((velha[2][0]=='O') && (velha[2][1]=='O') && (velha[2][2]=='O')) || ((velha[0][0]=='O') && (velha[1][0]=='O') && (velha[2][0]=='O')) || ((velha[0][1]=='O') && (velha[1][1]=='O') && (velha[2][1]=='O')) || ((velha[0][2]=='O') && (velha[1][2]=='O') && (velha[2][2]=='O')) || ((velha[0][0]=='O') && (velha[1][1]=='O') && (velha[2][2]=='O')) || ((velha[0][2]=='O') && (velha[1][1]=='O') && (velha[2][0]=='O'))){
								system("cls");
								printf("Player 2 Venceu o JOGO!");
								getch();
								break;
							}
						}
					}
				if (cont == 8){
					system("cls");
					printf("DEU VELHA!");
					getch();
					break;
				}
				cont++;
				}
		}
		printf("\nDeseja Jogar NOVAMENTE? (S/N): ");
		scanf("%s", &resultado);
		system("cls");
	}
	while((resultado=='S' || resultado=='s'));
	return 0;
}
