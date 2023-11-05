#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"  // include vbuddy code
#define MAX_SIM_CYC 100000
#define RESET_CYCLES 5

int main(int argc, char **argv, char **env) {
  unsigned int simcyc;  // simulation clock count
  int lights = 0; // state to toggle LED lights
  int tick = 0;

  Verilated::commandArgs(argc, argv);
  Vtop *top = new Vtop;
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("top.vcd");

  if (vbdOpen() != 1) return -1;
  vbdHeader("L3T4");
  vbdSetMode(1);  // Flag mode set to one-shot

  top->clk = 0;
  top->rst = 1; // Begin in reset
  top->trigger = 0;
  top->N = 50;
  top->K = vbdValue();

   // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // Display toggle neopixel
    if (top->time_out) {
      vbdInitWatch();
      vbdBar(lights);
      lights = lights ^ 0xFF;
      top->data_out = vbdElapsed();
      vbdHex(2, (top->data_out >> 4) & 0xF); // Added line to display two digits
      vbdHex(1, top->data_out & 0xF);
    }

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->trigger = vbdFlag();
    
    vbdHex(2, (top->data_out >> 4) & 0xF); // Added line to display two digits
    vbdHex(1, top->data_out & 0xF);
    vbdBar(top->data_out & 0xFF); // mask data_out with 0xFF

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->en = (simcyc > 2);
    top->N = vbdValue();
    vbdCycle(simcyc);

    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
