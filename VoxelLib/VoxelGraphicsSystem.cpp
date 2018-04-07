#include "VoxelGraphicsSystem.h"
#include <gl/GL.h>

namespace voxel
{
	VoxelGraphicsSystem* VoxelGraphicsSystem::spInstance = nullptr;

	VoxelGraphicsSystem* VoxelGraphicsSystem::getInstance()
	{
		return spInstance;
	}

	bool VoxelGraphicsSystem::initInstance()
	{
		if (!spInstance)
		{
			std::cout << "Creating a new instance of Voxel Graphics System." << std::endl;
			spInstance = new VoxelGraphicsSystem();
		}

		return spInstance;
	}

	void VoxelGraphicsSystem::cleanupInstance()
	{
		if (spInstance)
		{
			delete spInstance;
			spInstance = nullptr;
		}
	}

	VoxelGraphicsSystem::VoxelGraphicsSystem()
	{

	}

	VoxelGraphicsSystem::~VoxelGraphicsSystem()
	{
		cleanup();
	}

	void VoxelGraphicsSystem::cleanup()
	{
		
	}
}