#include "DNA.h"
// might use a render texture instead 

double calcFit(const sf::Image &currentImage, sf::Image &targetImage, int step)
{
	double fit = 0;
	double r = 0; 
	double g = 0; 
	double b = 0; 
	for (int y = 0; y < targetImage.getSize().y; y+=step)
	{
		for (int x= 0; x < targetImage.getSize().x;  x+=step)
		{
			
			r += abs(targetImage.getPixel(x, y).r - currentImage.getPixel(x, y).r);
			b += abs(targetImage.getPixel(x, y).b - currentImage.getPixel(x, y).b);
			g += abs(targetImage.getPixel(x, y).g - currentImage.getPixel(x, y).g);
		}
	}
	fit = r * r + b * b + g * g; 
	return fit ; // returns the s
}

double returnPercentage(double fitness)
{
	return -210*(fitness * fitness) + 100; 
}
int main()
{
	srand(time(NULL));
	int step = 2, genNum=0; // this determines the perfermance and clarity of evolved picture
	sf::Image targetImage; 
	targetImage.loadFromFile("monalisa.jpg"); 
	int width = targetImage.getSize().x, height = targetImage.getSize().y;
	
	sf::RenderWindow window(sf::VideoMode(width,height),"Genetic Algorithm Image Recreater");
	DNA egg(width, height); // because the egg came before the chicken ;) 
	// get fitness of the original
	//make it so that the draw picture function returns an image 
	egg.savePic(genNum); 
	
	double currentFit = calcFit(egg.savePic(genNum).getTexture().copyToImage(), targetImage, step); // lower the better 
	window.clear(sf::Color::Black); 
	egg.drawPicture(window);
	window.display();
	sf::Event event; 
	while (window.isOpen()) // remember to iterate the genNum
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed||event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		// update 
		// make a new child with slight mutations 
		// 5-10 changes are possible 
		// each change is going to be maybe one percent of the range of the values 

		DNA child(egg.strand, width ,height ); 
		// with the now mutated child draw it and calc the fit 
		// if the fit is better ( less than the current) make the child the egg
		; 
		
		double newFit = calcFit(child.savePic(genNum).getTexture().copyToImage(), targetImage, step);
		if (newFit < currentFit) // better pic 
		{
			egg.setEqual(child); 
			currentFit = newFit; 
			std::cout <<"GEN  "<<genNum<< ": "<<currentFit << std::endl; 
			
		}




		//draw 

		window.clear(sf::Color::Black);
		child.drawPicture(window);
		window.display(); 
	}
	return 0;
}