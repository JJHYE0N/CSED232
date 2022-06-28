#ifndef OOP_ASSN2_2_VECTOR_RIDER_H
#define OOP_ASSN2_2_VECTOR_RIDER_H
#include "Rider.h"

using namespace std;


class Vector_Rider
{
private:
    Rider* data;//데이터를 담을 data선언
    int _capacity;//메모리의 크기에 해당하는 _capacity 선언
    int _size;//데이터의 크기에 해당하는 _size 선언
public:
    typedef Rider* iterator;//Rider*를 iterator 형으로 선언.
    typedef const Rider* const_iterator;//const Rider*를 const_iterator 형으로 선언

    Vector_Rider();//기본 생성자. 모든 멤버 변수를 0 혹은 NULL로 초기화한다.
    Vector_Rider(int size);//데이터 크기와 메모리 할당량은 size 로 초기화. size 개수만큼 0 으로 초기화된 데이터 저장.
    Vector_Rider(int size, const Rider& init);//Rider init 으로 초기화된 데이터를 저장. 데이터 크기와 메모리 할당량은 size 로 초기화.
    Vector_Rider(int size, const Rider* init);//Rider 배열 init 으로 초기화된 데이터 저장. 데이터 크기와 메모리 할당량은 size 로 초기화
    Vector_Rider(const Vector_Rider& v);//복사 생성자
    ~Vector_Rider();//소멸자

    int capacity() const;//데이터에 할당된 메모리 사이즈를 리턴한다.
    int size() const;//데이터 개수를 리턴한다.

    iterator begin();//데이터의 맨 처음 주소를 리턴한다.
    const_iterator begin() const;//데이터의 맨 처음 주소를 리턴한다. (const 버전)
    iterator end();//데이터의 맨 마지막 주소를 리턴한다.
    const_iterator end() const;//데이터의 맨 마지막 주소를 리턴한다. (const 버전)
    Rider& front();//데이터의 맨 처음 데이터를 리턴한다.
    const Rider& front() const;//데이터의 맨 처음 데이터를 리턴한다. (const 버전)
    Rider& back();//데이터의 맨 마지막 데이터를 리턴한다.
    const Rider& back() const;//데이터의 맨 마지막 데이터를 리턴한다. (const 버전)

    void allocate(int capacity);//데이터에 할당된 메모리를 capacity 만큼 동적 할당한다.
    void resize(int size);//size 만큼 데이터에 할당된 메모리를 동적 할당하며, 데이터 개수는 size 만큼 갖는다.

    void push_back(const Rider& value);//데이터의 맨 뒤에 새로운 데이터 value를 추가한다
    void pop_back();//맨 마지막 데이터를 삭제한다. 이때 메모리 할당은 유지한다.
    void insert(iterator position, const Rider& value); //데이터의 특정 위치(position)에 value 를 삽입한다
    void insert(iterator position, const Rider* first, const Rider* last);//데이터에서 특정 위치(position)에 Rider array 를 삽입한다.

    void erase(iterator position);//데이터에서 특정 위치(position)의 값을 삭제한다. 이때 메모리 할당은 유지한다.
    void clear();//할당된 메모리 사이즈, 데이터 개수를 0 으로 설정하며, 데이터를 NULL 로 설정한다


    Rider& operator[](int index);//연산자 '[]'를 오버로딩한다. 데이터에서 index 위치에 해당하는 값을 리턴한다.
    const Rider& operator[](int index) const;//연산자 '[]'를 오버로딩한다. 데이터에서 index 위치에 해당하는 값을 리턴한다. (const 버전)
    Vector_Rider& operator=(const Vector_Rider& v);//연산자 '='를 오버로딩한다. 현재 멤버변수를 입력 Vector 의 멤버변수로 치환한다.
};

#endif //OOP_ASSN2_2_VECTOR_RIDER_H