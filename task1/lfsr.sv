module lfsr (
    input logic             clk, // clock
    input logic             rst, // reset
    input logic             en,  // enable
    output logic [4:1]      data_out // pseudo-random output
);

    logic[4:1] sreg;        // remember to initialise the "shift register" here

always_ff @ (posedge clk, posedge rst)
    if (rst) 
        sreg <= 4'b1; // Resets the shift register to all '1's which is a common non-zero state.
    else if (en)
        sreg <= {sreg[3:1], sreg[4] ^ sreg[3]}; // Feedback step: taps at 3rd and 4th bit positions

assign data_out = sreg; 

// Primitive polynomial: 1 + X^3 + X^4

endmodule
