<h3>How To Install OpenCV</h3>

- Download from https://opencv.org/releases/
- Extract into a folder
- Add Variable to Path in System variables (C\opencv\build\bin)
- Create Empty c++ Project in Visual Studio 
- Change Debug to x64
- In solution Properties > C/C++ > General >  Additional Include Directories (C:\opencv\build\include) 
- In Solution Properties > Linker > General > Additional Library Directories (C:\opencv\build\x64\vc14\lib)
- In Solution Properties > Linker > Input > select the file with d.lib, this contains the Debugger Options for your project. (opencv_world430d.lib;)
- Add Source File
- Happy Coding!