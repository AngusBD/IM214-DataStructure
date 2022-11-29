#include<iostream>
using namespace std;

class LinkedList;

class ListNode{
    private:
        int data;
        ListNode* next;
    public:
        ListNode(int num):data(num),next(NULL){};
        friend class LinkedList;
};

class LinkedList{
    private:
        ListNode* first;
    public:
        LinkedList():first(0){};
        void PrintList();
        void Insert(int x);
        void Delete(int x);
        void Reverse();
        LinkedList SeparateOdd(LinkedList list);
        LinkedList SeparateEven(LinkedList list);
};

void LinkedList::PrintList(){
    static int count = 0;
    count++;
    if (first == 0){
        cout << "List is empty.\n";
        return;
    }
    ListNode* current = first;
    cout << "head";
    if(count == 3){
        cout << "1";
    }
    else if(count == 4){
        cout << "2";
    }
    while (current != 0){
        cout << "->" << current->data;
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Insert(int x){

    ListNode* newNode = new ListNode(x); 

    if(first == 0){
        first = newNode;
        return;
    }
    if(first->data > x){
        newNode->next = first;
        first = newNode;
        return;
    }
    ListNode* current = first;
    for(; (current->next != 0) && (current->next->data) < x;){
        current = current->next;
    }
    if(current->next == 0){
        current->next = newNode;
        return;
    }
    else{
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList :: Reverse(){
    ListNode* current = first;
    ListNode* pre = NULL;
    ListNode* nextTemp = NULL;
    for(; current != NULL; ){
        nextTemp = current->next;
        current->next = pre;
        pre = current;
        current = nextTemp;
    }
    first = pre;
}

void LinkedList :: Delete(int x){
    ListNode* current = first, *pre = 0;
    for(; current != 0 && (current->data) != x; ){
        pre = current;
        current = current->next;
    }
    if(current == 0){
        cout << "There is no " << x << " in list.\n";
    }
    else if(current == first){
        first = current->next;
        delete current;
        current = 0;
    }
    else if(current->next == 0){
        pre->next = current->next;
        delete current;
        current = 0;
    }
    else{
        pre->next = current->next;
        delete current;
        current = 0;
    }
}

LinkedList LinkedList :: SeparateEven(LinkedList list){
    LinkedList temp;
    ListNode* current = list.first;
    int repeatCheck = 1;
    for(; current != 0;){
        if((current->data) % 2 == 0){
            if(current->data != repeatCheck){
                temp.Insert(current->data);
            }
            repeatCheck = current->data;
        }
        current = current->next;
    }
    return temp;
}

LinkedList LinkedList :: SeparateOdd(LinkedList list){
    LinkedList temp;
    ListNode* current = list.first;
    int repeatCheck;
    for(; current != 0;){
        if((current->data) % 2 != 0){
            if(current->data != repeatCheck){
                temp.Insert(current->data);
            }
            repeatCheck = current->data;
        }
        current = current->next;
    }
    return temp;
}

int main(void){
    int N;
    cin >> N;
    LinkedList list;
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        list.Insert(rand() % 10);
    }
    list.PrintList();
    list.Reverse();
    list.PrintList();
    LinkedList newListOdd;
    LinkedList newListEven;
    newListOdd = list.SeparateOdd(list);//其實用void就好，不須設定傳輸型態也能跑，只是我想炫技，但翻車後改回來懶得刪。
    newListEven = list.SeparateEven(list);
    newListOdd.Reverse();
    newListEven.Reverse();
    newListOdd.PrintList();
    newListEven.PrintList();
}