#ifndef FORESTSKIMER_H
#define FORESTSKIMER_H

// system include files
#include <memory>
#include <string>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"


class forestSkimer : public edm::EDAnalyzer {
	public:
		explicit forestSkimer(const edm::ParameterSet&);
		~forestSkimer();

		virtual void analyze(const edm::Event&, const edm::EventSetup&);
		virtual void endJob();
		void buildIntree();
		void buildOuttree();

	private:
		TTree *itree;
		TTree *otree;
		TFile *of;//, *infile;
		edm::Service<TFileService> sf;
		float ijtpt[999];
		std::vector<float> *jtpt;
		//muon info.
		bool doMuon = 0;
		std::vector<float> *muonPt=0, *muonEta=0, *muonPhi=0; 
		std::vector<int> *muonIsGood=0, *muonType=0, *muonIsGlobal=0, *muonIsTracker=0, *muonIsPF=0, *muonIsSTA=0, *muonCharge=0;
		std::vector<float> *muonD0=0, *muonDz=0, *muonIP3D=0, *muonD0Err=0, *muonDzErr=0, *muonIP3DErr=0, *muonChi2ndf=0;
		std::vector<float> *muonInnerDz=0, *muonInnerD0=0, *muonInnerDzErr=0, *muonInnerD0Err=0, *muonInnerPt=0, *muonInnerPtErr=0;
		std::vector<float> *muonInnerEta=0;
		std::vector<int> *muonTrkLayers=0, *muonPixelLayers=0, *muonPixelHits=0, *muonMuHits=0, *muonTrkQuality=0, *muonStations=0;
};

#endif
