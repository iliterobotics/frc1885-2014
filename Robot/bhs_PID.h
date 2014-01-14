#ifndef BHS_PID_H
#define BHS_PID_H

class bhs_PID {
	public:
		bhs_PID();
		
		void reset();
		void init(double, double, double);
		void setMaxCumul(double);
		double apply(double error);
		
		double getP();
		double getD();
		
	private:
		double m_pMult;
		double m_iMult;
		double m_dMult;

		double m_cumulError;
		double m_prevError;
		bool m_firstRun;
		
		bool m_useMaxCumul;
		double m_maxCumul;
};

#endif // BHS_PID_H
