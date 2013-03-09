#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <cxtypes.h>
#include <ml.h>
#include <math.h>

#define CV_IMWRITE_JPEG_QUALITY 1

int main(int argc, char* argv[])
{	
	int flag1=0;
	int i,j,dRed, dGreen, dBlue, dTotal;
	const int fuMysticDigit = 66;
	int p[3]; //params 4 save in jpg
	p[0] = CV_IMWRITE_JPEG_QUALITY;
	p[1] = 100;
	p[2] = 0;
	unsigned int stupidc0unt=0;
	IplImage* frame =0;
	IplImage* resu = 0;
	const char* filename = argc >= 2 ? argv[1] : "sample.mp4";

	cvNamedWindow("LOL", CV_WINDOW_AUTOSIZE);

	CvCapture* capture = cvCreateFileCapture(filename);	

	while(1){
		frame = cvQueryFrame(capture);
		if (!frame){break;}

		stupidc0unt++;
		if(stupidc0unt/99==stupidc0unt%99)
			{

				if(flag1==0){
					resu = cvCloneImage(frame);
					flag1=1;
				}

				int height     = frame->height;
				int width      = frame->width;
				int channels   = frame->nChannels;
				uchar* data1    = (uchar *)frame->imageData;
				uchar* data2    = (uchar *)resu->imageData;

				for(i=0;i<height;i++)
				{
					for(j=0;j<width;j++)
					{
						dRed	= (int)data1[i*width*channels+j*channels]-(int)data2[i*width*channels+j*channels];
						dGreen	= (int)data1[i*width*channels+j*channels+1]-(int)data2[i*width*channels+j*channels+1];
						dBlue	= (int)data1[i*width*channels+j*channels+2]-(int)data2[i*width*channels+j*channels+2];
						dTotal	= sqrt(pow(dRed,2)+pow(dGreen,2)+pow(dBlue,2));

						if (dTotal > fuMysticDigit)
						{
							data2[i*width*channels+j*channels]   = 0;
							data2[i*width*channels+j*channels+1] = 0;
							data2[i*width*channels+j*channels+2] = 0;
						}
					}
				}
				cvShowImage( "LOL",resu);
				}
		}

	cvSaveImage("result.jpg", resu, p);

	cvReleaseCapture(&capture);

	cvDestroyWindow("LOL");
        return 0;		
}