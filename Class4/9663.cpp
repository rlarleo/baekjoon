#include <iostream>

using namespace std;

int board[15][15];
int N;
int cnt;
bool checked(int i, int j){
    return i >= 0 && j >= 0 && i < N && j < N;
}

bool promise(int y, int x){
    for(int i = 0; i < N; i++){
        if(board[y][i] == 1) return false;
        if(board[i][x] == 1) return false;
    }

    int i = y+1;
    int j = x+1;
    while(checked(i, j)){
        if(board[i][j] == 1) return false;
        i++;
        j++;
    }
    i = y-1;
    j = x+1;
    while(checked(i, j)){
        if(board[i][j] == 1) return false;
        i--;
        j++;
    }
    i = y+1;
    j = x-1;
    while(checked(i, j)){
        if(board[i][j] == 1) return false;
        i++;
        j--;
    }
    i = y-1;
    j = x-1;
    while(checked(i, j)){
        if(board[i][j] == 1) return false;
        i--;
        j--;
    }
    return true;
}

void dfs(int y){
    if(y == N) {cnt++; return;}

    for(int i = 0; i < N; i++){
        if(promise(y, i)){
            board[y][i] = 1;
            dfs(y+1);
            board[y][i] = 0;
        }
    }


}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dfs(0);

    cout << cnt;
    return 0;
}
