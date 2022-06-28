#include "Rider.h"
#include <iostream>

Rider::Rider() {
    this->money = 0;
    this->earnMoney = 0;
    this->time = 0;
}
//�⺻ ������. money, earnMoney, time ��� 0 ���� �ʱ�ȭ�Ѵ�.
Rider::Rider(float money, float earnMoney, float time) {
    this->money = money;
    this->earnMoney = earnMoney;
    this->time = time;
}
//��� ���� money, earnMoney, time �� �Է� ������ �����Ѵ�.
Rider::Rider(const Rider& rider) {
    this->money = rider.money;
    this->earnMoney = rider.earnMoney;
    this->time = rider.time;
}
//���� ������.
Rider::~Rider() { }
//�Ҹ���. �Լ� ���� ���ٸ� ������ �ʿ� �����ϴ�.
float Rider::reportMoney() const {
    return earnMoney;
}
//��� ��簡 ������� �� ���� �� �ջ��� �����Ѵ�.
float Rider::reportTime() const {
    return time;
}
//��� ��簡 ������� ���ڸ� ����ϴµ� �ɸ� �� �ð��� �����Ѵ�.
void Rider::deliver(float price, float time) {
    money += price;
    earnMoney += price;
    Rider::time += time;
}
//������ ���� ���ݸ�ŭ ���� ������, ������ ��� �ð���ŭ �� ��� �ð��� �����ش�.
std::ostream& operator <<(std::ostream& os, const Rider& x) {
    os << "(money, earnMoney, time) : (" << x.money << ", " << x.earnMoney << ", " << x.time << std::endl;
    return os;
    /*
    (money, earnMoney, time) : ([money], [earnMoney], [time])
    �� ���� ��µǵ����Ѵ�.
    */
}
//�ܼ� â�� �Ʒ��� ���� ��µǵ��� �����ε��� ���� �����Ѵ�. ���� ��ȣ([ ])�� ������ �ǹ��Ѵ�. (���� ��[��, ��]�� �� ����� �ʿ� ����)