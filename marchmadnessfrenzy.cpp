/* ---------------------------------------------
March Madness Frenzy
Program analyzes the March Madness tournament for men or women
Author: Sami Abushamat
---------------------------------------------
*/
#include <algorithm> // For count() use
#include <cassert>   // For asserting file is open
#include <fstream>   // For File Input Output
#include <iostream>  // For Input Output
#include <sstream>   // For csv manipulation
#include <string>    // For String Use
#include <vector>    // For Vector Use
using namespace std;

// Class for each game and its attributes
class GameRecord {
private:
  string region;
  int rank1;
  string team1;
  int score1;
  int rank2;
  string team2;
  int score2;
  string winningTeam;
  int roundNumber;
  int gameNumber;

public:
  // Default Constructor
  GameRecord() {
    region = "Region";
    rank1 = 0;
    team1 = "Team 1";
    score1 = 0;
    rank2 = 0;
    team2 = "Team 2";
    score2 = 0;
    winningTeam = "Winning Team";
    roundNumber = 0;
    gameNumber = 0;
  }

  //Fully Quantified Constructor
  GameRecord(string Region, int Rank1, string Team1,int Score1,int Rank2,string Team2,int Score2,string WinningTeam,int RoundNumber, int GameNumber)
  {
    region = Region;
    rank1 = Rank1;
    team1 = Team1;
    score1 = Score1;
    rank2 = Rank2;
    team2 = Team2;
    score2 = Score2;
    winningTeam = WinningTeam;
    roundNumber = RoundNumber;
    gameNumber = GameNumber;
  }

  void displayGame();
  void setRegion(string region);
  string getRegion();
  void setRank1(int rank);
  int getRank1();
  void setTeam1(string team);
  string getTeam1();
  void setScore1(int score);
  int getScore1();
  void setRank2(int rank);
  int getRank2();
  void setTeam2(string team);
  string getTeam2();
  void setScore2(int score);
  int getScore2();
  void setWinningTeam(string winningTeam);
  string getWinningTeam();
  void setRoundNumber(int roundNumber);
  int getRoundNumber();
  void setGameNumber(int gameNumber);
  int getGameNumber();
};

//Getters and Setters
void GameRecord ::setRegion(string region) { this->region = region;}

string GameRecord ::getRegion() { return this->region;}

void GameRecord ::setRank1(int rank) { this->rank1 = rank;}

int GameRecord ::getRank1() { return this->rank1;}

void GameRecord ::setTeam1(string team) { this->team1 = team;}


string GameRecord ::getTeam1() { return this->team1;}

void GameRecord ::setScore1(int score) { this->score1 = score;}


int GameRecord ::getScore1() { return this->score1;}


void GameRecord ::setRank2(int rank) { this->rank2 = rank;}


int GameRecord ::getRank2() { return this->rank2;}


void GameRecord ::setTeam2(string team) { this->team2 = team;}


string GameRecord ::getTeam2() { return this->team2;}


void GameRecord ::setScore2(int score) { this->score2 = score;}

int GameRecord ::getScore2() { return this->score2;}


void GameRecord ::setWinningTeam(string winningTeam) { this->winningTeam = winningTeam;}


string GameRecord ::getWinningTeam() { return this->winningTeam;}


void GameRecord ::setRoundNumber(int roundNumber) { this->roundNumber = roundNumber;}


int GameRecord ::getRoundNumber() { return this->roundNumber;}


void GameRecord ::setGameNumber(int gameNumber) { this->gameNumber = gameNumber;}


int GameRecord ::getGameNumber() { return this->gameNumber;}


// Utility Function
void GameRecord ::displayGame() {
  cout << "Region: "<< this->region<<endl;
  cout << "Team 1: "<<this->team1<<endl;
  cout << "Score 1: "<<this->score1<<endl;
  cout << "Rank 2: "<<this->rank2<<endl;
  cout << "Team 2: "<<this->team2<<endl;
  cout << "Score 2: "<<this->score2<<endl;
  cout << "Winning Team: "<<this->winningTeam<<endl;
  cout << "Round Number: "<<this->roundNumber<<endl;
  cout << "Game Number: "<<this->gameNumber<<endl;
}


