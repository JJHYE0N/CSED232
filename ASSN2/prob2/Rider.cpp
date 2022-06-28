#include "Rider.h"
#include <iostream>

Rider::Rider() {
    this->money = 0;
    this->earnMoney = 0;
    this->time = 0;
}
//기본 생성자. money, earnMoney, time 모두 0 으로 초기화한다.
Rider::Rider(float money, float earnMoney, float time) {
    this->money = money;
    this->earnMoney = earnMoney;
    this->time = time;
}
//멤버 변수 money, earnMoney, time 을 입력 값으로 설정한다.
Rider::Rider(const Rider& rider) {
    this->money = rider.money;
    this->earnMoney = rider.earnMoney;
    this->time = rider.time;
}
//복사 생성자.
Rider::~Rider() { }
//소멸자. 함수 내에 별다른 구현은 필요 없습니다.
float Rider::reportMoney() const {
    return earnMoney;
}
//배달 기사가 현재까지 번 돈의 총 합산을 리턴한다.
float Rider::reportTime() const {
    return time;
}
//배달 기사가 현재까지 피자를 배달하는데 걸린 총 시간을 리턴한다.
void Rider::deliver(float price, float time) {
    money += price;
    earnMoney += price;
    Rider::time += time;
}
//정해진 피자 가격만큼 돈을 받으며, 정해진 배달 시간만큼 총 배달 시간에 더해준다.
std::ostream& operator <<(std::ostream& os, const Rider& x) {
    os << "(money, earnMoney, time) : (" << x.money << ", " << x.earnMoney << ", " << x.time << std::endl;
    return os;
    /*
    (money, earnMoney, time) : ([money], [earnMoney], [time])
    와 같이 출력되도록한다.
    */
}
//콘솔 창에 아래와 같이 출력되도록 오버로딩을 통해 구현한다. 꺾쇠 괄호([ ])는 변수를 의미한다. (꺾쇠 ‘[‘, ‘]’ 는 출력할 필요 없음)