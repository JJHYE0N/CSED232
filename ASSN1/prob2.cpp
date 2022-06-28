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
    std::ifstream file1("input.txt");   //input.txt를 file1으로 읽기모드로 실행한다.
    std::ofstream file2("output.txt");  //output.txt를 file2으로 쓰기모드로 실행한다.

    int size = 0;
    while (!file1.eof()) {  //eof를 이용하여 끝까지 input.txt를 읽어준다.
        file1 >> year[size] >> name[size];    //input.txt를 차근차근 읽어서 year와 name 배열에 저장한다.
        size++;
    }

    //정렬1 (연도를 기준으로 오름차순으로 정렬하는 함수 sort_year 호출한다.)
    sort_year(year, name, size);
    //정렬2 (장소코드를 기준으로 오름차순으로 정렬하는 함수 sort_name 호출한다.)
    sort_name(year, name, size);

    for (int i = 0; i < size; i++) {
        file2 << year[i] << " " << name[i] << "\n";  //정리된 순서를 바탕으로 output.txt에 입력해준다.
    }
    file1.close();  //file1을 닫는다.
    file2.close();  //file2를 닫는다.
    return 0;
}

void sort_year(int year[], std::string name[], int size) {
    std::string temp_str;   //정렬을 위해 임시로 string을 담을 temp_str 선언한다.
    int temp_num;   //정렬을 위해 임시로 정수값을 담을 temp_num을 선언한다.
    for (int i = 0; i < size - 1; i++) {  //for문으로 첫번째 자리부터 가장 작은 연도값이 오도록 하는 선택정렬을 한다.
        int least = i;    //가장 작은 값의 순서를 담을 least 를 선언하고 i값으로 초기화해준다.
        for (int j = i + 1; j < size; j++) {    //j를 i보다 큰 값으로 for문을 돌려준다
            if (year[least] > year[j]) least = j;    //least에 해당하는 연도보다 j에 해당하는 연도가 더 작을 경우 least를 j로 초기화 해준다
        }

        if (least != i) {    //만약 least가 초기화된 경우 라면 i와 least에 해당하는 연도와 장소코드를 스왑해준다.
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
    std::string temp_str;   //정렬을 위해 임시로 string을 담을 temp_str 선언한다.
    int temp_num;   //정렬을 위해 임시로 정수값을 담을 temp_num을 선언한다.
    for (int i = 0; i < size - 1; i++) {  //for문으로 첫번째 자리부터 가장 작은 장소코드가 오도록 하는 선택정렬을 한다.
        int least = i;    //가장 작은 값의 순서를 담을 least 를 선언하고 i값으로 초기화해준다.
        for (int j = i + 1; j < size; j++) {    //j를 i보다 큰 값으로 for문을 돌려준다
            if (name[least] > name[j] && year[least] == year[j]) least = j;
            //least에 해당하는 장소코드 보다 j에 해당하는 장소코드가 더 작을 경우 least를 j로 초기화 해준다
            //이때 같은 연도에서만 장소코드의 비교를 할 수 있도록 year가 같은지 &연산자로 판단을 해주어 초기화를 해준다.
        }
        if (least != i) {       //만약 least가 초기화된 경우 라면 i와 least에 해당하는 연도와 장소코드를 스왑해준다.
            temp_num = year[least];
            year[least] = year[i];
            year[i] = temp_num;

            temp_str = name[least];
            name[least] = name[i];
            name[i] = temp_str;
        }
    }
}