{
  gSystem->AddIncludePath(" -I$ROOFITSYS/include ");
  gSystem->Load("libRooFit");

  gROOT->ProcessLine(".L RooRecursiveChebyshev.cc++");
}
