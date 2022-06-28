#include "Vector.h"
#include <iostream>

//using namespace std;

Vector::Vector() {
    this->_size = 0;    //_size를 0으로 설정
    this->_capacity = 0;    //_capacity를 0으로 설정
    this->data = new float[_capacity];    //data를 capacity의 크기만큼 동적할당
    this->data = NULL;    //data를 NULL로 초기화
}//기본 생성자. 모든 멤버 변수를 0 혹은 NULL로 초기화한다.
Vector::Vector(int size) {
    this->_size = size; //_size를 size로 설정
    this->_capacity = size; //_capacity를 size로 설정
    this->data = new float[_capacity];    //data를 capacity의 크기만큼 동적할당
    for (int i = 0; i < _size; i++) {   //size 개수 만큼 0으로 초기화된 데이터 저장.
        *(this->data + i) = 0;
    }
}//데이터 크기와 메모리 할당량은 size 로 초기화. size 개수만큼 0 으로 초기화된 데이터 저장.
Vector::Vector(int size, const float& init) {
    this->_size = size; //_size를 size로 설정
    this->_capacity = size; //_capacity를 size로 설정
    this->data = new float[_capacity];    //data를 capacity의 크기만큼 동적할당
    this->data[0] = init; //data에 init의 값을 저장
}//float init 으로 초기화된 데이터를 저장. 데이터 크기와 메모리 할당량은 size 로 초기화.
Vector::Vector(int size, const float* init) {   //size값으로 데이터의 크기를 초기화해주고, init값으로 data값에 넣어준다.
    this->_size = size; //_size를 size로 설정
    this->_capacity = size; //capacity를 size 로 설정
    this->data = new float[_capacity];    //_capacity크기 만큼의 data 동적할당
    for (int i = 0; i < _size; i++) {   //data에 init의 값을 순차적으로 저장
        *(this->data + i) = init[i];
    }
}//float 배열 init 으로 초기화된 데이터 저장. 데이터 크기와 메모리 할당량은 size 로 초기화
Vector::Vector(const Vector& v) {
    this->_size = v._size;  //_size를 v._size로 설정
    this->_capacity = v._capacity;  //_capacity를 v._capacity로 설정
    this->data = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        this->data[i] = v.data[i];
    }
    //this->data = v.data;    //data를 v.data로 설정
};//복사 생성자
Vector::~Vector() {
    /*
    if (this->data) {    //data가 존재시 동적할당을 해제해준다.
        delete[] this->data;
        this->_capacity = 0;    //_capacity를 0으로 한다.
        this->_size = 0;    //_size를 0으로 한다.
    }
    */
    delete[] data;
};//소멸자. 할당된 메모리를 삭제한다.

int Vector::capacity() const {
    return _capacity;
};//데이터에 할당된 메모리 사이즈를 리턴한다.
int Vector::size() const {
    return _size;
};//데이터 개수를 리턴한다.
Vector::iterator Vector::begin() {
    return &data[0];
};//데이터의 맨 처음 주소를 리턴한다.
Vector::const_iterator Vector::begin() const {
    return &data[0];
};//데이터의 맨 처음 주소를 리턴한다. (const 버전)
Vector::iterator Vector::end() {
    return &data[_size];
};//데이터의 맨 마지막 주소를 리턴한다.
Vector::const_iterator Vector::end() const {
    return &data[_size];
};//데이터의 맨 마지막 주소를 리턴한다. (const 버전)
float& Vector::front() {
    return(data[0]);
};//데이터의 맨 처음 데이터를 리턴한다.
const float& Vector::front() const {
    return(data[0]);
};//데이터의 맨 처음 데이터를 리턴한다. (const 버전)
float& Vector::back() {
    return(data[_size - 1]);
};//데이터의 맨 마지막 데이터를 리턴한다.
const float& Vector::back() const {
    return(data[_size - 1]);
};//데이터의 맨 마지막 데이터를 리턴한다. (const 버전)
void Vector::allocate(int capacity) {
    float* temp = new float[capacity];  //temp를 capacity크기로 동적할당해준다.
    for (int i = 0; i < _size; i++) { //temp에 값에 data의 값을 넣어준다.
        temp[i] = data[i];
    }
    delete[] data;  //data를 동적할당해제한다.
    data = temp;    //data를 temp로 할당한다.
    _capacity = capacity; //_capacity를 capacity로 설정한다.
};//데이터에 할당된 메모리를 capacity 만큼 동적 할당한다.
void Vector::resize(int size) {
    float* temp = new float[size];  //temp를 size크기로 동적할당해준다.
    for (int i = 0; i < size; i++) { //temp에 값에 data의 값을 넣어준다.
        temp[i] = data[i];
    }
    delete[] data;  //data를 동적할당해제한다.
    data = temp;    //data를 temp로 할당한다.
    _size = size; //_size를 size로 설정한다.
    _capacity = size; //_capacity를 size로 설정한다.
};//size 만큼 데이터에 할당된 메모리를 동적 할당하며, 데이터 개수는 size 만큼 갖는다.

