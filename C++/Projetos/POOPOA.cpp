#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <functional>
#include <time.h>
#include <wiringPi.h>

using namespace std;

long int tempo_atual = 1, tempo_anterior = 0;


// Principio de codigo basico medidor de aceleração e velocidade
// Aplica o agendamento para ida e volta (função transversal)
float media(float ini, float fin, const string& a){
    if(tempo_atual == tempo_anterior) return;               // Média
    float res = ((fin-ini)/(tempo_atual-tempo_anterior));   // delay 100ms;
    cout << "A " << a << " atual é" << res << endl;         // Imprimir texto
    return res; // delay 100ms
}


// Valores estimados lineares
class estimacao_linear{
public:
    float posicao_primaria;     // Posição anterior
    float posicao_secundaria;   // Posição atual
    float velocidade_primaria;  // Velocidade anterior
    float velocidade_secundaria;// Velocidade atual
    float acel;                 // Aceleração atual
    estimacao(float posi){
        posicao_primaria = posi; // Construtor atribuindo a posição inicial
        posicao_secundaria = 0.00;  // Iniciador
        velocidade_primaria = 0.00; // Iniciador
        velocidade_secundaria = 0.00;   // Iniciador
        acel = 0.00;
    }
    void calc_velocidade() {velocidade_secundaria = media(posicao_primaria, posicao_secundaria, "velocidade" );}   // Método para calcular a velocidade atual
    void calc_aceleracao() {acel = media(velocidade_primaria, velocidade_secundaria, "aceleração");}  // Método para calcular a aceleração atual
    void atualizacao(){ // Método para atualizar dados
        posicao_primaria = posicao_secundaria;  // Atualiza posição
        velocidade_primaria = velocidade_secundaria;    // Atualiza velocidade
    }
};


// Programa de estimação de velocidades, acelerações e temperaturas
int main() {
    srand(time(NULL));              // Inicar gerador aleatorio
    if (wiringPiSetup() == -1) {return 1;}  // Iniciar biblioteca
    estimacao_linear movel(0);             // Iniciar objeto
    while(1){
        tempo_atual = millis ();    // Atualiza tempo
        cout << "iniciando novas medições" << endl; // Inicar medições
        movel.posicao_secundaria = rand()%100;  // Gerador aleatorio de posição.
        movel.calc_velocidade();    // Calcular velocidade
        movel.calc_aceleracao();    // Calcular aceleração
        movel.atualizacao();        // Atualizar
        cout << endl;               // Quebrar linha
        tempo_anterior = tempo_atual;   // Atualiza tempo
        delay(100); // evitar problemas de sobrecarga
    }
}
