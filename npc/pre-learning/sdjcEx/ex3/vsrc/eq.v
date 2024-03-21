module eq(
    input [3:0] A,
    input [3:0] B,
    input 		ena,

    output [3:0] result
);

wire        zero;

sub sub0 (
    .A(A),
    .B(B),
    .ena(1),
    .result(),
    .zero(zero),
    .overflow()
);

assign result = {4{zero}} & {4{ena}};

endmodule