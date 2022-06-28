#ifndef OOP_ASSN3_1_ASHAPE_H
#define OOP_ASSN3_1_ASHAPE_H
#include "WhiteBoard.h"

class AShape {
private:

protected:
    char alphabet;  //char�� alphabet
public:
    AShape();//������
    virtual ~AShape();//�Ҹ���
    virtual void draw(WhiteBoard* board) const = 0;
    //ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
    virtual void print() const = 0;
    //�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
    //������ ��� AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] �̿� ���� ����ϸ� �ȴ�.
    // �ݵ�� ���� ���� ������� ����� �ʿ�� ����, �ʿ��� ������ ��������� �ȴ�.
    virtual int size() const = 0;
    //������ ũ�⸦ �����ϴ� �Լ�. ���� ��� 1, ���� ��쿣 ���� ����, �簢���� ��쿡�� �簢���� �����̴�.
};

class APoint : public AShape {
private:    //x,y�� ���� ���� private������ ����
    int x;
    int y;
public:
    APoint();//������
    APoint(int x_, int y_, char alphabet_);//������
    ~APoint();//�Ҹ���
    void draw(WhiteBoard* board) const;
    //ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
    void print() const;
    //�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
    //������ ��� AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] �̿� ���� ����ϸ� �ȴ�.
    // �ݵ�� ���� ���� ������� ����� �ʿ�� ����, �ʿ��� ������ ��������� �ȴ�.
    int size() const;
    //������ ũ�⸦ �����ϴ� �Լ�. ���� ��� 1, ���� ��쿣 ���� ����, �簢���� ��쿡�� �簢���� �����̴�.
};

class AVerticalLine : public AShape {
private:    //x,y�� ���� ���� private������ ����
    int x;
    int y_start;
    int y_end;
public:
    AVerticalLine();//������
    AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);//������
    ~AVerticalLine();//�Ҹ���
    void draw(WhiteBoard* board) const;
    //ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
    void print() const;
    //�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
    //������ ��� AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] �̿� ���� ����ϸ� �ȴ�.
    // �ݵ�� ���� ���� ������� ����� �ʿ�� ����, �ʿ��� ������ ��������� �ȴ�.
    int size() const;
    //������ ũ�⸦ �����ϴ� �Լ�. ���� ��� 1, ���� ��쿣 ���� ����, �簢���� ��쿡�� �簢���� �����̴�.
    //void draw(WhiteBoard *board) const;
};

class AHorizontalLine : public AShape {
private:    //x,y�� ���� ���� private������ ����
    int y;
    int x_start;
    int x_end;
public:
    AHorizontalLine();//������
    AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);//������
    ~AHorizontalLine();//�Ҹ���
    void draw(WhiteBoard* board) const;
    //ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
    void print() const;
    //�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
    //������ ��� AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] �̿� ���� ����ϸ� �ȴ�.
    // �ݵ�� ���� ���� ������� ����� �ʿ�� ����, �ʿ��� ������ ��������� �ȴ�.
    int size() const;
    //������ ũ�⸦ �����ϴ� �Լ�. ���� ��� 1, ���� ��쿣 ���� ����, �簢���� ��쿡�� �簢���� �����̴�.
};

class ARectangle : public AShape {
private:    //x,y�� ���� ���� private������ ����
    int x_start;
    int x_end;
    int y_start;
    int y_end;
public:
    ARectangle();//������
    ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);//������
    ~ARectangle();//�Ҹ���
    void draw(WhiteBoard* board) const;
    //ȭ��Ʈ���忡 �ش� ������ ��ǥ �� ���ĺ��� ������ ���� �׸��� �Ѵ�.
    void print() const;
    //�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�. ���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�.
    //������ ��� AHorizontalLine with [alphabet: q] and [y: 13] [x_start: 10 ] [x_end: 12] [size: 3] �̿� ���� ����ϸ� �ȴ�.
    // �ݵ�� ���� ���� ������� ����� �ʿ�� ����, �ʿ��� ������ ��������� �ȴ�.
    int size() const;
    //������ ũ�⸦ �����ϴ� �Լ�. ���� ��� 1, ���� ��쿣 ���� ����, �簢���� ��쿡�� �簢���� �����̴�.
};

#endif //OOP_ASSN3_1_ASHAPE_H
