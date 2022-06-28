#ifndef OOP_ASSN3_1_ASHAPELIST_H
#define OOP_ASSN3_1_ASHAPELIST_H
#include "WhiteBoard.h"
#include "AShape.h"

struct AShapeNode { //AShapeNode 구조체를 선언한다.
    AShape* shape;//shape에 해당하는 정보와
    AShapeNode* next;//next에 해당하는 정보 설정
};

class AShapeList {
private://haed, tail을 선언하고, size를 선언한다.
    AShapeNode* head;
    AShapeNode* tail;
    int size;
public:
    AShapeList();//생성자
    ~AShapeList();//소멸자
    void addNewAShape(AShape* new_shape);    //리스트에 새 도형을 추가한다.
    AShapeNode* popNodeByIdx(int idx);
    //인덱스를 받아 리스트에서 해당 AShapeNode 를 빼내고, 빼낸 노드의 포인터를 리턴한다. (ex) idx 0 이 들어올때 첫번째 Node 를 리턴한다.
    const AShapeNode* getNodeByIdx(int idx) const;   //인덱스를 받아 리스트에서 인덱스에 해당하는 순번의 AShapeNode 의 포인터를 리턴한다. popNodeByIdx 와 달리, 노드를 리스트에서 빼지 않는다.
    void displayAShapeList() const;    //현재 관리중인 모든 도형의 리스트를 출력한다. 도형 삭제 시 도형의 정보를 한꺼번에 출력할 때 쓰인다.
    void drawAll(WhiteBoard* board) const;   //현재 관리중인 모든 도형을 WhiteBoard 에 그린다.
    int getSize() const; //현재 리스트가 갖고 있는 도형의 개수를 리턴한다.
};


#endif //OOP_ASSN3_1_ASHAPELIST_H
