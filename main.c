#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//4 carros, 7 arvores, 8 pedras
int tabuleiro[10][10];
int rickY,rickX;
int zumbis = 15;

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
    int carros = 4, arvores = 7, pedras = 8;

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
}


int main(){
    int balas = 0;
    srand(time(0));
    inicia_tab();
    rick();
    while(zumbis != 0){
        inimigos();
        zumbis--;
    }
    objetos();
    imprime_tab();

    }
