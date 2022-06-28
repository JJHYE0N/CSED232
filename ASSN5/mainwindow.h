//“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //기본 생성자
    ~MainWindow();  //기본 소멸자
    void reset_data();  //단어 초기화 함수
private slots:
    void _my_timer();   //타이머 전용 함수
    void _my_game();    //단어 추가 함수
    void _wordmove();   //단어 움직이는 함수
    void on_my_input_returnPressed();   //입력창 전용 함수
    void _message(int n);   //메세지 출력 함수


private:
    Ui::MainWindow *ui;
    QTimer* m_time; //timer 변수
    QTimer* m_word; //단어 함수 호출 해주는 변수
    QString m_input;    //입력 호출 해주는 변수
    QTimer* m_score;    //점수 호출 해주는 변수
    QTimer* m_move; //단어 움직이게 해주는 변수
    std::shared_ptr<QLabel> m_label[6]; //단어 변수

    int _game=1;    //게임 진행 변수
    int _wordcount=0;   //단어 개수 변수
    int _wordexist[6]={ 0,};    //단어 존재여부 함수
    QString easy_words[30]= {"명징","직조", "갈증","비행기","나흗날","비둘기", "옹달샘", "줄이다", "거울", "집오리", "물리학", "토마토", "올리브", "은박지", "문지방", "물병", "양치질", "어린이", "집무실", "달빛", "다르다", "부고", "낫", "서당", "참외", "사다리", "천지", "인바디", "어금니", "추격"};
    QString crazy_words[10]= {"숨마쿰라우데", "우거지다", "토지소유권", "하염없다", "도톰하다", "넓적부리", "타란티노", "방울토마토", "객체지향수업", "컴퓨터공학과" };

};
#endif // MAINWINDOW_H
