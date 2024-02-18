#include <iostream>
#include <vector>
using namespace std; 

int main(int argc, char *argv[]) 
{ 
    unsigned int count = 0;     // 1씩 증가하면서 제곱값 확인
    unsigned int monkey, dog;     // 원숭이, 강아지 키
    unsigned int key;     // 강아지 - 원숭이 키
    count = 0; 
    cin >> monkey >> dog; 
    key = dog - monkey; 
    if (key < 1) {     // 키차이가 1보다 작은 경우
        cout << 0; 
        return 0; 
    } 
    while (count * count < key) {     // 제곱값이 키차이값 보다 작으면 반복
        ++count; 
    } 
    if (count * count - count < key) {     // 설명 참고
        cout << count * 2 - 1; 
    }     
    else { 
        cout << count * 2 - 2;     // 설명 참고
    } 
    return 0; 
}