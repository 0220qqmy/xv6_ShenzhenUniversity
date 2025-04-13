#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;
  char *l, *r;
  char tmp;

  for(i = 1; i < argc; i++){
    for(l = argv[i], r = argv[i] + strlen(argv[i]) - 1; l < r; l++, r--){
        tmp = *l;
        *l = *r;
        *r = tmp;
    }
    write(1, argv[i], strlen(argv[i]));
    if(i + 1 < argc){
        write(1, " ", 1);
    } else{
        write(1, "\n", 1);
    }
  }
  exit(0);
}
