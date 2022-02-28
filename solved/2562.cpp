#include <iostream>
#include <vector> 

using namespace std;

int main()
{

    int arr[9];
    int Max=1;  // 들어오는 9개의 자연수 이므로 초깃값 0으로 지정
    int index;

    for(int i=0; i<9; i++){
        cin >> arr[i];

        if(arr[i] > Max) {
            Max=arr[i];
            index = i+1;
        }
    }
        cout << Max << "\n" << index;
        return 0;
}
