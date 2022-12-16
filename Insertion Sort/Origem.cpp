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
	uniform_int_distribution<int> dist(0, 20);
	return dist(mt);
}

void mergeSort(int *vetor, int tam) {
	int i, j, aux;
	for(i = 1; i < tam; i++) {
		aux = vetor[i];
		for(j = i; (j > 0) && (aux < vetor[j - 1]); j--)
			vetor[j] = vetor[j - 1];
		vetor[j] = aux;
	}
}
