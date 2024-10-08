//
// 由管理员于2023年7月5日创建。
//

#ifndef KIG_IMGUIEGL_H
#define KIG_IMGUIEGL_H

#include "pch.h"

#include "ImGui_Menu.h"
#include "JniTool.h"
class ImGui_Init {
public:
    // 触摸事件枚举
    enum eTouchEvent {
        TOUCH_DOWN,
        TOUCH_UP,
        TOUCH_MOVE,
        TOUCH_CANCEL,
        TOUCH_OUTSIDE
    };

    // EGL
    EGLNativeWindowType     SurfaceWin;
    EGLDisplay              g_EglDisplay;
    EGLSurface              g_EglSurface;
    EGLConfig               mEglConfig;
    EGLContext              g_EglContext;

    std::string             g_IniFilename = "";
    bool                    g_Initialized = false;
    char*                   g_LogTag = { "ImGuiExample" };
    int                     FPS = { 60 };

    // ImGui
    ImGuiIO*                imGuiIo;
    ImGuiStyle*             imGuiStyle;
    ImGuiWindow*            g_Window = nullptr;
    ImGuiContext*           g_Context = nullptr;
    ImFont*                 imFont;

    ImVector<ImGuiWindow*>  WinList;

    ImVec2 DisplaySize;
    AAssetManager* assetManager;
    ImGui_Init();

    // EGL初始化函数
    int InitEGL();

    // ImGui初始化和渲染
    void ImGuiNewFrame();
    void ImGuiRender();

    // Egl操作的线程
    void EglThread();

    // 使用JNIEnv和jobject进行初始化
    void init(JNIEnv* env, jobject surface);

    // 示例窗口函数
    void MyWindowFunction();
    void SetAAssetManager(AAssetManager* assetManager);
    // 输入事件处理
    void InputTouchEvent(int event_get_action, float x, float y);

    void Start();
    int GetAssetData(const char* filename, void** outData);
    void UpDisplaySize(int width,int height);

    ~ImGui_Init();
private:
    void LoadFont();
};

#endif // KIG_IMGUIEGL_H
