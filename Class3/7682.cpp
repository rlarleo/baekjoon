#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int myIndex = 0;


char map[3][3];

bool Win(char c){
    for(int i = 0; i < 3; i++){
        if( c == map[i][0] && c == map[i][1] && c == map[i][2] ){
            return true;
        }
    }
    for(int i = 0; i < 3; i++){
        if( c == map[0][i] && c == map[1][i] && c == map[2][i] ){
            return true;
        }
    }
    if( c == map[0][0] && c == map[1][1] && c == map[2][2]){
        return true;
    }
    if( c == map[0][2] && c == map[1][1] && c == map[2][0]){
        return true;
    }
    return false;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        string input;
        cin >> input;
        if(input == "end") break;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                map[i][j] = input[i*3 + j];
            }
        }
        
        // 개수가 말이 안되는 경우
        int xCount = 0;
        int oCount = 0;
        int empty = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(map[i][j] == 'X') xCount ++;
                if(map[i][j] == 'O') oCount ++;
                if(map[i][j] == '.') empty ++;
            }
        }
        if(oCount > xCount) {
            cout << "Invalid" << endl;
        }
        else if(xCount < 3){
            cout << "Invalid" << endl;
        }
        else if(xCount - oCount > 0){
            cout << "Invalid" << endl;
        }
        // 가득차있지 않은데 승자가 없는 경우
        else if(empty != 0 && !Win('X') && !Win('O')){
            cout << "Invalid" << endl;
        }
        // 두명이 이긴 경우 
        else if(Win('X') && Win('O')){
            cout << "Invalid" << endl;
        }
        // O가 이겼는데 X가 많은 경우
        else if(Win('O') && xCount > oCount){
            cout << "Invalid" << endl;
        }
        // X가 이겼는데 O랑 같은 경우
        else if(Win('X') && xCount == oCount){
            cout << "Invalid" << endl;
        }
        else {
            cout << "Valid" << endl;
        }
    }



    return 0;
}
