//�ݽ�������������
//1.1 ��������
//ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
//������ʽ�����������ÿ��6���ˣ�ѡ��ÿ��Ҫ������飬���б���
//ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ��� 10001 ~10012
//��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
//��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
//�ڶ���Ϊ������ǰ����ʤ��
//ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ
//1.2 ������
//��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ���׶�
//�鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
//��ձ�����¼�����ļ����������
//�˳��������򣺿����˳���ǰ����
#include<iostream>
using namespace std;
#include"speechManager.h"
#include<ctime>
int main() {
	srand((unsigned int)time(NULL));
	//�������������
	SpeechManager sm;
	//for (map<int, Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++) {
	//	cout << "number of xuanshou:" << it->first << "	name of xuanshou:" << it->second.m_name
	//		<< "		score if xuanshou:" << it->second.m_score[0] << endl;
	//}
	int choice = 0;
	while (true) {
		sm.show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴���������¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.cleanRecord();
			break;
		case 0://�˳�ϵͳ
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




















