/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:06:23+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T22:33:03+00:00
*/

#ifndef MJ344_IOMANAGER_HH_
#define MJ344_IOMANAGER_HH_

#include <vector>
#include <string>

#include "Outputs/Light.hh"
#include "Inputs/UserInput/UserInput.hh"
#include "Inputs/SensorInput/ASensorInput.hh"

#include "Outputs/Host.hh"
#include "Outputs/Screen.hh"

class IOManager {

public:
	IOManager();
	~IOManager();

private:
	std::vector<UserInput*>		userInputs;
	std::vector<ASensorInput*>	sensors;

	Screen						screen;
	Host 						host;

	Light						bottomLight;
	Light						topLight;

	int							currentSensorIndex;

public:

	void						display(const std::string &);
	void						log(const std::string &);

	void 						addUserInput(UserInput *);
	void 						addSensor(ASensorInput *);

	const std::vector<ASensorInput*>	&getSensors();
	ASensorInput					*getNextSensor();
	ASensorInput 					*getPreviousSensor();

	Light					&getBottomLight();
	Light					&getTopLight();
};

#endif /* !MJ344_IOMANAGER_HH_ */
