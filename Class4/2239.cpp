#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <cmath>
#include <queue>

using namespace std;
int N;
int sudoku[9][9];
bool row[10][10] = { false, };
bool col[10][10] = { false, };
bool square[10][10] = { false, };


void Dfs(int index){
    if(index == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = index % 9;
    int y = index / 9;

    if(sudoku[y][x] == 0){
        for(int i = 1; i <= 9; i++){
            if(row[y][i] == false && col[x][i] == false && square[(y / 3) * 3 + (x / 3)][i] == false){
                sudoku[y][x] = i;
                row[y][i] = true;
                col[x][i] = true;
                square[(y /3) * 3 + (x / 3)][i] = true;
                Dfs(index+1);
                sudoku[y][x] = 0;
                row[y][i] = false;
                col[x][i] = false;
                square[(y /3) * 3 + (x / 3)][i] = false;
            }
        }
    }
    else {
        Dfs(index+1);
    }

    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    for(int i = 0; i < 9; i++){
        string input;
        cin >> input;
        for(int j = 0; j < 9; j++){
            sudoku[i][j] = input[j] - '0';
            if(sudoku[i][j] != 0){
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[((i / 3) * 3) + (j / 3)][sudoku[i][j]] = true;
            }
        }
    }

    Dfs(0);
    
    return 0;
}