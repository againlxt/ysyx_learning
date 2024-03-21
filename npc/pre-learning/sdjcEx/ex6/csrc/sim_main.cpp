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
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
                  top->A=0b0101;  top->B=0b0101;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b1101;  step_and_dump_wave();
	top->sw=0b001;  top->A=0b0001;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
                  top->A=0b0111;  top->B=0b1101;  step_and_dump_wave();
	top->sw=0b010;  top->A=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  step_and_dump_wave();
                  top->A=0b1001;  step_and_dump_wave();
                  top->A=0b1101;  step_and_dump_wave();
  top->sw=0b011;  top->A=0b0001;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
  top->sw=0b100;  top->A=0b0001;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
	top->sw=0b101;  top->A=0b0001;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
	top->sw=0b110;  top->A=0b0001;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
	top->sw=0b111;  top->A=0b0001;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1011;  top->B=0b0001;  step_and_dump_wave();
                  top->A=0b1001;  top->B=0b0011;  step_and_dump_wave();
                  top->A=0b1101;  top->B=0b0101;  step_and_dump_wave();
	
	sim_exit();
}
