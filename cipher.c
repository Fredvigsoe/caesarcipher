#include <stdio.h>
#include <wctype.h>  // Til towupper() for letterToNumber så både store og små bogstaver virker
#include <wchar.h> // Til at hjælpe med at læse ÆØÅ, ved brug af wchar_t og wprintf. Fordi char forventer 1 byte per bogstav, og ÆØÅ er mere end 1 byte.
#include <locale.h> // Til at hjælpe med at læse ÆØÅ
#include "cipher.h"

wchar_t alphabet[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
int alphabet_length = 29;


// Krav: int letterToNumber( wchar_t ) ← der laver et bogstav (stort eller lille) om til en talværdi for positionen i alfabetet.
int letterToNumber(wchar_t letter) {
    letter = towupper(letter);  // Brug towupper til bredtegn

    // Homemade indexOf
    for (int i = 0; i < alphabet_length; i++) {
        if (alphabet[i] == letter) {
            return i + 1;
        }
    }
    return -1;
}

// Krav: char numberToLetter( int ) ← der laver et tal om til et (stort) bogstav baseret på positionen i alfabetet (tal mindre end 1 eller større end længden af alfabetet bliver til mellemrum)
wchar_t numberToLetter(int number) {
    if (number < 0 || number >= alphabet_length) {
        return L' ';
    }
    return alphabet[number - 1];
}

// Krav: int shift( int number, int shiftvalue ) ← der lægger shiftvalue til number, men hvis resultatet bliver større end længden af alfabetet, skal der starte fra 1 - altså fx bliver shift( 29, 1 ) til 1.
int shift(int number, int shiftValue) {
    if (number <= 0 || number >= 30) {
        wprintf(L"Ugyldigt tal\n");
        return -1;
    }

    int shifted = (number + shiftValue) % alphabet_length;
    if (shifted < 0 && number > 0 && number < 30) {
        shifted += alphabet_length;
    }
    return shifted + 1;
}

// Krav: encrypt( char* text, shift ) ← der shifter hvert eneste tegn i den modtagne text, og erstatter det med det forskudte tegn. Funktionen skal selv finde ud af hvor lang teksten er.
void encrypt(wchar_t* text, int shiftValue) {
    for (int i = 0; text[i] != 0; i++) {
        int number = letterToNumber(text[i]);
        if (number != -1) {
            int shiftedNumber = shift(number, shiftValue);
            wchar_t newLetter = numberToLetter(shiftedNumber);
            text[i] = newLetter;
        }
    }
}

// Krav: decrypt( char *text, shift ) ← der “unshifter” hvert eneste tegn i den modtagne tekst - så hvis et tegn har værdien 5, og shift er 3, så skal tegnet erstattes med tegn nummer 2 i alfabetet.
void decrypt(wchar_t* text, int shiftValue) {
    for (int i = 0; text[i] != 0; i++) {
        int number = letterToNumber(text[i]);
        if (number != -1) {
            int shiftedNumber = shift(number, -shiftValue);
            wchar_t newLetter = numberToLetter(shiftedNumber);
            text[i] = newLetter;
        }
    }
}





/*
// main-funktion til test af letterToNumber, numberToLetter, shift, encrypt & decrypt
int main() {
    setlocale(LC_CTYPE, "");

    wprintf(L"--------------- TEST AF letterToNumber-------------------\n");
    
    // Test letterToNumber C
    wchar_t testLetter = L'C';
    int number = letterToNumber(testLetter);
    wprintf(L"Letter '%lc' is number %d in the alphabet.\n", testLetter, number);  // Forventer 3

    // Test letterToNumber Æ
    wchar_t testLetter2 = L'Æ';
    int number2 = letterToNumber(testLetter2);
    wprintf(L"Letter '%lc' is number %d in the alphabet.\n", testLetter2, number2);  // Forventer 27

    // Test letterToNumber med lille b
    wchar_t testLetter3 = L'b';
    int number3 = letterToNumber(testLetter3);
    wprintf(L"Letter '%lc' is number %d in the alphabet.\n", testLetter3, number3);  

    wprintf(L"--------------- TEST AF numberToLetter-------------------\n");

    // Test numberToLetter 3
    int testNumber = 3;
    wchar_t letter = numberToLetter(testNumber);
    wprintf(L"Number %d is letter '%lc' in the alphabet.\n", testNumber, letter); 

    // Test numberToLetter 27
    int testNumber2 = 27;
    wchar_t letter2 = numberToLetter(testNumber2);
    wprintf(L"Number %d is letter '%lc' in the alphabet.\n", testNumber2, letter2);  

    // Test numberToLetter 28
    int testNumber3 = 28;
    wchar_t letter3 = numberToLetter(testNumber3);
    wprintf(L"Number %d is letter '%lc' in the alphabet.\n", testNumber3, letter3); 

    wprintf(L"--------------- TEST AF SHIFT-------------------\n");

    // Test af shift

    int testmed30 = shift(30, 1);
    wprintf(L"test = %d\n", testmed30); 

    int testmed0 = shift(0, 1);
    wprintf(L"test = %d\n", testmed0); 
    int result = shift(5, 3);
    wprintf(L"test = %d\n", result);  // Forventer 8

    // Test af shift eksempel i opgavebeskrivelsen
    result = shift(28, 1);
    wprintf(L"test = %d\n", result);  // Forventer 1

    // Test af shift med negativt tal
    result = shift(5, -3);
    wprintf(L"test = %d\n", result);  // Forventer 2

    // Test af shift der skal gå til slutningen af alfabetet
    result = shift(2, -3);
    wprintf(L"test = %d\n", result);  // Forventer 28

    wprintf(L"--------------- TEST AF ENCRYPT-------------------\n");

    // Test af encrypt til at kryptere til index af alfabetet + shifted_value
    wchar_t testtext[] = L"ABC DEF";
    int shifted_value = 3;
    encrypt(testtext, shifted_value);
    wprintf(L"test = %ls\n", testtext);  // Forventer "CDE FGH"

    // Test 2 af encrypt
    wchar_t testtext2[] = L"GHI JKL";
    int shifted_value2 = 5;
    encrypt(testtext2, shifted_value2);
    wprintf(L"test = %ls\n", testtext2);  // Forventer "KLM NOP"

    wchar_t decrypttest[] = L"CDE FGH";
    int shifted_value3 = 3;
    decrypt(decrypttest, shifted_value3);
    wprintf(L"test = %ls\n", decrypttest);  // Forventer dekryptering til "ABC DEF"

    return 0;
} 
*/