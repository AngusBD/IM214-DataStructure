#include <iostream>

using namespace std;

class HashTableEntry {
    int value;
    HashTableEntry* next;
    HashTableEntry(int value) {
        this->value = value;
        this->next = NULL;
    }

    friend class HashMapTable;
};

class HashMapTable {
public:
    HashTableEntry** hashtable;
    int capacity = 7;

    HashMapTable() {
        hashtable = new HashTableEntry * [capacity];
        for (int i = 0; i < capacity; i++)
            hashtable[i] = NULL;
    }

    int HashFunc(int value) {
        return value % capacity;
    }

    void Insert(int value) {

        //完成的部分 

    }

    void display() {
        //要完成的部分 
    }

    ~HashMapTable() {
        delete[] hashtable;
    }
};


int main()
{
    /***************  完成 Insert,display 就可以執行 53~69  *****/
    /*
    HashMapTable hash;
    hash.Insert(76);
    hash.Insert(93);
    hash.Insert(40);
    hash.Insert(55);
    hash.Insert(54);
    hash.display();

    cout << endl;

    hash.Insert(47);
    hash.Insert(61);
    hash.Insert(48);
    hash.display();

    cout << endl;*/


    return 0;
}

