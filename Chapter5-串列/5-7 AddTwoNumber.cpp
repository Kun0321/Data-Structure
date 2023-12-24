/*
你手上擁有兩個由LinkedList組成的數字，每個ListNode只會存放1個數字，且存放時反向存入。

請將兩個數字相加並印出結果，系統會先輸入該數字的位數，在分別輸入數字。本題須使用前面題目LinkedList的InsertFirst功能，並額外完成addTwoNumbers(ListNode* l1, ListNode* l2)的function，該function會回傳ListNode*。

*main函式與ListNode請勿修改！

以下是範例輸入1：
3
3 8 4
4
3 5 2 1

此時l1與l2會是
483
1253

相加結果為
5093(384+3521=3905)

範例輸入2：
3
2 4 3
3
5 6 4

輸出2：
708

範例輸入3：
7
9 9 9 9 9 9 9
4
9 9 9 9

輸出3：
89990001
*/

#include<iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* link;
    ListNode() : data(0), link(0) {}
    ListNode(int x) : data(x), link(0) {}
    ListNode(int x, ListNode* link) : data(x), link(link) {}
};

class LinkedList {
public:
    ListNode* first = nullptr;
    void InsertFirst(int x) {
        ListNode* newNode = new ListNode(x);
        if (first == nullptr) {
            first = newNode;
        }
        else {
            newNode->link = first;
            first = newNode;
        }
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = nullptr;
    ListNode* temp = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->link;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->link;
        }

        carry = sum / 10;
        if (result == nullptr) {
            result = new ListNode(sum % 10);
            temp = result;
        }
        else {
            temp->link = new ListNode(sum % 10);
            temp = temp->link;
        }
    }

    return result;
}

int main() {
    int times, number;
    LinkedList l1, l2;

    cin >> times >> number;
    l1.InsertFirst(number);
    for (int i = 0; i < times - 1; ++i) {
        cin >> number;
        l1.InsertFirst(number);
    }
    cin >> times >> number;
    l2.InsertFirst(number);
    for (int i = 0; i < times - 1; ++i) {
        cin >> number;
        l2.InsertFirst(number);
    }

    ListNode* ans = addTwoNumbers(l1.first, l2.first);

    while (ans != NULL) {
        cout << ans->data;
        ans = ans->link;
    }
}
