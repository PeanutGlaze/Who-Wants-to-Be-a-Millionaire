#include "header.h"

void file_reader(const char* path, const char* flag)
{
  FILE *file = fopen(path, "r");
  char line[256];
  if(file != NULL)
  {
    bool flag_reached = false;

    while(fgets(line, sizeof(line), file))
    {
      //Skipping lines, as long as the reader hasn't found the flag:
      if(!flag_reached)
      {
        if (strncmp(line, flag, strlen(flag)) == 0)
        { flag_reached = true;  }

        continue;
      }

      //Skipping empty lines:
      if(strncmp(line, "\n", 1) == 0) { continue; }

      //Stopping the reader if there's another flag detected:
      else if(strncmp(line, "@QUESTION", 9) == 0) { break; }

      //Reading out the question and the answers
      else
      {
        strcpy(question[0], line);
        for(int i = 1; i < 5; i++)
        {
          fgets(line, sizeof(line), file);
          strcpy(question[i], line);
        }
      }
    }

    fclose(file);

  //When there's no file correlating to the path:
  } else { printf("No file"); }
}
