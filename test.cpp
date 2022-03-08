#include <iostream>
#include <cmath>
<<<<<<< HEAD

using namespace std;

int Decimal(size_t T){
    int count=0, N;
    if(T==1) {
        cout<<1<<"\n";
        return 0;
    }

    N=ceil(sqrt(2*T));
    for(size_t t=2; t<=N; t++) {
        if(N%t==0 && N!=t) break;
        if(t==N){
            count++;
            break;
        }
    }
    N=ceil(sqrt(T));
    for(size_t t=2; t<=N; t++) {
        if(N%t==0 && N!=t) break;
        if(N==N){
            count--;
            break;
        }
    // 이러지말고 2T에서 T값을 빼자 ..
}
cout << count << "\n";
return 0;
}
int main(){
    size_t T;
    while(true){
        cin>>T;
        if(T == 0) break;
        Decimal(T);
=======
#include <vector>
using namespace std;

vector<int> P(2);
vector<vector<int>> Point();

int makeRect(int, vector<int> &P, vector<vector<int>> &Point);
int makeDistance(vector<vector<int>> &Point, int);

int main()
{
    int T;
    cin >> T;

    int x1, y1, x2, y2;
    int r1, r2;

    for (int i = 0; i < T; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        vector<int> P1(P);
        vector<int> P2(P);
        P1.at(0) = x1;
        P1.at(1) = y1; // P1, P2에는 1)x, 2) y가 담겨있다
        P2.at(0) = x2;
        P2.at(1) = y2; // P1, P2에는 1)x, 2) y가 담겨있다
        vector<vector<int>> Point1(4 * r1 * r1 * 2 + 10);
        vector<vector<int>> Point2(4 * r2 * r2 * 2 + 10);

        // cout << P1.at(0) << " , " << P1.at(1) << "\n";
        // cout << P2.at(0) << " , " << P2.at(1) << "\n";

        // 만들어진 좌표가 제대로 생성되었는지 테스트
        // 요 함수를 x1, y1값을 P1 객체로 대체하고, r1값, P1값만 넣어 반환하는 것을 목표로 하자.
        // makeRect(r1, P1);    // 요런식으로 하고, Point 배열같은 경우는 함수 내에서 재 구현,
        makeRect(r1, P1, Point1);
        makeRect(r2, P2, Point2);

        // 좌표 제대로 들어갔고, distance = x1*x1 +y1*y1한 값이 r1*r1보다 작은 값을 추림.
        makeDistance(Point1, r1); // 문제는 여기서 프로그램 종료.
        makeDistance(Point2, r2);

        // 값 초기화
        // P={}; Point={}; P1={}; Point1={}; P2={}; Point2={};
>>>>>>> 0a8932dc325dc96837fa7bb06808877c190356d5
    }

    return 0;
}
<<<<<<< HEAD
=======

// 배열 내 좌표값 설정: 1분면, 2분면, 3분면, 4분면 순서대로 값 입력해줄거임.
// 아래의 경우, 중점이 중복해서 4번 들어갈 수 있음.
int makeRect(int R, vector<int> &P, vector<vector<int>> &Point)
{
    int i = 0;
    vector<int> initP(P);
    initP.at(0) = P.at(0);
    initP.at(1) = P.at(1); // 초기 좌표값 저장

    // 1, 2, 3, 4 분면 좌표 생성 함수
    int Xfraction = 1;
    int Yfraction = 1;
    for (int t = 1; t <= 4; t++)
    { // 4번 반복
        if (t == 1)
        {
            Xfraction = 1;
            Yfraction = 1;
        }
        if (t == 2)
        {
            Xfraction = -1;
            Yfraction = 1;
        }
        if (t == 3)
        {
            Xfraction = -1;
            Yfraction = -1;
        }
        if (t == 4)
        {
            Xfraction = 1;
            Yfraction = -1;
        }

        P.at(0) = initP.at(0); // 초기 좌표로 초기화

        for (int x = 0; x <= R; x++)
        {
            for (int y = 0; y <= R; y++)
            {
                Point.at(i) = P;
                P.at(1) += Yfraction;
                i++;
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

    for (int t = 0; t < Point.size(); t++)
    {

        Point_X = Point[t][0];
        Point_Y = Point[t][1];
        cout << Point_X << ", " << Point_Y << "\n";

        distance = Point_X * Point_X + Point_Y * Point_Y;

        if (distance <= R * R)
        {
            cout << "(x, y) -> (" << Point[t][0] << ", " << Point[t][1] << ")"
                 << " \n ";
        }
        else
        {
            Point.erase(Point.begin() + t);
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
>>>>>>> 0a8932dc325dc96837fa7bb06808877c190356d5
