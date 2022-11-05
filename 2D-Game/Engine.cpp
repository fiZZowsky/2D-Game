#include "Engine.h"

Engine::Engine() {
	this->initWindow(WINDOWED);
}

Engine::~Engine(){
	delete this->window;
}

//Functions
void Engine::run() {
	int fps;
	clock = sf::Clock::Clock();
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time curTime;

	// Main Loop
	while (this->window->isOpen()) {
		this->update();
		this->render();
		
		//FPS counter
		curTime = clock.getElapsedTime();
		fps = 1.0f / (curTime.asSeconds() - prevTime.asSeconds());
		/*std::cout << fps << std::endl;*/
		prevTime = curTime;
	}	
}


//Private functions
void Engine::initWindow(int windowMode) {
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	switch (windowMode) {
	case FULLSCREEN:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Game Engine", Style::Fullscreen);
		break;
	case WINDOWED:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), "2D Game Engine", Style::Close);
		break;
	case CUSTOM:
		this->window = new RenderWindow(VideoMode(SCREEN_WIDTH_FHD, SCREEN_HEIGHT_FHD), "2D Game Engine", Style::Close);
		break;
	}

	this->window->setVerticalSyncEnabled(true);
}

void Engine::update() {
	Event event;

	while (this->window->pollEvent(event)) {
		if (event.Event::type == Event::Closed) {
			this->window->close();
		}
		if (event.Event::KeyPressed && event.Event::key.code == Keyboard::Escape) {
			this->window->close();
		}
	}
}

void Engine::render() {
	this->window->clear(sf::Color::White);

	//Draw all the stuffs
	//window->draw(primitiveRenderer.drawRectangle(80, 400, 200, 50));
	//window->draw(primitiveRenderer.drawCircle(300, 300, 40));
	//window->draw(primitiveRenderer.drawTriangle(50, 50, 30));
	//window->draw(primitiveRenderer.drawPolygon(100, 150, 40, 7));
	//window->draw(primitiveRenderer.drawSFMLLine(500, 500, 150, 45));
	//window->draw(primitiveRenderer.drawLine(300, 100, 400, 200));
	//primitiveRenderer.myDrawLine(window, 300, 120, 400, 220, sf::Color::Green);

	//============================================================================================
	// TODO: DELETE THIS LATER
	//Point2D testPoint(400, 200);
	//window->draw(testPoint.drawPoint());

	//LineSegment lineSegment(450, 200, 600, 300);
	////window->draw(lineSegment.draw(sf::Color::Cyan));
	//lineSegment.drawWithIncrementalAlgorithm(window, sf::Color::Green);

	std::vector<Point2D> points;
	Point2D p1(100, 100), p2(200, 100), p3(200, 200), p4(150, 200);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);

	//window->draw(primitiveRenderer.drawPolyline(points, sf::Color::Blue));
	//window->draw(primitiveRenderer.drawClosedPolyline(points, sf::Color::Green));


	//std::vector<LineSegment> lineSegments;
	//LineSegment ls1(&p1, &p2), ls2(&p2, &p3);
	//lineSegments.push_back(ls1);
	//lineSegments.push_back(ls2);

	//window->draw(primitiveRenderer.drawPolyline(lineSegments, sf::Color::Blue));
	//window->draw(primitiveRenderer.drawClosedPolyline(lineSegments, sf::Color::Blue));

	primitiveRenderer.myDrawCircle(window, 100, 100, 70);
	primitiveRenderer.myDrawElipse(window, 300, 100, 100, 50);

	/*LineSegment ls1(50, 50, 200, 50), ls2(100, 30, 100, 49);
	window->draw(ls1.draw(sf::Color::Blue));
	window->draw(ls2.draw(sf::Color::Green));


	if (LineSegment::isLineSegmentsCrossing(ls1, ls2))	std::cout << "Tak" << std::endl;
	else std::cout << "Nie" << std::endl;*/



	//============================================================================================

	this->window->display();
}
