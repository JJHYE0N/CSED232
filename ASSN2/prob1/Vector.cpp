#include "Vector.h"
#include <iostream>

//using namespace std;

Vector::Vector() {
    this->_size = 0;    //_size�� 0���� ����
    this->_capacity = 0;    //_capacity�� 0���� ����
    this->data = new float[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
    this->data = NULL;    //data�� NULL�� �ʱ�ȭ
}//�⺻ ������. ��� ��� ������ 0 Ȥ�� NULL�� �ʱ�ȭ�Ѵ�.
Vector::Vector(int size) {
    this->_size = size; //_size�� size�� ����
    this->_capacity = size; //_capacity�� size�� ����
    this->data = new float[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
    for (int i = 0; i < _size; i++) {   //size ���� ��ŭ 0���� �ʱ�ȭ�� ������ ����.
        *(this->data + i) = 0;
    }
}//������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ. size ������ŭ 0 ���� �ʱ�ȭ�� ������ ����.
Vector::Vector(int size, const float& init) {
    this->_size = size; //_size�� size�� ����
    this->_capacity = size; //_capacity�� size�� ����
    this->data = new float[_capacity];    //data�� capacity�� ũ�⸸ŭ �����Ҵ�
    this->data[0] = init; //data�� init�� ���� ����
}//float init ���� �ʱ�ȭ�� �����͸� ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ.
Vector::Vector(int size, const float* init) {   //size������ �������� ũ�⸦ �ʱ�ȭ���ְ�, init������ data���� �־��ش�.
    this->_size = size; //_size�� size�� ����
    this->_capacity = size; //capacity�� size �� ����
    this->data = new float[_capacity];    //_capacityũ�� ��ŭ�� data �����Ҵ�
    for (int i = 0; i < _size; i++) {   //data�� init�� ���� ���������� ����
        *(this->data + i) = init[i];
    }
}//float �迭 init ���� �ʱ�ȭ�� ������ ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ
Vector::Vector(const Vector& v) {
    this->_size = v._size;  //_size�� v._size�� ����
    this->_capacity = v._capacity;  //_capacity�� v._capacity�� ����
    this->data = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        this->data[i] = v.data[i];
    }
    //this->data = v.data;    //data�� v.data�� ����
};//���� ������
Vector::~Vector() {
    /*
    if (this->data) {    //data�� ����� �����Ҵ��� �������ش�.
        delete[] this->data;
        this->_capacity = 0;    //_capacity�� 0���� �Ѵ�.
        this->_size = 0;    //_size�� 0���� �Ѵ�.
    }
    */
    delete[] data;
};//�Ҹ���. �Ҵ�� �޸𸮸� �����Ѵ�.

int Vector::capacity() const {
    return _capacity;
};//�����Ϳ� �Ҵ�� �޸� ����� �����Ѵ�.
int Vector::size() const {
    return _size;
};//������ ������ �����Ѵ�.
Vector::iterator Vector::begin() {
    return &data[0];
};//�������� �� ó�� �ּҸ� �����Ѵ�.
Vector::const_iterator Vector::begin() const {
    return &data[0];
};//�������� �� ó�� �ּҸ� �����Ѵ�. (const ����)
Vector::iterator Vector::end() {
    return &data[_size];
};//�������� �� ������ �ּҸ� �����Ѵ�.
Vector::const_iterator Vector::end() const {
    return &data[_size];
};//�������� �� ������ �ּҸ� �����Ѵ�. (const ����)
float& Vector::front() {
    return(data[0]);
};//�������� �� ó�� �����͸� �����Ѵ�.
const float& Vector::front() const {
    return(data[0]);
};//�������� �� ó�� �����͸� �����Ѵ�. (const ����)
float& Vector::back() {
    return(data[_size - 1]);
};//�������� �� ������ �����͸� �����Ѵ�.
const float& Vector::back() const {
    return(data[_size - 1]);
};//�������� �� ������ �����͸� �����Ѵ�. (const ����)
void Vector::allocate(int capacity) {
    float* temp = new float[capacity];  //temp�� capacityũ��� �����Ҵ����ش�.
    for (int i = 0; i < _size; i++) { //temp�� ���� data�� ���� �־��ش�.
        temp[i] = data[i];
    }
    delete[] data;  //data�� �����Ҵ������Ѵ�.
    data = temp;    //data�� temp�� �Ҵ��Ѵ�.
    _capacity = capacity; //_capacity�� capacity�� �����Ѵ�.
};//�����Ϳ� �Ҵ�� �޸𸮸� capacity ��ŭ ���� �Ҵ��Ѵ�.
void Vector::resize(int size) {
    float* temp = new float[size];  //temp�� sizeũ��� �����Ҵ����ش�.
    for (int i = 0; i < size; i++) { //temp�� ���� data�� ���� �־��ش�.
        temp[i] = data[i];
    }
    delete[] data;  //data�� �����Ҵ������Ѵ�.
    data = temp;    //data�� temp�� �Ҵ��Ѵ�.
    _size = size; //_size�� size�� �����Ѵ�.
    _capacity = size; //_capacity�� size�� �����Ѵ�.
};//size ��ŭ �����Ϳ� �Ҵ�� �޸𸮸� ���� �Ҵ��ϸ�, ������ ������ size ��ŭ ���´�.

void Vector::push_back(const float& value) {
    int tempsize = _size + 1;   //���������� ���� �ش��ϴ� ���� tempsize ����
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        //������ 0 �߰� 1 �Ҵ� ������1 �϶� �׳� �ִ°ɷ� ���� =���� �ȵ� �� ����
        if (tempsize <= 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            float* temp = new float[tempsize];
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
            float* temp = new float[tempsize * 2];    //���� ������ ������ 2�� ��ŭ temp�� �����Ҵ��Ѵ�.
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
};//�������� �� �ڿ� ���ο� ������ value�� �߰��Ѵ�. 2.���� ���� ���� ��Ģ�� ���� �޸𸮸� ���� �Ҵ��Ѵ�.
void Vector::pop_back() {//������ �����͸� NULL������ �ٲ��ְ�, _size�� 1�� ���δ�.
    data[_size - 1] = NULL;
    _size--;

};//�� ������ �����͸� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
void Vector::insert(iterator position, const float& value) {
    int tempsize = _size + 1;   //���������� ���� �ش��ϴ� ���� tempsize ����
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        if (tempsize < 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            float* temp = new float[tempsize];
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
            float* temp = new float[tempsize * 2];
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
};//�������� Ư�� ��ġ(position)�� value �� �����Ѵ�.
// 2.���� ���� ���� ��Ģ�� ���� �޸𸮸� ���� �Ҵ��Ѵ�.
void Vector::insert(iterator position, const float* first, const float* last) {
    int arr_size = last - first;//last�� first�� �ּҰ� ���̸� �̿��Ͽ� �������� �迭�� ũ�⸦ ���Ѵ�.
    int tempsize = _size + arr_size;//���������� ���� �ش��ϴ� ���� tempsize ����
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    if (tempsize >= _capacity) {  //������ �߰� ��, ���� ������ ������ ���� �Ҵ�� �޸� ������� ũ�ų� ���� ���, �޸𸮸� �ٽ� �Ҵ��� �� �����͸� �߰��Ѵ�.
        if (tempsize < 5) {    //���� ������ ������ 5���� �������,���� ������ ������ŭ�� �޸𸮸� �Ҵ��Ѵ�
            float* temp = new float[tempsize];
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
            float* temp = new float[tempsize * 2];
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

};//�����Ϳ��� Ư�� ��ġ(position)�� float array �� �����Ѵ�.
// �̶� first, last �� ���� float array�� �� ó�� �ּ�, �� ������ �ּ��̴�.
void Vector::erase(iterator position) {
    int target = position - begin();    //begin()�� position�� �ּҰ� ���̸� �̿��Ͽ� target index�� ���Ѵ�.
    for (int i = target; i < _size; i++) {  //position�� �ش��ϴ� �ε����� ������ �ش� ���� ������ ���� �����Ѵ�.
        data[i] = data[i + 1];
    }
    _size -= 1;   //_size ���� �ϳ� �ٿ��ش�.

};//�����Ϳ��� Ư�� ��ġ(position)�� ���� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
void Vector::clear() {
    _size = 0;    //_size�� _capacity�� 0���� ������ش�.
    _capacity = 0;
    data = NULL;    //data�� NULL�� ���ش�.
};//�Ҵ�� �޸� ������, ������ ������ 0 ���� �����ϸ�, �����͸� NULL �� �����Ѵ�.
float& Vector::operator[](int index) {
    return data[index];
};//������ '[]'�� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�.
const float& Vector::operator[](int index) const {
    return data[index];
};//������ '[]'�� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�. (const ����)
Vector& Vector::operator=(const Vector& v) {
    this->_size = v._size;  //this->_size�� v._size�� �����Ѵ�.
    this->_capacity = v._capacity;  //this->_capacity�� v._capacity�� �����Ѵ�.
    this->data = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        this->data[i] = v.data[i];    //this->data�� v.data�� �����Ѵ�.
    }
    return *this;   //this�� �����Ѵ�.
};//������ '='�� �����ε��Ѵ�. ���� ��������� �Է� Vector �� ��������� ġȯ�Ѵ�.