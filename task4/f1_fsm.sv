module f1_fsm (
    input logic             clk, // clock
    input logic             rst, // reset
    input logic             trigger,   // start trigger for the sequence
    input logic             en,  // enable
    output logic [7:0]      data_out, // output
    output reg              cmd_seq,   // command to sequence lights
    output reg              cmd_delay  // command to trigger delay
);

    typedef enum  {S0,S1,S2,S3,S4,S5,S6,S7,S8} states;
    states curr_state, nxt_state;

always_comb // Next state logic
    case (curr_state)
        S0: nxt_state = S1;
        S1: nxt_state = S2;
        S2: nxt_state = S3;
        S3: nxt_state = S4;
        S4: nxt_state = S5;
        S5: nxt_state = S6;
        S6: nxt_state = S7;
        S7: nxt_state = S8;
        S8: nxt_state = S0;
        default: nxt_state = S0;
    endcase  

always_comb // Output logic
    case (curr_state)
        S0: data_out = 8'b0;
        S1: data_out = 8'b1;
        S2: data_out = 8'b11;
        S3: data_out = 8'b111;
        S4: data_out = 8'b1111;
        S5: data_out = 8'b11111;
        S6: data_out = 8'b111111;
        S7: data_out = 8'b1111111;
        S8: data_out = 8'b11111111;
        default: data_out = 8'b0;
    endcase

always_ff @(posedge clk)// State transition
    if (rst)           curr_state <= S0;
    else if (en)       curr_state <= nxt_state;
    

endmodule
