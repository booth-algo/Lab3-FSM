// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1_fsm.h for the primary calling header

#include "verilated.h"

#include "Vf1_fsm___024root.h"

VL_INLINE_OPT void Vf1_fsm___024root___sequent__TOP__0(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->f1_fsm__DOT__curr_state = 1U;
    } else if (vlSelf->en) {
        vlSelf->f1_fsm__DOT__curr_state = vlSelf->f1_fsm__DOT__nxt_state;
    }
    if (((((((((0U == vlSelf->f1_fsm__DOT__curr_state) 
               | (1U == vlSelf->f1_fsm__DOT__curr_state)) 
              | (2U == vlSelf->f1_fsm__DOT__curr_state)) 
             | (3U == vlSelf->f1_fsm__DOT__curr_state)) 
            | (4U == vlSelf->f1_fsm__DOT__curr_state)) 
           | (5U == vlSelf->f1_fsm__DOT__curr_state)) 
          | (6U == vlSelf->f1_fsm__DOT__curr_state)) 
         | (7U == vlSelf->f1_fsm__DOT__curr_state))) {
        if ((0U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 1U;
            vlSelf->data_out = 0U;
        } else if ((1U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 2U;
            vlSelf->data_out = 1U;
        } else if ((2U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 3U;
            vlSelf->data_out = 3U;
        } else if ((3U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 4U;
            vlSelf->data_out = 7U;
        } else if ((4U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 5U;
            vlSelf->data_out = 0xfU;
        } else if ((5U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 6U;
            vlSelf->data_out = 0x1fU;
        } else if ((6U == vlSelf->f1_fsm__DOT__curr_state)) {
            vlSelf->f1_fsm__DOT__nxt_state = 7U;
            vlSelf->data_out = 0x3fU;
        } else {
            vlSelf->f1_fsm__DOT__nxt_state = 8U;
            vlSelf->data_out = 0x7fU;
        }
    } else {
        vlSelf->f1_fsm__DOT__nxt_state = 0U;
        vlSelf->data_out = ((8U == vlSelf->f1_fsm__DOT__curr_state)
                             ? 0xffU : 0U);
    }
}

void Vf1_fsm___024root___eval(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vf1_fsm___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vf1_fsm___024root___eval_debug_assertions(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
