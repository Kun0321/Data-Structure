/*
請使用，stringstream在一串字串中，擷取數字的部分作輸出
不可更改main函式內容

範例輸入1：
23,24,25

範例輸出1：
23
24
25

範例輸入2：
120,88,243,294,289,214,155,228,274,292,116

範例輸出2：
120
88
243
294
289
214
155
228
274
292
116
*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str){
    vector<int> number;
    stringstream ss(str); // 使用 stringstream 来處理输入字符串
    string temp;

    while(getline(ss, temp, ',')){ // 逗號分隔符
        int num;
        stringstream temp_ss(temp);
        if(temp_ss >> num) number.push_back(num);
    }
    return number;

}

int main(int argc, char* argv[]) {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