// Function to take data from requested file and push back each game as an
// instance of a class to a vector
void readDataIntoClass(string fileName, vector<GameRecord> &gameData) {
  ifstream inputFile;
  inputFile.open(fileName);
  string line = "";
  while (getline(inputFile, line)) {
    stringstream inputString(line);
    // Instance of class
    GameRecord game;
    // Vars correlating to the class
    string region;
    int rank1;
    string team1;
    int score1;
    int rank2;
    string team2;
    int score2;
    string winningTeam;
    int roundNumber;
    int gameNumber;
    string tempString;
    // Get lines for each comma then assigning those values to the instance of
    // the class
    getline(inputString, region, ',');
    game.setRegion(region);
    getline(inputString, tempString, ','); // int
    rank1 = atoi(tempString.c_str());
    game.setRank1(rank1);
    getline(inputString, team1, ','); // string
    game.setTeam1(team1);
    getline(inputString, tempString, ','); // int
    score1 = atoi(tempString.c_str());
    game.setScore1(score1);
    getline(inputString, tempString, ','); // int
    rank2 = atoi(tempString.c_str());
    game.setRank2(rank2);
    getline(inputString, team2, ','); // string
    game.setTeam2(team2);
    getline(inputString, tempString, ',');
    score2 = atoi(tempString.c_str()); // int
    game.setScore2(score2);
    getline(inputString, winningTeam, ','); // string
    game.setWinningTeam(winningTeam);
    getline(inputString, tempString,',');
    roundNumber = atoi(tempString.c_str());
    game.setRoundNumber(roundNumber);
    getline(inputString, tempString,',');
    gameNumber = atoi(tempString.c_str());
    game.setGameNumber(gameNumber);
    // Pushing back each game and its data
    gameData.push_back(game);
    // clearing line
    line = "";
  }
  inputFile.close();
}


//Function to display overall stats of tournament
void displayOverallStats(vector<GameRecord>& gameData) {
  int gamesPlayed;
  //Size of vector is the amount of games played in the tournament minus 1 because of header line
  gamesPlayed = gameData.size()-1;
  string westTeam, eastTeam, southTeam, midWestTeam;
  cout << endl << "Total number of games played in tournament: " << gamesPlayed << endl;
  cout<<"The Final Four contestants are: "<<endl;
    
  for (int i = 1; i < gameData.size(); i++) {
     //finding the winners of the elite eight those who move to final four and their region
    if (gameData.at(i).getRoundNumber() == 4) {
       cout<< gameData.at(i).getRegion()<<" region: "<<gameData.at(i).getWinningTeam()<<endl;
    }
  }
}


//Function to find the path to victory 
void pathToVictory(vector<GameRecord>& gameData) {
   //Finding the winner of the whole tournament
   string winningTeam = gameData.at(1).getWinningTeam();
   cout<<"Path to the championship:"<<endl;
   //Looping through the vector from round 6-1 instead of 1-6
   for(int i=gameData.size()-1; i > 0;i--) {
      // if statement looking for all of the games that the tournament winner won
      int gameNumber = gameData.at(i).getGameNumber();
      if(gameData.at(i).getWinningTeam() == winningTeam) {
         // Once found outputting in the correct format
         cout<<"Round "<<gameData.at(i).getRoundNumber()<<", "<<"Game "<<gameData.at(i).getGameNumber()<<": "<< gameData.at(i).getTeam1()<<" vs "<<gameData.at(i).getTeam2()<<". "<<"Winner: "<< winningTeam<<endl;
      } else {
         continue;
      }
   }
}


