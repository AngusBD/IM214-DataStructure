#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAX 10000

class Sorting {
public:
	int sortArray[MAX] = { };
	int originArray[MAX] = { };
	Sorting() {
		generateArr();
		reset();
	}
	void generateArr() {
		for (int i = 0; i < MAX; i++) {
			originArray[i] = rand() % 1000;
		}
	}
	void reset() {
		for (int i = 0; i < MAX; i++) {
			sortArray[i] = originArray[i];
		}
	}
	void printArray() {
		for (int i = 0; i < MAX; i++) {
			cout << sortArray[i] << '\t';
			if (i % 10 == 9)
				cout << endl;
		}
		cout << endl;
	}
	void bubbleSortDecending(int);
	void selectionSortDecending(int);
	void maxHeapSort(int);
	void maxHeapify(int, int);

};
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}



void Sorting::bubbleSortDecending(int top) {
	for(int i = 0; i < top - 1; i++){
		for(int j = 0; j < top - i - 1; j++){
			if(sortArray[j] < sortArray[j+1]){
				swap(sortArray[j], sortArray[j+1]);
			}
		}
	}
}

void Sorting::selectionSortDecending(int top) {
	for (int i = 0; i < top - 1; i++) {
        int max = i;
        for (int j = i + 1; j < top; j++) {
            if (sortArray[j] > sortArray[max]) {
                max = j;
            }
        }
        if (max != i) {
            swap(sortArray[i], sortArray[max]);
        }
    }
}

void Sorting::maxHeapSort(int top) {
	for (int i = top / 2 - 1; i >= 0; i--) //把樹調整成Max Heap
	{
		maxHeapify(i, top - 1);
	}
	//把最上面的節點( root ) 跟最後面的節點交換位置，
	//把交換位置後的樹轉成 Max Heap
	for (int i = top - 1; i > 0; i--)
	{
		swap(sortArray[0], sortArray[i]);
		maxHeapify(0, i - 1);
	}
}
void Sorting::maxHeapify(int start, int end) {
	int parent = start;
	int child = parent * 2 + 1;
	while (child <= end) //若子節點在範圍內才做比較
	{
		//如果右邊子節點也在範圍內，並且左邊子節點的比較大
		if (child + 1 <= end && sortArray[child] > sortArray[child + 1])
			child++; //那就選右邊的
		if (sortArray[parent] < sortArray[child]) //如果父節點小於子節點代表調整完畢，直接跳出函式
			return;
		else  //否則交換父子內容  移動parent、child
		{
			swap(sortArray[parent], sortArray[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

int main()
{
	srand(time(NULL));
	clock_t start, finish;

	Sorting sorting;

	//bubbleSortDecending
	start = clock();
	sorting.bubbleSortDecending(MAX);
	finish = clock();
	double bubble = (double)(finish - start) / CLOCKS_PER_SEC;
	// sorting.printArray();
	sorting.reset();

	//selectionSortDecending
	start = clock();
	sorting.selectionSortDecending(MAX);
	finish = clock();
	double select = (double)(finish - start) / CLOCKS_PER_SEC;
	// sorting.printArray();
	sorting.reset();

	//maxHeapSort
	start = clock();
	sorting.maxHeapSort(MAX);
	finish = clock();
	double heap = (double)(finish - start) / CLOCKS_PER_SEC;
	// sorting.printArray();
	sorting.reset();

	cout << "排序亂數產生10000個數字" << endl;
	cout << "BubbleSort:" << bubble << "s" << endl;
	cout << "SelectSort:" << select << "s" << endl;
	cout << "HeapSort:" << heap << "s" << endl;

}
