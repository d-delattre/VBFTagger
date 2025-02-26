#pragma once

#include <iostream>
#include <sys/stat.h>

#include <TH1F.h>
#include <TFile.h>
#include <TGraphAsymmErrors.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLine.h>
#include <TStyle.h>
#include <TKey.h>
#include <TTree.h>
#include <TLatex.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

#include "LEAF/Analyzer/include/BaseHists.h"
#include "LEAF/Analyzer/include/constants.h"
#include "LEAF/Analyzer/include/useful_functions.h"
#include "LEAF/Analyzer/include/GenLevelConstants.h"
#include "LEAF/Analyzer/include/GenLevelUtils.h"

#include "LEAF/VBFTagger/include/VBFTaggerEvent.h"
#include "LEAF/VBFTagger/include/Utils.h"
#include "LEAF/VBFTagger/include/ParticlesFinder.h"


using namespace std;

class GenLevelStudiesPrunedHists : public BaseHists{

public:
  // Constructors, destructor
  GenLevelStudiesPrunedHists(TString dir_, TString selection_="");
  GenLevelStudiesPrunedHists(const GenLevelStudiesPrunedHists &) = default;
  GenLevelStudiesPrunedHists & operator = (const GenLevelStudiesPrunedHists &) = default;
  ~GenLevelStudiesPrunedHists() = default;

  // Main functions
  void fill(const VBFTaggerEvent & event);

private:
  TString selection;
  vector<string> gen_ids_names;

  const vector<ParticleID> gen_ids = {
    // ParticleID::u, ParticleID::d, ParticleID::s, ParticleID::c, ParticleID::b, ParticleID::t,
    ParticleID::e, ParticleID::mu, ParticleID::v_e, ParticleID::v_mu, ParticleID::v_tau,
    ParticleID::photon, ParticleID::Z, ParticleID::W, ParticleID::H,
    ParticleID::pi_0, ParticleID::pi_plus, ParticleID::kaon_0_L, ParticleID::kaon_0_S, ParticleID::kaon_plus,
    ParticleID::delta_plus_plus, ParticleID::delta_plus, ParticleID::delta_0, ParticleID::lambda, ParticleID::proton
  };

  const vector<string> gen_flags_names = {
    "isDecayedLeptonHadron", "isDirectHadronDecayProduct", "fromHardProcessFinalState", "fromHardProcessDecayed"
    "isPrompt", "isPromptFinalState", "isPromptDecayed", "isHardProcess", "fromHardProcess", "fromHardProcessBeforeFSR",
  };

};
