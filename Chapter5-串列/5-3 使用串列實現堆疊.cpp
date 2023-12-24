/*
請寫一個Stack類別，繼承題目5-1所寫的LinkedList類別，使用鏈結串列的方式實現堆疊。

Stack類別裡面有void Push(int x)、int Pop()、void PrintStack()三個函式。void Push(int x)可將資料x加入到堆疊頂端，int Pop()可從堆疊頂端取出一個資料並回傳，void PrintStack()從堆疊底部依序印出資料到堆疊頂端。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

系統輸入：
第一行，Push()執行次數，後面接著要傳入函式的參數
第二行，Pop()執行次數

結果輸出：
函式PrintStack()的執行結果

輸入範例：
6 10 20 30 40 50 60
2

輸出範例：
10 20 30 40
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
            if(first == nullptr){
                return 0;
            }

            int deletedDate = first->date;
            ListNode *temp = first;
            first = first->link;
            delete temp;

            if(first == nullptr)
                last = nullptr;

            return deletedDate;
        }
        int DeleteLast() {
            if (last == nullptr) {
                return -1;
            }
            int value = last->date;
            if (first == last) {
                delete last;
                first = nullptr;
                last = nullptr;
            }
            else {
                ListNode* temp = first;
                while (temp->link != last) {
                    temp = temp->link;
                }
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

class Stack{
    private:
        LinkedList list;

    public:
    void Push(int x){
        list.InsertLast(x);
    }
    int Pop(){
        list.DeleteLast();
    }
    void PrintStack(){
        list.PrintList();
    }
};

int main(int argc, char* argv[]) {
    Stack stack;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        stack.Push(input);
    }
    for (cin >> times; times > 0; times--)
        stack.Pop();
    stack.PrintStack();
}
