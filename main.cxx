#include <iostream>
#include <string>
#include "src/CmcMaker.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"

using std::cout;

int main(int argc, char** argv){

    // Initialization.
    std::string* fileName;
    if(argc <= 1){
        fileName = new std::string("CmcEvents.root");
    }
    else{
        fileName = new std::string(argv[1]);
    }
    CmcMaker* m = new CmcMaker();
    double* px = m->getPx();
    double* pxStep = m->getPxStep();
    double* py = m->getPy();
    double* pyStep = m->getPyStep();
    int mul = m->getMul();
    TTree* tTree = new TTree("CMC", "");
    TH1D* hPx = new TH1D("hPx", "", 100, -2.5, 2.5);
    TH1D* hPy = new TH1D("hPy", "", 100, -2.5, 2.5);
    TH1D* hPxStep = new TH1D("hPxStep", "", 100, 0, 2.5);
    TH1D* hPyStep = new TH1D("hPyStep", "", 100, 0, 2.5);
    tTree->Branch("px", px);
    tTree->Branch("pxStep", pxStep);
    tTree->Branch("py", py);
    tTree->Branch("pyStep", pyStep);
    tTree->Branch("mul", &mul);

    // Generate events.
    int nEv = 1000;
    double lam = 20.; // double lam -> The multiplicity is a variable respects to Poisson distribution.
    //int n = 20; // int n -> The multiplicity is a certain integer.
    for(int i=0; i<nEv; i++){
        m->generate(lam);
        // m->generate(n);
        mul = m->getMul();
        px = m->getPx();
        pxStep = m->getPxStep();
        py = m->getPy();
        pyStep = m->getPyStep();
        // fill the histogram
        for(int j=0; j<mul; j++){
            hPx->Fill(px[j]);
            hPy->Fill(py[j]);
            hPxStep->Fill(pxStep[j]);
            hPyStep->Fill(pyStep[j]);
        }
        tTree->Fill();
    }

    // Save root file.
    TFile* tFile = new TFile(fileName->c_str(), "recreate");
    tFile->cd();
    tTree->Write();
    hPx->Write();
    hPy->Write();
    hPxStep->Write();
    hPyStep->Write();
    tFile->Close();

    return 0;
}