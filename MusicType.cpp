#include "MusicType.h"
#include <iostream>
using namespace std;
void MusicType::playmusicOneTime() { // �÷��� Ÿ�� 1����
	cout << "������ 1�� �÷��� �մϴ�." << endl;
	playTime++;
}
void MusicType::Display() { // ���, �����̸�, ������Ʈ ��¥�� ����Ѵ�.
	cout << Name << " " << Singer << " " << update_day << endl;
}
int MusicType::GetGenre() { // �帣�� ��ȯ�Ѵ�.
	return Genre;
}
void MusicType::SetUpdateDayFrKB() { // ������Ʈ ��¥�� �����Ѵ�.
	cout << "������Ʈ ��¥�� �Է��ϼ���. ex)970218  ";
	cin >> update_day;

	PrimaryKey_for_seperate_song = Name + update_day; // primary_key�� ����Ǳ� ������ �Լ������� �������ش�.
}
string MusicType::GetName() { // ����� ��ȯ�Ѵ�.
	return Name; 
}

string MusicType::GetSinger() { // �������� ��ȯ�Ѵ�.
	return Singer;
}

string MusicType::GetPrimaryKey() { // Music ������ �����ϴ� primary_key�� ��ȯ�Ѵ�.
	return PrimaryKey_for_seperate_song;
}
string MusicType::GetPrimaryKey_Singer() { // �������� �����Ǵ� primary_key�� ��ȯ�Ѵ�.
	return PrimaryKey_for_Singer;
}
void MusicType::SetRecordFromKB() { // Music�� ��� ������ Ű����� ���� �Է¹޴´�.
	cout << "����� �Է��ϼ���. : ";
	cin >> Name;
	cout << "�������� �Է��ϼ���. : ";
	cin >> Singer;
	cout << "���� ��������� �Է��ϼ���. : ex)970515 ";
	cin >> Singer_birth;
	cout << "���� ������Ʈ ��¥�� �Է��ϼ���. : ";
	cin >> update_day;
	cout << "���� �帣�� �Է��ϼ���. : ex) Ŭ���� 1�� �߶�� 2�� ���� 3��  ";
	cin >> Genre;
	playTime = 0;

	PrimaryKey_for_seperate_song = Name + update_day; // primary_key �����鵵 ����Ǳ� ������ �Լ� �������� ������ �ش�.

	PrimaryKey_for_Singer = Singer + Singer_birth;
}

void MusicType::SetNameFromKB() { // �̸��� Ű����� ���� �Է¹޴´�.
	cout << "������ �̸��� �Է����ּ���. : ";
	cin >> Name;
	PrimaryKey_for_seperate_song = Name + update_day;
}

