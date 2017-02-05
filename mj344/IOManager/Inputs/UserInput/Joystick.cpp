/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T12:11:22+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T19:07:08+00:00
*/

#include "Joystick.hh"

Joystick::Joystick(Callback<void(const UserInput::Type)> fptr): UserInput(fptr) {
	this->up = new InterruptIn(A2);
	this->down = new InterruptIn(A3);
	this->left = new InterruptIn(A4);
	this->right = new InterruptIn(A5);
	this->fire = new InterruptIn(D4);

	this->up->rise(callback(this, &Joystick::upTriggered));
	this->down->rise(callback(this, &Joystick::downTriggered));
	this->left->rise(callback(this, &Joystick::leftTriggered));
	this->right->rise(callback(this, &Joystick::rightTriggered));
	this->fire->rise(callback(this, &Joystick::fireTriggered));
}

Joystick::~Joystick() {
	if (this->up != NULL) { delete this->up; }
	if (this->down != NULL) { delete this->down; }
	if (this->left != NULL) { delete this->left; }
	if (this->right != NULL) { delete this->right; }
	if (this->fire != NULL) { delete this->fire; }
}

void	Joystick::upTriggered() {
	this->inputCallback(UP);
}

void	Joystick::downTriggered() {
	this->inputCallback(DOWN);
}

void	Joystick::leftTriggered() {
	this->inputCallback(LEFT);
}

void	Joystick::rightTriggered() {
	this->inputCallback(RIGHT);
}

void	Joystick::fireTriggered() {
	this->inputCallback(FIRE);
}
