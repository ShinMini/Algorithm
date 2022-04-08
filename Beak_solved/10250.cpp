
#include <iostream>
#include <vector>

using namespace std;
void roomNumber(int H, int W, int T){
    int t;
    vector<int> room;
    room.resize(W*H+1);
    t=0;
    for (int w = 1; w<=W; w++)
    {
        for (int h = 1; h <= H; h++)
        {
            t++;
            room.at(t) = h*100 + w;
        }
    }
    cout << room.at(T)<<"\n";


}

int main()
{
    int N, H, W, T;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> H >> W >> T;
        roomNumber(H, W, T);
    }
    return 0;
}
