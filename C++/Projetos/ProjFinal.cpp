#include <iostream>
using namespace std;

struct NoAVL {
    int chave;
    NoAVL* esquerda;
    NoAVL* direita;
    int altura;

    NoAVL(int valor)
        : chave(valor), esquerda(nullptr), direita(nullptr), altura(1) {}
};

int main(){

    return 0;
}