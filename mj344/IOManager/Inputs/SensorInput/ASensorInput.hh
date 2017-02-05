/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T13:37:35+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T20:08:52+00:00
*/

#ifndef MJ344_SENSORINPUT_HH_
#define MJ344_SENSORINPUT_HH_

#include <map>
#include <string>
#include <vector>

#include "../../../../mbed-os/mbed.h"

class ASensorInput {

public:
	enum Type {
		TEMPERATURE, ACCELEROMETER
	 };

public:
	ASensorInput(const ASensorInput::Type);
	virtual ~ASensorInput() {};

	ASensorInput::Type						getType() const;
	std::string								getTypeReadable() const;
	const std::vector<std::string>			&getUnits() const;
	const std::string						getCurrentUnit() const;
	const std::string						getNextUnit();
	const std::string 						getPreviousUnit();

	virtual std::map<std::string, float>	getData() const = 0;

private:
	const ASensorInput::Type				type;

protected:
	int								currentUnitIndex;
	std::vector<std::string>				units;
//	void	(*sensorCallback)(const std::map<>);
};

#endif /* !MJ344_SENSORINPUT_HH_ */
