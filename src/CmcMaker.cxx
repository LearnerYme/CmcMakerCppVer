#include "CmcMaker.h"
#include "TRandom3.h"
#include <iostream>

Event::Event(){
    mul = MAXMUL;
    clean();
    return;
}

Event::Event(int mul){
    this->mul = mul;
    clean();
    return;
}

void Event::clean(){
    for(int i=0; i<=MAXMUL; i++){
        px[i] = 0;
        py[i] = 0;
    }
    return;
}

CmcMaker::CmcMaker(){
    event = new Event();
    nu = 1./6;
    pMin = 2E-7;
    pMax = 2;
    return;
}

CmcMaker::CmcMaker(double nu){
    event = new Event();
    this->nu = nu;
    pMin = 2E-7;
    pMax = 2;
    return;
}

CmcMaker::CmcMaker(double nu, double pMin, double pMax){
    event = new Event();
    this->nu = nu;
    this->pMin = pMin;
    this->pMax = pMax;
    return;
}

double CmcMaker::inverseFunction(double F){
    double a = TMath::Power(pMin, nu);
    double b = TMath::Power(pMax, nu);
    return TMath::Power((a*b) / (b - (b - a)*F), 1/nu);
}

void CmcMaker::clean(){
    event->clean();
    return;
}

void CmcMaker::generate(int mul){
    TRandom3 rd(0);
    event->mul = mul;
    event->px[0] = rd.Uniform(-0.5, 0.5);
    event->py[0] = rd.Uniform(-0.5, 0.5);
    for(int iTrack=1; iTrack<=mul; iTrack++){
        double F1 = rd.Uniform(0, 1);
        double F2 = rd.Uniform(0, 1);
        double sign1 = rd.Uniform(0, 1);
        double sign2 = rd.Uniform(0, 1);
        double pxStepTmp = inverseFunction(F1);
        double pyStepTmp = inverseFunction(F2);
        if(sign1 < 0.5){
            pxStepTmp *= -1;
        }
        if(sign2 < 0.5){
            pyStepTmp *= -1;
        }
        event->pxStep[iTrack] = pxStepTmp;
        event->pyStep[iTrack] = pyStepTmp;
        event->px[iTrack] = event->px[iTrack-1] + pxStepTmp;
        event->py[iTrack] = event->py[iTrack-1] + pyStepTmp;
    }
    return;
}

void CmcMaker::generate(double lam){
    TRandom3 rd(0);
    int mul = rd.Poisson(lam);
    event->mul = mul;
    generate(mul);
    return;
}

double* CmcMaker::getPx(){
    return event->px;
}

double* CmcMaker::getPy(){
    return event->py;
}

double* CmcMaker::getPxStep(){
    return event->pxStep;
}

double* CmcMaker::getPyStep(){
    return event->pyStep;
}

int CmcMaker::getMul(){
    return event->mul;
}
