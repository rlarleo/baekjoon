#include <iostream>
#include <vector>

using namespace std;

vector<bool> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    int s, k;
    cin >> s;

    for(int i = 0; i < s; i++){
        int input;
        cin >> input;
        vec.push_back(input);
    }
    cin >> k;

    for(int i = 0; i < k; i++){
        int gender, index;
        cin >> gender >> index;
        index = index - 1;
        if(gender == 1){
            for(int j = index; j < s; j = j + index + 1){
                vec[j] = !vec[j];
            }
        }
        else{
            int move = 0;
            vec[index] = !vec[index];
            while(true){
                move++;
                int left = index - move;
                int right = index + move;
                if(left < 0 || right >= s) break;
                if(vec[left] == vec[right]){
                    vec[left] = !vec[left];
                    vec[right] = !vec[right];
                }
                else break;
            }
        }
    }
    int count = 0;
    for(auto v : vec){
        count ++;
        cout << v << ' ';
        if(count >= 20){
            cout << '\n';
            count = 0;
        }
    }

}
