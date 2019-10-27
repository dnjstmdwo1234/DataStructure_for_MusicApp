#include "SingerType.h"


void SingerType::SetRecordFrKB() { // 가수의 모든 정보를 키보드로 부터 입력받는다.
	cout << "가수 이름을 입력하세요. : ";
	cin >> name;
	cout << "가수의 생년월일을 입력하세요. ex)975464";
	cin >> birth_year_month_day; 



	PrimaryKey = name + birth_year_month_day;// primary_key 정보도 변경되기 떄문에 수정한다.
}

void SingerType::Display() { // 가수의 정보를 출력
	cout << "가수 이름 : " << name << endl;
	cout << "생년월일 : " << birth_year_month_day << endl;
}

void SingerType::SetNameFrKB() { // 키보드로 부터 가수의 이름을 입력받는다.
	cout << "가수 이름을 입력하세요. : ";
	cin >> name;
	PrimaryKey = name + birth_year_month_day; // primary_key 정보도 변경되기 떄문에 수정한다.
}

void SingerType::Setbirth_year_month_dayKB() { // 키보드로 부터 가수의 생년월일을 입력받는다.
	cout << "가수의 생년월일을 입력하세요. ex)975464";
	cin >> birth_year_month_day;
	PrimaryKey = name + birth_year_month_day; // primary_key 정보도 변경되기 떄문에 수정한다.
}

string SingerType::GetPrimaryKey() { // primary를 반환한다.
	return PrimaryKey;
}