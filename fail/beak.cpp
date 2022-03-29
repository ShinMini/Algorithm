#include <iostream>
#include <vector>

using namespace std;
int main()
{
   int vector<int> room;
   int N, H, W, T;
   cin >> N;

   for (int i = 0; i < N; i++)
   {
      cin >> H >> W >> T;

      room.resize(W * H);
      int i = 0;
      for (int w = 1; w < W; w++)
      {
         for (int h = 1; h <= H; h++)
         {
            i++;
            room.at(i) = h * 100 + w;
         }
      }

      cout << room.at(T - 1);
   }
   return 0;
}