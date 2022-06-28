#include <iostream>
#include "Menu.h"
#include "WhiteBoard.h"

Menu::Menu(WhiteBoard* board, AShapeList* shape_list) {
    is_running = 1;//�������̹Ƿ� �⺻���� 1�� �ʱ�ȭ�Ѵ�.
    Menu::board = board;
    Menu::shape_list = shape_list;
}//������

Menu::~Menu() {
}//�Ҹ���

void Menu::display() const {
    std::cout << "=============\n";
    std::cout << "[Select Menu]\n";
    std::cout << "=============\n";
    std::cout << "1. add new shape\n";
    std::cout << "2. delete existing shape\n";
    std::cout << "3. exit\n>>";
}//�޴��� ����Ѵ�.

bool Menu::getRunning() const {
    return is_running;
}//���� ���α׷��� ���� �������� ���θ� true, false�� �����Ѵ�.

void Menu::getUserInput() {
    int answer;
    std::cin >> answer;
    switch (answer) {
    case 1: addAShape(); break;//addAShape ȣ��
    case 2: deleteAShape(); break;//deleteAShape ȣ��
    case 3: std::cout << "Exit program"; is_running = 0; break;   //Exit program
    default: std::cout << "Error: Invalid input. Type again\n"; break; //�̿��� �Է��� ��� ���
    }
}//������ �Է��� �޾� �޴��� ���� �ϰ�, ���� addAShape, deleteAShape ���� ȣ���Ѵ�.

void Menu::addAShape() const {
    char _alphabet_;
    int _x_start_, _y_start_, _x_end_, _y_end_;    //x,y,alphabet �� ������ ������ �����ϰ� �Է¹޴´�.
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

    //����ó��
    if (_x_start_ > _x_end_) {   //x_start �� x_end ���� ū ���
        std::cout << "Error: x_start exceed x_end\n";
    }
    else if (_y_start_ > _y_end_) { //y_start �� y_end ���� ū ���
        std::cout << "Error: y_start exceed y_end\n";
    }
    else if (_x_start_ < 0 || _x_end_ < 0 || _y_start_ < 0 || _y_end_ < 0) { //��ǥ�߿� �ϳ��� ������ ������ ���
        std::cout << "Error: coordinate cannot be negative value\n";
    }
    else if (_x_start_ > 14 || _y_start_ > 14 || _x_end_ > 14 || _y_end_ > 14) {  //��ǥ�߿� �ϳ��� ȭ��Ʈ������ ũ�⸦ ����� ���
        std::cout << "Error: your input exceed whiteboard size\n";
    }

    else {  //�۾� ����
        if (_x_end_ - _x_start_ == 0 && _y_end_ - _y_start_ == 0) {  //APoint�� �ش��ϴ� �����ڿ� addNewAShape ȣ��
            APoint* temp = new APoint(_x_start_, _y_start_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
        else if (_x_end_ - _x_start_ == 0 && _y_end_ - _y_start_ > 0) { //AVerticalLine�� �ش��ϴ� �����ڿ� addNewAShape ȣ��
            AVerticalLine* temp = new AVerticalLine(_x_start_, _y_start_, _y_end_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
        else if (_x_end_ - _x_start_ > 0 && _y_end_ - _y_start_ == 0) {  //AHorizontalLine�� �ش��ϴ� �����ڿ� addNewAShape ȣ��
            AHorizontalLine* temp = new AHorizontalLine(_y_start_, _x_start_, _x_end_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
        else if (_x_end_ - _x_start_ > 0 && _y_end_ - _y_start_ > 0) {  //ARectangle�� �ش��ϴ� �����ڿ� addNewAShape ȣ��
            ARectangle* temp = new ARectangle(_x_start_, _x_end_, _y_start_, _y_end_, _alphabet_);
            shape_list->addNewAShape(temp);
        }
    }
}//������ �Է��� �޾� �� ������ �߰��Ѵ�.

void Menu::deleteAShape() const {
    int del_select;
    if (shape_list->getSize() == 0) {  //���� ����Ʈ�� ����ִ� ���
        std::cout << "AShapeList is empty.\n";
    }
    else {
        std::cout << "Choose index of AShape that you want to remove\n";
        std::cout << "[========List of AShape======]\n";
        std::cout << "Current Size: " << shape_list->getSize() << "\n";
        shape_list->displayAShapeList();    //AShapeList�� �ش��ϴ� ����Ʈ�� ��� ǥ���Ѵ�.
        std::cout << ">>";
        std::cin >> del_select; //del_select�� �ش��ϴ� �Է��� �޴´�.

        if (del_select < 0 || del_select > shape_list->getSize() - 1) {   //�Է� ���� ���� ���� ���
            std::cout << "Error: Index exceed size of AShapeList\n";
        }
        else {
            //���� ����
            delete shape_list->popNodeByIdx(del_select);    //�Ҵ������Ѵ�.
        }
    }
}//������ �Է��� �޾� ���� ������ �����Ѵ�.(���� ���� ������ �����ϸ� ������ ������ �ٽ� �������Ѵ�.)