#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int N;
int numbers[11];
int operators[4]; // + - x /
int mymin = 1000000001;
int mymax = -1000000001;

void Dfs(int result, int index){
    if(index == N){
        if(result > mymax)
            mymax = result;
        if(result < mymin)
            mymin = result;
        return;
    }
   for(int i = 0; i < 4; i++)
    {
        if(operators[i] > 0)
        {
            operators[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
            if(i == 0)
                Dfs(result + numbers[index], index+1);
            else if(i == 1)
                Dfs(result - numbers[index], index+1);
            else if(i == 2)
                Dfs(result * numbers[index], index+1);
            else
                Dfs(result / numbers[index], index+1);
            operators[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> nums;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> operators[i];
    }

    Dfs(numbers[0], 1);

    cout << mymin << '\n' << mymax;


    return 0;
}