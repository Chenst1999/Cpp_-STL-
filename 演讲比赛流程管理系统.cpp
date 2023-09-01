//演讲比赛程序需求
//1.1 比赛规则
//学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
//比赛方式：分组比赛，每组6个人；选手每次要随机分组，进行比赛
//每名选手都有对应的编号，如 10001 ~10012
//第一轮分为两个小组，每组6个人。 整体按照选手编号进行抽签后顺序演讲。
//当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
//第二轮为决赛，前三名胜出
//每轮比赛过后需要显示晋级选手的信息
//1.2 程序功能
//开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
//查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
//清空比赛记录：将文件中数据清空
//退出比赛程序：可以退出当前程序
#include<iostream>
using namespace std;
#include"speechManager.h"
#include<ctime>
int main() {
	srand((unsigned int)time(NULL));
	//创建管理类对象
	SpeechManager sm;
	//for (map<int, Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++) {
	//	cout << "number of xuanshou:" << it->first << "	name of xuanshou:" << it->second.m_name
	//		<< "		score if xuanshou:" << it->second.m_score[0] << endl;
	//}
	int choice = 0;
	while (true) {
		sm.show_menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看往届比赛记录
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.cleanRecord();
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}




















