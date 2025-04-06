// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#include <GtkLibWidget/GtkLibWidget.hpp>
#include <gtkmm/box.h>

#include <Logger/Logger.hpp>
#include <Utils/Utils.hpp>

namespace dotname {

  GtkLibWidget::GtkLibWidget () : buttonHello_ ("Hello DotName"), buttonClose_ ("Close Window") {

    auto box = Gtk::make_managed<Gtk::Box> (Gtk::Orientation::VERTICAL, 10);

    box->append (buttonHello_);
    box->append (buttonClose_);

    buttonHello_.set_margin (10);
    buttonHello_.signal_clicked ().connect (
        sigc::mem_fun (*this, &GtkLibWidget::onButtonHelloClicked));

    buttonClose_.set_margin (10);
    buttonClose_.signal_clicked ().connect (
        sigc::mem_fun (*this, &GtkLibWidget::onButtonCloseClicked));

    // This packs the button into the Window (a container).
    set_child (*box);

    set_title ("DotNameCpp Template");
    set_default_size (320, 100);
  }

  GtkLibWidget::GtkLibWidget (const std::filesystem::path& assetsPath) {
    assetsPath_ = assetsPath;
    if (!assetsPath_.empty ()) {
      LOG_D_STREAM << "Assets path: " << assetsPath_ << std::endl;
    } else {
      LOG_D_STREAM << "Assets path is empty" << std::endl;
    }
  }

  GtkLibWidget::~GtkLibWidget () {
  }

  void GtkLibWidget::onButtonHelloClicked () {
    LOG_I_STREAM << "Hello World from Gtk" << std::endl;
  }

  void GtkLibWidget::onButtonCloseClicked () {
    LOG_I_STREAM << "Close from Gtk" << std::endl;
  }

} // namespace dotname