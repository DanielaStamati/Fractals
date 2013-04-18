CC  = mpicc
FLG = -o
EXE = fractals
SRC = *.c
IN  = test/julia1.in
OUT = out.pgm
MATH = -lm
RUN = mpirun -n 10

all: clean build

build:
  $(CC) $(FLG) $(EXE) $(SRC) $(MATH)

clean:
	rm -rf *~ $(EXE)
