#include <iostream>
#include <fstream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    char calc;  //어떤 연산을 수행할지 입력받을 char형 변수 선언
    float num1,num2,result; //1,2번째 값과 이들의 연산결과를 저장할 변수를 float로 선언
    std::ifstream file1("input.txt");   //input.txt 파일 읽기 형식으로 호출
    std::ofstream file2("output.txt");  //output.txt 파일 쓰기 형식으로 호출

    while (!file1.eof()) {  //file1의 파일을 끝까지 부르도록 end of file 명령어 사용
        file1 >> calc >> num1 >> num2;  //calc
        result = 0; //result =0 으로 초기화

        //char형태로 calc 값에 따라 해당하는 연산을 수행한다.
        if (calc == '+') result = num1 + num2;
        else if (calc == '-') result = num1 - num2;
        else if (calc == '*') result = num1 * num2;
        else if (calc == '/') result = num1 / num2;

        //cmath 헤더파일을 사용
        //round는 소수 첫째자리를 이용해 반올림을 하므로
        //소숫점 아래 3자리까지 반올림하기 위해 10의 3승을 곱하고 반올림하고 다시 나눠주는 과정을 거친다.
        result*=1000;
        result = round(result);
        result/=1000;

        file2 << std::fixed;    //항상 소숫점 3자리까지 표시하기 위해 fixed와 precision 을 사용한다
        file2.precision(3);
        file2 << result << "\n";
        //if(file1.eof());
    }
    file1.close();  //file1 닫기
    file2.close();  //file2 닫기
    return 0;
}