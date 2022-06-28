//“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <string>
#include <QDebug>
#include <QRect>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    for (int i=0; i<6; i++) {
        int _move=rand()%730;   //x좌표 랜덤 생성
        m_label[i] = std::make_shared<QLabel>(this);    //동적할당
        m_label[i]->setText("");    //문자열 초기화
        m_label[i]->move(_move,45); //초기 위치로 이동
        _wordexist[i]=0;    //해당 인덱스의 단어 초기화
    }

    ui->setupUi(this);
    m_time=new QTimer(this);    //m_time에 해당하는 QTimer 선언
    connect(m_time, SIGNAL(timeout()), this, SLOT(_my_timer()));
    m_time->start(1000);    //1초마다 동작

    m_word=new QTimer(this);    //m_word에 해당하는 QTimer 선언
    connect(m_word, SIGNAL(timeout()), this, SLOT(_my_game()));
    m_word->start(1000);    //1초마다 동작

    m_move=new QTimer(this);    //m_move에 해당하는 QTimer 선언
    connect(m_move, SIGNAL(timeout()), this, SLOT(_wordmove()));
    m_move->start(1000);    //1초마다 동작
}

void MainWindow::_wordmove() {  //단어를 움직이는 역할
    if (_wordcount>0&&_game==1) {   //game은 게임이 진행중임을 나타내는 변수
        for(int i=0; i<6; i++) {    //6개의 단어를 각각 움직여준다.
            if(_wordexist[i]==1&&m_label[i]->text()!="") {
                m_label[i]->move(m_label[i]->x(),m_label[i]->y()+20);   //기본이동은 20
            }
            else if(_wordexist[i]==2&&m_label[i]->text()!="") {
                if (m_label[i]->y()<260)
                    m_label[i]->move(m_label[i]->x(),m_label[i]->y()+30);   //중앙 이전에는 빠르게 30(1.5배)으로 이동
                else
                    m_label[i]->move(m_label[i]->x(),m_label[i]->y()+20);   //기본이동은 20
            }
        }
    }
    //어려운 단어 박스는 창 중앙까지는 빠르게(기본 속도의 1.5배) 떨어지며, 중앙 이후로는 기본 단어 박스와 같은 속도로 떨어진다.

    for(int i=0; i<6; i++) {    //단어가 입력칸만큼 도달 시
        if (m_label[i]->y()>470&&_game==1) {
            m_label[i]->clear();    //문자열 초기화
            _wordexist[i]=0;    //존재하지 않는다는 배열
            ui->my_timer->display(ui->my_timer->intValue()-3);  //타이머의 시간을 3 감소 시킨다.
            if(ui->my_timer->intValue()<=0){    //timer가 0보다 작으면
                ui->my_timer->display(0);   //0을 출력해줌
                for(int j=0; j<6; j++) {    //단어들의 위치를 원래 위치로 되돌려줌
                    m_label[i]->move(m_label[i]->x(),45);
                }
            }
        }
    }
}

void MainWindow::_my_game() {   //단어를 생성해주는 함수
    if(_wordcount<6) {
        int _rand;  //랜덤 단어 생성을 위한 난수
        int _move;  //단어의 x 랜덤 위치 받는 변수
        _rand=rand()%10+1;  //1~10 까지 나눔
        if (_rand<9) {  //1~8일 경우 일반 단어
            for (int i=0; i<6; i++) {
                if(m_label[i]->text()=="") {
                    _rand=rand()%30;    //쉬운 단어는 30개
                    _move=rand()%730;   //x좌표 난수
                    m_label[i]->move(_move,45); //이동
                    m_label[i]->setText(easy_words[_rand]);
                    _wordexist[i]=1;    //존재함을 배열에 나타냄 1=쉬운 단어
                    break;
                }
            }
        }
        else {  //아닐 경우 어려운 단어
            _rand=rand()%10;    //어려운 단어는 10개
            for (int i=0; i<6; i++) {
                if(m_label[i]->text()=="") {
                    _rand=rand()%10;    //어려운 단어는 10개
                    _move=rand()%730;   //x좌표 난수
                    m_label[i]->move(_move,45); //이동
                    m_label[i]->setText(QString("<span style='color:#ff0000;'>%1</span>").arg(crazy_words[_rand])); //빨간 글씨
                    _wordexist[i]=2;    //존재함을 배열에 나타냄 2=어려운 단어
                    break;
                }
            }
        }
        _wordcount+=1;  //단어의 개수 증가
    }
}


