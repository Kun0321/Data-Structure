/*
有N筆成績資料，請計算其平均成績，並判斷是否及格。

1 <= N <= 50
系統輸入：N個int型態的數值

結果輸出："及格" 或 "不及格"

輸入範例：
2

60 70
輸出範例：及格
*/

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main(int argc, char* argv[]) {
    int n, sum = 0, number;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> number;
        sum += number;
    }
    if((sum / n) >= 60)
        cout<<"及格";
    else
        cout<<"不及格";
    return 0;
}
