#include "Vector_Customer.h"
#include "Customer.h"
#include <iostream>

using namespace std;

Vector_Customer::Vector_Customer() {
    _size = 0;    //_size�� 0���� ����
    _capacity = 0;    //_capacity�� 0���� ����
    data = new Customer[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
}
Vector_Customer::Vector_Customer(int size) {
    _size = size; //_size�� size�� ����
    _capacity = size; //_capacity�� size�� ����
    data = new Customer[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�

    for (int i = 0; i < _size; i++) {   //size ���� ��ŭ 0���� �ʱ�ȭ�� ������ ����.
        data[i].Customer::Customer(); 
    }

}
Vector_Customer::Vector_Customer(int size, const Customer& init) {
    _size = size; //_size�� size�� ����
    _capacity = size; //_capacity�� size�� ����
    data = new Customer[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
    data[0] = init; //data�� init�� ���� ����
}
Vector_Customer::Vector_Customer(int size, const Customer* init) {
    _size = size; //_size�� size�� ����
    _capacity = size; //capacity�� size �� ����
    data = new Customer[_capacity];    //_capacityũ�� ��ŭ�� data �����Ҵ�
    for (int i = 0; i < _size; i++) {   //data�� init�� ���� ���������� ����
        *(data + i) = init[i];
    }
}
Vector_Customer::Vector_Customer(const Vector_Customer& v) {
    _size = v._size;  //_size�� v._size�� ����
    _capacity = v._capacity;  //_capacity�� v._capacity�� ����
    data = v.data;    //data�� v.data�� ����
}
Vector_Customer::~Vector_Customer() { }//�Ҹ���

int Vector_Customer::capacity() const {
    return _capacity;//capacity�� �����Ѵ�.
}
int Vector_Customer::size() const {
    return _size;//capacity�� �����Ѵ�.
}

Vector_Customer::iterator Vector_Customer::begin() {
    return &data[0];//���ͷ������� ���� �κ��� �����Ѵ�.
}
Vector_Customer::const_iterator Vector_Customer::begin() const {
    return data;//���ͷ������� ���� �κ��� �����Ѵ�.
}
Vector_Customer::iterator Vector_Customer::end() {
    return data + _size;//���ͷ������� ���� �κ��� �����Ѵ�.
}
Vector_Customer::const_iterator Vector_Customer::end() const {
    return data + _size;//���ͷ������� ���� �κ��� �����Ѵ�.
}
Customer& Vector_Customer::front() {
    return(data[0]);//�պκ��� �������ش�.
}
const Customer& Vector_Customer::front() const {
    return(data[0]);//�պκ��� �������ش�.
}
Customer& Vector_Customer::back() {
    return(data[_size - 1]);//������ �κ��� �������ش�.
}
const Customer& Vector_Customer::back() const {
    return(data[_size - 1]);//������ �κ��� �������ش�.
}

void Vector_Customer::allocate(int capacity) {
    Customer* temp = new Customer[capacity];  //temp�� capacityũ��� �����Ҵ����ش�.
    for (int i = 0; i < _size; i++) { //temp�� ���� data�� ���� �־��ش�.
        temp[i] = data[i];
    }
    delete[] data;  //data�� �����Ҵ������Ѵ�.
    data = temp;    //data�� temp�� �Ҵ��Ѵ�.
    _capacity = capacity; //_capacity�� capacity�� �����Ѵ�.
}
void Vector_Customer::resize(int size) {
    Customer* temp = new Customer[size];  //temp�� sizeũ��� �����Ҵ����ش�.
    for (int i = 0; i < size; i++) { //temp�� ���� data�� ���� �־��ش�.
        temp[i] = data[i];
    }
    delete[] data;  //data�� �����Ҵ������Ѵ�.
    data = temp;    //data�� temp�� �Ҵ��Ѵ�.
    _size = size; //_size�� size�� �����Ѵ�.
    _capacity = size; //_capacity�� size�� �����Ѵ�.
}

void Vector_Customer::push_back(const Customer& value) {
    int tempsize = _size + 1;   //���������� ���� �ش��ϴ� ���� tempsize ����
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        //������ 0 �߰� 1 �Ҵ� ������1 �϶� �׳� �ִ°ɷ� ���� =���� �ȵ� �� ����
        if (tempsize <= 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Customer* temp = new Customer[tempsize];
            for (int i = 0; i < _size; i++) {   //temp�� data�� ���� _size-1���� ��� �������ش�.
                temp[i] = data[i];
            }
            temp[tempsize - 1] = value; //temp ������ �����Ϳ� value���� �־��ش�.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize;
        }   //data�� �����Ҵ� ������ �ϰ� �ٽ� temp�� �Ҵ��� ���ش�. _size�� _capacity�� ���������� ������ŭ ������Ʈ���ش�.
        else {  //���� ������ ������ 5���� ũ�ų� ���� ���,���� ������ ������ 2�踸ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Customer* temp = new Customer[tempsize * 2];    //���� ������ ������ 2�� ��ŭ temp�� �����Ҵ��Ѵ�.
            for (int i = 0; i < _size; i++) {   //temp�� data�� ���� _size-1���� ��� �������ش�.
                temp[i] = data[i];
            }
            temp[tempsize - 1] = value; //temp ������ �����Ϳ� value���� �־��ش�.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity *= tempsize * 2;
        }   //data�� �����Ҵ� ������ �ϰ� �ٽ� temp�� �Ҵ��� ���ش�. _size�� ���������� ���� ��ŭ, _capacity�� ���������� ������ 2�� ��ŭ ������Ʈ���ش�.
    }
    else {  //�Ҵ�� �޸𸮰� ���������� �������� Ŭ���
        data[tempsize - 1] = value; //�������� �������� value���� �־��ش�.
        _size = tempsize; //_size�� ���������� ������ŭ �����Ѵ�.
    }
}
void Vector_Customer::pop_back() {//�������� ������ �κ��� �����. ����� 1 �ٿ��ش�.
    //data[_size-1]=NULL;
    _size--;
}
void Vector_Customer::insert(iterator position, const Customer& value) {
    int tempsize = _size + 1;   //���������� ���� �ش��ϴ� ���� tempsize ����
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        if (tempsize < 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Customer* temp = new Customer[tempsize];
            for (int i = 0; i < target; i++) {   //data�� ���� ���ο� ���� �������� position �� ���� temp�� ��� �������ش�.
                temp[i] = data[i];
            }
            for (int i = target + 1; i < tempsize; i++) {    //position���� �ش��ϴ� data���� ��ĭ�� �ڷ� �ű��.
                temp[i] = data[i - 1];
            }
            temp[target] = value;    //position�� �ش��ϴ� index�� value�� �����Ѵ�.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize;
        }   //data�� �����Ҵ� ������ �ϰ� �ٽ� temp�� �Ҵ��� ���ش�. _size�� _capacity�� ���������� ������ŭ ������Ʈ���ش�.
        else {  //���� ������ ������ 5���� ũ�ų� ���� ���,���� ������ ������ 2�踸ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Customer* temp = new Customer[tempsize * 2];
            for (int i = 0; i < target; i++) {   //data�� ���� ���ο� ���� �������� position �� ���� temp�� ��� �������ش�.
                temp[i] = data[i];
            }
            for (int i = target + 1; i < tempsize; i++) {    //position���� �ش��ϴ� data���� ��ĭ�� �ڷ� �ű��.
                temp[i] = data[i - 1];
            }
            temp[target] = value;    //position�� �ش��ϴ� index�� value�� �����Ѵ�.
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize * 2;
        }   //data�� �����Ҵ� ������ �ϰ� �ٽ� temp�� �Ҵ��� ���ش�. _size�� ���������� ���� ��ŭ, _capacity�� ���������� ������ 2�� ��ŭ ������Ʈ���ش�.
    }
    else {  //�Ҵ�� �޸𸮰� ���������� �������� Ŭ���
        for (int i = target + 1; i < tempsize; i++) { //position���� �ش��ϴ� data���� ��ĭ�� �ڷ� �ű��.
            data[i] = data[i - 1];
        }
        data[target] = value; //position�� �ش��ϴ� index�� value�� �����Ѵ�.
        _size = tempsize; //_size�� ���������� ������ŭ �����Ѵ�.
    }
}
void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last) {
    int arr_size = last - first;//last�� first�� �ּҰ� ���̸� �̿��Ͽ� �������� �迭�� ũ�⸦ ���Ѵ�.
    int tempsize = _size + arr_size;//���������� ���� �ش��ϴ� ���� tempsize ����
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        if (tempsize < 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Customer* temp = new Customer[tempsize];
            for (int i = 0; i < target; i++) {   //data�� ���� ���ο� ���� �������� position �� ���� temp�� ��� �������ش�.
                temp[i] = data[i];
            }
            for (int i = target + arr_size; i < tempsize; i++) { //data[target]������ ������ temp [target+arr_size]���� ���������� �����Ѵ�.
                temp[i] = data[i - arr_size];
            }   //�� ��� temp[target]���� temp[target+arr_size-1]�� �迭�� ���� �� �ְ�, �׵ڷδ� ���� �ִ� ������ ���������� ��Ÿ�� ���̴�.
            for (int i = target; i < target + arr_size; i++) {     //temp[target]���� first�� ������ �־��ָ� first ���� �������� �迭�� �־��ش�.
                temp[i] = *first;
                first++;
            }
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize;
        }   //data�� �����Ҵ� ������ �ϰ� �ٽ� temp�� �Ҵ��� ���ش�. _size�� _capacity�� ���������� ������ŭ ������Ʈ���ش�.
        else {  //���� ������ ������ 5���� ũ�ų� ���� ���,���� ������ ������ 2�踸ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Customer* temp = new Customer[tempsize * 2];
            for (int i = 0; i < target; i++) {   //data�� ���� ���ο� ���� �������� position �� ���� temp�� ��� �������ش�.
                temp[i] = data[i];
            }
            for (int i = target + arr_size; i < tempsize; i++) { //data[target]������ ������ temp [target+arr_size]���� ���������� �����Ѵ�.
                temp[i] = data[i - arr_size];
            }
            for (int i = target; i < target + arr_size; i++) {//temp[target]���� first�� ������ �־��ָ� first ���� �������� �迭�� �־��ش�.
                temp[i] = *first;
                first++;
            }
            delete[] data;
            data = temp;
            _size = tempsize;
            _capacity = tempsize * 2;
        }   //data�� �����Ҵ� ������ �ϰ� �ٽ� temp�� �Ҵ��� ���ش�. _size�� ���������� ���� ��ŭ, _capacity�� ���������� ������ 2�� ��ŭ ������Ʈ���ش�.
    }
    else {
        for (int i = target + arr_size; i < tempsize; i++) {  //�迭�� �������� �ϴ� position���� �� ���ĵ��� ������ ��� �迭 �����ŭ �ڷ� �Ű��ش�.
            data[i] = data[i - arr_size];
        }
        for (int i = target; i < target + arr_size; i++) {//temp[target]���� first�� ������ �־��ش�.
            data[i] = *first;
            first++;
        }
        _size = tempsize; //_size�� ���������� ������ŭ �����Ѵ�.
    }
}

void Vector_Customer::erase(iterator position) {
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    for (int i = target; i < _size - 2; i++) {  //position�� �ش��ϴ� �ε����� ������ �ش� ���� ������ ���� �����Ѵ�.
        data[i] = data[i + 1];
    }
    _size -= 1;   //_size ���� �ϳ� �ٿ��ش�.
}
void Vector_Customer::clear() {
    _size = 0;    //_size�� _capacity�� 0���� ������ش�.
    _capacity = 0;
    data = NULL;    //data�� NULL�� ���ش�.
}


Customer& Vector_Customer::operator[](int index) {
    return data[index];//index�� �������ش�.
}
const Customer& Vector_Customer::operator[](int index) const {
    return data[index];//index�� �������ش�.
}
Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v) {
    this->_size = v._size;  //this->_size�� v._size�� �����Ѵ�.
    this->_capacity = v._capacity;  //this->_capacity�� v._capacity�� �����Ѵ�.
    this->data = v.data;    //this->data�� v.data�� �����Ѵ�.
    return *this;   //*this�� �����Ѵ�.
}