//Function to find the region most likely to win
void regionToWin(int roundChosen, vector<GameRecord> &gameData) {
   //vars for data holding
   cout<<"Analyzing round "<< roundChosen<<" ..."<<endl;
   string regionToWin;
   vector<GameRecord> gamesInChosenRound;
   // paralle vectors to store region names and their combined ranks
   vector<int> regionRanks;
   vector<string> regionNames;
   //count for each region
   int westCount = 0;
   int eastCount = 0;
   int southCount = 0;
   int midwestCount = 0;
   int greensboroCount = 0;
   int wichitaCount = 0;
   int spokaneCount = 0;
   int bridgeportCount = 0;
   //pushing back all of the region names as strings
   regionNames.push_back("West");
   regionNames.push_back("East");
   regionNames.push_back("South");
   regionNames.push_back("Midwest");
   regionNames.push_back("Greensboro");
   regionNames.push_back("Wichita");
   regionNames.push_back("Spokane");
   regionNames.push_back("Bridgeport");
    
   // looking for games in chosen round
   for(int i = 1; i < gameData.size();i++) {
      // if round is 5 look at round 4 for the region count
      if(roundChosen == 5) {
         roundChosen = 4;
      }
      //pushing back correlating games
       if(roundChosen == gameData.at(i).getRoundNumber()) {
         gamesInChosenRound.push_back(gameData.at(i));
      } else {
         continue;
      }
   }  

//For loops to iterate games and check if the region is matching 
   for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "West")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
         westCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "West")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
          westCount += gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
     for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "East")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
         eastCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "East")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         eastCount+= gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
     for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "South")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1()))
      {
         southCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "South")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         southCount+= gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
     for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "Midwest")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
         midwestCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "Midwest")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         midwestCount+= gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
    for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
        if((gamesInChosenRound.at(i).getRegion() == "Greensboro")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
            greensboroCount += gamesInChosenRound.at(i).getRank1();
        } else if((gamesInChosenRound.at(i).getRegion() == "Greensboro")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         greensboroCount += gamesInChosenRound.at(i).getRank2();
        } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
     for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "Wichita")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
         wichitaCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "Wichita")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         wichitaCount+= gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
     for(int i = 0; i < gamesInChosenRound.size();i++) {
      // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "Spokane")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
         spokaneCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "Spokane")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         spokaneCount+= gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //For loops to iterate games and check if the region is matching
     for(int i = 0; i < gamesInChosenRound.size();i++) {
            // If statement to see if team1 or team 2 won and adding that teams rank to the count depending on which team won
      if((gamesInChosenRound.at(i).getRegion() == "Bridgeport")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam1())) {
         bridgeportCount += gamesInChosenRound.at(i).getRank1();
      } else if((gamesInChosenRound.at(i).getRegion() == "Bridgeport")&&(gamesInChosenRound.at(i).getWinningTeam() == gamesInChosenRound.at(i).getTeam2())) {
         bridgeportCount+= gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
    
   //Pushing back all of the counts in order of the region names
   regionRanks.push_back(westCount);
   regionRanks.push_back(eastCount);
   regionRanks.push_back(southCount);
   regionRanks.push_back(midwestCount);
   regionRanks.push_back(greensboroCount);
   regionRanks.push_back(wichitaCount);
   regionRanks.push_back(spokaneCount);
   regionRanks.push_back(bridgeportCount);
    
   // setting smallest rank to impossible number to compare to
   int smallestRank = 100 ;
   // For loop to find the region with the smallest total ranks
   for(int i = 0; i < regionRanks.size();i++) {
      // if the region is 0 skip (to compare men and women region in the same loop)
      if(regionRanks.at(i) == 0) {
         continue;
      }
      //if the region is smaller than value, value become region value
      //then regions name is taken for the output statemen
      if(smallestRank > regionRanks.at(i)) {
         smallestRank = regionRanks.at(i);
         regionToWin = regionNames.at(i);
      } else {
         continue;
      }
   }
   //Outputting answer in correct format
   cout<<"The region expected to win is: "<<regionToWin<<endl;
}


