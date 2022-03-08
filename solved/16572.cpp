#include <iostream>

using namespace std;

int mainArray[2000][2000]{};

void countPixel(int A, int B, int C){
    int B_length = C;

    for(int i=0; i<C; i++){ 
        for(int t=0; t<B_length; t++){ //
            mainArray[i+A][t+B] =1;
        }
        B_length--;
    }
}

int main(){
    int N, A, B, C;
    cin>>N;
    for(int i=0; i<N; i++){
        cin >> A >> B >> C;
        countPixel(A, B, C);
    }
    size_t R=0;
    for(int i=0; i<2000; i++){ for(int t=0; t<2000; t++){
            if(mainArray[i][t] ==1) R++; 
        }
    }
    cout <<R;

    return 0;
}
