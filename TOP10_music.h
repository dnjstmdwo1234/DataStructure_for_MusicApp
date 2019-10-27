#ifndef __top10_music__
#define __top10_music__

#include <iostream>
#include "SortedList.h"
#include "MusicType.h"
#define maxTop10 10
using namespace std;

class TOPMUSIC { // �ǽð� top10 music�� �����ϴ� class
private:
	SortedList<MusicType> top10music; // �迭�� �̿��� sortedlist�� �����Ѵ�.

public:
	int Add_new(MusicType newMusic) { // ���ο� music�� top10�� �߰��Ѵ�.
		if (top10music.IsFull()) { // top10 music�� ��ã�� ��� ������ top10 music�� �÷��� Ƚ���� ���Ѵ�.
			MusicType data;
			int num = 0;
			top10music.ResetList();
			while (top10music.GetNextMusic(data) != -1) {
				num++;
				if (data < newMusic) { //�̹� sortedlist�� playtime�� ���� ������� ��ġ�� �Ǿ� �ִ�.
					top10music.Delete(data); // ���� ������ ���� �ϳ��� ���ؼ� ���� ���ο� ���Ǻ��� ������ �ش� �����͸� �����Ѵ�.
					top10music.Add(newMusic); // ���ο� �����͸� top10music sortedlist�� �߰�
					cout << "���ο� Music�� �ǽð� Top10�� �߰��߽��ϴ�." << endl;
					return 1; //return �� ��ȯ �� �Լ� ����
				}
				if (num == top10music.GetLength() - 1) { // ���� ������ search�� �Ϸ�Ǹ� ������ top10music�� playtime�� �� ū������ �Ǵ��Ѵ�.
					cout << "���ο� Music�� ������ ���Ƽ� �߰��� �� �����ϴ�." << endl;
					return 0;
				}
			}
		}

		else { // top10music�� �� ���� �ʾ��� ��쿡�� �ٷ� top10music�� ���ο� �����͸� �߰��Ѵ�.
			top10music.Add(newMusic);
			cout << "���ο� Music�� �ǽð� Top10�� �߰��߽��ϴ�." << endl;
			return 1;
		}
	}
			
	void Display_top10() { // ���� top10music�� ��� ���� ����Ѵ�.
		int num = 1;
		top10music.ResetList();
		MusicType data;
		while (top10music.GetNextMusic(data) != -1) {
			cout << num << "�� : " << data.GetName() << endl; // ex) 1�� : ������
			num++;
		}
	}
	
};




#endif