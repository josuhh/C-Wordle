🇬🇧 [English](./README.md) | 🇧🇷 **Português Brasileiro**

# Term.ooo
Um jogo de adivinhar palavras no terminal, escrito em C.

## Requisitos
- GCC

## Compilar

```bash
gcc main.c -o term
```

## Executar

```bash
./term
```

## Como Jogar

- Você tem 6 tentativas para adivinhar a palavra secreta
- Cada tentativa deve ser uma palavra válida de 5 letras
- Após cada tentativa, os números indicam o quão perto você está:
    - 1 = Letra correta, posição correta
    - 2 = Letra correta, posição errada
    - 0 = Letra não está na palavra