
/******************************************************************************
 Ben St. John
 Computer Project #3
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
 Creates a counter used to generate 4-bits, and displays output
******************************************************************************/

void simnet()
{
    Signal w, x, y, z, Present, a, b, c, d, e, f, g;
    Signal Strobe (1);
    Signal ResetA (1);
    Signal ResetB (1);
    Signal Output (4);
    
    Pulser ((SD("2a"), "r -- Reset counter"),  ResetA, 'r', 10000);
    Pulser ((SD("3a"), "s -- Strobe counter"), Strobe, 's', 10000);
    
    Not (SD("2b"), ResetA, ResetB);
    
    Counter ((SD("2c-3c"), "4-bit counter"), (ResetB, Strobe), Output);
//sends the four output bits to circuits function

  circuits( SD("1d-4d"), Output[3], Output[2], Output[1], Output[0], Present, a, b, c, d, e, f, g);

  // Displays the output given
    Probe ((SD("1f"), "present"),Present);
    Probe ((SD("2f"), "a"),a);
    Probe ((SD("3g"), "b"),b);
    Probe ((SD("5g"), "c"),c);
    Probe ((SD("6f"), "d"),d);
    Probe ((SD("5e"), "e"),e);
    Probe ((SD("3e"), "f"),f);
    Probe ((SD("4f"), "g"),g);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits, uses NOT, AND, OR to
 help display minimizations

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Replace with declarations for any auxiliary Signals
    Signal notw, notx, noty, notz;
    Signal and1, and2, and3, and4, and5, and6,
    and7, and8, and9, and10, and11, and12, and13, and14, and15, and16, and17;

  // Replace with circuit implementation (Not, And, Or gates)
    Not ( SD(sd, "1a"), w, notw );
    Not ( SD(sd, "2a"), x, notx );
    Not ( SD(sd, "3a"), y, noty );
    Not ( SD(sd, "4a"), z, notz );

    //present
    And ( SD(sd, "2d"), (notw, notx), and1);
    And ( SD(sd, "3d"), (notw, noty), and2);
    And ( SD(sd, "4d"), (notx, y, notz), and3);
    
    Or ( SD(sd, "1f"), (and1, and2, and3), Present);

    //a
    And ( SD(sd, "2e"), (notx, notz), and4);
    And ( SD(sd, "3e"), y, and5);
    And ( SD(sd, "4e"), (x, z), and6);
    
    Or ( SD(sd, "2f"), (and4, and5, and6), a);
    
    //b
    
    Or ( SD(sd, "3g"), (notx, notz), b);
    
    //c
    
    Or ( SD(sd, "5g"), (w, noty, z), c);
    
    //d
    And ( SD(sd, "2g"), (notw, y), and13);
    And ( SD(sd, "3g"), (x, z), and14);
    And ( SD(sd, "4g"), (notx, noty, notz), and15);
    
    Or ( SD(sd, "6f"), (and13, and14, and15), d);
    //e
    
    And ( SD(sd, "2h"), (notx, notz), and16);
    Or( SD(sd, "5e"), (and16), e);
    
    //f
    And ( SD(sd, "2i"), (noty, notz), and17);
    Or( SD(sd, "3e"), (w, x, and17), f);
    
    //g
    Or( SD(sd, "4f"), (x, y), g);
    
}

