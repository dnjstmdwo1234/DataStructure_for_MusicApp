#include "Application.h"


Application::Application() {
	m_Command = 0;
}

Application::~Application() {

}

void Application::Run() // Application 실행
{
	while (1)
	{
		m_Command = GetCommand_main();

		switch (m_Command)
		{
		case 1:		// Song 기능 선택				
			SongData_edit(); break;
		case 2:		// Singer 기능선택					
			SingerData_edit(); break;
		case 3:		// PlayList 기능 선택			
			PlayListData_edit(); break;
		case 4:		// 실시간 TOP10 기능선택
			Top10_edit(); break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::Top10_edit() {
		m_Command = GetCommand_top10();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 top10에 입력에 추가
			Add_Top10(); break;
		case 2:		// 실시간 TOP10 MUSIC 현황을 출력					
			Top10_Display(); break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
}


void Application::SongData_edit() {
	m_Command = GetCommand_Song();

	switch (m_Command)
	{
	case 1:		// 곡 정보를 입력 받아 리스트에 추가					
		AddSong(); break;
	case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제					
		DeleteSong(); break;
	case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신	
		RetrieveSong(); break;
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

void Application::SingerData_edit() {
	m_Command = GetCommand_Singer();

	switch (m_Command)
	{
	case 1:		// 가수 정보를 입력 받아 리스트에 추가					
		AddSinger(); break;
	case 2:		// 가수의 고유번호를 입력 받아 리스트에서 삭제					
		DeleteSinger(); break;
	case 3:		// 가수 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			
		RetrieveSinger(); break;
	case 4:		// 가수가 등록한 모든 Music을 Display 
		ShowAllMusic_from_singer();
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

void Application::ShowAllMusic_from_singer() {
	SingerType data;
	MusicType music1;
	data.SetNameFrKB();
	data.Setbirth_year_month_dayKB(); // keyboard로 가수의 이름과 생년월일을 입력받는다. -> name+birth_year_month_day = primary_key
	MusicList.ResetList();
	for (int i = 0; i < MusicList.GetLength(); i++) {
		MusicList.GetNextItem(music1); 
		if (music1.GetPrimaryKey_Singer() == data.GetPrimaryKey()) { // Music database에서 동일한 primary_key를 가지는 곡을 출력한다.
			music1.Display();
		}
	}
}


void Application::PlayListData_edit() {
	m_Command = GetCommand_PlayList();

	switch (m_Command)
	{
	case 1:		// 곡 정보를 입력 받아 플레이리스트에 추가					
		AddToPlayList(); break;
	case 2:		// 곡을 플레이리스트에서 삭제					
		DeleteFrPlayList(); break;
	case 3:		// 플레이리스트에 있는 모든 곡을 1회 플레이		
		PlayAllMusic(); break;
	case 4:		// 플레이리스트에 있는 특정 곡을 1회 플레이
		PlayOneMusic();
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

int Application::GetCommand_Singer() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Add Singer" << endl;
	cout << "\t 2 : Delete Singer" << endl;
	cout << "\t 3 : Retrieve Singer" << endl;
	cout << "\t 4 : Display All Song with Singer" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int Application::GetCommand_top10() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Add_top10" << endl;
	cout << "\t 2 : Display TOP10" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int Application::GetCommand_Song() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Add Song" << endl;
	cout << "\t 2 : Delete Song" << endl;
	cout << "\t 3 : Retrieve Song" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int Application::GetCommand_PlayList() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Add PlayList" << endl;
	cout << "\t 2 : Delete PlayList" << endl;
	cout << "\t 3 : Play All Music" << endl;
	cout << "\t 4 : Play One Music" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int Application::GetCommand_main() {  // m_Command 값 반환
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 4 : top10 music challenge" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;
	
	return command;
}

int Application::AddSong() {
	MusicType music1;
	music1.SetRecordFromKB();
	
	if (MusicList.Get(music1) == 0) { // 기존에 등록된 가수인지 확인한 후 등록 되어있지 않으면 새로 추가한다.
		MusicList.Add(music1);
		cout << "기존에 데이터가 없습니다. 새로운 가수를 추가합니다." << endl;
		
		return 1;
	}
	else {
		cout << "기존에 데이터가 존재합니다." << endl;
		return 0;
	}
		
}

int Application::DeleteSong() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB();
	cout << music1.GetPrimaryKey() << endl;
	if (MusicList.Get(music1) == 1) { // 기존에 등록된 가수인지 확인한 후 등록 되어있지 않으면 새로 추가한다.
		MusicList.Delete(music1);
		cout << "기존에 데이터를 삭제했습니다." << endl;
		return 1;
	}
	else {
		cout << "기존에 데이터가 존재하지 않습니다." << endl;
		return 0;
	}
}

int Application::RetrieveSong() {
	MusicType data;
	data.SetNameFromKB();
	data.SetUpdateDayFrKB();
	cout << data.GetPrimaryKey() << endl;
	if (MusicList.Get(data)) {
		data.Display();
		return 1;
	}
	else {
		cout << "해당 곡을 찾지 못했습니다. " << endl;
		return 0;
	}
		
}


int Application::AddSinger() {
	SingerType singer1;
	singer1.SetRecordFrKB();

	if (SingerList.Get(singer1) == 0) { // 기존에 등록된 가수인지 확인한 후 등록 되어있지 않으면 새로 추가한다.
		SingerList.Add(singer1);
		cout << "기존에 데이터가 없습니다. 새로운 가수를 추가합니다." << endl;

		return 1;
	}
	else {
		cout << "기존에 데이터가 존재합니다." << endl;
		return 0;
	}

}

int Application::DeleteSinger() {
	SingerType singer1;
	singer1.SetNameFrKB();
	singer1.Setbirth_year_month_dayKB();
	cout << singer1.GetPrimaryKey() << endl;
	if (SingerList.Get(singer1) == 1) { // 기존에 등록된 가수인지 확인한 후 등록 되어있지 않으면 새로 추가한다.
		SingerList.Delete(singer1);
		cout << "기존에 데이터를 삭제했습니다." << endl;
		return 1;
	}
	else {
		cout << "기존에 데이터가 존재하지 않습니다." << endl;
		return 0;
	}
}

int Application::RetrieveSinger() {
	SingerType data;
	data.SetNameFrKB();
	data.Setbirth_year_month_dayKB();
	cout << data.GetPrimaryKey() << endl;
	if (SingerList.Get(data)) {
		data.Display();
		return 1;
	}
	else {
		cout << "해당 가수를 찾지 못했습니다. " << endl;
		return 0;
	}

}


int Application::Add_Top10() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); // Music 정보를 keybroad에서 입력받아 해당 곡의 자세한 정보를 MusicList에서 가져와 TOP10에 등록한다.
	if (MusicList.Get(music1)) {
		topmusicList.Add_new(music1); 
		return 1;
	}
	else {
		cout << "해당 Music을 찾지 못했습니다. " << endl;
		return 0;
	}
}

void Application::Top10_Display() {
	topmusicList.Display_top10(); // 실시간 top10 music을 출력한다.
}


int Application::AddToPlayList() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); // music을 키보드로 부터 입력받아 playlist에 추가한다.
	if (MusicList.Get(music1)) //0이 아니면(찾으면)
	{
		playList.EnQueue(music1);
		cout << "PlayList에 추가완료했습니다." << endl;
		return 1;
	}
	else {
		cout << "해당 곡을 찾을 수 없습니다. " << endl;
		return 0;	//실패(0)을 리턴
	}
	
}

void Application::PlayAllMusic() {
	MusicType data;
	playList.ResetPoint(); 
	while (playList.GetNextItem(data)) {
		if (MusicList.Get(data)) //0이 아니면(찾으면)
		{
			data.playmusicOneTime(); //playlist에 있는 모든 노래를 한번씩 플레이한다.
			topmusicList.Add_new(data); // 플레이 된 노래는 자동으로 top10 music에 add 심사를 한다.
			MusicList.Replace(data); 
		}
	}
}

void Application::PlayOneMusic() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); //music을 키보드로 부터 입력받는다.
	if (MusicList.Get(music1)) //0이 아니면(찾으면)
	{
		music1.playmusicOneTime(); //해당 music을 한번 플레이 한다.
		topmusicList.Add_new(music1); // 플레이된 music은 실시간 top10에 오를 수 있는지 심사한다.
		MusicList.Replace(music1);
	}
}

int Application::DeleteFrPlayList() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); //사용자로 부터 입력받아 해당 음악의 정보를 playlist에서 삭제한다.
	if (MusicList.Get(music1)) //0이 아니면(찾으면)
	{
		playList.DeQueue(music1);
		cout << "PlayList에서 제거완료했습니다." << endl;
		return 1;
	}
	else {
		cout << "해당 곡을 찾을 수 없습니다. " << endl;
		return 0;	//실패(0)을 리턴
	}
}