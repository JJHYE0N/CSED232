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
    //string�� �޾� ��ü�� instance�� �����ϴ� ����� �����ϴ� class
private:

public:
    canvas2d parse_canvas(const string& line) {
        int width, height;  //�ʺ� ���̸� ���������� �����Ѵ�.
        char c_empty;   //c_empty�� ���������� �����Ѵ�.

        stringstream ss(line);
        string value;
        vector<string> temp;
        char c_[2];

        getline(ss, value, ',');    //x���� �Է¹޴´�
        temp.push_back(value);
        width = stoi(temp[0]);
        getline(ss, value, ',');    //y���� �Է¹޴´�.
        temp.push_back(value);
        height = stoi(temp[1]);
        getline(ss, value);
        strcpy(c_, value.c_str());  //string -> char�� �̿��Ͽ� ���ڸ� �Է¹޴´�. 
        c_empty = c_[0];

        return canvas2d(width, height, c_empty);    //canvas2d�� �����Ѵ�.
    }

    geometry* parse_geometry(const string& line) {
        int N = 0;
        stringstream ss(line);
        string value;
        //string temp;
        //vector<string> temp;

        getline(ss, value, ',');
        if (value == "point") { //point�� ��� 
            getline(ss, value, ',');
            if (value == "int") {   //int ��
                int array[5] = { 0,0,0,0,0 };
                int i = 0;
                while (getline(ss, value, ',')) {   //array�� �������� �־��ش�. 
                    array[i] = stoi(value);
                    N++;
                    i++;
                }

                if (N == 2) {//2������ ��� 
                    point<int, 2>* pt = new point<int, 2>(array);//point ������ ���� �����Ҵ� ���ְ�
                    return pt;//�޸� ����(������) ���Ͼ�� �ϴ� ���
                }
                else if (N == 3) {//3������ ���
                    point<int, 3>* pt = new point<int, 3>(array);
                    return pt;
                }
                else if (N == 4) {//4������ ���
                    point<int, 4>* pt = new point<int, 4>(array);
                    return pt;
                }
                else if (N == 5) {//5������ ��� 
                    point<int, 5>* pt = new point<int, 5>(array);//point ������ ���� �����Ҵ� ���ְ�
                    return pt;
                }

            }
            else if (value == "float") {    //float ��
                float array[5] = { 0.0,0.0,0.0,0.0,0.0 };    
                int i = 0;
                while (getline(ss, value, ',')) { //array�� float���� �־��ش�.
                    array[i] = stof(value);
                    N++;
                    i++;
                }
                //rectangle<int> *rec_ = new rectangle<int>(array[0],array[1],array[2],array[3]);
                if (N == 2) {//2������ ��� 
                    point<float, 2>* pt = new point<float, 2>(array);
                    return pt;
                }
                else if (N == 3) {//3������ ��� 
                    point<float, 3>* pt = new point<float, 3>(array);
                    return pt;
                }
                else if (N == 4) {//4������ ��� 
                    point<float, 4>* pt = new point<float, 4>(array);
                    return pt;
                }
                else if (N == 5) {//5������ ��� 
                    point<float, 5>* pt = new point<float, 5>(array);//point ������ ���� �����Ҵ� ���ְ�
                    return pt;
                }//�޸� ����(������) ���Ͼ�� �ϴ� ���
            }

        }
        else if (value == "rectangle") {//rectangle�� ��� 
            getline(ss, value, ',');
            if (value == "int") {   //int ��
                int array[4];
                int i = 0;
                while (getline(ss, value, ',')) {
                    array[i] = stoi(value);
                    i++;
                }

                rectangle<int>* rec_ = new rectangle<int>(array[0], array[1], array[2], array[3]);//ractangle ������ ���� �����Ҵ� ���ְ�
                return rec_;//�޸� ����(������) ���Ͼ�� �ϴ� ���
            }
            else if (value == "float") {    //float ��
                float array[4];
                int i = 0;
                while (getline(ss, value, ',')) {
                    array[i] = stof(value);
                    i++;
                }

                rectangle<float>* rec_ = new rectangle<float>(array[0], array[1], array[2], array[3]);//ractangle ������ ���� �����Ҵ� ���ְ�
                return rec_;//�޸� ����(������) ���Ͼ�� �ϴ� ���
            }
        }
        else throw;

        return 0;
    }
};

#endif //OOP_ASSN4_PARSER_H