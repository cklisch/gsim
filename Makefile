CC = g++
CC_FLAGS = -Wall -Wextra -std=c++11

# temporary directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin
IMGDIR = img

# generate target name from enclosing folder
TARGET = $(BINDIR)/$(shell basename `readlink -f .`)

CPP_FILES = $(wildcard $(SRCDIR)/*.cpp)

all: $(TARGET)

# notdir  	strip directory prefix
# :.cpp=.o	replace suffix
$(TARGET): $(addprefix $(OBJDIR)/, $(notdir $(CPP_FILES:.cpp=.o)))
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CC_FLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR) $(IMGDIR)

sim:
	# perform simple simulation with hard compiled parameters
	$(BINDIR)/$(TARGET)
	# render video from image sequence
	ffmpeg -f image2 -i $(IMGDIR)/%05d.bmp -c:v libx264 -crf 0 simulation.mp4