#include <iostream>
#include <vector>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string problem;
    vector<int> plus;
    vector<int> minus;
    int flagNum = 0;
    bool firstMinus = false;
    cin >> problem;

    for(int i = 0; i < problem.length(); i++){
        if(!firstMinus && (problem[i] == '+' ||  problem[i] == '-') ){ // 처음 마이너스를 만나지 않고 플러스를 만남
            plus.push_back(stoi(problem.substr(flagNum, i)));
            flagNum = i+1;
        }
        else if(firstMinus && (problem[i] == '+' || problem[i] == '-') ){
            minus.push_back(stoi(problem.substr(flagNum, i)));
            flagNum = i+1;
        }
        if(problem[i] == '-') firstMinus = true;
    }
    if(!firstMinus){
        plus.push_back(stoi(problem.substr(flagNum, problem.length())));
    }
    else{
        minus.push_back(stoi(problem.substr(flagNum, problem.length())));
    }

    int result = 0;
    for(auto p : plus){
        //cout << "p: " << p;
        result = result + p;
    }
    for(auto m : minus){
        //cout << "m: " << m;
        result = result - m;
    }
    cout << result;

    return 0;
}
