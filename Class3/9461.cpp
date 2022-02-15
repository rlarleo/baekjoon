#include <iostream>
#include <vector>
using namespace std;
vector<long long> vec;

void init(){
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(9);
}

int main()
{
    init();
    int T, N;
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;

        for(int i = 11; i <= N; i++){
            if(vec.size() <= i)
                vec.push_back(vec[i-1] + vec[i-5]);
        }
        cout << vec[N] << '\n';
    }



    return 0;
}
