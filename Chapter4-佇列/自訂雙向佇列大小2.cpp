/*
自定義一個繼承自 std::deque 的類別，並在 push_front 和 push_back 操作中添加檢查以限制大小
*/

#include <iostream>
#include <deque>

template <typename T>
class LimitedSizeDeque : public std::deque<T> {
public:
    void push_front(const T& value) {
        if (this->size() < maxSize) {
            std::deque<T>::push_front(value);
        }
    }

    void push_back(const T& value) {
        if (this->size() < maxSize) {
            std::deque<T>::push_back(value);
        }
    }

private:
    static const int maxSize = 5; // 想要的最大大小
};

int main() {
    LimitedSizeDeque<int> myDeque;

    // 前端入列
    myDeque.push_front(1);
    myDeque.push_front(2);
    myDeque.push_front(3);

    // 後端入列
    myDeque.push_back(4);
    myDeque.push_back(5);
    myDeque.push_back(6);

    // 印出結果
    for (const auto& elem : myDeque) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
