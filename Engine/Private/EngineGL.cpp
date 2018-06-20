#include "..\Public\EngineGL.h"
#include "GL\glew.h"
#include "SDL.h"
#include "Engine\Public\Core\Time.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\ColorF.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Engine\Public\Core\Shaders.h"
#include "Engine\Public\Utils\Matrix4.h"
#include "Engine\Public\Core\FMath.h"
#include "Game\Public\IGame.h"

#define ATTRIB_POINT 0
#define countof(x) (sizeof(x) / sizeof(0[x]))

const float SQUARE[] = {
	-1.0f,  1.0f,
	-1.0f, -1.0f,
	1.0f,  1.0f,
	1.0f, -1.0f
};

int EngineGL::Init(IGame * pGame, const char * pTitle, const int & pWidth, const int & pHeight)
{
	// Initialize video and audio subsystems
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		// Some error
		return 1;
	}

	// Initialize a window with the opengl flags
	mWindow = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pWidth, pHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS );

	mWindowWidth = pWidth;
	mWindowHeight = pHeight;

	// Window was not successfully created
	if (mWindow == nullptr)
	{
		SDL_Quit();
		return 1;
	}

	// Create the opengl context associated with the window
	mGLContext = SDL_GL_CreateContext(mWindow);

	// Apparently we have to do this, otherwise some of the glew functions will crash, also GL_TRUE is just a macro for 1, which means true
	glewExperimental = GL_TRUE;

	// Initialize the extension entry points. So this has to be callled after creating the context. It returns an error type
	GLenum error = glewInit();

	// Ignore the error
	glGetError();

	// Check if the error is OK
	if (error != GLEW_OK)
	{
		// Cleanup
		SDL_GL_DeleteContext(mGLContext);
		SDL_DestroyWindow(mWindow);

		// Simply quit all subsystems in sdl
		SDL_Quit();
		return 1;
	}

	// This makes our buffer swap synchronized with the monitor's vertical refresh
	// Double buffering
	if (SDL_GL_SetSwapInterval(1) != 0)
	{
		// Cleanup
		SDL_GL_DeleteContext(mGLContext);
		SDL_DestroyWindow(mWindow);

		// Simply quit all subsystems in sdl
		SDL_Quit();
		return 1;
	}

	// do depth comparisons and update the depth buffer
	glEnable(GL_DEPTH_TEST);

	// updates to the shaders so they they'll A) draw in the correct space B) we can control the colour
	/*const GLchar *vert_shader =
		"#version 330\n"
		"layout(location = 0) in vec2 point;\n"
		"uniform float angle;\n"
		"void main() {\n"
		"    gl_Position = vec4(0.75 * point, 0.0, 1.0);\n"
		"}\n";*/

	const GLchar *vert_shader =
		"#version 330\n"
		"layout(location = 0) in vec2 point;\n"
		"uniform mat4 model, view, proj;\n"
		"uniform vec2 size;\n"
		"void main() {\n"
		"    gl_Position = proj * view * model * vec4(size * point, 0.0, 1.0);\n"
		"}\n";
	const GLchar *frag_shader =
		"#version 330\n"
		"layout(location = 0) out vec4 color;\n"
		"uniform vec3 in_color;\n"
		"void main() {\n"
		"    color = vec4(in_color, 0);\n"
		"}\n";

	// compile and link OpenGL program
	GLuint vert = Shaders::CompileShader(GL_VERTEX_SHADER, vert_shader);
	GLuint frag = Shaders::CompileShader(GL_FRAGMENT_SHADER, frag_shader);

	mGC.mProgram = Shaders::LinkProgram(vert, frag);
	mGC.mUniformAngle = glGetUniformLocation(mGC.mProgram, "in_color");

	glDeleteShader(frag);
	glDeleteShader(vert);

	// prepare vertex buffer object (VBO)
	glGenBuffers(1, &mGC.mVBOPoint);
	glBindBuffer(GL_ARRAY_BUFFER, mGC.mVBOPoint);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SQUARE), SQUARE, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// prepare vertex array object (VAO)
	glGenVertexArrays(1, &mGC.mVAOPoint);
	glBindVertexArray(mGC.mVAOPoint);
	glBindBuffer(GL_ARRAY_BUFFER, mGC.mVAOPoint);
	glVertexAttribPointer(ATTRIB_POINT, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(ATTRIB_POINT);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void EngineGL::Run(IGame * pGame)
{
	// Loop until the user quits
	while (true)
	{
		// Union that contains structs for different event types
		SDL_Event e;
		// It dequeues events
		// Pass the address of e, so that the contents of the pointer can be modified, hence modifying e
		// In C++ you would use aliases &
		// Returns 1 if there was an event
		if (SDL_PollEvent(&e) != 0)
		{
			// Check if the user pressed the quit button
			// The program will not quit if we do not tell it to quit
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}

		// Color
		Color clearColor = Color(0, 0, 0, 255);

		ColorF clearColorF = clearColor.ToColorF();

		glClearColor(clearColorF.R, clearColorF.G, clearColorF.B, clearColorF.A);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Determines the delta time, for now 
		Time::Update();

		DrawRect(Vector2(400.0f, 300.0f), Vector2(790.0f, 590.0f), Color(100, 255, 255));

		// Double buffer
		SDL_GL_SwapWindow(mWindow);
	}
}

void EngineGL::Quit(IGame * pGame) const
{
	// Cleanup
	SDL_GL_DeleteContext(mGLContext);
	SDL_DestroyWindow(mWindow);

	// Simply quit all subsystems in sdl
	SDL_Quit();
}

void EngineGL::DrawLine(const Vector2 & pOrigin, const Vector2 & pTarget, const Color & pColor)
{
}

void EngineGL::DrawFillCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor)
{
}

