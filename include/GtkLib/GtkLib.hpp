// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#ifndef __GTKLIB_HPP
#define __GTKLIB_HPP

#include <GtkLib/version.h>
#include <filesystem>
#include <string>

// Public API

namespace dotname {

  class GtkLib {
  private:
    const std::string libName_ = std::string ("GtkLib v.") + GTKLIB_VERSION;
    std::filesystem::path assetsPath_;

  public:
    GtkLib ();
    GtkLib (const std::filesystem::path& assetsPath, int argc, char* argv[]);
    ~GtkLib ();

    const std::filesystem::path getAssetsPath () const {
      return assetsPath_;
    }
    void setAssetsPath (const std::filesystem::path& assetsPath) {
      assetsPath_ = assetsPath;
    }
  };

} // namespace dotname

#endif // __GTKLIB_HPP