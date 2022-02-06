#include <iostream>
#include <vector>
using namespace std;

bool computer[101][101] = {0, };
bool visited[101] = {0, };
int nodeNum, rowNum;
int result = 0;

void dfs(int start){
    result++;
    visited[start] = 1;
    for(int i = 1; i <= nodeNum; i++){
        if(computer[start][i] && !visited[i])
            dfs(i);
    }
}

int main()
{
    cin >> nodeNum >> rowNum;
    int start, end;
    for(int i = 0; i < rowNum; i++){
        cin >> start >> end;
        computer[start][end] = 1;
        computer[end][start] = 1;
    }

    dfs(1);

    cout << result - 1;
    return 0;
}
