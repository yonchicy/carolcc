MAKEFLAGS += -j 20
vpath %.cpp src
vpath %.cpp src/frontend

CC :=g++
CPPFLAGS := -std=c++17 -O2
SOURCE := $(wildcard src/*.cpp src/frontend/*.cpp)
OBJECTS :=$(patsubst %.cpp,build/%.o,$(notdir $(SOURCE)))
DEPENDS :=$(patsubst %.o,%.d,$(OBJECTS))
TARGETS := build/easycc

$(shell mkdir -p build)

.PHONY:all

all: $(TARGETS) scanner
	@echo build finish
run:all
	@ ./build/easycc
$(TARGETS) :$(OBJECTS)
	$(CC) $(CPPFLAGS) -lm $^ -o $@

scanner:src/frontend/parser.cpp src/frontend/token.cpp

src/frontend/parser.cpp:src/frontend/parser.y
	bison -o $@ -d -Wcounterexamples $< 

src/frontend/token.cpp:src/frontend/token.l
	flex -o $@ $<

build/%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

-include $(DEPENDS)

build/%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,build/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -r $@.$$$$

.PHONY:clean
clean:
	@rm -r build/* ||true

.PHONY:test
test:
	cd test && ./test.sh
