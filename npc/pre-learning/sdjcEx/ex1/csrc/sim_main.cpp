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

	top->a[0]=0; top->a[1]=0;
	top->b[0]=1; top->b[1]=0;
	top->c[0]=0; top->c[1]=1;
	top->d[0]=1; top->d[1]=1;
	top->s[0]=0; top->s[1]=0; step_and_dump_wave();
	top->s[0]=1; top->s[1]=0; step_and_dump_wave();
	top->s[0]=0; top->s[1]=1; step_and_dump_wave();
	top->s[0]=1; top->s[1]=1; step_and_dump_wave();
	
	sim_exit();
}
