#ifndef OOP_ASSN2_2_PIZZA_H
#define OOP_ASSN2_2_PIZZA_H
#include <iostream>
#include "Rider.h"
#include "Customer.h"
#include "Vector_Rider.h"
#include "Vector_Customer.h"

using namespace std;

class Pizza {

private:
    float money;//가게의 돈
    float priceA;//A 구역의 피자 가격
    float priceB;//B 구역의 피자 가격
    float feeA;//A 구역 배달 수수료
    float feeB;//B 구역 배달 수수료
    float timeA;//A 구역 배달 소요 시간
    float timeB;//B 구역 배달 소요 시간

    /*Vector_Customer A;//A 구역 고객들. Vector_Customer class 사용.
    Vector_Customer B;//B 구역 고객들. Vector_Customer class 사용.
    Vector_Rider R;//배달 기사. Vector_Rider class 사용.*/
    Vector_Customer A;
    Vector_Customer B;
    Vector_Rider R;
public:
    Pizza();//기본 생성자.
    //Money, timeA, timeB 는 각각 10000, 10, 20 으로 설정한다.
    //A와 B는 각각 기본 생성자로 생성된 Customer 객체를 5개씩 갖는다.
    //R은 기본 생성자로 생성된 Rider 객체를 5개 갖는다.
    //priceA, priceB, feeA, feeB 는 객체의 setPrice() 멤버 함수를 통해 일괄 설정한다. (입력 인자가 없는 setPrice() 함수)
    Pizza(float money);//멤버 변수 money 를 입력으로 받아 설정하며, 나머지는 기본 생성자와 동일하다.
    Pizza(const Pizza& pizza);//복사 생성자. 모든 멤버 변수를 입력의 멤버 변수로 대체한다.
    ~Pizza();
    //소멸자. 함수 내에 별다른 구현은 필요 없습니다.
    void setPrice();
    //A, B 구역의 피자 가격과 배달 수수료를 문제 공통 조건과 같이 책정한다.
    void setPrice(float a, float b);
    //a, b 가 주어졌을 때 A, B 구역의 피자 가격과 배달 수수료를 아래와 같이 책정한다. priceA [100 – a x A 구역 고객 수] (A 구역에 7 명 고객이 있으면 100 – a * 7), priceB [100 – b x B 구역 고객 수] (B 구역에 3 명 고객이 있으면 100 – b * 3), feeA [10 - A구역 고객 수],
    //feeB [10 – B 구역 고객 수]
    void hire(const Rider& rider);
    //배달 기사 채용 기능을 구현한다. 배달 기사 관리 원칙은 선입선출을 따른다.
    void hire(const Rider* riders, int size);
    //배달 기사 여러 명을 한 번에 채용하는 기능을 구현한다.
    // Rider 객체 배열을 입력으로 받으며, size 는 배열의 객체 개수이다.
    // 배달 기사 관리 원칙은 선입선출을 따른다.
    // 즉 새로운 3명의 배달기사를 채용할 경우 가장 먼저 고용된 3명의 배달 기사를 해고한다.
    void enroll(const Customer& customer, bool a);
    //특정 지역의 고객을 추가한다. 외부에서 선언된 Customer class 를 입력으로 받는다.
    // Bool a가 true이면 A 지역에 추가하며, false이면 B 지역에 추가한다. 고객 관리 원칙은 문제 공통 조건을 따른다.
    void enroll(const Customer* customers, int size, bool a);
    //특정 지역의 다수 고객들을 추가하는 기능을 구현한다. Customer 객체 배열을 입력으로 받으며,
    // size는 배열의 객체 개수이다. Bool a가 true이면 A 지역에 추가하며, false이면 B 지역에 추가한다.
    // 고객 관리 원칙은 문제 공통 조건을 따른다.
    float reportMoney() const;
    //피자 가게가 현재 가지고 있는 돈을 리턴한다.
    int numRiders() const;
    //배달 기사의 현재 인원을 리턴한다.
    int numCustomers(bool a) const;
    //Bool a가 true일 경우, A 지역 고객 수를 리턴한다. Bool a가 false일 경우, B 지역 고객 수를 리턴한다.
    float meanFee() const;
    //현재 고용 중인 라이더가 배달을 통해 번 돈의 평균을 리턴한다.
    float meanTimeRiders() const;
    //현재 고용 중인 라이더가 배달하는데 걸린 시간의 평균을 리턴한다.
    float meanMoneyCustomers() const;
    //현재 관리 중인 고객들이 피자를 구매하는데 든 비용의 평균을 리턴한다.
    float meanTimeCustomers() const;
    //현재 관리 중인 고객들이 배달 받는데 걸린 시간의 평균을 리턴한다.
    void deliver();
    //각 구역의 고객들에게 일괄적으로 피자를 배달한다.
    // (배달 시각, 라이더 배치 시간 겹침 등은 고려 X) 고객은 가게에 돈을 지불한다.
    // 고객의 돈은 소속된 구역의 피자 가격만큼 빠져나가며, 가게의 돈은 그만큼 증가한다.
    // 또한, 고객의 총 배달시간은 소속된 구역의 배달 시간만큼 증가한다. (Customer class 참고)
    friend ostream& operator <<(std::ostream& os, const Pizza& x);
    //콘솔 창에 아래와 같이 출력되도록 오버로딩을 통해 구현한다. 꺾쇠 괄호([ ])는 변수를 의미한다. (꺾쇠 ‘[‘, ‘]’ 는 출력할 필요 없음)
};

#endif //OOP_ASSN2_2_PIZZA_H