#include "Object.h"

void Object::rotateTheObject(float angle , int x, int y, int z)
{
	rotationVector = rotate(angle, vec3(x, y, z));
}

Object::Object()
{
}

void Object::init()
{
	//VAO
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	//VBO
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, (this->verts.size()) * sizeof(Vertex), &verts[0], GL_STATIC_DRAW);
	//element array
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (this->indices.size()) * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);

		// pos
	glEnableVertexAttribArray(0);
		// color
	glEnableVertexAttribArray(1);
		// texture
	glEnableVertexAttribArray(2);
	// Attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV));
	
	translateVector = translate( vec3(0.0f, 0.0f, 0.0f) ) ;
	scaleVector = scale(vec3(1.0f, 1.0f, 1.0f) );
	rotationVector = rotate(0.0f,vec3(1.0f,1.0f,1.0f));
	glBindVertexArray(0);
}

void Object::draw(GLuint pID)
{
	glBindVertexArray(vertexArrayID);
	// set modelMatrix
	GLuint modeMatrixID = glGetUniformLocation(pID,	"ModelMatrix");
	mat4 mM = getModelMatrix();
	glUniformMatrix4fv(modeMatrixID, 1, GL_FALSE, &mM[0][0]);
	//draw
	texture->Bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
}

mat4 Object::getModelMatrix()
{
	mat4 modelMatrix = mat4(1);
	//modelMatrix = translate(0.0f, 0.0f, 0.0f) * rotate(0.0f, vec3(1.0, 1.0, 1.0)) * scale(1.0f, 1.0f, 1.0f);
	modelMatrix = translateVector * 
		rotationVector  * 
		scaleVector;
	return modelMatrix;
}


Object::~Object()
{
}
