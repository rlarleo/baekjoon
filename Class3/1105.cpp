#include <iostream>
#include <vector>

using namespace std;

int result = 0;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string L, R;

    cin >> L >> R;
    if(!(L.length() != R.length())) {
        for(int i = 0; i < L.length(); i++){
            if(L[i] == R[i]){
                if(L[i] == '8')
                    result++;
            }
            else {
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}