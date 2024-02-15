#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, S, M;
    bool map[50][1001];
    int musics[51] = {0, };
    int curr = S;
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++){
        int music = 0;
        cin >> music;
        musics[i] = music;
    }
    
    map[0][S] = 1;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(map[i][j] == 1){
                int minus = j - musics[i+1];
                int plus = j + musics[i+1];
                if(plus <= M){
                    map[i+1][plus] = 1;
                }
                if(minus >= 0){
                    map[i+1][minus] = 1;
                }
            }
        }
    }
    bool flag = true;
    for(int i = M; i > 0; i--){
        if(map[N][i]){
            cout << i;
            flag = false;
            break;
        }
    };
    if(flag)  cout << -1;


    return 0;
}