void Vector::push_back(const float& value) {
    int tempsize = _size + 1;   //최종데이터 개수 해당하는 변수 tempsize 선언
    if (tempsize >= _capacity) {  //데이터 추가 시, 최종 데이터 개수가 현재 할당된 메모리 사이즈보다 크거나 같을 경우, 메모리를 다시 할당한 후 데이터를 추가한다.
        //데이터 0 추가 1 할당 사이즈1 일때 그냥 넣는걸로 보아 =들어가면 안될 것 같은
        if (tempsize <= 5) {    //최종 데이터 개수가 5보다 작을경우,최종 데이터 개수만큼의 메모리를 할당한다
            float* temp = new float[tempsize];
            for (int i = 0; i < _size; i++) {   //temp에 data의 값을 _size-1까지 모두 저장해준다.
                temp[i] = data[i];
            }
            temp[tempsize - 1] = value; //temp 마지막 데이터에 value값을 넣어준다.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize;
        }   //data의 동적할당 해제를 하고 다시 temp로 할당을 해준다. _size와 _capacity도 최종데이터 개수만큼 업데이트해준다.
        else {  //최종 데이터 개수가 5보다 크거나 같을 경우,최종 데이터 개수의 2배만큼의 메모리를 할당한다
            float* temp = new float[tempsize * 2];    //최종 데이터 개수의 2배 만큼 temp를 동적할당한다.
            for (int i = 0; i < _size; i++) {   //temp에 data의 값을 _size-1까지 모두 저장해준다.
                temp[i] = data[i];
            }
            temp[tempsize - 1] = value; //temp 마지막 데이터에 value값을 넣어준다.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity *= tempsize * 2;
        }   //data의 동적할당 해제를 하고 다시 temp로 할당을 해준다. _size는 최종데이터 개수 만큼, _capacity은 최종데이터 개수의 2배 만큼 업데이트해준다.
    }
    else {  //할당된 메모리가 최종데이터 개수보다 클경우
        data[tempsize - 1] = value; //데이터의 마지막에 value값을 넣어준다.
        _size = tempsize; //_size를 최종데이터 개수만큼 설정한다.
    }
};//데이터의 맨 뒤에 새로운 데이터 value를 추가한다. 2.문제 세부 조건 규칙에 따라 메모리를 동적 할당한다.
void Vector::pop_back() {//마지막 데이터를 NULL값으로 바꿔주고, _size를 1개 줄인다.
    data[_size - 1] = NULL;
    _size--;

};//맨 마지막 데이터를 삭제한다. 이때 메모리 할당은 유지한다.
void Vector::insert(iterator position, const float& value) {
    int tempsize = _size + 1;   //최종데이터 개수 해당하는 변수 tempsize 선언
    int target = position - begin();    //begin()과 position의 주소값 차이를 이용하여 target index를 구한다.
    if (tempsize >= _capacity) {  //데이터 추가 시, 최종 데이터 개수가 현재 할당된 메모리 사이즈보다 크거나 같을 경우, 메모리를 다시 할당한 후 데이터를 추가한다.
        if (tempsize < 5) {    //최종 데이터 개수가 5보다 작을경우,최종 데이터 개수만큼의 메모리를 할당한다
            float* temp = new float[tempsize];
            for (int i = 0; i < target; i++) {   //data의 값을 새로운 값을 넣으려는 position 전 까지 temp에 모두 저장해준다.
                temp[i] = data[i];
            }
            for (int i = target + 1; i < tempsize; i++) {    //position부터 해당하는 data값을 한칸씩 뒤로 옮긴다.
                temp[i] = data[i - 1];
            }
            temp[target] = value;    //position에 해당하는 index에 value를 저장한다.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize;
        }   //data의 동적할당 해제를 하고 다시 temp로 할당을 해준다. _size와 _capacity도 최종데이터 개수만큼 업데이트해준다.
        else {  //최종 데이터 개수가 5보다 크거나 같을 경우,최종 데이터 개수의 2배만큼의 메모리를 할당한다
            float* temp = new float[tempsize * 2];
            for (int i = 0; i < target; i++) {   //data의 값을 새로운 값을 넣으려는 position 전 까지 temp에 모두 저장해준다.
                temp[i] = data[i];
            }
            for (int i = target + 1; i < tempsize; i++) {    //position부터 해당하는 data값을 한칸씩 뒤로 옮긴다.
                temp[i] = data[i - 1];
            }
            temp[target] = value;    //position에 해당하는 index에 value를 저장한다.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize * 2;
        }   //data의 동적할당 해제를 하고 다시 temp로 할당을 해준다. _size는 최종데이터 개수 만큼, _capacity은 최종데이터 개수의 2배 만큼 업데이트해준다.
    }
    else {  //할당된 메모리가 최종데이터 개수보다 클경우
        for (int i = target + 1; i < tempsize; i++) { //position부터 해당하는 data값을 한칸씩 뒤로 옮긴다.
            data[i] = data[i - 1];
        }
        data[target] = value; //position에 해당하는 index에 value를 저장한다.
        _size = tempsize; //_size를 최종데이터 개수만큼 설정한다.
    }
};//데이터의 특정 위치(position)에 value 를 삽입한다.
// 2.문제 세부 조건 규칙에 따라 메모리를 동적 할당한다.
void Vector::insert(iterator position, const float* first, const float* last) {
    int arr_size = last - first;//last와 first의 주소값 차이를 이용하여 넣으려는 배열의 크기를 구한다.
    int tempsize = _size + arr_size;//최종데이터 개수 해당하는 변수 tempsize 선언
    int target = position - begin();    //begin()과 position의 주소값 차이를 이용하여 target index를 구한다.
    if (tempsize >= _capacity) {  //데이터 추가 시, 최종 데이터 개수가 현재 할당된 메모리 사이즈보다 크거나 같을 경우, 메모리를 다시 할당한 후 데이터를 추가한다.
        if (tempsize < 5) {    //최종 데이터 개수가 5보다 작을경우,최종 데이터 개수만큼의 메모리를 할당한다
            float* temp = new float[tempsize];
            for (int i = 0; i < target; i++) {   //data의 값을 새로운 값을 넣으려는 position 전 까지 temp에 모두 저장해준다.
                temp[i] = data[i];
            }
            for (int i = target + arr_size; i < tempsize; i++) { //data[target]이후의 값들을 temp [target+arr_size]부터 순차적으로 저장한다.
                temp[i] = data[i - arr_size];
            }   //이 결과 temp[target]부터 temp[target+arr_size-1]에 배열을 넣을 수 있고, 그뒤로는 원래 있던 값들이 순차적으로 나타날 것이다.
            for (int i = target; i < target + arr_size; i++) {     //temp[target]부터 first의 값들을 넣어주며 first 값을 증가시켜 배열을 넣어준다.
                temp[i] = *first;
                first++;
            }
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize;
        }   //data의 동적할당 해제를 하고 다시 temp로 할당을 해준다. _size와 _capacity도 최종데이터 개수만큼 업데이트해준다.
        else {  //최종 데이터 개수가 5보다 크거나 같을 경우,최종 데이터 개수의 2배만큼의 메모리를 할당한다
            float* temp = new float[tempsize * 2];
            for (int i = 0; i < target; i++) {   //data의 값을 새로운 값을 넣으려는 position 전 까지 temp에 모두 저장해준다.
                temp[i] = data[i];
            }
            for (int i = target + arr_size; i < tempsize; i++) { //data[target]이후의 값들을 temp [target+arr_size]부터 순차적으로 저장한다.
                temp[i] = data[i - arr_size];
            }
            for (int i = target; i < target + arr_size; i++) {//temp[target]부터 first의 값들을 넣어주며 first 값을 증가시켜 배열을 넣어준다.
                temp[i] = *first;
                first++;
            }
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize * 2;
        }   //data의 동적할당 해제를 하고 다시 temp로 할당을 해준다. _size는 최종데이터 개수 만큼, _capacity은 최종데이터 개수의 2배 만큼 업데이트해준다.
    }
    else {
        for (int i = target + arr_size; i < tempsize; i++) {  //배열을 넣으려고 하는 position부터 그 이후들의 값들을 모두 배열 사이즈만큼 뒤로 옮겨준다.
            data[i] = data[i - arr_size];
        }
        for (int i = target; i < target + arr_size; i++) {//temp[target]부터 first의 값들을 넣어준다.
            data[i] = *first;
            first++;
        }
        _size = tempsize; //_size를 최종데이터 개수만큼 설정한다.
    }

};//데이터에서 특정 위치(position)에 float array 를 삽입한다.
// 이때 first, last 는 각각 float array의 맨 처음 주소, 맨 마지막 주소이다.
void Vector::erase(iterator position) {
    int target = position - begin();    //begin()과 position의 주소값 차이를 이용하여 target index를 구한다.
    for (int i = target; i < _size; i++) {  //position에 해당하는 인덱스의 값부터 해당 값의 이후의 값을 배정한다.
        data[i] = data[i + 1];
    }
    _size -= 1;   //_size 값을 하나 줄여준다.

};//데이터에서 특정 위치(position)의 값을 삭제한다. 이때 메모리 할당은 유지한다.
void Vector::clear() {
    _size = 0;    //_size와 _capacity를 0으로 만들어준다.
    _capacity = 0;
    data = NULL;    //data를 NULL로 해준다.
};//할당된 메모리 사이즈, 데이터 개수를 0 으로 설정하며, 데이터를 NULL 로 설정한다.
float& Vector::operator[](int index) {
    return data[index];
};//연산자 '[]'를 오버로딩한다. 데이터에서 index 위치에 해당하는 값을 리턴한다.
const float& Vector::operator[](int index) const {
    return data[index];
};//연산자 '[]'를 오버로딩한다. 데이터에서 index 위치에 해당하는 값을 리턴한다. (const 버전)
Vector& Vector::operator=(const Vector& v) {
    this->_size = v._size;  //this->_size를 v._size로 설정한다.
    this->_capacity = v._capacity;  //this->_capacity를 v._capacity로 설정한다.
    this->data = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        this->data[i] = v.data[i];    //this->data를 v.data로 설정한다.
    }
    return *this;   //this를 리턴한다.
};//연산자 '='를 오버로딩한다. 현재 멤버변수를 입력 Vector 의 멤버변수로 치환한다.