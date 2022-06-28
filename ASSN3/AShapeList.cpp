#include <iostream>
#include "AShapeList.h"

AShapeList::AShapeList() {
    size = 0;
    head = NULL;
    tail = NULL;
}//�⺻ ������ size=0, �����ʹ� NULL�� ����Ű���� �Ѵ�.
AShapeList::~AShapeList() {
}//�Ҹ���
void AShapeList::addNewAShape(AShape* new_shape) {
    AShapeNode* temp = new AShapeNode;//������ AShapeNode�� �����Ҵ� �Ѵ�.
    temp->shape = new_shape;//temp�� shape�� argument�� �� new_shape�� �Ѵ�.
    temp->next = NULL;
    if (size == 0) {//empty�� ��� temp�� ��� head,tail�� �����Ѵ�.
        head = temp;
        tail = temp;
    }
    else {//element�� �����Ұ��
        tail->next = temp;//tail�� ������ temp�� �������ϰ�,
        tail = temp;//tail�� temp�� ������Ʈ�Ѵ�.
    }
    size += 1;//�� element�� �߰��Ǿ��� ������ size +1 ���ش�.
}    //����Ʈ�� �� ������ �߰��Ѵ�.
AShapeNode* AShapeList::popNodeByIdx(int idx) {
    AShapeNode* pPre = new AShapeNode;  //idex-1�� ������ ��带 ���� �����Ҵ� �����Ѵ�.
    AShapeNode* pCur = new AShapeNode;  //idx�� ������ ��带 ���� �����Ҵ� �����Ѵ�.
    pPre = head;  //pPre�� head�� �ϰ�
    pCur = pPre->next;    //pCur�� pPre�� next�� �Ѵ�.

    if (idx == 0) { //idx�� 0�� ���
        head = pPre->next;//head�� ���� head�� ������ ��Ÿ����
        size -= 1;//size�� 1 ���δ�.
        return pPre;//���� ����� �����͸� �����Ѵ�.
    }
    else {
        for (int i = 0; pCur != NULL; i++) {
            if (idx - 1 == i) {     //idx-1�� i�� ���� ���
                pPre->next = pCur->next;    //pPre->next=pCur->next�� �Ѵ�.
                break;//������ ���� ���´�.
            }
            pPre = pPre->next;  //pPre = pPre->next�� ������Ʈ�Ѵ�.
            pCur = pCur->next;  //pCur = pCur->next�� ������Ʈ�Ѵ�.
        }
        size -= 1;//size�� 1 ���δ�.
        return pCur;//���� ����� �����͸� �����Ѵ�.
    }
}
//�ε����� �޾� ����Ʈ���� �ش� AShapeNode �� ������, ���� ����� �����͸� �����Ѵ�. (ex) idx 0 �� ���ö� ù��° Node �� �����Ѵ�.
const AShapeNode* AShapeList::getNodeByIdx(int idx) const {
    AShapeNode* pCur = new AShapeNode;  //��带 ���� �����Ҵ� �����Ѵ�.
    pCur = head;  //pCur�� head�� �ʱ�ȭ �Ѵ�.
    for (int i = 0; pCur != NULL; i++) {    //loop�� �̿��Ͽ� idx�� �ش��ϴ� node�� pCur�� ������ش�.
        if (idx == i) {
            break;
        }
        pCur = pCur->next;
    }
    return pCur;//idx�� �ش��ϴ� �����͸� �����Ѵ�.
}   //�ε����� �޾� ����Ʈ���� �ε����� �ش��ϴ� ������ AShapeNode �� �����͸� �����Ѵ�. popNodeByIdx �� �޸�, ��带 ����Ʈ���� ���� �ʴ´�.
void AShapeList::displayAShapeList() const {
    AShapeNode* temp = new AShapeNode;//��带 ���� �����Ҵ� �Ѵ�.
    temp = head;//head�� ����Ű�� �Ѵ�.
    for (int i = 0; i < size; i++) {    //loop�� �̿��Ͽ� shape�� print�Լ��� ����Ͽ� ��� ������ ����Ʈ�� ����ϵ��� �Ѵ�.
        std::cout << i;
        temp->shape->print();
        temp = temp->next;
    }

}    //���� �������� ��� ������ ����Ʈ�� ����Ѵ�. ���� ���� �� ������ ������ �Ѳ����� ����� �� ���δ�.
void AShapeList::drawAll(WhiteBoard* board) const {
    AShapeNode* temp = new AShapeNode;
    for (temp = head; temp != NULL; temp = temp->next) {
        temp->shape->draw(board);//�ش��ϴ� shape�� ���� draw�� �׸���.
    }
}   //���� �������� ��� ������ WhiteBoard �� �׸���.
int AShapeList::getSize() const {
    return size;
} //���� ����Ʈ�� ���� �ִ� ������ ������ �����Ѵ�.