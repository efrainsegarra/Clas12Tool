//***********************************************************************
//***********************************************************************
//    ____  ____  _____  _______     ___      ______       __
//   |_   ||   _||_   _||_   __ \  .'   `.   / ____ `.    /  |
//     | |__| |    | |    | |__) |/  .-.  \  `'  __) |    `| |
//     |  __  |    | |    |  ___/ | |   | |  _  |__ '.     | |
//    _| |  | |_  _| |_  _| |_    \  `-'  / | \____) | _  _| |_
//   |____||____||_____||_____|    `.___.'   \______.'(_)|_____|
//
//=======================================================================
// Autogenerated code by HIPO 3.1 io library
// Modify the main loop to suite your needs
// Date: 07/17/2018
// Author: G.Gavalian
//***********************************************************************
#include <cstdlib>
#include <iostream>
#include <chrono>
#include "reader.h"
#include "clas12event.h"


int main(int argc, char** argv) {
  // Record start time
  auto start = std::chrono::high_resolution_clock::now();

   std::cout << " reading file example program (HIPO) "  << __cplusplus << std::endl;

   char inputFile[256];
   char outputFile[256];

   if(argc>1) {
      sprintf(inputFile,"%s",argv[1]);
   } else {
      std::cout << " *** please provide a file name..." << std::endl;
     exit(0);
   }

   hipo::reader  reader;
   reader.open(inputFile);

   clas12::clas12event  event(reader);

   clas12::vector3      electron;

   while(reader.next()==true){
      int np = event.particles().getSize();

      double starttime = event.header().getStartTime();

      for(int i = 0; i < np; i++){
        int     pid = event.particles().getPid(i);
        if(pid==11){

           event.particles().getVector3(i,electron);

           double beta = event.getBeta(clas12::FTOF1A,i);
           double time = event.getTime(clas12::FTOF1A,i);
           double ecEnergy   = event.getEnergy(clas12::EC,i);
           double pcalEnergy = event.getEnergy(clas12::PCAL,i);
           double sf         = ecEnergy/electron.mag();
           // printf("pid = %8d time = %8.3f ec = %8.3f  pcal = %8.3f sf = %8.3f beta = %8.3f\n",
           //        pid,time-starttime,ecEnergy,pcalEnergy,sf, beta);
        }
      }
   }
  auto finish = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = finish - start;
   std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}
//### END OF GENERATED CODE
