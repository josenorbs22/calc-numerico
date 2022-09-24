#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

double funcao(double variavel){
    double res;
    res = ((pow(variavel, 3)) - variavel - 1);
    return res;
}

double derivada(double variavel){
    double res;
    res = ((3 * pow(variavel, 2)) - 1);
    return res;
}

bool bissecao(double a, double b){
    double x_ns = (a + b) / 2;
    double x_ns_anterior;
    double e = 0.001, a_n = a, b_n = b;
    for (int i = 0; i < 1000; i++){
        x_ns_anterior = x_ns;
        if((funcao(a_n) * funcao(x_ns)) < 0){
            b_n = x_ns;
        } else if((funcao(x_ns) * funcao(b_n)) < 0){
            a_n = x_ns;
        }
        x_ns = (a_n + b_n) / 2;
        cout << (i + 1) << " | " << fixed << setprecision(4) << a_n << " | " << b_n << " | " << x_ns << " | " << funcao(x_ns) << endl;
        if(fabs(x_ns - x_ns_anterior) <= e){
            cout << "Raiz alcancada: " << x_ns << endl;
            return true;
        }
    }
    return false;
}
bool falsaPosicao(double a, double b){
    double x_ns = ((a * funcao(b) - b * funcao(a)) / (funcao(b) - funcao(a)));
    double x_ns_anterior;
    double e = 0.001, a_n = a, b_n = b;
    for (int i = 0; i < 1000; i++){
        x_ns_anterior = x_ns;
        if((funcao(a_n) * funcao(x_ns)) < 0){
            b_n = x_ns;
        } else if((funcao(x_ns) * funcao(b_n)) < 0){
            a_n = x_ns;
        }
        x_ns = ((a_n * funcao(b_n) - b * funcao(a_n)) / (funcao(b_n) - funcao(a_n)));
        cout << (i + 1) << " | " << fixed << setprecision(4) << a_n << " | " << b_n << " | " << x_ns << " | " << funcao(x_ns) << endl;
        if(fabs(x_ns - x_ns_anterior) <= e){
            cout << "Raiz alcancada: " << x_ns << endl;
            return true;
        }
    }
    return false;
}

bool newton(double x){
    double x_ns = x;
    double x_ns_anterior, e = 0.001;
    for (int i = 0; i < 1000; i++){
        x_ns_anterior = x_ns;
        x_ns = (x_ns_anterior - (funcao(x_ns) / derivada(x_ns)));
        cout << (i + 1) << fixed << setprecision(4) << " | " << x_ns <<  " | " << funcao(x_ns) << endl;
        if(fabs(x_ns - x_ns_anterior) <= e){
            cout << "Raiz alcancada: " << x_ns << endl;
            return true;
        }
    }
    return false;
}

int main(){
    int opt, n;
    double a, b;
    while(true){
        cout << "Calculadora para achar as raizes da funcao f(x) = x^3 - x - 1" << endl << endl << "-----------------------------------------" << endl;
        cout << "Qual metodo a ser usado? (qualquer outro numero para sair do programa): " << endl;
        cout << "1 - Metodo da bissecao" << endl;
        cout << "2 - Metodo da Falsa Posicao" << endl;
        cout << "3 - Metodo de Newton" << endl;
        cout << "Opcao: ";
        cin >> opt;
        if(opt == 1){
            while(true){
                cout << "Limite inferior do intervalo: ";
                cin >> a;
                cout << "Limite superior do intervalo: ";
                cin >> b;
                if(b > a && (funcao(a) * funcao(b)) < 0){
                    break;
                }
                else if(a > b){
                    cout << "Trocando limite inferior pelo superior e vice-versa" << endl;
                    int p = a;
                    a = b;
                    b = p;
                    break;
                } else {
                    cout << "Intervalo invalido porque nao ha raiz nele." << endl;
                    continue;
                }
            }
            cout << "i | a_n | b_n | x_ns | f(x_ns)" << endl; 
            if(bissecao(a, b))
                cout << "Tolerancia alcancada!" << endl;
            else
                cout << "Numero de iteracoes maximo alcancado.";

            continue;

        } else if(opt == 2){
            while(true){
                cout << "Limite inferior do intervalo: ";
                cin >> a;
                cout << "Limite superior do intervalo: ";
                cin >> b;
                if(b > a && (funcao(a) * funcao(b)) < 0){
                    break;
                }
                else if(a > b){
                    cout << "Trocando limite inferior pelo superior e vice-versa" << endl;
                    int p = a;
                    a = b;
                    b = p;
                    break;
                } else {
                    cout << "Intervalo invalido porque nao ha raiz nele." << endl;
                    continue;
                }
            }
            cout << "i | a_n | b_n | x_ns | f(x_ns)" << endl; 
            if(falsaPosicao(a, b))
                cout << "Tolerancia alcancada!" << endl;
            else
                cout << "Numero de iteracoes maximo alcancado.";

            continue;
        } else if(opt == 3){
            while(true){
                cout << "Palpite inicial de raiz: ";
                cin >> a;
                cout << "i | x_ns | f(x_ns)" << endl; 
                if(newton(a)){
                    cout << "Tolerancia alcancada!" << endl;
                    break;
                } else {
                    cout << "Palpite muito longe da resposta certa, tente novamente." << endl;
                    continue;
                }                
            }
            continue;
        } else {
            break;   
        }
    }

    return 0;
}