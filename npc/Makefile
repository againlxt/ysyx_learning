all:
	@echo "Write this Makefile by your self."

sim: sim_main.cpp top.v
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 0 -Wall sim_main.cpp top.v --trace

include ../Makefile
