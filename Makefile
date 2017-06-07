TARGET = sample
LIBS = -L $(shell ruby -e 'puts RbConfig::CONFIG["libdir"]') $(shell ruby -e 'puts RbConfig::CONFIG["LIBS"] + " " +  RbConfig::CONFIG["LIBRUBYARG_STATIC"]')
INCLUDE = -I $(shell ruby -e 'puts RbConfig::CONFIG["rubyhdrdir"] + File::SEPARATOR + RbConfig::CONFIG["arch"]') -I $(shell ruby -e 'puts RbConfig::CONFIG["rubyhdrdir"]')

all : $(TARGET)

$(TARGET) : sample.c callee.rb
	gcc $(INCLUDE) $(LIBS) -o $(TARGET) sample.c

clean :
	rm -f $(TARGET)
