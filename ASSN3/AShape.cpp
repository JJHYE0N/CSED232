#include <iostream>
#include "WhiteBoard.h"
#include "AShape.h"

AShape::AShape() {
    alphabet = 'a';
}//AShape의 생성자
AShape::~AShape() {
}//AShape의 소멸자

//APoint
APoint::APoint() {
    x = 0;
    y = 0;
    alphabet = 'a';
}//생성자
APoint::APoint(int x_, int y_, char alphabet_) {
    x = x_;
    y = y_;
    alphabet = alphabet_;
}//생성자
APoint::~APoint() {

}//소멸자
void APoint::draw(WhiteBoard* board) const {
    board->fillPoint(x, y, alphabet);
}//화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
void APoint::print() const {
    std::cout << ") APoint with [alphabet: " << alphabet << "] and [x: " << x << " ] [y: " << y
        << "] [size: " << size() << "]" << std::endl;
}//해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
int APoint::size() const {
    return 1;
}//도형의 크기를 리턴하는 함수. 점이므로 1이다.

//AVerticalLine
AVerticalLine::AVerticalLine() {
    x = 0;
    y_start = 0;
    y_end = 0;
    alphabet = 'a';
}//생성자
AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_) {
    x = x_;
    y_start = y_start_;
    y_end = y_end_;
    alphabet = alphabet_;
}//생성자
AVerticalLine::~AVerticalLine() {

}//소멸자
void AVerticalLine::draw(WhiteBoard* board) const {
    for (int i = y_start; i <= y_end; i++) {
        board->fillPoint(x, i, alphabet);
    }
}//화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
void AVerticalLine::print() const {
    std::cout << ") AVerticalLine with [alphabet: " << alphabet << "] and [x: " << x
        << " ] [y_start: "
        << y_start << " ] [y_end: " << y_end << "] [size: " << size() << "]" << std::endl;
}//해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
int AVerticalLine::size() const {
    return (y_end - y_start + 1);
}//도형의 크기를 리턴하는 함수. 선이므로 선의 길이 이다.

//AHorizontalLine
AHorizontalLine::AHorizontalLine() {
    x_start = 0;
    x_end = 0;
    y = 0;
    alphabet = 'a';
}//생성자
AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_) {
    y = y_;
    x_start = x_start_;
    x_end = x_end_;
    alphabet = alphabet_;
}//생성자
AHorizontalLine::~AHorizontalLine() {

}//소멸자
void AHorizontalLine::draw(WhiteBoard* board) const {
    for (int i = x_start; i <= x_end; i++) {
        board->fillPoint(i, y, alphabet);
    }
}//화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
void AHorizontalLine::print() const {
    //std::cout << i << ") AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y
    std::cout << ") AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y
        << " ] [x_start: "
        << x_start << " ] [x_end: " << x_end << "] [size: " << size() << "]" << std::endl;
}//해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
int AHorizontalLine::size() const {
    return (x_end - x_start + 1);
}//도형의 크기를 리턴하는 함수. 선이므로 선의 길이 이다..

//ARectangle
ARectangle::ARectangle() {
    x_start = 0;
    x_end = 0;
    y_start = 0;
    y_end = 0;
    alphabet = 'a';
}//생성자
ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_) {
    x_start = x_start_;
    x_end = x_end_;
    y_start = y_start_;
    y_end = y_end_;
    alphabet = alphabet_;
}//생성자
ARectangle::~ARectangle() {

}//소멸자
void ARectangle::draw(WhiteBoard* board) const {
    for (int i = x_start; i <= x_end; i++) {
        for (int j = y_start; j <= y_end; j++) {
            board->fillPoint(i, j, alphabet);
        }
    }
}//화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
void ARectangle::print() const {
    //std::cout << i << ") ARectangle with [alphabet: " << alphabet << "] and [x_start: " << x_start
    std::cout << ") ARectangle with [alphabet: " << alphabet << "] and [x_start: " << x_start
        << " ] [x_end: " << x_end << "][y_start:" << y_start << "][y_end:" << y_end << "] [size: "
        << size()
        << "]" << std::endl;
}//해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
int ARectangle::size() const {
    return (x_end - x_start + 1) * (y_end - y_start + 1);
}//도형의 크기를 리턴하는 함수. 사각형이므로 사각형의 넓이이다.