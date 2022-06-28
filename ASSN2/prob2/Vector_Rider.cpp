#include "Vector_Rider.h"
#include "Rider.h"
#include <iostream>

Vector_Rider::Vector_Rider() {
    _size = 0;    //_size�� 0���� ����
    _capacity = 0;    //_capacity�� 0���� ����
    data = new Rider[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
}
Vector_Rider::Vector_Rider(int size) {
    _size = size; //_size�� size�� ����
    _capacity = size; //_capacity�� size�� ����
    data = new Rider[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�


    for (int i = 0; i < _size; i++) {   //size ���� ��ŭ 0���� �ʱ�ȭ�� ������ ����.    
        data[i].Rider::Rider();
    }

}
Vector_Rider::Vector_Rider(int size, const Rider& init) {
    _size = size; //_size�� size�� ����
    _capacity = size; //_capacity�� size�� ����
    data = new Rider[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
    data[0] = init; //data�� init�� ���� ����
}
Vector_Rider::Vector_Rider(int size, const Rider* init) {
    _size = size; //_size�� size�� ����
    _capacity = size; //capacity�� size �� ����
    data = new Rider[_capacity];    //_capacityũ�� ��ŭ�� data �����Ҵ�
    for (int i = 0; i < _size; i++) {   //data�� init�� ���� ���������� ����
        *(data + i) = init[i];
    }
}
Vector_Rider::Vector_Rider(const Vector_Rider& v) {
    _size = v._size;  //_size�� v._size�� ����
    _capacity = v._capacity;  //_capacity�� v._capacity�� ����
    data = v.data;    //data�� v.data�� ����
}
Vector_Rider::~Vector_Rider() { }//�Ҹ���

int Vector_Rider::capacity() const {
    return _capacity;//capacity�� �������ش�.
}
int Vector_Rider::size() const {
    return _size;//size�� �������ش�.
}

Vector_Rider::iterator Vector_Rider::begin() {
    return &data[0];//���ͷ������� ���� �κ��� �����Ѵ�.
}
Vector_Rider::const_iterator Vector_Rider::begin() const {
    return &data[0];//���ͷ������� ���� �κ��� �����Ѵ�.
}
Vector_Rider::iterator Vector_Rider::end() {
    return data + _size;//���ͷ������� ���� �κ��� �����Ѵ�.
}
Vector_Rider::const_iterator Vector_Rider::end() const {
    return data + _size;//���ͷ������� ���� �κ��� �����Ѵ�.
}
Rider& Vector_Rider::front() {
    return(data[0]);//�պκ��� �������ش�.
}
const Rider& Vector_Rider::front() const {
    return(data[0]);//�պκ��� �������ش�.
}
Rider& Vector_Rider::back() {
    return(data[_size - 1]);//������ �κ��� �������ش�.
}
const Rider& Vector_Rider::back() const {
    return(data[_size - 1]);//������ �κ��� �������ش�.
}

void Vector_Rider::allocate(int capacity) {
    Rider* temp = new Rider[capacity];  //temp�� capacityũ��� �����Ҵ����ش�.
    for (int i = 0; i < _size; i++) { //temp�� ���� data�� ���� �־��ش�.
        temp[i] = data[i];
    }
    delete[] data;  //data�� �����Ҵ������Ѵ�.
    data = temp;    //data�� temp�� �Ҵ��Ѵ�.
    _capacity = capacity; //_capacity�� capacity�� �����Ѵ�.
}
void Vector_Rider::resize(int size) {
    Rider* temp = new Rider[size];  //temp�� sizeũ��� �����Ҵ����ش�.
    for (int i = 0; i < size; i++) { //temp�� ���� data�� ���� �־��ش�.
        temp[i] = data[i];
    }
    delete[] data;  //data�� �����Ҵ������Ѵ�.
    data = temp;    //data�� temp�� �Ҵ��Ѵ�.
    _size = size; //_size�� size�� �����Ѵ�.
    _capacity = size; //_capacity�� size�� �����Ѵ�.
}

void Vector_Rider::push_back(const Rider& value) {
    int tempsize = _size + 1;   //���������� ���� �ش��ϴ� ���� tempsize ����
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        //������ 0 �߰� 1 �Ҵ� ������1 �϶� �׳� �ִ°ɷ� ���� =���� �ȵ� �� ����
        if (tempsize <= 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Rider* temp = new Rider[tempsize];
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
            Rider* temp = new Rider[tempsize * 2];    //���� ������ ������ 2�� ��ŭ temp�� �����Ҵ��Ѵ�.
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
void Vector_Rider::pop_back() {//�������� ������ �κ��� �����. ����� 1 �ٿ��ش�.
    data[_size - 1].Rider::Rider();
    _size--;
}
void Vector_Rider::insert(iterator position, const Rider& value) {
    int tempsize = _size + 1;   //���������� ���� �ش��ϴ� ���� tempsize ����
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        if (tempsize < 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Rider* temp = new Rider[tempsize];
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
            Rider* temp = new Rider[tempsize * 2];
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
void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last) {
    int arr_size = last - first;//last�� first�� �ּҰ� ���̸� �̿��Ͽ� �������� �迭�� ũ�⸦ ���Ѵ�.
    int tempsize = _size + arr_size;//���������� ���� �ش��ϴ� ���� tempsize ����
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        if (tempsize < 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            Rider* temp = new Rider[tempsize];
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
            Rider* temp = new Rider[tempsize * 2];
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

void Vector_Rider::erase(iterator position) {
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    for (int i = target; i < _size - 1; i++) {  //position�� �ش��ϴ� �ε����� ������ �ش� ���� ������ ���� �����Ѵ�.
        data[i] = data[i + 1];
    }
    _size -= 1;   //_size ���� �ϳ� �ٿ��ش�.
}
void Vector_Rider::clear() {
    _size = 0;    //_size�� _capacity�� 0���� ������ش�.
    _capacity = 0;
    data = NULL;    //data�� NULL�� ���ش�.
}

Rider& Vector_Rider::operator[](int index) {
    return data[index];//index�� �������ش�.
}
const Rider& Vector_Rider::operator[](int index) const {
    return data[index];//index�� �������ش�.
}
Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v) {
    this->_size = v._size;  //this->_size�� v._size�� �����Ѵ�.
    this->_capacity = v._capacity;  //this->_capacity�� v._capacity�� �����Ѵ�.
    this->data = v.data;    //this->data�� v.data�� �����Ѵ�.
    return *this;   //this�� �����Ѵ�.
}