CXX = g++
CPPFLAGS += -Wall -Wextra -Werror -Wno-missing-field-initializers -Wold-style-cast
CXXFLAGS += -g

sources = $(wildcard *.cpp)
headers = $(wildcard *.hpp) $(wildcard *.h)
objects = $(patsubst %.cpp,out/%.o,$(sources))

lab_header_checks  = $(addprefix out/,$(addsuffix .header,$(headers)))

ifneq 'MINGW' '$(patsubst MINGW%,MINGW,$(system))'
CPPFLAGS += -std=c++14
else
CPPFLAGS += -std=gnu++14
endif

ifneq 'yes' '$(VERBOSE)'
hide := @
endif

all: build

run: out/main
	@$(FAULT_INJECTION_CONFIG) $(if $(TIMEOUT),$(TIMEOUT_CMD) --signal=KILL $(TIMEOUT)s )$(if $(VALGRIND),valgrind $(VALGRIND) )$< $(ARGS)

build: out/main

out/main: $(objects) $(lab_header_checks) $(headers)
	$(if $(SILENT),,@echo [LINK] $@)
	$(hide)$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $(filter-out %.header,$^)

$(objects): out/%.o: %.cpp | out/.dir
	$(if $(SILENT),,@echo [C++ ] $<)
	$(hide)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

%/.dir:
	@mkdir -p $(@D) && touch $@

$(lab_header_checks): out/%.header: % | out/.dir
	$(if $(SILENT),,@echo [HDR ] $<)
	$(hide)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -Wno-unused-const-variable -c $< -fsyntax-only $<
	@touch $@

clean:
	rm -rf out
