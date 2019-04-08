#include <iostream>

using namespace std;

struct tiempo{
	int hora;
	int minuto;
	int segundo;
	tiempo(int hora, int minuto, int segundo){
		this->hora = hora;
		this->minuto = minuto;
		this->segundo = segundo;
	}
};

bool esPosterior(tiempo &t1, tiempo &t2){

	bool esPosterior = false;

	int t1_seg, t2_seg;

	t1_seg = ConvertirASegundos(t1);
	t2_seg = ConvertirASegundos(t2);

	if (t1 < t2)
		esPosterior = true;

	return esPosterior;

};

int ConvertirASegundos(tiempo t){

	int segundos = 0;

	segundos =+ (t.hora * 60 * 60) + (t.minuto * 60) + t.segundo;

	return segundos;

};

tiempo ObtenerNuevoTiempo(tiempo &t, int &incr_seg){

	int horas, minutos, segundos;

	horas = incr_seg / (60 * 60);
	incr_seg = incr_seg % (60 * 60);
	
	minutos = incr_seg / 60;
	segundos = incr_seg % 60;

	int hora_final, minuto_final, segundo_final;

	if (t.segundo + segundos >= 60){
		segundo_final = (t.segundo + segundos) % 60;
		minutos++;
	}else
		segundo_final = t.segundo + segundos;

	if (t.minuto + minutos >= 60){
		minuto_final = (t.minuto + minutos) % 60;
		horas++;
	}else
		minuto_final = t.minuto + minutos;

	hora_final = (t.hora + horas) % 24;
	
	tiempo t_final(hora_final, minuto_final, segundo_final);

	return t_final;

};


main(){

	tiempo t1(13, 55, 43);
	tiempo t2(4, 32, 36);
	tiempo t3(16, 12, 3);

	cout << "t1: " << t1.hora << ":" << t1.minuto << ":" << t1.segundo << endl;
	cout << "t2: " << t2.hora << ":" << t2.minuto << ":" << t2.segundo << endl;
	cout << "t3: " << t3.hora << ":" << t3.minuto << ":" << t3.segundo << endl;

	bool es_Posterior = esPosterior(t1, t2);

	cout << "¿Es t2 posterior a t1? " << es_Posterior << endl;

	es_Posterior = esPosterior(t1, t3);
	cout << "¿Es t3 posterior a t1? " << es_Posterior << endl;

	int segundos_t1 = ConvertirASegundos(t1);

	cout << "Segundos totales de t1: " << segundos_t1 << endl;

	int incremento_seg = 400;

	tiempo t4 = ObtenerNuevoTiempo(t1, incremento_seg);

	cout << "Nuevo instante de tiempo -> t1 + 400 seg = " << t4.hora << ":" << t4.minuto << ":" << t4.segundo << endl;

}
