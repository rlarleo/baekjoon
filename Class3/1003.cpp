#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> zero;
vector<int> one;


int main()
{
    int N;
    int maxN = 0;
    cin >> N;
    vector<int> arr;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
        if(maxN < n){
            maxN = n;
        }
    }
    vector<int> fibonacci;
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    fibonacci.push_back(2);
    for(int i = 1; i < maxN-2; i++){
        fibonacci.push_back(fibonacci[i] + fibonacci[i+1]);
    }
    for(auto a : arr){
        if(a == 0) cout << "1 0\n";
        else if(a == 1) cout << "0 1\n";
        else if(a == 2) cout << "1 1\n";
        else{
            cout << fibonacci[a-2] << " " << fibonacci[a-1] << '\n';
        }
    }

    return 0;
}
