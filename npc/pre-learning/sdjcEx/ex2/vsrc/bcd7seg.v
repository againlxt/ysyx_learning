module bcd7seg #(DATA_WIDTH = 3)(
	input		[DATA_WIDTH-1:0]	idata,
	input							enable,
	output reg	[7:0]				seg
);
	always @(*)
	begin
		if(!enable)
			seg	= 8'b0000_0000;
		else
		begin
			case (idata)
				3'd0:		seg = 8'b1111_1101;
				3'd1:		seg = 8'b0110_0000;
				3'd2:		seg = 8'b1101_1010;
				3'd3:		seg = 8'b1111_0010;
				3'd4:		seg = 8'b0110_0110;
				3'd5:		seg = 8'b1011_0110;
				3'd6:		seg = 8'b1011_1110;
				3'd7:		seg = 8'b1110_0000;
				default:	seg = 8'b0000_0000;
			endcase
			seg = ~seg;
		end
	end
endmodule
