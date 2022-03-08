#include <iostream>
#include <vector>
#include <string> 


using namespace std;

int main(){
    std::vector<char> C(26);
    std::vector<int> A(26, -1); 
    std::vector<int> B(26);
    for(int i=0; i<26; i++) C.at(i) = 'a'+i;

    string S; 
    cin >> S; 
    int count=0;
    for(char num : S){
        for(int i=0; i<C.size(); i++){
            if(C[i] == num) {
                if(B[i] ==0){
                B[i] = 1;
                A[i] = count;
                }
            }
        }
        count++;
    }
    for(int i=0; i<C.size(); i++) cout << A[i] << " ";



    return 0;
}
