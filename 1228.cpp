#include <iostream>
using namespace std;


void PrintArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void quickSort(int* arr, int left, int right) {
	if (left >= right)
		return;
	int i = , j = ;
	int key = arr[left];
	while (i != j) {
		while (arr[j] > key && i < j) {

		}
		while (arr[i] <= key && i < j) {

		}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}

	arr[left] = arr[i];
	arr[i] = key;

	quickSort(, , );
	quickSort(, , );
}


int main() {

	int n = 9;
	int arr[] = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
	cout << "original:" << endl;
	PrintArray(arr, n);

	quickSort(arr, 0, n - 1);

	cout << "sorted:" << endl;
	PrintArray(arr, n);
	return 0;
}