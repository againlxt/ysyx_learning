module ascii_rom(
    input       [7:0]   address,
    output reg  [7:0]   data
);

always @(*) begin
    case (address)
        8'h16:  data =  8'd49;
        8'h1E:  data =  8'd50;
        8'h26:  data =  8'd51;
        8'h25:  data =  8'd52;
        8'h2E:  data =  8'd53;
        8'h36:  data =  8'd54;
        8'h3D:  data =  8'd55;
        8'h3E:  data =  8'd56;
        8'h46:  data =  8'd57;
        8'h45:  data =  8'd48;
        8'h1C:  data =  8'd97;
        8'h32:  data =  8'd98;
        8'h21:  data =  8'd99;
        8'h23:  data =  8'd100;
        8'h24:  data =  8'd101;
        8'h2B:  data =  8'd102;
        8'h34:  data =  8'd103;
        8'h33:  data =  8'd104;
        8'h43:  data =  8'd105;
        8'h3B:  data =  8'd106;
        8'h42:  data =  8'd107;
        8'h4B:  data =  8'd108;
        8'h3A:  data =  8'd109;
        8'h31:  data =  8'd110;
        8'h44:  data =  8'd111;
        8'h4D:  data =  8'd112;
        8'h15:  data =  8'd113;
        8'h2D:  data =  8'd114;
        8'h1B:  data =  8'd115;
        8'h2C:  data =  8'd116;
        8'h3C:  data =  8'd117;
        8'h2A:  data =  8'd118;
        8'h1D:  data =  8'd119;
        8'h22:  data =  8'd120;
        8'h35:  data =  8'd121;
        8'h1A:  data =  8'd122;
        default: data=  8'd0;
    endcase
end

endmodule