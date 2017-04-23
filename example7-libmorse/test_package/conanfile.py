from conans import ConanFile, CMake
from conans.tools import cross_building
import os


channel = os.getenv("CONAN_CHANNEL", "stable")
username = os.getenv("CONAN_USERNAME", "hilborn")


class LibmorseTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "LibMorse/0.1@%s/%s" % (username, channel)
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is in "test_package"
        cmake.configure(build_dir=".")
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")

    def test(self):
        if not cross_building(self.settings):
            self.run("cd bin && .{0}example".format(os.sep))
            #CMake(self).test(target="example")
