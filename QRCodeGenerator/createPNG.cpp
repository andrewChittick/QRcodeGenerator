#include <vector>

//createPNG.cpp
//Marcellus Hunt
//10/15/19
void makeImage(int level,int ** input[]){
	//make a white
	
		//make a blue line(column)
		// v1: 29 x 29 x 4 = 3364 matrix
		//v2: 33 x 33 x 4 = 4356
		
		//0 white 1 Black; 255 white 0 black
		
		//for the 29 x 29 matrix
		
		//if version 1
        if (level ==1)
		{
			std::vector<unsigned char> newImage (3364, 255);
			
			for (int i =0; i < 841; i++)
			{
			
				// if the matrix[i] == 1
				if (input[i] == 1)
				{
					//then set i*4 = 0, i*4+1 = 0;, i*4+2 = 0;
					newImage = [i*4] = 0;
					newImage = [i*4+1] = 0;
					newImage = [i*4+2] = 0;
				}
			
			}
		//make a PNG
		encodeOneStep("QR.png", picture,29,29); 
		}
				
				
		//if version 2
		if (level == 2)
		{
		std::vector<unsigned char> picture (4356, 255);
		//for the 33 x 33 matrix
			for (int y = 0; y < 1089; y++)
			{
				//if the matrix [i] ==1 
				if(input[i] == 1)
				{
					//then i*4 = 0, i*4+1 = 0; i*4+2 = 0;
					newImage = [i*4] = 0;
					newImage = [i*4 + 1] = 0;
					newImage = [i*4+2] = 0;
				}	
			}
			
		//make a PNG
		encodeOneStep("QR.png", picture,33,33); 
		}
		
	}
	

