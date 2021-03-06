/*
Copyright (c) 2015, Kripasindhu Sarkar
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder(s) nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*//** \brief Example of the usage of cascade detector
   *
   * \author Kripasindhu Sarkar
   *
   */

#include <detectors/global2D/detection/ODCascadeDetector.h>
#include <detectors/global2D/detection/ODHOGDetector.h>
//#include "detectors/global2D/detection/ODHOGDetector.h"
#include "common/utils/ODFrameGenerator.h"

#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"


using namespace od;

int main(int argc, char *argv[])
{
  std::string trained_hog(argv[1]), images(argv[2]);

  //detector
  od::g2d::ODHOGDetector *detector = new od::g2d::ODHOGDetector;
  detector->setTrainedDataLocation(trained_hog);
  //detector->setSvmtype(g2d::ODHOGDetector::OD_DAIMLER_PEOPLE);
  detector->init();

  //get scenes
  od::ODFrameGenerator<od::ODSceneImage, od::GENERATOR_TYPE_FILE_LIST> frameGenerator(images);
  //GUI
  cv::namedWindow("Overlay", cv::WINDOW_NORMAL);
  while(frameGenerator.isValid() && cv::waitKey(1000) != 27)
  {
    od::ODSceneImage * scene = frameGenerator.getNextFrame();

    //Detect
    ODDetections2D *detections =  detector->detectOmni(scene);

    if(detections->size() > 0)
      cv::imshow("Overlay", detections->renderMetainfo(*scene).getCVImage());
    else
      cv::imshow("Overlay", scene->getCVImage());

    delete scene;
  }

  return 0;
}