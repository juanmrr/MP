#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	const int TOPE = 20;
	int v1 [TOPE];

	time_t t;
        
	srand ((int) time(&t));

	for(int i = 0; i < TOPE; i++){
		v1[i] = (rand() % 100) + 1;
		cout << v1[i] << endl;
	}

	int *p;
	int *p_fin;
	int *ref = v1;
	int *aux = new int;
	bool seguir = true;

	while (seguir){
		p = v1;
		p_fin = v1 + TOPE - 1;
		while ((*p <= *ref) && p < p_fin)
			p++;
		while ((*p_fin > *ref) && p_fin > p)
			p_fin--;
		if (p < p_fin){
			cout << *p << "  " << *p_fin << endl; 
			*aux = *p;
			*p = *p_fin;
			*p_fin = *aux;
		}else
			seguir = false;
	}

	for (int i = 0; i < TOPE; i++)
		cout << v1[i] << " ";
}
