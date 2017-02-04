/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-04T12:40:57+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-04T15:25:38+00:00
*/

#include "Switch.hh"

Switch::Switch(const PinName &pn, void (*fptr)(const UserInput::Type)): UserInput(fptr) {
	this->button = new InterruptIn(pn);
	this->button->fall(callback(this, &Switch::triggered));
}

Switch::~Switch() {
	if (this->button != NULL) {
		delete this->button;
	}
}

void	Switch::triggered() {
	this->inputCallback(FIRE);
}
