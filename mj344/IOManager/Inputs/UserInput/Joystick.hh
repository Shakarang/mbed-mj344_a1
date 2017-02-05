/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T11:47:53+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T13:14:30+00:00
*/

#ifndef MJ344_JOYSTICK_HH_
#define MJ344_JOYSTICK_HH_

#include "UserInput.hh"

class Joystick: public UserInput {

public:
	Joystick(void (*)(const UserInput::Type));
	~Joystick();

	void 		triggered();

private:
	InterruptIn *up;
	InterruptIn *down;
	InterruptIn *left;
	InterruptIn *right;
	InterruptIn *fire;

private:
	void 		upTriggered();
	void 		downTriggered();
	void 		leftTriggered();
	void 		rightTriggered();
	void 		fireTriggered();
};

#endif /* !MJ344_JOYSTICK_HH_ */
