#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> result;
    int preNum = 1;
    int N;
    int count = 0;
    cin >> N;
    result.push_back(0);
    for(int i = 1; i<=N; i++){
        int num = i;
        while(num % 5 == 0){
            num = num/5;
            count++;
        }
        result.push_back(count);
    }
    int index = 0;
    cout << result[N];

    return 0;
}
