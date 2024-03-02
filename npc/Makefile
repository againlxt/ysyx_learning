all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	echo "entre your *.cpp, *.vcd file"
	read cpp vcd
	verilator --cc --exe --build -j 0 -Wall $(cpp) $(vcd) --trace

include ../Makefile
