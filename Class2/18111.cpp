#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M, height;
    long long B;
    int startHeight = 501;
    int endHeight = 0;
    int resultTime = INT_MAX;
    int resultHeight = 0;
    vector<int> heights;

    cin >> N >> M >> B;

    for(int i = 0; i < N*M; i++) {
        cin >> height;
        heights.push_back(height);
        if(height < startHeight) startHeight = height;
        if(height > endHeight) endHeight = height;
    }

    for(int i = startHeight; i <= endHeight; i++){
        int time = 0;
        bool over = false;
        int inven = B;

        for(auto h : heights){
            if(h == i) continue;
            else if(h > i){
                time = time + (h-i)*2;
                inven = inven + (h-i);
            } else if (h < i) {
                time = time + (i-h);
                inven = inven - (i-h);
            }
        }
        if(inven >= 0 && time <= resultTime) {
            resultTime = time;
            resultHeight = i;
        }
    }

    cout << resultTime << ' ' << resultHeight;


    return 0;
}
