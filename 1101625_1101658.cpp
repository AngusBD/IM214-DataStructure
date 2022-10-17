#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int answer(string s);

class digstack {
private:
	int top;
	// int top = -1;
	int capacity;
	// int capacity = 5;
	int* digit;
public:
	digstack() :top(-1), capacity(5) {//運算元建構式
		digit = new int[capacity];
	}
	void push(int val);
	int pop();
	int cur();
};
void digstack::push(int val) {//運算元push
	if (top + 1 == capacity) {
		cout << "stack is full!" << endl;
		//擴充stack
		capacity = capacity * 2;
		int* temp = new int[capacity];
		copy(digit, digit + top + 1, temp);
		delete[] digit;
		digit = temp;
	}
	digit[++top] = val;
}
int digstack::pop() {//運算元pop
	if (top == -1) {
		cout << "stack is empty!" << endl;
		return 0;
	}
	return digit[top--];
}
int digstack::cur() {//回傳當前最上方的運算元
	return digit[top];
}

class operstack {
private:
	int top;
	// int top = -1;
	int capacity;
	// int capacity = 5;
	char* operators;
public:
	operstack() :top(-1), capacity(5) {//運算子建構式
		operators = new char[capacity];
	}
	void push(char oper);
	char pop();
	bool isEmpty();
	char cur();
};
void operstack::push(char oper) {//運算元push
	if (top + 1 == capacity) {
		cout << "stack is full!" << endl;
		//擴充stack
		capacity = capacity * 2;
		char* temp = new char[capacity];
		copy(operators, operators + top + 1, temp);
		delete[] operators;
		operators = temp;
	}
	operators[++top] = oper;
}
char operstack::pop() {//運算子pop
	if (top == -1) {
		cout << "stack is empty!" << endl;
		return 0;
	}
	return operators[top--];
}
bool operstack::isEmpty() {//確認運算子stack是否為空(null)
	return (top == -1);
}
char operstack::cur() {//回傳當前最上方的運算子
	return operators[top];
}

int main() {
	string s; // 輸入範例:"-5+9*3-81/-9" 答案:31 
	cout << "Enter the function : " << endl;
	cin >> s;
	cout << "Ans : " << answer(s) << endl;

	return 0;
}

bool isDigit(char c) { //確認是否為數字(運算元)
	return (c >= '0' && c <= '9');
}

bool isOp(char c) { //確認是否為運算子
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int priority(char c) { // 回傳運算子層級
	switch (c) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default: return 0;
	}
}

int calculate(int val1, int val2, char oper) { // 運算
	if (oper == '+')  return val1 + val2;
	if (oper == '-')  return val1 - val2;
	if (oper == '*')  return val1 * val2;
	if (oper == '/')  return val1 / val2;
}

int answer(string s) {
	digstack digs;  //運算元stack
	operstack opers;  //運算子stack

	int pos = 0;
	while (pos<s.length()/*讀輸入字串直到讀完為止*/) {
		char spot = s[pos];
		if (isDigit(spot)/*如果是現在讀到的是運算元*/) {
			//將數字push進stack
			digs.push(spot - 48);
			while (/*當現在讀到的數的下一位也是數字*/isDigit(s[pos + 1])) {
				//把stack裡的數字丟出來加上一個位數後，加上下一位再存回去stack
				digs.push(digs.pop() * 10 + (s[pos + 1]-48));
				//換下一個位置讀
				pos++;
			}
		}
		else {
			if (/* 現在讀到的是減號'-'&&現在位置是在第一位 */spot == '-' && pos == 0) {
				//把下一位數字變成負的，存進stack
				digs.push(-(s[pos + 1] - 48));
				//換下一個位置讀
				pos++;
				while (/*當現在讀到的數的下一位也是數字*/isDigit(s[pos +1])) {
					//把stack裡的數字丟出來加上一個位數後，，加上「負的」下一位並再存回去stack
					digs.push(digs.pop() * 10 -(s[pos + 1] - 48));
					//換下一個位置讀
					pos++;
				}
			}
			else if (/*如果是現在讀到的是減號'-'&&前一位不是數字*/spot == '-' && !isDigit(s[pos - 1]) ){
				//把下一位數字變成負的，存進stack
				digs.push(-(s[pos + 1] - 48));
				//換下一個位置讀
				pos++;
				while (/*當現在讀到的數的下一位也是數字*/isDigit(s[pos + 1])) {
					//把stack裡的數字丟出來加上一個位數後，，加上「負的」下一位並再存回去stack
					digs.push(digs.pop()*10 - (s[pos + 1] - 48));
					//換下一個位置讀
					pos++;
				}
			}
			else { //執行運算
				while (priority(s[pos])<= priority(opers.cur())/*如果讀到的運算子的層級 <= stack裡的最上層的運算子的層級(使用priority)*/) {
					//Pop出一個運算子
					char a = opers.pop();
					//Pop出兩個運算元
					int b = digs.pop();
					int c = digs.pop();
					//進行計算(使用calculate)
					int d = calculate(c, b, a);
					//將結果存入stack
					digs.push(d);
				}
				//將現在讀到的運算子進入stack
				opers.push(spot);

			}
		}
		//換下一個位置讀
		pos++;
	}
	while (!opers.isEmpty()/*當運算子stack不是空的*/) {
		//Pop出一個運算子
		char t_oper = opers.pop();
		//Pop出兩個運算元
		int num1 = digs.pop();
		int num2 = digs.pop();
		int newNum = calculate(num2, num1, t_oper);
		//將結果存入stack
		digs.push(newNum);
	}
	return (digs.cur()/*丟最後結果出來*/);
}
