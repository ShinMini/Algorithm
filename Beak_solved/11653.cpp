#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    size_t T;
    cin>>T;

    for(int i=2; i<=T; i++){
        while(!(T%i)){
            cout << i<<"\n";
            T/=i;
        }
    }
    return 0;
}
