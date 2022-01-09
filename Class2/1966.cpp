#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int C, N, M;
    cin >> C;
    for(int i = 0; i < C; i++){
        queue<pair<int, int>> que;
        priority_queue<int> pq;
        cin >> N >> M;
        for(int j = 0; j < N; j++){
            int num;
            cin >> num;
            que.push(make_pair(j, num));
            pq.push(num);
        }
        int result = 1;
        while(true){

            if(pq.top() == que.front().second) {
                if(que.front().first == M) break;
                que.pop();
                pq.pop();
                result++;
            }
            else{
                que.push(que.front());
                que.pop();
            }
        }
        cout << result << '\n';
    }

    return 0;
}
