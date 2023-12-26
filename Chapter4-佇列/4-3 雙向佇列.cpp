/*
請修改題目4-2的環狀佇列，將其改成「雙向佇列」。
增加BackEnqueue(int x)、BackDequeue()兩個函式。
BackEnqueue(int x)可將變數x加入到佇列前面，BackDequeue()可刪除佇列最後面的一個值。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

系統輸入：
Enqueue次數(最多9次)+放入佇列的值+Dequeue次數+
BackEnqueue次數(最多9次)+放入佇列的值+BackDequeue次數

結果輸出：函式PrintQueue()的執行結果

輸入範例：
6 10 20 30 40 50 60 2
5 70 80 90 100 110 2

輸出範例：
110 100 90 80 70 30 40 rear:4 front:7
*/

#include <iostream>
using namespace std;

class Queue{
    private:
        int arr[10];
        int rear;
        int front;
        
    public:
    Queue():rear(0), front(0){}
    
    void Enqueue(int x){
        arr[rear] = x;
        rear = (rear + 1) % 10;
    }

    void Dequeue(){
        front = (front + 1) % 10;
    }

    // 1 2 3 4 5 6 7 8
    void BackEnqueue(int x){
        front = (front - 1 + 10) % 10;
        arr[front] = x;
    }

    void BackDequeue(){
        rear = (rear - 1 + 10) % 10;
    }

    void PrintQueue(){
        int temp = front;
        while (temp != rear) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % 10;
        }
        cout << "rear:" << rear << " front:" << front << endl;
    }
};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;

    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.Enqueue(input);
    }

    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.Dequeue();
    }

    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.BackEnqueue(input);
    }

    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.BackDequeue();
    }

    queue.PrintQueue();
}
