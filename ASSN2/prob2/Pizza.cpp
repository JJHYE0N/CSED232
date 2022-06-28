
#include "Pizza.h"
#include "Customer.h"
#include "Vector_Rider.h"
#include "Vector_Customer.h"

#include <iostream>
using namespace std;

Pizza::Pizza() {
    money = 10000;
    timeA = 10;
    timeB = 20;

    A.Vector_Customer::Vector_Customer(5);
    B.Vector_Customer::Vector_Customer(5);
    R.Vector_Rider::Vector_Rider(5);

    setPrice();

}//기본 생성자.
//Money, timeA, timeB 는 각각 10000, 10, 20 으로 설정한다.
//A와 B는 각각 기본 생성자로 생성된 Customer 객체를 5개씩 갖는다.
//R은 기본 생성자로 생성된 Rider 객체를 5개 갖는다.
//priceA, priceB, feeA, feeB 는 객체의 setPrice() 멤버 함수를 통해 일괄 설정한다. (입력 인자가 없는 setPrice() 함수)
Pizza::Pizza(float money) {
    Pizza::money = money;
    timeA = 10;
    timeB = 20;

    A.Vector_Customer::Vector_Customer(5);
    B.Vector_Customer::Vector_Customer(5);
    R.Vector_Rider::Vector_Rider(5);

    setPrice();
}
//멤버 변수 money 를 입력으로 받아 설정하며, 나머지는 기본 생성자와 동일하다.
Pizza::Pizza(const Pizza& pizza) {
    money = pizza.money;
    priceA = pizza.priceA;
    priceB = pizza.priceB;
    feeA = pizza.feeA;
    feeB = pizza.feeB;
    timeA = pizza.timeA;
    timeB = pizza.timeB;
    A = pizza.A;
    B = pizza.B;
    R = pizza.R;
}
//복사 생성자. 모든 멤버 변수를 pizza입력의 멤버 변수로 대체한다.
Pizza::~Pizza() { }
//소멸자. 함수 내에 별다른 구현은 필요 없습니다.

