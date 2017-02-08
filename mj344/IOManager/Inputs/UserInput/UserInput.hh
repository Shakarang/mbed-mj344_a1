/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-04T12:48:55+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T15:53:27+00:00
*/

#ifndef MJ344_USERINPUT_HH_
#define MJ344_USERINPUT_HH_

#include "mbed.h"

/**
 * UserInput class helps managing the different inputs which ara not analogic.
 */
class UserInput {

public:
	/**
	 * Type of the input
	 */
	enum Type {
		FIRE, LEFT, RIGHT, UP, DOWN
	 };

public:
	/**
	 * Constructor taking event callback in parameters.
	 */
	UserInput(Callback<void(const UserInput::Type)>);
	~UserInput() {};

protected:
	/**
	 * Callback to call when the user did an action.
	 */
	Callback<void(const UserInput::Type)> inputCallback;
};

#endif /* !MJ344_USERINPUT_HH_ */
