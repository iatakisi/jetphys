// Purpose: Analysis settings for jet physics package
// Author:  mikko.voutilainen@cern.ch
// Created: June 1, 2015
// Updated: June 1, 2015
#ifndef __settings_h__
#define __settings_h__
#include <string>
using std::string;

// All the settings variables are in global name space
// To avoid conflicts, and to make them easier to find
// global variables all start with _jp_ (for JetPhysics)

// Print out debugging information (for this only, no _jp_)
const bool _debug = false;

////////////////////////////////////////
// Necessary analysis settings/inputs //
////////////////////////////////////////

// Algorithm to use ("AK4" or "AK8")
std::string _jp_algo = "AK4";
// Data type ("DATA", "MC", or "HW")
std::string _jp_type = "DATA";

// Number of events to process (-1 for all)
Long64_t _jp_nentries = -1; // all
//Long64_t _jp_nentries = 10; // debug
//Long64_t _jp_nentries = 100000; // short test run
//Long64_t _jp_nentries = 1000000; // for MC
// Number of events to skip from the beginning (for debugging)
Long64_t _jp_nskip = 0;

// PU profiles for data and MC
bool _jp_reweighPU = true;
std::string _jp_pudata = "pileup/pileup_DT.root";
std::string _jp_pumc   = "pileup/pileup_PY_76X.root";
//std::string _jp_pumc   = "pileup/pileup_PY_74X.root";
//std::string _jp_prescalefile = "pileup/prescales74x_run.txt";
std::string _jp_prescalefile = "";//pileup/prescales74x.txt";

// JEC text files in CondFormats/JetMETObjects/data/
bool _jp_redoJEC = true;
std::string _jp_jecgt = "Spring16_25nsV6";
//std::string _jp_jecgt = "Fall15_25nsV2"; // 76X
//std::string _jp_jecgt = "Summer15_25nsV7"; // 74X
//std::string _jp_jecgt = "Summer15_25nsV6";
//std::string _jp_jecgt = "Summer15_50nsV5";

// Veto jets near ECAL boundaries in JetID
const bool _jp_doECALveto = false;
string _jp_ecalveto = "lumicalc/ecalveto.root";

// Reapply json selection based on the latest one (check lumicalc if false!)
const bool _jp_dojson = false;//true;
string _jp_json = "lumicalc/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_v2.txt";

// Calculate luminosity on the fly based on .csv file
const bool _jp_dolumi = true;
string _jp_lumifile = "lumicalc/brilcalc_lumibyls.csv"; // Run II
//string _jp_lumifile = "lumicalc/brilcalc_lumibyls_silver.csv"; // Run II
//string _jp_lumifile = "lumicalc/pixellumi_by_LS_jan16.csv"; // Run I

// List of triggers used in the analysis
/*
// This is the 8 TeV list
const int _jp_ntrigger = 6;
std::string _jp_triggers[_jp_ntrigger] =
  {"jt30",    "jt60",   "jt110",   "jt190",   "jt240",   "jt370"};
double _jp_trigthr[_jp_ntrigger] =
  {    30,        60,       110,       190,       240,       370};
double _jp_trigranges[_jp_ntrigger][2] =
  { {0,97}, {97,174}, {174,300}, {300,362}, {362,507}, {507,3500}};
*/

/*
// This is the 13 TeV 50 ns list
const int _jp_ntrigger = 9;//10; // jt450,jt500 both unprescaled, so drop 500
std::string _jp_triggers[_jp_ntrigger] =
  {"jt40",    "jt60",    "jt80",   "jt140",   "jt200",   "jt260",   "jt320",   "jt400",  "jt450"};
double _jp_trigthr[_jp_ntrigger] =
  {     40,       60,        80,       140,       200,       260,       370,       400,      450};
double _jp_trigranges[_jp_ntrigger][2] =
  { {0,97}, {97,174},  {97,174}, {174,300}, {300,362}, {362,507}, {362,507}, {507,548}, {548,6500}};
*/

// This is the 13 TeV 25 ns list (Run2015D)
const int _jp_ntrigger = 9; // jt450 unprescaled, so drop 500, but add Zero Bias
std::string _jp_triggers[_jp_ntrigger] =
  {"jt40",    "jt60",    "jt80",   "jt140",   "jt200",   "jt260",   "jt320",   "jt400",  "jt450"};
double _jp_trigthr[_jp_ntrigger] =
  {40,       60,        80,       140,       200,       260,       320,       400,      450};
