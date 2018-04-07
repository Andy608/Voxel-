#ifndef VOXEL_WINDOW_H_
#define VOXEL_WINDOW_H_

#include <string>
#include <Trackable.h>
#include "VoxelIncludes.h"

namespace voxel
{
	class VoxelWindow : public Trackable
	{
		friend class VoxelWindowSystem;

	public:
		VoxelWindow(const VoxelWindow& copy) = delete;
		void operator=(const VoxelWindow& copy) = delete;

		void setTitle(std::string title);
		inline const std::string& getTitle() const { return mTitle; };
		inline const std::string& getID() const { return mID; };

		static void makeWindowCurrent(VoxelWindow* window);
		void showWindow() const;
		void hideWindow() const;

		static void clearColor(VoxelWindow* window);
		void flip();
		void setViewport(GLuint startX, GLuint startY, GLuint width, GLuint height) const;

	private:
		const std::string mID;//ID used in VoxelWindowSystem

		std::string mTitle;
		GLFWwindow* mWindowHandle;

		VoxelWindow(std::string windowID, std::string windowTitle, GLuint windowWidth, GLuint windowHeight);
		~VoxelWindow();

		//For now set default window hints.
		void initWindowHints();
	};
}

#endif