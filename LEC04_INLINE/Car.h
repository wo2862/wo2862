#pragma once
#include <cstdio>
#include <cstring>

class Car {
protected:
	int speed;
	char name[40];
public:
	int gear;
	Car() {}
	~Car() {}
	Car(int s, const char* n, int g)
		: speed(s), gear(g) {
		strcpy_s(name, n);
	}
	void chngeGear(int g = 4) {
		gear = g;
	}
	void changeGear(int g = 4) {
		gear = g;
	}
	void speedUp() {
		speed += 5;
	}
	void display() {
		printf("[%s : 기어 =%d단 속도 = %dkmph\n", name, gear, speed);
	}
	void whereAmi() { printf("객체주소 = %x\n", this); }
};