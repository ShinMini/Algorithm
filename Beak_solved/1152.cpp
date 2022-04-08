#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main(){
    string s;
    int count=1;
    int number=1;
    char delimiter = ' ';

    getline(cin, s);

    for(char num : s){ if(number != 1 && number != s.size()){ if(num == delimiter) count++; } number++; }
    if(s.size() ==0) count =0;
    cout << count;
    return 0;
}
