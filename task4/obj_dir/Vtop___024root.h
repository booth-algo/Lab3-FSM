// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(data_out,7,0);
    VL_OUT8(time_out,0,0);
    CData/*0:0*/ top__DOT__tick;
    CData/*0:0*/ top__DOT__cmd_seq;
    CData/*0:0*/ top__DOT__cmd_delay;
    CData/*6:0*/ top__DOT__LFSR__DOT__sreg;
    CData/*3:0*/ top__DOT__MUX__DOT__d0;
    CData/*3:0*/ top__DOT__MUX__DOT__d1;
    CData/*0:0*/ top__DOT__MUX__DOT__s;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN16(K,15,0);
    VL_IN16(N,15,0);
    SData/*15:0*/ top__DOT__CLOCK__DOT__count;
    SData/*9:0*/ top__DOT__DELAY__DOT__count;
    IData/*31:0*/ top__DOT__FSM__DOT__curr_state;
    IData/*31:0*/ top__DOT__FSM__DOT__nxt_state;
    IData/*31:0*/ top__DOT__DELAY__DOT__current_state;
    IData/*31:0*/ top__DOT__DELAY__DOT__next_state;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
