module top(
    input           clk, 
    input           reset,
    input           ps2_clk,
    input           ps2_data,
    output [7:0]    hex0,
    output [7:0]    hex1,
    output [7:0]    hex2,
    output [7:0]    hex3,
    output [7:0]    hex4,
    output [7:0]    hex5
);

wire [7:0]  reseive_data;
wire        valid;
wire [7:0]  count;
wire        end_flag;
reg         end_flag_reg;
reg  [7:0]  reseive_data_reg;
wire [7:0]  encoded_data;

assign  end_flag = end_flag_reg;

always @(posedge clk or posedge reset or posedge valid) begin
    if (reset) begin
        reseive_data_reg    <= 8'b0000_0000;
    end
    else if (valid) begin
        reseive_data_reg    <= reseive_data;
    end
    else
        reseive_data_reg    <= reseive_data_reg;
end

assign      end_flag = end_flag_reg;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        end_flag_reg    <= 1'b1;
    end
    else if (reseive_data == 8'b1111_0000 && valid == 1'b1) begin
        end_flag_reg    <= 1'b1;
    end
    else if (reseive_data != 8'b1111_0000 && valid == 1'b1) begin
        end_flag_reg    <= 1'b0;
    end
    else
        end_flag_reg    <= end_flag_reg;
end

ps2_keyboard kb0 (
    .clk(clk),
    .resetn(~reset),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .counter(count),
    .o_reseive_data(reseive_data),
    .o_valid(valid)
);

ascii_rom rom0 (
    .address(reseive_data),
    .data(encoded_data)
);

bcd7seg seg0 (
    .idata(reseive_data_reg[3:0]),
    .enable(!reset),
    .endflag(end_flag),
    .seg(hex0)
);

bcd7seg seg1 (
    .idata(reseive_data_reg[7:4]),
    .enable(!reset),
    .endflag(end_flag),
    .seg(hex1)
);

bcd7seg seg2 (
    .idata(encoded_data[3:0]),
    .enable(!reset),
    .endflag(end_flag),
    .seg(hex2)
);

bcd7seg seg3 (
    .idata(encoded_data[7:4]),
    .enable(!reset),
    .endflag(end_flag),
    .seg(hex3)
);

bcd7seg seg4 (
    .idata(count[3:0]),
    .enable(!reset),
    .endflag(1'b0),
    .seg(hex4)
);

bcd7seg seg5 (
    .idata(count[7:4]),
    .enable(!reset),
    .endflag(1'b0),
    .seg(hex5)
);

endmodule