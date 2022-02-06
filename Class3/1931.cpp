#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, start, end;
    vector<pair<int, int>> times;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> start >> end;
        times.push_back(pair<int, int>(end, start));
    }

    sort(times.begin(), times.end());

    int lastTime = 0;
    int result = 0;

    for(auto t : times){
        if(t.second >= lastTime) {
            lastTime = t.first;
            result ++;
        }
    }

    cout << result;
    return 0;
}
