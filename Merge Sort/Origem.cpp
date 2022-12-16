#include <iostream> 
#include <random> 
using namespace std;

void mergeSort(int *, int, int);
void merge(int *, int, int, int);
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

void mergeSort(int *vetor, int inicio, int fim) {
	int meio;
	if(inicio < fim) {
		meio = floor((inicio + fim) / 2);
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

void merge(int *vetor, int inicio, int meio, int fim) {
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio + 1;
	temp = (int *)malloc(tamanho * sizeof(int));
	if(temp!=NULL) {
		for(i = 0; i < tamanho; i++) {
			if(!fim1 && !fim2) {
				if(vetor[p1] < vetor[p2])
					temp[i] = vetor[p1++];
				else
					temp[i] = vetor[p2++];
				if(p1 > meio) fim1 = 1;
				if(p2 > fim)fim2 = 1;
			} else {
				if(!fim1)
					temp[i] = vetor[p1++];
				else
					temp[i] = vetor[p2++];
			}
		}
		for(j = 0; k = inicio; j < tamanho, j++, i++)
			vetor[k] = temp[j];
	}
	free(temp);
}
