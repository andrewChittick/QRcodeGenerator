//main.cpp
//Andrew Chittick
//10/15/19

#include <iostream>
#include <vector>
#include "lodepng.h"

void encodeOneStep(const char* , std::vector<unsigned char>& , unsigned , unsigned);

int main(){
	//make a white 200 * 200
	std::vector<unsigned char> picture (160000, 255);

	for (int i=0; i<160000; i++){
		//make a blue line(column)
		if (i%200==0){
			picture[i]=0;
			picture[i+2]=0;

			picture[i+4]=0;
			picture[i+6]=0;

			picture[i+8]=0;
			picture[i+10]=0;
			
			picture[i+12]=0;
			picture[i+14]=0;
		}
		//make a red line(row)
		if (i>80000 && i<83200){
			if(i%4==1){
				picture[i]=0;
			}
			if(i%4==2){
				picture[i]=0;
			}
		}
	}
	//make a PNG
	encodeOneStep("sample.png", picture,200,200); 

	return 0;
}


/*
LodePNG Examples

Copyright (c) 2005-2012 Lode Vandevenne

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.
*/

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
  	//Encode the image
  	unsigned error = lodepng::encode(filename, image, width, height);

  	//if there's an error, display it
  	if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}
