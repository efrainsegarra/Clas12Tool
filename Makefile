all: 
	@cd Lz4 ; make
	@cd Hipo; make
	@cd Utils; make

clean:
	@cd Lz4; make clean
	@cd Hipo; make clean
	@cd Utils; make clean
