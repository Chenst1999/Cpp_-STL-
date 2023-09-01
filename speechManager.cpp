#include"speechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

void SpeechManager::speechDraw() {
	cout << "��<< " << this->m_index << " >>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ����ݽ�˳�����£�" << endl;
	if (this->m_index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << "  ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << "--------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest() {
	cout << "---------------��" << this->m_index << "�ֱ�����ʽ��ʼ---------------" << endl;
	multimap<double, int, greater<double>>groupScore;
	int num = 0;
	vector<int>v_src;
	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600)/10.f;
			//cout << score << "  ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//cout <<"num:"<<*it<<"	name:"<<this->m_speaker[*it].m_name<<"  avg:" << avg << endl;
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value��ѡ�ֱ��
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С���������:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "��ţ�" << it->second << "		������" << this->m_speaker[it->second].m_name 
					<< "		�ɼ���" << this->m_speaker[it->second].m_score[this->m_index-1] << endl;
			}
			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; count++,it++) {
				if (this->m_index == 1) {
					v2.push_back((*it).second);
				}
				else {
					vVictory.push_back(it->second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "---------------��" << this->m_index << "�ֱ������---------------" << endl;
	system("pause");
}

void SpeechManager::showScore() {
	cout << "---------------��" << this->m_index << "�ֽ���ѡ������---------------" << endl;
	vector<int>v;
	if (this->m_index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << *it << "		������" << this->m_speaker[*it].m_name 
			<< "		������" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_menu();
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
	//��ÿ��ѡ������д���ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	//����״̬��Ϊ��
	this->fileIsEmpty = false;
}

void SpeechManager::startSpeech() {
	//��һ��
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showScore();
	this->m_index++;
	//�ڶ���
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showScore();
	//4.����������ļ���
	this->saveRecord();
	//���ñ���������ȡ��¼
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ��Ż���
	string data;
	int index = 0;
	while (ifs >> data) {
		//cout << data << endl;
		int pos = -1;//�鵽����"��"λ�õı���
		int start = 0;
		vector<string>v;
		while(true){
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index,v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++) {
	//	cout << "��" << it->first + 1 << "��ھ���ţ�" << it->second[0] << "		������" << it->second[1] << endl;
	//}
}

void SpeechManager::showRecord() {
	if (fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "��" << i + 1 << "��"
				<< "�ھ���ţ�" << this->m_record[i][0] << "  �÷֣�" << this->m_record[i][1] << "		"
				<< "�Ǿ���ţ�" << this->m_record[i][2] << "  �÷֣�" << this->m_record[i][3] << "		"
				<< "������ţ�" << this->m_record[i][4] << "  �÷֣�" << this->m_record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::cleanRecord() {
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1.yes" << endl;
	cout << "2.no" << endl;
	int select=0;
	cin >> select;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++) {
			sp.m_score[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i+10001,sp));
	}
}

void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_speaker.clear();
	this->m_record.clear();
	this->m_index = 1;
}

void SpeechManager::show_menu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager() {

}