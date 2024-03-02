#include "Vtop.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
int main(int argc, char** argv) {
	// Create logs/ directory in case we have traces to put under it
	Verilated::mkdir("logs");

	VerilatedContext* contextp = new VerilatedContext;
	
	contextp->commandArgs(argc, argv);
	// Verilator must compute traced signals
	contextp->traceEverOn(true);
	Vtop* top = new Vtop{contextp};

	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	int sim_time = 20;

	while (contextp->time() < sim_time && !contextp->gotFinish()) {
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
		top->eval();
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		assert(top->f == (a ^ b));
	}

	top->final();
	tfp->close();
	return 0;
}
