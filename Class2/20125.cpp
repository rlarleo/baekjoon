#include <iostream>

using namespace std;

char graph[1000][1000];
int N;
string input;

bool IsValid(pair<int, int> curr){
    return curr.first >= 0 && curr.first < N && curr.second >=0 && curr.second < N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    pair<int, int> head = {-1, -1};
    pair<int, int> gochu = {-1, -1};
    pair<int, int> heart = {-1, -1};
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            graph[i][j] = input[j];
            if(input[j] == '*' && head.first == -1){
                head = {i, j};
                heart = {i+1, j};
                cout << i+2 << ' ' << j+1 << '\n';
            }
        }
    }
    int result = 0;
    pair<int, int> curr = heart;

    // 왼팔
    while(true){
        curr.second = curr.second - 1;
        if(graph[curr.first][curr.second] == '_' || !IsValid(curr)) break;
        result++;
    }
    cout << result << ' ';
    result = 0;
    curr = heart;   

    // 오른팔
    while(true){
        curr.second = curr.second + 1;
        if(graph[curr.first][curr.second] == '_' || !IsValid(curr)) break;
        result++;
    }
    cout << result << ' ';
    result = 0;
    curr = heart;   

    // 허리
    while(true){
        curr.first = curr.first + 1;
        if(graph[curr.first][curr.second] == '_' || !IsValid(curr)) break;
        result++;
        gochu = curr;
    }
    cout << result  << ' ';
    result = 1;
    curr = {gochu.first + 1, gochu.second - 1};   

    // 왼 다리
    while(true){
        curr.first = curr.first + 1;
        if(graph[curr.first][curr.second] == '_' || !IsValid(curr)) break;
        result++;
    }
    cout << result << ' ';
    result = 1;
    curr = {gochu.first + 1, gochu.second + 1};   
    
    while(true){
        curr.first = curr.first + 1;
        if(graph[curr.first][curr.second] == '_' || !IsValid(curr)) break;
        result++;
    }
    cout << result;

}