double _jp_trigranges[_jp_ntrigger][2] =
  //{ {0,0}, {0,97}, {97,174},  {97,174}, {174,300}, {300,362}, {362,507}, {362,507}, {507,548}, {548,6500}};
  { {0,74}, {74,97},  {97,174}, {174,245}, {245,330}, {330,430}, {430,507}, {507,548}, {548,6500}}; // V2c, AK4
// brilcalc lumi --hltpath "HLT_PFJet40_v*" -i [JSON]
bool _jp_usetriglumi = true; // use luminosity numbers below, in /ub
double _jp_triglumi[_jp_ntrigger] = // in /ub
  //{2.331314e+05, 3.424242e+05, 6.931689e+05, 2.727443e+06, 1.87656e+07, 1.90751e+08, 3.99126e+08,  8.83649e+08, 2.18260e+09}; // golden
//{2.345463e+05, 3.987553e+05, 9.188639e+05, 2.874062e+06, 2.169800e+07, 2.347366e+08, 4.870975e+08, 1.059592e+09, 2.534487e+09}; // silver
  //{2.33091e+05, 3.42068e+05, 6.91877e+05, 2.72039e+06, 1.87110e+07, 1.90199e+08, 3.97959e+08, 8.81065e+08, 2.17573e+09}; // Cert_fillHistos.json
  //
  //brilcalc lumi -i Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_v2.txt --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/OfflineNormtagV2.json --hltpath "HLT_PFJet40_v*"
  {2.454848e+05, 3.593645e+05, 7.241042e+05, 2.832670e+06, 1.947122e+07,
   1.981668e+08, 4.145646e+08, 9.180884e+08, 2.263472e+09}; // normtag golden
// Decide whether or not to simulate triggers from MC (this is slow)
bool _jp_domctrigsim = false;
// Use "mc" trigger for whole pT range instead of stiching triggers together
bool _jp_usemctrig = true;
std::string _jp_mctrig = "jt450"; // reference trigger (for PU profile)

// Unprescaled luminosity for plots
const double _jp_lumi = 2.2635; // /fb from brilcalc for jt450
const double _jp_sqrts = 13000.; // GeV
const double _jp_emax = _jp_sqrts/2.; // GeV

//////////////////////////////////
// Additional analysis switches //
//////////////////////////////////

// Do additional AK4/AK8 histograms
const bool _jp_ak4ak8 = (_jp_algo=="AK8" && false);
// Apply "CHS" through betaStar
const bool _jp_doCHS = false;
// Fill histograms separately for each five eras
const bool _jp_doEras = false;
// Use Intervals-Of-Validity for JEC
const bool _jp_useIOV = false;
// Produce run-level histograms
const bool _jp_doRunHistos = true;//false;
// Produce basic set of histograms
const bool _jp_doBasicHistos = true;

// Process pThatbins instead of flat sample
const bool _jp_pthatbins = false;
// Correct for trigger efficiency based on MC
const bool _jp_dotrigeff = false;//true;
 // Correct pT<114 GeV only, if above _jp_dotrigeff=true
const bool _jp_dotrigefflowptonly = false;//true;
// Correct for time-dependence (prescales) in data
const bool _jp_dotimedep = false;//true;
// For creating smearing matrix
const bool _jp_doMatrix = false;

// Check that run / lumi section was listed in the .csv file
const bool _jp_dolumcheck = false;
//// Veto bad run list
//const bool _jp_dorunveto = false;
// Check for duplicates (warning: takes a lot of memory!)
const bool _jp_checkduplicates = false;//true;
// Only load selected branches (large speedup, but be careful!)
const bool _jp_quick = true;
// Center uncertainties around ansatz (true) or data (false)
const bool _jp_centerOnAnsatz = false;
const bool _jp_centerOnTheory = false;

// Plot Pythia for final PRL results
const bool _plotPythia = false;
// Minimum and maximum pT range to be plotted and fitted
const double _jp_recopt = 24;//21.;
const double _jp_fitptmin = 43;
// Changed on 2013-05-020: analysis from 49 GeV to 56 GeV
const double _jp_xmin57 = 56;
const double _jp_xminpas = 56;
const double _jp_xmin = 24.;//20.;
const double _jp_xmax = 1999.;

const double _jp_xsecMinBias = 7.126E+10;

//// Write histograms to PAS file
//const bool _jp_pas = true;
// Draw b-jets against MC@NLO instead of reco MC
//const bool _mcnlo = true;
//// Draw againts HERAPDF1.7 instead of PDF4LHC
const bool _jp_herapdf = false;

// Produce plots
const bool _jp_pdf = true;

#endif // __settings_h__
