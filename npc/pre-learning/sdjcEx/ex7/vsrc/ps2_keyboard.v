module ps2_keyboard(clk,resetn,ps2_clk,ps2_data,o_reseive_data,o_valid,counter);
    input           clk,resetn,ps2_clk,ps2_data;
    output [7:0]    o_reseive_data;
    output          o_valid;
    output reg [7:0] counter;

    reg [9:0] buffer;        // ps2_data bits
    reg [3:0] count;  // count ps2_data bits
    reg [2:0] ps2_clk_sync;

    assign  o_reseive_data  = buffer[8:1];
    assign  o_valid         = (buffer[0] == 0) && (ps2_data) && (^buffer[9:1]);

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (resetn == 0) begin // reset
            count <= 0;
            counter <= 8'd0;
        end
        else begin
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit
                    (ps2_data)       &&  // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    if (buffer[8:1]!=8'hf0) begin
                      counter <= counter + 1;
                    end
                    else
                      counter <= counter;
                    $display("receive %x", buffer[8:1]);
                end
                count <= 0;     // for next
              end else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
    end

endmodule