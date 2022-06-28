#ifndef OOP_ASSN2_2_RIDER_H
#define OOP_ASSN2_2_RIDER_H

#include <iostream>
using namespace std;

class Rider {
private:
    float money;//��� ��簡 ���� ��
    float earnMoney;//��� ��簡 �� ���� �� �ջ�
    float time;// ���� ����ϴµ� �ɸ� �� �ð�
public:
    Rider();
    //�⺻ ������. money, earnMoney, time ��� 0 ���� �ʱ�ȭ�Ѵ�.
    Rider(float money, float earnMoney, float time);
    //��� ���� money, earnMoney, time �� �Է� ������ �����Ѵ�.
    Rider(const Rider& rider);
    //���� ������.
    ~Rider();
    //�Ҹ���. �Լ� ���� ���ٸ� ������ �ʿ� �����ϴ�.
    float reportMoney() const;
    //��� ��簡 ������� �� ���� �� �ջ��� �����Ѵ�.
    float reportTime() const;
    //��� ��簡 ������� ���ڸ� ����ϴµ� �ɸ� �� �ð��� �����Ѵ�.
    void deliver(float price, float time);
    //������ ���� ���ݸ�ŭ ���� ������, ������ ��� �ð���ŭ �� ��� �ð��� �����ش�.
    friend std::ostream& operator <<(std::ostream& os, const Rider& x);
    //�ܼ� â�� �Ʒ��� ���� ��µǵ��� �����ε��� ���� �����Ѵ�. ���� ��ȣ([ ])�� ������ �ǹ��Ѵ�. (���� ��[��, ��]�� �� ����� �ʿ� ����)
};
#endif //OOP_ASSN2_2_RIDER_H