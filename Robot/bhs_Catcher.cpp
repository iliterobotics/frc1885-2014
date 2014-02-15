#include "bhs_Catcher.h"

bhs_Catcher::bhs_Catcher(bhs_GDCatcher* a_dc){
	m_dc = a_dc;
}
void bhs_Catcher::run(){
	if(m_dc->mdc_catcherButton)
		m_dc->mdc_catcherOn = true;
	else //if m-dc->mdc_catcherButton
		m_dc->mdc_catcherOn = false;
}
bhs_Catcher::~bhs_Catcher(){
	m_dc = 0;
}