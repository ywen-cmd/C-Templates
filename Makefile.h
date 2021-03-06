##################################################################
# Makefile with general settings for the book "C++ Templates"
# - is included by each individual Makefile
# - please send updates and suggestions to tmplbook@josuttis.com
##################################################################

########
# GCC settings
########
#GCCFLAGS=-g -Wall -ansi -fhonor-std
GCCFLAGS=-g -ansi -W -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wtraditional -pedantic
# gcc 3.0.2
GCCDIR=/local/gcc/rundir
CXX =  $(GCCDIR)/bin/g++
CXXFLAGS = $(GCCFLAGS)
LIBCPPDIR = $(GCCDIR)/lib
LDFLAGS = -L$(LIBCPPDIR) -Wl,--rpath -Wl,$(LIBCPPDIR) -lm


########
# EDG (and my personal std headers)
########
CXX = /local/edg/bin/eccp --exceptions --strict
CXXFLAGS = -Imystd -I../mystd
LDFLAGS = -lm

########
# Microsoft Visual C++
########
CXX = cl /Za /Zc:forScope,wchar_t
CXXFLAGS =
LDFLAGS = 


##################################################################

help::
	@echo "all:    progs"

all:: progs

.SUFFIXES: .ctt .htt .cpp .hpp

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp
.o:
	$(CXX) $*.o $(LDFLAGS) -o $*

help::
	@echo 'progs:  create all in $$(PROGS) and in $$(OUTPROGS)'
	@echo "        (failed progs in MAKE.LOG)"
progs::
	@cat /dev/null > MAKE.LOG
	@if test "$(PROGS)" != "" ; \
	then \
	    for PROG in $(PROGS)""; \
	    do \
	        echo "MAKE $$PROG"; \
	        mingw32-make $$PROG || echo " + mingw32-make $$PROG failed !!!" >> MAKE.LOG; \
	    done; \
	fi
	@if test "$(OUTPROGS)" != "" ; \
	then \
	    for PROG in $(OUTPROGS)""; \
	    do \
	        echo "MAKE $$PROG"; \
	        mingw32-make $$PROG || echo " + mingw32-make $$PROG failed !!!" >> MAKE.LOG; \
	    done; \
	fi
	@if test -s MAKE.LOG ; \
	then \
	    echo "failures:"; \
	    cat MAKE.LOG; \
	else \
	    echo "no failure"; \
	fi

help::
	@echo 'clean:  clean all generated'
clean::
	rm -rf MAKE.LOG *.o *.exe *.ii *.ti *~
	rm -rf $(PROGS) $(OUTPROGS)
	@for DATEI in *.ctt; \
	do \
	    BASE=`basename $$DATEI .ctt`; \
	    if test -r $$BASE.cpp; \
	    then \
	        echo " remove $$BASE.cpp"; \
		rm $$BASE.cpp; \
	    fi; \
	    if test -x $$BASE; \
            then \
                echo " remove $$BASE"; \
                rm $$BASE; \
            fi; \
	done
	@for DATEI in *.cpp; \
	do \
	    BASE=`basename $$DATEI .cpp`; \
	    if test -x $$BASE; \
            then \
                echo " remove $$BASE"; \
                rm $$BASE; \
            fi; \
	done
	@for DATEI in *.htt; \
	do \
            BASE=`basename $$DATEI .htt`; \
            if test -r $$BASE.hpp; \
            then \
                echo " remove $$BASE.hpp"; \
                rm $$BASE.hpp; \
            fi; \
	done

