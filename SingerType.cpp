#include "SingerType.h"


void SingerType::SetRecordFrKB() { // ������ ��� ������ Ű����� ���� �Է¹޴´�.
	cout << "���� �̸��� �Է��ϼ���. : ";
	cin >> name;
	cout << "������ ��������� �Է��ϼ���. ex)975464";
	cin >> birth_year_month_day; 



	PrimaryKey = name + birth_year_month_day;// primary_key ������ ����Ǳ� ������ �����Ѵ�.
}

void SingerType::Display() { // ������ ������ ���
	cout << "���� �̸� : " << name << endl;
	cout << "������� : " << birth_year_month_day << endl;
}

void SingerType::SetNameFrKB() { // Ű����� ���� ������ �̸��� �Է¹޴´�.
	cout << "���� �̸��� �Է��ϼ���. : ";
	cin >> name;
	PrimaryKey = name + birth_year_month_day; // primary_key ������ ����Ǳ� ������ �����Ѵ�.
}

void SingerType::Setbirth_year_month_dayKB() { // Ű����� ���� ������ ��������� �Է¹޴´�.
	cout << "������ ��������� �Է��ϼ���. ex)975464";
	cin >> birth_year_month_day;
	PrimaryKey = name + birth_year_month_day; // primary_key ������ ����Ǳ� ������ �����Ѵ�.
}

string SingerType::GetPrimaryKey() { // primary�� ��ȯ�Ѵ�.
	return PrimaryKey;
}