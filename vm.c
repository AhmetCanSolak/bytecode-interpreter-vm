#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Declare data[] array */
int* data;

/* required pointers */
int ip = 0;
int sp = 0;

/* instruction parts */
int binopNum = 0;
int opcode = 0;
int dataBits = 0;


// These functions evaluate the currentInstruction according to its opcode bits and dataBits.
void performActionBinopZero(/* arguments */) {
  /* code */

  // Call required commands for the opcode
  switch (/* expression */opcode) {
    case /* value */0:
      break;
    case /* value */1:
      break;
    case /* value */2:
      break;
    case /* value */3:
      break;
    case /* value */4:
      break;
    case /* value */5:
      break;
    case /* value */6:
      break;
    case /* value */7:
      break;
    case /* value */8:
      break;
    case /* value */9:
      break;
    case /* value */10:
      break;
  }

}

void performActionBinopOne(/* arguments */) {
  /* code */

  // Call required commands for the opcode
  switch (/* expression */opcode) {
    case /* value */0:
      break;
    case /* value */1:
      break;
    case /* value */2:
      break;
    case /* value */3:
      break;
    case /* value */4:
      break;
    case /* value */5:
      break;
    case /* value */6:
      break;
    case /* value */7:
      break;
    case /* value */8:
       break;
    case /* value */9:
        break;
    case /* value */10:
         break;
  }

}

// This function takes an instruction and decode its binop, opcode and optional data
void decode(/* arguments */int instr) {
  /* code */
  binopNum = (instr & 0x80000000) >> 31;
  opcode = (instr & 0x7F000000) >>  24;
  dataBits = (instr & 0xFFFFFF);

}

// This function takes name of the image as input and load image
void loadImage(/* arguments */char const* const fileName) {
  /* code */

  FILE* file = fopen(fileName, "rb");// Open the file first.
  char line[10];// Create a buffer for reading file.
  int lineIndex = 0;// Declare a variable for line indexing.

  while (fgets(line, sizeof(line), file)) {
     	 // Read data-size first. image-size second. Then read rest of the lines into data[] array
         if (/* condition */lineIndex == 0) {
           /* code */
           const char* hexstring = line;
           int dataSize = (int)strtol(hexstring, NULL, 16);
           sp = dataSize;// Initialize the sp
           data = (int*) malloc(dataSize * sizeof(int));// Allocate the required memory for the data[] array
           lineIndex = lineIndex + 1;
         } else if (/* condition */lineIndex == 1) {
           /* code */
           const char* hexstring = line;
           int imageSize = (int)strtol(hexstring, NULL, 16);
           lineIndex = lineIndex + 1;
         } else {
           const char* hexstring = line;
           data[lineIndex-2] = (int)strtol(hexstring, NULL, 16);
           lineIndex = lineIndex + 1;
         }
  }

  fclose(file);// Close the file pointer after finish the reading.
}

int main(int argc, char const *argv[]) {
  /* code */

  // Load the VM image
  loadImage(argv[1]);

  // Start the VM
  while(1){
    /* code */
    int currentInstruction = data[ip];// Fetch the instruction from loaded image.
    ip = ip + 1;// Increase the instruction pointer.
    decode(currentInstruction);// Decode the instruction

    /* Check Binop bit to perform action */
    if (binopNum == 0) {
      performActionBinopZero();
    } else {
      performActionBinopOne();
    }
  }

  return 0;
}
