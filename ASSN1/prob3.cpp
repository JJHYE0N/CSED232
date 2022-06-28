#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

int check_fn(int table[10][10], int i, int j, int k, int count, int* d, int x, int y);

int main() {
    using namespace std;
    ifstream file1("input.txt");
    ofstream file2("output.txt");

    char table_char[10][10];    //input.txt에 문자들을 읽어주기 위한 char형 2차원 배열 선언
    int table_int[10][10];  //읽어낸 char형 2차원 배열을 정수값 2차원 배열로 바꿔주기 위한 int형 2차원 배열 선언
    int d1 = 1000, d2 = 1000;  //(0,0) to k 의 최단거리 d1을 1000으로 초기화 및 k to e 의 최단거리 d2를 100으로 초기화
    int x1, x2, y1, y2;    //x1,y1 -> k의 좌표 / x2,y2 -> e의 좌표

    for (int i = 0; i < 10; i++) {  //input.txt에 문자들을 읽어준다
        for (int j = 0; j < 10; j++) {
            file1 >> table_char[i][j];
        }
    }

    //char형 2차원 배열을 int 형 2차원 배열로 변환
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (table_char[i][j] == '0') table_int[i][j] = 0;   //문자 0은 정수 0으로
            else if (table_char[i][j] == '1') table_int[i][j] = 1;  //문자 1은 정수 1로
            else if (table_char[i][j] == 'k') {   //문자 k일 때에는 정수 0으로 하고, 해당 좌표(i,j)를 (x1,y1) 로 저장
                table_int[i][j] = 0;
                x1 = i;
                y1 = j;
            }
            else if (table_char[i][j] == 'e') {   //문자 e일 때에는 정수 0으로 하고, 해당 좌표(i,j)를 (x2,y2) 로 저장
                table_int[i][j] = 0;
                x2 = i;
                y2 = j;
            }
        }
    }
    //함수 호출
    check_fn(table_int, 0, 0, 0, 0, &d1, x1, y1);  //(0,0) to k 까지의 최단거리를 구한다
    check_fn(table_int, x1, y1, 1, 0, &d2, x2, y2);   //k to e 까지의 최단거리를 구한다.

    file2 << d1 + d2;    //d1+d2 값을 output.txt에 출력
    file1.close();  //input.txt를 닫는다.
    file2.close();  //output.txt를 닫는다.
    return 0;
}

int check_fn(int table[10][10], int i, int j, int k, int count, int* d, int x, int y) {
    //table_int를 인자로 받고, 초기 좌표에 해당하는 i,j 값을 받고 이동한 거리에 해당하는 count를 매개로 받고,
    //(0,0)->k 일때에는 k==0이고 k->e 일때에는 k==1로 구분하기 위해 정수형 변수 k를 매개한다.
    //
    //*d는 각각 (0,0)->k의 최단거리 d1의 주소와 k->e의 최단거리 d2의 주소를 받아 업데이트 하도록 하고
    //정수형 변수 x,y는 목표로하는 좌표를 의미하고 k==0일 때 x,y는 k의 좌표며, k==1일 때 x,y는 e의 좌표이다.
    if (k == 0 && i == x && j == y) {  //k==0일 때 i,j가 목표로하는 위치 x,y(k의 좌표)에 도달했는지 판단
        if (count < *d) *d = count; //만약 count (이동거리가) 최단거리보다 작을 경우 최단거리를 업데이트 해준다.
        return 0;   //함수 종료
    }
    else if (k == 1 && i == x && j == y) { //k==1일 때 i,j가 목표로하는 위치 x,y(e의 좌표)에 도달했는지 판단
        if (count < *d) *d = count; //만약 count (이동거리가) 최단거리보다 작을 경우 최단거리를 업데이트 해준다.
        return 0;   //함수 종료
    }
    table[i][j] = 1;  //지나간 곳은 중복 방지용으로 1로 만들어준다.

    //상하좌우로 움직이는데 이때 i/j>0 혹은 i,j<9로 이동시 판을 나가는 것을 막고 1인 곳은 지나가지 않도록 한다.
    //check_fn함수를 재귀하면서 count를 계속 증가시켜서 이동한 거리를 측정해준다.
    //위
    if (j > 0 && table[i][j - 1] != 1) {
        check_fn(table, i, j - 1, k, count + 1, d, x, y);
    }
    //아래
    if (j < 9 && table[i][j + 1] != 1) {
        check_fn(table, i, j + 1, k, count + 1, d, x, y);
    }
    //왼쪽
    if (i > 0 && table[i - 1][j] != 1) {
        check_fn(table, i - 1, j, k, count + 1, d, x, y);
    }
    //오른쪽
    if (i < 9 && table[i + 1][j] != 1) {
        check_fn(table, i + 1, j, k, count + 1, d, x, y);
    }

    table[i][j] = 0; //갈 곳이 없는 경우 0으로 만들어서 다른 경로를 탐색하도록 한다.
}