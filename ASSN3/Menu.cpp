#include <iostream>
#include "Menu.h"
#include "WhiteBoard.h"

Menu::Menu(WhiteBoard* board, AShapeList* shape_list) {
    is_running = 1;//실행중이므로 기본값은 1로 초기화한다.
    Menu::board = board;
    Menu::shape_list = shape_list;
}//생성자

Menu::~Menu() {
}//소멸자

void Menu::display() const {
    std::cout << "=============\n";
    std::cout << "[Select Menu]\n";
    std::cout << "=============\n";
    std::cout << "1. add new shape\n";
    std::cout << "2. delete existing shape\n";
    std::cout << "3. exit\n>>";
}//메뉴를 출력한다.

bool Menu::getRunning() const {
    return is_running;
}//현재 프로그램이 실행 중인지의 여부를 true, false로 리턴한다.

void Menu::getUserInput() {
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1: addAShape(); break;//addAShape 호출
    case 2: deleteAShape(); break;//deleteAShape 호출
    case 3: std::cout << "Exit program"; is_running = 0; break;   //Exit program
    default: std::cout << "Error: Invalid input. Type again\n"; break; //이외의 입력일 경우 출력
    }
}//유저의 입력을 받아 메뉴를 고르게 하고, 이후 addAShape, deleteAShape 등을 호출한다.

void Menu::addAShape() const {
    char _alphabet_;
    int _x_start_, _y_start_, _x_end_, _y_end_;    //x,y,alphabet 와 관련한 정보를 선언하고 입력받는다.
    std::cout << "[Add New AShape]\n";
    std::cout << "Enter Alphabet >>";
    std::cin >> _alphabet_;
    std::cout << "Enter x_start >>";
    std::cin >> _x_start_;
    std::cout << "Enter x_end >>";
    std::cin >> _x_end_;
    std::cout << "Enter y_start >>";
    std::cin >> _y_start_;
    std::cout << "Enter y_end >>";
    std::cin >> _y_end_;

    //예외처리
    if (_x_start_ > _x_end_) {   //x_start 가 x_end 보다 큰 경우
        std::cout << "Error: x_start exceed x_end\n";
    }
    else if (_y_start_ > _y_end_) { //y_start 가 y_end 보다 큰 경우
        std::cout << "Error: y_start exceed y_end\n";
    }
    else if (_x_start_ < 0 || _x_end_ < 0 || _y_start_ < 0 || _y_end_ < 0) { //좌표중에 하나라도 음수가 들어오는 경우
        std::cout << "Error: coordinate cannot be negative value\n";
    }
    else if (_x_start_ > 14 || _y_start_ > 14 || _x_end_ > 14 || _y_end_ > 14) {  //좌표중에 하나라도 화이트보드의 크기를 벗어나는 경우
        std::cout << "Error: your input exceed whiteboard size\n";
    }

    else {  //작업 시작
        if (_x_end_ - _x_start_ == 0 && _y_end_ - _y_start_ == 0) {  //APoint에 해당하는 생성자와 addNewAShape 호출
            APoint* temp = new APoint(_x_start_, _y_start_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
        else if (_x_end_ - _x_start_ == 0 && _y_end_ - _y_start_ > 0) { //AVerticalLine에 해당하는 생성자와 addNewAShape 호출
            AVerticalLine* temp = new AVerticalLine(_x_start_, _y_start_, _y_end_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
        else if (_x_end_ - _x_start_ > 0 && _y_end_ - _y_start_ == 0) {  //AHorizontalLine에 해당하는 생성자와 addNewAShape 호출
            AHorizontalLine* temp = new AHorizontalLine(_y_start_, _x_start_, _x_end_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
        else if (_x_end_ - _x_start_ > 0 && _y_end_ - _y_start_ > 0) {  //ARectangle에 해당하는 생성자와 addNewAShape 호출
            ARectangle* temp = new ARectangle(_x_start_, _x_end_, _y_start_, _y_end_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
    }
}//유저의 입력을 받아 새 도형을 추가한다.

void Menu::deleteAShape() const {
    int del_select;
    if (shape_list->getSize() == 0) {  //도형 리스트가 비어있는 경우
        std::cout << "AShapeList is empty.\n";
    }
    else {
        std::cout << "Choose index of AShape that you want to remove\n";
        std::cout << "[========List of AShape======]\n";
        std::cout << "Current Size: " << shape_list->getSize() << "\n";
        shape_list->displayAShapeList();    //AShapeList에 해당하는 리스트를 모두 표시한다.
        std::cout << ">>";
        std::cin >> del_select; //del_select에 해당하는 입력을 받는다.

        if (del_select < 0 || del_select > shape_list->getSize() - 1) {   //입력 값에 범위 밖일 경우
            std::cout << "Error: Index exceed size of AShapeList\n";
        }
        else {
            //삭제 동작
            delete shape_list->popNodeByIdx(del_select);    //할당해제한다.
        }
    }
}//유저의 입력을 받아 도형 삭제를 진행한다.(위를 덮은 도형을 삭제하면 기존의 도형이 다시 보여야한다.)