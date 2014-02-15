#ifndef BHS_CATCHER_H_
#define BHS_CATCHER_H_

#include "bhs_Constants.h"
#include "bhs_GDCatcher.h"

class bhs_Catcher	{
	public:	
		bhs_Catcher(bhs_GDCatcher*);
		~bhs_Catcher();
		//bhs_Catcher();
		
		void run();
		
	private:
		bhs_GDCatcher *m_dc;
};
#endif // BHS_CATCHER_H_