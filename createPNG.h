#ifndef CREATEPNG_H
#define CREATEPNG_H

#include <iostream>
#include <vector>
#include "../makePNGprototype/lodepng.h"

void makeImage(int ,int**);
void encodeOneStep(const char* , std::vector<unsigned char>& , unsigned , unsigned);

#endif // CREATEPNG_H
