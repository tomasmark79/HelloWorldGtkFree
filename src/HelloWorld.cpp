// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#include <HelloWorld/HelloWorld.hpp>
#include <HelloWorld/version.h>
#include <Logger/Logger.hpp>
#include <Utils/Utils.hpp>

#include <gtkmm/application.h>

namespace library
{

  HelloWorldGtk::HelloWorldGtk ()
    : m_button (
        "Hello World") // creates a new button with label "Hello World".
  {
    // Sets the margin around the button.
    m_button.set_margin (10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    m_button.signal_clicked ().connect (
      sigc::mem_fun (*this, &HelloWorldGtk::on_button_clicked));

    // This packs the button into the Window (a container).
    set_child (m_button);

    set_title ("DotNameCpp Template");
    set_default_size (320, 100);
  }

  HelloWorldGtk::~HelloWorldGtk () {}

  void HelloWorldGtk::on_button_clicked ()
  {
    std::cout << "Hello World from Gtk" << std::endl;
  }

  HelloWorld::HelloWorld (const std::string &assetsPath, int argc, char **argv)
    : m_assetsPath (assetsPath)
  {
    LOG_INFO ("HelloWorld v." + std::string (HELLOWORLD_VERSION)
              + " constructed.");
    LOG_DEBUG ("Assets Path: " + this->m_assetsPath);

    auto app = Gtk::Application::create ("name.digitalspace.helloworldgtk");

    app->make_window_and_run<HelloWorldGtk> (argc, argv);
  }

  HelloWorld::~HelloWorld () { LOG_DEBUG ("HelloWorld deconstructed."); }

} // namespace library