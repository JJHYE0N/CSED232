#ifndef OOP_ASSN3_1_ASHAPE_H
#define OOP_ASSN3_1_ASHAPE_H
#include "WhiteBoard.h"

class AShape {
private:

protected:
    char alphabet;  //char형 alphabet
public:
    AShape();//생성자
    virtual ~AShape();//소멸자
    virtual void draw(WhiteBoard* board) const = 0;
    //화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
    virtual void print() const = 0;
    //해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
    //수평선의 경우 AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] 이와 같이 출력하면 된다.
    // 반드시 위와 같은 양식으로 출력할 필요는 없고, 필요한 정보만 담겨있으면 된다.
    virtual int size() const = 0;
    //도형의 크기를 리턴하는 함수. 점의 경우 1, 선의 경우엔 선의 길이, 사각형의 경우에는 사각형의 넓이이다.
};

class APoint : public AShape {
private:    //x,y에 대한 정보 private형으로 선언
    int x;
    int y;
public:
    APoint();//생성자
    APoint(int x_, int y_, char alphabet_);//생성자
    ~APoint();//소멸자
    void draw(WhiteBoard* board) const;
    //화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
    void print() const;
    //해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
    //수평선의 경우 AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] 이와 같이 출력하면 된다.
    // 반드시 위와 같은 양식으로 출력할 필요는 없고, 필요한 정보만 담겨있으면 된다.
    int size() const;
    //도형의 크기를 리턴하는 함수. 점의 경우 1, 선의 경우엔 선의 길이, 사각형의 경우에는 사각형의 넓이이다.
};

class AVerticalLine : public AShape {
private:    //x,y에 대한 정보 private형으로 선언
    int x;
    int y_start;
    int y_end;
public:
    AVerticalLine();//생성자
    AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);//생성자
    ~AVerticalLine();//소멸자
    void draw(WhiteBoard* board) const;
    //화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
    void print() const;
    //해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
    //수평선의 경우 AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] 이와 같이 출력하면 된다.
    // 반드시 위와 같은 양식으로 출력할 필요는 없고, 필요한 정보만 담겨있으면 된다.
    int size() const;
    //도형의 크기를 리턴하는 함수. 점의 경우 1, 선의 경우엔 선의 길이, 사각형의 경우에는 사각형의 넓이이다.
    //void draw(WhiteBoard *board) const;
};

class AHorizontalLine : public AShape {
private:    //x,y에 대한 정보 private형으로 선언
    int y;
    int x_start;
    int x_end;
public:
    AHorizontalLine();//생성자
    AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);//생성자
    ~AHorizontalLine();//소멸자
    void draw(WhiteBoard* board) const;
    //화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
    void print() const;
    //해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
    //수평선의 경우 AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] 이와 같이 출력하면 된다.
    // 반드시 위와 같은 양식으로 출력할 필요는 없고, 필요한 정보만 담겨있으면 된다.
    int size() const;
    //도형의 크기를 리턴하는 함수. 점의 경우 1, 선의 경우엔 선의 길이, 사각형의 경우에는 사각형의 넓이이다.
};

class ARectangle : public AShape {
private:    //x,y에 대한 정보 private형으로 선언
    int x_start;
    int x_end;
    int y_start;
    int y_end;
public:
    ARectangle();//생성자
    ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);//생성자
    ~ARectangle();//소멸자
    void draw(WhiteBoard* board) const;
    //화이트보드에 해당 도형의 좌표 및 알파벳의 정보를 보내 그리게 한다.
    void print() const;
    //해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다. 도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다.
    //수평선의 경우 AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] 이와 같이 출력하면 된다.
    // 반드시 위와 같은 양식으로 출력할 필요는 없고, 필요한 정보만 담겨있으면 된다.
    int size() const;
    //도형의 크기를 리턴하는 함수. 점의 경우 1, 선의 경우엔 선의 길이, 사각형의 경우에는 사각형의 넓이이다.
};

#endif //OOP_ASSN3_1_ASHAPE_H
