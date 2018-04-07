#ifndef VOXEL_GRAPHICS_SYSTEM_H_
#define VOXEL_GRAPHICS_SYSTEM_H_

#include <Trackable.h>
#include "VoxelIncludes.h"

namespace voxel
{
	class VoxelGraphicsSystem : public Trackable
	{
		friend class VoxelWindowSystem;

	public:
		static VoxelGraphicsSystem* getInstance();
		static bool initInstance();
		static void cleanupInstance();

		VoxelGraphicsSystem(const VoxelGraphicsSystem& copy) = delete;
		void operator=(const VoxelGraphicsSystem& copy) = delete;

	private:
		static VoxelGraphicsSystem* spInstance;

		VoxelGraphicsSystem();
		~VoxelGraphicsSystem();

		void cleanup();
	};
}

#endif