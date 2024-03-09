module cmp(
    input [3:0] A,
    input [3:0] B,
    input 		ena,

    output [3:0] result
);

wire [3:0]  result_temp;
wire        zero;

sub sub0 (
    .A(A),
    .B(B),
    .ena(1),
    .result(result_temp),
    .zero(zero),
    .overflow()
);

assign result[0]    = (~zero) & (result_temp[3]) & ena;
assign result[3:1]  = {3{~zero}} & {3{ena}};

endmodule