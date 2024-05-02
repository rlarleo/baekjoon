#include <iostream>
#include <vector>

using namespace std;

int paper[100][100] = {0, };

int FindLastIndex(int color, int i, int j, int lastIndex){
    for(int k = lastIndex - 1; k >= j; k--){
        if(paper[i][k] == color) return k;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    int copyPaper[100][100] = {0, };
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int input;
            cin >> input;
            paper[i][j] = input;
        }
    }
    int result = 0;
    for(int i = 0; i < N; i++){
        int lastIndex = M;
        for(int j = 0; j < M; j++){
            if(paper[i][j] != copyPaper[i][j]){
                result++;
                lastIndex = FindLastIndex(paper[i][j], i, j, lastIndex);
                if(lastIndex < 0) break;
                for(int k = j; k <= lastIndex; k++){
                    copyPaper[i][k] = paper[i][j];
                }
            }
        }
    }
    cout << result;
}
