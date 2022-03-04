#include <iostream>


using namespace std;

pair<int, int> tree[27];

void preOrder(int current){
    if(current == -19) return;
    cout << (char)(current + 'A');
    preOrder(tree[current].first);
    preOrder(tree[current].second);
}

void inOrder(int current){
    if(current == -19) return;
    inOrder(tree[current].first);
    cout << (char)(current + 'A');
    inOrder(tree[current].second);
}

void postOrder(int current){
    if(current == -19) return;
    postOrder(tree[current].first);
    postOrder(tree[current].second);
    cout << (char)(current + 'A');
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    while(N--){
        char a, b, c;
        cin >> a >> b >> c;
        // -19 == '.'
        tree[a-'A'].first = b-'A';
        tree[a-'A'].second = c-'A';
    }
    preOrder(0); cout << endl;
    inOrder(0); cout << endl;
    postOrder(0);

    return 0;
}
