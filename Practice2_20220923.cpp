#include <iostream>
using namespace std;

void sort(int*, int);

int main()
{
	srand(time(NULL)); //一個是srand函數！這是在調用rand（）這個函數之前使用的！rand（）是一個產生隨機數的函數！而srand是一個設置隨機數種子的函數！通常這兩個函數是一起使用的！來完成產生隨機數的功能！
										//而time(NULL)這個函數的返回值是作為srand函數的參數的！意思是以現在的系統時間作為隨機數的種子來產生隨機數！至於NULL這個參數,很簡單因為這個話就返回到現在時間時候的long秒,只有設置成NULL才能獲得系統的時間！
	int a[7];
	for (int i = 0; i < 7; i++)
		a[i] = rand() % 101 + 200; // 將獲取的隨機變數限制在200~300


	sort(a, 7);

	for (int i = 0; i < 7; i++) {
		cout << i << ". " << a[i] << endl;
	}
}

//請將陣列變成由小排到大
void sort(int* m, int n) {//你使用的排序方式: Bubble Sort
	int temp;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j<n-1; j++){
			if (m[j] > m[j + 1]) {
				temp=m[j];
				m[j]=m[j+1];
				m[j+1]=temp;
			}
		}
	}
}
