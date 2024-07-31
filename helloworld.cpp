#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdlib.h>

using namespace std;

int N, L, R;
int graph[50][50];
int tempGraph[50][50];
bool visited[50][50] = {
    0,
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void InitVisited()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
}

bool IsValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N);
}

bool IsOpen(int x, int y, int a, int b)
{
    int distance = abs(graph[y][x] - graph[b][a]);
    return (distance >= L && distance <= R);
}

int Bfs(int y, int x)
{
    int sum = graph[y][x];
    vector<pair<int, int>> visitedPoint;
    visitedPoint.push_back({y, x});

    visited[y][x] = 1;
    queue<pair<int, int>> que;
    que.push({y, x});
    while (!que.empty())
    {
        int curr_y = que.front().first;
        int curr_x = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];
            if (IsValid(next_x, next_y) && !visited[next_y][next_x] && IsOpen(curr_x, curr_y, next_x, next_y))
            {
                visited[next_y][next_x] = 1;
                que.push({next_y, next_x});
                visitedPoint.push_back({next_y, next_x});
                sum += graph[next_y][next_x];
            }
        }
    }

    int newInput = sum / visitedPoint.size();
    for (auto p : visitedPoint)
    {
        tempGraph[p.first][p.second] = newInput;
    }

    return visitedPoint.size() - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> L >> R;

    int input;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            graph[i][j] = input;
        }
    }

    int day = 0;
    while (true)
    {
        int move = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    move += Bfs(i, j);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                graph[i][j] = tempGraph[i][j];
            }
        }
        if (move == 0)
            break;
        InitVisited();
        day++;
    }

    cout << day;

    // test
}
