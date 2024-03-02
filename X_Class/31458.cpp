#include <iostream>


using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        string input;
        cin >> input;
        int preCount = 0;
        int postCount = 0;
        char N = 0;
        bool yet = true;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '!'){
                if(yet) preCount ++;
                else postCount ++;
            } 
            else{
                N = input[i];
                yet = false;
            }
        }
        if(postCount > 0) N = '1';

        if((preCount % 2) == 0) cout << N << '\n';
        else if(N == '0') cout << '1' << '\n';
        else cout << '0' << '\n';
    }


    return 0;
}
