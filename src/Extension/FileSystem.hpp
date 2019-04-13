//
//  FileSystem.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 12/04/2019.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include "ofMain.h"
#include <stdio.h>

class FileSystem{
public:
    FileSystem();
    ~FileSystem();
    
    int getMusicCount();
    
private:
    ofDirectory *musicDataDirectory;
    
    size_t musicDataSize;
};

#endif /* FileSystem_hpp */
