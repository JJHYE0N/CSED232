#ifndef OOP_ASSN3_1_MENU_H
#define OOP_ASSN3_1_MENU_H
#include "WhiteBoard.h"
#include "AShapeList.h"

class Menu {
private:
    bool is_running;//현재 프로그램이 실행 중인지의 여부를 true, false로 저장한다.
    AShapeList* shape_list;//AShapeList shape_list 선언
    WhiteBoard* board;//WhiteBoard* board 선언
public:
    Menu(WhiteBoard* board, AShapeList* shape_list);//생성자
    ~Menu();//소멸자
    void display() const;   //메뉴를 출력한다.
    bool getRunning() const;    //현재 프로그램이 실행 중인지의 여부를 true, false로 리턴한다.
    void getUserInput();  //유저의 입력을 받아 메뉴를 고르게 하고, 이후 addAShape, deleteAShape 등을 호출한다.
    void addAShape() const; //유저의 입력을 받아 새 도형을 추가한다.
    void deleteAShape() const;  //유저의 입력을 받아 도형 삭제를 진행한다.
};

#endif //OOP_ASSN3_1_MENU_H
