#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string map[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            string input;
            cin >> input;
            map[i][j] = input;
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        if (map[i][0] == map[i][1] &&
            map[i][0] == map[i][2] &&
            map[i][0] == map[i][3] &&
            map[i][0] == map[i][4] &&
            map[i][0] == map[i][5] &&
            map[i][0] == map[i][6] &&
            map[i][0] == map[i][7] &&
            map[i][0] == map[i][8] &&
            map[i][0] == map[i][9])
        {
            result++;
        }
        if (map[0][i] == map[1][i] &&
            map[0][i] == map[2][i] &&
            map[0][i] == map[3][i] &&
            map[0][i] == map[4][i] &&
            map[0][i] == map[5][i] &&
            map[0][i] == map[6][i] &&
            map[0][i] == map[7][i] &&
            map[0][i] == map[8][i] &&
            map[0][i] == map[9][i])
        {
            result++;
        }
    }
    result = result > 0 ? 1 : 0;
    cout << result;
    return 0;
}
