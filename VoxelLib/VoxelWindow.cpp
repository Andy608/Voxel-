#include "VoxelWindow.h"
#include "VoxelWindowSystem.h"
#include "VoxelIncludes.h"

namespace voxel
{
	VoxelWindow::VoxelWindow(std::string windowID, std::string windowTitle, GLuint windowWidth, GLuint windowHeight)
		try : mID(windowID), mTitle(windowTitle)
	{
		mWindowHandle = glfwCreateWindow(windowWidth, windowHeight, mTitle.c_str(), nullptr, nullptr);

		if (!mWindowHandle)
		{
			throw(std::exception("Error creating window."));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		VoxelWindowSystem::getInstance()->cleanupWindow(mID);
	}

	VoxelWindow::~VoxelWindow()
	{
		glfwDestroyWindow(mWindowHandle);
	}

	void VoxelWindow::setTitle(std::string title)
	{
		mTitle = title;
		glfwSetWindowTitle(mWindowHandle, mTitle.c_str());
	}

	void VoxelWindow::makeWindowCurrent(VoxelWindow* window)
	{
		if (window->mWindowHandle)
		{
			glfwMakeContextCurrent(window->mWindowHandle);
		}
		else
		{
			std::cout << "Cannot make window context current. Handle is null." << std::endl;
		}
	}

	void VoxelWindow::showWindow() const
	{
		if (mWindowHandle)
		{
			glfwShowWindow(mWindowHandle);
		}
		else
		{
			std::cout << "Cannot show window. Handle is null." << std::endl;
		}
	}

	void VoxelWindow::hideWindow() const
	{
		if (mWindowHandle)
		{
			glfwHideWindow(mWindowHandle);
		}
		else
		{
			std::cout << "Cannot hide window. Handle is null." << std::endl;
		}
	}

	void VoxelWindow::initWindowHints()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	}

	void VoxelWindow::clearColor(VoxelWindow* window)
	{
		glClearColor(1.0f, 0.8f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void VoxelWindow::flip()
	{
		glfwSwapBuffers(mWindowHandle);
	}

	void VoxelWindow::setViewport(GLuint startX, GLuint startY, GLuint width, GLuint height) const
	{
		glViewport(startX, startY, width, height);
	}
}