#ifndef OOP_ASSN4_RECTANGLE_H
#define OOP_ASSN4_RECTANGLE_H
#include "geometry.h"
#include "canvas2d.h"

template <typename T>
class rectangle : public geometry {
    //2���� ����� ������ �簢�� Ŭ����
    //�����簢��, �� ���� x,y��� ������ �����Ѵ�.
private:
    T x1, x2, y1, y2;   //x,y ���� ��� ������ ���� 
    T left_x, right_x;  //���� x ,������ y ���� 
    T top_y, bottom_y;  //�� y �Ʒ� y ���� 
    T width, height;    //�ʺ�� ���� ���� 

public:
    rectangle<T>(T _x1, T _y1, T _x2, T _y2) {  //�⺻ ������
        if (_x1 == _x2 || _y1 == _y2) {   //���� x,y���� �Է��� ����
            throw;
        }
        else {  //x1,x2,y1,y2�� �ʰ�ȭ �Ѵ�.
            x1 = _x1;
            x2 = _x2;
            y1 = _y1;
            y2 = _y2;

            if (x1 < x2) { //���� ���ʿ� �ִ� ���� �����ʿ� �ִ� ���� ���ǹ����� �и��Ѵ�.
                left_x = x1;
                right_x = x2;
            }
            else {
                left_x = x2;
                right_x = x1;
            }
            if (y1 < y2) { //���� ���� �ִ� ���� �Ʒ��� �ִ� ���� ���ǹ����� �и��Ѵ�.
                top_y = y1;
                bottom_y = y2;
            }
            else {
                top_y = y2;
                bottom_y = y1;
            }

            width = right_x - left_x + 1; //�ʺ�
            height = bottom_y - top_y + 1;//����
        }
    }
    //�Ʒ� �׸��� ���� �簢���� ������ ��ǥ�� ���ǵ� �� �ִ�.������ ���ڴ� ���� ��� x_1, y_1, x_2, y_2�� �ش��Ѵ�.
    //�簢���� ������ 0�� �ǵ��� ���ڰ� �־��� ��� ��throw�� Ű���带 ���ؼ� ���α׷��� fail��Ų��.

    bool is_equal(const rectangle<T>& other) {  //���� ��� 
        if (left_x == other.left_x && right_x == other.right_x && top_y == other.top_y && bottom_y == other.bottom_y) {
            return true;
        }
        else {
            return false;
        }
    }
    //����Լ��� ȣ���ϴ� instance�� other�� ��Ȯ�� 4���� point�� �����ϴ� ��� true, �׷��� ���� ��� false

    bool is_intersect(const rectangle<T>& other) {  //���ͼ�Ʈ�� �ϴ� ��� 
        if (!is_equal(other)) {
            if (left_x > other.right_x || right_x<other.left_x || top_y>other.bottom_y || bottom_y < other.top_y)
            {
                return false;
            }
            //A�� ���� �𼭸��� B�� ������ �����ڸ� �����ʿ� ������ A�� ������ B�� �������̴�.
            //A�� ������ �𼭸��� B�� ���� �����ڸ� ���ʿ� ������ A�� B�� ���ʿ� ������ �ִ�.
            //A�� ���� ���� B�� �Ʒ��� ���� �Ʒ��� ������ A�� ������ B�Ʒ��� �ִ�.
            //A�� �Ʒ��� ���� A�� ���� ���� ���� ������ A�� ������ B ���� �ִ�.
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }//����Լ��� ȣ���ϴ� instance�� other�� equal�� �ƴϸ鼭 ������ ��ġ�� ��� true, �׷��� ���� ��� false (�Ʒ� ����)

    bool is_line_overlap(const rectangle<T>& other) {   //�������� �ϴ� ���
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
    }//����Լ��� ȣ���ϴ� instance�� other�� equal �� intersect�� �ƴϸ鼭 �� ���� �����ϴ� ��� true, �׷��� ���� ��� false(�Ʒ� ����)

    bool is_point_match(const rectangle<T>& other) {
        if (!is_intersect(other)) {    //intersect�� �ƴϰ�
            //this���� ������ �� �𼭸����� ���� ��+���� �� �𼭸����� ���� ��+������ �Ʒ� �𼭸����� ���� ��+���� �Ʒ� �𼭸����� ���� ��
            if ((right_x == other.left_x && top_y == other.bottom_y)
                || (left_x == other.right_x && top_y == other.bottom_y)
                || (right_x == other.left_x && bottom_y == other.top_y)
                || (left_x == other.right_x && bottom_y == other.top_y)) {
                return true;
            }
            else return false;
        }
        else return false;
    }//����Լ��� ȣ���ϴ� instance�� other�� intersect�� �ƴϸ鼭 ���� �� ���� �����ϴ� ��� true, �׷��� ���� ��� false (�Ʒ� ����)

    bool is_disjoint(const rectangle<T>& other) {   //������Ʈ�ϴ� ���

        if ((left_x > other.right_x) || (right_x < other.left_x) || (top_y > other.bottom_y) || (bottom_y < other.top_y)) {
            return true;
        }
        else return false;
    }//����Լ��� ȣ���ϴ� instance�� other�� ������ �ʴ� ��� true, �׷��� ���� ��� false (�Ʒ� ����)

    void draw2canvas(float**& table, int w, int h) {  ///���忡 ���� �־��ִ� �Լ�
    //2���� �迭 + ���� ���̸�� �޾�
        if (right_x > w-1&&bottom_y>h-1) {
            for (int i = left_x; i <= w - 1; i++) { //������ ũ�⺸�� ������x�� ũ��, �Ʒ���y�� Ŭ ��
                for (int j = top_y; j <= h - 1; j++) {
                    table[j][i] += 1;
                }
            }
        }
        else if (right_x > w - 1 && bottom_y <= h - 1) {//������ ũ�⺸�� ������x�� Ŭ �� 
            for (int i = left_x; i <= w-1; i++) {
                for (int j = top_y; j <= bottom_y; j++) {
                    table[j][i] += 1;
                }
            }
        }
        else if (right_x <= w - 1 && bottom_y > h - 1) {//������ ũ�⺸�� �Ʒ���y�� Ŭ �� 
            for (int i = left_x; i <= right_x; i++) {
                for (int j = top_y; j <= h - 1; j++) {
                    table[j][i] += 1;
                }
            }
        }
        else {
            for (int i = left_x; i <= right_x; i++) {   //ħ������ �ʴ� ��� 
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