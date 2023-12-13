/*
請寫一個BinTree類別，使用「鏈結串列」儲存資料的方式實現二元樹。
BinTree類別裡面有void BuildTree(vector data, int n)、void Plot()兩個函式和TreeNode *root一個變數。
BinTree內部以TreeNode類別實例物件來儲存資料。
TreeNode *root指標指到樹的根節點。
void BuildTree(vector data, int n)可將大小為n的data建立成二元樹，其中data為使用者依序輸入的資料。
void Plot()可以畫出樹的形狀。
void Plot()的程式碼已經有提供，不需要重新撰寫。

系統輸入：
第一行，輸入資料的次數
第二行，資料的內容

結果輸出：
函式Plot()的執行結果



輸入範例：
8
4 6 5 9 7 11 2 1

輸出範例（在Dev-C++執行，底線為空白）：
_______________4
_______2_______________6
___1_______________5_______9
_________________________7__11

4
2 6
1 5 9
7 11

*/
#include <math.h>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
   public:
    friend class BinTree;
    TreeNode(int a) {
        data = a;
        leftChild = rightChild = 0;
    };

   private:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

class BinTree{
    private:
        TreeNode *root;
    public:
        BinTree():root(0){};

        void BuildTree(vector<int> data, int n) {
            // step 1: 設定根結點，從 1 開始
            root = new TreeNode(data[0]);

            // step 2:for 是由 data數量決定
            for(int i = 1 ; i < n ; i++){
                // 所有都從根結點開始
                TreeNode *newTree = root;
                
                while(newTree != 0){
                    // step 3: 遇到大的放右邊
                    if(newTree->data < data[i]){
                        if(newTree->rightChild != 0){
                            newTree = newTree->rightChild;
                        }else{
                            newTree->rightChild = new TreeNode(data[i]);
                            break;
                        }
                    // step 4: 遇到小的放左邊
                    }else if(newTree->data > data[i]){
                        if(newTree->leftChild != 0){
                            newTree = newTree->leftChild;
                        }else{
                            newTree->leftChild = new TreeNode(data[i]);
                            break;
                        }
                    }
                }
            }
        }

        void Plot();

};

void BinTree::Plot() {
    int MAX_HEIGHT = 7, CHAR_SPACE = 2;
    int capacity = pow(2, MAX_HEIGHT);
    vector<int> arr(capacity);
    queue<TreeNode*> q;
    queue<int> index_q;
    q.push(root);
    index_q.push(1);
    TreeNode* currentNode;
    int currentIndex, tail = 0;
    while (!q.empty()) {
        currentNode = q.front();
        q.pop();
        currentIndex = index_q.front();
        index_q.pop();
        arr[currentIndex] = currentNode->data;
        if (tail < currentIndex)
            tail = currentIndex;
        if (currentNode->leftChild) {
            q.push(currentNode->leftChild);
            index_q.push(currentIndex * 2);
        }
        if (currentNode->rightChild) {
            q.push(currentNode->rightChild);
            index_q.push(currentIndex * 2 + 1);
        }
    }
    int i, sps;
    int max_level = log(tail) / log(2) + 1;
    for (int lv = 1; lv <= max_level; lv++) {
        sps = pow(2, max_level - lv) * CHAR_SPACE;
        i = pow(2, lv - 1);
        cout << setw(sps);
        if (arr[i])
            cout << arr[i];
        else
            cout << " ";
        sps *= 2;
        for (i++; i <= pow(2, lv) - 1; i++) {
            cout << setw(sps);
            if (arr[i])
                cout << arr[i];
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    BinTree tree1;
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Plot();
}
