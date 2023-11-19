#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int T, N;


int calc(string a, string b){
    int result = 0;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]) result++;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string input;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        vector<string> mbtis;
        for(int j = 0; j < N; j++){
            cin >> input;
            mbtis.push_back(input);
        }
        int flag = 0;
        int result = 12;
        for(int j = 0; j < N; j++){
            for(int k = j+1; k < N; k++){
                for(int l = k+1; l < N; l++){
                    int curr = 0;
                    curr += calc(mbtis[j], mbtis[k]);
                    curr += calc(mbtis[j], mbtis[l]);
                    curr += calc(mbtis[k], mbtis[l]);
                    result = result > curr ? curr : result;
                    if(curr == 0) {
                        flag = 1;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
        }
        cout << result << endl;
    }



    return 0;
}
