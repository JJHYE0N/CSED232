#ifndef OOP_ASSN4_POINT_H
#define OOP_ASSN4_POINT_H
#include "geometry.h"
#include "canvas2d.h"

template <typename T, int N>
class point : public geometry {
    //포인트 class로 T는 사용될 numeric type, N은 coordinate dimension을 의미한다
    // 예로, N이 2면 2차원 point, 3이면 3차원 point가 된다.
private:
    T array[N];//템플릿형 배열을 선언한다.

public:
    point<T, N>(const T* coords) {
        for (int i = 0; i < N; i++) {//array[i]=coords[i]로 초기화 시켜준다.
            array[i] = coords[i];
        }
    }
    //point<T, int N>(const T* coords)
    //point class의 생성자이며 N개의 T값으로 초기화 된다.

    void draw2canvas(float**& table, int w, int h) { //다시보기
        float sum = 0;
        if (N == 2) table[(int) array[1]][(int) array[0]] += 1;
        else if (N > 2) {//3차원 이상의 경우에 뒤에오는 정수를 더해 해당 좌표에 값을 더해준다.
            for (int i = 2; i < N; i++) {
                sum += array[i];
            }
            int i_x = (int)array[0] ;//문자로 되어있는 것을 int로 바꿔준다.
            int i_y = (int)array[1];//문자로 되어있는 것을 int로 바꿔준다.
  
            if (sum == 0) table[i_y][i_x] += 1; //합이 0일 경우 1씩만 더해준다.
            else {
                table[i_y][i_x] += (int) sum;   //해당하는 좌표에 sum값을 더해준다.
            }
            return;
        }
    }
};

#endif //OOP_ASSN4_POINT_H