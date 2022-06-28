#ifndef OOP_ASSN2_2_VECTOR_RIDER_H
#define OOP_ASSN2_2_VECTOR_RIDER_H
#include "Rider.h"

using namespace std;


class Vector_Rider
{
private:
    Rider* data;//�����͸� ���� data����
    int _capacity;//�޸��� ũ�⿡ �ش��ϴ� _capacity ����
    int _size;//�������� ũ�⿡ �ش��ϴ� _size ����
public:
    typedef Rider* iterator;//Rider*�� iterator ������ ����.
    typedef const Rider* const_iterator;//const Rider*�� const_iterator ������ ����

    Vector_Rider();//�⺻ ������. ��� ��� ������ 0 Ȥ�� NULL�� �ʱ�ȭ�Ѵ�.
    Vector_Rider(int size);//������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ. size ������ŭ 0 ���� �ʱ�ȭ�� ������ ����.
    Vector_Rider(int size, const Rider& init);//Rider init ���� �ʱ�ȭ�� �����͸� ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ.
    Vector_Rider(int size, const Rider* init);//Rider �迭 init ���� �ʱ�ȭ�� ������ ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ
    Vector_Rider(const Vector_Rider& v);//���� ������
    ~Vector_Rider();//�Ҹ���

    int capacity() const;//�����Ϳ� �Ҵ�� �޸� ����� �����Ѵ�.
    int size() const;//������ ������ �����Ѵ�.

    iterator begin();//�������� �� ó�� �ּҸ� �����Ѵ�.
    const_iterator begin() const;//�������� �� ó�� �ּҸ� �����Ѵ�. (const ����)
    iterator end();//�������� �� ������ �ּҸ� �����Ѵ�.
    const_iterator end() const;//�������� �� ������ �ּҸ� �����Ѵ�. (const ����)
    Rider& front();//�������� �� ó�� �����͸� �����Ѵ�.
    const Rider& front() const;//�������� �� ó�� �����͸� �����Ѵ�. (const ����)
    Rider& back();//�������� �� ������ �����͸� �����Ѵ�.
    const Rider& back() const;//�������� �� ������ �����͸� �����Ѵ�. (const ����)

    void allocate(int capacity);//�����Ϳ� �Ҵ�� �޸𸮸� capacity ��ŭ ���� �Ҵ��Ѵ�.
    void resize(int size);//size ��ŭ �����Ϳ� �Ҵ�� �޸𸮸� ���� �Ҵ��ϸ�, ������ ������ size ��ŭ ���´�.

    void push_back(const Rider& value);//�������� �� �ڿ� ���ο� ������ value�� �߰��Ѵ�
    void pop_back();//�� ������ �����͸� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
    void insert(iterator position, const Rider& value); //�������� Ư�� ��ġ(position)�� value �� �����Ѵ�
    void insert(iterator position, const Rider* first, const Rider* last);//�����Ϳ��� Ư�� ��ġ(position)�� Rider array �� �����Ѵ�.

    void erase(iterator position);//�����Ϳ��� Ư�� ��ġ(position)�� ���� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
    void clear();//�Ҵ�� �޸� ������, ������ ������ 0 ���� �����ϸ�, �����͸� NULL �� �����Ѵ�


    Rider& operator[](int index);//������ '[]'�� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�.
    const Rider& operator[](int index) const;//������ '[]'�� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�. (const ����)
    Vector_Rider& operator=(const Vector_Rider& v);//������ '='�� �����ε��Ѵ�. ���� ��������� �Է� Vector �� ��������� ġȯ�Ѵ�.
};

#endif //OOP_ASSN2_2_VECTOR_RIDER_H