#ifndef VOXEL_WINDOW_SYSTEM_H_
#define VOXEL_WINDOW_SYSTEM_H_

#include <map>
#include <string>
#include <Trackable.h>
#include "VoxelIncludes.h"
#include "VoxelWindow.h"

namespace voxel
{
	class VoxelWindowSystem : public Trackable
	{
		friend class VoxelWindow;

	public:
		static VoxelWindowSystem* getInstance();
		static bool initInstance();
		static void cleanupInstance();

		VoxelWindowSystem(const VoxelWindowSystem& copy) = delete;
		void operator=(const VoxelWindowSystem& copy) = delete;

		//Get the display size from VoxelMonitorInfo in the future.
		VoxelWindow* createWindow(std::string windowID, std::string windowTitle = "Hello, Voxel!", GLuint windowWidth = 960, GLuint windowHeight = 540);
		VoxelWindow* getWindow(std::string windowID) const;

	private:
		static VoxelWindowSystem* spInstance;
		GLboolean mIsInitialized = false;

		std::map<std::string, VoxelWindow*> mWindows;

		VoxelWindowSystem();
		~VoxelWindowSystem();

		GLboolean initWindowSystem();

		void cleanup();
		void cleanupWindows();
		void cleanupWindow(std::string windowID);
	};
}

#endif