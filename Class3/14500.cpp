#include <iostream>
using namespace std;

int arr[501][501] = {0, };

int main() {
   ios_base::sync_with_stdio(0);cin.tie(0);

   int result = 0;
   int sum = 0;
   int N,M;
   cin >> N >> M;

   for(int i = 0; i < N; i++){
       for(int j = 0; j < M; j++){
            cin >> arr[i][j];
       }
   }
   int x[5] = {0, 3, 1, 1, 2};
   int y[5] = {3, 0, 1, 2, 1};

   for(int k = 0; k < 5; k++){
        for(int i = 0; i < N - x[k]; i++){
            for(int j = 0; j < M - y[k]; j++){
                if(k == 0){
                    sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
                    result = result < sum ? sum : result;
                }
                else if(k == 1){
                    sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
                    result = result < sum ? sum : result;
                }
                else if(k == 2){
                    sum = arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1];
                    result = result < sum ? sum : result;
                }
                else if(k == 3){
                    sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];
                    result = result < sum ? sum : result;
                    sum = arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j];
                    result = result < sum ? sum : result;

                    sum = arr[i][j+1] + arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
                    result = result < sum ? sum : result;

                    sum = arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i][j+2] + arr[i][j+1] + arr[i+1][j+1];
                    result = result < sum ? sum : result;
                }
                else if(k == 4){
                    sum = arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+2][j];
                    result = result < sum ? sum : result;

                    sum = arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j];
                    result = result < sum ? sum : result;
                    sum = arr[i][j]  + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
                    result = result < sum ? sum : result;

                    sum =  arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
                    result = result < sum ? sum : result;
                    sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j];
                    result = result < sum ? sum : result;
                }
            }
        }
   }
   cout << result;

   return 0;
}
