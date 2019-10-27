#include "MusicType.h"
#include <iostream>
using namespace std;
void MusicType::playmusicOneTime() { // 플레이 타임 1증가
	cout << "음악을 1번 플레이 합니다." << endl;
	playTime++;
}
void MusicType::Display() { // 곡명, 가수이름, 업데이트 날짜를 출력한다.
	cout << Name << " " << Singer << " " << update_day << endl;
}
int MusicType::GetGenre() { // 장르를 반환한다.
	return Genre;
}
void MusicType::SetUpdateDayFrKB() { // 업데이트 날짜를 수정한다.
	cout << "업데이트 날짜를 입력하세요. ex)970218  ";
	cin >> update_day;

	PrimaryKey_for_seperate_song = Name + update_day; // primary_key도 변경되기 때문에 함수내에서 수정해준다.
}
string MusicType::GetName() { // 곡명을 반환한다.
	return Name; 
}

string MusicType::GetSinger() { // 가수명을 반환한다.
	return Singer;
}

string MusicType::GetPrimaryKey() { // Music 각각을 구별하는 primary_key를 반환한다.
	return PrimaryKey_for_seperate_song;
}
string MusicType::GetPrimaryKey_Singer() { // 가수별로 구별되는 primary_key를 반환한다.
	return PrimaryKey_for_Singer;
}
void MusicType::SetRecordFromKB() { // Music의 모든 정보를 키보드로 부터 입력받는다.
	cout << "곡명을 입력하세요. : ";
	cin >> Name;
	cout << "가수명을 입력하세요. : ";
	cin >> Singer;
	cout << "가수 생년월일을 입력하세요. : ex)970515 ";
	cin >> Singer_birth;
	cout << "곡의 업데이트 날짜를 입력하세요. : ";
	cin >> update_day;
	cout << "곡의 장르를 입력하세요. : ex) 클래식 1번 발라드 2번 가요 3번  ";
	cin >> Genre;
	playTime = 0;

	PrimaryKey_for_seperate_song = Name + update_day; // primary_key 정보들도 변경되기 때문에 함수 마지막에 변경해 준다.

	PrimaryKey_for_Singer = Singer + Singer_birth;
}

void MusicType::SetNameFromKB() { // 이름을 키보드로 부터 입력받는다.
	cout << "음악의 이름을 입력해주세요. : ";
	cin >> Name;
	PrimaryKey_for_seperate_song = Name + update_day;
}

