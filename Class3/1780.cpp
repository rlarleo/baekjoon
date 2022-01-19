#include <iostream>
using namespace std;

int results[3] = {0, };

bool check(int x, int y, int** arrs, int N){
    int start = arrs[x][y];
    for(int i = x; i < x + N; i++){
        for(int j = y; j < y + N; j++){
            if(arrs[i][j] != start){
                return false;
            }
        }
    }
    results[start+1]++;
    return true;
}

void divide(int x, int y, int** arrs, int N){
    if(check(x, y, arrs, N)){
        return;
    }
    else{
      int size = N/3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                divide(x+i*size, y+j*size, arrs, size);
            }
        }
    }

}

int main()
{
    int N, in;
    cin >> N;

    int** arrs = new int*[N];

    for(int i = 0; i < N; i++){
        arrs[i] = new int[N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> in;
            arrs[i][j] = in;
        }
    }

    divide(0, 0, arrs, N);

    for(int i = 0; i < 3; i++){
        cout << results[i] << endl;
    }
    delete[] arrs;
    return 0;
}