void MainWindow::_my_timer() {
    if (ui->my_timer->intValue() > 0 && _game==1) { //게임중이고 타이머가 0보다 클경우
        ui->my_timer->display(ui->my_timer->intValue() -1); //시간 감소
    }
    else if (ui->my_timer->intValue() <= 0 && _game==1 ){   //게임중이고 타이머가 0보다 작을 경우
        for(int i=0; i<6; i++) {
            m_label[i]->setText("");    //모든 단어 초기화
        }
        _game=0;    //게임 중이지 않음
        _message(ui->my_score->intValue()); //메세지 호출
    }
    else {
        ui->my_timer->display(0);   //게임중이지 않을 경우 타이머는 0
    }
}

MainWindow::~MainWindow()   //기본 소멸자
{
    delete ui;
}


void MainWindow::on_my_input_returnPressed()    //입력창 눌렀을 경우
{
    m_input= ui->my_input->text();  //m_input에 문자열 저장
    QString s = QString("<span style='color:#ff0000;'>%1</span>").arg(m_input);//빨간색 입력도 만들어준다.
    int idx = -1;   //중복된 단어가 있을 때 먼저 입력된 단어 먼저 제거하기 위해 Idx를 만들어준다.
    int val = 0;    //10점과 15점을 주기 위해 선언
    for (int i=0; i<6; i++) {   //단어를 모두 검사한다.
        if(m_label[i]->text()==ui->my_input->text()||m_label[i]->text()==s) //만약 입력과 같은 단어가 있을 경우
        {
            if(_wordexist[i]==1&&idx!=i) {  //일반 단어의 경우
                val=10;
                if (idx==-1) idx=i; //첫 단어면 idx=i
                else if(m_label[idx]->y()<m_label[i]->y()) idx=i; //두번째 단어면 위치가 아래에 있는게 먼저 생성된거기 때문에 위치 비교후 idx 없데이트
            }
            else if (_wordexist[i]==2&&idx!=i){
                val=15;
                if (idx==-1) idx=i; //첫 단어면 idx=i
                else if(m_label[idx]->y()<m_label[i]->y()) idx=i;   //두번째 단어면 위치가 아래에 있는게 먼저 생성된거기 때문에 위치 비교후 idx 없데이트
            }
        }
    }
    if (idx>-1) {   //idx가 -1보다 크면, 단어가 존재한다는 의미 이므로
        ui->my_score->display(ui->my_score->intValue()+val);    //점수 업데이트
        _wordexist[idx]=0;  //단어 삭제
        _wordcount-=1;  //단어 수 줄이기
        m_label[idx]->setText("");  //초기화
        _my_game(); //단어 추가
    }
    ui->my_input->setText("");  //인풋 초기화
}

void MainWindow::reset_data()   //변수 초기화 하는 함수
{
    ui->my_timer->display(30);  //시간 30
    ui->my_score->display(0);   //점수 0
    _wordcount=0;   //단어수 0
    for (int i=0; i<6; i++) {   //모든 단어 초기화
        _wordexist[i]=0;    //단어 모두 존재하지 않음
        m_label[i]->setText("");    //단어 초기화
    }
    _game=1;    //게임 시작
}

void MainWindow::_message(int n)    //n은 스코어를 받는다.
{
    QString m;
    QString mm = QString::number(n);    //score받는 용
    m+="Your score is ";
    m+=mm;
    m+=".\nDo you want to try again?";
    QString title;  //타이틀 설정
    title="Time Out";
    QMessageBox::StandardButton reply = QMessageBox::question(this, title, m,QMessageBox::Yes|QMessageBox::No); //메세지 박스
    if (reply==QMessageBox::No) {
        QApplication::quit();   //다시 안할꺼면 끝내기
    }
    _game=1;    //게임을 안끝내면 다시 게임 실행시키는 함수 호출 및 변수 초기화
    reset_data();
}
