﻿#include <stdio.h>

int main() {
	int pocet[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int cisla[10];

	int znak = 0;
	int cislo = 0;

	FILE* soubor = fopen("text.txt", "r");

	if (soubor == NULL) {
		printf("Chyba: Soubor nelze otevrit pro cteni.\n");
		return 1;
	}

	while (!feof(soubor)) {
		fscanf(soubor, "%d", &cisla[znak]);
		znak++;
	}
	for (int i = 0; i < 10; i++) {
		cislo = cisla[i];
		pocet[cislo]++;
	}
	
		for (int i = 0; i < 10; i++) {
			if (pocet[i] != 0) printf("Cislo %d je v souboru %d\n", i, pocet[i]);
		}

	if (fclose(soubor) == EOF) {
		printf("Chyba: Soubor se nepodarilo zavrit.\n");
		return 1;
	}

	return(0);
}