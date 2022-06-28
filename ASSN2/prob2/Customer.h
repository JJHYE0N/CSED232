#ifndef OOP_ASSN2_2_CUSTOMER_H
#define OOP_ASSN2_2_CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
private:
    float money;//���� ���� ���� ��
    float paidMoney;//���� ������ ���� �� �ջ�
    float time;//���� ���� ��� �޴µ� �ɸ� �� �ð�
public:
    Customer();
    //�⺻ ������. money, paidMoney, time ���� 1000, 0, 0 ���� �ʱ�ȭ�Ѵ�.
    Customer(float money, float paidMoney, float time);
    //��� ���� money, paidMoney, time �� �Է� ������ �����Ѵ�.
    Customer(const Customer& customer);
    //���� ������.
    ~Customer();
    //�Ҹ���. �Լ� ���� ���ٸ� ������ �ʿ� �����ϴ�.
    float reportMoney() const;
    //���� ������� ������ ���� �� ���� �����Ѵ�.
    float reportTime() const;
    //���� ������� ���ڸ� ��� �޴µ� �ɸ� �� �ð��� �����Ѵ�.
    void pay(float price, float time);
    //���� ���Կ� ������ ���� ���ݸ�ŭ ���� �����ϸ�, ������ ��� �ð���ŭ �� ��� �ð��� �����ش�.
    friend std::ostream& operator <<(std::ostream& os, const Customer& x);
    //�ܼ� â�� �Ʒ��� ���� ��µǵ��� �����ε��� ���� �����Ѵ�. ���� ��ȣ([ ])�� ������ �ǹ��Ѵ�. (���� ��[��, ��]�� �� ����� �ʿ� ����)
};
#endif //OOP_ASSN2_2_CUSTOMER_H