all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	echo "Entre your contents"
	read contents
	cd $(contents)
	echo "entre your *.cpp, *.vcd file"
	read cpp vcd
	verilator --cc --exe --build -j 0 -Wall $(cpp) $(vcd) --trace

include ../Makefile
