#include <iostream>
#include <string> 
#include <vector> 

using namespace std;

int flip(size_t T){
    size_t result;
    result = T%10*100 + (T/10)%10*10 + (T/100);

    return result;
}
int main(){

    size_t N1, N2;
    cin >> N1 >> N2;

    if(flip(N1)>flip(N2)) cout << flip(N1);
    else cout << flip(N2);


    return 0; 
}
