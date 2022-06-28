#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

void sort_year(int year[], std::string name[], int size);
void sort_name(int year[], std::string name[], int size);

int main() {
    const int num = 100;
    int year[num];
    std::string name[num];
    std::ifstream file1("input.txt");   //input.txt�� file1���� �б���� �����Ѵ�.
    std::ofstream file2("output.txt");  //output.txt�� file2���� ������� �����Ѵ�.

    int size = 0;
    while (!file1.eof()) {  //eof�� �̿��Ͽ� ������ input.txt�� �о��ش�.
        file1 >> year[size] >> name[size];    //input.txt�� �������� �о year�� name �迭�� �����Ѵ�.
        size++;
    }

    //����1 (������ �������� ������������ �����ϴ� �Լ� sort_year ȣ���Ѵ�.)
    sort_year(year, name, size);
    //����2 (����ڵ带 �������� ������������ �����ϴ� �Լ� sort_name ȣ���Ѵ�.)
    sort_name(year, name, size);

    for (int i = 0; i < size; i++) {
        file2 << year[i] << " " << name[i] << "\n";  //������ ������ �������� output.txt�� �Է����ش�.
    }
    file1.close();  //file1�� �ݴ´�.
    file2.close();  //file2�� �ݴ´�.
    return 0;
}

void sort_year(int year[], std::string name[], int size) {
    std::string temp_str;   //������ ���� �ӽ÷� string�� ���� temp_str �����Ѵ�.
    int temp_num;   //������ ���� �ӽ÷� �������� ���� temp_num�� �����Ѵ�.
    for (int i = 0; i < size - 1; i++) {  //for������ ù��° �ڸ����� ���� ���� �������� ������ �ϴ� ���������� �Ѵ�.
        int least = i;    //���� ���� ���� ������ ���� least �� �����ϰ� i������ �ʱ�ȭ���ش�.
        for (int j = i + 1; j < size; j++) {    //j�� i���� ū ������ for���� �����ش�
            if (year[least] > year[j]) least = j;    //least�� �ش��ϴ� �������� j�� �ش��ϴ� ������ �� ���� ��� least�� j�� �ʱ�ȭ ���ش�
        }

        if (least != i) {    //���� least�� �ʱ�ȭ�� ��� ��� i�� least�� �ش��ϴ� ������ ����ڵ带 �������ش�.
            temp_num = year[least];
            year[least] = year[i];
            year[i] = temp_num;

            temp_str = name[least];
            name[least] = name[i];
            name[i] = temp_str;
        }
    }
}

void sort_name(int year[], std::string name[], int size) {
    std::string temp_str;   //������ ���� �ӽ÷� string�� ���� temp_str �����Ѵ�.
    int temp_num;   //������ ���� �ӽ÷� �������� ���� temp_num�� �����Ѵ�.
    for (int i = 0; i < size - 1; i++) {  //for������ ù��° �ڸ����� ���� ���� ����ڵ尡 ������ �ϴ� ���������� �Ѵ�.
        int least = i;    //���� ���� ���� ������ ���� least �� �����ϰ� i������ �ʱ�ȭ���ش�.
        for (int j = i + 1; j < size; j++) {    //j�� i���� ū ������ for���� �����ش�
            if (name[least] > name[j] && year[least] == year[j]) least = j;
            //least�� �ش��ϴ� ����ڵ� ���� j�� �ش��ϴ� ����ڵ尡 �� ���� ��� least�� j�� �ʱ�ȭ ���ش�
            //�̶� ���� ���������� ����ڵ��� �񱳸� �� �� �ֵ��� year�� ������ &�����ڷ� �Ǵ��� ���־� �ʱ�ȭ�� ���ش�.
        }
        if (least != i) {       //���� least�� �ʱ�ȭ�� ��� ��� i�� least�� �ش��ϴ� ������ ����ڵ带 �������ش�.
            temp_num = year[least];
            year[least] = year[i];
            year[i] = temp_num;

            temp_str = name[least];
            name[least] = name[i];
            name[i] = temp_str;
        }
    }
}