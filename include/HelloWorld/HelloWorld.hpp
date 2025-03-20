#ifndef __HELLOWORLD_H__
#define __HELLOWORLD_H__

// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#include <gtkmm/button.h>
#include <gtkmm/window.h>

#include <string>
// Public API

namespace library
{

  class HelloWorldGtk : public Gtk::Window
  {

  public:
    HelloWorldGtk ();
    ~HelloWorldGtk () override;

  protected:
    void on_button_clicked ();
    Gtk::Button m_button;

  }; // class HelloWorldGtk

  class HelloWorld
  {
  public:
    HelloWorld (const std::string &assetsPath, int argc, char **argv);
    ~HelloWorld ();

    // alternatively, you can use a getter function
    const std::string getAssetsPath () const { return m_assetsPath; }

  private:
    std::string m_assetsPath;
  }; // class HelloWorld

} // namespace library

#endif // __HELLOWORLD_H__
