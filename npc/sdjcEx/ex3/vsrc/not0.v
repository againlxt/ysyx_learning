module not0 (
    input [3:0] A,
    input 		ena,

    output [3:0] result
);

assign result = {4{ena}} & (~A);

endmodule