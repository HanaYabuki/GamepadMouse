#include "GamepadController.h"

GamepadController::GamepadController() {
	vspeed.vx = 0; vspeed.vy = 0;
	speed = 3 * SPEED_LEVEL;
	btn_A = false;
	btn_B = false;
	btn_X = false;
	btn_LB = false;
	btn_RB = false;
	btn_Start = false;
}

void GamepadController::updateAllKey() {
	JOYINFOEX joyinfoex;
	joyinfoex.dwSize = sizeof(JOYINFOEX);
	joyinfoex.dwFlags = JOY_RETURNALL;
	//��ȡ�ֱ���Ϣ
	if (joyGetNumDevs() >= 1) {
		MMRESULT joyreturn = joyGetPosEx(JOYSTICKID1, &joyinfoex);
		if (joyreturn == JOYERR_NOERROR) {

			vspeed.vx = ((double)(joyinfoex.dwXpos) - 32767) / (double)(32767 / speed);
			vspeed.vy = ((double)(joyinfoex.dwYpos) - 32767) / (double)(32767 / speed);
			btn_A = (joyinfoex.dwButtons & 1) == 1;
			btn_B = ((joyinfoex.dwButtons >> 1) & 1) == 1;
			btn_X = ((joyinfoex.dwButtons >> 2) & 1) == 1;
			btn_LB = ((joyinfoex.dwButtons >> 4) & 1) == 1;
			btn_RB = ((joyinfoex.dwButtons >> 5) & 1) == 1;
			btn_Start = ((joyinfoex.dwButtons >> 7) & 1) == 1;
			setSpeed(joyinfoex.dwPOV);

			if (btn_Start) {
				system("cls");

				std::cout << "--�ֱ�������Ϣ--" << std::endl;

				std::cout << "L-Con" << std::endl;
				std::cout << "X���� : " << joyinfoex.dwXpos << std::endl;
				std::cout << "Y���� : " << joyinfoex.dwYpos << std::endl;

				std::cout << "R-Con" << std::endl;
				std::cout << "X����: " << joyinfoex.dwUpos << std::endl;
				std::cout << "Y���� : " << joyinfoex.dwRpos << std::endl;

				std::cout << "LT - RT : " << joyinfoex.dwZpos << std::endl;
				std::cout << "D-pad ��Ϣ : " << joyinfoex.dwPOV << std::endl;
				std::cout << "������Ϣ : " << joyinfoex.dwButtons << std::endl;
				std::cout << "�������� : " << joyinfoex.dwButtonNumber << std::endl;
				std::cout << std::endl;

				std::cout << "--���ģ����Ϣ--" << std::endl;
				std::cout << "\033[33m����λ�ƣ�" << vspeed.vx << "   ����λ��: " << vspeed.vy << std::endl;
				std::cout << "�ٶ�: " << speed << std::endl;
				std::cout << "\033[32mA��-���: " << btn_A << std::endl;
				std::cout << "\033[31mB��-�Ҽ�: " << btn_B << std::endl;
				std::cout << "\033[1m\033[34mX��-�м�: " << btn_X << std::endl;
				std::cout << "\033[37mLB��-�����Ϲ�: " << btn_LB << std::endl;
				std::cout << "RB��-�����¹�: " << btn_RB << std::endl;
				std::cout << "Start��-���¿���̨: " << btn_Start << std::endl;
			}
		}
		else {
			switch (joyreturn) {
			case JOYERR_PARMS:
				std::cout << "�������" << std::endl; break;
			case JOYERR_NOCANDO:
				std::cout << "����δ���" << std::endl; break;
			case JOYERR_UNPLUGGED:
				std::cout << "δ�ҵ��ֱ�" << std::endl; break;
			default:
				std::cout << "δ֪����" << std::endl; break;;
			}
		}
	}
}

void GamepadController::setSpeed(int dwPOV) {
	if (dwPOV != 65535) {
		speed = dwPOV * SPEED_LEVEL / 9000 + SPEED_LEVEL;
	}
}

// I NEED LOMBOK

IntVector2 GamepadController::getVSpeed() {
	return vspeed;
}

bool GamepadController::getButton_A() {
	return btn_A;
}

bool GamepadController::getButton_B() {
	return btn_B;
}

bool GamepadController::getButton_X() {
	return btn_X;
}

bool GamepadController::getButton_LB() {
	return btn_LB;
}

bool GamepadController::getButton_RB() {
	return btn_RB;
}

int GamepadController::getSpeed() {
	return speed;
}