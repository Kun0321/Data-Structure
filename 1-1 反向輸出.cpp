/*
輸入一整數N，代表整數的陣列大小，接著輸入一串陣列數字，接著反向輸出。
1 <= N <= 499

範例輸入:
4

1 5 6 7
範例輸出:
7 6 5 1
*/

#include<iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin>>n;
    int number[n];
    for(int i = 0 ; i < n ; i++)
        cin >> number[i];
    
    for(int i = n-1 ; i >= 0 ; i--)
        cout << number[i] << " ";
        
    return 0;
}
