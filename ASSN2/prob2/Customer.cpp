#include <iostream>
#include "Customer.h"
//#include "Pizza.h"

Customer::Customer() {
    this->money = 1000;
    this->paidMoney = 0;
    this->time = 0;
}
//�⺻ ������. money, paidMoney, time ���� 1000, 0, 0 ���� �ʱ�ȭ�Ѵ�.
Customer::Customer(float money, float paidMoney, float time) {
    this->money = money;
    this->paidMoney = paidMoney;
    this->time = time;
}
//��� ���� money, paidMoney, time �� �Է� ������ �����Ѵ�.
Customer::Customer(const Customer& customer) {
    this->money = customer.money;
    this->paidMoney = customer.paidMoney;
    this->time = customer.time;
}
//���� ������.
Customer::~Customer() { }
//�Ҹ���. �Լ� ���� ���ٸ� ������ �ʿ� �����ϴ�.
float Customer::reportMoney() const {
    return paidMoney;
}
//���� ������� ������ ���� �� ���� �����Ѵ�.
float Customer::reportTime() const {
    return time;
}
//���� ������� ���ڸ� ��� �޴µ� �ɸ� �� �ð��� �����Ѵ�.
void Customer::pay(float price, float time) {
    money -= price;
    paidMoney += price;
    Customer::time += time;
}
//���� ���Կ� ������ ���� ���ݸ�ŭ ���� �����ϸ�, ������ ��� �ð���ŭ �� ��� �ð��� �����ش�.
std::ostream& operator <<(std::ostream& os, const Customer& x) {
    os << "(money, paidMoney, time) : (" << x.money << ", " << x.paidMoney << ", " << x.time << ")" << std::endl;
    return os;
    /*
    (money, paidMoney, time) : ([money], [paidMoney], [time])
    */
}
//�ܼ� â�� �Ʒ��� ���� ��µǵ��� �����ε��� ���� �����Ѵ�. ���� ��ȣ([ ])�� ������ �ǹ��Ѵ�. (���� ��[��, ��]�� �� ����� �ʿ� ����)