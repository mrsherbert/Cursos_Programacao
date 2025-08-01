#include <iostream>
using namespace std;

class Velha {
public:
    char matriz[3][3];
    char aux; // jogador da vez

    Velha() { aux = 'X'; }

    void iniciar() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                matriz[i][j] = ' ';
            }
        }
    }

    bool atribuir(int plinha, int pcoluna) {
        if(plinha < 0 || plinha > 2 || pcoluna < 0 || pcoluna > 2) {
            cout << "Posição inválida!" << endl;
            return true;
        }
        if(matriz[plinha][pcoluna] == ' ') {
            matriz[plinha][pcoluna] = aux;
            return false; // jogada válida
        } else {
            cout << "Local preenchido" << endl;
            return true; // precisa jogar de novo
        }
    }

    bool verificar() {
        // verifica as linhas
        for(int i = 0; i < 3; i++) {
            if(matriz[i][0] == aux && matriz[i][1] == aux && matriz[i][2] == aux) {
                cout << "Jogador " << aux << " ganhou na linha " << i+1 << endl;
                return true;
            }
        }
        // Verifica as colunas
        for(int j = 0; j < 3; j++) {
            if(matriz[0][j] == aux && matriz[1][j] == aux && matriz[2][j] == aux) {
                cout << "Jogador " << aux << " ganhou na coluna " << j+1 << endl;
                return true;
            }
        }
        // verifica as diagonais
        if(matriz[0][0] == aux && matriz[1][1] == aux && matriz[2][2] == aux) {
            cout << "Jogador " << aux << " ganhou na diagonal principal" << endl;
            return true;
        }
        if(matriz[0][2] == aux && matriz[1][1] == aux && matriz[2][0] == aux) {
            cout << "Jogador " << aux << " ganhou na diagonal secundaria" << endl;
            return true;
        }
        return false;
    }

    bool cheio() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(matriz[i][j] == ' ') return false; // ainda tem espaço
            }
        }
        return true;
    }

    void imprimir() {
        cout << "\n   Colunas:  1   2   3" << endl;
        for(int i = 0; i < 3; i++) {
            cout << "Linha " << i+1 << ": ";
            for(int j = 0; j < 3; j++) {
                cout << matriz[i][j];
                if(j < 2) cout << " | ";
            }
            cout << endl;
            if(i < 2) cout << "       ---+---+---" << endl;
        }
        cout << endl;
    }
};

int main() {
    Velha jogo;
    jogo.iniciar();
    char jogador = 'O'; // começa o jogador O
    int linha, coluna;
    bool ver;

    cout << "Quem inicia é o jogador X" << endl;
    while(true) {
        // Alterna o jogador
        if(jogador == 'X') jogador = 'O';
        else jogador = 'X';

        ver = true;
        while(ver) {
            jogo.aux = jogador;

            cout << "Vez de " << jogador << endl;
            cout << "Digite a linha (1 a 3): ";
            cin >> linha;
            cout << "Digite a coluna (1 a 3): ";
            cin >> coluna;

            ver = jogo.atribuir(linha-1, coluna-1);
            jogo.imprimir();
        }

        if(jogo.verificar()) {
            cout << "Fim de jogo! Reiniciando tabuleiro...\n" << endl;
            jogo.iniciar();
            jogo.imprimir();
        }
        else if(jogo.cheio()) {
            cout << "Empate! Tabuleiro cheio.\nReiniciando tabuleiro...\n" << endl;
            jogo.iniciar();
            cout << "Deseja continuar jogando digite 's' \n" << endl;
            cin >> jogador;
            if(jogador == 's'){
            }else{return 0;}
            jogo.imprimir();
        }
    }

    return 0;
}
