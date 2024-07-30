#include <iostream>
#include <cmath>

using namespace std;

int graph[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dx2[4] = {0, -1, 0, 1};
int dy2[4] = {1, 0, -1, 0};
int N, M;
int result = 1;


class Machine
{
    public:
        int x;
        int y;
        int direction;
};


bool IsValid(int x, int y){
    return (x >= 0 && y >= 0 && x < M && y < N);
}

int main()
{
    cin >> N >> M;
    Machine machine;

    cin >> machine.x  >> machine.y >> machine.direction;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int input;
            cin >> input;
            graph[i][j] = input;
        }
    }
    graph[machine.y][machine.x] = 1;
    

    while(true){
        bool isMove = false;
        for(int i = 0; i < 4; i ++){
            int next_x = machine.x + dx[(i + (4 - machine.direction)) % 4];
            int next_y = machine.y + dy[(i + (4 - machine.direction)) % 4];
            if(IsValid(next_x, next_y) && graph[next_y][next_x] == 0){
                machine.x = next_x;
                machine.y = next_y;
                machine.direction = ( machine.direction + 3) % 4;
                graph[next_y][next_x] = 1;
                isMove = true;
                result ++;
                break;
            }
        }
        
        if(!isMove){
            bool canMove;
            int next_x = machine.x + dx2[machine.direction];
            int next_y = machine.y + dy2[machine.direction];
            machine.x = next_x;
            machine.y = next_y;
            if(!IsValid(next_x, next_y)){
                break;
            }
        }
    }
    cout << result;

}