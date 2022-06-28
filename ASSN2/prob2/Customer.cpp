#include <iostream>
#include "Customer.h"
//#include "Pizza.h"

Customer::Customer() {
    this->money = 1000;
    this->paidMoney = 0;
    this->time = 0;
}
//기본 생성자. money, paidMoney, time 각각 1000, 0, 0 으로 초기화한다.
Customer::Customer(float money, float paidMoney, float time) {
    this->money = money;
    this->paidMoney = paidMoney;
    this->time = time;
}
//멤버 변수 money, paidMoney, time 을 입력 값으로 설정한다.
Customer::Customer(const Customer& customer) {
    this->money = customer.money;
    this->paidMoney = customer.paidMoney;
    this->time = customer.time;
}
//복사 생성자.
Customer::~Customer() { }
//소멸자. 함수 내에 별다른 구현은 필요 없습니다.
float Customer::reportMoney() const {
    return paidMoney;
}
//고객이 현재까지 지불한 돈의 총 합을 리턴한다.
float Customer::reportTime() const {
    return time;
}
//고객이 현재까지 피자를 배달 받는데 걸린 총 시간을 리턴한다.
void Customer::pay(float price, float time) {
    money -= price;
    paidMoney += price;
    Customer::time += time;
}
//피자 가게에 정해진 피자 가격만큼 돈을 지불하며, 정해진 배달 시간만큼 총 배달 시간에 더해준다.
std::ostream& operator <<(std::ostream& os, const Customer& x) {
    os << "(money, paidMoney, time) : (" << x.money << ", " << x.paidMoney << ", " << x.time << ")" << std::endl;
    return os;
    /*
    (money, paidMoney, time) : ([money], [paidMoney], [time])
    */
}
//콘솔 창에 아래와 같이 출력되도록 오버로딩을 통해 구현한다. 꺾쇠 괄호([ ])는 변수를 의미한다. (꺾쇠 ‘[‘, ‘]’ 는 출력할 필요 없음)