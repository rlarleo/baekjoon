#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stdlib.h>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> pointers;
    vector<pair<string, pair<int,int>>> cmds;
    int N, M, Q;

    cin >> N >> M >> Q;


    for(int i = 0; i < M; i++){
        int input;
        cin >> input;
        pointers.push_back(input);
    }
    for(int i = 0; i < Q; i++){
        string cmd;
        int a, b = 0;
        cin >> cmd;
        if(cmd == "assign" || cmd == "swap"){
            cin >> a >> b;
        }
        else{
            cin >> a;
        }
        cmds.push_back({cmd, {a, b}});
    }

    for(auto cmd : cmds){
        if(cmd.first ==  "assign"){
            pointers[cmd.second.first-1] =  pointers[cmd.second.second-1];
        }
        else if(cmd.first == "swap"){
            int tmp = pointers[cmd.second.first-1];
            pointers[cmd.second.first-1] =  pointers[cmd.second.second-1];
            pointers[cmd.second.second-1] = tmp;
        }
        else{
            pointers[cmd.second.first-1] = 0;
        }
    }
    set<int> sets;

    for(auto pointer : pointers){
        if(pointer != 0) sets.insert(pointer);
    }
    cout << sets.size() << '\n';
    for (auto s : sets) {
		cout << s << '\n';
	}



    return 0;
}