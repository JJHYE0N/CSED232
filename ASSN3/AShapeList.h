#ifndef OOP_ASSN3_1_ASHAPELIST_H
#define OOP_ASSN3_1_ASHAPELIST_H
#include "WhiteBoard.h"
#include "AShape.h"

struct AShapeNode { //AShapeNode ����ü�� �����Ѵ�.
    AShape* shape;//shape�� �ش��ϴ� ������
    AShapeNode* next;//next�� �ش��ϴ� ���� ����
};

class AShapeList {
private://haed, tail�� �����ϰ�, size�� �����Ѵ�.
    AShapeNode* head;
    AShapeNode* tail;
    int size;
public:
    AShapeList();//������
    ~AShapeList();//�Ҹ���
    void addNewAShape(AShape* new_shape);    //����Ʈ�� �� ������ �߰��Ѵ�.
    AShapeNode* popNodeByIdx(int idx);
    //�ε����� �޾� ����Ʈ���� �ش� AShapeNode �� ������, ���� ����� �����͸� �����Ѵ�. (ex) idx 0 �� ���ö� ù��° Node �� �����Ѵ�.
    const AShapeNode* getNodeByIdx(int idx) const;   //�ε����� �޾� ����Ʈ���� �ε����� �ش��ϴ� ������ AShapeNode �� �����͸� �����Ѵ�. popNodeByIdx �� �޸�, ��带 ����Ʈ���� ���� �ʴ´�.
    void displayAShapeList() const;    //���� �������� ��� ������ ����Ʈ�� ����Ѵ�. ���� ���� �� ������ ������ �Ѳ����� ����� �� ���δ�.
    void drawAll(WhiteBoard* board) const;   //���� �������� ��� ������ WhiteBoard �� �׸���.
    int getSize() const; //���� ����Ʈ�� ���� �ִ� ������ ������ �����Ѵ�.
};


#endif //OOP_ASSN3_1_ASHAPELIST_H
