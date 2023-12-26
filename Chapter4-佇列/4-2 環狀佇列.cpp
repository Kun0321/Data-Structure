/*
請修改題目4-1的Queue類別，將其改成「環狀佇列」。
rear和front初始值為0。PrintQueue()除了列印出佇列全部內容(從後至前)，還要列印出rear和front這兩個變數的值。請參考輸出範例。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

系統輸入：{Enqueue次數(最多9次)+放入佇列的值+Dequeue次數} * 2

結果輸出：函式PrintQueue()的執行結果

輸入範例：
6 10 20 30 40 50 60 2
5 70 80 90 100 110 2

輸出範例：
50 60 70 80 90 100 110 rear:1 front:4
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
        rear = (rear + 1)%10;
        // %10 目的是如果front超過10會回到0開始繼續加到9
    }

    void Dequeue(){
        front = (front + 1) % 10;
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
    
    for (int i = 0; i < 2; i++) {
        cin >> times;
        for (int j = 0; j < times; j++) {
            cin >> input;
            queue.Enqueue(input);
        }
        cin >> times;
        for (int j = 0; j < times; j++) {
            queue.Dequeue();
        }
    }
    queue.PrintQueue();
}
