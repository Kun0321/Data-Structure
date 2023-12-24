/*
PolyList類別是一個多項式串列，利用鏈結串列來儲存多項式中的「非零項目」。其中ListNode類別的int coef表示多項式的「係數」，int exp表示多項式的「指數」。

main函式中已經建立好降冪排序的多項式串列A和B。現在請完成PolyList類別的void Add(PolyList& b)和void PrintList()兩個函式。

void Add(PolyList& b)可與多項式串列b進行「相加」。
void PrintList()可依序將串列中的所有資料印出。

系統輸入：
輸入資料總共兩個例子，每個例子由兩行組成，第一行包含一個整數n，第二行包含n個整數a1, b1, a2, b2, … ,an（1 ≤ ai ≤ 10, 0 ≤ bi ≤ 6），a1表示多項式非零項的「係數」，b1表示多項式非零項的「指數」，依此類推。

結果輸出：
函式PrintList()的執行結果。請以降冪方式依序印出每個ListNode的係數a和指數k，格式為ax^k。每筆印出之間以空格分隔即可。



輸入範例一：
4
2 3 5 1
4
2 3 6 2

輸出範例一：
4x^3 6x^2 5x^1



輸入範例二：
4
2 3 5 1
6
2 4 6 2 4 0

輸出範例二：
2x^4 2x^3 6x^2 5x^1 4x^0

*/
#include <iostream>
using namespace std;

class ListNode {
    public:
        ListNode(int a, int b) {
            coef = a;
            exp = b;
            link = 0;
        }

    private:
        int coef;//係數
        int exp;//指數
        ListNode* link;

    friend class PolyList;
};

class PolyList {
    public:
        void InsertLast(int, int);
        void Add(PolyList&);
        void PrintList();

    private:
        ListNode* first = 0;
        ListNode* last = 0;
};

void PolyList::InsertLast(int coef, int exp) {
    ListNode* newNode = new ListNode(coef, exp);
    if (last == 0)
        first = newNode;
    else
        last->link = newNode;
    last = newNode;
}

void PolyList::Add(PolyList& b) {
    // Write here
    // A點 和 B點的位置（從first出發）
    ListNode *temp_a = first, *temp_b = b.first;
    ListNode* preNode = 0;
    // 應為單向串列，A和B都還有便會繼續進行
    while (temp_a != 0 && temp_b != 0) {
        // 如果 A和B 目前指數一樣，直接將係數相加，兩個都向下進行
        if (temp_a->exp == temp_b->exp) {
            // 將相同指數的係數相加
            temp_a->coef = temp_a->coef + temp_b->coef;
            preNode = temp_a;

            // A B 指數向下進行
            temp_a = temp_a->link;
            temp_b = temp_b->link;
        }

        // 如果 A的指數 > B的指數，A的資料向下進行
        else if (temp_a->exp > temp_b->exp || temp_b == 0) {
            preNode = temp_a;
            temp_a = temp_a->link;

        }

        // 如果 A的指數 < B的指數，先加入B的資料安插在A之中
        else if (temp_a->exp < temp_b->exp) {
            ListNode* nextNode_a = temp_a;  // 先將A的下一個保存在此
            ListNode* newNode = new ListNode(temp_b->coef, temp_b->exp);
            if (nextNode_a == first) {  // 如果是first
                newNode->link = first;
                first = newNode;
            } else {  // 並不是第一個
                preNode->link = newNode;
                newNode->link = nextNode_a;
            }
            preNode = newNode;
            temp_b = temp_b->link;
        }
    }
    while (temp_b != 0) {
        last->link = temp_b;
        last = temp_b;
        preNode = temp_b;
        temp_b = temp_b->link;
    }
}

void PolyList::PrintList() {
    // Write here
    ListNode* temp = first;
    for (; temp != nullptr ; temp = temp->link) {
        cout << temp->coef << "x^" << temp->exp << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    PolyList A, B;
    int times, input, input2;
    for (cin >> times, times /= 2; times > 0; times--) {
        cin >> input >> input2;
        A.InsertLast(input, input2);
    }
    for (cin >> times, times /= 2; times > 0; times--) {
        cin >> input >> input2;
        B.InsertLast(input, input2);
    }
    A.Add(B);
    A.PrintList();
}
