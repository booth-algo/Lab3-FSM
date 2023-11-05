module lfsr (
    input logic             clk, // clock
    input logic             rst, // reset
    input logic             en,  // enable
    output logic [7:1]      data_out // pseudo-random output
);

    logic[7:1] sreg;        // remember to initialise the "shift register" here

always_ff @ (posedge clk, posedge rst)
    if (rst) 
        sreg <= 7'b1;
    else if (en)
        sreg <= {sreg[6:1], sreg[7] ^ sreg[3]};

assign data_out = sreg; 

// Primitive polynomial: 1 + X^3 + X^7

endmodule
