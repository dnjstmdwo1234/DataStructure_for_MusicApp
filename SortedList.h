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
	void MakeEmpty(); // List�� ����.
	int GetLength(); // m_Length�� ��ȯ�Ѵ�.
	bool IsFull(); // List�� ���� ���� �� �������� �˷��ش�.
	int Add(T data); // ���ο� data�� List�� �߰��Ѵ�.
	void ResetList(); // m_CurPointer�� ó������ �̵���Ų��.
	int GetNextMusic(T& data); // �Է¹��� data�� ���� data�� ��� ������ ��ȯ�Ѵ�.
	bool IsEmpty(); // List�� ���� ������� �˷��ش�.
	int Get(T& data); // data�� ã�Ƽ� ��� ������ ���
	int Delete(T& data); // data�� ã�Ƽ� ����
	int Replace(T& data); // data�� ã�Ƽ� ���뺯��
	int Retrieve_SeqS(T& data); // data�� ã�Ƽ� �ش� Music ���� ���
	int Retrieve_Binary(T& data); // data�� binary search ������� ã�Ƽ� �ش� Music ���� ���
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
void SortedList<T>::MakeEmpty() { // List�� ����.
	m_Length = 0;
}

template<typename T>
int SortedList<T>::GetLength() { // m_Length�� ��ȯ�Ѵ�.
	return m_Length;
}

template<typename T>
bool SortedList<T>::IsFull() { // List�� ���� ���� �� �������� �˷��ش�.
	if (m_Length == MAXSIZE) {
		return true;
	}
	return false;
}

template<typename T>
int SortedList<T>::Add(T inData) { // ���ο� data�� List�� �߰��Ѵ�.
	if (!IsFull())
	{
		T CurItem;
		ResetList();
		GetNextMusic(CurItem);

		while (m_CurPointer <= m_Length) {
			if (CurItem == inData) {
				cout << "�̹� ������ Primary_Key�� �����մϴ�. Add ����� ����մϴ�" << endl;
				return 0;
			}

			GetNextMusic(CurItem);
		}

		T CurItem_;
		ResetList();
		GetNextMusic(CurItem_);

		while (m_CurPointer <= m_Length) //ó������ ������
		{

			if (CurItem_ == inData || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�

				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextMusic(CurItem_);	//��������������


		}
	}

	else
		return 0;

	return 1;
}

template<typename T>
void SortedList<T>::ResetList() {  // m_CurPointer�� ó������ �̵���Ų��.
	//  Pre: 	List has been inititalized.
// Post:	Current position is prior to first element in list.

	m_CurPointer = -1;
}


template<typename T>
int SortedList<T>::GetNextMusic(T & data) { // �Է¹��� data�� ���� data�� ��� ������ ��ȯ�Ѵ�.
	//  Pre: 	List has been initialized. Current position is defined.
//		Element at current position is not last in list.
// Post:	Current position is updated to next position.
// 		item is a copy of element at current position.

	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == m_Length)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

template<typename T>
bool  SortedList<T>::IsEmpty() { // List�� ���� ������� �˷��ش�.
	if (m_Length == 0)
		return true;
	else
		return false;
}

template<typename T>
int SortedList<T>::Get(T & data) { // data�� ã�Ƽ� ��� ������ ���
	//  Pre: 	Key member of item is initialized.
// Post:	If found, item��s key matches an element��s key in the list and a copy 
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
int SortedList<T>::Delete(T & data) { // data�� ã�Ƽ� ����
	//  Pre: 	item��s key has been inititalized.
//		An element in the list has a key that matches item��s.
// Post:	No element in the list has a key that matches item��s.

	if (Retrieve_SeqS(data))	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;
}

template<typename T>
int SortedList<T>::Replace(T & data) { // data�� ã�Ƽ� ���뺯��
	//  Pre: 	item��s key has been inititalized.
//		An element in the list has a key that matches item��s.
	// Post:	No element in the list has a key that matches item��s.
	int location = 0;
	while (data != m_Array[location])
		location++;
	m_Array[location] = data;
	return 1;
}


template<typename T>
int SortedList<T>::Retrieve_Binary(T & data) {
	T CurItem;
	int num = m_Length / 2; // int�� ���� num ���� �ʱⰪ list ������ ����

	m_CurPointer = num - 1;
	GetNextMusic(CurItem);	// list �߰��� �������� ������

	while (m_CurPointer < m_Length - 1 && m_CurPointer >= -1) // m_CurPointer ���� ����
	{
		
		if (CurItem == data) {
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
		}
		else if(CurItem < data) {
			num = num / 2;  // num�� ���� ũ��� ����
			if (num == 0) { //num�� ���� 0�̶�� ���� �� ��ȯ
				GetNextMusic(CurItem);
				break;
			}
			else { // num�� 0�� �ƴ϶�� m_CurPointer �� num����ŭ ���������� �̵�

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
	return 0; //���н�0
}

template<typename T>
int SortedList<T>::Retrieve_SeqS(T & data) {
	T CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextMusic(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		if (CurItem == data) {
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;
		}
		else if (CurItem > data) {
			return 0;
		}
		else
			GetNextMusic(CurItem);	//���� �������� �����´�.(��� Ž��)
	}
	return 0; //���н�0
}

#endif