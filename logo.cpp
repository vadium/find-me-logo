#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <cxtypes.h>
#include <ml.h>

#define CV_IMWRITE_JPEG_QUALITY 1

int main(int argc, char* argv[])
{	
	int flag1=0;
	int i,j;
	int p[3]; //params 4 save in jpg
	p[0] = CV_IMWRITE_JPEG_QUALITY;
	p[1] = 100;
	p[2] = 0;
	unsigned int stupidc0unt=0;
	IplImage* frame =0;
	IplImage* resu = 0;
	char* filename = argc >= 2 ? argv[1] : "sample.mp4";

	cvNamedWindow("LOL", CV_WINDOW_AUTOSIZE);
	
	CvCapture* capture = cvCreateFileCapture(filename);	

	while(1){
		frame = cvQueryFrame(capture);
		if (!frame){break;}
	
		stupidc0unt++;
		if(stupidc0unt/165==stupidc0unt%165)
			{
				
				if(flag1==0){
					resu = cvCloneImage(frame);
				}
								
				int height     = frame->height;
				int width      = frame->width;
				int step       = frame->widthStep/sizeof(uchar);
				int channels   = frame->nChannels;
				uchar* data1    = (uchar *)frame->imageData;
				uchar* data2    = (uchar *)resu->imageData;

				for(i=0;i<height;i++)
				{
					for(j=0;j<width;j++)
					{
						if ((data1[i*step+j*channels+0]!=data2[i*step+j*channels+0])&&
							(data1[i*step+j*channels+1]!=data2[i*step+j*channels+1])&&
							(data1[i*step+j*channels+2]!=data2[i*step+j*channels+2]))
						{
							data2[i*step+j*channels+0] = 0;
							data2[i*step+j*channels+1] = 0;
							data2[i*step+j*channels+2] = 0;
						}
					}
				}
				cvShowImage( "LOL",resu);
				flag1=1;				
			}
		}
	
	cvSaveImage("result.jpg", resu, p);

	cvReleaseCapture(&capture);

	cvDestroyWindow("LOL");
        return 0;		
}