#pragma once
#include "GlobalSettings.h"

#include <iostream>
#include <Windows.h>

#include<MMSystem.h>
#pragma comment(lib, "Winmm.lib")

class GamepadController {
	IntVector2 vspeed;
	int speed;
	bool btn_A, btn_B, btn_X, btn_LB, btn_RB, btn_Start;
public:
	GamepadController();		// ���캯��
	void updateAllKey();			// ����ȫ����״̬
	void setSpeed(int dwPOV);		// �����ٶ�
	IntVector2 getVSpeed();
	bool getButton_A();
	bool getButton_B();
	bool getButton_X();
	bool getButton_LB();
	bool getButton_RB();
	int getSpeed();
};