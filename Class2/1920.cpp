#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<bool> resultVec;
bool result = false;

void myFind(int start, int end, int num){
    if(start > end) {result = false; return;}
    else{
        int mid = (end + start + 1)/2;
        if(vec[mid] == num) {result = true; return;}
        else if(vec[mid] < num) myFind(mid+1, end, num);
        else if(vec[mid] > num) myFind(start, mid-1, num);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        myFind(0, N-1, num); // 시간초과
        // auto it = find(vec.begin(), vec.end(), num); // 시간초과
        if(result) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
