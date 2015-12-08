TARGET = gsim
CC = g++-5
CC_FLAGS = -Wall -Wextra -std=c++11

# temporary directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin
IMGDIR = img

CPP_FILES = $(wildcard $(SRCDIR)/*.cpp)
all: $(TARGET)

# notdir  	strip directory prefix
# :.cpp=.o	replace suffix
$(TARGET): $(addprefix $(OBJDIR)/, $(notdir $(CPP_FILES:.cpp=.o)))
	mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CC_FLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR) $(IMGDIR)

sim:
	# perform simple simulation with hard compiled parameters
	bin/$(TARGET) $(IMGDIR)
	# render video from image sequence
	ffmpeg -f image2 -i $(IMGDIR)/%05d.bmp -c:v libx264 -crf 0 simulation.mp4