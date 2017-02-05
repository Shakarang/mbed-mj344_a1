/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T10:44:59+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T13:19:57+00:00
*/

#include "Light.hh"

Light::Light(const Light::Position position) {
	if (position == FRDM) {
		this->red = new DigitalOut(LED1);
		this->green = new DigitalOut(LED2);
		this->blue = new DigitalOut(LED3);
	} else {
		this->red = new DigitalOut(D5);
		this->green = new DigitalOut(D9);
		this->blue = new DigitalOut(D8);
	}
}

Light::~Light() {
	if (this->red != NULL) { delete this->red; }
	if (this->green != NULL) { delete this->green; }
	if (this->blue != NULL) { delete this->blue; }
}

void	Light::updateState(const Light::Color clr) {
	this->red->write(!((clr & ( 1 << 2 )) >> 2));
	this->green->write(!((clr & ( 1 << 1 )) >> 1));
	this->blue->write(!((clr & ( 1 << 0 )) >> 0));
}
