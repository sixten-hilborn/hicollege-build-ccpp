from conans import ConanFile, CMake
from conans.tools import download, unzip
import os


class LibmorseConan(ConanFile):
    name = "LibMorse"
    version = "0.1"
    generators = "cmake"
    settings = "os", "arch", "compiler", "build_type"
    options = {
        "shared": [True, False]
    }
    default_options = "shared=False"
    exports = ["CMakeLists.txt"]
    url = "https://github.com/k4r573n/LibMorse"

    def configure(self):
        del self.settings.compiler.libcxx

    def source(self):
        zip_name = "libmorse.zip"
        download("https://github.com/k4r573n/LibMorse/archive/b1b05e16a8e74f3859838b82dbe817b06cc44c90.zip", zip_name)
        unzip(zip_name)
        os.unlink(zip_name)

    def build(self):
        defs = {"CMAKE_INSTALL_PREFIX": "install"}
        cmake = CMake(self)
        cmake.configure(defs=defs)
        cmake.build(target="install")

    def package(self):
        # Copy header file(s)
        self.copy("*.h", dst="include", src="install/include")

        # Copy static and dynamic libs
        self.copy("*.dll", dst="bin", src="install", keep_path=False)
        self.copy("*.dylib", dst="lib", src="install", keep_path=False)
        self.copy("*.so*", dst="lib", src="install", keep_path=False)
        self.copy("*.a", dst="lib", src="install", keep_path=False)
        self.copy("*.lib", dst="lib", src="install", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ['morse']
