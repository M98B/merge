#include <iostream>
#include <cstdlib>
#include<ctime>

using namespace std;

void tabGen(float tab[], int n);
float minVal(float tab[], int n);
float maxVal(float tab[], int n);
float srednia(float tab[], int n);
void mergeSort(float tab[], int n);

int main() {
	srand(time(NULL));
	const int max_n = 100;
	float tab[max_n];
	tabGen(tab, max_n);
	//cout << *tab << endl << *(tab + 1);
	cout << minVal(tab, max_n) << endl << maxVal(tab, max_n) << endl << srednia(tab, max_n) << endl ;

	system("pause");
return 0;
}


void tabGen(float tab[], int n) {

	for (int i = 0; i < n; i++)
		tab[i] = (float) rand()/RAND_MAX * 100;
}


float minVal(float tab[], int n) {
	float minimum = 100;
	for (int i = 0; i < n; i++) {
		if (minimum > tab[i]) minimum = tab[i];
	}
	return minimum;
}

float maxVal(float tab[], int n) {
	float maximum = 0;
	for (int i = 0; i < n; i++) {
		if (maximum < tab[i]) maximum = tab[i];
	}
	return maximum;
}


float srednia(float tab[], int n) {
	float suma = 0;
	for (int i = 0; i < n; i++)
		suma += tab[i];
	return suma/n;
}
void CopyTab(float orig[], float copy[],int  n) {
	for (int i = 0; i < n; i++)
		copy[i] = orig[i];
}

void mergeSort() {
	
}


