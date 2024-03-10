module top (
    input           clk_but,
    input           reset,
    input   [7:0]   idata,

    output  [7:0]   hex0,
    output  [7:0]   hex1
);

wire [7:0]          moved_data;

lfs8reg lfs (
    .clk(clk_but),
    .rst(reset),
    .idata(idata),

    .odata(moved_data)
);

bcd7seg seg0 (
    .idata(moved_data[3:0]),
    .enable(!reset),

    .seg(hex0)
);

bcd7seg seg1 (
    .idata(moved_data[7:4]),
    .enable(!reset),

    .seg(hex1)
);

endmodule