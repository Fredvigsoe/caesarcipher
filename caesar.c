#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "cipher.h"
#include "caesar.h"

#define MAX_TEXT_LENGTH 255


void printMenu() {
    wprintf(L"-----------------------------------------------------------------------------------\n");
    wprintf(L"Velkommen til Caesar Cipher, der kan kryptere og dekryptere en tekst efter dit valg\n");
    wprintf(L"-----------------------------------------------------------------------------------\n");
    wprintf(L"E. Encrypt tekst\n");
    wprintf(L"D. Decrypt tekst\n");
    wprintf(L"Q. Afslut\n");
    wprintf(L"Vælg en mulighed ved hjælp af E, D eller Q: ");
}

void getChoice(wchar_t* text, int shiftValue, char option) {
    if (option == 'E' || option == 'e') {
        encrypt(text, shiftValue - 2); 
    } else if (option == 'D' || option == 'd') {
        decrypt(text, shiftValue); 
    }
}

int main() {
    setlocale(LC_CTYPE, ""); 
    wchar_t text[MAX_TEXT_LENGTH];
    char option;
    int shiftValue;

    while (1) {
        printMenu();
        
        // Læs brugerens valg
        if (scanf(" %c", &option) != 1) {
            wprintf(L"Ugyldigt valg. Prøv igen.\n");
            while (getchar() != '\n');
            continue;
        }

        // Afslut programmet hvis brugeren vælger 'Q' eller 'q'
        if (option == 'Q' || option == 'q') {
            wprintf(L"Afslutter programmet.\n");
            break;
        }

        // Læs shift-værdi
        wprintf(L"Indtast shift værdi: ");
        if (scanf("%d", &shiftValue) != 1) {
            wprintf(L"Ugyldig værdi. Prøv igen.\n");
            while (getchar() != '\n'); 
            continue;
        }

        
        while (getchar() != '\n');

        // Læs teksten fra brugeren
        wprintf(L"Indtast tekst (op til %d tegn): ", MAX_TEXT_LENGTH);
        if (fgetws(text, MAX_TEXT_LENGTH, stdin) == NULL) {
            wprintf(L"Fejl ved læsning af tekst.\n");
            continue;
        }

        // Krypter eller dekrypter teksten 
        getChoice(text, shiftValue, option);

        wprintf(L"--------------------------------------------\n");
        // Udskriv resultat
        wprintf(L"\nResultat: %ls\n", text);
        wprintf(L"--------------------------------------------\n");
    }

    return 0;
}
