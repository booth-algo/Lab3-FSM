module top #(
    parameter WIDTH = 16
)(
    input  logic             clk,      // clock 
    input  logic             rst,      // reset
    input  logic             trigger,
    input  logic             en,
    input  logic [WIDTH-1:0] K,        // Number of clock cycles to delay
    input  logic [WIDTH-1:0] N,        // Used for clock division in clktick
    output logic [7:0]       data_out, // Output from FSM
    output logic             time_out  // Output from delay indicating timeout
);

logic tick;
logic cmd_seq;
logic cmd_delay;

f1_fsm FSM (
    .clk (clk),
    .rst (rst),
    .en (tick),       // FSM is enabled by the tick from clktick
    .trigger(trigger),
    .cmd_seq (cmd_seq),    // FSM will provide this signal to control sequencing
    .cmd_delay (cmd_delay),// FSM will provide this signal to start the delay
    .data_out (data_out)   // Output data from the FSM
);

clktick CLOCK (
    .clk (clk),
    .rst (rst),
    .en (cmd_seq),   // clktick is enabled based on FSM's cmd_seq signal
    .N (N),
    .tick (tick)     // Output tick signal used to drive FSM state changes
);

delay DELAY (
    .clk (clk),
    .rst (rst),
    .trigger (cmd_delay),  // Trigger delay based on FSM's cmd_delay signal
    .n (K),
    .time_out(time_out)    // Output time_out indicating the delay has finished
);

lfsr LFSR (
    .clk (clk),
    .rst (rst),
    .en (en),
    .data_out (data_out) // <-- this needs changing because now its data_out is the same as the FSM's dataout
);

mux2 MUX (
    .d0 (),
    .d1 (),
    .s  (),
    .y  ()
);

endmodule