#include <iostream> 
#include <random> 
using namespace std;

void mergeSort(int *, int);
int random();
int const tam = 10;

int main() {
	int vetor[tam] = {};

	for(int i = 0; i < tam; i++)
		vetor[i] = random();

	for(int v : vetor)
		cout << v << " ";
	
	cout << endl;
	mergeSort(vetor, tam);
	cout << endl;

	for(int v : vetor)
		cout << v << " ";

	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}

int random() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 50);
	return dist(mt);
}

void mergeSort(int *vetor, int tam) {
	int continua, aux, fim = tam;
	do {
		continua = 0;
		for(int i = 0; i < fim - 1; i++) {
			if(vetor[i] > vetor[i + 1]) {
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				continua = i;
			}
		}
		fim--;
	} while(continua != 0);
}
