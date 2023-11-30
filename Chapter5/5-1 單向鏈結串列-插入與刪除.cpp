/*
請寫一個LinkedList類別，裡面有void InsertFirst(int x)、void InsertLast(int x)、int DeleteFirst()、int DeleteLast()、void PrintList()五個函式和ListNode *first、ListNode *last兩個變數。

類別內部以ListNode類別的實例物件來儲存資料。first指到鏈結串列中第一筆資料。last指到鏈結串列中最後一筆資料。

void InsertFirst(int x)可在開頭新增值為x的資料。
void InsertLast(int x)在最後新增值為x的資料。
int DeleteFirst()刪除開頭一筆資料，並回傳刪除資料的值。
int DeleteLast()刪除最後一筆資料，並回傳刪除資料的值。
void PrintList()透過Traversal的方式所有資料依序印出。
在ListNode類別裡面，int data表示儲存的資料，ListNode *link表示下一個鏈結的物件。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

系統輸入：
第一行，第一個值為InsertFirst()執行次數，後面接著要傳入函式的參數
第二行，第一個值為DeleteFirst()執行次數
第三行，第一個值為InsertLast()執行次數，後面接著要傳入函式的參數
第四行，第一個值為DeleteLast()執行次數

結果輸出：
函式PrintList()的執行結果

輸入範例：
5 10 20 30 40 50
2
5 60 70 80 90 100
2

輸出範例：
30 20 10 60 70 80
*/

#include <iostream>
using namespace std;

class ListNode {
   public:
    ListNode(int a) {
        data = a;//存數值
        link = 0;//存下一個ListNode的記憶體位置
    }

   private:
    int data;
    ListNode* link;
    friend class LinkedList;
};

class LinkedList{
    private:
        ListNode *first;
        ListNode *last;

    public:
    LinkedList() : first(nullptr), last(nullptr) {}//初始化

    void InsertFirst(int x){
        ListNode *newNode = new ListNode(x);
        //判斷first是否為空的
        if(first == nullptr){
            //是 直接設定first和last為newlink
            first = newNode;
            last = newNode;
        }else{
            //否 將newlink的連結指到first，在更新first
            newNode->link = first;
            first = newNode;
        }
    }

    void InsertLast(int x){
        ListNode *newNode = new ListNode(x);
        //判斷last是否為空的
        if(last == nullptr){
            //是 直接設定first和last為newlink
            first = newNode;
            last = newNode;
        }else{
            //否 將last的連結指到新建的newNode，在更新開頭
            last->link = newNode;
            last = newNode;
        }
    }

    int DeleteFirst(){
        //先判斷是否為空的，已經為空就不能再刪東西
        if(first == nullptr)
            return -1;

        //存要刪的date
        int deletedDate = first->data;
        ListNode *temp = first;
        //first更新為first的連結，因為first的連結是下一個newNode
        first = first->link;
        //釋放first的記憶體空間 first會變成nullptr
        delete temp;

        //如果只有一個刪掉之後就會變空的，last也要變成nullptr
        if(first == nullptr)
            last = nullptr;

        return deletedDate;
    }

    int DeleteLast(){
        if(last == nullptr)//先判斷是否為空的，已經為空就不能再刪東西
            return -1;

        int deletedDate = last->data;
        if(first == last){//判斷是否為只剩下一個newNode
            delete last;
            first = nullptr;
            last = nullptr;
        }else{
            ListNode *temp = first;
            while(temp->link != last)//找到倒數第二個ListNode記憶體位址
                temp = temp->link;

            delete last;//釋放最後一個記憶體空間
            last = temp;//將找到的倒數第二個記憶體存回last
            last->link = nullptr;
        }
        
        return deletedDate;
    }
    void PrintList(){
        ListNode *temp = first;
        while (temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->link;
        }
        cout<<endl;
    }
};

int main(int argc, char* argv[]) {
    LinkedList list;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        list.InsertFirst(input);
    }
    for (cin >> times; times > 0; times--)
        list.DeleteFirst();
    for (cin >> times; times > 0; times--) {
        cin >> input;
        list.InsertLast(input);
    }
    for (cin >> times; times > 0; times--)
        list.DeleteLast();
    list.PrintList();
}
