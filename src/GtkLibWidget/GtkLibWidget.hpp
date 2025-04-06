// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#ifndef __GTKLIBWIDGET_HPP
#define __GTKLIBWIDGET_HPP

#include <filesystem>
#include <string>

#include <gtkmm/window.h>
#include <gtkmm/button.h>

namespace dotname {

  class GtkLibWidget : public Gtk::Window {

  private:
    std::filesystem::path assetsPath_;

  protected:
    Gtk::Button buttonHello_;
    Gtk::Button buttonClose_;
    void onButtonHelloClicked ();
    void onButtonCloseClicked ();

  public:
    GtkLibWidget ();
    GtkLibWidget (const std::filesystem::path& assetsPath);
    ~GtkLibWidget () override;

    const std::filesystem::path getAssetsPath () const {
      return assetsPath_;
    }
    void setAssetsPath (const std::filesystem::path& assetsPath) {
      assetsPath_ = assetsPath;
    }
  };

} // namespace dotname

#endif // __GTKLIBWIDGET_HPP