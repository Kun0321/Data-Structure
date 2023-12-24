/*
請寫一個MaxHeap類別，其父節點的值恆大於子節點的值。
請使用「陣列」的方式來儲存資料。
MaxHeap類別裡面有void Insert(int x)、void Print()兩個函式和int arr[100]、int tail兩個變數。
int arr[100]用來儲存資料。
int tail是最後一個節點的索引值。
void Insert(int x)可將資料x加入到最後一個節點中，並依照最大堆積樹的規則調整位置。
void Print()從索引1開始到tail依序印出陣列的內容。

系統輸入：
第一行，Insert()的執行次數
第二行，依序傳入Insert()的參數

結果輸出：
函式Print()的執行結果

輸入範例：
9
9 4 2 5 1 8 11 22 10

輸出範例：
22 11 9 10 1 2 8 4 5
*/

#include <iostream>
using namespace std;

class MaxHeap{
    private:
        int arr[100], tail = 0;
    public:
        void Insert(int x){
            int temp = ++tail;
            while(temp != 1  && arr[temp/2] < x){
                arr[temp] = arr[temp/2];
                temp /= 2;
                
            }
            arr[temp] = x;
            // cout<<"temp: "<<temp<<" tail: "<< tail << endl;
            // Print();
            // cout<<endl;
            
        }
        void Print(){
            for(int i = 1 ; i <= tail ; i++){
                cout<<arr[i]<<" ";
            }
        }
};

int main(int argc, char *argv[]){   
    MaxHeap tree1;
    int times, input;
    for(cin >> times; times > 0; times--){
        cin >> input;
        tree1.Insert(input);
    }
	tree1.Print();
}
