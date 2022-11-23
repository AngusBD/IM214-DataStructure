#include <iostream>
using namespace std;

class LinkedList;
class ListNode{
private:
    int data;
    ListNode* next;
    ListNode* prev;
public:
    ListNode() :prev(NULL), next(NULL), data(0) { };
    ListNode(int a) :prev(NULL), next(NULL), data(a) { };
    friend class LinkedList;
};

class LinkedList{
private:
    ListNode* first;
public:
    LinkedList() :first(0) {};
    void PrintList();
    void Insert(int x);
    void Delete(int x);
    void Search(int x);			
    void Clear();           
};

void LinkedList::PrintList(){

    if (first == 0){
        cout << "List is empty.\n";
        return;
    }

    ListNode* current = first; 
    while (current != 0){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Insert(int x){

    ListNode* newNode = new ListNode(x); 

    if (first == 0){// 1.Doubly Linked List是空的
        first = newNode;
        return;
    }

    if (first->data > x/*如果first指到的node值比新增的值大的話*/){//2.要插入的Node的值是最小的(要放在最前面)
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
        return;
    }

    ListNode* current = first;

    while (current->next != 0 && current->next->data < x){
        current = current->next;
    }

    if (current->next == 0/*如果current指到的node值後面沒有node*/){//3.2 要新增的node剛好在list的最後
        current->next = newNode;
        newNode->prev = current;
        return;
    }
    else{//3.1 node不新增在first, 也不在最後一個
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        return;
    }

}

void LinkedList::Delete(int x){
    //Traversal, 檢查list是否為empty或是否有要刪的node
    ListNode* current = first, * previous = 0;

    while (current != 0 && current->data != x){
        previous = current;
        current = current->next;
    }
    if (current == 0){
        cout << "There is no " << x << " in list.\n";
    }
    else if (current == first){
        //1. 刪除的node剛好在list的開頭：要先把first指到下一個node, 再把要刪除的node刪掉
        first = current->next;
        delete current;
        current = 0;
    }
    else if (current->next == 0){
        //2. 刪除的node剛好在list的最後：要先把previous指到下一個node, 再把要刪除的node刪掉
        previous->next = current->next;
        delete current;
        current = 0;
    }
    else{
        //3. 其餘情況(list中有欲刪除的node, 且node不為first, 也不為最後一個)：
        //把要刪掉的上一個node(所以你前面可以先有一個指標指到上一個node)指到要刪掉的下一個node,
        //接著把下一個node的prev指到上一個node, 再把要刪除的node刪掉 
        previous->next = current->next;
        current->next->prev = previous;
        delete current;
        current = 0;
    }
}

void LinkedList::Search(int x){
    ListNode* current = first;
    int pos = 0;

    while (current != 0 && current->data != x){
        current = current->next;
        pos++;
    }
    if (current == 0){
        cout << "There is no " << x << " in list.\n";
    }
    else{
        cout << "There is " << x << " in list.At the " << pos + 1 << " place.\n";
    }
}

void LinkedList::Clear(){

    while (first != 0){ // Traversal
        ListNode* current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}

int main(void){

    LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      // list是空的, 沒有4
    list.Insert(5);   // list: 5
    list.Insert(3);   // list: 3 5
    list.Search(5);   // 印出:There is 5 in list.At the 2 place.
    // list.PrintList();
    list.Insert(9);  // list: 3 5 9
    list.Insert(4);   // list: 3 4 5 9
    list.PrintList();    // 印出:  3 4 5 9
    list.Search(1);   // 印出:There is no 1 in list.
    list.Delete(3);      // list: 4 5 9
    list.PrintList();    // 印出: 4 5 9
    list.Delete(7);		// list沒有7
    list.Insert(8);  // list: 4 5 8 9
    list.Insert(2);  // list: 2 4 5 8 9
    list.PrintList();    // 印出:  2 4 5 8 9
    list.Search(8);   // 印出:There is 8 in list.At the 4 place.
    list.Clear();        // 清空list
    list.PrintList();    // 印出: List is empty.*/

    return 0;
}
