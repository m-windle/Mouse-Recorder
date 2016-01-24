#include <iostream>
#include <Windows.h>
#include "GenLList.h"
#include "GenDataNode.h"

using namespace std;

GenLList<POINT> recordMouse();
void playMouse(GenLList<POINT>);

int main(){
	cout << "Hello!\nPress <INSERT> when you want to begin recording";

	while (true){
		// Check if insert key is pressed to start recording
		if (GetAsyncKeyState(VK_INSERT)){
			GenLList<POINT> recList = recordMouse();

			// Playback on delete key pressed
			cout << "\nPress <DELETE> to play back\n";
			while (true){
				if(GetAsyncKeyState(VK_DELETE)){
					playMouse(recList);
					break;
				}
			}
		}
	}

	system("PAUSE");
	return 0;
}

GenLList<POINT> recordMouse(){
	POINT p; 
	GetCursorPos(&p);
	GenLList<POINT> locList = GenLList<POINT>(p);

	for (int i = 0; i < 1000; i++){
		if (GetCursorPos(&p)){
			locList.addNewNode(p);
		}

		Sleep(10);
	}

	return locList;
}

void playMouse(GenLList<POINT> locList){
	GenDataNode<POINT>* current = locList.getFirstNode();
	POINT pCurrent = current->getData();
	SetCursorPos(pCurrent.x, pCurrent.y);
	cout << pCurrent.x << pCurrent.y;

	while (current->getNextNode() != NULL){
		current = current->getNextNode();
		pCurrent = current->getData();

		SetCursorPos(pCurrent.x, pCurrent.y);

		cout << pCurrent.x << pCurrent.y;
		Sleep(10);
	}
}