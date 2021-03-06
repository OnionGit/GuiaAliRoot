void runSimulation(Int_t nevents,
		   const Char_t *config,
		   Int_t runNumber) {
  
  AliSimulation *simulator = new AliSimulation(config);

  TDatime dt;
  UInt_t seed = dt.Get();
  simulator->SetSeed(seed);
  simulator->SetRunNumber(runNumber);
  simulator->SetTriggerConfig("MUON");
  simulator->SetMakeDigits("MUON MFT");
  simulator->SetMakeSDigits("MUON MFT");
  simulator->SetRunQA(":");
  simulator->SetRunHLT("");

  gRandom->SetSeed(seed);

  // MUON Tracker
  simulator->SetSpecificStorage("MUON/Align/Data",      "alien://folder=/alice/simulation/2008/v4-15-Release/Ideal");
  simulator->SetSpecificStorage("MUON/Calib/RecoParam", "alien://folder=/alice/cern.ch/user/a/auras/OCDB/");
  simulator->SetSpecificStorage("MFT/Align/Data",       "alien://folder=/alice/cern.ch/user/a/auras/OCDB/");
  simulator->SetSpecificStorage("MFT/Calib/RecoParam",  "alien://folder=/alice/cern.ch/user/a/auras/OCDB/");

  simulator->UseMagFieldFromGRP();

  // The rest
  TStopwatch timer;
  timer.Start();
  simulator->Run(nevents);
  timer.Stop();
  timer.Print();

}
