#include <iostream>
#include "WhiteBoard.h"

WhiteBoard::WhiteBoard() {  //생성자
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board[i][j] = 'a';   //기본 'a'로 board를 초기화한다.
        }
    }
}
WhiteBoard::~WhiteBoard() { //소멸자
}

void WhiteBoard::fillPoint(int x, int y, char alphabet) {
    board[y][x] = alphabet;
} //지정된 x,y 좌표에 들어온 alphabet 으로 칸을 채운다.
void WhiteBoard::reset() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board[i][j] = '*';
        }
    }
}    //모든 칸을 *로 초기화한다.
void WhiteBoard::display() const {
    std::cout << "[WhiteBoard]\n";
    std::cout << "===============\n";
    //보드 출력
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "===============\n";
}    //whiteboard 를 출력한다.