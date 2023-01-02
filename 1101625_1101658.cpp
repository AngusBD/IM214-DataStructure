//1101625
//1101658
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
        
        // create a hash linked list table
        if(hashtable[HashFunc(value)] == NULL){
            HashTableEntry* newNode = new HashTableEntry(0);
            hashtable[HashFunc(value)] = newNode;
        }

        // travel the linked list until the condition is not satisfied 
        // (which mean the list is empty and the node's data is not samller than the new node's data)
        HashTableEntry* current = hashtable[HashFunc(value)];
        HashTableEntry* newNode = new HashTableEntry(value);
        
        for(; current->next != NULL && current->next->value > newNode->value; ){
            current = current->next;
        }

        // insert the data to the linked list
        newNode->next = current->next;
        current->next = newNode;

    }

    void display() {
        for(int i = 0; i < capacity; i++){
            if(hashtable[i] == NULL){
                cout << "key = " << i << endl;
            }
            else{
                // display the linked list if the linked list has the data
                cout << "key = " << i << "-->";
                HashTableEntry* current = hashtable[i];
                for(; current->next->next != NULL; ){
                    // current = current->next;
                    cout << current->next->value << "-->";
                    current = current->next;
                }
                cout << current->next->value << endl;
            }
        } 
    }

    ~HashMapTable() {
        delete[] hashtable;
    }
};


int main(){
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

    cout << endl;


    return 0;
}

