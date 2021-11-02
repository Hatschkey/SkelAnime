#ifndef SKELANIME_PROPERTY_GUI
#define SKELANIME_PROPERTY_GUI

#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImGuiFileBrowser.h"

#include <map>

#include "Scene.hpp"

class PropertyGUI {

	enum DisplayableWindows {
		ARMATURE,
		HELP
	};

private:
	std::map <DisplayableWindows, bool> shouldDisplay;
	std::vector<bool> displayProperties;
	Scene* scene;

protected:

	void DrawBonePropertyWindow(std::vector<Bone>& bones, int index);
	void RenderBoneTree(std::vector<Bone>& bones, int boneIndex);
	void DrawArmatureWindow();
	void DrawHelpWindow();
	void DrawMenuBar();

public:
	PropertyGUI(GLFWwindow* drawnToWindow, Scene* scene);
	virtual ~PropertyGUI();

	void Draw();
};

#endif // SKELANIME_PROPERTY_GUI
