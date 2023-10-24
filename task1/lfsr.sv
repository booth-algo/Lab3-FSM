module lfsr (
    input logic             clk; // clock
    input logic             rst; // reset
    input logic             en;  // enable
    output logic [4:1]      data_out // pseudo-random output
);

always_ff @ (posedge clk, posedge rst)
    if (rst) 
        sreg <= 4'b1;
    else if (en)
        sreg <= {sreg[3:1], sreg[4] ^ sreg[3]};

assign data_out = sreg; 

// Primitive polynomial: 1 + X^3 + X^4

endmodule