//Function to find the biggest underdog based on the selected round
void biggestUnderdog(int roundChosen, vector<GameRecord>& gameData) {
    // local vars
   string underDogTeam;
   int underDogTeamRank;
   int biggestDifference = 0;
   int biggestDifferenceIndex = 0;
   vector<GameRecord> gamesInChosenRound;
   //For loop to find the games in the correct / chosen round
   for(int i = 1; i < gameData.size();i++) {
      if(roundChosen == gameData.at(i).getRoundNumber()) {
         gamesInChosenRound.push_back(gameData.at(i));
      } else {
         continue;
      }
   }
   // for loop to find which teams rank if larger to assure correct math
   for(int i = 0; i < gamesInChosenRound.size();i++) {
      int difference = 0;
      int team1or2;
      // if the second teams rank is larger than the first then rank2 - rank1
      if((gamesInChosenRound.at(i).getRank2() >gamesInChosenRound.at(i).getRank1())) {
         difference = gamesInChosenRound.at(i).getRank2() - gamesInChosenRound.at(i).getRank1();
         team1or2 = 2;
      }
      // if the first teams rank is larger than the second teams rank then rank 1-rank2
      else if((gamesInChosenRound.at(i).getRank1() > gamesInChosenRound.at(i).getRank2())) {
         difference = gamesInChosenRound.at(i).getRank1() - gamesInChosenRound.at(i).getRank2();
         team1or2 = 1;
      }
      // if the difference is larger that the value it replaces it and the index is taken, if the lower ranked team is under team1 then that teams rank and name would be taken
      if((difference >= biggestDifference)&&( team1or2 == 1)&& gamesInChosenRound.at(i).getRank1() > underDogTeamRank) {
         biggestDifference = difference;
         biggestDifferenceIndex = i;
         underDogTeam = gamesInChosenRound.at(i).getTeam1();
         underDogTeamRank = gamesInChosenRound.at(i).getRank1();
      }
       //if the difference is larger than value it replaces it and the index is take, if the lower rank is under team2 then rank 2 and team 2 names are taken down
      else if ((difference >= biggestDifference) && (team1or2 ==2)&&(gamesInChosenRound.at(i).getRank2() > underDogTeamRank)) {
         biggestDifference = difference;
         biggestDifferenceIndex = i;
         underDogTeam = gamesInChosenRound.at(i).getTeam2();
         underDogTeamRank = gamesInChosenRound.at(i).getRank2();
      } else {
         continue;
      }
   }
   // outputting the answer in corrrect format
   cout<<"The best underdog team is "<< underDogTeam <<" which has rank "<<underDogTeamRank<<"."<<endl;
}


