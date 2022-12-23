#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


class hashArray {
private:
	int* table;
	int size;
public:
	hashArray() {
		size = 8;
		table = new int[size];
		for (int i = 0; i < size; i++) {
			table[i] = NULL;
		}
	}
	int hashCode(int val) {
		return val % size;//Index
	}
	void insertLinear(int val) {// value = key

		//1.Set hashIndex


		//2.While collision, find next free space by linear probling



		table[hashIndex] = val;
	}
	void insertQuadratic(int val) {// value = key

		//1.Set hashIndex


		//2.While collision, find next free space by quadratic probling



		table[hashIndex] = val;
	}

	void printTable() {
		for (int i = 0; i < size; i++) {

			cout << i << ".\t";
			if (table[i] == NULL)
				cout << "NULL" << endl;
			else
				cout << table[i] << endl;
		}
	}
};

int main()
{
	int nums[6] = { 97,99,57,14,28,41 };
	hashArray hash1, hash2;
	for (int i = 0; i < 6; i++) {
		hash1.insertLinear(nums[i]);
		hash2.insertQuadratic(nums[5 - i]);
	}
	cout << " Linear probing : " << endl;
	hash1.printTable();
	cout << " Quadratic probing : " << endl;
	hash2.printTable();

}
