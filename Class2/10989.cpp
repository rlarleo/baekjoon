#include <iostream>

using namespace std;
int N, num;
/*
void QuickSort(int* vec, int left, int right){
    if(left >= right) return;
    int pivot = left;
    int i = left+1;
    int j = right;
    while(i <= j){
        while(i <= right && vec[i] <= vec[pivot]){
            i++;
        }
        while(j > left && vec[j] >= vec[pivot]){
            j--;
        }
        if(i > j){
            int temp = vec[j];
            vec[j] = vec[pivot];
            vec[pivot] = temp;
        } else {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }

    }

    QuickSort(vec, left, j-1);
    QuickSort(vec, j+1, right);
}*/

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    int arr[10001] = {0, };
    int idx;

    for(int i = 0; i < N; i++){
        cin >> idx;
        arr[idx]++;
    }

    for(int i = 0; i < 10001; i++){
        if(arr[i] != 0){
            for(int j = 0; j < arr[i]; j++){
                cout << i << '\n';
            }
        }
    }
    return 0;
}
