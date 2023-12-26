/*
請寫一個Queue類別，裡面有Enqueue(int x)、Dequeue()、PrintQueue()三個函式和int arr、int rear、int front三個變數。

arr儲存佇列內容，大小為10。rear表示最後一個值的位置，front表示最前面一個值的位置-1。
rear和front初始值為-1。Enqueue(int x)可將變數x加入到佇列後面，Dequeue()可刪除佇列最前面的一個值，PrintQueue()則列印出佇列全部內容(從後至前)。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

系統輸入：Enqueue次數(最多10)+放入佇列的值+Dequeue次數

結果輸出：函式PrintQueue()的執行結果

輸入範例：
6 10 20 30 40 50 60 2

輸出範例：
30 40 50 60
*/

#include <iostream>
using namespace std;

class Queue{
private:
    int arr[10];
    int rear;   //加
    int front;  //刪

public:
    //初始化
    Queue():rear(-1), front(-1){}
    
    void Enqueue(int x){
        arr[++rear] = x;
    }

    void Dequeue(){
        ++front;
    }

    void PrintQueue(){
        for (int i = front+1 ; i <= rear ; i++) 
            cout << arr[i] << " ";
    }
};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;

    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }

    cin >> times;
    for (int i = 0; i < times; i++) {
        queue.Dequeue();
    }
    
    queue.PrintQueue();
}
