#pragma once
#include <gl/glew.h>
#include<GL\glfw3.h>
#include <iostream>
#include <vector>
#include<string>
#include "texture.h"
#include "Vertex.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace glm;
using namespace std;
class Object
{
protected:
	// load shader, generate IDS in init().
	GLuint programID;
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLuint normalsBufferID;
	//texture 
	Texture * texture;
	// modelMatrix components
	// vectors of each obj.
	vector <Vertex> verts;
	vector <GLushort> indices;
	// to be used in light
	GLuint AmbientLightID;
	GLuint LightPositionID;
	GLuint EyePositionID;
	glm::vec3 ambientLight;
	glm::vec3 lightPosition;
public:
	bool Died;
	int health;

	GLfloat sizeX;
	GLfloat sizeY;
	GLfloat sizeZ;

	GLfloat posX;
	GLfloat posY;
	GLfloat posZ;

	lowp_mat4 translateVector;
	lowp_mat4 scaleVector;
	lowp_mat4 rotationVector;
	void rotateTheObject(float, int, int, int);
	void scaleTheObject(float , float , float );
	void translateTheObject(float , float , float );
	Object();
	void init();
	void draw(GLuint);
	mat4 getModelMatrix();

	~Object();
};

