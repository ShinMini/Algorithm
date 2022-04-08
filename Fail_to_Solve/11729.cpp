#include <iostream>
using namespace std;
 
void 1to3();
void 2to3();
void 2to1();
void 3to2();
void after();
void move(int);
void print(int);
int count=0;

int main(){
    int N;
    cin >> N;
    move(N);
    cout<< count;

    return 0;
}
void 1to3(){ // platform 1에 있는 3층탑 platform 3로 이동
    cout <<1<<" "<<3<<"\n";
    cout <<1<<" "<<2<<"\n";
    cout <<3<<" "<<2<<"\n";
    cout <<1<<" "<<3<<"\n";
    cout <<2<<" "<<1<<"\n";
    cout <<2<<" "<<3<<"\n";
    cout <<1<<" "<<3<<"\n";
    count +=7;
}

void 3to2(){ // platform 3에있는 3층탑 2로 이동.
    cout <<3<<" "<<2<<"\n";
    cout <<3<<" "<<1<<"\n";
    cout <<2<<" "<<1<<"\n";
    cout <<3<<" "<<2<<"\n";
    cout <<1<<" "<<3<<"\n";
    cout <<1<<" "<<2<<"\n";
    cout <<3<<" "<<1<<"\n";
    count +=7;
}
void 2to1(){ // platform 2에 있는 3층탑 platform 1으로 이동. 
    cout <<2<<" "<<1<<"\n";
    cout <<2<<" "<<3<<"\n";
    cout <<1<<" "<<3<<"\n";
    cout <<2<<" "<<1<<"\n";
    cout <<3<<" "<<2<<"\n";
    cout <<3<<" "<<1<<"\n";
    cout <<2<<" "<<1<<"\n";
    count +=7;
}
void 2to3(){ // platform 2에 있는 3층탑 platform 3으로 이동. 
    cout <<2<<" "<<3<<"\n";
    cout <<2<<" "<<1<<"\n";
    cout <<3<<" "<<1<<"\n";
    cout <<2<<" "<<3<<"\n";
    cout <<1<<" "<<2<<"\n";
    cout <<1<<" "<<3<<"\n";
    cout <<2<<" "<<1<<"\n";
    count +=7;
}

// floor값이 짝수일경우, plat2로 움직여줘야함. 
// floor값이 홀수일 경우, plat1로 움직여줘야함. 
void print(int N){
    int Plus = (N-5)/2;
    int T=N%2;

    move(T); 
    for(int i=0; i<addPlus; i++){
        after(Plus);
    }
    move(T);
}
void move(int T){
    if(T==0){
        1to2();
        cout <<1<<" "<<3<<"\n";
        2to3();
        count++;
    }
    if(T==1){
        1to3();
        cout <<1<<" "<<2<<"\n";
        3to2();

        cout<<1<<" "<<3<<"\n";

        2to1();
        cout<<2<<" "<<3<<"\n";
        1to3();

        count+=3;
    }
}
void after(){
        cout <<1<<" "<<2<<"\n";
        3to1();
        cout <<3<<" "<<2<<"\n";
        1to2();

        cout<<1<<" "<<3<<"\n";
        2to3();
        cout<<2<<" "<<1<<"\n";
        3to1();
        count+=4;
}
