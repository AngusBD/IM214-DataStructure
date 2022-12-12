#include <iostream>
#include <cstdlib>
using namespace std;
class minHeap {
private:
	int MAX_ELEMENTS;
	int* heap;
	int num;
public:
	minHeap() {
		MAX_ELEMENTS = 20;
		heap = new int[MAX_ELEMENTS];
		num = 0;
	}
	void insert(int val) {
		int i; // i 用來當現在新增的這個node的索引值
						  // num 代表這個heap目前有多少node
		if (num >= MAX_ELEMENTS) //檢查還有沒有空間可以insert
		{
			cout << "Heap is full." << endl;
			return;
		}
		i = ++num;

		//如果樹不是空的 或 加入的數小於它的parent 才跑這個while
		while ((i != 1) && (val < heap[i / 2]))
		{
			heap[i] = heap[i / 2]; //把parent的值往下拉
			i /= 2; //移動到parent的位址
		}

		heap[i] = val;
	}
	void deleteMin() {
		int parent, child, temp;

		if (num == 0) //檢查heap有沒有東西可以刪
		{
			cout << "Heap is empty." << endl;
			return;
		}
		temp = heap[num--]; //先把最後一個node的值存在temp
						//因為刪除了 所以num要 -1
		parent = 1;
		child = 2;
		cout << "Delete " << heap[parent] << endl; //刪除一定是刪第一個
		while (child <= num)
		{
			// 如果有兩個子樹 且 左子樹 > 右子樹
			if ((child < num) && (heap[child] > heap[child + 1])) {
				child++; // 因為右子樹比較小 所以選右子樹
			}
			if (temp <= heap[child]) //如果temp比子樹還小 就跳離while迴圈 
			{
				break;
			}
			heap[parent] = heap[child]; //child的值放到parent的位址
			parent = child; //原本的child變成parent
			child *= 2; //child下移
		}
		heap[parent] = temp;
	}
	void printHeap() {
		for (int i = 1; i <= num; i++)
		{
			cout << heap[i] << '\t';
		}
		cout << endl;
	}
};
int main()
{
	int input, val;
	minHeap heap;

	int num[12] = { 19,26,21,65,31,32,3,80,7,10,99,52 };
	for (int i = 0; i < 12; i++) {
		heap.insert(num[i]);
		heap.printHeap();
	}
	for (int i = 0; i < 2; i++) {
		heap.deleteMin();
	}
	heap.printHeap();

	/*
	do
	{
		system("cls");

		cout << endl;

		cout << " Function list:" << endl;
		cout << " (1)新增值<insert>" << endl;
		cout << " (2)刪除最小值<deleteMin>" << endl;
		cout << " (3)列印整個堆積<printHeap>" << endl;
		cout << " (4)離開程式<Exit>" << endl;
		cout << endl << " 輸入要執行的選項：";
		cin >> input;
		cout << endl;

		switch (input)
		{
		case 1:
			cout << " 輸入 0 以終止 " << endl;
			do
			{
				cout << " 輸入新增的值：";
				cin >> val;

				if (val)
				{
					heap.insert(val);
				}
			} while (val);
			break;
		case 2:
			heap.deleteMax();
			cout << endl;
			system("PAUSE");
			break;
		case 3:
			heap.printHeap();
			cout << endl;
			system("pause");
			break;
		case 4:
			break;
		}

	} while (input != 4);
	*/
}
