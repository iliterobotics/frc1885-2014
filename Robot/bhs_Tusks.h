#ifndef BHS_TUSKS_H_
#define BHS_TUSKS_H_

#include "bhs_Constants.h"
#include "bhs_GDTusks.h"

class bhs_Tusks  {
	public:
		bhs_Tusks(bhs_GDTusks*);
		~bhs_Tusks();

		void run();

	private:
		bhs_GDTusks* m_dt;
};

#endif //BHS_TUSKS_H_
