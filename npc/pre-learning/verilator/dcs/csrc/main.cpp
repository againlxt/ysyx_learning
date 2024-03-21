#include <nvboard.h>
#include <Vtop.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);

int main() {
	nvboard_bind_all_pins(&dut);
	nvboard_init();

	while(1) {
		nvboard_update();
		int a = rand() & 1;
		int b = rand() & 1;
		dut.a = a;
		dut.b = b;
		dut.eval();
	}
}
