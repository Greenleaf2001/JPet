#pragma once

#include <wrl.h>
#include <wil/com.h>
#include <webview2.h>

#include <string>

/**
 * @brief A simple wrapper for webview of game info
 */
class GamePanel {
 public:
  /**
   * @brief Construct a new GamePanel object
   *
   * @param[in] parent The parent window handle
   */
  GamePanel(HWND parent, HINSTANCE instance);

  /**
   * @brief Destroy the GamePanel object
   */
  ~GamePanel();

  /**
   * @brief Navigate to the given URL
   *
   * @param[in] url The URL to navigate to
   */
  void Navigate(const std::string& url);

  /**
   * @brief Resize the panel
   *
   * @param[in] width The new width
   * @param[in] height The new height
   */
  void Resize(int width, int height);

  /**
   * @brief Show the panel
   */
  void Show();

  /**
   * @brief Hide the panel
   */
  void Hide();

  /**
   * @brief Check if the panel is visible
   *
   * @return true if the panel is visible
   */
  bool IsVisible();

  wil::com_ptr<ICoreWebView2Controller> webviewController;

 private:
  HWND _parent;
  HWND _window;
  HINSTANCE _instance;
  bool _visible;

  wil::com_ptr<ICoreWebView2> webview;

  void WindowProc();
};