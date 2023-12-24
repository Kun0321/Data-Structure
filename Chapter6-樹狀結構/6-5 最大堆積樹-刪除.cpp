/*
基於題目6-4所寫的MaxHeap類別，新增int Delete()函式，可以刪除根節點，並依照最大堆積樹的規則調整位置，最後回傳刪除的值。

系統輸入：
第一行，Insert()的執行次數
第二行，依序傳入Insert()的參數
第三行，Delete()的執行次數

結果輸出：
函式Print()的執行結果

輸入範例：
9
9 4 2 5 1 8 11 22 10
3

輸出範例：
9 5 8 4 1 2
*/

#include <iostream>
#define CAPACITY 100
using namespace std;

class MaxHeap{
	public:
		void Insert(int);
		int Delete();
		void Print();
	private:
		int arr[CAPACITY];
		int tail = 0;
};

void MaxHeap::Insert(int x){
	int current = ++tail;
	while (current != 1 && arr[current / 2] < x) {				
		arr[current] = arr[current / 2];				
		current /= 2;
	}
	arr[current] = x;
}

int MaxHeap::Delete() {
	int rt_val = arr[1];
	// Move the last element to the first
	arr[1] = arr[tail];
	arr[tail--] = 0;
	
	int current = 1;
	while (current < tail && (arr[current] < arr[current*2] || arr[current] < arr[current*2+1])) {
		if (arr[current*2] > arr[current*2+1]) {
			swap(arr[current], arr[current*2]);
			current = current * 2;
		}
		else {
			swap(arr[current], arr[current*2+1]);
			current = current * 2 + 1;
		}
	}
	return rt_val;
}

void MaxHeap::Print(){
	for (int i = 1; i <= tail; i++)
		cout << arr[i] << " ";
}

int main(int argc, char *argv[]){

    MaxHeap tree1;
    int times, input;

    for(cin >> times; times > 0; times--) {
		cin >> input; tree1.Insert(input);
	}

    for(cin >> times; times > 0; times--) {
		tree1.Delete();
	}

	tree1.Print();
}
