#include "render_flag.h"

RenderFlag::RenderFlag() {
	_flag = new Flag;
	float aspect_of_the_window = (float)_windowWidth / (float)_windowHeight;
	//std::cout << aspect_of_the_window;
	
	_stars[0]=new Star(glm::vec2(-0.38,0.25), 90, 0.12,aspect_of_the_window);
	_stars[1] = new Star(glm::vec2(-0.25, 0.4), 126, 0.05, aspect_of_the_window);
	_stars[2] = new Star(glm::vec2(-0.21,0.3), 144, 0.05, aspect_of_the_window);
	_stars[3] = new Star(glm::vec2(-0.21,0.2), 90 , 0.05, aspect_of_the_window);
	_stars[4] = new Star(glm::vec2(-0.25, 0.1), 126, 0.05, aspect_of_the_window);

	// create 5 stars
	// write your code here
	
	// _stars[i] = new Star(ndc_position, rotation_in_radians, size_of_star, aspect_of_the_window);
	
	// hint: aspect_of_the_window = _windowWidth / _windowHeight
}

RenderFlag::~RenderFlag() {
	if (_flag) {
		delete _flag;
		_flag = nullptr;
	}

	for (int i = 0; i < 5; ++i) {
		delete _stars[i];
		_stars[i] = nullptr;
	}
}

void RenderFlag::handleInput() {
	// do nothing
}

void RenderFlag::renderFrame() {
	showFpsInWindowTitle();

	glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);
	glClear(GL_COLOR_BUFFER_BIT);

	_flag->render();
	//_stars[1]->render();
	for (int i = 0; i < 5; ++i) {
		if (_stars[i] != nullptr) {
			_stars[i]->render();
		}
	}
}