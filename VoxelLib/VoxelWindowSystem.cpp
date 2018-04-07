#include "VoxelWindowSystem.h"
#include "VoxelWindow.h"

#include <iostream>
#include <GLFW/glfw3.h>

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

		return spInstance->initGLFW();
	}

	void VoxelWindowSystem::cleanupInstance()
	{
		if (spInstance)
		{
			delete spInstance;
			spInstance = nullptr;
		}
	}

	VoxelWindowSystem::VoxelWindowSystem()
	{

	}

	VoxelWindowSystem::~VoxelWindowSystem()
	{
		cleanup();
	}

	bool VoxelWindowSystem::initGLFW()
	{
		if (mIsInitialized)
		{
			std::cout << "GLFW is already initialized." << std::endl;
		}
		else if (glfwInit())
		{
			mIsInitialized = true;
		}
		else
		{
			std::cout << "Error initalizing GLFW." << std::endl;
			cleanupInstance();
		}
		
		return mIsInitialized;
	}

	void VoxelWindowSystem::cleanup()
	{
		if (mIsInitialized)
		{
			cleanupWindows();
			mIsInitialized = false;
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
}