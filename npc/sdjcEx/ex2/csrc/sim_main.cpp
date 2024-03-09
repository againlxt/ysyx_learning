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

	top->enable=0b0; 	top->sw=0b00000000; step_and_dump_wave();
						top->sw=0b00000001; step_and_dump_wave();
						top->sw=0b00000011; step_and_dump_wave();
						top->sw=0b00000111; step_and_dump_wave();
						top->sw=0b00001111; step_and_dump_wave();
						top->sw=0b00011111; step_and_dump_wave();
						top->sw=0b00111111; step_and_dump_wave();
						top->sw=0b01111111; step_and_dump_wave();
						top->sw=0b11111111; step_and_dump_wave();
	top->enable=0b1;    top->sw=0b00000000; step_and_dump_wave();
                        top->sw=0b00000001; step_and_dump_wave();
                        top->sw=0b00000011; step_and_dump_wave();
                        top->sw=0b00000111; step_and_dump_wave();
                        top->sw=0b00001111; step_and_dump_wave();
                        top->sw=0b00011111; step_and_dump_wave();
                        top->sw=0b00111111; step_and_dump_wave();
                        top->sw=0b01111111; step_and_dump_wave();
                        top->sw=0b11111111; step_and_dump_wave();
	sim_exit();
}
