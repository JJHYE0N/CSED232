#ifndef OOP_ASSN4_CANVAS2D_H
#define OOP_ASSN4_CANVAS2D_H
#include <vector>
#include <iostream>
#include "geometry.h"

using namespace std;

class canvas2d : public vector<geometry*> {
private:
    int width, height;   //�ʺ� ����
    char c_empty;   //����
    float** table; //���̺� �ش��ϴ� 2���� float ������ ����

public:
    canvas2d(int w, int h, char c) {
        width = w;    //�ʺ� �ʱ�ȭ
        height = h;   //���� �ʱ�ȭ
        c_empty = c;  //���� �ʱ�ȭ

        table = new float* [height];    //2���� �����͸� float������ �����Ҵ� ���ش�.
        for (int i = 0; i < height; i++) {
            table[i] = new float[width];
        }

        for (int i = 0; i < height; i++) {  //table�� ���� ��� 0���� �ʱ�ȭ �����ش�.
            for (int j = 0; j < width; j++) {
                //table[height][width] = c_empty;
                table[i][j] = 0;
            }
        }

        // vector<vector<int>> table(width, vector<int>(height, 0));
    }

    ~canvas2d() {   //�Ҹ��ڿ��� �����ϰ� talbe�� ���� �����Ҵ� ������ ���ش�.
        for (int i = 0; i < height; i++) {
            delete[] table[i];
        }
        delete[] table;
        //
    }//width: canvas�� �� / height: canvas�� ���� / �� ������ ǥ���� ����(char)


    void draw2stdout() {
        //for������ draw to canvas�� �ҷ��� ���� ���� �޾Ƽ� ���忡ǥ�� ���� ����� ó�� ���°� �ƴϰ� ��ġ�� ������,
        //1 �ݺ������� table�� ���� ������Ʈ���ش�.
        vector<geometry*>::iterator p;
        for (p = begin(); p != end(); p += 1) {
            geometry* temp = *p;
            temp->draw2canvas(table, width, height);
        }
        //2 ��ü table�� ����Ѵ�.
        int num;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (table[i][j] > 0) {
                    num = (int)table[i][j] % 10;
                    cout << num;   //���� ���
                }
                else {  //������ ���� 0�ΰ�� ���ڸ� ����Ѵ�.
                    cout << c_empty;   //���� ���
                }
            }
            cout << endl;
        }
    }
};//������ ��ü�� stdout���� ���

#endif //OOP_ASSN4_CANVAS2D_H