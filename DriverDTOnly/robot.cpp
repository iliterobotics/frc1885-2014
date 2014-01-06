#include <vector>

#include "WPILib.h"

class DriverDTOnly : public SimpleRobot
{
	Joystick leftStick, rightStick;

	Talon dtLeft1, dtRight1, dtLeft2, dtRight2, dtLeft3, dtRight3, dtLeft4, dtRight4, dtLeft5, dtRight5;

	bool arcadeDrive;
	float joy1x, joy1y, joy2x, joy2y;
	float dtLeftPower, dtRightPower;

	static const int arcadeToggle = 3, tankToggle = 5;

public:
	DriverDTOnly(void):
		leftStick(1),
		rightStick(2),
		dtLeft1(1),
		dtRight1(2),
		dtLeft2(3),
		dtRight2(4),
		dtLeft3(5),
		dtRight3(6),
		dtLeft4(7),
		dtRight4(8),
		dtLeft5(9),
		dtRight5(10),
		arcadeDrive(true),
		joy1x(0.0),
		joy1y(0.0),
		joy2x(0.0),
		joy2y(0.0),
		dtLeftPower(0.0),
		dtRightPower(0.0)
	{

	}

	void Autonomous(void)	{}

	void OperatorControl(void)
	{
		while (IsOperatorControl())

		{
			getInput();
			processDriveTrain();
			outputToMotors();

			Wait(0.005);				// wait for a motor update time
		}
	}

	void getInput()
	{
		// Check for arcade/tank mode
		if (leftStick.GetRawButton(arcadeToggle)) 
		{
			arcadeDrive = true;
		}

		else if (leftStick.GetRawButton(tankToggle))
		{
			arcadeDrive = false;
		}

		// Get joystick inputs
		joy1x = leftStick.GetX(GenericHID::kLeftHand);
		joy1y = leftStick.GetY(GenericHID::kLeftHand);
		joy2x = rightStick.GetX(GenericHID::kRightHand);
		joy2y = rightStick.GetY(GenericHID::kRightHand);
	}

	void processDriveTrain ()
	{
		if (arcadeDrive)
		{
			if (joy2y > 0)
			{
				dtLeftPower = -joy2x - joy2y;
				dtRightPower = joy2y - joy2x;
			}

			else
			{
				dtLeftPower = joy2x - joy2y;
				dtRightPower = joy2x + joy2y;
			}
		}
		else
		{
			dtLeftPower = -joy1y;
			dtRightPower = joy2y;
		}
	}

	void outputToMotors()
	{
		dtLeft1.SetSpeed(dtLeftPower);
		dtLeft2.SetSpeed(dtLeftPower);
		dtLeft3.SetSpeed(dtLeftPower);
		dtLeft4.SetSpeed(dtLeftPower);
		dtLeft5.SetSpeed(dtLeftPower);
		
		dtRight1.SetSpeed(dtRightPower);
		dtRight2.SetSpeed(dtRightPower);
		dtRight3.SetSpeed(dtRightPower);
		dtRight4.SetSpeed(dtRightPower);
		dtRight5.SetSpeed(dtRightPower);
	}
};

START_ROBOT_CLASS(DriverDTOnly);



