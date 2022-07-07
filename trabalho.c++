#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
#include <time.h>

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: não permitido o uso de funções e variáveis compostas como structs, vetores e matrizes
    - Corrigir os rastros (pássaro e obstáculos)    OK
    - Implementar colisão  OK
    - Implementar pontuação (mais um ponto para cada obstáculo superado) OK
    - Fazer 2 obstáculos simultâneos (obstaculo1 e obstaculo2) OK
    - Deixar a pontuação visível durante todo o jogo
    - Definir marcos para acelerar a velocidade OK
*/



int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.
    srand(time(NULL));

    int bird_x=5, bird_y=10;
    int obstaculo_1x=130, obstaculo_1y, obstaculo_2x = 180, obstaculo_2y;
    int tecla;
    // variavel para terminar o jogo
    bool jogo = true;
    int ponto = 0;
    int tempo = 100;
    int cont = 0;
    int rand1_min = 3;
    int rand1_max = 6;
    int rand2_min = 8;
    int rand2_max = 12;
    int r1_1  = rand()%(rand1_max-rand1_min+1)+rand1_min;
    int r1_2  = rand()%(rand2_max-rand2_min+1)+rand2_min;
    int r2_1  = rand()%(rand1_max-rand1_min+1)+rand1_min;
    int r2_2  = rand()%(rand2_max-rand2_min+1)+rand2_min;
    ///DESENHO DO CENÁRIO





    while (jogo) { //esse laço faz o jogo rodar para sempre

        ///CORRIGE BUG DO RASTRO
        system("cls");
        /// PLACAR
        coord.X = 1;
        coord.Y = 29;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"PONTOS:"<<ponto;
        ///POSICIONA O PÁSSARO
        coord.X = bird_x;
        coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);



        ///POSICIONA O OBSTÁCULO 1
            if(obstaculo_1x == 0 || jogo == true) {
                obstaculo_1y=1;
                while(obstaculo_1y<30){
                    coord.X = obstaculo_1x;
                    coord.Y = obstaculo_1y;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    if(obstaculo_1y< r1_1 || obstaculo_1y> r1_2){
                        cout<<char(219);
                    } else {
                        cout<<" ";
                    }

                    obstaculo_1y++;
                }
            }




        ///POSICIONA O OBSTÁCULO 2
        if(obstaculo_2x == 0 || jogo == true) {
            obstaculo_2y=1;
            while(obstaculo_2y<30){
                coord.X = obstaculo_2x;
                coord.Y = obstaculo_2y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo_2y< r2_1 || obstaculo_2y>r2_2){
                    cout<<char(219);
                } else {
                    cout<<" ";
                }

                obstaculo_2y++;
            }
        }




        ///VERIFICA COLISÃO E PONTUAÇÃO
        if ( ((bird_y <=r1_1 || bird_y >= r1_2) && bird_x == obstaculo_1x) || ((bird_y <=r2_1 || bird_y >= r2_2) && bird_x == obstaculo_2x)  || (bird_y==0) || (bird_y==29)) {
            jogo=false;
        }


        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' ){
            bird_y--;
        } else {
            bird_y++;
        }



        ///PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR
        tecla='s';

        ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA
        obstaculo_1x--;
        obstaculo_2x--;

        ///REDESENHA O OBSTACULO
        if(obstaculo_1x == 0) {
            ponto++;
            cont+=1;
            obstaculo_1x = 130;
            r1_1  = rand()%(rand1_max-rand1_min+1)+rand1_min;
            r1_2  = rand()%(rand2_max-rand2_min+1)+rand2_min;
        }
        if(obstaculo_2x == 0) {
            ponto++;
            cont+=1;
            obstaculo_2x = 180;
            r2_1  = rand()%(rand1_max-rand1_min+1)+rand1_min;
            r2_2  = rand()%(rand2_max-rand2_min+1)+rand2_min;
        }


        ///TEMPO DE ESPERA
        if (cont == 5) {
            tempo-=25;
            cont = 0;
        }
        Sleep(tempo);


    }
    system("cls");
    system("pause");
    cout<<"PERDEU";
    cout<<ponto << " PONTOS";




    return 0;
}