/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-04T12:48:55+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-04T14:13:28+00:00
*/

#ifndef MJ344_USERINPUT_HH_
#define MJ344_USERINPUT_HH_

#include "../../../mbed-os/mbed.h"

class UserInput {

public:
	enum Type {
		FIRE, LEFT, RIGHT, UP, DOWN
	 };

public:
	UserInput(void (*)(const UserInput::Type));
	~UserInput() {};



protected:
	void (*inputCallback)(const UserInput::Type);
};

#endif /* !MJ344_USERINPUT_HH_ */
