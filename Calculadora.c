#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <locale.h>
#include <windows.h>
#define PI 3.1415926
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu(){
	setlocale(LC_ALL, "Portuguese");
	printf("\n			          |- ESCOLHA A OPERAÇÃO DESEJADA -|");
	setlocale(LC_ALL, "C");
	printf("\n			%c%c%c                                               %c%c%c", 218, 196, 196, 196, 196, 191);
	printf("\n			%c A - soma B- subtracao C- multiplicacao D- divisao %c", 179, 179);
	printf("\n			%c  E - raiz quadrada F- potenciacao G- nume. primo  %c", 179, 179);
	printf("\n			%c   H - m..cubicos I- logari. J- seno K- cosseno.   %c", 179, 179);
	printf("\n			%c             L - tangente M- fatorial.             %c", 179, 179);
	printf("\n			%c   	         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                %c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c   	         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                %c", 179, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c                                                   %c", 179, 179);
	printf("\n			%c%c%c                                               %c%c%c", 192, 196, 196, 196, 196, 217);

}
float soma(float v1, float v2){
	return v1+v2;
}
float subtracao(float v1, float v2){
	return v1-v2;
}
float multiplicacao(float v1, float v2){
	return v1*v2;
}
float divisao(float v1, float v2){
	return v1/v2;
}
float raiz_quadrada(float v1){
	float d;
	d = sqrt(v1);
	return d;
}
float potenciacao(float v1, float v2){
	float d;
	d = pow(v1,v2);
	return d;
}
float metros_cubicos(float v1){
	printf("\n												Crescente");
	printf("\n											KM -> HM3: %f", v1*1000);
	printf("\n											HM3 -> DAM3: %f", v1*1000);
	printf("\n											DAM3 -> M3: %f", v1*1000);
	printf("\n											M3 -> DM3: %f", v1*1000);
	printf("\n											DM3 -> CM3: %f", v1*1000);
	printf("\n											CM3 -> MM3: %f", v1*1000);
	printf("\n												Decrescente");
	printf("\n											CM3 <- MM3: %f", v1/1000);
	printf("\n											DM3 <- CM3: %f", v1/1000);
	printf("\n											M3 <- DM3: %f", v1/1000);
	printf("\n											DAM3 <- M3: %f", v1/1000);
	printf("\n											HM3 <- DAM3: %f", v1/1000);
	printf("\n											KM <- HM3: %f", v1/1000);
}
float logaritmo(float v1){
	float d;
	d = log(v1);
	return d;
}
float seno(float v1){
	float d;
	d = sin(v1*PI/180);
	return d;
}
float cosseno(float v1){
	float d;
	d = cos(v1*PI/180);
	return d;
}
float tangente(float v1){
	float d;
	d = tan(v1*PI/180);
	return d;
}
float numeroprimo(int v1){
	int cont = 0;
	float auxprimo = 0;
	auxprimo = cont = 0;
	for (cont = 1; cont <= v1; cont++) {
    	if (v1 % cont == 0) { 
    		auxprimo++;
    	}
  	}
  	return auxprimo;
}
float fatorial(float v1){
	float fatorial = 1;
	for (fatorial = 1; v1 > 1; v1 = v1-1){
		fatorial = fatorial * v1;
	}
	return fatorial;
}

main(){
	setlocale(LC_ALL, "Portuguese");
	float resultado, x, y;
	float voltar[50];
	resultado = x = y = 0;
	char escolha, resp = 0;
	int cont, xx, auxiliar, opcao, auxc = 0;
	xx = cont = auxiliar = 0;
	auxc = opcao = 1;
	for (cont = 0; cont < 50; cont++){
		voltar[cont] = 0;
	}
	do{
		menu();
		if (auxiliar > 0){
			printf("\n					 Valor OPÇÃO: %.2f", voltar[opcao], setlocale(LC_ALL, "Portuguese"));
			resp = 's';
			while (resp == 's'){
				printf("\n			     deseja voltar ou avançar os valores? (S/N): ");
				scanf("%s", &resp);
				if (resp == 's'){
					gotoxy(40,17);
					printf("Use 'V' PARA VOLTAR.", setlocale(LC_ALL, "Portuguese"));
					gotoxy(38,16);
					printf("Use 'W' PARA AVANÇAR - ", setlocale(LC_ALL, "Portuguese"));
					scanf("%s", &resp);
					if (resp == 'V'){
						if (opcao < 1){
							system("cls");
							printf("\nArmazenamento Inválido");
							break;
						}
						opcao--;
						printf("\n					 Valor OPÇÃO: %.2f", voltar[opcao], setlocale(LC_ALL, "Portuguese"));
					}
					else if (resp == 'W'){
						if (opcao > 50){
							system("cls");
							printf("\nArmazenamento Inválido");
							break;
						}
						opcao++;
						printf("\n					 Valor OPÇÃO: %.2f", voltar[opcao], setlocale(LC_ALL, "Portuguese"));
					}
				}
			}
		}
		escolha = getch();
		switch(escolha){
			case 'A':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("+");
						gotoxy(60,8);
						printf("V2: ");
						scanf("%f", &x);
						resultado = soma(voltar[opcao],x);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("+");
				gotoxy(60,8);
				printf("V2: ");
				scanf("%f", &y);
				resultado = soma(x,y);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'B':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("-");
						gotoxy(60,8);
						printf("V2: ");
						scanf("%f", &x);
						resultado = subtracao(voltar[opcao],x);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("-");
				gotoxy(60,8);
				printf("V2: ");
				scanf("%f", &y);
				resultado = subtracao(x,y);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'C':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("x");
						gotoxy(60,8);
						printf("V2: ");
						scanf("%f", &x);
						resultado = multiplicacao(voltar[opcao],x);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("x");
				gotoxy(60,8);
				printf("V2: ");
				scanf("%f", &y);
				resultado = multiplicacao(x,y);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'D':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("/");
						gotoxy(60,8);
						printf("V2: ");
						scanf("%f", &x);
						resultado = divisao(voltar[opcao],x);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("/");
				gotoxy(60,8);
				printf("V2: ");
				scanf("%f", &y);
				resultado = divisao(x,y);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'E':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("raiz");
						resultado = raiz_quadrada(voltar[opcao]);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				resultado = raiz_quadrada(x);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'F':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1 - B: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("pot");
						gotoxy(60,8);
						printf("V2 - E: ");
						scanf("%f", &x);
						resultado = potenciacao(voltar[opcao],x);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1 - B: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("pot");		
				gotoxy(60,8);
				printf("V2 - E: ");
				scanf("%f", &y);
				resultado = potenciacao(x,y);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'G':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						resultado = numeroprimo(voltar[opcao]);
						if (resultado == 2){
							gotoxy(45,10);
							printf("P: %.2f", voltar[opcao]);
						}
						else{
							gotoxy(45,10);
							printf("N/P: %.2f", voltar[opcao]);
						}
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%d", &xx);
				resultado = numeroprimo(xx);
				if (resultado == 2){
					gotoxy(45,10);
					printf("P: %d", xx);
				}
				else{
					gotoxy(45,10);
					printf("N/P: %d", xx);
				}
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'H':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.4f", voltar[opcao]);
						metros_cubicos(voltar[opcao]);
						gotoxy(32,22);
						printf("Digite o RESULTADO QUE DESEJA USAR: ");
						scanf("%f", &resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				metros_cubicos(x);
				gotoxy(32,22);
				printf("Digite o RESULTADO QUE DESEJA USAR: ");
				scanf("%f", &resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'I':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("log");
						resultado = logaritmo(voltar[opcao]);
						gotoxy(45,10);
						printf("R: %f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("log");
				resultado = logaritmo(x);
				gotoxy(45,10);
				printf("R: %f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'J':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("sen");
						resultado = seno(voltar[opcao]);
						gotoxy(45,10);
						printf("R: %f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("sen");
				resultado = seno(x);
				gotoxy(45,10);
				printf("R: %f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'K':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("cos");
						resultado = cosseno(voltar[opcao]);
						gotoxy(45,10);
						printf("R: %f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("cos");
				resultado = cosseno(x);
				gotoxy(45,10);
				printf("R: %f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'L':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("tan");
						resultado = tangente(voltar[opcao]);
						gotoxy(45,10);
						printf("R: %f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("tan");		
				resultado = tangente(x);
				gotoxy(45,10);
				printf("R: %f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
			case 'M':
				if (auxiliar > 0){
					gotoxy(29,21);
					printf("deseja calcular como novo resultado? (S/N): ");
					scanf("%s", &resp);
					if (resp == 'n'){
						gotoxy(35,8);
						printf("V1: %.2f", voltar[opcao]);
						gotoxy(50,8);
						printf("!");
						resultado = fatorial(voltar[opcao]);
						gotoxy(45,10);
						printf("R: %.2f", resultado);
						voltar[auxc] = resultado;
						auxc++;
						break;
					}
				}
				gotoxy(35,8);
				printf("V1: ");
				scanf("%f", &x);
				gotoxy(50,8);
				printf("!");		
				resultado = fatorial(x);
				gotoxy(45,10);
				printf("R: %.2f", resultado);
				voltar[auxc] = resultado;
				auxc++;
				break;
		}
	auxiliar++;
	gotoxy(29,20);
	printf("você deseja continuar sua aplicação? (S/N): ", setlocale(LC_ALL, "Portuguese"));
	scanf("%s", &resp);
	system("cls");
	}
	while(resp == 's');
	return 0;
}
