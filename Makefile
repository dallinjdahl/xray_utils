%.bit:
	vivado -mode batch -source mlib.tcl -tclargs $*

%.fasm: %.bit
	$(XRAY_BIT2FASM) $< > $@

clean:
	rm *webtalk* *.jou *.log
