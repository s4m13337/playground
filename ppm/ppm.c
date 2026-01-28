// https://www.youtube.com/watch?v=xNX9H_ZkfNE

#include <stdio.h>

int main() {
  const char *output_path = "output.ppm";
  FILE *f = fopen(output_path, "wb");
  int w = 16*60, h = 9*60;
  
  
  fprintf(f, "P6\n");    // Magic number
  fprintf(f, "%d %d\n", w, h);    // Dimensions of image
  fprintf(f, "255\n");    // Maximum value of the color component

  // From this point, the file switches to binary mode
  for(int i=0; i<w; i++){
    for(int j=0; j<h; j++){
      fputc(0x00, f);    // Red component is 0
      fputc(0xff, f);    // Green component is set to maximum value
      fputc(0x00, f);    // Blue component is 0
    }
  }
  fclose(f);
  printf("Generated %s\n", output_path);
  return 0;
}
