#include "Vector_Customer.h"
#include "Customer.h"
#include <iostream>

using namespace std;

Vector_Customer::Vector_Customer() {
    _size = 0;    //_size를 0으로 설정
    _capacity = 0;    //_capacity를 0으로 설정
    data = new Customer[_capacity];    //data를 capacity의 크기만큼 동적할당
}
Vector_Customer::Vector_Customer(int size) {
    _size = size; //_size를 size로 설정
    _capacity = size; //_capacity를 size로 설정
    data = new Customer[_capacity];    //data를 capacity의 크기만큼 동적할당

    for (int i = 0; i < _size; i++) {   //size 개수 만큼 0으로 초기화된 데이터 저장.
        data[i].Customer::Customer(); 
    }

}
Vector_Customer::Vector_Customer(int size, const Customer& init) {
    _size = size; //_size를 size로 설정
    _capacity = size; //_capacity를 size로 설정
    data = new Customer[_capacity];    //data를 capacity의 크기만큼 동적할당
    data[0] = init; //data에 init의 값을 저장
}
Vector_Customer::Vector_Customer(int size, const Customer* init) {
    _size = size; //_size를 size로 설정
    _capacity = size; //capacity를 size 로 설정
    data = new Customer[_capacity];    //_capacity크기 만큼의 data 동적할당
    for (int i = 0; i < _size; i++) {   //data에 init의 값을 순차적으로 저장
        *(data + i) = init[i];
    }
}
Vector_Customer::Vector_Customer(const Vector_Customer& v) {
    _size = v._size;  //_size를 v._size로 설정
    _capacity = v._capacity;  //_capacity를 v._capacity로 설정
    data = v.data;    //data를 v.data로 설정
}
Vector_Customer::~Vector_Customer() { }//소멸자

int Vector_Customer::capacity() const {
    return _capacity;//capacity를 리턴한다.
}
int Vector_Customer::size() const {
    return _size;//capacity를 리턴한다.
}

Vector_Customer::iterator Vector_Customer::begin() {
    return &data[0];//이터레이터의 시작 부분을 리턴한다.
}
Vector_Customer::const_iterator Vector_Customer::begin() const {
    return data;//이터레이터의 시작 부분을 리턴한다.
}
Vector_Customer::iterator Vector_Customer::end() {
    return data + _size;//이터레이터의 엔드 부분을 리턴한다.
}
Vector_Customer::const_iterator Vector_Customer::end() const {
    return data + _size;//이터레이터의 엔드 부분을 리턴한다.
}
Customer& Vector_Customer::front() {
    return(data[0]);//앞부분을 리턴해준다.
}
const Customer& Vector_Customer::front() const {
    return(data[0]);//앞부분을 리턴해준다.
}
Customer& Vector_Customer::back() {
    return(data[_size - 1]);//마지막 부분을 리턴해준다.
}
const Customer& Vector_Customer::back() const {
    return(data[_size - 1]);//마지막 부분을 리턴해준다.
}

void Vector_Customer::allocate(int capacity) {
    Customer* temp = new Customer[capacity];  //temp를 capacity크기로 동적할당해준다.
    for (int i = 0; i < _size; i++) { //temp에 값에 data의 값을 넣어준다.
        temp[i] = data[i];
    }
    delete[] data;  //data를 동적할당해제한다.
    data = temp;    //data를 temp로 할당한다.
    _capacity = capacity; //_capacity를 capacity로 설정한다.
}
void Vector_Customer::resize(int size) {
    Customer* temp = new Customer[size];  //temp를 size크기로 동적할당해준다.
    for (int i = 0; i < size; i++) { //temp에 값에 data의 값을 넣어준다.
        temp[i] = data[i];
    }
    delete[] data;  //data를 동적할당해제한다.
    data = temp;    //data를 temp로 할당한다.
    _size = size; //_size를 size로 설정한다.
    _capacity = size; //_capacity를 size로 설정한다.
}

void Vector_Customer::push_back(const Customer& value) {
    int tempsize = _size + 1;   //최종데이터 개수 해당하는 변수 tempsize 선언
    if (tempsize >= _capacity) {  //데이터 추가 시, 최종 데이터 개수가 현재 할당된 메모리 사이즈보다 크거나 같을 경우, 메모리를 다시 할당한 후 데이터를 추가한다.
        //데이터 0 추가 1 할당 사이즈1 일때 그냥 넣는걸로 보아 =들어가면 안될 것 같은
        if (tempsize <= 5) {    //최종 데이터 개수가 5보다 작을경우,최종 데이터 개수만큼의 메모리를 할당한다
            Customer* temp = new Customer[tempsize];
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
            Customer* temp = new Customer[tempsize * 2];    //최종 데이터 개수의 2배 만큼 temp를 동적할당한다.
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
}
void Vector_Customer::pop_back() {//데이터의 마지막 부분을 지우고. 사이즈를 1 줄여준다.
    //data[_size-1]=NULL;
    _size--;
}
void Vector_Customer::insert(iterator position, const Customer& value) {
    int tempsize = _size + 1;   //최종데이터 개수 해당하는 변수 tempsize 선언
    int target = position - begin();    //begin()과 position의 주소값 차이를 이용하여 target index를 구한다.
    if (tempsize >= _capacity) {  //데이터 추가 시, 최종 데이터 개수가 현재 할당된 메모리 사이즈보다 크거나 같을 경우, 메모리를 다시 할당한 후 데이터를 추가한다.
        if (tempsize < 5) {    //최종 데이터 개수가 5보다 작을경우,최종 데이터 개수만큼의 메모리를 할당한다
            Customer* temp = new Customer[tempsize];
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
            Customer* temp = new Customer[tempsize * 2];
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
}
void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last) {
    int arr_size = last - first;//last와 first의 주소값 차이를 이용하여 넣으려는 배열의 크기를 구한다.
    int tempsize = _size + arr_size;//최종데이터 개수 해당하는 변수 tempsize 선언
    int target = position - begin();    //begin()과 position의 주소값 차이를 이용하여 target index를 구한다.
    if (tempsize >= _capacity) {  //데이터 추가 시, 최종 데이터 개수가 현재 할당된 메모리 사이즈보다 크거나 같을 경우, 메모리를 다시 할당한 후 데이터를 추가한다.
        if (tempsize < 5) {    //최종 데이터 개수가 5보다 작을경우,최종 데이터 개수만큼의 메모리를 할당한다
            Customer* temp = new Customer[tempsize];
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
            Customer* temp = new Customer[tempsize * 2];
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
}

void Vector_Customer::erase(iterator position) {
    int target = position - begin();    //begin()과 position의 주소값 차이를 이용하여 target index를 구한다.
    for (int i = target; i < _size - 2; i++) {  //position에 해당하는 인덱스의 값부터 해당 값의 이후의 값을 배정한다.
        data[i] = data[i + 1];
    }
    _size -= 1;   //_size 값을 하나 줄여준다.
}
void Vector_Customer::clear() {
    _size = 0;    //_size와 _capacity를 0으로 만들어준다.
    _capacity = 0;
    data = NULL;    //data를 NULL로 해준다.
}


Customer& Vector_Customer::operator[](int index) {
    return data[index];//index를 리턴해준다.
}
const Customer& Vector_Customer::operator[](int index) const {
    return data[index];//index를 리턴해준다.
}
Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v) {
    this->_size = v._size;  //this->_size를 v._size로 설정한다.
    this->_capacity = v._capacity;  //this->_capacity를 v._capacity로 설정한다.
    this->data = v.data;    //this->data를 v.data로 설정한다.
    return *this;   //*this를 리턴한다.
}