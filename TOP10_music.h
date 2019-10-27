#ifndef __top10_music__
#define __top10_music__

#include <iostream>
#include "SortedList.h"
#include "MusicType.h"
#define maxTop10 10
using namespace std;

class TOPMUSIC { // 실시간 top10 music을 관리하는 class
private:
	SortedList<MusicType> top10music; // 배열을 이용한 sortedlist로 선언한다.

public:
	int Add_new(MusicType newMusic) { // 새로운 music을 top10에 추가한다.
		if (top10music.IsFull()) { // top10 music이 꽉찾을 경우 기존의 top10 music의 플레이 횟수와 비교한다.
			MusicType data;
			int num = 0;
			top10music.ResetList();
			while (top10music.GetNextMusic(data) != -1) {
				num++;
				if (data < newMusic) { //이미 sortedlist로 playtime이 적은 순서대로 배치가 되어 있다.
					top10music.Delete(data); // 작은 데이터 부터 하나씩 비교해서 만약 새로운 음악보다 작으면 해당 데이터를 삭제한다.
					top10music.Add(newMusic); // 새로운 데이터를 top10music sortedlist에 추가
					cout << "새로운 Music을 실시간 Top10에 추가했습니다." << endl;
					return 1; //return 값 반환 후 함수 종료
				}
				if (num == top10music.GetLength() - 1) { // 기존 데이터 search가 완료되면 기존의 top10music의 playtime이 더 큰것으로 판단한다.
					cout << "새로운 Music의 점수가 낮아서 추가할 수 없습니다." << endl;
					return 0;
				}
			}
		}

		else { // top10music이 꽉 차지 않았을 경우에는 바로 top10music에 새로운 데이터를 추가한다.
			top10music.Add(newMusic);
			cout << "새로운 Music을 실시간 Top10에 추가했습니다." << endl;
			return 1;
		}
	}
			
	void Display_top10() { // 현재 top10music의 모든 곡을 출력한다.
		int num = 1;
		top10music.ResetList();
		MusicType data;
		while (top10music.GetNextMusic(data) != -1) {
			cout << num << "위 : " << data.GetName() << endl; // ex) 1위 : ㅁㅁㅁ
			num++;
		}
	}
	
};




#endif