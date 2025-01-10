#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define QUESTION_COUNT 15

//Blueprint for() {} the struct:
typedef struct qst
{
  char correctAnswer;
  char question[100];
  char answer1[100];
  char answer2[100];
  char answer3[100];
  char answer4[100];
} qst;

//Making the struct that'll be used throughout the game:
struct qst currentQuestion;

bool questionWasUsed[QUESTION_COUNT];
int money = 0;
int gameRound = 0;

void game();
void getQuestion();
void setMoney();

int main()
{
  srand(time(NULL));

  char start;

  system("cls");
  puts("Welcome to Who Wants to Be a Millionaire!");
  puts("Are you ready to face 15 devious questions, all related to gaming?");
  puts("");
  puts("J - Start Game");
  puts("N - End Game");
  puts("");
  start = getchar();
  puts("");

  switch(start)
  {
    case 'J':
      game();
      break;
    case 'N':
      return 0;
      break;
    default:
      puts("Invalid input!");
      puts("");
      main();
      break;
  }
  return 0;
}

//Method that leads the game:
void game()
{
  puts("Let us begin the game!");
  puts("To answer a question, type the correlating letter.");
  puts("");

  for(gameRound = 1; gameRound < 16; gameRound++)
  {
    setMoney();

    printf("Round: %d", gameRound);
    printf("\tPrize Money: %d\n\n", money);

    getQuestion();

    retryAnswer:;

    printf("Question: %s\n", &currentQuestion.question);
    printf("A: %s\n", &currentQuestion.answer1);
    printf("B: %s\n", &currentQuestion.answer2);
    printf("C: %s\n", &currentQuestion.answer3);
    printf("D: %s\n\n", &currentQuestion.answer4);

    while (getchar() != '\n');
    char givenAnswer = getchar();

    //Check if Answer is valid
    if(givenAnswer == 'A' || givenAnswer == 'B' ||
      givenAnswer == 'C' || givenAnswer == 'D')
    {
      //Check if Answer is correct
      if(givenAnswer == currentQuestion.correctAnswer)
      {
        if(gameRound != 15)
        {
          puts("");
          puts("This was the correct answer!");
          puts("Get ready for the next round:");
          puts("");
        }
        else
        {
          //End of the game:
          puts("");
          puts("It seems that you have answered all 15 questions correctly!");
          puts("This means that you won the game and will be walking home with 1 million dollars!");
          puts("Congratulations!");
          puts("We hope to see you face our challenge again.");
          puts("");
        }
      }
      else
      {
        puts("");
        puts("Your answer was incorrect!");
        printf("The correct answer was ");

        //Giving out the correct answer:
        switch(currentQuestion.correctAnswer)
        {
          case 'A':
            printf("A: %s\n", currentQuestion.answer1);
            break;
          case 'B':
            printf("B: %s\n", currentQuestion.answer2);
            break;
          case 'C':
            printf("C: %s\n", currentQuestion.answer3);
            break;
          case 'D':
            printf("D: %s\n", currentQuestion.answer4);
            break;
        }

        puts("");
        puts("Sadly, this also means that you have lost the game.");
        if(gameRound == 1) {
          puts("Since this was the first question, you did not earn any prize money.");
          puts("Maybe next time!");
        }
        if(gameRound > 1) {
          printf("But don't be angry, for you have earned: $%d\n", money);
        }
        puts("We are looking forward to seeing you again!");
        puts("");

        break;
      }
    }
    else
    {
      puts("");
      puts("Your answer is invalid.");
      puts("Please try again:");
      puts("");

      goto retryAnswer;
    }
  }
}

