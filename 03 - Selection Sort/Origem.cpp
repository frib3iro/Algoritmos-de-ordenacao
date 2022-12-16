#include <iostream> 
#include <random> 
using namespace std;

void selectionSort(int *, int);
int random();
int const tam = 10;

int main() {
	int vetor[tam] = {};

	for(int i = 0; i < tam; i++)
		vetor[i] = random();

	for(int v : vetor)
		cout << v << " ";
	cout << "\n---------------------------\n";

	selectionSort(vetor, tam);

	for(int i = 0; i < tam; i++) {
		cout << vetor[i] << " ";
	}
	cout << "\n---------------------------\n";

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

void selectionSort(int *vetor, int tam) {
	int menor, troca;
	for(int i = 0; i < tam - 1; i++) {
		menor = i;
		for(int j = i + 1; j < tam; j++) {
			if(vetor[j] < vetor[menor])
				menor = j;
		}
		if(i != menor) {
			troca = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = troca;
		}
	}
}
