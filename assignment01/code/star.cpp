#include "star.h"

Star::Star(const glm::vec2& position, float rotation, float radius, float aspect)
	: _position(position), _rotation(rotation), _radius(radius) {
	// assemble the vertex data of the star
	// write your code here
	// -------------------------------------
	const float PI = acos(0) * 2;
	_rotation /= 180;
	_rotation *= PI;

	float r = _radius / 2.618f;
	glm::vec2 L0 = _position;
	glm::vec2 L1 = _position+glm::vec2(_radius * cos(_rotation)/aspect, _radius * sin(_rotation));
	glm::vec2 L2 = _position+glm::vec2(r * cos(_rotation + 0.2* PI) / aspect, r * sin(_rotation + 0.2 * PI));
	glm::vec2 L3 = _position+glm::vec2(_radius * cos(_rotation+0.4*PI) / aspect, _radius * sin(_rotation+ 0.4 * PI));
	glm::vec2 L4 = _position + glm::vec2(r * cos(_rotation + 0.6 * PI) / aspect, r * sin(_rotation + 0.6 * PI));
	glm::vec2 L5 = _position + glm::vec2(_radius * cos(_rotation + 0.8 * PI) / aspect, _radius * sin(_rotation + 0.8 * PI));
	glm::vec2 L6 = _position + glm::vec2(r * cos(_rotation + 1. * PI) / aspect, r * sin(_rotation + 1. * PI));
	glm::vec2 L7 = _position + glm::vec2(_radius * cos(_rotation + 1.2 * PI) / aspect, _radius * sin(_rotation + 1.2 * PI));
	glm::vec2 L8 = _position + glm::vec2(r * cos(_rotation + 1.4 * PI) / aspect, r * sin(_rotation + 1.4 * PI));
	glm::vec2 L9 = _position + glm::vec2(_radius * cos(_rotation + 1.6 * PI) / aspect, _radius * sin(_rotation + 1.6 * PI));
	glm::vec2 L10 = _position + glm::vec2(r * cos(_rotation + 1.8 * PI) / aspect, r * sin(_rotation + 1.8 * PI));
	

	const glm::vec2 _vertices[30]{
		L0,L1,L2,
		L0,L2,L3,
		L0,L3,L4,
		L0,L4,L5,
		L0,L5,L6,
		L0,L6,L7,
		L0,L7,L8,
		L0,L8,L9,
		L0,L9,L10,
		L0,L10,L1
	};
	// -------------------------------------
	
	glGenVertexArrays(1, &_vao);
	glGenBuffers(1, &_vbo);
	
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

Star::~Star() {
	if (_vbo) {
		glDeleteVertexArrays(1, &_vbo);
		_vbo = 0;
	}

	if (_vao) {
		glDeleteVertexArrays(1, &_vao);
		_vao = 0;
	}
}

void Star::render() {
	_shader.use();
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(_vertices) / sizeof(glm::vec2));
}