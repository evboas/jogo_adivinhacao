#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout << "*****************************************" << endl;
    cout << "*** Bem vindos ao jogo da adivinhação ***" << endl;
    cout << "*****************************************" << endl;

    cout << endl;
    cout << "Você deve escolher um número de 1 - 100 e tentar adivinhar o número sorteado pelo computador." << endl;
    cout << "Você é capaz de vencer o computador?" << endl;
    cout << endl;


    srand(time(NULL));
    int numero_secreto = rand() % 100;

    int chute, tentativa = 1;
    bool acertou;
    double pontos = 1000;
    char dificuldade;

    int numero_de_tentativas;
    bool selecao = false;

    while(selecao == false){
    
        cout << "Escolha o seu nível de dificuldade: " << endl;
        cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;
        cin >> dificuldade;
        cout << endl;

        if(dificuldade == 'F' || dificuldade == 'f'){
            numero_de_tentativas = 15;
            selecao = true;
        }
        else if(dificuldade == 'M'|| dificuldade == 'm'){
            numero_de_tentativas = 10;
            selecao = true;
        }
        else if(dificuldade == 'D' || dificuldade == 'd'){
            numero_de_tentativas = 5;
            selecao = true;
        }
        else{
            cout << "Entrada inválida" << endl;
            cout << endl;
        }
    }

    do{
        cout <<  "Tentativas: " << tentativa << endl;

        cout <<  "Qual o seu chute? ";
        cin >> chute;

        //cout << "O valor do seu chute é: " << chute << endl;
        acertou = chute == numero_secreto;
        double pontos_perdidos = abs(chute-numero_secreto)/2.;
        pontos -= pontos_perdidos;

        if(chute == numero_secreto){
            cout << "Parabéns, você acertou o número secreto na tentativa " << tentativa << "." << endl;
            cout << "Fim de jogo!" << endl;
            cout << endl;
        }
        else if(chute > numero_secreto){
            cout << "Seu chute foi maior que o número secreto!" << endl;
            tentativa++;
            cout << endl;
        }
        else{
            cout << "Seu chute foi menor que o número secreto!" << endl;
            tentativa++;
            cout << endl;
        }

        cout << endl;
    }while(acertou == false && tentativa <= numero_de_tentativas);

    if(!acertou){
        cout << "Você perdeu, tente novamente!" << endl;
        cout << "O número secreto era " << numero_secreto << endl;
        cout << endl;
    } else {
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de: " << pontos << "." << endl;
        cout << endl;
    }
}

