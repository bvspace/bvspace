#include <irrlicht.h>
using namespace irr;

#pragma comment(lib, "irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

IrrlichtDevice *dev = 0;
video::IVideoDriver *vdriver = 0;
const int TILESIZE = 16;
int main()
{
    dev = createDevice(video::EDT_DIRECT3D9, core::dimension2d<u32>(320, 240));
    if(0 == dev)
        return 1;
        
    dev->setWindowCaption(L"My Tetris");
    vdriver = dev->getVideoDriver();
    
    video::ITexture *img = vdriver->getTexture("blocks.bmp");
    
    core::ret<s32> block(50, 30, 66, 46);
    
    while(dev->run() && vdriver)
    {
        if(dev->isWindowActive())
        {
            u32 time = dev->getTimer()->getTime();
            
            vdriver->beginScene(true, true, vedio::SColor(255, 255, 255, 255));
            for(int i=0; i<5; ++i)
                vdriver->draw2DImage(img, core::position2d<s32>(50, 50),
                         core::rect<s32>(i*TILESIZE,0,(i+1)*TILESIZE,TILESIZE), 0, 
                         video::SColor(255,255,255,255), true;);
            vdriver->endScene();
        }
    }
    dev->drop();
    
    return 0;
}