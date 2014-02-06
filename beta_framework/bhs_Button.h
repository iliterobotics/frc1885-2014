#ifndef BHS_BUTTON_H
#define BHS_BUTTON_H
#include "Joystick.h"

class bhs_Button 
{
public:
        bhs_Button(Joystick*, int, btnType);
        bhs_Button(Joystick*, int, btnType, int);

        bool apply();
protected:
        static typedef enum
        {
        	toggle,
        	constant,
        	delay
        } btnType;
        
        bhs_ButtonType button;
        
        Joystick* joystick;
        int btnNum;
};

class bhs_ButtonType {
public:
	bhs_ButtonType(int);
	virtual bool apply(bool);
protected:
	int btnDelay;
	int count;
	bool m_currentValue;
	bool m_lastValue;
};
class bhs_ToggleButton : bhs_ButtonType {
public:
	bhs_ToggleButton();
	bool apply(bool);
};
class bhs_ConstantButton : bhs_ButtonType {
public:
	bhs_ConstantButton();
	bool apply(bool);
};
class bhs_DelayButton : bhs_ButtonType {
public:
	bhs_DelayButton();
	bool apply(bool);
};

#endif
