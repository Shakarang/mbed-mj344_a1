/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T17:13:43+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:13:59+00:00
*/

#ifndef MJ344_SERVICEMANAGER_HH_
#define MJ344_SERVICEMANAGER_HH_

#include <map>
#include <string>

#include "IOManager/IOManager.hh"

#define SERVICE_MINIMAL_RATE 10.0 // Slowest rate
#define SERVICE_RATE_STEP 0.2 // Incrementation to slow up the rate
#define SERVICE_MAXIMAL_RATE 0.2 // Fastest rate

/**
 * The purpose of this class is to manage all the project.
 */
class ServiceManager {

public:
	ServiceManager();
	~ServiceManager();

private:
	/**
	 * Manager to help reading/writing data.
	 */
	IOManager		iomanager;

	/**
	 * Current sensor to collect the data.
	 */
	ASensorInput	*currentSensor = NULL;

	/**
	 * Boolean to know if we should display sensor data on screen or not.
	 * It's false when the user is interracting with the joystick.
	 */
	bool			shouldDisplayData;

	/**
	 * Is the program "running", used to manage the resume/pause.
	 */
	bool			isRunning;

	/**
	 * Ticker used to collect data from selected sensor.
	 * When the program in in pause, we delete it to avoid too much power consuption.
	 */
	Ticker			*ticker = NULL;

	/**
	 * Current rate to collect sensor data.
	 */
	float			rate;

public:
	/**
	 * Start : starts the "program" by creating a new ticker to collect data.
	 */
	void			start();

	/**
	 * Stop : stops the "program", changes led display and delete ticket.
	 */
	void			stop();

private:

	/**
	 * Handler triggered by all inputs from joystick.
	 * @param UserInput::Type input type : FIRE,LEFT,RIGHT,UP,DOWN
	 */
	void			joystickHandler(const UserInput::Type);

	/**
	 * Handler triggered by an associated UserInput.
	 * @param UserInput::Type input type : FIRE
	 */
	void			resumeHandler(const UserInput::Type);

	/**
	 * Handler triggered by an associated UserInput.
	 * Changes the rate value by increasing the time between two collections.
	 * @param UserInput::Type input type : FIRE
	 */
	void			updateRateHandler(const UserInput::Type);

	/**
	 * Handler used to manage temperature data and what to do with.
	 * @param map containing all data [String: Float] e.g. Celsius:20.0
	 */
	void			temperatureHandler(std::map<std::string, float>);

	/**
	 * Handler used to manage accelerometer data and what to do with.
	 * Change the color of the LED on the shield.
	 * @param map containing all data [String: Float] e.g. Pitch:30.à
	 */
	void			accelerometerHandler(std::map<std::string, float>);

	/**
	 * Handler triggered at each tick.
	 */
	void			tickerHandler();

	/**
	 * Choose which color will be displayed depending of the orientation.
	 * @param  float Pitch
	 * @param  float Roll
	 * @return       Color
	 */
	int accelerometerColor(float, float);

};

#endif /* !MJ344_SERVICEMANAGER_HH_ */
