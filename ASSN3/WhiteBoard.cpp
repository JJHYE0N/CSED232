#include <iostream>
#include "WhiteBoard.h"

WhiteBoard::WhiteBoard() {  //������
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board[i][j] = 'a';   //�⺻ 'a'�� board�� �ʱ�ȭ�Ѵ�.
        }
    }
}
WhiteBoard::~WhiteBoard() { //�Ҹ���
}

void WhiteBoard::fillPoint(int x, int y, char alphabet) {
    board[y][x] = alphabet;
} //������ x,y ��ǥ�� ���� alphabet ���� ĭ�� ä���.
void WhiteBoard::reset() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board[i][j] = '*';
        }
    }
}    //��� ĭ�� *�� �ʱ�ȭ�Ѵ�.
void WhiteBoard::display() const {
    std::cout << "[WhiteBoard]\n";
    std::cout << "===============\n";
    //���� ���
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "===============\n";
}    //whiteboard �� ����Ѵ�.