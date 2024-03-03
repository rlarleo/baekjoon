#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int T, N, input, result;
pair<int, int> startPoint, endPoint;

void Swap(pair<int, int> a, pair<int, int> b)
{
    if(a.first > b.first){
        pair<int, int> temp;
        temp = startPoint;
        startPoint = endPoint;
        endPoint = temp;
    }
}

int MaxCurrentI(int i, vector<int> vec1, vector<int> vec2)
{
    int result = 0;
    if(i < 0 || i >= N) return result;
    result = max(max(vec1[i], vec2[i]), vec1[i] + vec2[i]);
    if(result < 0) result = 0;
    return result;
}

int CalcRight2(pair<int, int> a, vector<int> vec1, vector<int> vec2)
{
    int maxRight = 0;
    int startData = 0;
    int plus = 0;
        
    if(a.first + 1 < N){
        maxRight = MaxCurrentI(a.first + 1, vec1, vec2);
    }

    for(int i = a.first + 1; i < N; i ++){
        plus += (vec1[i] + vec2[i]);
        maxRight = max(maxRight, MaxCurrentI(i + 1, vec1, vec2) + plus);
    }
    if((maxRight + startData) > 0) return (maxRight + startData);
    else return 0;
}

int CalcLeft2(pair<int, int> a, vector<int> vec1, vector<int> vec2)
{
    int maxLeft = 0;
    int startData = 0;
    int plus = 0;
    
    if(a.first - 1 >= 0){
        maxLeft = MaxCurrentI(a.first - 1, vec1, vec2);
    }
    
    for(int i = a.first - 1; i >= 0; i --){
        plus += (vec1[i] + vec2[i]);
        maxLeft = max(maxLeft, MaxCurrentI(i - 1, vec1, vec2) + plus);
    }
    if((maxLeft + startData) > 0) return (maxLeft + startData);
    else return 0;
}

int CalcLeft(pair<int, int> a, vector<int> vec1, vector<int> vec2)
{
    int maxLeft = 0;
    int startData = 0;
    int plus = 0;
    if(a.second == 0)
        startData = vec2[a.first];
    else 
        startData = vec1[a.first];
    
    if(a.first - 1 >= 0){
        maxLeft = MaxCurrentI(a.first - 1, vec1, vec2);
    }
    
    for(int i = a.first - 1; i >= 0; i --){
        plus += (vec1[i] + vec2[i]);
        maxLeft = max(maxLeft, MaxCurrentI(i - 1, vec1, vec2) + plus);
    }
    if((maxLeft + startData) > 0) return (maxLeft + startData);
    else return 0;
}

int CalcRight(pair<int, int> a, vector<int> vec1, vector<int> vec2)
{
    int maxRight = 0;
    int startData = 0;
    int plus = 0;
    if(a.second == 0)
        startData = vec2[a.first];
    else 
        startData = vec1[a.first];
        
    if(a.first + 1 < N){
        maxRight = MaxCurrentI(a.first + 1, vec1, vec2);
    }

    for(int i = a.first + 1; i < N; i ++){
        plus += (vec1[i] + vec2[i]);
        maxRight = max(maxRight, MaxCurrentI(i + 1, vec1, vec2) + plus);
    }
    if((maxRight + startData) > 0) return (maxRight + startData);
    else return 0;
}

int Direct(vector<int> vec1, vector<int> vec2){
    int result = 0;
    if(startPoint.second == 0)
        result += vec1[startPoint.first];
    else 
        result += vec2[startPoint.first];
    if(endPoint.second == 0)
        result += vec1[endPoint.first];
    else 
        result += vec2[endPoint.first];
        
    for(int i = startPoint.first + 1; i < endPoint.first; i++){
        if(vec1[i] > 0) result += vec1[i];
        if(vec2[i] > 0) result += vec2[i];
        if(vec1[i] < 0 && vec2[i] < 0) result += max(vec1[i], vec2[i]);
    }


    return result;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> T;
    for(int t = 0; t < T; t++){
        vector<int> vec1;
        vector<int> vec2;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> input;
            vec1.push_back(input);
        }
        for(int i = 0; i < N; i++){
            cin >> input;
            vec2.push_back(input);
        }
        cin >> input;
        startPoint.first = input - 1;
        cin >> input;
        startPoint.second = input - 1;
        cin >> input;
        endPoint.first = input - 1;
        cin >> input;
        endPoint.second = input - 1;
        if(startPoint.first == endPoint.first){
            
            cout << max(CalcLeft2(startPoint, vec1, vec2), CalcRight2(startPoint, vec1, vec2)) + vec1[startPoint.first] + vec2[startPoint.first];
        }
        else{
            Swap(startPoint, endPoint);
            result = CalcLeft(startPoint, vec1, vec2) + CalcRight(endPoint, vec1, vec2) + Direct(vec1, vec2); 
            cout << result;
        }

    }


    return 0;
}
