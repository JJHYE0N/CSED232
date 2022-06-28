#ifndef OOP_ASSN4_POINT_H
#define OOP_ASSN4_POINT_H
#include "geometry.h"
#include "canvas2d.h"

template <typename T, int N>
class point : public geometry {
    //����Ʈ class�� T�� ���� numeric type, N�� coordinate dimension�� �ǹ��Ѵ�
    // ����, N�� 2�� 2���� point, 3�̸� 3���� point�� �ȴ�.
private:
    T array[N];//���ø��� �迭�� �����Ѵ�.

public:
    point<T, N>(const T* coords) {
        for (int i = 0; i < N; i++) {//array[i]=coords[i]�� �ʱ�ȭ �����ش�.
            array[i] = coords[i];
        }
    }
    //point<T, int N>(const T* coords)
    //point class�� �������̸� N���� T������ �ʱ�ȭ �ȴ�.

    void draw2canvas(float**& table, int w, int h) { //�ٽú���
        float sum = 0;
        if (N == 2) table[(int) array[1]][(int) array[0]] += 1;
        else if (N > 2) {//3���� �̻��� ��쿡 �ڿ����� ������ ���� �ش� ��ǥ�� ���� �����ش�.
            for (int i = 2; i < N; i++) {
                sum += array[i];
            }
            int i_x = (int)array[0] ;//���ڷ� �Ǿ��ִ� ���� int�� �ٲ��ش�.
            int i_y = (int)array[1];//���ڷ� �Ǿ��ִ� ���� int�� �ٲ��ش�.
  
            if (sum == 0) table[i_y][i_x] += 1; //���� 0�� ��� 1���� �����ش�.
            else {
                table[i_y][i_x] += (int) sum;   //�ش��ϴ� ��ǥ�� sum���� �����ش�.
            }
            return;
        }
    }
};

#endif //OOP_ASSN4_POINT_H