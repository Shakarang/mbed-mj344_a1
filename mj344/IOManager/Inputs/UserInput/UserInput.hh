/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-04T12:48:55+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T19:16:39+00:00
*/

#ifndef MJ344_USERINPUT_HH_
#define MJ344_USERINPUT_HH_

#include "../../../../mbed-os/mbed.h"

class ServiceManager;

//typedef void (ServiceManager::*Callback)(const UserInput::Type);

class UserInput {

public:
	enum Type {
		FIRE, LEFT, RIGHT, UP, DOWN
	 };

public:
	UserInput(Callback<void(const UserInput::Type)>);//void (ServiceManager::*)(const UserInput::Type));
	~UserInput() {};

protected:
	//void	(ServiceManager::*inputCallback)(const UserInput::Type);
	Callback<void(const UserInput::Type)> inputCallback;
};

#endif /* !MJ344_USERINPUT_HH_ */
