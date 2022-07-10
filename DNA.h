#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>  
#include <string>
// at some point wanna make it able to use other shapes

struct Tri // renderable triangles 
{
	unsigned r, g, b, a, x1, y1, x2, y2, x3, y3;

	sf::VertexArray triangle= sf::VertexArray(sf::Triangles, 3);
	Tri(); 
	
	~Tri()
	{}

	void initRand(int width , int height )
	{
		r = rand() % 255;
		g = rand() % 255; 
		b = rand() % 255; 
		a = rand() % 255; 
		x1 = rand() % width; 
		y1 = rand() % height; 
		
		x2 = rand() % width; 
		y2 = rand() % height; 

		x3 = rand() % width;
		y3 = rand() % height;
		triangle[0].position = sf::Vector2f(x1,y1);
		triangle[0].color = sf::Color(r,g,b,a);
		triangle[1].position = sf::Vector2f(x2, y2);
		triangle[1].color = sf::Color(r, g, b, a);
		triangle[2].position = sf::Vector2f(x3, y3); 
		triangle[2].color = sf::Color(r, g, b, a);
	}
	
	
};
typedef std::vector<Tri> Strand;
class DNA 
{
public: 
	Strand strand; // hold a certain amount of strands to draw a picture 
	int width, height, shapeMax = 50;
	double widthRange = 1, heightRange =1, colorRange = 3; 
	DNA(); 
	DNA(const Strand parent, int width ,int height );
	DNA(int width , int height); 
	~DNA(); 
	void drawPicture(sf::RenderWindow& window); 
	sf::RenderTexture& savePic(int &genNum); 
	void compare(sf::Texture target ); // compare this DNA's picture to the target image 
	void mutate(int attributeIndex, Tri &tri); 
	void setEqual(DNA &child); 
	static std::string getStringPath(int genNum); 
private: 
	
	
	sf::RenderTexture texture; 
};

