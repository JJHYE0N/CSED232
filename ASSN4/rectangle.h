#ifndef OOP_ASSN4_RECTANGLE_H
#define OOP_ASSN4_RECTANGLE_H
#include "geometry.h"
#include "canvas2d.h"

template <typename T>
class rectangle : public geometry {
    //2차원 평면을 가정한 사각형 클래스
    //직각사각형, 각 변이 x,y축과 평행을 가정한다.
private:
    T x1, x2, y1, y2;   //x,y 값들 멤버 변수로 선언 
    T left_x, right_x;  //왼쪽 x ,오른쪽 y 선언 
    T top_y, bottom_y;  //위 y 아래 y 선언 
    T width, height;    //너비와 높이 선언 

public:
    rectangle<T>(T _x1, T _y1, T _x2, T _y2) {  //기본 생성자
        if (_x1 == _x2 || _y1 == _y2) {   //같은 x,y값의 입력을 방지
            throw;
        }
        else {  //x1,x2,y1,y2를 초가화 한다.
            x1 = _x1;
            x2 = _x2;
            y1 = _y1;
            y2 = _y2;

            if (x1 < x2) { //둘중 왼쪽에 있는 값과 오른쪽에 있는 값을 조건문으로 분리한다.
                left_x = x1;
                right_x = x2;
            }
            else {
                left_x = x2;
                right_x = x1;
            }
            if (y1 < y2) { //둘중 위에 있는 값과 아래에 있는 값을 조건문으로 분리한다.
                top_y = y1;
                bottom_y = y2;
            }
            else {
                top_y = y2;
                bottom_y = y1;
            }

            width = right_x - left_x + 1; //너비
            height = bottom_y - top_y + 1;//높이
        }
    }
    //아래 그림과 같이 사각형은 두점의 좌표로 정의될 수 있다.각각의 인자는 순서 대로 x_1, y_1, x_2, y_2에 해당한다.
    //사각형의 면적이 0이 되도록 인자가 주어진 경우 “throw” 키워드를 통해서 프로그램을 fail시킨다.

    bool is_equal(const rectangle<T>& other) {  //같은 경우 
        if (left_x == other.left_x && right_x == other.right_x && top_y == other.top_y && bottom_y == other.bottom_y) {
            return true;
        }
        else {
            return false;
        }
    }
    //멤버함수를 호출하는 instance와 other이 정확히 4개의 point를 공유하는 경우 true, 그렇지 않은 경우 false

    bool is_intersect(const rectangle<T>& other) {  //인터섹트를 하는 경우 
        if (!is_equal(other)) {
            if (left_x > other.right_x || right_x<other.left_x || top_y>other.bottom_y || bottom_y < other.top_y)
            {
                return false;
            }
            //A의 왼쪽 모서리가 B의 오른쪽 가장자리 오른쪽에 있으면 A는 완전히 B의 오른쪽이다.
            //A의 오른쪽 모서리가 B의 왼쪽 가장자리 왼쪽에 있으면 A는 B의 왼쪽에 완전히 있다.
            //A의 위쪽 변이 B의 아래쪽 변의 아래에 있으면 A는 완전히 B아래에 있다.
            //A의 아래쪽 변이 A의 위쪽 변에 위에 있으면 A는 완전히 B 위에 있다.
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }//멤버함수를 호출하는 instance와 other이 equal이 아니면서 영역이 겹치는 경우 true, 그렇지 않은 경우 false (아래 예시)

    bool is_line_overlap(const rectangle<T>& other) {   //오버랩을 하는 경우
        if (!is_equal(other)) {
            if (!is_intersect(other)) {
                //not match
                if (!is_point_match(other)) {
                    if (right_x == other.left_x || top_y == other.bottom_y || bottom_y == other.top_y || left_x == other.right_x) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }//멤버함수를 호출하는 instance와 other이 equal 및 intersect가 아니면서 한 변을 공유하는 경우 true, 그렇지 않은 경우 false(아래 예시)

    bool is_point_match(const rectangle<T>& other) {
        if (!is_intersect(other)) {    //intersect가 아니고
            //this기준 오른쪽 위 모서리에서 만날 때+왼쪽 위 모서리에서 만날 때+오른쪽 아래 모서리에서 만날 때+왼쪽 아래 모서리에서 만날 때
            if ((right_x == other.left_x && top_y == other.bottom_y)
                || (left_x == other.right_x && top_y == other.bottom_y)
                || (right_x == other.left_x && bottom_y == other.top_y)
                || (left_x == other.right_x && bottom_y == other.top_y)) {
                return true;
            }
            else return false;
        }
        else return false;
    }//멤버함수를 호출하는 instance와 other이 intersect가 아니면서 오직 한 점을 공유하는 경우 true, 그렇지 않은 경우 false (아래 예시)

    bool is_disjoint(const rectangle<T>& other) {   //디스조인트하는 경우

        if ((left_x > other.right_x) || (right_x < other.left_x) || (top_y > other.bottom_y) || (bottom_y < other.top_y)) {
            return true;
        }
        else return false;
    }//멤버함수를 호출하는 instance와 other이 만나지 않는 경우 true, 그렇지 않은 경우 false (아래 예시)

    void draw2canvas(float**& table, int w, int h) {  ///보드에 값을 넣어주는 함수
    //2차원 배열 + 넓이 높이모두 받아
        if (right_x > w-1&&bottom_y>h-1) {
            for (int i = left_x; i <= w - 1; i++) { //보드의 크기보다 오른쪽x가 크고, 아래쪽y가 클 때
                for (int j = top_y; j <= h - 1; j++) {
                    table[j][i] += 1;
                }
            }
        }
        else if (right_x > w - 1 && bottom_y <= h - 1) {//보드의 크기보다 오른쪽x가 클 때 
            for (int i = left_x; i <= w-1; i++) {
                for (int j = top_y; j <= bottom_y; j++) {
                    table[j][i] += 1;
                }
            }
        }
        else if (right_x <= w - 1 && bottom_y > h - 1) {//보드의 크기보다 아래쪽y가 클 때 
            for (int i = left_x; i <= right_x; i++) {
                for (int j = top_y; j <= h - 1; j++) {
                    table[j][i] += 1;
                }
            }
        }
        else {
            for (int i = left_x; i <= right_x; i++) {   //침범하지 않는 경우 
                for (int j = top_y; j <= bottom_y; j++) {
                    table[j][i] += 1;
                }
            }
        }
    }
};

//template <typename T>
//class point<T,int N> : public geometry {

#endif //OOP_ASSN4_RECTANGLE_H