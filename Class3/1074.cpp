#include <iostream>
using namespace std;

int N, r, c;
int cnt = 0;

void Z(int x, int y, int arrSize){
    if(x == r && y == c) return;

    if(r < arrSize && c < arrSize){ // 1
        Z(x, y, arrSize/2);
    }
    else if(r < arrSize && c >= arrSize){ // 2
        cnt = cnt + arrSize*arrSize;
        Z(x, y + arrSize, arrSize/2);
    }
    else if(r >= arrSize && c < arrSize){ // 3
        cnt = cnt + 2*arrSize*arrSize;
        Z(x + arrSize, y, arrSize/2);
    }
    else if(r >= arrSize && c >= arrSize){ // 4
        cnt = cnt + 3*arrSize*arrSize;
        Z(x + arrSize, y + arrSize, arrSize/2);
    }
}


int main() {
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin >> N >> r >> c;

   int arrSize = N*N/2;

   Z(0, 0, arrSize);
   cout <<cnt;
}
