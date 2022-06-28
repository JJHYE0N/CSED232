#ifndef OOP_ASSN3_1_WHITEBOARD_H
#define OOP_ASSN3_1_WHITEBOARD_H

class WhiteBoard {
private:
    char board[15][15]; //char�� 15*15 ���带 �����.
public:
    WhiteBoard();   //������
    ~WhiteBoard();  //�Ҹ���
    void fillPoint(int x, int y, char alphabet); //������ x,y ��ǥ�� ���� alphabet ���� ĭ�� ä���.
    void reset();    //��� ĭ�� *�� �ʱ�ȭ�Ѵ�.
    void display() const;    //whiteboard �� ����Ѵ�.
};

#endif //OOP_ASSN3_1_WHITEBOARD_H
