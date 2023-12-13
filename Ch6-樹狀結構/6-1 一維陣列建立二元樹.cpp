/*
請寫一個BinTree類別，使用「陣列」儲存資料的方式實現二元樹。
BinTree類別裡面有void BuildTree(int data[], int n)、void Print()兩個函式和int arr[100]、int tail兩個變數。
int arr[100]用來儲存資料。int tail為陣列中有使用到的最大索引值。
void BuildTree(int data[], int n)可將大小為n的data建立成二元樹，其中data為使用者依序輸入的資料。
void Print()印出陣列的內容。

系統輸入：
第一行，輸入資料的次數
第二行，資料的內容

結果輸出：
函式Print()的執行結果

輸入範例：
8
4 6 5 9 7 11 2 1

輸出範例：
4 2 6 1 0 5 9 0 0 0 0 0 0 7 11

                    4(1)
         2(1*2)               6(1*2+1)
    1(2*2)    0(2*2+1)    5(3*2)    9(3*2+1)
0(4*2)  0(4*2+1)   0(6*2)      0(6*2+1)            7      11
                  0      0 0     0
*/
#include <iostream>
using namespace std;

class BinTree {
    private:
        int arr[100]={0}, tail = 1;
    public:
        void BuildTree(int data[], int n) {
            arr[1] = data[0];
            int temp = tail;
            for (int i = 1; i < n; i++) {
                temp = 1;
                while (arr[temp] != 0) {
                    if (data[i] > arr[temp])
                        temp = temp * 2 + 1;
                    else
                        temp = temp * 2;
                }
                if (tail < temp) {
                    tail = temp;
                }
                arr[temp] = data[i];
            }
        }
        void Print() {
            for (int i = 1; i <= tail; i++) {
                cout << arr[i] << " ";
            }
        }
};

int main(int argc, char* argv[]){
    BinTree tree1;
    int n;
    cin >> n;
    int data[100];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Print();
}
