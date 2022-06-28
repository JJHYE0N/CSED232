#ifndef OOP_ASSN3_1_WHITEBOARD_H
#define OOP_ASSN3_1_WHITEBOARD_H

class WhiteBoard {
private:
    char board[15][15]; //char형 15*15 보드를 만든다.
public:
    WhiteBoard();   //생성자
    ~WhiteBoard();  //소멸자
    void fillPoint(int x, int y, char alphabet); //지정된 x,y 좌표에 들어온 alphabet 으로 칸을 채운다.
    void reset();    //모든 칸을 *로 초기화한다.
    void display() const;    //whiteboard 를 출력한다.
};

#endif //OOP_ASSN3_1_WHITEBOARD_H
