#ifndef VOXEL_WINDOW_SYSTEM_H_
#define VOXEL_WINDOW_SYSTEM_H_

#include <map>
#include <string>
#include <Trackable.h>

namespace voxel
{
	class VoxelWindow;

	class VoxelWindowSystem : public Trackable
	{
	public:
		static VoxelWindowSystem* getInstance();
		static bool initInstance();
		static void cleanupInstance();

		VoxelWindowSystem(const VoxelWindowSystem& copy) = delete;
		void operator=(const VoxelWindowSystem& copy) = delete;

	private:
		static VoxelWindowSystem* spInstance;
		bool mIsInitialized = false;

		std::map<std::string, VoxelWindow*> mWindows;

		VoxelWindowSystem();
		~VoxelWindowSystem();

		bool initGLFW();
		void cleanup();
		void cleanupWindows();

	};
}

#endif