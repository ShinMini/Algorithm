#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

// std::string::nops => -1을 가지는 상수

int main() {
<<<<<<< HEAD
=======
    ios_base::sync_with_stdio(false); cin.tie(0);
>>>>>>> 0a8932dc325dc96837fa7bb06808877c190356d5

    std::string s = "hello mini is it good?";
    std::string delimiter = " "; 

    std::size_t pos =0;
    std::string token;

    while((pos = s.find(delimiter)) != -1) {
        token = s.substr(0, pos);
        std::cout <<token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << "s: " << s <<"\n";


return 0;
}
/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    string hi = "hi there" ;

    string hello[3] = {"first", "second", "third"};

    string *ptr2;
    string *ptr3;

    ptr2 = &hello[0];

    ptr3 = &hello[1];

    cout <<"hello: " << hello<<"\n";

    cout <<"hello[0]: " << hello[0]<<"\n";
    cout <<"hello[1]: " << hello[1]<<"\n";

    cout <<"*ptr2: " << *ptr2 << "\n";
    cout <<"&ptr2: " << &ptr2 << "\n";

    cout <<"&ptr3: " << &ptr3 << "\n";
    cout <<"*ptr3: " << *ptr3 << "\n";

    return 0;
}

*/
