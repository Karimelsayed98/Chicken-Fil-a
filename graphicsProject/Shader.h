#pragma once
class Shader
{
public:
	unsigned int pID;
	Shader(const GLchar * vertexPath, const GLchar * fragmentPath);
	Shader();

	void use();

	~Shader();
};

