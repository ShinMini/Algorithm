#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> P(2);
vector<vector<int>> Point();

int makeRect(int, vector<int> &P, vector<vector<int>> &Point);
int makeDistance(vector<vector<int>> &Point, int);

int main()
{
    int T, x1, y1, x2, y2, r1, r2;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        vector<int> P1(P);
        vector<int> P2(P);
        P1.at(0) = x1; P1.at(1) = y1; // P1, P2에는 1)x, 2) y가 담겨있다
        P2.at(0) = x2; P2.at(1) = y2; // P1, P2에는 1)x, 2) y가 담겨있다
        vector<vector<int>> Point1(4 * r1 * r1 * 2 + 10);
        vector<vector<int>> Point2(4 * r2 * r2 * 2 + 10);


        makeRect(r1, P1, Point1);
        makeRect(r2, P2, Point2);

        makeDistance(Point1, r1); // 문제는 여기서 프로그램 종료.
    }

    return 0;
}

int makeRect(int R, vector<int> &P, vector<vector<int>> &Point)
{
    vector<int> initP(P);
    initP.at(0) = P.at(0);
    initP.at(1) = P.at(1); // 초기 좌표값 저장

    // 1, 2, 3, 4 분면 좌표 생성 함수
    int Xfraction = 1;
    int Yfraction = 1;
    for (int t = 1; t <= 4; t++)
    { // 4번 반복
        if (t == 1) { Xfraction = 1; Yfraction = 1; }
        if (t == 2) { Xfraction = -1; Yfraction = 1; }
        if (t == 3) { Xfraction = -1; Yfraction = -1; }
        if (t == 4) { Xfraction = 1; Yfraction = -1; }

        P.at(0) = initP.at(0); // 초기 좌표로 초기화

        for (int x = 0; x <= R; x++)
        {
            for (int y = 0; y <= R; y++)
            {
                Point.push_back(P);
                P.at(1) += Yfraction;
            }
            P.at(0) += Xfraction;
            P.at(1) = initP.at(1); // y좌표 초기화
        }
    }
    return 0;
}

int makeDistance(vector<vector<int>> &Point, int R)
{
    int distance = 1, Point_X, Point_Y;
    cout << Point.size() << "\n";
    Point.shrink_to_fit();
    cout << Point.size() << "\n";
    

    for (int a = 0; a < Point.size(); a++)
    {

        Point_X = Point.at(a)[0];
        Point_Y = Point.at(a)[1];
        cout << Point_X << ", " << Point_Y << "\n";

        distance = Point_X*Point_X + Point_Y*Point_Y;

        if (distance <= R * R)
        {
            cout << "(x, y) -> (" << Point.at(a)[0] << ", " << Point.at(a)[1]<< ")"
                 << " \n ";
        }
        else
        {
            Point.erase(Point.begin() + a);
            cout << "erase!"
                 << "\n";
        }
        //cout << t << " : " << Point.size() << "\n";
        if (Point.empty())
            break;
    }

    return 0;
}









// 두 원 사이의 좌표를 먼저 구하자,
// 먼저 (r1 * 2)지름 만큼의 길이를 가진 정사각형을 만든뒤,
//
// 내부의 좌표값을 가진 Point1(2r1*2r1)배열을 만든다.
//
// 이후, Point1 배열 내의 좌표값과 P1(x1, y1)사이의 거리가 < r1반지름 이하인,
// (원 내부에 있는 좌표를 걸러준뒤) (거리가 r1이상일 경우, 0으로 값 초기화)
// Point1배열을 수정한다.
// 같은 방식으로 Point2배열을 만든 뒤,
//
// Point1배열 내부 좌표와, P2(x2, y1)의 거리가 r2이하인 좌표를 구한다.
// 같은방식으로
// Point2배열 내부 좌표와 P1(x1, y1)의 거리가 r1이하인 좌표를 구한다.
// (그 외값 전부 0으로 초기화)
// Point1배열과 Point2 배열값을 비교해 같은 좌표를 갖고 있는 경우,
// count++를 해줌. 끝.
