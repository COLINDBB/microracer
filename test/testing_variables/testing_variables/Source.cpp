#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main(){

	int throttle_int = 1;
	int steer_int = 127;
	char steer_char = char(steer_int);
	unsigned char throttle_char = (char)throttle_int;
	
	cout << "Throttle as int: " << throttle_int << ", and throttle as char: " << (int)throttle_char << endl;
	cout << "Steer as int: " << steer_int << ", and steer as char: " << (int)steer_char << endl;
	_getch();


}