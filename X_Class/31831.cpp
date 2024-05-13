#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    int stress = 0;
    int result = 0;

    cin >> N >> M;

    for(int i = 0 ; i < N; i++){
        int input;
        cin >> input;

        if(stress < -(input)){
            stress = 0;
        }
        else {
            stress += input;
        }
        if(stress >= M) result++;
    }

    cout << result;
    
}
