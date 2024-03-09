module add (
	input [3:0] A,
    input [3:0] B,
    input 		ena,

    output [3:0] result,
	output zero,
	output overflow
);

wire [3:0] result_temp;
wire overflow_temp;
assign {overflow_temp, result_temp} = {A[3], A} + {B[3], B};
assign zero                         = ~(|{overflow_temp, result_temp});
assign result                       = {overflow_temp ,result_temp[2:0]} & {4{ena}};
assign overflow                     = overflow_temp ^ result_temp[3];

endmodule
