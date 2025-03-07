#include "header.h"

#define QUESTION_COUNT 17

bool questionWasUsed[QUESTION_COUNT];
char correctAnswer;
char question[5][128];
int money;
int gameRound;

int main()
{
  srand(time(NULL));

  char start;

  //system("cls");
  puts("Welcome to Who Wants to Be a Millionaire!");
  puts("Are you ready to face 15 devious questions, all related to gaming?");
  puts("");
  puts("Y - Start Game");
  puts("N - End Game");
  puts("");
  start = getchar();
  puts("");

  switch(start)
  {
    case 'Y':
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
    getQuestion();

    retryAnswer:;

    puts("");
    printf("Round: %d", gameRound);
    printf("\tPrize Money: %d\n\n", money);
    for (int i = 0; i < 5; i++) { printf("%s\n", question[i]); }

    while (getchar() != '\n');
    char givenAnswer = getchar();

    //Check if Answer is valid
    if(givenAnswer == 'A' || givenAnswer == 'B' ||
      givenAnswer == 'C' || givenAnswer == 'D')
    {
      //Check if Answer is correct
      if(givenAnswer == correctAnswer)
      {
        if(gameRound != 15)
        {
          //Continuing the game via a random message consisting of
          //two randomly chosen sentences
          puts("");
          switch((rand() % 6))
          {
            case 0:
              puts("This was the correct answer!");
              break;
            case 1:
              puts("You gave the right answer!");
              break;
            case 2:
              puts("Correct! Did you actually know this?");
              break;
            case 3:
              puts("Right answer!");
              break;
            case 4:
              puts("Perfect!");
              break;
            case 5:
              puts("Splendid!");
              break;
          }
          switch((rand() % 6))
          {
            case 0:
              puts("Get ready for the next round:");
              break;
            case 1:
              puts("Don't lose focus now:");
              break;
            case 2:
              puts("This next one will be tough:");
              break;
            case 3:
              puts("Prepare for the next question:");
              break;
            case 4:
              puts("Make sure to read the question carefully:");
              break;
            case 5:
              puts("Good luck with the next question:");
              break;
          }
          puts("");
        }
        else
        {
          //End of the game
          puts("");
          puts("It seems that you have answered all 15 questions correctly!");
          puts("This means that you won the game and will be walking home with 1 million dollars!");
          puts("Congratulations!");
          puts("We hope to see you face our challenge again.");
          puts("");
          system("PAUSE");
        }
      }
      else
      {
        //Ending the game after entering a wrong answer
        puts("");
        puts("Your answer was incorrect!");
        printf("The correct answer was ");

        //Giving out the correct answer
        switch(correctAnswer)
        {
          case 'A':
            printf("A: %s\n", question[1]);
            break;
          case 'B':
            printf("B: %s\n", question[2]);
            break;
          case 'C':
            printf("C: %s\n", question[3]);
            break;
          case 'D':
            printf("D: %s\n", question[4]);
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
        system("PAUSE");

        break;
      }
    }
    else
    {
      //Looping around to the question if the asnwer was invalid
      puts("");
      puts("Your answer is invalid.");
      puts("Please try again:");
      puts("");
      system("PAUSE");

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
        correctAnswer = 'C';
          file_reader("questions.txt", "@QUESTION1");
        questionWasUsed[0] = true;
      } else { goto retryQuestion; }
      break;
    case 1:
      if(!questionWasUsed[1])
      {
        correctAnswer = 'B';
          file_reader("questions.txt", "@QUESTION2");
        questionWasUsed[1] = true;
      } else { goto retryQuestion; }
      break;
    case 2:
      if(!questionWasUsed[2])
      {
        correctAnswer = 'C';
          file_reader("questions.txt", "@QUESTION3");
        questionWasUsed[2] = true;
      } else { goto retryQuestion; }
      break;
    case 3:
      if(!questionWasUsed[3])
      {
        correctAnswer = 'A';
          file_reader("questions.txt", "@QUESTION4");
        questionWasUsed[3] = true;
      } else { goto retryQuestion; }
      break;
    case 4:
      if(!questionWasUsed[4])
      {
        correctAnswer = 'B';
          file_reader("questions.txt", "@QUESTION5");
        questionWasUsed[4] = true;
      } else { goto retryQuestion; }
      break;
    case 5:
      if(!questionWasUsed[5])
      {
        correctAnswer = 'D';
          file_reader("questions.txt", "@QUESTION6");
        questionWasUsed[5] = true;
      } else { goto retryQuestion; }
      break;
    case 6:
      if(!questionWasUsed[6])
      {
        correctAnswer = 'D';
          file_reader("questions.txt", "@QUESTION7");
        questionWasUsed[6] = true;
      } else { goto retryQuestion; }
      break;
    case 7:
      if(!questionWasUsed[7])
      {
        correctAnswer = 'A';
          file_reader("questions.txt", "@QUESTION8");
        questionWasUsed[7] = true;
      } else { goto retryQuestion; }
      break;
    case 8:
      if(!questionWasUsed[8])
      {
        correctAnswer = 'B';
          file_reader("questions.txt", "@QUESTION9");
        questionWasUsed[8] = true;
      } else { goto retryQuestion; }
      break;
    case 9:
      if(!questionWasUsed[9])
      {
        correctAnswer = 'C';
          file_reader("questions.txt", "@QUESTION10");
        questionWasUsed[9] = true;
      } else { goto retryQuestion; }
      break;
    case 10:
      if(!questionWasUsed[10])
      {
        correctAnswer = 'A';
          file_reader("questions.txt", "@QUESTION11");
        questionWasUsed[10] = true;
      } else { goto retryQuestion; }
      break;
    case 11:
      if(!questionWasUsed[11])
      {
        correctAnswer = 'D';
          file_reader("questions.txt", "@QUESTION12");
        questionWasUsed[11] = true;
      } else { goto retryQuestion; }
      break;
    case 12:
      if(!questionWasUsed[12])
      {
        correctAnswer = 'B';
          file_reader("questions.txt", "@QUESTION13");
        questionWasUsed[12] = true;
      } else { goto retryQuestion; }
      break;
    case 13:
      if(!questionWasUsed[13])
      {
        correctAnswer = 'C';
          file_reader("questions.txt", "@QUESTION14");
        questionWasUsed[13] = true;
      } else { goto retryQuestion; }
      break;
    case 14:
      if(!questionWasUsed[14])
      {
        correctAnswer = 'B';
          file_reader("questions.txt", "@QUESTION15");
        questionWasUsed[14] = true;
      } else { goto retryQuestion; }
      break;
    case 15:
      if(!questionWasUsed[15])
      {
        correctAnswer = 'C';
          file_reader("questions.txt", "@QUESTION16");
        questionWasUsed[15] = true;
      } else { goto retryQuestion; }
      break;
    case 16:
      if(!questionWasUsed[16])
      {
        correctAnswer = 'D';
          file_reader("questions.txt", "@QUESTION17");
        questionWasUsed[16] = true;
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
