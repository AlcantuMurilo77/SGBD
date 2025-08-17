#include "log.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <storage.h>

#define VERSION "0.1"

int main() {
  char input[256];
  bool running = true;

  printf("\nWelcome to SGBD\nType :help for help\n");

  while (running) {
    printf("> ");

    if (!fgets(input, sizeof(input), stdin)) {
      break;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, ":quit") == 0) {
      running = false;
    } else if (strcmp(input, ":help") == 0) {
      printf("\nAvailable commands:\n");
      printf("\n  :help   - show this help message\n");
      printf("\n  :version   - show current version\n");
      printf("\n  :quit   - exits program\n");
    } else if (strcmp(input, ":version") == 0) {
      printf("\nVersion: %s\n", VERSION);
    
    } else if (strcmp(input, ":rundb") == 0){
      Storage st;
      Status s = storage_open(&st, "data.db");

      if (s != STATUS_OK){
        LOG_ERR("Error opening/creating data.db");
        return 1;
      }

      LOG_INFO("File data.db opened/created");

      storage_close(&st);
      return 0;
      
    } else {
      printf("\nUnknown command: %s\n", input);
    }
  }

  printf("\nExiting...\n");
  return 0;
}