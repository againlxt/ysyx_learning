module top(
	input	a[1:0], b[1:0], c[1:0], d[1:0], s[1:0],
	output	y[1:0]
);
	MuxKeyWithDefault #(4, 2, 2) i0 ( {y[1], y[0]}, {s[1], s[0]}, 2'b00, {
		2'b00, a[1], a[0],
		2'b01, b[1], b[0],
		2'b10, c[1], c[0],
		2'b11, d[1], d[0]
	});
endmodule
