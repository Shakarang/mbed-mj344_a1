/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T17:13:43+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-06T20:38:15+00:00
*/

#ifndef MJ344_SERVICEMANAGER_HH_
#define MJ344_SERVICEMANAGER_HH_

#include <map>
#include <string>


#include "IOManager/IOManager.hh"

#define SERVICE_MINIMAL_RATE 10.0 // Slowest rate
#define SERVICE_RATE_STEP 0.2 // Incrementation to slow up the rate
#define SERVICE_MAXIMAL_RATE 0.2 // Fastest rate

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

	bool	shouldDisplayData;

	bool isRunning;

	Ticker	*ticker;

	float rate;

public:
	void	start();
	void	stop();

	void	joystickHandler(const UserInput::Type);


private:
	void	resumeHandler(const UserInput::Type);
	void	updateRateHandler(const UserInput::Type);
	void	temperatureHandler(std::map<std::string, float>);
	void	accelerometerHandler(std::map<std::string, float>);
	void	tickerHandler();

	Light::Color accelerometerColor(float, float);

};

#endif /* !MJ344_SERVICEMANAGER_HH_ */
