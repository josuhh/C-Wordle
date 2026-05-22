🇬🇧 **English** | 🇧🇷 [Português Brasileiro](./README_pt-BR.md)

# C-Wordle
 A terminal-based wordle written in C.
 
## Requirements 
- GCC

## Build
 
```bash
gcc main.c -o term
```
 
## Run
 
```bash
./term
```
 
## How to Play
- You have 6 attempts to guess the secret word
- Each guess must be a valid 5-letter word
- After each guess, the numbers will indicate how close you are:
    - 1 = Correct letter, correct position
    - 2 = Correct letter, wrong position
    - 0 = Letter not in the word