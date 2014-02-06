#include "bhs_Button.h"
bhs_Button::bhs_Button(Joystick* joy, int btn, btnType type)
{
	joystick = joy;
	btnNum = btn;
	switch (type)
	{
	case toggle:
		button = new bhs_ToggleButton(0);
		break;
	case constant:
		button = new bhs_ConstantButton(0);
		break;
	case delay:
		button = new bhs_DelayButton(0);
		break;
	default:
		button = new bhs_ConstantButton(0);
		break;
	}
}
bhs_Button::bhs_Button(Joystick* joy, int btn, btnType type, int delay)
{
	joystick = joy;
	button = btn;
	switch (type)
		{
		case toggle:
			button = new bhs_ToggleButton(delay);
			break;
		case constant:
			button = new bhs_ConstantButton(delay);
			break;
		case delay:
			button = new bhs_DelayButton(delay);
			break;
		default:
			button = new bhs_ConstantButton(delay);
			break;
		}
}

bool bhs_Button::apply() {
	return button.apply(joystick->GetRawButton(btn));
}	

bhs_ButtonType::bhs_ButtonType(int delay) 
	: count(0)
	, m_currentValue(false)
	, m_lastValue(false)
{
	btnDelay = delay;
}

bool bhs_ToggleButton::apply(bool inVal) {
        m_currentValue = inVal;

        if (m_lastValue && m_currentValue) {
                m_currentValue = false;
        } else {
                m_lastValue = m_currentValue;
        }

        return m_currentValue;
}

bool bhs_ConstantButton::apply(bool inVal) {
        m_currentValue = inVal;

        return m_currentValue;
}

bool bhs_DelayButton::apply(bool inVal) {
        m_currentValue = false;

        if (count == delay)
        {
        	m_currentValue = inVal;
        	count = 0;
        }
        
        count++;
        
        return m_currentValue;
}
