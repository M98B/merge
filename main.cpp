#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void tabGen(float tab[], int n);
float minVal(float tab[], int n);
float maxVal(float tab[], int n);
float srednia(float tab[], int n);
void mergeSort(float tab[], int left, int right);
void merge(float tab[], int left, int middle, int right);


int main()
{
	const int max_n = 100000;
	srand(time(NULL));
	float tab[max_n];
	tabGen(tab, max_n);
	//cout << minVal(tab, max_n) << endl << maxVal(tab, max_n) << endl << srednia(tab, max_n) << endl ;
	// for (int i = 0; i < max_n ; i ++){
	// 	cout << tab[i] << "  ";
	// }
	mergeSort(tab, 0, max_n-1);
	// for (int i = 0; i < max_n; i++){
	// 	cout << tab[i] << endl;
	// }
	cout << "done" << endl;
	system("pause");
return 0;
}

void tabGen(float tab[], int n) {
	for (int i = 0; i < n; i++)
		tab[i] = (float) rand();
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

void merge(float tab[], int left, int middle, int right){
	int l_index = left;
	int r_index = middle+1;
	int current = left;
	//cout << left << "  to  " << right << endl;
	float temp[right - left + 1];
	for(int i = left; i <= right ; i++){
		temp[i - left] = tab[i];
	}
	
	while (l_index <= middle && r_index <= right){
		if (temp[l_index - left] <= temp[r_index - left])
		{
			tab[current] = temp[l_index - left];
			l_index++;
		} else {
			tab[current] = temp[r_index - left];
			r_index++;
		}
		current++;
	}

	while (l_index <= middle){
		tab[current] = temp[l_index - left];
		l_index++;
		current++;
	}
	while (r_index <= right){
		tab[current] = temp[r_index - left];
		r_index++;
		current++;
	}
}

void mergeSort(float tab[], int left, int right) {
		int middle = (left + right) / 2;
	if (left < right){
		mergeSort(tab, left , middle);
		mergeSort(tab, middle+1, right);
		merge(tab, left, middle, right);
	}
}


