#ifndef BHS_PC_DATA_SERVER_H
#define BHS_PC_DATA_SERVER_H

#include <vxWorks.h>

#include <errnoLib.h>
#include <hostLib.h>
#include <inetLib.h>
#include <sockLib.h>
#include <semLib.h>

#include "Task.h"
#include "Timer.h"
#include "Utility.h"

#define VIDEO_TO_PC_PORT 1180

class bhs_PCDataServer 
{
public:
	/*
	 * Singleton Pattern
	 */
	static bhs_PCDataServer& getInstance()
	{
		static bhs_PCDataServer instance;
		return instance;
	}

	~bhs_PCDataServer(void);
	unsigned int Release(void);

	bool ready(void);
	void xmitRawData(int header,int length,char* apData);

	static int ServerSocketTask(bhs_PCDataServer* apThis);

private:
	bhs_PCDataServer(void);
	int ServerTask();
	bool mbServerReady;
	SEM_ID mExternalUserSem;
	SEM_ID mServerReadySem;
	SEM_ID mCurrentConnectionDone;

	int mConnectedSocket;

};

#endif
