//Andrew Chittick
//Error Correction takes data codewords
//and produces error correction codewords

#include <iostream>
#include <vector>
int numberOfCodewords=10;

int alphaIndex = [1,2,4,8,16,32,64,128,29,58,116,232,205,135,19,38,76,152,45,90.180,117,234,201,143,3,6,12,24,48,96,192,157,39,78,156,37,74,148,53,106,212,181,119,238,193,159,35,70,140,5,10,20,40,80,160,93,186,105,210,185,111,222,161,95,190,97,194,153,47,94,188,101,2202,137,15,30,60,120,240,253,231,211,187,107,214,177,127,254,225,223,163,91,182,113,226,217,175,67,134,17,34,68,136,13,26,52,104,208,189,103,206,129,31,62,124,248,237,199,147,59,118,236,197,151,51,102,204,133,23,46,92,184,109,218,169,79,158,33,66,132,21,42,84,168,77,154,41,82,164,85,170,73,146,57,114,228,213,183,115,230,209,191,99,198,145,63,126,252,229,215,179,123,246,241,255,227,219,171,75,150,49,98,196,149,55,110,220,165,87,174,65,130,25,50,100,200,141,7,14,28,56,112,224,221,167,83,166,81,162,89,178,121,242,249,239,195,155,43,86,172,69,138,9,18,36,72,144,61,122,244,245,247,243,251,235,203,139,11,22,44,88,176,125,250,233,207,131,27,54,108,216,173,71,142,1];

int intIndex = [0,1,25];

int convertToAlpha(int);
int convertToInteger(int);

int main(int argc, char * argv[]){
  //your code hurr
  //convert binary data codewords into decimal for message polynomial
  //hello world message polynomial for test case
  std::vector <int> message{32, 91, 11, 120, 209, 114, 220, 77, 67, 64, 236, 17, 236, 17, 236, 17};
  std::vector <int> result = message;
  //get generator polynomial
  std::vector <int> generator{0, 251, 67, 46, 61, 118, 70, 64, 94, 32, 45};
  /*divide the message by the generator*/
  int temp = 0;
  int step = 0;
  //multiply the generator polynomial by the lead term of the message polynomial
  for (int messageIndex = 0; messageIndex<message.size(); messageIndex++){
    //convert term to alpha notation
    int alpha = convertToAlpha(message[messageIndex]);
    //multiply generator by converted term
    //step 1a
    //std::cout<<generator.size()<<std::endl;
    for (int i = step; i<generator.size(); i++){
      temp = generator[i] + alpha;
      //maintain Galois Field
      if (temp > 255){
        temp = temp % 255;
      }
      temp = convertToInteger(temp);
      //step 1b: XOR
      result[i] = temp ^ message[i];
    }
    step++;
  }

  /* /error correction words are the remainder (result[step-size])
  int resultSize = result.size() - step;
  for (int i=0; i<resultSize; i++){
    answer[i]= result[step];
    step++;
    std::cout<<answer[i]<<" ";
  }
  */

  return 0;
}

int convertToAlpha(int index){
  //std::cout<<dec<<std::endl;
  //return intIndex[index];
  return 12;
}
int convertToInteger(int index){
  //std::cout<<alpha<<std::endl;
  return alphaIndex[index];
}
