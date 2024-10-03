#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int number = 1000000;
vector<bool> isNotPrime(1000000);

	 
void PrimeChk(){
    for(int i = 2; i*i<=number; i++){
        if(isNotPrime[i]==0){
            for(int j = i*i; j<=number; j+=i){
                isNotPrime[j] = 1;
            }
        }
        
    }
}
 


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    PrimeChk();
    int input;
    while(true){
        cin >> input;
        if(input == 0) break;

        for(int i = 3; i < number; i++){
            if(!isNotPrime[i] && !isNotPrime[input - i]){
                cout << input << " = " << i << " + " << input - i << '\n';
                break;
            }
        }

    }



    return 0;
}
