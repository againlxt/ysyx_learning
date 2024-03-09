module top (
	input 	[7:0]	sw,
	input			enable,

	output	[2:0]	led,
	output			led4,
	output	[7:0]	hex0
);

wire [2:0] 	encodered_data;
wire		inputflag;
wire [7:0]	outputseg;

encoder83 ec1 (
	.i_data			(sw),
	.enable			(enable),
	
	.o_data			(encodered_data),
	.o_inputflag	(inputflag)
);

assign led 	= encodered_data;
assign led4 = inputflag;

bcd7seg bcd7seg0 (
	.idata	(encodered_data),
	.enable	(inputflag),

	.seg	(outputseg)
);

assign hex0	= outputseg;

endmodule
