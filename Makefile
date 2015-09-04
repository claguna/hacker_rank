CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all:$(OBJ_FILES)
	g++ -o $@ $^

obj/%.o: %cpp
	g++ -c -o $@ $<

clean:
	find -maxdepth 1 -executable | xargs rm ; rm *cpp~ *~

