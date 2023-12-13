/*
基於題目6-2所寫的BinTree類別，新增void Inorder(TreeNode*)、void Preorder(TreeNode*)、void Postorder(TreeNode*)函式，使用遞迴的方式，分別對二元樹實現中序追蹤、前序追蹤，以及後續追蹤，並印出其追蹤過程。

系統輸入：
第一行，輸入資料的次數
第二行，資料的內容

結果輸出：
第一行，Inorder()的執行結果
第二行，Preorder()的執行結果
第三行，Postorder()的執行結果

輸入範例：
8
4 6 5 9 7 11 2 1

輸出範例：
1 2 4 5 6 7 9 11
4 2 1 6 5 9 7 11
1 2 5 7 11 9 6 4
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
        TreeNode *root;                             // 樹的根節點
    public:
        BinTree():root(0){};
        TreeNode* getRoot();                        // 回傳樹的根節點
        void BuildTree(vector<int> data, int n);    // 建立二元樹
        void Inorder(TreeNode* node);               // 中序追蹤
        void Preorder(TreeNode* node);              // 前序追蹤
        void Postorder(TreeNode* node);             // 後序追蹤

};

void BinTree::BuildTree(vector<int> data, int n) {
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

TreeNode* BinTree::getRoot() {
    return root;
}

void  BinTree::Inorder(TreeNode* node) {
    if (node != nullptr) {
        Inorder(node->leftChild);
        cout << node->data << " ";
        Inorder(node->rightChild);
    }
}

void  BinTree::Preorder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        Preorder(node->leftChild);
        Preorder(node->rightChild);
    }
}

void  BinTree::Postorder(TreeNode* node) {
    if (node != nullptr) {
        Postorder(node->leftChild);
        Postorder(node->rightChild);
        cout << node->data << " ";
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

    tree1.Inorder(tree1.getRoot());
    cout << endl;
    tree1.Preorder(tree1.getRoot());
    cout << endl;
    tree1.Postorder(tree1.getRoot());
    cout << endl;
}
