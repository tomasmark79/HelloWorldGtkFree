// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#include <gtkmm/application.h> // order is important // replaced functionalitty of Logger.hpp
#include <GtkLib/GtkLib.hpp>
#include <GtkLibWidget/GtkLibWidget.hpp>

#include <Logger/Logger.hpp>
#include <Utils/Utils.hpp>

namespace dotname {

  GtkLib::GtkLib () {
    LOG_D_STREAM << libName_ << " ...constructed" << std::endl;
  }

  GtkLib::GtkLib (const std::filesystem::path& assetsPath, int argc, char* argv[]) {
    assetsPath_ = assetsPath;
    if (!assetsPath_.empty ()) {
      LOG_D_STREAM << "Assets path: " << assetsPath_ << std::endl;
    } else {
      LOG_D_STREAM << "Assets path is empty" << std::endl;
    }

    auto app = Gtk::Application::create ("name.digitalspace.helloworldgtk");
    app->make_window_and_run<GtkLibWidget> (argc, argv);
  }
  GtkLib::~GtkLib () {
    LOG_D_STREAM << libName_ << " ...destructed" << std::endl;
  }

} // namespace dotname