#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long M = 1234567891;
    long long N;
    long long sum = 0;
    string word;
    cin >> N >> word;

    for(long long i = 0; i<N; i++){
        long long intWord = (long long)(word[i] - 'a') + 1;
        long long R = 1;
        for(int j = 1; j<=i; j++){
            R *= 31;
            if(R > M)
                R = R % M;
        }
        sum += intWord * R;
        if(sum > M)
            sum = sum % M;
    }
    cout << sum;
}
