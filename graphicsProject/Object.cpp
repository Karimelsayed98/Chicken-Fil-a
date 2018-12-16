#include "Object.h"

void Object::rotateTheObject(float angle , int x, int y, int z)
{
	rotationVector *= rotate(angle, vec3(x, y, z));
}

void Object::scaleTheObject(float x , float y , float z )
{

	sizeX = x* (abs(verts[0].pos.x - verts[3].pos.x) / 2.0);
	sizeY = y* (abs(verts[0].pos.y - verts[3].pos.y) / 2.0);
	sizeZ = z* (abs(verts[0].pos.z - verts[3].pos.z) / 2.0);
	posX *= sizeX ;
	posY *= sizeY ;
	posZ *= sizeZ ;
	this->scaleVector *= scale(x, y, z);
}

void Object::translateTheObject(float x, float y , float z)
{
	this->translateVector *= translate(x, y, z);
	posX = translateVector[3].x;
	posY = translateVector[3].y;
	posZ = translateVector[3].z;
	//vec4 trans = this->translateVector*vec4(1.0f, 1.0f, 1.0f, 1.0f);
	cout << posX << ' ' << posY << ' ' << posZ << endl;
}

Object::Object()
{
}

void Object::init()
{
	Died = false; 

	sizeX = abs(verts[0].pos.x - verts[3].pos.x) / 2.0;
	sizeY = abs(verts[0].pos.y - verts[3].pos.y) / 2.0; 
	sizeZ = abs(verts[0].pos.z - verts[3].pos.z) / 2.0;

	posX = 0.0f;
	posY = 0.0f;
	posZ = 0.0f;

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
	if (Died == true)
		return;
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
