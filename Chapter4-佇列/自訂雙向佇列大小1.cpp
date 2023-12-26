#include <iostream>
#include <deque>

int main() {
    const int maxSize = 10; // 想要的最大大小

    std::deque<int> myDeque;

    // 前端入列
    myDeque.push_front(1);
    myDeque.push_front(2);
    myDeque.push_front(3);

    // 檢查大小
    if (myDeque.size() > maxSize) {
        myDeque.pop_back();
    }

    // 後端入列
    myDeque.push_back(4);
    myDeque.push_back(5);
    myDeque.push_back(6);

    // 檢查大小
    if (myDeque.size() > maxSize) {
        myDeque.pop_front();
    }

    // 印出結果
    for (const auto& elem : myDeque) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
