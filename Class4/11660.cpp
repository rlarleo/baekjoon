#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, M, input;
int graph[1026][1026];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j =1; j <= N; j++){
            cin >> input;
            graph[i][j] = graph[i][j-1] + input;
        }
    }

    for(int i = 0; i < M; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        for(int i = x1; i <= x2; i++){
            result += graph[i][y2] - graph[i][y1-1];
        }
        cout << result << '\n';
    }

    return 0;
}
