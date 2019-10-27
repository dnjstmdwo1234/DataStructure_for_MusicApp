#ifndef __Singer_Type__
#define __Singer_Type__


#include <iostream>
#include <string>
#include "MusicType.h"
#define MAXSIZE 1024
using namespace std;


class SingerType {
private: 
	string name;
	string birth_year_month_day;
	int mainGenre; 
	string PrimaryKey; // ���� �̸��� ��������� ���� ������ primary_key�� ����

public:
	SingerType() {
		name = "";
		string birth_year_month_day = "000000";
		int mainGenre = 0;
		PrimaryKey = name + birth_year_month_day;

	}
	~SingerType() {}
	void Display(); // ������ ������ ���
	void SetRecordFrKB(); // ������ ��� ������ Ű����� ���� �Է¹޴´�.
	void SetNameFrKB(); // ������ �̸��� Ű����� ���� �Է¹޴´�.
	void Setbirth_year_month_dayKB(); // ������ ��������� Ű����� ���� �Է¹޴´�.
	string GetPrimaryKey(); // primary_key ��ȯ

	bool operator < (SingerType& singer) {
		if (this->GetPrimaryKey() < singer.GetPrimaryKey()) {
			return true;
		}
		else
			false;
	}

	bool operator == (SingerType& singer) {
		if (this->GetPrimaryKey() == singer.GetPrimaryKey()) {
			return true;
		}
		else
			return false;
	}

	bool operator > (SingerType& singer) {
		if (this->GetPrimaryKey() > singer.GetPrimaryKey()) {
			return true;
		}
		else
			false;
	}
};


#endif