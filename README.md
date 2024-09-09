# Caesar Cipher Aflevering

[Link til opgavebeskrivelse](https://petlatkea.notion.site/caesar-c-ed492273291a467bbf6634693d9c21c1)

Testet på Mac(ARM64)

## Hvordan virker det?

Man vælger i startmenuen om du vil encrypt, decrypt eller afslutte programmet ved hjælp af E/e, D/e eller Q/q. Når du har valgt enten encrypt eller decrypt,
vil du blive bedt om at sætte en shift-værdi, for hvor meget teksten skal forskydes. 

## Eksempel
```
-----------------------------------------------------------------------------------
Velkommen til Caesar Cipher, der kan kryptere og dekryptere en tekst efter dit valg
-----------------------------------------------------------------------------------
E. Encrypt tekst
D. Decrypt tekst
Q. Afslut
Vælg en mulighed ved hjælp af E, D eller Q: E
Indtast shift værdi: 3
Indtast tekst (op til 255 tegn): ABC DEF
--------------------------------------------

Resultat: CDE FGH

--------------------------------------------
```
Resultatet stemmer overens med [Khan academy cipheren](https://www.khanacademy.org/computing/computer-science/cryptography/crypt/pi/caesar-cipher-exploration)

## QEH AXV OTJKT TUØKSHKX

## Compile & kør programmet

For at kompilere og køre programmet, brug følgende kommando i terminalen:

```bash
gcc -c cipher.c -o cipher.o
gcc -c caesar.c -o caesar.o
gcc cipher.o caesar.o -o caesar_cipher
./caesar_cipher
