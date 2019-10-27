#ifndef _MusicType_
#define _MusicType_

#include <iostream>
#include <fstream>
#include <string>
# define FILESIZE 1024
using namespace std;


class MusicType {
private:
	string Name;
	string Singer;
	string Singer_birth;
	string update_day;
	int Genre; 
	string PrimaryKey_for_seperate_song; // Music 개개인을 구별하기 위한 primary_key -> 별도의 입력없이 곡명과 업데이트 날짜를 더한 string으로 자동배정된다.
	string PrimaryKey_for_Singer; // Music을 가수별로 묶기 위한 primary_key -> 가수명과 가수의 생년월일 정보를 더한 string으로 자동배정한다.
	int playTime;
public:
	MusicType() {
		Name = "";
		update_day = "000000";
		Genre = 0;
		playTime = 0;
		PrimaryKey_for_seperate_song = Name + update_day;
		PrimaryKey_for_Singer = Singer + Singer_birth;
	};
	~MusicType() {

	}
	void playmusicOneTime(); // 음악을 한번 재생한다.
	void SetUpdateDayFrKB(); // 업데이트 데이를 키보드로 입력받는다.
	void Display(); // Music 정보를 표시
	string GetPrimaryKey_Singer(); // 가수 구분을 위한 primary_key를 return 한다.
	string GetName(); // 이름을 반환한다.
	int GetGenre(); // 장르를 반환한다.
	string GetSinger(); // 가수를 반환한다.
	string GetPrimaryKey(); // Music 각각의 구별을 위한 primary_key를 반환한다.
	void SetRecordFromKB(); // Music의 모든 정보를 kb로 입력받는다.
	void SetNameFromKB(); // Music의 이름을 키보드로 부터 입력받는다.
	int GetPlayTime() { // play횟수를 return 한다.
		return playTime;
	}

	bool operator < (MusicType& music) {
		if (this->GetPlayTime() < music.GetPlayTime()) {
			return true;
		}
		else
			false;
	}

	bool operator == (const MusicType& music) {
		if (this->PrimaryKey_for_seperate_song == music.PrimaryKey_for_seperate_song) {
			return true;
		}
		else
			return false;
	}

	bool operator > (MusicType& music) {
		if (this->GetPlayTime() > music.GetPlayTime()) {
			return true;
		}
		else
			false;
	}
	

};

#endif