//function for shoo in or nail biter game in a given/ chosen round
void shooInOrNailBiter(int chosenRound,vector<GameRecord>& gameData)
{
    //local vars
   vector<GameRecord> gamesInChosenRound;
   int smallestDifference = 100;
   int smallestDifferenceIndex = 0;
   int largestDifference = 0;
   int largestDifferenceIndex = 0;
    
   //if the overall tournament is chosen the the correct output would be outputted
   if(chosenRound == 7) {
      cout<<"Analyzing the overall tournament ..."<<endl;
      //pushing back all games in to vector
      for(int i = 1; i<gameData.size();i++) {
         gamesInChosenRound.push_back(gameData.at(i));
      }
   } else {
       // outputting which round is being analyzed
      cout<<"Analyzing round "<<chosenRound<<" ..."<<endl;
      //pushing back games with correct round
      for(int i = 1; i <gameData.size();i++) {
         if(gameData.at(i).getRoundNumber() == chosenRound) {
            gamesInChosenRound.push_back(gameData.at(i));
         } else {
            continue;
         }
      }
   }
    
   // looping through all games and finding which game had the highest difference or smallest difference
   for(int i = 0 ; i <gamesInChosenRound.size();i++) {
          //var
         int difference = 0;
         //finding which team had the higher score for correct calculations
         if(gamesInChosenRound.at(i).getScore1() > gamesInChosenRound.at(i).getScore2()) {
            difference = gamesInChosenRound.at(i).getScore1() - gamesInChosenRound.at(i).getScore2();
         } else if(gamesInChosenRound.at(i).getScore2() > gamesInChosenRound.at(i).getScore1()) {
             difference = gamesInChosenRound.at(i).getScore2() - gamesInChosenRound.at(i).getScore1();
         }
         // if the difference is greater than the value then it would be taken down along with the games index
         if(difference > largestDifference) {
            largestDifference = difference;
            largestDifferenceIndex = i;
         }
         // if the difference is smaller thatn the value then it woud be taken down along with the games index
         if(difference < smallestDifference) {
            smallestDifference = difference;
            smallestDifferenceIndex = i;
         } else {
            continue;
         }
      }
      // outputting answer in correct format
      cout<<"The shoo-in game was: "<<endl;
      //outputting game with largest difference
      cout<<"Round "<<gamesInChosenRound.at(largestDifferenceIndex).getRoundNumber()<<", Game "<<gamesInChosenRound.at(largestDifferenceIndex).getGameNumber()<<": "<<gamesInChosenRound.at(largestDifferenceIndex).getTeam1()<<" vs "<<gamesInChosenRound.at(largestDifferenceIndex).getTeam2()<<". Winner: "<<gamesInChosenRound.at(largestDifferenceIndex).getWinningTeam()<<endl;
      cout<<"The difference was " << largestDifference<<" points."<<endl;
      cout<< "The nail-biting game was: "<<endl;
      // outputting game with smallest differnce
      cout<<"Round "<<gamesInChosenRound.at(smallestDifferenceIndex).getRoundNumber()<<", Game "<<gamesInChosenRound.at(smallestDifferenceIndex).getGameNumber()<<": "<<gamesInChosenRound.at(smallestDifferenceIndex).getTeam1()<<" vs "<<gamesInChosenRound.at(smallestDifferenceIndex).getTeam2()<<". Winner: "<<gamesInChosenRound.at(smallestDifferenceIndex).getWinningTeam()<<endl;
      cout<<"The difference was " << smallestDifference<<" points."<<endl;
}