void EngineGL::DrawCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor)
{
}

void EngineGL::DrawRect(const Vector2 & pTopLeft, const Vector2 & pBotRight, const Color & pColor)
{
	// the three matrices we need
	Matrix4 orthographicProjection;
	Matrix4 model;
	Matrix4 view;

	// Dimensions
	// I had an epiphany
	float size[2] = { FMath::Abs(pBotRight.x - pTopLeft.x) / 2.0f, FMath::Abs(pBotRight.y - pTopLeft.y) / 2.0f };

	// projection matrix
	Matrix4::OrthographicProjectionMatrix(&orthographicProjection, 800.0f, 600.0f, -100.0f, 100.0f);

	// view matrix (really just an identity matrix, maybe optimize this call?)
	// This is the pivot
	Matrix4::MakeTranslationMatrix(&view, Vector2(size[0], size[1]));

	// positions of the uniforms
	int view_mat_location;
	int proj_mat_location;
	int model_mat_location;
	int size_vec_location;

	glUseProgram(mGC.mProgram);

	ColorF colorF = pColor.ToColorF();

	float color[3] = { colorF.R, colorF.G, colorF.B };
	glUniform3fv(mGC.mUniformAngle, 1, &color[0]);

	Matrix4::MakeTranslationMatrix(&model, pTopLeft); // position of the object
	model.m43 = -1.0f; // this is the "layer", cast from int to float

	view_mat_location = glGetUniformLocation(mGC.mProgram, "view");
	glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, view.ToFloatPtr());
	proj_mat_location = glGetUniformLocation(mGC.mProgram, "proj");
	glUniformMatrix4fv(proj_mat_location, 1, GL_FALSE, orthographicProjection.ToFloatPtr());
	model_mat_location = glGetUniformLocation(mGC.mProgram, "model");
	glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, model.ToFloatPtr());
	size_vec_location = glGetUniformLocation(mGC.mProgram, "size");
	glUniform2fv(size_vec_location, 1, &size[0]);
	
	glBindVertexArray(mGC.mVAOPoint);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, countof(SQUARE) / 2);
	glBindVertexArray(0);
	glUseProgram(0);
}

void EngineGL::DrawText(std::string pFontFile, const int & pFontSize, const std::string pMessage, const Vector2 & pPosition, const Color & pColor)
{
}
