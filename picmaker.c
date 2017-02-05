#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define XRES 500
#define YRES 500
#define PI 3.14159265

int main(){

  int fd, r, g, b, o;
  double i, j;
  char line[20];

  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  sprintf(line, "P3 %d %d 255\n", XRES, YRES);
  write(fd, line, strlen(line));

  for(i = 0; i < 500; i++){
    for(j = 0; j < 500; j++){
    	o = (int)fabs(log10(((int)i % 300) * ((int)j % 300))) % 256;
    	r = (int)ldexp((int)i % 10, (int)j % 10) % 256;
      	g = (int)((int)i % 200 * (int)j % 100) % 256;
      	b = (int)(exp((o % 10) * i / j) + exp((r % 10) * j / i)) % 256;
      	sprintf(line, "%d %d %d\n", r, g, b);
      	write(fd, line, strlen(line));
    }
  }
  close(fd);
  return 0;
}

  
