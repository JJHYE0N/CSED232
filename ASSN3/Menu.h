#ifndef OOP_ASSN3_1_MENU_H
#define OOP_ASSN3_1_MENU_H
#include "WhiteBoard.h"
#include "AShapeList.h"

class Menu {
private:
    bool is_running;//���� ���α׷��� ���� �������� ���θ� true, false�� �����Ѵ�.
    AShapeList* shape_list;//AShapeList shape_list ����
    WhiteBoard* board;//WhiteBoard* board ����
public:
    Menu(WhiteBoard* board, AShapeList* shape_list);//������
    ~Menu();//�Ҹ���
    void display() const;   //�޴��� ����Ѵ�.
    bool getRunning() const;    //���� ���α׷��� ���� �������� ���θ� true, false�� �����Ѵ�.
    void getUserInput();  //������ �Է��� �޾� �޴��� ���� �ϰ�, ���� addAShape, deleteAShape ���� ȣ���Ѵ�.
    void addAShape() const; //������ �Է��� �޾� �� ������ �߰��Ѵ�.
    void deleteAShape() const;  //������ �Է��� �޾� ���� ������ �����Ѵ�.
};

#endif //OOP_ASSN3_1_MENU_H
