.. _installation_instruction:

Installation Instructions
=========================

To compile OD from source, install its dependencies as stated below.


Dependencies
------------

1. OpenCV 3.0 or above
    
    :Source: http://opencv.org/downloads.html or https://github.com/Itseez/opencv
    
        
    Required setting
    
    - OpenCV contrib (for xfeatures2d module handing SIFT/SURF features):
     
           Detailed instructions with source: https://github.com/itseez/opencv_contrib
           (make sure to get the same version of OpenCV and OpenCV contrib)
           
           :Additional CMAKE options: OPENCV_EXTRA_MODULES_PATH=<opencv_contrib>/modules
           
    - OpenCV CUDA module (for GPU enabled feature detectors and matcher): 
    
            CUDA Downloads: https://developer.nvidia.com/cuda-downloads
            Detailed installation instructions: http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html
    
           :Additional CMAKE options: WITH_CUDA=ON
           
    - VTK 5.x.x or 6.x.x
    
            VTK Downloads: https://www.vtk.org/download/
            Detailed installation instructions: https://www.vtk.org/Wiki/VTK/Configure_and_Build
            (No need to build VTK with QT)
            
            :Additional CMAKE options: WITH_VTK=ON

    
    Compile and install Opencv 3.0 with the above settings.
 
 
2. VTK 7.0 or above
    
    Just download and compile latest VTK with its default settings.
    (Don't worry about having 2 different VTK versions on your system)
    
   
3. PCL 1.6 or above    
    
    *Source:* https://github.com/PointCloudLibrary/pcl or https://github.com/PointCloudLibrary/pcl/releases
    
    Required settings:
    
    * 3d_rec_framework (for ESF, ESF etc recognition pipeline)
    
        :Additional CMAKE options: BUILD_apps=ON, BUILD_apps_3d_rec_framework=ON
    
4. Eigen

    Get the latest version of Eigen (source) using your package manager.

5. SVMLight

    We use SVMLight for training. To user the feature of training using SVMLight, you need to download the source and put     in a specific folder (we could not include the source in 3rdparty because of its restrictive licence). Please see         http://svmlight.joachims.org/ for the details and terms of use.

    Download the source code from http://svmlight.joachims.org/ and extract it to opendetection/3rdparty/svmlight. You         should have files like svm_common.c, svm_learn.c, etc. under the directory opendetection/3rdparty/svmlight.

6. Additional dependencies

    These may or may not be present on your system already:
    
    - FreeGlut (package name - freeglut3-dev)
    - libusb (package name - lib-1.0.0-dev)
    - Flann (package name - libflann-dev)
    - GLEW (package name - libglew-dev)
    
Installing Open Detection
-------------------------
Download the source from https://github.com/krips89/opendetection. With the above dependencies installed, OD should compile fine. The code while platform independent, is only tested and run in Linux machine. Instructions for the usage for linux are provided below:

Compile out of source using cmake+your favorite compiler. For example:

Download the code::

    cd <path_to_desired_download_location>
    git clone https://github.com/krips89/opendetection.git

configure with CMake and compile::

    cd <path_to_source>
    mkdir build; cd build
    cmake ..
    make
    make install

