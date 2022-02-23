#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string channel;
    int N, x;
    int xButton[10];

    cin >> channel >> N;

    for(int i = 0; i < N; i++){
        cin >> x;
        xButton[x] = 1;
    }

    int digit = channel.size() - 1;
    for(int i = 0; i < channel.size(); i++){

    }


    return 0;
}
