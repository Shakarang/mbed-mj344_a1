/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T13:37:35+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T15:53:44+00:00
*/

#ifndef MJ344_SENSORINPUT_HH_
#define MJ344_SENSORINPUT_HH_

#include <map>
#include <string>
#include <vector>

#include "mbed.h"

/**
 * Abstract class that needs to be inherited.
 * It is used to interract with different inputs
 */
class ASensorInput {

public:
	/**
	 * Sensor type.
	 */
	enum Type {
		TEMPERATURE, ACCELEROMETER
	 };

public:
	ASensorInput(const ASensorInput::Type);
	virtual ~ASensorInput() {};

	/**
	 * Get sensor type
	 * @return type
	 */
	ASensorInput::Type						getType() const;

	/**
	 * Get sensor type in a readable way.
	 * Used for print.
	 * @return type in string
	 */
	std::string								getTypeReadable() const;

	/**
	 * Get all available units. (e.g. Celsius, Fahrenheit...)
	 */
	const std::vector<std::string>			&getUnits() const;

	/**
	 * Get current unit used.
	 * @return unit in string
	 */
	const std::string						getCurrentUnit() const;

	/**
	 * Get the index of the current unit.
	 * Used to select it in the menu/
	 * @return index
	 */
	int										getCurrentUnitIndex() const;

	/**
	 * Get next unit of the list.
	 * @return unit
	 */
	const std::string						getNextUnit();

	/**
	 * Get previous unit of the list.
	 * @return unit
	 */
	const std::string 						getPreviousUnit();

	/**
	 * Get data is a pure function that needs to be implemented by the child.
	 * It help to manage the data and the related calculus.
	 */
	virtual std::map<std::string, float>	getData() const = 0;

private:
	/**
	 * Type of the sensor.
	 */
	const ASensorInput::Type				type;

protected:
	/**
	 * Index of the needed used to put the needed information.
	 */
	int										currentUnitIndex;

	/**
	 * All available units.
	 */
	std::vector<std::string>				units;
};

#endif /* !MJ344_SENSORINPUT_HH_ */
