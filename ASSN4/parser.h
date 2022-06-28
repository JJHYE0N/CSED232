#ifndef OOP_ASSN4_PARSER_H
#define OOP_ASSN4_PARSER_H
#include <vector>
#include <sstream>
#include "rectangle.h"
#include "point.h"
#include "geometry.h"
#include "canvas2d.h"
#include <string>

using namespace std;

class parser {
    //string을 받아 객체의 instance를 생성하는 기능을 제공하는 class
private:

public:
    canvas2d parse_canvas(const string& line) {
        int width, height;  //너비 높이를 정수형으로 선언한다.
        char c_empty;   //c_empty를 문자형으로 선언한다.

        stringstream ss(line);
        string value;
        vector<string> temp;
        char c_[2];

        getline(ss, value, ',');    //x값을 입력받는다
        temp.push_back(value);
        width = stoi(temp[0]);
        getline(ss, value, ',');    //y값을 입력받는다.
        temp.push_back(value);
        height = stoi(temp[1]);
        getline(ss, value);
        strcpy(c_, value.c_str());  //string -> char을 이용하여 문자를 입력받는다. 
        c_empty = c_[0];

        return canvas2d(width, height, c_empty);    //canvas2d를 리턴한다.
    }

    geometry* parse_geometry(const string& line) {
        int N = 0;
        stringstream ss(line);
        string value;
        //string temp;
        //vector<string> temp;

        getline(ss, value, ',');
        if (value == "point") { //point인 경우 
            getline(ss, value, ',');
            if (value == "int") {   //int 형
                int array[5] = { 0,0,0,0,0 };
                int i = 0;
                while (getline(ss, value, ',')) {   //array에 정수값을 넣어준다. 
                    array[i] = stoi(value);
                    N++;
                    i++;
                }

                if (N == 2) {//2차원의 경우 
                    point<int, 2>* pt = new point<int, 2>(array);//point 포인터 만들어서 동적할당 해주고
                    return pt;//메모리 누수(힙오류) 안일어나게 하는 방법
                }
                else if (N == 3) {//3차원의 경우
                    point<int, 3>* pt = new point<int, 3>(array);
                    return pt;
                }
                else if (N == 4) {//4차원의 경우
                    point<int, 4>* pt = new point<int, 4>(array);
                    return pt;
                }
                else if (N == 5) {//5차원의 경우 
                    point<int, 5>* pt = new point<int, 5>(array);//point 포인터 만들어서 동적할당 해주고
                    return pt;
                }

            }
            else if (value == "float") {    //float 형
                float array[5] = { 0.0,0.0,0.0,0.0,0.0 };    
                int i = 0;
                while (getline(ss, value, ',')) { //array에 float값을 넣어준다.
                    array[i] = stof(value);
                    N++;
                    i++;
                }
                //rectangle<int> *rec_ = new rectangle<int>(array[0],array[1],array[2],array[3]);
                if (N == 2) {//2차원의 경우 
                    point<float, 2>* pt = new point<float, 2>(array);
                    return pt;
                }
                else if (N == 3) {//3차원의 경우 
                    point<float, 3>* pt = new point<float, 3>(array);
                    return pt;
                }
                else if (N == 4) {//4차원의 경우 
                    point<float, 4>* pt = new point<float, 4>(array);
                    return pt;
                }
                else if (N == 5) {//5차원의 경우 
                    point<float, 5>* pt = new point<float, 5>(array);//point 포인터 만들어서 동적할당 해주고
                    return pt;
                }//메모리 누수(힙오류) 안일어나게 하는 방법
            }

        }
        else if (value == "rectangle") {//rectangle의 경우 
            getline(ss, value, ',');
            if (value == "int") {   //int 형
                int array[4];
                int i = 0;
                while (getline(ss, value, ',')) {
                    array[i] = stoi(value);
                    i++;
                }

                rectangle<int>* rec_ = new rectangle<int>(array[0], array[1], array[2], array[3]);//ractangle 포인터 만들어서 동적할당 해주고
                return rec_;//메모리 누수(힙오류) 안일어나게 하는 방법
            }
            else if (value == "float") {    //float 형
                float array[4];
                int i = 0;
                while (getline(ss, value, ',')) {
                    array[i] = stof(value);
                    i++;
                }

                rectangle<float>* rec_ = new rectangle<float>(array[0], array[1], array[2], array[3]);//ractangle 포인터 만들어서 동적할당 해주고
                return rec_;//메모리 누수(힙오류) 안일어나게 하는 방법
            }
        }
        else throw;

        return 0;
    }
};

#endif //OOP_ASSN4_PARSER_H