//Method to choose a random question every round
void getQuestion()
{
  retryQuestion:;

  switch((rand() % QUESTION_COUNT))
  {
    case 0:
      if(!questionWasUsed[0])
      {
        currentQuestion.correctAnswer = 'C';
        strcpy(currentQuestion.question,
          "What is the name of Joel's first daughter in The Last of Us");
        strcpy(currentQuestion.answer1, "Jessie");
        strcpy(currentQuestion.answer2, "Ellie");
        strcpy(currentQuestion.answer3, "Sarah");
        strcpy(currentQuestion.answer4, "Catherine");
        questionWasUsed[0] = true;
      } else { goto retryQuestion; }
      break;
    case 1:
      if(!questionWasUsed[1])
      {
        currentQuestion.correctAnswer = 'B';
        strcpy(currentQuestion.question,
          "Which of these four characters from Alien: Isolation turns out to be an Android?");
        strcpy(currentQuestion.answer1, "Amanda Ripley");
        strcpy(currentQuestion.answer2, "Christopher Samuels");
        strcpy(currentQuestion.answer3, "Henry Marlow");
        strcpy(currentQuestion.answer4, "Axel");
        questionWasUsed[1] = true;
      } else { goto retryQuestion; }
      break;
    case 2:
      if(!questionWasUsed[2])
      {
        currentQuestion.correctAnswer = 'C';
        strcpy(currentQuestion.question,
          "How many coins do you need to buy a hammer in Kingdom: Two Crowns?");
        strcpy(currentQuestion.answer1, "1");
        strcpy(currentQuestion.answer2, "2");
        strcpy(currentQuestion.answer3, "3");
        strcpy(currentQuestion.answer4, "4");
        questionWasUsed[2] = true;
      } else { goto retryQuestion; }
      break;
    case 3:
      if(!questionWasUsed[3])
      {
        currentQuestion.correctAnswer = 'A';
        strcpy(currentQuestion.question,
          "In World of Tanks, how many tech tree tanks are based on the chassis of the Pz. IV?");
        strcpy(currentQuestion.answer1, "3");
        strcpy(currentQuestion.answer2, "6");
        strcpy(currentQuestion.answer3, "8");
        strcpy(currentQuestion.answer4, "7");
        questionWasUsed[3] = true;
      } else { goto retryQuestion; }
      break;
    case 4:
      if(!questionWasUsed[4])
      {
        currentQuestion.correctAnswer = 'B';
        strcpy(currentQuestion.question,
          "In The Binding of Isaac, how many completion marks are there, including DLC?");
        strcpy(currentQuestion.answer1, "14");
        strcpy(currentQuestion.answer2, "12");
        strcpy(currentQuestion.answer3, "13");
        strcpy(currentQuestion.answer4, "11");
        questionWasUsed[4] = true;
      } else { goto retryQuestion; }
      break;
    case 5:
      if(!questionWasUsed[5])
      {
        currentQuestion.correctAnswer = 'D';
        strcpy(currentQuestion.question,
          "How many killer perks in Dead by Daylight affect pick up speed?");
        strcpy(currentQuestion.answer1, "5");
        strcpy(currentQuestion.answer2, "12");
        strcpy(currentQuestion.answer3, "0");
        strcpy(currentQuestion.answer4, "1");
        questionWasUsed[5] = true;
      } else { goto retryQuestion; }
      break;
    case 6:
      if(!questionWasUsed[6])
      {
        currentQuestion.correctAnswer = 'D';
        strcpy(currentQuestion.question,
          "How many axes can you collect in The Forest?");
        strcpy(currentQuestion.answer1, "3");
        strcpy(currentQuestion.answer2, "6");
        strcpy(currentQuestion.answer3, "4");
        strcpy(currentQuestion.answer4, "5");
        questionWasUsed[6] = true;
      } else { goto retryQuestion; }
      break;
    case 7:
      if(!questionWasUsed[7])
      {
        currentQuestion.correctAnswer = 'A';
        strcpy(currentQuestion.question,
          "How many unique slimes are there in Slime Rancher?");
        strcpy(currentQuestion.answer1, "19");
        strcpy(currentQuestion.answer2, "17");
        strcpy(currentQuestion.answer3, "23");
        strcpy(currentQuestion.answer4, "15");
        questionWasUsed[7] = true;
      } else { goto retryQuestion; }
      break;
    case 8:
      if(!questionWasUsed[8])
      {
        currentQuestion.correctAnswer = 'B';
        strcpy(currentQuestion.question,
          "How many Animatronics are there in Five Nights at Freddy's Ultimate Custom Night?");
        strcpy(currentQuestion.answer1, "50");
        strcpy(currentQuestion.answer2, "59");
        strcpy(currentQuestion.answer3, "58");
        strcpy(currentQuestion.answer4, "61");
        questionWasUsed[8] = true;
      } else { goto retryQuestion; }
      break;
    case 9:
      if(!questionWasUsed[9])
      {
        currentQuestion.correctAnswer = 'C';
        strcpy(currentQuestion.question,
          "How many players earned the most common achievement in Hearts of Iron IV?");
        strcpy(currentQuestion.answer1, "90%");
        strcpy(currentQuestion.answer2, "50%");
        strcpy(currentQuestion.answer3, "20%");
        strcpy(currentQuestion.answer4, "75%");
        questionWasUsed[9] = true;
      } else { goto retryQuestion; }
      break;
    case 10:
      if(!questionWasUsed[10])
      {
        currentQuestion.correctAnswer = 'A';
        strcpy(currentQuestion.question,
          "How many standalone Ace Attorney games are there, not counting collections?");
        strcpy(currentQuestion.answer1, "11");
        strcpy(currentQuestion.answer2, "9");
        strcpy(currentQuestion.answer3, "10");
        strcpy(currentQuestion.answer4, "12");
        questionWasUsed[10] = true;
      } else { goto retryQuestion; }
      break;
    case 11:
      if(!questionWasUsed[11])
      {
        currentQuestion.correctAnswer = 'D';
        strcpy(currentQuestion.question,
          "On which console did Phoenix Wright: Ace Attorney originally release on?");
        strcpy(currentQuestion.answer1, "Nintendo Wii");
        strcpy(currentQuestion.answer2, "Nintendo DS");
        strcpy(currentQuestion.answer3, "PC");
        strcpy(currentQuestion.answer4, "GameBoy Advanced");
        questionWasUsed[11] = true;
      } else { goto retryQuestion; }
      break;
    case 12:
      if(!questionWasUsed[12])
      {
        currentQuestion.correctAnswer = 'B';
        strcpy(currentQuestion.question,
          "How many cookies do you need for the first Prestige Level in Cookie Clicker?");
        strcpy(currentQuestion.answer1, "1 billion");
        strcpy(currentQuestion.answer2, "1 trillion");
        strcpy(currentQuestion.answer3, "100 million");
        strcpy(currentQuestion.answer4, "10 trillion");
        questionWasUsed[12] = true;
      } else { goto retryQuestion; }
      break;
    case 13:
      if(!questionWasUsed[13])
      {
        currentQuestion.correctAnswer = 'C';
        strcpy(currentQuestion.question,
          "How many unique fighters are there in Super Smash Bros Ultimate?");
        strcpy(currentQuestion.answer1, "79");
        strcpy(currentQuestion.answer2, "80");
        strcpy(currentQuestion.answer3, "89");
        strcpy(currentQuestion.answer4, "90");
        questionWasUsed[13] = true;
      } else { goto retryQuestion; }
      break;
    case 14:
      if(!questionWasUsed[14])
      {
        currentQuestion.correctAnswer = 'B';
        strcpy(currentQuestion.question,
          "How many champions did League of Legends have on release?");
        strcpy(currentQuestion.answer1, "10");
        strcpy(currentQuestion.answer2, "40");
        strcpy(currentQuestion.answer3, "30");
        strcpy(currentQuestion.answer4, "20");
        questionWasUsed[14] = true;
      } else { goto retryQuestion; }
      break;
    case 15:
      if(!questionWasUsed[15])
      {
        currentQuestion.correctAnswer = 'C';
        strcpy(currentQuestion.question,
          "How many Finnish tanks are there in World of Tanks Blitz?");
        strcpy(currentQuestion.answer1, "0");
        strcpy(currentQuestion.answer2, "10");
        strcpy(currentQuestion.answer3, "1");
        strcpy(currentQuestion.answer4, "11");
        questionWasUsed[15] = true;
      } else { goto retryQuestion; }
      break;
  }
}

//Method to increase money every round
//(It's its own method for organizations sake)
void setMoney()
{
  switch(gameRound)
  {
    case 1:
      money = 0;
      break;
    case 2:
      money = 50;
      break;
    case 3:
      money = 100;
      break;
    case 4:
      money = 200;
      break;
    case 5:
      money = 300;
      break;
    case 6:
      money = 500;
      break;
    case 7:
      money = 1000;
      break;
    case 8:
      money = 2000;
      break;
    case 9:
      money = 4000;
      break;
    case 10:
      money = 8000;
      break;
    case 11:
      money = 16000;
      break;
    case 12:
      money = 32000;
      break;
    case 13:
      money = 64000;
      break;
    case 14:
      money = 125000;
      break;
    case 15:
      money = 500000;
      break;
  }
}
