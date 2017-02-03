#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define XRES 500
#define YRES 500

int main(){

  int fd, i, j, r, g, b;
  char line[20];

  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, sizeof(line));

  for(i = 0; i < 500; i++){
    for(j = 0; j < 500; j++){
      r = 255;
      g = 0;
      b = 0;
      snprintf(line, sizeof(line), "%d %d %d\n", r, g, b);
      write(fd, line, sizeof(line));
    }
  }
  close(fd);
  return 0;
}

  
