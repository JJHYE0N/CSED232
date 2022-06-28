#ifndef OOP_ASSN4_GEOMETRY_H
#define OOP_ASSN4_GEOMETRY_H
#include <vector>

//template <typename T>
class geometry {
    //모든 geometry 구성 요소들의 abstract class
private:    //너비,높이,문자에 해당하는 멤버변수 선언 
    char c_empty;
    int width, height;
public:
    geometry() { }
    virtual void draw2canvas(float**& table, int w, int h) {
        this->draw2canvas(table, w, h);
    }
    //보드 인자를 배열로 받는다. int **board
    //canvas의 instance가 geometry를 그릴 때 사용된다.
};
#endif //OOP_ASSN4_GEOMETRY_H