// 1101625林暉恩
// 1101658楊嘉冠

#include <iostream>
using namespace std;

int capacity = 10;

void output(int *int_arr){
	for (int i = 0; i < capacity; i++){
		cout << int_arr[i] << '\t';
	}
	cout << endl;
}

void initialize(int *int_arr, int *original_arr){
	for (int i = 0; i < capacity; i++){
		int_arr[i] = original_arr[i];
	}
	cout << endl;
}

void swap(int *num1Ptr, int *num2Ptr){
	int temp;
	temp = *num1Ptr;
	*num1Ptr = *num2Ptr;
	*num2Ptr = temp;
	// *num1Ptr ^= *num2Ptr;
	// *num2Ptr ^= *num1Ptr;
	// *num1Ptr ^= *num2Ptr;
}

void BubbleSortAscending(int *int_arr){
	for (int i = 0; i < capacity - 1; i++){
		for (int j = 0; j < capacity - 1 - i; j++){
			if (int_arr[j] > int_arr[j + 1]){
				swap(&int_arr[j], &int_arr[j + 1]);
			}
		}
		output(int_arr);
	}
}

void BubbleSortDecending(int *int_arr){
	for (int i = 0; i < capacity - 1; i++){
		for (int j = 0; j < capacity - 1 - i; j++){
			if (int_arr[j] < int_arr[j + 1]){
				swap(&int_arr[j], &int_arr[j + 1]);
			}
		}
		output(int_arr);
	}
}

void SelectionSortAscending(int *int_arr){
	for (int i = 0; i < capacity - 1; i++){
		int min = i;
		for (int j = i + 1; j < capacity; j++){
			if (int_arr[j] < int_arr[min]){
				min = j;
			}
		}
		swap(&int_arr[min], &int_arr[i]);
		output(int_arr);
	}
}

void SelectionSortDecending(int *int_arr){
	for (int i = 0; i < capacity - 1; i++){
		int max = i;
		for (int j = i + 1; j < capacity; j++){
			if (int_arr[j] > int_arr[max]){
				max = j;
			}
		}
		swap(&int_arr[max], &int_arr[i]);
		output(int_arr);
	}
}

void InsertionSortAscending(int *int_arr){
	for (int i = 1; i < capacity; i++){
		int key = int_arr[i];
		int j = i - 1;
		while (key < int_arr[j] && j >= 0){
			int_arr[j + 1] = int_arr[j];
			j--;
		}
		int_arr[j + 1] = key;
		output(int_arr);
	}
}

void InsertionSortDecending(int *int_arr){
	for (int i = 1; i < capacity; i++){
		int key = int_arr[i];
		int j = i - 1;
		while (key > int_arr[j] && j >= 0){
			int_arr[j + 1] = int_arr[j];
			j--;
		}
		int_arr[j + 1] = key;
		output(int_arr);
	}
}

int main(){
	srand(time(NULL));
	int int_arr[10], original_arr[10];
	// int int_arr[10], original_arr[10] = {0,1,2,3,4,5,6,7,8,9};
	// int int_arr[10], original_arr[10] = {9,8,7,6,5,4,3,2,1,0};
	cout << "Original Array:" << endl;
	for (int i = 0; i < capacity; i++){
		original_arr[i] = rand() % 20 + 1;
		int_arr[i] = original_arr[i];
	}
	output(int_arr);

	cout << "BubbleSort(Ascending):" << endl;
	BubbleSortAscending(int_arr);
	initialize(int_arr, original_arr);

	cout << "BubbleSort(Decending):" << endl;
	BubbleSortDecending(int_arr);
	initialize(int_arr, original_arr);

	cout << endl;

	cout << "SelectionSort(Ascending):" << endl;
	SelectionSortAscending(int_arr);
	initialize(int_arr, original_arr);

	cout << "SelectionSort(Decending):" << endl;
	SelectionSortDecending(int_arr);
	initialize(int_arr, original_arr);

	cout << endl;

	cout << "InsertionSort(Ascending):" << endl;
	InsertionSortAscending(int_arr);
	initialize(int_arr, original_arr);

	cout << "InsertionSort(Decending):" << endl;
	InsertionSortDecending(int_arr);
	initialize(int_arr, original_arr);
}
