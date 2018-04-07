#include "VoxelWindowSystem.h"
#include "VoxelWindow.h"

#include <iostream>

namespace voxel
{
	VoxelWindowSystem* VoxelWindowSystem::spInstance = nullptr;

	VoxelWindowSystem* VoxelWindowSystem::getInstance()
	{
		return spInstance;
	}

	bool VoxelWindowSystem::initInstance()
	{
		if (!spInstance)
		{
			std::cout << "Creating a new instance of Voxel Window System." << std::endl;
			spInstance = new VoxelWindowSystem();
		}

		return spInstance->initWindowSystem();
	}

	void VoxelWindowSystem::cleanupInstance()
	{
		if (spInstance)
		{
			delete spInstance;
			spInstance = nullptr;
		}
	}

	VoxelWindow* VoxelWindowSystem::createWindow(std::string windowID, std::string windowTitle, GLuint windowWidth, GLuint windowHeight)
	{
		if (mWindows.find(windowID) != mWindows.end())
		{
			throw(std::exception(("There is already a window with ID: \'" + windowID + "\'.").c_str()));
		}

		VoxelWindow* window = new VoxelWindow(windowID, windowTitle, windowWidth, windowHeight);

		window->initWindowHints();
		VoxelWindow::makeWindowCurrent(window);
		
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			delete window;
			throw(std::exception(("Error initalizing GLAD for window ID: \'" + windowID + "\'.").c_str()));
		}
		else
		{
			mWindows.insert(std::make_pair(windowID, window));
		}

		return window;
	}

	VoxelWindow* VoxelWindowSystem::getWindow(std::string windowID) const
	{
		auto windowIter = mWindows.find(windowID);

		if (windowIter == mWindows.end())
		{
			throw(std::exception(("No window with ID: \'" + windowID + "\'.").c_str()));
		}

		return windowIter->second;
	}

	VoxelWindowSystem::VoxelWindowSystem()
	{

	}

	VoxelWindowSystem::~VoxelWindowSystem()
	{
		cleanup();
	}

	GLboolean VoxelWindowSystem::initWindowSystem()
	{
		if (mIsInitialized)
		{
			std::cout << "The Voxel Window System is already initialized." << std::endl;
		}
		else
		{
			if (!glfwInit())
			{
				std::cout << "Error initalizing GLFW." << std::endl;
				cleanupInstance();
			}
			else
			{
				mIsInitialized = GL_TRUE;
			}
		}
		
		return mIsInitialized;
	}

	void VoxelWindowSystem::cleanup()
	{
		if (mIsInitialized)
		{
			cleanupWindows();
			glfwTerminate();
			mIsInitialized = GL_FALSE;
		}
	}

	void VoxelWindowSystem::cleanupWindows()
	{
		auto windowIter = mWindows.begin();
		for (; windowIter != mWindows.end(); ++windowIter)
		{
			if (windowIter->second)
			{
				delete windowIter->second;
			}
		}

		mWindows.clear();
	}

	void VoxelWindowSystem::cleanupWindow(std::string windowID)
	{
		auto windowIter = mWindows.find(windowID);

		if (windowIter != mWindows.end())
		{
			delete windowIter->second;
		}
		else
		{
			std::cout << "No window found with id: \'" << windowID << "\'." << std::endl;
		}
	}
}