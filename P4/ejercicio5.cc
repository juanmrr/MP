#include <iostream>

using namespace std;

int main(){

	const int TOPE = 100;
	float v1 [TOPE] = {2, 3, 8, 22, 44, 88, 99, 100, 101, 255, 665};
	float v2 [TOPE] = {1, 3, 4, 5, 6, 25, 87, 89, 99, 100, 500, 1000};
	float res [2*TOPE];

	int tam_v1 = 11, tam_v2 = 12;
	int tam_res = tam_v1 + tam_v2;

	float *p1 = v1;
	float *p2 = v2;
	float *p_res = res;
	float *p1_fin = v1 + tam_v1;
	float *p2_fin = v2 + tam_v2;

	int i = 0, j = 0;

	while (p1 < p1_fin && p2 < p2_fin){
		if ((*p1) >= (*p2)){
			*p_res = (*p2);
			p2++;
			p_res++;
			j++;
		}
		else if ((*p2) > (*p1)){
			*p_res = (*p1);
			p1++;
			p_res++;
			i++;
		}
	}

	while (p1 < p1_fin){
		*p_res = (*p1);
		p_res++;
		p1++;
	}
	
	while (p2 < p2_fin){
		*p_res = (*p2);
		p_res++;
		p2++;
	}

	for (int i = 0; i < tam_res; i++)
		cout << res[i] << "\t";

	cout << endl;
			

	

}
