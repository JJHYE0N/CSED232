#ifndef OOP_ASSN4_GEOMETRY_H
#define OOP_ASSN4_GEOMETRY_H
#include <vector>

//template <typename T>
class geometry {
    //��� geometry ���� ��ҵ��� abstract class
private:    //�ʺ�,����,���ڿ� �ش��ϴ� ������� ���� 
    char c_empty;
    int width, height;
public:
    geometry() { }
    virtual void draw2canvas(float**& table, int w, int h) {
        this->draw2canvas(table, w, h);
    }
    //���� ���ڸ� �迭�� �޴´�. int **board
    //canvas�� instance�� geometry�� �׸� �� ���ȴ�.
};
#endif //OOP_ASSN4_GEOMETRY_H