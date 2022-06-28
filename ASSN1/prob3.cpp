#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

int check_fn(int table[10][10], int i, int j, int k, int count, int* d, int x, int y);

int main() {
    using namespace std;
    ifstream file1("input.txt");
    ofstream file2("output.txt");

    char table_char[10][10];    //input.txt�� ���ڵ��� �о��ֱ� ���� char�� 2���� �迭 ����
    int table_int[10][10];  //�о char�� 2���� �迭�� ������ 2���� �迭�� �ٲ��ֱ� ���� int�� 2���� �迭 ����
    int d1 = 1000, d2 = 1000;  //(0,0) to k �� �ִܰŸ� d1�� 1000���� �ʱ�ȭ �� k to e �� �ִܰŸ� d2�� 100���� �ʱ�ȭ
    int x1, x2, y1, y2;    //x1,y1 -> k�� ��ǥ / x2,y2 -> e�� ��ǥ

    for (int i = 0; i < 10; i++) {  //input.txt�� ���ڵ��� �о��ش�
        for (int j = 0; j < 10; j++) {
            file1 >> table_char[i][j];
        }
    }

    //char�� 2���� �迭�� int �� 2���� �迭�� ��ȯ
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (table_char[i][j] == '0') table_int[i][j] = 0;   //���� 0�� ���� 0����
            else if (table_char[i][j] == '1') table_int[i][j] = 1;  //���� 1�� ���� 1��
            else if (table_char[i][j] == 'k') {   //���� k�� ������ ���� 0���� �ϰ�, �ش� ��ǥ(i,j)�� (x1,y1) �� ����
                table_int[i][j] = 0;
                x1 = i;
                y1 = j;
            }
            else if (table_char[i][j] == 'e') {   //���� e�� ������ ���� 0���� �ϰ�, �ش� ��ǥ(i,j)�� (x2,y2) �� ����
                table_int[i][j] = 0;
                x2 = i;
                y2 = j;
            }
        }
    }
    //�Լ� ȣ��
    check_fn(table_int, 0, 0, 0, 0, &d1, x1, y1);  //(0,0) to k ������ �ִܰŸ��� ���Ѵ�
    check_fn(table_int, x1, y1, 1, 0, &d2, x2, y2);   //k to e ������ �ִܰŸ��� ���Ѵ�.

    file2 << d1 + d2;    //d1+d2 ���� output.txt�� ���
    file1.close();  //input.txt�� �ݴ´�.
    file2.close();  //output.txt�� �ݴ´�.
    return 0;
}

int check_fn(int table[10][10], int i, int j, int k, int count, int* d, int x, int y) {
    //table_int�� ���ڷ� �ް�, �ʱ� ��ǥ�� �ش��ϴ� i,j ���� �ް� �̵��� �Ÿ��� �ش��ϴ� count�� �Ű��� �ް�,
    //(0,0)->k �϶����� k==0�̰� k->e �϶����� k==1�� �����ϱ� ���� ������ ���� k�� �Ű��Ѵ�.
    //
    //*d�� ���� (0,0)->k�� �ִܰŸ� d1�� �ּҿ� k->e�� �ִܰŸ� d2�� �ּҸ� �޾� ������Ʈ �ϵ��� �ϰ�
    //������ ���� x,y�� ��ǥ���ϴ� ��ǥ�� �ǹ��ϰ� k==0�� �� x,y�� k�� ��ǥ��, k==1�� �� x,y�� e�� ��ǥ�̴�.
    if (k == 0 && i == x && j == y) {  //k==0�� �� i,j�� ��ǥ���ϴ� ��ġ x,y(k�� ��ǥ)�� �����ߴ��� �Ǵ�
        if (count < *d) *d = count; //���� count (�̵��Ÿ���) �ִܰŸ����� ���� ��� �ִܰŸ��� ������Ʈ ���ش�.
        return 0;   //�Լ� ����
    }
    else if (k == 1 && i == x && j == y) { //k==1�� �� i,j�� ��ǥ���ϴ� ��ġ x,y(e�� ��ǥ)�� �����ߴ��� �Ǵ�
        if (count < *d) *d = count; //���� count (�̵��Ÿ���) �ִܰŸ����� ���� ��� �ִܰŸ��� ������Ʈ ���ش�.
        return 0;   //�Լ� ����
    }
    table[i][j] = 1;  //������ ���� �ߺ� ���������� 1�� ������ش�.

    //�����¿�� �����̴µ� �̶� i/j>0 Ȥ�� i,j<9�� �̵��� ���� ������ ���� ���� 1�� ���� �������� �ʵ��� �Ѵ�.
    //check_fn�Լ��� ����ϸ鼭 count�� ��� �������Ѽ� �̵��� �Ÿ��� �������ش�.
    //��
    if (j > 0 && table[i][j - 1] != 1) {
        check_fn(table, i, j - 1, k, count + 1, d, x, y);
    }
    //�Ʒ�
    if (j < 9 && table[i][j + 1] != 1) {
        check_fn(table, i, j + 1, k, count + 1, d, x, y);
    }
    //����
    if (i > 0 && table[i - 1][j] != 1) {
        check_fn(table, i - 1, j, k, count + 1, d, x, y);
    }
    //������
    if (i < 9 && table[i + 1][j] != 1) {
        check_fn(table, i + 1, j, k, count + 1, d, x, y);
    }

    table[i][j] = 0; //�� ���� ���� ��� 0���� ���� �ٸ� ��θ� Ž���ϵ��� �Ѵ�.
}