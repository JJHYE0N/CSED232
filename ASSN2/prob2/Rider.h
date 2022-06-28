#ifndef OOP_ASSN2_2_RIDER_H
#define OOP_ASSN2_2_RIDER_H

#include <iostream>
using namespace std;

class Rider {
private:
    float money;//배달 기사가 가진 돈
    float earnMoney;//배달 기사가 번 돈의 총 합산
    float time;// 피자 배달하는데 걸린 총 시간
public:
    Rider();
    //기본 생성자. money, earnMoney, time 모두 0 으로 초기화한다.
    Rider(float money, float earnMoney, float time);
    //멤버 변수 money, earnMoney, time 을 입력 값으로 설정한다.
    Rider(const Rider& rider);
    //복사 생성자.
    ~Rider();
    //소멸자. 함수 내에 별다른 구현은 필요 없습니다.
    float reportMoney() const;
    //배달 기사가 현재까지 번 돈의 총 합산을 리턴한다.
    float reportTime() const;
    //배달 기사가 현재까지 피자를 배달하는데 걸린 총 시간을 리턴한다.
    void deliver(float price, float time);
    //정해진 피자 가격만큼 돈을 받으며, 정해진 배달 시간만큼 총 배달 시간에 더해준다.
    friend std::ostream& operator <<(std::ostream& os, const Rider& x);
    //콘솔 창에 아래와 같이 출력되도록 오버로딩을 통해 구현한다. 꺾쇠 괄호([ ])는 변수를 의미한다. (꺾쇠 ‘[‘, ‘]’ 는 출력할 필요 없음)
};
#endif //OOP_ASSN2_2_RIDER_H