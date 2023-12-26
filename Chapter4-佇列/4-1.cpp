/*
輸入範例：
6 10 20 30 40 50 60 2

輸出範例：
30 40 50 60
*/

#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char* argv[]) {
    //使用C++ 佇列內建的功能
    queue<int> A;
    int times, input;

    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        A.push(input);
    }
    cout<< "push 6次大小：" << A.size() <<endl;

    cin >> times;
    for (int i = 0; i < times; i++)
        A.pop();
    cout<< "pop 2次大小：" << A.size() <<endl;

    while (!A.empty()){
        cout<<A.front()<<" ";
        A.pop();
    }
    
}
