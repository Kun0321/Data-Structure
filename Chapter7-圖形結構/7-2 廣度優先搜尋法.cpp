/*
請寫一個void BFS(int i)的副程式，可以從圖形的 i 節點開始拜訪，以「先廣後深」的方式來搜尋，並印出拜訪的順序。

系統輸入：
第一行包含i、N、E三個整數，i 表示從圖形的 i 節點開始拜訪，N為圖形的頂點總數，E為圖形的邊總數。
第二行開始會給出圖形相鄰的資訊，總共E行的資料，每行都會給出n1、n2兩個整數，代表 n1 節點與 n2 節點相鄰。

結果輸出：
BFS()的執行結果。

輸入範例一：
1 8 10
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 8
7 8

輸出範例一：
1 2 3 4 5 6 7 8

輸入範例二：
4 6 6
1 5
1 6
2 3
2 5
3 4
4 5

輸出範例二：
4 3 5 2 1 6
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100;  // 可以根據實際需求調整

vector<int> adjList[MAX_N + 1];
bool visited[MAX_N + 1];

void BFS(int start, int N) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < adjList[current].size(); ++i) {
            int neighbor = adjList[current][i];
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int i, N, E;
    cin >> i >> N >> E;

    for (int j = 0; j < E; ++j) {
        int n1, n2;
        cin >> n1 >> n2;
        adjList[n1].push_back(n2);
        adjList[n2].push_back(n1);  // 無向圖，需考慮雙向
    }

    //cout << "BFS Order: ";
    BFS(i, N);

    return 0;
}
