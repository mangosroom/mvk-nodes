//
// Created by mango on 3/28/2020.
//

#ifndef MACHINE_VISION_LIBRARY_BLOBDETECT_H
#define MACHINE_VISION_LIBRARY_BLOBDETECT_H

#include "opencv2/features2d.hpp"

using namespace cv;
namespace mv
{
    // Single blob info
    struct BlobInfo
    {
    public:
        float area;                                 //area
        std::vector<cv::Point> outline;             //outline
        float radius;                               //radius
        cv::Point center;                           //cenpter point's coordinate
    };//BlobInfo

    struct BlobDetectResult
    {
        std::vector<BlobInfo> bloblist;
    };//BlobDetectResult

    class BlobDetect: public SimpleBlobDetector
    {
    public:
        explicit BlobDetect(const SimpleBlobDetector::Params &parameters = SimpleBlobDetector::Params());

        virtual void read( const FileNode& fn ) CV_OVERRIDE;
        virtual void write( FileStorage& fs ) const CV_OVERRIDE;

        static Ptr<BlobDetect> create(const SimpleBlobDetector::Params &parameters = SimpleBlobDetector::Params());

        // Workflow
        void Init(cv::Mat& input_image);                               // input image
        void SetParams();                                              // default value
        void SetParams(std::string name, float value);                // set value by param name
        void Run();                                                    // run detection processing

        // class members for user
        cv::Mat input_image;
        BlobDetectResult result;

    private:
        void ParseKeyPoint();                                          // parse keypoints to result
        //
        std::vector<cv::KeyPoint> keypoints;
        Params params;
    };//BlobDetect
}//namespace mv
#endif //MACHINE_VISION_LIBRARY_BLOBDETECT_H
