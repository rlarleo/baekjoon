#include <vector>
#include <iostream>
using namespace std;

int* results;

int main(void){
    int N, input;
    cin >> N;

    vector<int> vec;
    results = new int[N];

    for(int i = 0; i < N; i++){
        results[i] = 1;
    }


    for(int i = 0; i < N; i++){
        cin >> input;
        vec.push_back(input);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(vec[i] > vec[j]){
                results[i] = results[i] > (results[j]+1) ? results[i] : results[j]+1;
            }
            //cout << results[j] << " ";
        }
        //cout << endl;
    }
    int result = 0;
    for(int i = 0; i < N; i++){
        result = result < results[i] ? results[i] : result;
    }
    cout << result;


    delete results;


    return 0;
}
