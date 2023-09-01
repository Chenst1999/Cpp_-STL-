#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"speaker.h"
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
//����ݽ�����������
//����������
//-�ṩ�˵��������û�����
//-���ݽ��������̽��п���
//-���ļ��Ķ�д����
class SpeechManager {
public:
	//���캯��
	SpeechManager();

	//��ʼ���ݽ�����
	void initSpeech();

	//��������ѡ��
	void createSpeaker();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	map<int, vector<string>>m_record;

	//��ռ�¼
	void cleanRecord();

	//��ʾ�����¼
	void showRecord();

	//��ʾ�˵�
	void show_menu();

	//�Ƴ�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();

	//��Ա����
	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;
	map<int, Speaker>m_speaker;
	int m_index;
};