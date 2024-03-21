module counter (
    input           clk,
    input           reset,
    input           valid,
    output [7:0]    count  
);

reg [7:0]   count_reg;
assign      count = count_reg;

always @(posedge clk or posedge reset or posedge valid) begin
   if (reset) begin
        count_reg <= 8'd0;
   end
   else if (valid) begin
        count_reg <= count_reg + 1;
        $display("receive %x", count_reg);
   end
   else
        count_reg <= count_reg;
end

endmodule