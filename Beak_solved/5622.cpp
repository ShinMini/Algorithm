#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t rowSize = 10;
    size_t columnSize = 4;
    char arr[rowSize][columnSize] = { 0 };
    char alpabet = 'A';

    for(size_t i=2; i<rowSize; i++){
        for(size_t t=0; t<columnSize-1; t++){
            arr[i][t] = alpabet;
            alpabet++;
        }
    }
    arr[7][3] = 'S';
    arr[9][3] = 'Z';

//    for(size_t i=2; i<rowSize; i++){
//        for(size_t t=0; t<columnSize; t++){
//            cout << i << "   " << t << " ";
//            cout << arr[i][t] << "\n ";
//        }}
//    cout << "---------------------" <<"\n";
    string S;
    cin >> S;

    size_t result = 0;
    for( char C : S )
    {
        for(size_t i=2; i<rowSize; i++){
            for(size_t t=0; t<columnSize; t++){
                if(arr[i][t] == C){
                    result += i+1;
                    //cout << "i : " << i <<" , t : " << t <<" , result : " << result << "\n";
                }
            }
        }
    }
    cout << result;

    return 0;
}
