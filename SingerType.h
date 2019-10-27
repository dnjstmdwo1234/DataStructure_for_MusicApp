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
	string PrimaryKey; // 가수 이름과 생년월일을 합한 정보를 primary_key로 저장

public:
	SingerType() {
		name = "";
		string birth_year_month_day = "000000";
		int mainGenre = 0;
		PrimaryKey = name + birth_year_month_day;

	}
	~SingerType() {}
	void Display(); // 가수의 정보를 출력
	void SetRecordFrKB(); // 가수의 모든 정보를 키보드로 부터 입력받는다.
	void SetNameFrKB(); // 가수의 이름을 키보드로 부터 입력받는다.
	void Setbirth_year_month_dayKB(); // 가수의 생년월일을 키보드로 부터 입력받는다.
	string GetPrimaryKey(); // primary_key 반환

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