#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
 * n 개의 퍼즐을 제한 시간 내에 풀어야 한다
 * 각 퍼즐은 난이도와 소요시간이 정해져 있다
 * 숙련도에 따라 퍼즐을 풀 때 틀리는 횟수가 바뀐다
 *
 * diff <= level : time_cur 만큼
 * diff > level : diff - level 만큼 틀리고, 틀릴때 마다 time_cur 만큼을 추가로 소모
 *                  + 이전 퍼즐을 모두 풀고 와야 한다 (이때는 틀리지 않음)
 * 이전 퍼즐을 다시 풀 때는 난이도에 상관 없이 틀리지 않음
 *
 */

bool possible(int level, vector<int> &diffs, vector<int> &times, ll limit)
{

    ll current_time = 0;
    ll prev_time = 0;

    for (int i = 0; i < diffs.size(); i++)
    {
        if (level >= diffs[i])
        {
            current_time += times[i];
        }
        else
        {
            ll repeat = diffs[i] - level;
            current_time += times[i] + (times[i] + prev_time) * repeat;
        }
        prev_time = times[i];
        if (current_time > limit)
            return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit)
{

    int l = 1;
    int r = 200000;
    int ans = INT_MAX;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (possible(mid, diffs, times, limit))
        {
            r = mid - 1;
            ans = min(mid, ans);
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}