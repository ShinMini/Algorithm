#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main(){
    // a = 97, z = 122,  Z = 90, A= 65;  => Z+7 = 'a' 
    // alpa => 0~25(a~z), 26~50(A~Z)
    vector<char> alpa(52);
    vector<std::size_t> count(52);
    for(int i=0; i<alpa.size(); i++){
        if(i<26) alpa.at(i)=(97+i);
        else alpa.at(i)=(39+i);
    }

    string s;
    cin >> s;
    for(char num : s){

        for(int i=0; i<alpa.size(); i++){
            if( num == alpa.at(i)) {
                if(i<26) count.at(i)++;
                else count.at(i-26)++;
            }
        }
    }

    size_t result = 0;
    size_t max=0, sum = 0;
    for(int i=0; i<count.size(); i++){ 
        if(count[i]>=max){ 
        max = count[i];
        result = i;
    }}
    for(int i=0; i<count.size(); i++){ if(max == count[i]) sum++; }

    if(sum==1) cout << alpa[result + 26];
    else cout <<"?";


    return 0;
}
