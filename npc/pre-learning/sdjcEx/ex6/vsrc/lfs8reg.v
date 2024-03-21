// LFSR (Linear-feedback shift register)
module lfs8reg (
    input               clk,
    input               rst,

    input   [7:0]       idata,

    output  [7:0]       odata
);

reg [7:0]   odata_reg;
reg [7:0]   idata_reg;
wire        move_bit;
assign      move_bit = idata_reg[4] ^ idata_reg[3] ^ idata_reg[2] ^ idata_reg[0];
assign      odata    = odata_reg;

always @(posedge clk or posedge rst) begin
    if(rst)
        odata_reg   <= idata_reg;
    else begin
        odata_reg   <= {move_bit, idata_reg[7:1]};
    end
end

always @(posedge clk or posedge rst) begin
    if(rst)
        idata_reg <= idata;
    else begin
        idata_reg <= odata;
    end
end 

endmodule