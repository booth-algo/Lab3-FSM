// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__DELAY__DOT__count = 0U;
}

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->time_out = ((0U != vlSelf->top__DOT__DELAY__DOT__current_state) 
                        & ((1U != vlSelf->top__DOT__DELAY__DOT__current_state) 
                           & (2U == vlSelf->top__DOT__DELAY__DOT__current_state)));
    vlSelf->data_out = vlSelf->top__DOT__LFSR__DOT__sreg;
    if (((((((((0U == vlSelf->top__DOT__FSM__DOT__curr_state) 
               | (1U == vlSelf->top__DOT__FSM__DOT__curr_state)) 
              | (2U == vlSelf->top__DOT__FSM__DOT__curr_state)) 
             | (3U == vlSelf->top__DOT__FSM__DOT__curr_state)) 
            | (4U == vlSelf->top__DOT__FSM__DOT__curr_state)) 
           | (5U == vlSelf->top__DOT__FSM__DOT__curr_state)) 
          | (6U == vlSelf->top__DOT__FSM__DOT__curr_state)) 
         | (7U == vlSelf->top__DOT__FSM__DOT__curr_state))) {
        if ((0U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 1U;
            vlSelf->data_out = 0U;
        } else if ((1U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 2U;
            vlSelf->data_out = 1U;
        } else if ((2U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 3U;
            vlSelf->data_out = 3U;
        } else if ((3U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 4U;
            vlSelf->data_out = 7U;
        } else if ((4U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 5U;
            vlSelf->data_out = 0xfU;
        } else if ((5U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 6U;
            vlSelf->data_out = 0x1fU;
        } else if ((6U == vlSelf->top__DOT__FSM__DOT__curr_state)) {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 7U;
            vlSelf->data_out = 0x3fU;
        } else {
            vlSelf->top__DOT__FSM__DOT__nxt_state = 8U;
            vlSelf->data_out = 0x7fU;
        }
    } else {
        vlSelf->top__DOT__FSM__DOT__nxt_state = 0U;
        vlSelf->data_out = ((8U == vlSelf->top__DOT__FSM__DOT__curr_state)
                             ? 0xffU : 0U);
    }
    vlSelf->top__DOT__DELAY__DOT__next_state = ((0U 
                                                 == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                 ? 
                                                ((IData)(vlSelf->top__DOT__cmd_delay)
                                                  ? 1U
                                                  : vlSelf->top__DOT__DELAY__DOT__current_state)
                                                 : 
                                                ((1U 
                                                  == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                  ? 
                                                 ((0U 
                                                   == (IData)(vlSelf->top__DOT__DELAY__DOT__count))
                                                   ? 2U
                                                   : vlSelf->top__DOT__DELAY__DOT__current_state)
                                                  : 
                                                 ((2U 
                                                   == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                   ? 
                                                  ((IData)(vlSelf->top__DOT__cmd_delay)
                                                    ? 3U
                                                    : 0U)
                                                   : 
                                                  ((3U 
                                                    == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__cmd_delay)
                                                     ? vlSelf->top__DOT__DELAY__DOT__current_state
                                                     : 0U)
                                                    : 0U))));
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->K = VL_RAND_RESET_I(16);
    vlSelf->N = VL_RAND_RESET_I(16);
    vlSelf->data_out = VL_RAND_RESET_I(8);
    vlSelf->time_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cmd_seq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cmd_delay = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__FSM__DOT__curr_state = 0;
    vlSelf->top__DOT__FSM__DOT__nxt_state = 0;
    vlSelf->top__DOT__CLOCK__DOT__count = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__DELAY__DOT__count = VL_RAND_RESET_I(10);
    vlSelf->top__DOT__DELAY__DOT__current_state = 0;
    vlSelf->top__DOT__DELAY__DOT__next_state = 0;
    vlSelf->top__DOT__LFSR__DOT__sreg = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__MUX__DOT__d0 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__MUX__DOT__d1 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__MUX__DOT__s = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
