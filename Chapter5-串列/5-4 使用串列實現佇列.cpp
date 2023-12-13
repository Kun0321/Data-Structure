/*
請寫一個Queue類別，繼承題目5-1所寫的LinkedList類別，使用鏈結串列的方式實現佇列。

Queue類別裡面有void Enqueue(int x)、int Dequeue()、void PrintQueue()三個函式。void Enqueue(int x)可將資料x加入到佇列後面，int Dequeue()可刪除佇列最前面的一筆資料並回傳，void PrintQueue()則列印出佇列全部內容(從前至後)。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

系統輸入：
第一行，Enqueue()執行次數，後面接著要傳入函式的參數
第二行，Dequeue()執行次數

結果輸出：
函式PrintQueue()的執行結果

輸入範例：
6 10 20 30 40 50 60
2

輸出範例：
30 40 50 60
*/

#include <iostream>
using namespace std;

class ListNode{
    public:
    ListNode(int a){
        date = a;
        link = 0;
    }

    private:
        int date;
        ListNode *link;
        friend class LinkedList;
};

class LinkedList{
    private:
        ListNode *first;
        ListNode *last;
    
    public:
        LinkedList():first(nullptr),last(nullptr){};

        void InsertFirst(int x){
            ListNode *newlink = new ListNode(x);
            if(first == nullptr){
                first = newlink;
                last = newlink;
            }else{
                newlink->link = first;
                first = newlink;
            }
        }

        void InsertLast(int x){
            ListNode *newlink = new ListNode(x);
            if(last == nullptr){
                first = newlink;
                last = newlink;
            }else{
                last->link = newlink;
                last = newlink;
            }
        }

        int DeleteFirst(){
            if(first == nullptr)
                return 0;

            int deletedDate = first->date;
            ListNode *temp = first;
            first = first->link;
            delete temp;

            if(first == nullptr)
                last = nullptr;

            return deletedDate;
        }

        int DeleteLast() {
            if (last == nullptr)
                return -1;
            
            int value = last->date;
            if (first == last) {
                delete last;
                first = nullptr;
                last = nullptr;
            }
            else {
                ListNode* temp = first;
                while (temp->link != last)
                    temp = temp->link;
                
                delete last;
                last = temp;
                last->link = nullptr;
            }
            return value;
        }

        void PrintList(){
            ListNode *temp = first;
            while (temp != nullptr){
                cout<<temp->date<<" ";
                temp = temp->link;
            }
            cout<<endl;
        }
};

class Queue {
    private:
        LinkedList list;

    public:
        void Enqueue(int x) {
            list.InsertLast(x);
        }

        int Dequeue() {
            list.DeleteFirst();
        }

        void PrintQueue() {
            list.PrintList();
        }
};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        queue.Enqueue(input);
    }
    for (cin >> times; times > 0; times--)
        queue.Dequeue();
    queue.PrintQueue();
}
