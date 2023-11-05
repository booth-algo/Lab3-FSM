#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vf1_fsm.h"

#include "vbuddy.cpp"
#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env) {
  int simcyc;
  int tick; 

  Verilated::commandArgs(argc, argv);
  Vf1_fsm* top = new Vf1_fsm;
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("f1_fsm.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T1");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->rst = 1;
  top->en = 0; // init not enabled, so rotary button doesn't do anything
  top->data_out = 0;

  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    top->rst = 0; // Added line to set to 0 to start counter
    top->en = vbdFlag();
    vbdHex(2, (top->data_out >> 4) & 0xF); // Added line to display two digits
    vbdHex(1, top->data_out & 0xF);
    vbdBar(top->data_out & 0xFF); // mask data_out with 0xFF
    
    vbdCycle(simcyc+1); // Displays cycle number in display

    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}