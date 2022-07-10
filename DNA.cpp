#include "DNA.h"

DNA::DNA()
{
}

DNA::DNA(const Strand parent, int width, int height)
{
	this->width = width;
	this->height = height;
	
	texture.create(width, height);
	this->strand = parent; 
	//mutation rate 
	int mutationCap = 10; // 15% default 
	for (int i = 0; i < shapeMax; i++)
	{
		//for every one of the triangles 
		// have a 75% chance for every one of the 10 attributes to be mutated by 1 percent of the range 
		for (int j= 0; j< 10; j++)
		{
			int randNum = rand() % 100  ;
			if (randNum < mutationCap) // 
			{
				//mutate 
				mutate(j, strand[i]); 
			}
		}
	}
}

DNA::DNA(int width, int height)
{
	this->width = width; 
	this->height = height; 
	texture.create(width,height ); 
	for (int i = 0; i < shapeMax; i++)
	{
		Tri temp; 
		temp.initRand(width, height); 
		strand.push_back(temp); 
	} // makes 50 rand triangles
}

DNA::~DNA()
{
}

void DNA::drawPicture(sf::RenderWindow& window)
{
	// draw the representation on the window 
	for (int i = 0; i < shapeMax; i++)
	{
		window.draw(strand[i].triangle);
	}
}
sf::RenderTexture& DNA::savePic(int& genNum)
{
	genNum++;
	
	texture.clear(sf::Color::Black);
	for (int i = 0; i < shapeMax; i++)
	{
		texture.draw(strand[i].triangle);
	}
	texture.display();	

	std::string num = std::to_string(genNum);
	std::string png = ".png"; 
	std::string start = "images/"; 
	num += png;
	start += num; 
	
	return texture; 
	
}

void DNA::mutate(int attributeIndex, Tri &tri )// remember to change the values of the triangle  // fix how the position of the vertices work 

{
	int decider = rand() % 2; 
	int rangeOfChange = 2; 
	int widthMultiplier = rand()% rangeOfChange;
	int heightMultiplier = rand() % rangeOfChange;
	widthRange = widthMultiplier * 0.01*width; 
	heightRange = heightMultiplier * 0.01*height; 
	int colorMultiplier = rand() % rangeOfChange;
	colorRange = 3 * colorMultiplier; 
	
	switch(attributeIndex) // make sure it checks whether it is less that or greater than the max/min
	{
	case 0:
		if (decider == 1)
		{
			if (tri.triangle[0].position.x > widthRange)
			tri.triangle[0].position.x -= widthRange; 
		}
		else
		{
			if (tri.triangle[0].position.x < width - widthRange)
			tri.triangle[0].position.x += widthRange;
		}
		break; 
	case 1:
		if (decider == 1)
		{
			if (tri.triangle[1].position.y > heightRange)
			tri.triangle[0].position.y -= heightRange;
		}
		else
		{
			if (tri.triangle[1].position.y < height - heightRange)
			tri.triangle[0].position.y += heightRange;
		}
		break;
	case 2: 
		if (decider == 1)
		{
			if (tri.triangle[1].position.x > widthRange)
			tri.triangle[1].position.x -= widthRange;
		}
		else
		{
			if (tri.triangle[1].position.x < width - widthRange)
			tri.triangle[1].position.x += widthRange;
		}
		break;
	case 3: 
		if (decider == 1)
		{
			if (tri.triangle[1].position.y> heightRange)
			tri.triangle[1].position.y -= heightRange;
		}
		else
		{
			if (tri.triangle[1].position.y < height - heightRange)
			tri.triangle[1].position.y += heightRange;
		}
		break;
	case 4: 
		if (decider == 1)
		{
			if (tri.triangle[2].position.x > widthRange)
			tri.triangle[2].position.x -= widthRange;
		}
		else
		{
			if (tri.triangle[2].position.x < width - widthRange )
			tri.triangle[2].position.x += widthRange;
		}
		break;
	case 5: 
		if (decider == 1)
		{
			if(tri.triangle[2].position.y>heightRange)
			tri.triangle[2].position.y -= heightRange;
		}
		else
		{
			if (tri.triangle[2].position.y < height-heightRange)
			tri.triangle[2].position.y += heightRange;
		}
		break;
	case 6:
		if (decider == 1)
		{
			if (tri.triangle[0].color.r < 255 - colorRange)
			{
				tri.triangle[0].color.r += colorRange;
				tri.triangle[1].color.r += colorRange;
				tri.triangle[2].color.r += colorRange;
			}
		}
		else
		{

			if (tri.triangle[0].color.r >  colorRange)
			{
				tri.triangle[0].color.r -= colorRange;
				tri.triangle[1].color.r -= colorRange;
				tri.triangle[2].color.r -= colorRange;
			}
		}
		break;
	case 7:
		if (decider == 1)
		{
			if (tri.triangle[0].color.g < 255 - colorRange)
			{
				tri.triangle[0].color.g += colorRange;
				tri.triangle[1].color.g += colorRange;
				tri.triangle[2].color.g += colorRange;
			}
		}
		else
		{

			if (tri.triangle[0].color.g > colorRange)
			{
				tri.triangle[0].color.g -= colorRange;
				tri.triangle[1].color.g -= colorRange;
				tri.triangle[2].color.g -= colorRange;
			}
		}
		break;
	case 8:
		if (decider == 1)
		{ 
			if (tri.triangle[0].color.b < 255 - colorRange)
			{
				tri.triangle[0].color.b += colorRange;
				tri.triangle[1].color.b += colorRange;
				tri.triangle[2].color.b += colorRange;
			}
		}
		else
		{

			if (tri.triangle[0].color.b > colorRange)
			{
				tri.triangle[0].color.b -= colorRange;
				tri.triangle[1].color.b -= colorRange;
				tri.triangle[2].color.b -= colorRange;
			}
		}
		break;
	case 9: 
		if (decider == 1)
		{
			if (tri.triangle[0].color.a < 255 - colorRange)
			{
				tri.triangle[0].color.a += colorRange;
				tri.triangle[1].color.a += colorRange;
				tri.triangle[2].color.a += colorRange;
			}
		}
		else
		{

			if (tri.triangle[0].color.a > colorRange)
			{
				tri.triangle[0].color.a -= colorRange;
				tri.triangle[1].color.a -= colorRange;
				tri.triangle[2].color.a -= colorRange;
			}
		}
		break;
	}
}

void DNA::setEqual(DNA& child)
{
	// draw the texture onto the parents texture 
	texture.clear(sf::Color::Black); 
	for (int i = 0; i < child.strand.size(); i++)
	{
		texture.draw(child.strand[i].triangle); 
	}
	texture.display(); 
	//set all variables equal 
	this->strand = child.strand; 
}

std::string DNA::getStringPath(int genNum)
{
	std::string first = "images/"; 
	std::string second = std::to_string(genNum); 
	std::string third = ".png"; 
	first += second; 
	first += third; 
	return first;
}

Tri::Tri()
{
}
