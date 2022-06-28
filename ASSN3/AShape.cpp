#include <iostream>
#include "WhiteBoard.h"
#include "AShape.h"

AShape::AShape() {
    alphabet = 'a';
}//AShape�� ������
AShape::~AShape() {
}//AShape�� �Ҹ���

//APoint
APoint::APoint() {
    x = 0;
    y = 0;
    alphabet = 'a';
}//������
APoint::APoint(int x_, int y_, char alphabet_) {
    x = x_;
    y = y_;
    alphabet = alphabet_;
}//������
APoint::~APoint() {

}//�Ҹ���
void APoint::draw(WhiteBoard* board) const {
    board->fillPoint(x, y, alphabet);
}//ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
void APoint::print() const {
    std::cout << ") APoint with [alphabet: " << alphabet << "] and [x: " << x << " ] [y: " << y
        << "] [size: " << size() << "]" << std::endl;
}//�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
int APoint::size() const {
    return 1;
}//������ ũ�⸦ �����ϴ� �Լ�. ���̹Ƿ� 1�̴�.

//AVerticalLine
AVerticalLine::AVerticalLine() {
    x = 0;
    y_start = 0;
    y_end = 0;
    alphabet = 'a';
}//������
AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_) {
    x = x_;
    y_start = y_start_;
    y_end = y_end_;
    alphabet = alphabet_;
}//������
AVerticalLine::~AVerticalLine() {

}//�Ҹ���
void AVerticalLine::draw(WhiteBoard* board) const {
    for (int i = y_start; i <= y_end; i++) {
        board->fillPoint(x, i, alphabet);
    }
}//ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
void AVerticalLine::print() const {
    std::cout << ") AVerticalLine with [alphabet: " << alphabet << "] and [x: " << x
        << " ] [y_start: "
        << y_start << " ] [y_end: " << y_end << "] [size: " << size() << "]" << std::endl;
}//�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
int AVerticalLine::size() const {
    return (y_end - y_start + 1);
}//������ ũ�⸦ �����ϴ� �Լ�. ���̹Ƿ� ���� ���� �̴�.

//AHorizontalLine
AHorizontalLine::AHorizontalLine() {
    x_start = 0;
    x_end = 0;
    y = 0;
    alphabet = 'a';
}//������
AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_) {
    y = y_;
    x_start = x_start_;
    x_end = x_end_;
    alphabet = alphabet_;
}//������
AHorizontalLine::~AHorizontalLine() {

}//�Ҹ���
void AHorizontalLine::draw(WhiteBoard* board) const {
    for (int i = x_start; i <= x_end; i++) {
        board->fillPoint(i, y, alphabet);
    }
}//ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
void AHorizontalLine::print() const {
    //std::cout << i << ") AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y
    std::cout << ") AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y
        << " ] [x_start: "
        << x_start << " ] [x_end: " << x_end << "] [size: " << size() << "]" << std::endl;
}//�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
int AHorizontalLine::size() const {
    return (x_end - x_start + 1);
}//������ ũ�⸦ �����ϴ� �Լ�. ���̹Ƿ� ���� ���� �̴�..

//ARectangle
ARectangle::ARectangle() {
    x_start = 0;
    x_end = 0;
    y_start = 0;
    y_end = 0;
    alphabet = 'a';
}//������
ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_) {
    x_start = x_start_;
    x_end = x_end_;
    y_start = y_start_;
    y_end = y_end_;
    alphabet = alphabet_;
}//������
ARectangle::~ARectangle() {

}//�Ҹ���
void ARectangle::draw(WhiteBoard* board) const {
    for (int i = x_start; i <= x_end; i++) {
        for (int j = y_start; j <= y_end; j++) {
            board->fillPoint(i, j, alphabet);
        }
    }
}//ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
void ARectangle::print() const {
    //std::cout << i << ") ARectangle with [alphabet: " << alphabet << "] and [x_start: " << x_start
    std::cout << ") ARectangle with [alphabet: " << alphabet << "] and [x_start: " << x_start
        << " ] [x_end: " << x_end << "][y_start:" << y_start << "][y_end:" << y_end << "] [size: "
        << size()
        << "]" << std::endl;
}//�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
int ARectangle::size() const {
    return (x_end - x_start + 1) * (y_end - y_start + 1);
}//������ ũ�⸦ �����ϴ� �Լ�. �簢���̹Ƿ� �簢���� �����̴�.