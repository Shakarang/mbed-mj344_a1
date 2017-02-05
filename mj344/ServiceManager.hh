/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T17:13:43+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T19:52:25+00:00
*/

#ifndef MJ344_SERVICEMANAGER_HH_
#define MJ344_SERVICEMANAGER_HH_

#include <vector>
#include <string>

#include "IOManager/IOManager.hh"

class ServiceManager {

public:
	ServiceManager();
	~ServiceManager();

private:
	/**
	 * Manager to help reading/writing data
	 */
	IOManager	iomanager;

	ASensorInput	*currentSensor;

public:
	void	start();

	void	pauseHandler(const UserInput::Type);
	void	joystickHandler(const UserInput::Type);
};

#endif /* !MJ344_SERVICEMANAGER_HH_ */
