#include <iostream>
#include "AShapeList.h"

AShapeList::AShapeList() {
    size = 0;
    head = NULL;
    tail = NULL;
}//기본 생성자 size=0, 포인터는 NULL를 가리키도록 한다.
AShapeList::~AShapeList() {
}//소멸자
void AShapeList::addNewAShape(AShape* new_shape) {
    AShapeNode* temp = new AShapeNode;//임의의 AShapeNode를 동적할당 한다.
    temp->shape = new_shape;//temp의 shape는 argument로 온 new_shape로 한다.
    temp->next = NULL;
    if (size == 0) {//empty일 경우 temp를 모두 head,tail로 설정한다.
        head = temp;
        tail = temp;
    }
    else {//element가 존재할경우
        tail->next = temp;//tail의 다음을 temp가 오도록하고,
        tail = temp;//tail은 temp로 업데이트한다.
    }
    size += 1;//새 element가 추가되었기 때문에 size +1 해준다.
}    //리스트에 새 도형을 추가한다.
AShapeNode* AShapeList::popNodeByIdx(int idx) {
    AShapeNode* pPre = new AShapeNode;  //idex-1을 만족할 노드를 새로 동적할당 선언한다.
    AShapeNode* pCur = new AShapeNode;  //idx을 만족할 노드를 새로 동적할당 선언한다.
    pPre = head;  //pPre는 head로 하고
    pCur = pPre->next;    //pCur은 pPre의 next로 한다.

    if (idx == 0) { //idx가 0일 경우
        head = pPre->next;//head는 기존 head의 다음을 나타내고
        size -= 1;//size를 1 줄인다.
        return pPre;//빼낸 노드의 포인터를 리턴한다.
    }
    else {
        for (int i = 0; pCur != NULL; i++) {
            if (idx - 1 == i) {     //idx-1이 i와 같을 경우
                pPre->next = pCur->next;    //pPre->next=pCur->next로 한다.
                break;//루프를 빠져 나온다.
            }
            pPre = pPre->next;  //pPre = pPre->next로 업데이트한다.
            pCur = pCur->next;  //pCur = pCur->next로 업데이트한다.
        }
        size -= 1;//size를 1 줄인다.
        return pCur;//빼낸 노드의 포인터를 리턴한다.
    }
}
//인덱스를 받아 리스트에서 해당 AShapeNode 를 빼내고, 빼낸 노드의 포인터를 리턴한다. (ex) idx 0 이 들어올때 첫번째 Node 를 리턴한다.
const AShapeNode* AShapeList::getNodeByIdx(int idx) const {
    AShapeNode* pCur = new AShapeNode;  //노드를 새로 동적할당 선언한다.
    pCur = head;  //pCur을 head로 초기화 한다.
    for (int i = 0; pCur != NULL; i++) {    //loop를 이용하여 idx에 해당하는 node로 pCur를 만들어준다.
        if (idx == i) {
            break;
        }
        pCur = pCur->next;
    }
    return pCur;//idx에 해당하는 포인터를 리턴한다.
}   //인덱스를 받아 리스트에서 인덱스에 해당하는 순번의 AShapeNode 의 포인터를 리턴한다. popNodeByIdx 와 달리, 노드를 리스트에서 빼지 않는다.
void AShapeList::displayAShapeList() const {
    AShapeNode* temp = new AShapeNode;//노드를 새로 동적할당 한다.
    temp = head;//head를 가리키게 한다.
    for (int i = 0; i < size; i++) {    //loop를 이용하여 shape의 print함수를 출력하여 모든 도형의 리스트를 출력하도록 한다.
        std::cout << i;
        temp->shape->print();
        temp = temp->next;
    }

}    //현재 관리중인 모든 도형의 리스트를 출력한다. 도형 삭제 시 도형의 정보를 한꺼번에 출력할 때 쓰인다.
void AShapeList::drawAll(WhiteBoard* board) const {
    AShapeNode* temp = new AShapeNode;
    for (temp = head; temp != NULL; temp = temp->next) {
        temp->shape->draw(board);//해당하는 shape에 대한 draw를 그린다.
    }
}   //현재 관리중인 모든 도형을 WhiteBoard 에 그린다.
int AShapeList::getSize() const {
    return size;
} //현재 리스트가 갖고 있는 도형의 개수를 리턴한다.