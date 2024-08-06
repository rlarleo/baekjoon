#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Medal
{
    int nation;
    int gold;
    int silver;
    int bronze;
};

bool Cmp(const Medal &m1, const Medal &m2)
{
    if (m1.gold != m2.gold)
        return m1.gold > m2.gold;
    if (m1.silver != m2.silver)
        return m1.silver > m2.silver;
    if (m1.bronze != m2.bronze)
        return m1.bronze > m2.bronze;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    int nation, gold, silver, bronze;
    int resultGold, resultSilver, resultBronze;
    vector<Medal> nations;
    for (int i = 0; i < N; i++)
    {
        cin >> nation >> gold >> silver >> bronze;
        Medal medal;
        medal.nation = nation;
        medal.gold = gold;
        medal.silver = silver;
        medal.bronze = bronze;
        nations.push_back(medal);
        if (nation == K)
        {
            resultGold = gold;
            resultSilver = silver;
            resultBronze = bronze;
        }
    }
    sort(nations.begin(), nations.end(), Cmp);

    for (int i = 0; i < N; i++)
    {
        if (nations[i].gold == resultGold && nations[i].silver == resultSilver && nations[i].bronze == resultBronze)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}
