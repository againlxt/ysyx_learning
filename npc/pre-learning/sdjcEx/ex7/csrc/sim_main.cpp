#include "verilated.h"
#include <verilated_vcd_c.h>
#include "Vtop.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vtop* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vtop{contextp};
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  	step_and_dump_wave();
  	tfp->close();
}

int main() {
  sim_init();

	top->sw=0b000;  top->A=0b0100;  top->B=0b0100;  step_and_dump_wave();

	
	sim_exit();
}
