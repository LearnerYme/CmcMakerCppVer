#ifndef _CM_h
#define _CM_h
#include "TMath.h"

const int MAXMUL = 50;

class Event{
    // It is okay to set features public.
    public:
        Event();
        Event(int mul);
        ~Event();
        void clean();
        int mul;
        double px[MAXMUL];
        double py[MAXMUL];
        double pxStep[MAXMUL];
        double pyStep[MAXMUL];
};

class CmcMaker{
    public:
        CmcMaker();
        CmcMaker(double nu);
        CmcMaker(double nu, double pMin, double pMax);
        ~CmcMaker();
        double* getPx();
        double* getPy();
        double* getPxStep();
        double* getPyStep();
        int getMul();
        void clean();
        void generate(int mul);
        void generate(double lam);

    private:
        Event* event;
        double nu;
        double pMin;
        double pMax;
        double inverseFunction(double F);
};

#endif