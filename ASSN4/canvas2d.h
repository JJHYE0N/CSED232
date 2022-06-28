#ifndef OOP_ASSN4_CANVAS2D_H
#define OOP_ASSN4_CANVAS2D_H
#include <vector>
#include <iostream>
#include "geometry.h"

using namespace std;

class canvas2d : public vector<geometry*> {
private:
    int width, height;   //너비 높이
    char c_empty;   //문자
    float** table; //테이블에 해당하는 2차원 float 포인터 선언

public:
    canvas2d(int w, int h, char c) {
        width = w;    //너비 초기화
        height = h;   //높이 초기화
        c_empty = c;  //문자 초기화

        table = new float* [height];    //2차원 포인터를 float형으로 동적할당 해준다.
        for (int i = 0; i < height; i++) {
            table[i] = new float[width];
        }

        for (int i = 0; i < height; i++) {  //table의 값을 모두 0으로 초기화 시켜준다.
            for (int j = 0; j < width; j++) {
                //table[height][width] = c_empty;
                table[i][j] = 0;
            }
        }

        // vector<vector<int>> table(width, vector<int>(height, 0));
    }

    ~canvas2d() {   //소멸자에서 안전하게 talbe에 대한 동적할당 해제를 해준다.
        for (int i = 0; i < height; i++) {
            delete[] table[i];
        }
        delete[] table;
        //
    }//width: canvas의 폭 / height: canvas의 높이 / 빈 공간을 표현할 글자(char)


    void draw2stdout() {
        //for문으로 draw to canvas를 불러옴 도형 정보 받아서 보드에표시 저번 어싸인 처럼 덮는건 아니고 겹치면 더해줌,
        //1 반복문으로 table에 값을 업데이트해준다.
        vector<geometry*>::iterator p;
        for (p = begin(); p != end(); p += 1) {
            geometry* temp = *p;
            temp->draw2canvas(table, width, height);
        }
        //2 전체 table을 출력한다.
        int num;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (table[i][j] > 0) {
                    num = (int)table[i][j] % 10;
                    cout << num;   //숫자 출력
                }
                else {  //기존에 값이 0인경우 문자를 출력한다.
                    cout << c_empty;   //문자 출력
                }
            }
            cout << endl;
        }
    }
};//보유한 객체를 stdout으로 출력

#endif //OOP_ASSN4_CANVAS2D_H