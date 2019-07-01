FLAGS= -std=c++11

RM=rm -f

EXEC=transitive_closure

all: $(EXEC)

$(EXEC):
        nvcc $(FLAGS) $(EXEC).cu -o $(EXEC)

clean:
        $(RM) $(EXEC).o $(EXEC)

