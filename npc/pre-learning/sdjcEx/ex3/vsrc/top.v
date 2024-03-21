module top (
	input [3:0]         A,
	input [3:0]         B,
	input [2:0]         sw,

	output [7:0]        hex0,
    output [7:0]        hex1,
    output              overflow
);

wire [3:0] 	result_add, result_sub, result_not0, result_and0, result,
			result_or0, result_xor0, result_cmp, result_eq, result_temp;

wire 		ena_add, ena_sub, ena_not0, ena_and0,
            ena_or0, ena_xor0, ena_cmp, ena_eq;

wire        zero_add, zero_sub;
wire        overflow_add, overflow_sub;
// if module's ena is 0, it will output 4'b0000
assign result_temp  = result_add | result_sub | result_not0 | result_and0 |
                    result_or0 | result_xor0 | result_cmp | result_eq;

assign result[3]    = result_temp[3];
assign result[2:0]  = ({3{!result_temp[3]}} & result_temp[2:0]) | ({3{result_temp[3]}} & (~result_temp[2:0] + 1'b1));

// enable define
assign ena_add 	= !(sw[0] | sw[1] | sw[2]);
assign ena_sub 	= !(!sw[0] | sw[1] | sw[2]);
assign ena_not0	= !(sw[0] | !sw[1] | sw[2]);
assign ena_and0	= !(!sw[0] | !sw[1] | sw[2]);
assign ena_or0	= !(sw[0] | sw[1] | !sw[2]);
assign ena_xor0 = !(!sw[0] | sw[1] | !sw[2]);
assign ena_cmp	= !(sw[0] | !sw[1] | !sw[2]);
assign ena_eq	= sw[0] & sw[1] & sw[2];

bcd7seg seg0 (
    .idata({1'b0, result[2:0]}),
    .enable(1'b1),
    .seg(hex0)
);

assign hex1[7:2]    = 6'b1111_11;
assign hex1[1]      = !result_temp[3];
assign hex1[0]      = 1'b1;

add add(
	.A(A),
	.B(B),
	.ena(ena_add),
	.result(result_add),
    .zero(zero_add),
    .overflow(overflow_add)
);

sub sub(
    .A(A),
    .B(B),
    .ena(ena_sub),
	.result(result_sub),
    .zero(zero_sub),
    .overflow(overflow_sub)
);

assign overflow = (overflow_add & ena_add) | (overflow_sub & ena_sub);

not0 not0(
    .A(A),
    .ena(ena_not0),
	.result(result_not0)
);

and0 and0(
    .A(A),
    .B(B),
    .ena(ena_and0),
	.result(result_and0)
);

or0 or0(
    .A(A),
    .B(B),
    .ena(ena_or0),
	.result(result_or0)
);

xor0 xor0(
    .A(A),
    .B(B),
    .ena(ena_xor0),
	.result(result_xor0)
);

cmp cmp(
    .A(A),
    .B(B),
    .ena(ena_cmp),
	.result(result_cmp)
);

eq eq(
    .A(A),
    .B(B),
    .ena(ena_eq),
	.result(result_eq)
);

endmodule
