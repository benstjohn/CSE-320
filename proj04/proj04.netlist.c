
/******************************************************************************
 Ben St. John
 CSE320 Project #4
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Insert your Pulsers here
  Pulser ((SD("2a"), "I ----------- Initial "),  Init, 'i', 10000);
  Pulser ((SD("3a"), "C ----------- Clock"), Clock, 'c', 10000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Insert your Probes here
  Probe ( (SD("1e"), "w"), w );
  Probe ( (SD("2e"), "x"), x );
  Probe ( (SD("3e"), "y"), y );
  Probe ( (SD("4e"), "z"), z );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Insert your declarations for any auxiliary Signals here
  Signal notw, notx, noty, notz, and1, and2, and3, and4, and5, and6, W, X, Y, Z;

  // Insert your DFFs here
  Dff (SD(sd,"1d"), (Init, W, Clock, Zero), w);
  Dff (SD(sd,"2d"), (Zero, X, Clock, Init), x);
  Dff (SD(sd,"3d"), (Init, Y, Clock, Zero), y);
  Dff (SD(sd,"4d"), (Zero, Z, Clock, Init), z);

  // Insert your combinational logic here (Not, And, Or gates)
  Not ( SD(sd, "1a"), w, notw );
  Not ( SD(sd, "2a"), x, notx );
  Not ( SD(sd, "3a"), y, noty );
  Not ( SD(sd, "4a"), z, notz );

  // AND gates
  And ( SD(sd, "1b"), (notx, noty, z), and1 ); //W  

  And ( SD(sd, "2b"), (x, z), and2 ); //X

  And ( SD(sd, "3b"), (notx, z), and3 ); //Y
  And ( SD(sd, "4b"), (notz, x), and4 ); 

  And ( SD(sd, "5b"), (noty, notz), and5 ); //Z

  // OR gate*/
  Or ( SD(sd, "1c"), (and1), W );    
  Or ( SD(sd, "2c"), (and2, w), X );
  Or ( SD(sd, "3c"), (and3, and4), Y );
  Or ( SD(sd, "4c"), (w, and5), Z );
}

