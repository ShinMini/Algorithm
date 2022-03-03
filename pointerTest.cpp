#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(int nArgs, char ** vArgs)
{
    vector<int> *v = new vector<int>(10);
    v->at(2); //Retrieve using pointer to member
    v->operator[](2); //Retrieve using pointer to operator member
    v->size(); //Retrieve size
    vector<int> &vr = *v; //Create a reference
    vr[2]; //Normal access through reference
    delete &vr; //Delete the reference. You could do the same with
    //a pointer (but not both!)
}
