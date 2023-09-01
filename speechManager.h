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
//设计演讲比赛管理类
//功能描述：
//-提供菜单界面与用户交互
//-对演讲比赛流程进行控制
//-与文件的读写交互
class SpeechManager {
public:
	//构造函数
	SpeechManager();

	//初始化演讲比赛
	void initSpeech();

	//创建比赛选手
	void createSpeaker();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;
	map<int, vector<string>>m_record;

	//清空记录
	void cleanRecord();

	//显示往届记录
	void showRecord();

	//显示菜单
	void show_menu();

	//推出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//成员属性
	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;
	map<int, Speaker>m_speaker;
	int m_index;
};