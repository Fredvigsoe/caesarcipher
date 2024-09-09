# Caesar Cipher Aflevering

[Link til opgavebeskrivelse](https://petlatkea.notion.site/caesar-c-ed492273291a467bbf6634693d9c21c1)

Testet på Mac(ARM64)

## Compile & kør programmet

For at kompilere og køre programmet, brug følgende kommando i terminalen:

```bash
gcc -c cipher.c -o cipher.o
gcc -c caesar.c -o caesar.o
gcc cipher.o caesar.o -o caesar_cipher
./caesar_cipher
