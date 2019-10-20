#ifndef __unsortedlist__
#define __unsortedlist__

#include <iostream>
#define MAXSIZE 1024
using namespace std;

template<typename T>
class UnsortedList {
private:
	T m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;

public:
	UnsortedList() {
		m_Length = 0;
		ResetList();
	}

	~UnsortedList() {}
	
	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(T data);
	void ResetList();
	int GetNextMusic(T& data);
};

template <typename T>
void UnsortedList<T>::MakeEmpty() {
	m_Length = 0;
}

template <typename T>
int UnsortedList<T>::GetLength() {
	return m_Length;
}

template <typename T>
bool UnsortedList<T>::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


template<typename T>
int UnsortedList<T>::Add(T data) {
	if (!IsFull())
	{
		m_Array[m_Length] = data;
		m_Length++;
	}
	else
		return 0;

	return 1;
}

template <typename T>
void UnsortedList<T>::ResetList() {
	m_CurPointer = -1;
}


template<typename T>
int UnsortedList<T>::GetNextMusic(T& data) {
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}


#endif