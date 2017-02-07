/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T11:47:53+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-07T22:22:57+00:00
*/

#ifndef MJ344_JOYSTICK_HH_
#define MJ344_JOYSTICK_HH_

#include "UserInput.hh"

/**
 * Joystick inheriting from UserInput.
 */
class Joystick: public UserInput {

public:
	Joystick(Callback<void(const UserInput::Type)>);
	~Joystick();

private:

	/**
	 * Up used with InterruptIn to catch events.
	 */
	InterruptIn *up;

	/**
	 * Down used with InterruptIn to catch events.
	 */
	InterruptIn *down;

	/**
	 * Left used with InterruptIn to catch events.
	 */
	InterruptIn *left;

	/**
	 * Right used with InterruptIn to catch events.
	 */
	InterruptIn *right;

	/**
	 * Fire used with InterruptIn to catch events.
	 */
	InterruptIn *fire;

private:

	/**
	 * Up event catched.
	 */
	void 		upTriggered();

	/**
	 * Down event catched.
	 */
	void 		downTriggered();

	/**
	 * Left event catched.
	 */
	void 		leftTriggered();

	/**
	 * Right event catched.
	 */
	void 		rightTriggered();

	/**
	 * Fire event catched.
	 */
	void 		fireTriggered();
};

#endif /* !MJ344_JOYSTICK_HH_ */
