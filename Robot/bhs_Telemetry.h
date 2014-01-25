
#ifndef _TELEMETRY_H_
#define  _TELEMETRY_H_

class bhs_Telemetry 
{
public:
    bhs_Telemetry();
    int connect(String host);
    void disconnect();
    int transfer(void);

private:
    int m_sockFd;
}


#endif //  _TELEMETRY_H_


