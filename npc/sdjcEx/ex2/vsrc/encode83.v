module encoder83 (
	input [7:0] 		i_data,
	input 				enable,

	output reg 	[2:0] 	o_data,
	output reg 			o_inputflag
);

always @(*)
begin
	if(!enable)
	begin
		o_data		= 3'b000;
	end
	else
	begin
		if(i_data[7] == 1'b1)		o_data = 3'b111;
		else if(i_data[6] == 1'b1)	o_data = 3'b110;
		else if(i_data[5] == 1'b1)  o_data = 3'b101;
		else if(i_data[4] == 1'b1)  o_data = 3'b100;
		else if(i_data[3] == 1'b1)  o_data = 3'b011;
		else if(i_data[2] == 1'b1)  o_data = 3'b010;
		else if(i_data[1] == 1'b1)  o_data = 3'b001;
		else if(i_data[0] == 1'b1)  o_data = 3'b000;
		else 						o_data = 3'b000;
	end
end

always @(*)
begin
	if(!enable || i_data == 8'd0)	o_inputflag	= 1'b0;
	else							o_inputflag = 1'b1;
end

endmodule
