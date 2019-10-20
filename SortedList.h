#ifndef __SortedList_h__
#define __SortedList_h__


#define MAXSIZE 1024

template<typename T>
class SortedList {
private:
	T m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
public:
	SortedList();
	~SortedList();
	void MakeEmpty(); // List를 비운다.
	int GetLength(); // m_Length를 반환한다.
	bool IsFull(); // List가 현재 가득 찬 상태인지 알려준다.
	int Add(T data); // 새로운 data를 List에 추가한다.
	void ResetList(); // m_CurPointer를 처음으로 이동시킨다.
	int GetNextMusic(T& data); // 입력받은 data의 다음 data의 모든 정보를 반환한다.
	bool IsEmpty(); // List가 현재 비었는지 알려준다.
	int Get(T& data); // data를 찾아서 모든 정보를 출력
	int Delete(T& data); // data를 찾아서 삭제
	int Replace(T& data); // data를 찾아서 내용변경
	int Retrieve_SeqS(T& data); // data를 찾아서 해당 Music 정보 출력
	int Retrieve_Binary(T& data); // data를 binary search 방법으로 찾아서 해당 Music 정보 출력
	void Display();
};

template<typename T>
SortedList<T>::SortedList() {
	m_Length = 0;
	m_CurPointer = 0;
	ResetList();
}

template<typename T>
SortedList<T>::~SortedList() {

}

template<typename T>
void SortedList<T>::MakeEmpty() { // List를 비운다.
	m_Length = 0;
}

template<typename T>
int SortedList<T>::GetLength() { // m_Length를 반환한다.
	return m_Length;
}

template<typename T>
bool SortedList<T>::IsFull() { // List가 현재 가득 찬 상태인지 알려준다.
	if (m_Length == MAXSIZE) {
		return true;
	}
	return false;
}

template<typename T>
int SortedList<T>::Add(T inData) { // 새로운 data를 List에 추가한다.
	if (!IsFull())
	{
		T CurItem;
		ResetList();
		GetNextMusic(CurItem);

		while (m_CurPointer <= m_Length) {
			if (CurItem == inData) {
				cout << "이미 동일한 Primary_Key가 존재합니다. Add 명령을 취소합니다" << endl;
				return 0;
			}

			GetNextMusic(CurItem);
		}

		T CurItem_;
		ResetList();
		GetNextMusic(CurItem_);

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{

			if (CurItem_ == inData || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i - 1];	//배열 밀기

				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextMusic(CurItem_);	//다음아이템으로


		}
	}

	else
		return 0;

	return 1;
}

template<typename T>
void SortedList<T>::ResetList() {  // m_CurPointer를 처음으로 이동시킨다.
	//  Pre: 	List has been inititalized.
// Post:	Current position is prior to first element in list.

	m_CurPointer = -1;
}


template<typename T>
int SortedList<T>::GetNextMusic(T & data) { // 입력받은 data의 다음 data의 모든 정보를 반환한다.
	//  Pre: 	List has been initialized. Current position is defined.
//		Element at current position is not last in list.
// Post:	Current position is updated to next position.
// 		item is a copy of element at current position.

	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == m_Length)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

template<typename T>
bool  SortedList<T>::IsEmpty() { // List가 현재 비었는지 알려준다.
	if (m_Length == 0)
		return true;
	else
		return false;
}

template<typename T>
int SortedList<T>::Get(T & data) { // data를 찾아서 모든 정보를 출력
	//  Pre: 	Key member of item is initialized.
// Post:	If found, item’s key matches an element’s key in the list and a copy 
//	   of that element has been stored in item; otherwise, item is unchanged.
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i] == data) {
			m_Array[i].DisplayRecordOnScreen();
			return i;
		}
	}
	return -1;
}

template<typename T>
int SortedList<T>::Delete(T & data) { // data를 찾아서 삭제
	//  Pre: 	item’s key has been inititalized.
//		An element in the list has a key that matches item’s.
// Post:	No element in the list has a key that matches item’s.

	if (Retrieve_SeqS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;
}

template<typename T>
int SortedList<T>::Replace(T & data) { // data를 찾아서 내용변경
	//  Pre: 	item’s key has been inititalized.
//		An element in the list has a key that matches item’s.
	// Post:	No element in the list has a key that matches item’s.
	int location = 0;
	while (data != m_Array[location])
		location++;
	m_Array[location] = data;
	return 1;
}


template<typename T>
int SortedList<T>::Retrieve_Binary(T & data) {
	T CurItem;
	int num = m_Length / 2; // int형 변수 num 정의 초기값 list 길이의 절반

	m_CurPointer = num - 1;
	GetNextMusic(CurItem);	// list 중간의 아이템을 가져옴

	while (m_CurPointer < m_Length - 1 && m_CurPointer >= -1) // m_CurPointer 조건 설정
	{
		
		if (CurItem == data) {
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
		}
		else if(CurItem < data) {
			num = num / 2;  // num을 절반 크기로 줄임
			if (num == 0) { //num이 만약 0이라면 다음 값 반환
				GetNextMusic(CurItem);
				break;
			}
			else { // num이 0이 아니라면 m_CurPointer 을 num값만큼 오른쪽으로 이동

				m_CurPointer = m_CurPointer + num - 1;

				GetNextMusic(CurItem);

				break;
			}
		}
		else {
			num = num / 2;
			if (num == 0) {
				if (m_CurPointer < 1 && m_CurPointer > 0) {
					m_CurPointer = -1;
					GetNextMusic(CurItem);
					cout << 1 << endl;
					break;
				}
				else if (m_CurPointer == 0) {

					return 0;
				}
				else {
					m_CurPointer -= 2;
					GetNextMusic(CurItem);

					break;
				}

			}
			else {


				m_CurPointer = m_CurPointer - num - 1;

				GetNextMusic(CurItem);

				break;
			}
		}
	}
	return 0; //실패시0
}

template<typename T>
int SortedList<T>::Retrieve_SeqS(T & data) {
	T CurItem;

	ResetList();	//iterator 초기화
	GetNextMusic(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		if (CurItem == data) {
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;
		}
		else if (CurItem > data) {
			return 0;
		}
		else
			GetNextMusic(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
	}
	return 0; //실패시0
}

#endif