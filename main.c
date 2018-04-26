#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//4 carros, 7 arvores, 8 pedras
int tabuleiro[10][10];
int rickY,rickX;
int zumbis = 15;

int acabou(){
    return 0;
}

void inicia_tab() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tabuleiro[i][j] = 0;
		}
	}
}

void rick() {

	do {
		rickY = rand() % 10;
		rickX = rand() % 10;
	} while (tabuleiro[rickX][rickY] != 0);

	tabuleiro[rickX][rickY] = 1;
	printf("Rick começou em %d %d\n", rickX,rickY);
}

void imprime_tab() {
    printf("--------------------------------\n");
	for (int i = 0; i < 10; i++) {
		printf("|");
		for (int j = 0; j < 10; j++) {
			printf(" %d ", tabuleiro[i][j]);
		}
		printf("|\n");

	}
	printf("--------------------------------\n");
}

void inimigos() {
	int aleY = rand() % 10;
	int aleX = rand() % 10;
	if (tabuleiro[aleX][aleY] == 0) {
		tabuleiro[aleX][aleY] = 2;
	}
	else {
		zumbis++;
	}}

void objetos(){
    int carros = 4, arvores = 7, pedras = 8, balas = 4;

	while(carros != 0){
        int aleY = rand() % 10;
        int aleX = rand() % 10;
        if (tabuleiro[aleX][aleY] == 0) {
            tabuleiro[aleX][aleY] = 3;
            carros--;}
	}
		while(arvores != 0){
        int aleY = rand() % 10;
        int aleX = rand() % 10;
        if (tabuleiro[aleX][aleY] == 0) {
            tabuleiro[aleX][aleY] = 4;
            arvores--;}
	}
    	while(pedras != 0){
        int aleY = rand() % 10;
        int aleX = rand() % 10;
        if (tabuleiro[aleX][aleY] == 0) {
            tabuleiro[aleX][aleY] = 5;
            pedras--;}
	}
        while(balas != 0){
        int aleY = rand() % 10;
        int aleX = rand() % 10;
        if (tabuleiro[aleX][aleY] == 0) {
            tabuleiro[aleX][aleY] = 9;
            balas--;}
	}
}

void mover(char direcao){

    switch(direcao){
        case 'a':
            tabuleiro[rickX][rickY] = 0;
            rickY = rickY - 1;
            break;
        case 'd':
            tabuleiro[rickX][rickY] = 0;
            rickY = rickY + 1;
            break;
        case 's':
            tabuleiro[rickX][rickY] = 0;
            rickX = rickX + 1;
            break;
        case 'w':
            tabuleiro[rickX][rickY] = 0;
            rickX = rickX - 1;
            break;

    }
    tabuleiro[rickX][rickY] = 1;
    printf("Esta em %d %d\n", rickX,rickY);
}

int main(){
    int arma = 0;
    srand(time(0));
    inicia_tab();
    rick();
    while(zumbis != 0){
        inimigos();
        zumbis--;
    }
    objetos();
    do{imprime_tab();
    char comando;
    scanf(" %c", &comando);
    mover(comando);

    }while(!acabou());


    }
