#pragma once
#include <GL/glew.h>
#include <array>

class Square
{
public:
	//set up vertex buffer object
	GLuint VBO;
	//set up vertex array object
	GLuint VAO;
	//set up index buffer object
	GLuint EBO;

	//shader for the square
	Shader vSh, fSh;
	GLuint shaderProgram;

	
	//constructor
	Square() 
	{
		//shaders
		vSh.shaderFileName("..//..//Assets//Shaders//shader_Projection_basicLight.vert");
		fSh.shaderFileName("..//..//Assets//Shaders//shader_Projection_basicLight.frag");

		vSh.getShader(1);
		fSh.getShader(2);

		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vSh.shaderID);
		glAttachShader(shaderProgram, fSh.shaderID);
		glLinkProgram(shaderProgram);

		glDeleteShader(vSh.shaderID);
		glDeleteShader(fSh.shaderID);
	};
	
	//define vertices for the square
	GLfloat sq_vertices[32] = {
		//vertices				colour				texture coordinates    
		0.1f, 0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,   1.0f, 1.0f,		
		0.1f, -0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,	 1.0f, 0.0f,
		-0.1f, -0.1f, 0.0f,		0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		-0.1f, 0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,   0.0f, 1.0f
	};
	//define indices for the square
	GLuint indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	void setBuffers()
	{
		//
		//OpenGL buffers
		//set up 1 for the triangle
		glGenBuffers(1, &VBO);
		// Initialization code using Vertex Array Object (VAO) (done once (unless the object frequently changes))
		glGenVertexArrays(1, &VAO);
		//initialise the index buffer
		glGenBuffers(1, &EBO);
		// Bind Vertex Array Object
		glBindVertexArray(VAO);
		// Copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sq_vertices), sq_vertices, GL_STATIC_DRAW);
		//set up the EBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		
		// Then set our vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		// Then set our colour data
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		
		//set the texture coordinates attribute pointer
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		

		//Unbind the VAO
		glBindVertexArray(0);



	}

	void render()
	{
		//draw the square 
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

	}

};

class Brick
{
public:
	//set up vertex buffer object
	GLuint VBO;
	//set up vertex array object
	GLuint VAO;
	//set up index buffer object
	GLuint EBO;

	//shader for the square
	Shader vSh4, fSh4;
	GLuint shaderProgram4;
	Texture tex;
	//constructor
	Brick()
	{
		//shaders
		vSh4.shaderFileName("..//..//Assets//Shaders//shader_Projection_basicLight.vert");
		fSh4.shaderFileName("..//..//Assets//Shaders//shader_Projection_basicLight.frag");

		vSh4.getShader(1);
		fSh4.getShader(2);

		shaderProgram4 = glCreateProgram();
		glAttachShader(shaderProgram4, vSh4.shaderID);
		glAttachShader(shaderProgram4, fSh4.shaderID);
		glLinkProgram(shaderProgram4);

		glDeleteShader(vSh4.shaderID);
		glDeleteShader(fSh4.shaderID);

		//load the texture file
		tex.load("..//..//Assets//Textures//United_Kingdom.jpg");
	};


	//define vertices for the square
	GLfloat sq_vertices[32] = {
		//vertices				colour				texture coordinates    
		0.1f, 0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		0.1f, -0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,	 1.0f, 0.0f,
		-0.1f, -0.1f, 0.0f,		0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		-0.1f, 0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,   0.0f, 1.0f
	};
	//define indices for the square
	GLuint indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	void setBuffers()
	{
		//
		//OpenGL buffers
		//set up 1 for the triangle
		glGenBuffers(1, &VBO);
		// Initialization code using Vertex Array Object (VAO) (done once (unless the object frequently changes))
		glGenVertexArrays(1, &VAO);
		//initialise the index buffer
		glGenBuffers(1, &EBO);
		// Bind Vertex Array Object
		glBindVertexArray(VAO);
		// Copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sq_vertices), sq_vertices, GL_STATIC_DRAW);
		//set up the EBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// Then set our vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		// Then set our colour data
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		//set the texture coordinates attribute pointer
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);


		//Unbind the VAO
		glBindVertexArray(0);
		//texture buffers
		tex.setBuffers();

	}

	void render()
	{


		//draw the square 
		glUseProgram(shaderProgram4);
		glBindTexture(GL_TEXTURE_2D, tex.texture);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

};

class Brick1
{
public:
	//set up vertex buffer object
	GLuint VBO;
	//set up vertex array object
	GLuint VAO;
	//set up index buffer object
	GLuint EBO;

	//shader for the square
	Shader vSh5, fSh5;
	GLuint shaderProgram5;
	Texture tex;
	//constructor
	Brick1()
	{
		//shaders
		vSh5.shaderFileName("..//..//Assets//Shaders//shader_Projection_basicLight.vert");
		fSh5.shaderFileName("..//..//Assets//Shaders//shader_Projection_basicLight.frag");

		vSh5.getShader(1);
		fSh5.getShader(2);

		shaderProgram5 = glCreateProgram();
		glAttachShader(shaderProgram5, vSh5.shaderID);
		glAttachShader(shaderProgram5, fSh5.shaderID);
		glLinkProgram(shaderProgram5);

		glDeleteShader(vSh5.shaderID);
		glDeleteShader(fSh5.shaderID);

		//load the texture file
		tex.load("..//..//Assets//Textures//blue.jpg");
	};

	//define vertices for the square
	GLfloat sq_vertices[32] = {
		//vertices				colour				texture coordinates    
		0.1f, 0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		0.1f, -0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,	 1.0f, 0.0f,
		-0.1f, -0.1f, 0.0f,		0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		-0.1f, 0.1f, 0.0f,		 0.0f, 1.0f, 0.0f,   0.0f, 1.0f
	};
	//define indices for the square
	GLuint indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	void setBuffers()
	{
		//
		//OpenGL buffers
		//set up 1 for the triangle
		glGenBuffers(1, &VBO);
		// Initialization code using Vertex Array Object (VAO) (done once (unless the object frequently changes))
		glGenVertexArrays(1, &VAO);
		//initialise the index buffer
		glGenBuffers(1, &EBO);
		// Bind Vertex Array Object
		glBindVertexArray(VAO);
		// Copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sq_vertices), sq_vertices, GL_STATIC_DRAW);
		//set up the EBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// Then set our vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		// Then set our colour data
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		//set the texture coordinates attribute pointer
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);


		//Unbind the VAO
		glBindVertexArray(0);
		//texture buffers
		tex.setBuffers();

	}

	void render()
	{


		//draw the square 
		glUseProgram(shaderProgram5);
		glBindTexture(GL_TEXTURE_2D, tex.texture);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

};
/*
class Block : public Square
{
public:
	//Constructor
	Block();
	glm::vec3 pos;
	glm::vec3 scale;
	glm::vec3 color;
	GLfloat rotation;
	Texture texture;
	Texture cracked;
	GLint hits;
	bool blockAlive;
	bool blockDead;
};*/