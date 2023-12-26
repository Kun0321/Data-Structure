/*
老闆要求阿亮完成三個雙向佇列分別是A,B,C(佇列大小都為9)

但是阿亮沒有程式設計的概念

所以根本不會寫這個程式

這時他想到資工二年級的學生們可以幫他這個忙

老闆有特別告訴阿亮:

我今天
front跟rear都設初始值為0
第一次
輸入 n 表示我要執行幾次動作
第二次
輸入 1 時要執行Enqueue()的動作->再輸入x將x放入佇列內
輸入 2 時要執行Dequeue()的動作
輸入 3 時要執行BackEnqueue()的動作->再輸入x將x放入佇列內
輸入 4 時要執行BackDequeue()的動作
輸入 5 時要執行PrintQueue()的動作
第三次
輸入 1 時會使用A佇列進行動作
輸入 2 時會使用B佇列進行動作
輸入 3 時會使用C佇列進行動作

PrintQueue()要將雙向佇列的值印出並且要輸出front跟rear所在的位置

你能幫阿亮完成這個難題嗎?

輸入範例:

17
1 1 2
3 2 4
1 3 5
1 2 8
2 3
5 1
5 2
5 3
3 3 10
1 2 20
4 2
3 1 30
4 1
1 3 40
5 1
5 2
5 3

輸出範例:

A:2
front:0 rear:1
B:4 8
front:8 rear:1
C:
front:1 rear:1

A:30
front:8 rear:0
B:4 8
front:8 rear:1
C:10 40
front:0 rear:2

front為第一個值的位置，rear為最後一個值後面空的位置

※試著寫寫看，不要cout阿亮我也不會，否則我就把你當掉
*/

#include<iostream>
using namespace std;

class Queue{
    private:
        int arr[9], front, rear;
        
    public:
        Queue():rear(0), front(0){}

        void Enqueue(int x){
            arr[rear] = x;
            rear = (rear + 1 ) % 9;
        }

        void Dequeue(){
            front = (front + 1) % 9;
        }

        void BackEnqueue(int x){
            front = (front -1 + 9) % 9;
            arr[front] = x;
            
        }

        void BackDequeue(){
            rear = (rear - 1 + 9) % 9;
        }

        void PrintQueue(){
            int temp = front;
            while(temp != rear){
                cout<< arr[temp] << " ";
                temp = (temp + 1) % 9;
            }
            cout<<endl;
            cout<< "front:" << front << " rear:" << rear<<endl;
        }

};

int main(){
    Queue A_Liang[4];

    int first, second, third, x;
    cin>>first;

    for(int i = 0 ; i < first ; i++){
        cin>> second >> third;

        switch (second){
        case 1:
            cin>>x;
            A_Liang[third].Enqueue(x);
            break;
        case 2:
            A_Liang[third].Dequeue();
            break;
        case 3:
            cin>>x;
            A_Liang[third].BackEnqueue(x);
            break;
        case 4:
            A_Liang[third].BackDequeue();
            break;
        case 5:
            if(third == 1){
                cout<<"A:";
            }else if(third == 2){
                cout<<"B:";
            }else if(third == 3){
                cout<<"C:";
            }
            A_Liang[third].PrintQueue();
            cout<<endl;
            break;
        }
    }

}
