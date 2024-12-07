CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
CFLAGS = -std=c++11 -Wall -I$(INCLUDE_DIR) -g

EXECUTABLE_FILE = futballFantasy

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

OBJECTS = \
	$(BUILD_DIR)/Player.o \
	$(BUILD_DIR)/List_of_players.o \
	$(BUILD_DIR)/Player_week_info.o \
	$(BUILD_DIR)/League_team.o \
	$(BUILD_DIR)/Team_info.o \
	$(BUILD_DIR)/League_standings.o \
	$(BUILD_DIR)/Team.o \
	$(BUILD_DIR)/Football_team.o \
	$(BUILD_DIR)/Users_football_teams.o \
	$(BUILD_DIR)/Team_week.o \
	$(BUILD_DIR)/Admin.o \
	$(BUILD_DIR)/CommandHandler.o \
	$(BUILD_DIR)/Main.o \

$(BUILD_DIR)/Player.o: $(SRC_DIR)/Player.cpp \

	$(CC) $(CFLAGS) -c $(SRC_DIR)/Player.cpp -o $(BUILD_DIR)/Player.o

$(BUILD_DIR)/List_of_players.o: $(SRC_DIR)/List_of_players.cpp \
							
	$(CC) $(CFLAGS) -c $(SRC_DIR)/List_of_players.cpp -o $(BUILD_DIR)/List_of_players.o

$(BUILD_DIR)/Player_week_info.o: $(SRC_DIR)/Player_week_info.cpp \

	$(CC) $(CFLAGS) -c $(SRC_DIR)/Player_week_info.cpp -o $(BUILD_DIR)/Player_week_info.o
	
$(BUILD_DIR)/League_team.o: $(SRC_DIR)/League_team.cpp \
							$(INCLUDE_DIR)/Player.hpp 		
	$(CC) $(CFLAGS) -c $(SRC_DIR)/League_team.cpp -o $(BUILD_DIR)/League_team.o
	
	
$(BUILD_DIR)/Team_info.o: $(SRC_DIR)/Team_info.cpp \
							
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Team_info.cpp -o $(BUILD_DIR)/Team_info.o
	

$(BUILD_DIR)/League_standings.o: $(SRC_DIR)/League_standings.cpp \
							$(INCLUDE_DIR)/Team_info.hpp  
	$(CC) $(CFLAGS) -c $(SRC_DIR)/League_standings.cpp -o $(BUILD_DIR)/League_standings.o

$(BUILD_DIR)/Team.o: $(SRC_DIR)/Team.cpp \
							$(INCLUDE_DIR)/Player.hpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Team.cpp -o $(BUILD_DIR)/Team.o
	
$(BUILD_DIR)/Football_team.o: $(SRC_DIR)/Football_team.cpp \
							$(INCLUDE_DIR)/Team.hpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Football_team.cpp -o $(BUILD_DIR)/Football_team.o

	
$(BUILD_DIR)/Users_football_teams.o: $(SRC_DIR)/Users_football_teams.cpp \
							$(INCLUDE_DIR)/Player.hpp \
							$(INCLUDE_DIR)/Team.hpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Users_football_teams.cpp -o $(BUILD_DIR)/Users_football_teams.o
	
$(BUILD_DIR)/Team_week.o: $(SRC_DIR)/Team_week.cpp \
							
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Team_week.cpp -o $(BUILD_DIR)/Team_week.o


$(BUILD_DIR)/Admin.o: $(SRC_DIR)/Admin.cpp \
							
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Admin.cpp -o $(BUILD_DIR)/Admin.o

$(BUILD_DIR)/CommandHandler.o: $(SRC_DIR)/CommandHandler.cpp \
							$(INCLUDE_DIR)/Admin.hpp \
							$(INCLUDE_DIR)/List_of_players.hpp \
							$(INCLUDE_DIR)/Users_football_teams.hpp \
							$(INCLUDE_DIR)/League_team.hpp \
							$(INCLUDE_DIR)/League_standings.hpp \
							$(INCLUDE_DIR)/Player_week_info.hpp \
							$(INCLUDE_DIR)/Team_week.hpp 

	$(CC) $(CFLAGS) -c $(SRC_DIR)/CommandHandler.cpp -o $(BUILD_DIR)/CommandHandler.o


$(BUILD_DIR)/Main.o: $(SRC_DIR)/Main.cpp $(INCLUDE_DIR)/CommandHandler.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out
