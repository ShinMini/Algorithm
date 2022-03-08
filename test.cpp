#include <iostream>
#include <cmath>

using namespace std;

int Decimal(size_t T){
    int count=0, N;
    if(T==1) {
        cout<<1<<"\n";
        return 0;
    }

    N=ceil(sqrt(2*T));
    for(size_t t=2; t<=N; t++) {
        if(N%t==0 && N!=t) break;
        if(t==N){
            count++;
            break;
        }
    }
    N=ceil(sqrt(T));
    for(size_t t=2; t<=N; t++) {
        if(N%t==0 && N!=t) break;
        if(N==N){
            count--;
            break;
        }
    // 이러지말고 2T에서 T값을 빼자 ..
}
cout << count << "\n";
return 0;
}
int main(){
    size_t T;
    while(true){
        cin>>T;
        if(T == 0) break;
        Decimal(T);
    }

    return 0;
}
