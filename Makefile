PRJPATH=$(HOME)/research/btcmpfasm/
%.bit:
	vivado -mode batch -source mlib.tcl -tclargs $*

%.fasm: %.bit
	$(XRAY_BIT2FASM) $< > $@

clean:
	rm *webtalk* *.jou *.log

luttbl: luttbl.c
	gcc $< -o $@

install: luttbl
	cp luttbl $(PRJPATH)
	cp Makefile $(PRJPATH)
	echo "You might want to add the current directory (.) to your path,"
	echo "enabling you to easily run luttbl.  Otherwise put it somewhere
	echo "you can find it, or in your path."
