/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:06:23+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-07T22:08:37+00:00
*/

#ifndef MJ344_IOMANAGER_HH_
#define MJ344_IOMANAGER_HH_

#include <vector>
#include <string>

#include "Inputs/UserInput/UserInput.hh"
#include "Inputs/SensorInput/ASensorInput.hh"

#include "Outputs/Light.hh"
#include "Outputs/Host.hh"
#include "Outputs/Screen.hh"

/**
 * The purpose of this class is to manage all inputs and outputs the easiest way possible.
 * We can easily add and use an input or an output to out project.
 */
class IOManager {

public:
	IOManager();
	~IOManager();

private:

	/**
	 * Vector of all available userinputs (Switch, Joystick)
	 */
	std::vector<UserInput*>		userInputs;

	/**
	 * Vector of all available sensors (Temperature, Accelerometer..)
	 */
	std::vector<ASensorInput*>	sensors;

	/**
	 * LCD screen
	 */
	Screen						screen;

	/**
	 * Serial host
	 */
	Host 						host;

	/**
	 * RGB light on the K64F
	 */
	Light						bottomLight;

	/**
	 * RGB light on the shield
	 */
	Light						topLight;

	/**
	 * Current sensor index in the vector.
	 * Used for selecting sensor in the menu.
	 */
	int							currentSensorIndex;

public:

	/**
	 * Display string on LCD screen
	 * @param  data to print
	 */
	void								display(const std::string &);

	/**
	 * Print data on the computer
	 * @param  data to print
	 */
	void								log(const std::string &);

	/**
	 * Add userinput in the inputs array.
	 * @param  Pointer to the input to add.
	 */
	void 								addUserInput(UserInput *);

	/**
	 * Add sensor in the sensors array.
	 * @param  Pointer to the sensor to add.
	 */
	void 								addSensor(ASensorInput *);

	/**
	 * Retrieve all available sensors.
	 * @return reference on the sensors vector.
	 */
	const std::vector<ASensorInput*>	&getSensors() const;

	/**
	 * Get next sensor from the list
	 * @return Sensor
	 */
	ASensorInput						*getNextSensor();

	/**
	 * Get previous sensor from the list
	 * @return Sensor
	 */
	ASensorInput 						*getPreviousSensor();

	/**
	 * Get reference of the K64F rgb light.
	 * @return reference of light
	 */
	Light								&getBottomLight();

	/**
	 * Get reference of the mbed rgb light.
	 * @return reference of light
	 */
	Light								&getTopLight();
};

#endif /* !MJ344_IOMANAGER_HH_ */
