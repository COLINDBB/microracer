
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "serial_com.h"
#include "shared_memory.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Created shared memory for joystick
	int n = 1000;
	char name[] = "smem_joystick"; 
	char *p;
	p = shared_memory(name,n);
	int *q;
	q = (int *)p;


	// Create Serial Communication variables //
	HANDLE h1; 
	open_serial("COM8", h1); //bluetooth is on com8
	char* buffer_out[64];
	char* buffer_in[64];
	bool proceed = true; //if communication with arduino is established this is set to 'true'
	char ch;

	//Create joystick chars to send
	unsigned char throttle; // 0-255
	char direction; // -128 to 127
	unsigned char horn; // 0 or 1


	// Start communication
	serial_send_char('y', h1);
	Sleep(5);
	serial_recv_char(ch, h1);
	if (ch == 'y'){
		proceed = true;
		cout << "Communication is working so far" << endl; 
	}
	else cout << "Start over plz" << endl;
	Sleep(1000);
	//Start sending data to 
	while (proceed){
	
		throttle = (unsigned char)(q[2] * 255.0/996 );
		horn = (unsigned char)q[3];
		direction = (char)(q[1] * 255.0 / 996);
		cout << (int)throttle << " \t " << int(direction) << endl;
		Sleep(100);



	}

	

	_getch();
	return 0;
}