//function to compare someones prediction of the bracket
void comparePredictions(vector<GameRecord> gameData,vector<GameRecord> predictionGameData) {
    // vars
  int correctWinningTeams = 0;
  int totalScore = 0;
  // looping through prediction and actual bracket and if the winning team is the same for both files the variable is incremented accordingly
  for(int i = 1; i< predictionGameData.size();i++) {
    if(predictionGameData.at(i).getWinningTeam() == gameData.at(i).getWinningTeam()) {
        // taking score by multiplying round number by 5 and adding it to the total score
       totalScore += gameData.at(i).getRoundNumber()*(5);
       correctWinningTeams++;
    }
  }
    
  //outputting the correct answer in correct format
  cout<<"You correctly predicted the winner for "<<correctWinningTeams<<" games."<<endl;
  cout<<"This means that you have a score of "<< totalScore<<"."<<endl;
    
  // if predictions score is above 250 handle condition and output positive message
  if(totalScore >= 250) {
     cout<<"Great job! You could consider entering your predictions to win money!"<<endl;
  } else { // other than that output negative message
     cout<<"You may want to learn more about basketball to improve your predictions next year."<<endl;
  }

}
// main
int main() {
    //vars
  int userInput;
  string fileName;
  vector<GameRecord> gameData;
  vector<GameRecord> predictionGameData;
    
    
    //prompting programs functionality
  cout << "March Madness Frenzy" << endl;
  cout << "This program reads in data from NCAA Basketball Tournaments (aka "
          "March Madness). It provides overall information regarding the data, "
          "allows you to see the path taken to the championship, uses rankings "
          "of teams to determine which region is expected to win at a given "
          "round and to find the best underdog team, and calculates point "
          "differences within the games. You can also compare the actual "
          "brackets to your own predictions!"
       << endl;
       // asking for the name of the file requested
  cout << "Enter the name of the file with the data for the NCAA tournament: "
       << endl;
  cin>> fileName;
  //reading file into vector
    readDataIntoClass(fileName, gameData);
    // while loop to break out when 7 is inputted
      while (userInput != 7) {
          //prompting menu selections
    cout << "Select a menu option: \n"
         << "   1. Display overall information about the data \n"
         << "   2. Display the path of the winning team to the championship \n"
         << "   3. Determine which region is expected to win the championship "
            "based on a given round \n"
         << "   4. Identify the best underdog within a given round \n"
         << "   5. Find the shoo-in and nail-biting games within a given round, "
            "or overall \n"
         << "   6. Compare the actual brackets to your predicted brackets \n"
         << "   7. Exit \n"
         << "Your choice --> ";
    cin >> userInput;
    //breaking if option is 7
    if (userInput == 7) {
      cout << "Exiting program ...";
      break;
     } else if (userInput == 1) { // if option is 1 display overall stats
        displayOverallStats(gameData);
     } else if (userInput == 2) { //if option is 2 display path to victory
       pathToVictory(gameData);
     } else if (userInput == 3) { // if option is 3 display region to win after asking which round to analyze
       int roundChosen;
       cout<<"Enter a round to be evaluated: "<<endl;
       cout<<"\t Select 2 for round 2"<<endl;
       cout<<"\t Select 3 for round 3 'Sweet 16'"<<endl;
       cout<< "\t Select 4 for round 4 'Elite 8'"<<endl;
       cout<<"\t Select 5 for round 5 'Final 4'"<<endl;
       cout<<"Your choice -->";
       cin>> roundChosen;
       regionToWin(roundChosen,gameData);
     }  else if (userInput == 4) { // if option is 4 display biggest underdog after prompting which round to analyze
       int roundChosen;
       cout<<"Enter a round to be evaluated: "<<endl;
       cout<<"\t Select 2 for round 2"<<endl;
       cout<<"\t Select 3 for round 3 'Sweet 16'"<<endl;
       cout<< "\t Select 4 for round 4 'Elite 8'"<<endl;
       cout<<"\t Select 5 for round 5 'Final 4'"<<endl;
       cout<<"\t Select 6 for round 6 'Championship'"<<endl;
       cout<<"Your choice -->";
       cin>> roundChosen;
       biggestUnderdog(roundChosen,gameData);
     } 
     // if option is 5 dsiplay shoo in and nail biter game after prompting which round to analyze
    else if (userInput == 5) {
       int roundChosen;
       cout<<"Enter a round to be evaluated: "<<endl;
       cout<<"\t Select 1 for round 1"<<endl;
       cout<<"\t Select 2 for round 2"<<endl;
       cout<<"\t Select 3 for round 3 'Sweet 16'"<<endl;
       cout<< "\t Select 4 for round 4 'Elite 8'"<<endl;
       cout<<"\t Select 5 for round 5 'Final 4'"<<endl;
       cout<<"\t Select 6 for round 6 'Championship'"<<endl;
       cout<<"\t Select 7 for the overall tournament"<<endl;
       cout<<"Your choice -->";
       cin>> roundChosen;  
       shooInOrNailBiter(roundChosen,gameData);
     } else if (userInput == 6) { //if option is 6 display prediction comparison
       string predictionFileName;
       cout<<endl<<"Enter the name of the file with your predicted brackets: "<<endl;
       cin>> predictionFileName;
       predictionGameData.clear();
       readDataIntoClass(predictionFileName,predictionGameData);
       comparePredictions(gameData,predictionGameData);
     } else { // if an invalid integer is selected
      cout << "Invalid value.  Please re-enter a value from the menu options below." << endl;
     }
  }
  return (0);
}
