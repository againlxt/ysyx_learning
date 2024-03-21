module bcd7seg (
	input		[3:0]				idata,
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
				4'd0:		seg = 8'b1111_1100;
				4'd1:		seg = 8'b0110_0000;
				4'd2:		seg = 8'b1101_1010;
				4'd3:		seg = 8'b1111_0010;
				4'd4:		seg = 8'b0110_0110;
				4'd5:		seg = 8'b1011_0110;
				4'd6:		seg = 8'b1011_1110;
				4'd7:		seg = 8'b1110_0000;
                4'd8:       seg = 8'b1111_1110;
                4'd9:       seg = 8'b1111_0110;
                4'd10:      seg = 8'b1110_1110;
                4'd11:      seg = 8'b0011_1110;
                4'd12:      seg = 8'b1001_1100;
                4'd13:      seg = 8'b0111_1010;
                4'd14:      seg = 8'b1001_1110;
                4'd15:      seg = 8'b1000_1110;
				default:	seg = 8'b0000_0000;
			endcase
			seg = ~seg;
		end
	end
endmodule