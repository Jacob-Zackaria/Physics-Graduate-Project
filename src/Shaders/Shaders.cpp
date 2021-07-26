#include <sb6.h>
#include <math.h>
#include <assert.h>

#include "GameObject.h"
#include "MathEngine.h"
#include "File.h"
#include "Shader.h"
#include "Game.h"

Shader::Shader()
	:
	name(ShaderName::Name::NOT_INITIALIZED),
	programObject(0)
{

}

void Shader::Set(ShaderName::Name shaderName, const char * const shaderBaseFileName)
{
	this->name = shaderName;
	assert(shaderBaseFileName != 0);
	this->privCreateShader(this->programObject, shaderBaseFileName);
}

Shader::Shader( ShaderName::Name shaderName, const char * const shaderBaseFileName )
	: name (shaderName)
{
	assert( shaderBaseFileName != 0 );
	this->privCreateShader( this->programObject, shaderBaseFileName );
}

GLint Shader::GetLocation( const char * uniformName)
{
	assert( uniformName != 0 );
	GLint loc =  glGetUniformLocation(this->programObject, uniformName );
	assert( loc != -1 );

	return loc;
}

void Shader::SetActive()
{
	// Setup for shader
	glUseProgram(this->programObject);
}

bool Shader::privLoadNCompile(GLuint &shaderObject, const char * const shaderFileName, GLenum shader_type )
{
	FileHandle fh;
	FileError  ferror;

	ferror = File::open(fh, shaderFileName, FILE_READ );
	assert( ferror == FileError::FILE_SUCCESS );

	ferror = File::seek( fh,  FILE_SEEK_END, 0 );
	assert( ferror == FileError::FILE_SUCCESS );

	int numBytesInFile;
	ferror = File::tell( fh, numBytesInFile );
	assert( ferror == FileError::FILE_SUCCESS );
	assert(numBytesInFile >= 0);

	ferror = File::seek( fh,  FILE_SEEK_BEGIN, 0 );
	assert( ferror == FileError::FILE_SUCCESS );

	char *data =  new char [numBytesInFile + 1u];
	assert( data != 0 );

	ferror = File::read( fh, data, (unsigned int )numBytesInFile);
	assert( ferror == FileError::FILE_SUCCESS );

	// null termination character
	data[ numBytesInFile ] = 0;

	ferror = File::close( fh );
	assert( ferror == FileError::FILE_SUCCESS );

	// create a shader object
	shaderObject = glCreateShader(shader_type);
	assert( shaderObject != 0 );

	//load shader
    glShaderSource(shaderObject, 1, &data, 0);
	delete [] data;

	glCompileShader(shaderObject);

	// check for errors
    GLint status = 0;
    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &status);

	// found one
    if (!status)
    {
		char buffer[4096];
		glGetShaderInfoLog(shaderObject, 4096, NULL, buffer);

		printf("Error(ShaderLoadNCompile.cpp) %s: \n", shaderFileName);//, buffer);

		glDeleteShader(shaderObject);

		assert(false);
		return false;
    }
	else
	{
		return true;
	}
}

bool Shader::privCreateShader(  GLuint &progObject, const char * const shaderBaseFileName  )
{
	bool status;
	char nameBuff[128];
		
	assert( shaderBaseFileName != 0 );

	strcpy_s(nameBuff, 128, shaderBaseFileName);
	strcat_s(nameBuff, 128, ".fs.glsl");

	GLuint fs;
	status = privLoadNCompile( fs, nameBuff, GL_FRAGMENT_SHADER);
	assert( status == true );

	strcpy_s(nameBuff, 128, shaderBaseFileName);
	strcat_s(nameBuff, 128, ".vs.glsl");

	GLuint vs;
	status = privLoadNCompile( vs, nameBuff, GL_VERTEX_SHADER);
	assert( status == true );

	// Creates an empty program object
	progObject = glCreateProgram();

	//Attaches a shader object to a program object
	glAttachShader(progObject, vs);
	glAttachShader(progObject, fs);

	// Links a program object
	glLinkProgram(progObject);

	return true;
}