void Pizza::setPrice() {
    priceA = 100 - 3 * A.size(); //100-3xA고객수
    priceB = 100 - 6 * B.size();    //100-6xB고객수
    feeA = 10 - A.size();   //10-A고객수
    feeB = 10 - B.size();   //10-B고객수
}
//A, B 구역의 피자 가격과 배달 수수료를 문제 공통 조건과 같이 책정한다.
void Pizza::setPrice(float a, float b) {
    priceA = 100 - a * A.size();//100-axA고객수
    priceB = 100 - b * B.size();//100-bxB고객수
    feeA = 10 - A.size();//10-A고객수
    feeB = 10 - B.size();//10-B고객수
}
//a, b 가 주어졌을 때 A, B 구역의 피자 가격과 배달 수수료를 아래와 같이 책정한다. priceA [100 – a x A 구역 고객 수] (A 구역에 7 명 고객이 있으면 100 – a * 7), priceB [100 – b x B 구역 고객 수] (B 구역에 3 명 고객이 있으면 100 – b * 3), feeA [10 - A구역 고객 수],
//feeB [10 – B 구역 고객 수]
void Pizza::hire(const Rider& rider) {  
    R.erase(R.begin()); //맨 앞부터 데이터를 제거 
    R.push_back(rider); //마지막에 데이터를 삽입
}
//배달 기사 채용 기능을 구현한다. 배달 기사 관리 원칙은 선입선출을 따른다.
void Pizza::hire(const Rider* riders, int size) {
    for (int i = 0; i < size; i++) {    //여러명을 고용할 경우 
        R.erase(R.begin()); //처음부터 초과되는 라이더를 지운다.
    }
    for (int i = 0; i < size; i++) {    //그리고 지운만큼 라이더들을 새로 고용한다.
        R.push_back(riders[i]);
    }
}
//배달 기사 여러 명을 한 번에 채용하는 기능을 구현한다.
// Rider 객체 배열을 입력으로 받으며, size 는 배열의 객체 개수이다.
// 배달 기사 관리 원칙은 선입선출을 따른다.
// 즉 새로운 3명의 배달기사를 채용할 경우 가장 먼저 고용된 3명의 배달 기사를 해고한다.
void Pizza::enroll(const Customer& customer, bool a) {
    if (a == 1) {
        if (numCustomers(1) == 9) {   //A지역의 고객이 9명일 때, B지역 고객은 1명이므로 지울 수 없기 때문에, A지역의 맨 앞에 고객을 퇴출하고, 추가한다.
            A.erase(A.begin());//A 지역의 고객을 하나 삭제한다.
            A.push_back(customer);  //A지역의 고객을 추가한다.
        }
        else {  //B지역의 맨앞의 고객을 삭제하고, A지역의 고객을 추가한다.
            B.erase(B.begin());//B 지역의 고객을 하나 삭제한다.
            A.push_back(customer);  //A지역의 고객을 추가한다.
        }
    }
    else if (a == 0) {
        if (B.size() == 9) {   //B지역의 고객이 9명일 때, A지역 고객은 1명이므로 지울 수 없기 때문에, B지역의 맨 앞에 고객을 퇴출하고, 추가한다.
            B.erase(B.begin());//B 지역의 고객을 하나 삭제한다.
            B.push_back(customer);  //B지역의 고객을 추가한다.
        }
        else {  //A지역의 맨앞의 고객을 삭제하고, B지역의 고객을 추가한다.
            A.erase(A.begin());//A 지역의 고객을 하나 삭제한다.
            B.push_back(customer);  //B지역의 고객을 추가한다.
        }
    }
    setPrice(); //가격을 설정한다.
}
//특정 지역의 고객을 추가한다. 외부에서 선언된 Customer class 를 입력으로 받는다.
// Bool a가 true이면 A 지역에 추가하며, false이면 B 지역에 추가한다. 고객 관리 원칙은 문제 공통 조건을 따른다.
void Pizza::enroll(const Customer* customers, int size, bool a) {
    if (a == 1) {  //A지역 고객 추가
        for (int i = 0; i < size; i++) { //size만큼 반복문을 실행한다.
            if (A.size() == 9) {   //A지역의 고객이 9명일 때, B지역 고객은 1명이므로 지울 수 없기 때문에, A지역의 맨 앞에 고객을 퇴출하고, 추가한다.
                A.erase(A.begin());//A 지역의 고객을 하나 삭제한다.
                A.push_back(customers[i]);  //A지역의 고객 customer[i]을 추가한다.
            }
            else {  //B지역의 맨앞의 고객을 삭제하고, A지역의 고객을 추가한다.
                B.erase(B.begin());//B 지역의 고객을 하나 삭제한다.
                A.push_back(customers[i]);  //A지역의 고객 customer[i]을 추가한다.
            }
        }
    }
    else if (a == 0) {  //B지역 고객 추가
        for (int i = 0; i < size; i++) { //size만큼 반복문을 실행한다.
            if (B.size() == 9) {   //B지역의 고객이 9명일 때, A지역 고객은 1명이므로 지울 수 없기 때문에, B지역의 맨 앞에 고객을 퇴출하고, 추가한다.
                B.erase(B.begin());//B 지역의 고객을 하나 삭제한다.
                B.push_back(customers[i]);  //B지역의 고객 customer[i]을 추가한다.
            }
            else {  //A지역의 맨앞의 고객을 삭제하고, B지역의 고객을 추가한다.
                A.erase(A.begin());//A 지역의 고객을 하나 삭제한다.
                B.push_back(customers[i]);  //B지역의 고객 customer[i]을 추가한다.
            }
        }
    }
    setPrice();
}
//특정 지역의 다수 고객들을 추가하는 기능을 구현한다. Customer 객체 배열을 입력으로 받으며,
// size는 배열의 객체 개수이다. Bool a가 true이면 A 지역에 추가하며, false이면 B 지역에 추가한다.
// 고객 관리 원칙은 문제 공통 조건을 따른다.
float Pizza::reportMoney() const {
    return money;
}
//피자 가게가 현재 가지고 있는 돈을 리턴한다.
int Pizza::numRiders() const {
    return R.size();
}
//배달 기사의 현재 인원을 리턴한다.
int Pizza::numCustomers(bool a) const {
    if (a == 1) return A.size();
    else if (a == 0) return B.size();
}
//Bool a가 true일 경우, A 지역 고객 수를 리턴한다. Bool a가 false일 경우, B 지역 고객 수를 리턴한다.
float Pizza::meanFee() const {
    float sumFee = 0;
    for (int i = 0; i < 5; i++) {
        sumFee += R[i].reportMoney();   //라이더들의 번돈을 모두 더한다.
    }
    return (sumFee / 5);    //더한 돈을 5로 나누어 평균을 구해준다.
}
//현재 고용 중인 라이더가 배달을 통해 번 돈의 평균을 리턴한다.
float Pizza::meanTimeRiders() const {
    float sumTime = 0;
    for (int i = 0; i < 5; i++) {
        sumTime += R[i].reportTime();   //라이더들의 시간들을 모두 더한다.
    }
    return (sumTime / 5);//더한 시간을 5로 나누어 평균을 구해준다.
}
//현재 고용 중인 라이더가 배달하는데 걸린 시간의 평균을 리턴한다.
float Pizza::meanMoneyCustomers() const {
    float sumPaid = 0;
    for (int i = 0; i < A.size(); i++) {
        sumPaid += A[i].reportMoney();  //A구역의 고객들이 지불한 돈을 더한다.
    }
    for (int i = 0; i < B.size(); i++) {
        sumPaid += B[i].reportMoney();  //B구역의 고객들이 지불한 돈을 더한다.
    }
    return (sumPaid / 10);//더한 돈을 10으로 나누어 평균을 구한다.
}
//현재 관리 중인 고객들이 피자를 구매하는데 든 비용의 평균을 리턴한다.
float Pizza::meanTimeCustomers() const {
    float sumTime = 0;
    for (int i = 0; i < A.size(); i++) {     //A구역의 고객들이 걸린 시간을 더한다.
        sumTime += A[i].reportTime();
    }
    for (int i = 0; i < B.size(); i++) {    //B구역의 고객들이 걸린 시간을 더한다.
        sumTime += B[i].reportTime();
    }
    return (sumTime / 10);  //더한 시간을 10으로 나누어 평균을 구한다.
}
//현재 관리 중인 고객들이 배달 받는데 걸린 시간의 평균을 리턴한다.
void Pizza::deliver() {
    int index = A.size();//A 지역 고객의 수를 받아준다.
    int seq_a = 0;//A지역의 인덱스를 나타내주는 변수를 선언한다.
    int seq_b = 0;//B지역의 인덱스를 나타내주는 변수를 선언한다.
    for (int i = 0; i < 10; i++) {//i는 라이더들의 인덱스를 나타내며 5를 넘어가면 이후 5를 빼준 번호에 해당하는 라이더가 배달을 간다.
        if (i < 5) {//rider 0,1,2,3,4 가 배달을 간다.
            if (i < index) {//A지역의 고객 수보다 i가 작을 경우 A지역에 배달을 간다.
                A[seq_a].Customer::pay(priceA, timeA);//A지역 고객이 돈을 지불한다.
                money += priceA;//피자가게 사장은 돈을 얻는다.
                money -= feeA;//피자가게 사장은 배달수수료를 지불한다.
                R[i].Rider::deliver(feeA, timeA);//라이더는 배달수수료를 얻는다.
                seq_a += 1;//a지역 배달횟수를 1 늘린다.
            }
            else {//A지역의 고객 수보다 i가 크거나 같으면 B지역에 배달을 간다.
                B[seq_b].Customer::pay(priceB, timeB);//B지역 고객이 돈을 지불한다.
                money += priceB;//피자가게 사장은 돈을 얻는다.
                money -= feeB;//피자가게 사장은 배달수수료를 지불한다.
                R[i].Rider::deliver(feeB, timeB);//라이더는 배달수수료를 얻는다.
                seq_b += 1;//b지역 배달횟수를 1 늘린다.
            }
        }
        else if (i >= 5) {
            if (i < index) {//A지역의 고객 수보다 i가 작을 경우 A지역에 배달을 간다.
                A[seq_a].Customer::pay(priceA, timeA);//A지역 고객이 돈을 지불한다.
                money += priceA;//피자가게 사장은 돈을 얻는다.
                money -= feeA;//피자가게 사장은 배달수수료를 지불한다.
                R[i - 5].Rider::deliver(feeA, timeA);//라이더는 배달수수료를 얻는다.
                seq_a += 1;//a지역 배달횟수를 1 늘린다.
            }
            else {//A지역의 고객 수보다 i가 크거나 같으면 B지역에 배달을 간다.
                B[seq_b].Customer::pay(priceB, timeB);//B지역 고객이 돈을 지불한다.
                money += priceB;//피자가게 사장은 돈을 얻는다.
                money -= feeB;//피자가게 사장은 배달수수료를 지불한다.
                R[i - 5].Rider::deliver(feeB, timeB);//라이더는 배달수수료를 얻는다.
                seq_b += 1;//b지역 배달횟수를 1 늘린다.
            }
        }

    }
}
//각 구역의 고객들에게 일괄적으로 피자를 배달한다.
// (배달 시각, 라이더 배치 시간 겹침 등은 고려 X) 고객은 가게에 돈을 지불한다.
// 고객의 돈은 소속된 구역의 피자 가격만큼 빠져나가며, 가게의 돈은 그만큼 증가한다.
// 또한, 고객의 총 배달시간은 소속된 구역의 배달 시간만큼 증가한다. (Customer class 참고)
std::ostream& operator <<(std::ostream& os, const Pizza& x) {
    os << "1) Money : " << x.money << std::endl;
    os << "2) (Customers, Price, Fee)" << std::endl;
    os << "- A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << std::endl;
    os << "- B : (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << std::endl;
    os << "3) Riders: " << x.R.size() << std::endl;
    return os;
    /*
    1) Money : [피자가게가 보유한 돈]
    2) (Customers, Price, Fee)
    - A : ([A 구역 고객 수], [A 구역 피자 가격], [A 구역 배달 수수료])
    - B : ([B 구역 고객 수], [B 구역 피자 가격], [B 구역 배달 수수료])
    3) Riders: [배달 기사 수]
    와 같이 출력되도록한다.
    */
}
//콘솔 창에 아래와 같이 출력되도록 오버로딩을 통해 구현한다. 꺾쇠 괄호([ ])는 변수를 의미한다. (꺾쇠 ‘[‘, ‘]’ 는 출력할 필요 없음)