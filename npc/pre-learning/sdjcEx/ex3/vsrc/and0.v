module and0(
    input [3:0] A,
    input [3:0] B,
    input 		ena,

    output [3:0] result
);

assign result = (A & B) & {4{ena}};

endmodule