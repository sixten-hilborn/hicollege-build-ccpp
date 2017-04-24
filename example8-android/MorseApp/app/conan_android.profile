[settings]
os=Android
compiler=clang
compiler.version=3.8
compiler.libcxx=libstdc++


[options]
# Linux:
android-toolchain:ndk_path=~/Android/Sdk/ndk-bundle
# Windows:
# android-toolchain:ndk_path=~/AppData/local/Android/Sdk/ndk-bundle
# OSX:
# android-toolchain:ndk_path=~/Library/Android/sdk/ndk-bundle


[build_requires]
*:android-toolchain/r13b@lasote/testing