#ifndef OOP_ASSN2_2_VECTOR_CUSTOMER_H
#define OOP_ASSN2_2_VECTOR_CUSTOMER_H
#include "Customer.h"

using namespace std;

class Vector_Customer
{
private:
    Customer* data;//�����͸� ���� data����
    int _capacity;//�޸��� ũ�⿡ �ش��ϴ� _capacity ����
    int _size;//�������� ũ�⿡ �ش��ϴ� _size ����
public:
    typedef Customer* iterator;//Customer*�� iterator ������ ����.
    typedef const Customer* const_iterator;//const Customer*�� const_iterator ������ ����

    Vector_Customer();//�⺻ ������. ��� ��� ������ 0 Ȥ�� NULL�� �ʱ�ȭ�Ѵ�.
    Vector_Customer(int size);//������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ. size ������ŭ 0 ���� �ʱ�ȭ�� ������ ����.
    Vector_Customer(int size, const Customer& init);//Customer init ���� �ʱ�ȭ�� �����͸� ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ.
    Vector_Customer(int size, const Customer* init);//Customer �迭 init ���� �ʱ�ȭ�� ������ ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ
    Vector_Customer(const Vector_Customer& v);//���� ������
    ~Vector_Customer();//�Ҹ���

    int capacity() const;//�����Ϳ� �Ҵ�� �޸� ����� �����Ѵ�.
    int size() const;//������ ������ �����Ѵ�.

    iterator begin();//�������� �� ó�� �ּҸ� �����Ѵ�.
    const_iterator begin() const;//�������� �� ó�� �ּҸ� �����Ѵ�. (const ����)
    iterator end();//�������� �� ������ �ּҸ� �����Ѵ�.
    const_iterator end() const;//�������� �� ������ �ּҸ� �����Ѵ�. (const ����)
    Customer& front();//�������� �� ó�� �����͸� �����Ѵ�.
    const Customer& front() const;//�������� �� ó�� �����͸� �����Ѵ�. (const ����)
    Customer& back();//�������� �� ������ �����͸� �����Ѵ�.
    const Customer& back() const;//�������� �� ������ �����͸� �����Ѵ�. (const ����)

    void allocate(int capacity);//�����Ϳ� �Ҵ�� �޸𸮸� capacity ��ŭ ���� �Ҵ��Ѵ�.
    void resize(int size);//size ��ŭ �����Ϳ� �Ҵ�� �޸𸮸� ���� �Ҵ��ϸ�, ������ ������ size ��ŭ ���´�.

    void push_back(const Customer& value);//�������� �� �ڿ� ���ο� ������ value�� �߰��Ѵ�
    void pop_back();//�� ������ �����͸� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
    void insert(iterator position, const Customer& value);//�������� Ư�� ��ġ(position)�� value �� �����Ѵ�
    void insert(iterator position, const Customer* first, const Customer* last);//�����Ϳ��� Ư�� ��ġ(position)�� Customer array �� �����Ѵ�.

    void erase(iterator position);//�����Ϳ��� Ư�� ��ġ(position)�� ���� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
    void clear();//�Ҵ�� �޸� ������, ������ ������ 0 ���� �����ϸ�, �����͸� NULL �� �����Ѵ�

    Customer& operator[](int index);//������ '[]'�� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�.
    const Customer& operator[](int index) const;//������ '[]'�� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�. (const ����)
    Vector_Customer& operator=(const Vector_Customer& v);//������ '='�� �����ε��Ѵ�. ���� ��������� �Է� Vector �� ��������� ġȯ�Ѵ�.
};

#endif //OOP_ASSN2_2_VECTOR_CUSTOMER_H