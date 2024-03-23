#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Shark
{
public:
    int id;
    pair<int, int> location;
    int speed;
    int direction; // 1(위), 2(아래), 3(오른쪽), 4(왼쪽)
    int size;
};
// R->y, C->x
int R, C, M;
int personIndex = 0;
int map[1001][1001] = {
    0,
};
vector<Shark> sharks;
vector<Shark> catchedSharks;

bool Cmp(const Shark &s1, const Shark &s2)
{
    return s1.location.first < s2.location.first;
}

void CatchShark(int index)
{
    sort(sharks.begin(), sharks.end(), Cmp);
    int index2 = 0;
    for (auto shark : sharks)
    {
        if (shark.location.second == index)
        {
            catchedSharks.push_back(shark);
            sharks.erase(sharks.begin() + index2);

            break;
        }
        index2++;
    }
}

void MoveShark()
{
    int newMap[1001][1001] = {
        0,
    };
    int index1 = 0;
    for (auto shark : sharks)
    {
        for (int i = 0; i < shark.speed; i++)
        {
            map[shark.location.first][shark.location.second] = 0;
            if (shark.direction == 1)
            {
                if (shark.location.first == 1)
                {
                    map[shark.location.first + 1][shark.location.second] = shark.id;
                    shark.location.first = shark.location.first + 1;
                    shark.direction = 2;
                }
                else
                {
                    map[shark.location.first - 1][shark.location.second] = shark.id;
                    shark.location.first = shark.location.first - 1;
                }
            }
            else if (shark.direction == 2)
            {
                if (shark.location.first == R)
                {
                    map[shark.location.first - 1][shark.location.second] = shark.id;
                    shark.location.first = shark.location.first - 1;
                    shark.direction = 1;
                }
                else
                {
                    map[shark.location.first + 1][shark.location.second] = shark.id;
                    shark.location.first = shark.location.first + 1;
                }
            }
            else if (shark.direction == 3)
            {
                if (shark.location.first == C)
                {
                    map[shark.location.first][shark.location.second - 1] = shark.id;
                    shark.location.second = shark.location.second - 1;
                    shark.direction = 4;
                }
                else
                {
                    map[shark.location.first][shark.location.second + 1] = shark.id;
                    shark.location.second = shark.location.second + 1;
                }
            }
            else if (shark.direction == 4)
            {
                if (shark.location.first == 0)
                {
                    map[shark.location.first][shark.location.second + 1] = shark.id;
                    shark.location.second = shark.location.second + 1;
                    shark.direction = 3;
                }
                else
                {
                    map[shark.location.first][shark.location.second - 1] = shark.id;
                    shark.location.second = shark.location.second - 1;
                }
            }
        }
        if (newMap[shark.location.first][shark.location.second] != 0)
        {
            int index2 = 0;
            for (auto shark2 : sharks)
            {
                if (shark2.id != shark.id && shark2.location.first == shark.location.first && shark2.location.second == shark.location.second)
                {
                    if (shark2.size > shark.size)
                    {
                        sharks.erase(sharks.begin() + index1);
                    }
                    else
                    {
                        sharks.erase(sharks.begin() + index2);
                    }
                }
                index2++;
            }
        }
        index1++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++)
    {
        Shark input;
        input.id = i;
        cin >> input.location.first >> input.location.second >> input.speed >> input.direction >> input.size;
        map[input.location.first][input.location.second] = i;
        sharks.push_back(input);
    }
    for (int i = 0; i < C; i++)
    {
        CatchShark(i);
        MoveShark();
    }
    int result = 0;
    for (auto s : catchedSharks)
    {
        result += s.size;
    }

    cout << result;

    return 0;
}
