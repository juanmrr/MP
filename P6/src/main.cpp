#include "miniwin.h"
#include <ctime>
#include <iostream>
#include "particula.h"
#include "definiciones.h"
#include "ConjuntoParticulas.h"
#include "simulador.h"

using namespace miniwin;
using namespace std;

void pintaNube(const ConjuntoParticulas & miConjunto) {
    int N = miConjunto.get_utiles();
    Particula p;
    for (int i = 0; i < N; i++) {
        p = miConjunto.ObtieneParticula(i);
        color(p.get_color());
        circulo_lleno(p.get_x(), p.get_y(), RADIO);
    }

}

ostream& operator<< (ostream &flujo, Particula &p){
    
    flujo << "posX: " << p.get_x() << " posY: " << p.get_y() << " color: " << p.get_color();
    
    return flujo;
    
}

ostream& operator<< (ostream &flujo, ConjuntoParticulas &c){
    
    for (int i = 0; i < c.get_utiles(); i++){
        flujo << c[i] << "\t";
    }
    
    flujo << endl;
    
    return flujo;
    
}

int main() {
    srand(time(0));

    int ancho = 800;
    int alto = 600;

    int opcion;

    cout << "\n  Opcion a probar: ";
    cin >> opcion;

    switch (opcion) {

        case 1:
        {
            cout << "\n** Prueba sobrecarga de operadores **" << endl;
            //vredimensiona(100, 100);
            ConjuntoParticulas a1, b1(4);
            cout << b1 << endl;

            Particula x;
            a1.AgregaParticula(x);
            x.Mover(ancho, alto);
            a1.AgregaParticula(x);
            cout << a1 << endl;
            
            b1.Mover(ancho, alto);
            a1 = a1 + b1;
            cout << a1 << endl;

            ConjuntoParticulas cc = a1 + b1;
            ConjuntoParticulas xx(cc);
            cout << xx << endl;
            cout << endl;
            vcierra();

            break;
        }

        case 2:
        {
            cout << "\n** Prueba Conjunto Particulas ** " << endl;
            int NRO = 20;
            vredimensiona(ancho, alto);
            ConjuntoParticulas rojas(NRO);
            ConjuntoParticulas verdes(NRO);
            ConjuntoParticulas blancas;
            Particula p;

            for (int i = 0; i < NRO; i++) {
                p = rojas.ObtieneParticula(i);
                p.set_color(ROJO);
                rojas.ReemplazaParticula(i, p);

                p = verdes.ObtieneParticula(i);
                p.set_color(VERDE);
                verdes.ReemplazaParticula(i, p);
            }

            ConjuntoParticulas aux;
            for (int i = 0; i < 200; i++) {
                rojas.Mover(ancho, alto);
                verdes.Mover(ancho, alto);
                blancas.Mover(ancho, alto);
                aux = rojas + verdes + blancas;

                borra();
                pintaNube(aux);

                if (i % 10 == 0) {
                    Particula p;
                    p.set_color(BLANCO);
                    blancas.AgregaParticula(p);
                    rojas.BorraParticula(rand() % rojas.get_utiles());
                    verdes.BorraParticula(rand() % verdes.get_utiles());

                }

                refresca();
                espera(35);
            }
            vcierra();

            break;
        }

        case 3:
        {
            cout << "\n************** Probando Simulador ****************\n";
            ConjuntoParticulas base(30);
            ConjuntoParticulas otro(10);
            int tecla_pulsada = tecla();

            Simulador game(base, otro, ancho, alto);
 
            while (tecla_pulsada != ESCAPE){
                tecla_pulsada = tecla();
                switch (tecla_pulsada){
                    case F1:
                        game.AgregaFija();
                        break;
                    case F2:
                        game.AgregaMovil();
                        break;
                    case F3:
                        game.Regenera();
                        break;
                }
                game.Step();
                game.Pintar(30);
            }
            break;
        }
        
        case 4:
        {
            cout << "\n************** Probando Simulador modificado ****************\n";
            ConjuntoParticulas base(30);
            ConjuntoParticulas otro(10);
            int tecla_pulsada = tecla();

            Simulador game(base, otro, ancho, alto);
 
            while (tecla_pulsada != ESCAPE){
                tecla_pulsada = tecla();
                switch (tecla_pulsada){
                    case F1:
                        game.AgregaFija();
                        break;
                    case F2:
                        game.AgregaMovil();
                        break;
                    case F3:
                        game.Regenera();
                        break;
                }
                game.Step_colores();
                game.Pintar(30);
            }
            break;
        }

    };

    return 0;
}
