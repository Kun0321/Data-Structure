/*
使用「陣列」資料結構來存放N位同學的成績資料，然後再使用for迴圈的演算法來判斷N位同學的成績，最後列印出結果。
輸出介紹：先輸出最大值，在輸出最小值

輸入範例：
5 
60 70 80 85 90

輸出範例：
90 60
*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int n, x[n];
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> x[i];
    
    int min = x[0], max = x[0];

    for(int i = 1 ; i < n ; i++){
        if(min > x[i]) min = x[i];
        if(max < x[i]) max = x[i];
    }

    cout<< max << " " << min;
    return 0;
}
