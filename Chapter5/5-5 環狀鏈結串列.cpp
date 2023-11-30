/*
請寫一個CircularList類別，實現「環狀鏈結串列」的功能。
該類別裡面有void InsertFirst(int x)、void InsertLast(int x)、int DeleteFirst()、int DeleteLast()、void PrintList()五個函式和ListNode *last變數，CircularList內部以ListNode類別實例物件來儲存資料。

ListNode *last指標指到鏈結串列中最後一筆資料。
void InsertFirst(int x)可在鏈結串列開頭新增值為x的資料。
void InsertLast(int x)可在最後新增值為x的資料。
int DeleteFirst()刪除開頭一筆資料，並回傳刪除資料的值。
int DeleteLast()刪除最後一筆資料，並回傳刪除資料的值。
void PrintList()透過Traversal的方式將所有資料依序印出。
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
        data = a;
        link = 0;
    }

   private:
    int data;
    ListNode* link;
    friend class CircularList;
};

class CircularList{
    private:
        ListNode *last;
    public:
        CircularList():last(nullptr){}

        void InsertFirst(int x){
            ListNode *newlink = new ListNode(x);
            if(last == nullptr){
                last = newlink;//last設為newNode
                last->link = last;//last連結到自己，變成環狀
            }
            newlink->link = last->link;//因為加入的地方是前面，要將指向自己的連結傳到newNode做儲存
            last->link = newlink;//在把last的連結指向newNode
        }

        void InsertLast(int x){
            InsertFirst(x);//新元素加到開頭
            last = last->link;//更新最後一個加入的元素為最後一個,在輸出才會從第一個開始列印
        }

        int DeleteFirst(){
            if (last == nullptr) 
                return -1;
            
            int deleteDate = last->data;
            //判斷是否只剩下一個值
            if(last->link == last){
                delete last;//直接釋放記憶體
                last = nullptr;//將last改為nullptr，表示空的
            }else{
                ListNode *temp = last->link;//最後一個的下一個就是第一個
                last->link = temp->link;//將last的連結指向下下個，就是第二個
                delete temp;//這時候temp是存第一個值，第一個值為要刪除的數值，所以直接delete
            }

            return deleteDate;
        }

        int DeleteLast(){
            if(last == nullptr)
                return -1;

            int deleteDate = last->data;
            if(last->link == last){
                delete last;
                last = nullptr;
            }else{
                ListNode *temp = last->link;
                while (temp->link !=last)//找到倒數第二個newNode
                    temp = temp->link;
                
                temp->link = last->link;  // 將倒數第二個節點的 link 指向第一個節點
                delete last;
                last = temp;
            }
            return deleteDate;
        }

        void PrintList(){
            if (last == nullptr) 
                return;
            
            ListNode *temp = last->link;
            while (temp != last) {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << temp->data <<endl;
        }

};

int main(int argc, char* argv[]) {
    CircularList list;
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
